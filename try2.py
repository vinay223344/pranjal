
import re
import os
import sys
import shutil

if len(sys.argv)<4:
	print("Required arguments not given")
	sys.exit(1)
if len(sys.argv)>4:
	print("Only first 3 arguments are considered for execution")

Src=sys.argv[1]
Dest=sys.argv[2]
Txt=sys.argv[3]
	
if os.path.exists(Src):
	if os.path.isfile(Src):
		print(f"{Src} is a file")
		sys.exit(1)
else:
	print(f"{Src} is not exist")
	sys.exit(1)
	
	
if os.path.exists(Dest):
	if os.path.isdir(Dest):
		usr=input(f"{Dest} Directory is already present.Do you want to overwrite the directory(Y/N):")
		if usr=="N" or usr=="n":
			sys.exit(1)
		else:
			shutil.rmtree(Dest)
			os.mkdir(Dest)
			print(f"New {Dest} directory created")
else:
	os.mkdir(Dest)
	print(f"New {Dest} directory created")
	
Text=open(Txt,'r')
flag=0
i=0

soft_link_set=set()
suffix_set=set()
no_need_set=set()

for line in Text:
	if re.findall("SOFT_LINK:",line):
		i=1
	if re.findall("SUFFIX:",line):
		i=2
	if re.findall("NO_NEED:",line):
		i=3
	if i==1:
		if re.findall("./goldenDir",line):
			line=line.strip()
			line=re.findall("(?<=./).*",line)[0]
			if line:soft_link_set.add(line)	
	elif i==2:
		if re.findall("./goldenDir",line):
			line=line.strip()
			line=re.findall("(?<=./).*",line)[0]
			suffix_set.add(line)
	elif i==3:
		if re.findall("./goldenDir",line):
			line=line.strip()
			line=re.findall("(?<=./).*",line)[0]
			no_need_set.add(line)



#print(len(soft_link_set))
#print(len(no_need_set))
#print(len(suffix_set))


username="Mastes0811"
def processing(Src,Dest):
	for each in os.scandir(Src):
		print(each.path)
		path=re.findall("(?<=goldenDir/).*",each.path)[0]
		dest_path=Dest+"/"+path
		
		if each.path in no_need_set:
			continue
		elif each.path in suffix_set:
			if os.path.isdir(each.path):
				if not os.path.exists(dest_path):
					new_name=each.name+"_"+username
					new_path=re.findall(".*(?=/)",dest_path)[0]+"/"+new_name
					#print(new_path)
					#os.makedirs(new_path,exist_ok=True)
					shutil.copytree(each.path,new_path)
					
					#processing(each.path,new_path)
					
			else:
				if not os.path.exists(dest_path):
					os.makedirs(dest_path, exist_ok=True)
					shutil.copy2(each.path,dest_path)
		elif each.path in soft_link_set:
			os.symlink(os.path.abspath(each.path),dest_path)
		else:
			if os.path.isfile(each.path):
			
				if os.path.exists(dest_path):
					path1=re.findall("(?<=/).*$",each.path)
					path2=re.findall("(?<=/).*$",dest_path)
					if not path1==path2:
						shutil.copy2(each.path,dest_path)
				else:
					dest_path=re.findall(".*(?=/)",dest_path)[0]
					os.makedirs(dest_path,exist_ok=True)
					shutil.copy(each.path,dest_path)
			else:
				if not os.path.exists(dest_path):os.makedirs(dest_path)
		
		
		
		
		if os.path.isdir(each.path)and each.path not in suffix_set and each.path not in no_need_set:
			processing(each.path,Dest)
	
processing(Src,Dest)
