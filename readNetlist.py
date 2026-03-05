import os
import re
import sys
import shutil

spectre=open(sys.argv[1],'r')
root=sys.argv[2]
top_cell=sys.argv[3]

flag=0
cells=[]
cell_parents=[]
cells.append(top_cell)
cell_parents.append(root)

for cell in cells:
	spectre.seek(0)
	for line in spectre:
		line=line.strip()
		if flag==0:
			if line.startswith('subckt'):
				if re.findall(r'(?<=subckt\s)[0-9a-z_]+(?=\s)',line):
					if re.findall(r'(?<=subckt\s)[0-9a-z_]+(?=\s)',line)[0] == cell:
						flag=1
						continue
		if flag==1:
			if line.startswith('I'):
				instance_name=re.findall(r'^[0-9A-Z]+(?=\s)',line)[0]
				cell_name=re.findall(r'(?<=\)\s).*$',line)[0]
				cells.append(cell_name)
				
				if cell not in cell_parents: cell_parents.append(cell)
				dir_name=instance_name+"_"+cell_name
				print(dir_name)
				print(cells)
				print(cell)
				print(cell_parents)
				print("-----------------")
				if os.path.exists(root):
					if not os.path.exists(os.path.join(os.path.abspath(cell_parents[0]),cell)):
						os.makedirs(os.path.join(os.path.abspath(cell_parents[0]),cell),exist_ok=True)
						cell_parents.pop(0)
					os.makedirs(os.path.join(os.path.abspath(cell),dir_name),exist_ok=True)
				else: 
					os.makedirs(os.path.join(root,cell,dir_name),exist_ok=True)
					cell_parents.pop(0)
				continue
			elif line.startswith('M'):
				if os.path.exists(root):
					if not os.path.exists(os.path.join(os.path.abspath(cell_parents[0]),cell)):
						os.makedirs(os.path.join(os.path.abspath(cell_parents[0]),cell),exist_ok=True)
						cell_parents.pop(0)
					if not os.path.exists(os.path.join(os.path.abspath(cell),"leafCells.txt")):
						leafCells=open(os.path.join(os.path.abspath(cell),"leafCells.txt"),'w')
						leafCells.write("instanceName\t\tmodelName\t\twidth\t\tlength\t\tmultiplier\t\tfingers\n")
						leafCells.close()
				else: 
					os.makedirs(os.path.join(root,cell),exist_ok=True)
					leafCells=open(os.path.join(root,cell,"leafCells.txt"),'w')
					leafCells.write("instanceName\t\tmodelName\t\twidth\t\tlength\t\tmultiplier\t\tfingers\n")
					leafCells.close()
				leafCells=open(os.path.join(cell,"leafCells.txt"),'w')
				instance_name=re.findall(r'^[0-9A-Z]+(?=\s)',line)[0]
				model_name=re.findall(r'(?<=\)\s)[a-z0-9]+(?=\sw)',line)[0]
				width=re.findall(r'(?<=w\=)[\.0-9]+(?=\s)',line)[0]
				length=re.findall(r'(?<=l\=)[\.0-9]+(?=\s)',line)[0]
				multiplier=re.findall(r'(?<=m\=\()[0-9]+(?=\)\*)',line)[0]
				fingers=re.findall(r'(?<=\*\()[0-9]+(?=\))',line)[0]
				leafCells.write(f"{instance_name}\t\t{model_name}\t\t{width}\t\t{length}\t\t{multiplier}\t\t{fingers}\n")
				leafCells.close()
				continue
			elif line.startswith(f'ends {cell}'):
				spectre.seek(0)
				flag=0
				break
			else: continue
	cells.pop(0)		
			
		
