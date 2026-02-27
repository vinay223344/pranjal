import os
import sys
import re

if len(sys.argv)<3:
	print("required number of command line arguments are not provided")
	sys.exit(1)
if os.path.exists(sys.argv[2])==0:
	print("provided verilog module file doesn't exist")
	sys.exit(1)
else:
	ip_file=open(sys.argv[2],'r')
	i=0
	for each in ip_file:
		if i==0:
			i=1
			module_name=re.findall(r"(?<=module\s).*(?=\()",each)[0]
		else:
			break
	if sys.argv[1]!=module_name:
		opt=input(f"module name provided in argument is {sys.argv[1]} but the input file contains module name {module_name}. Do you want to replace the module name in the input file?[Y:N]:")
		if opt=='n'or opt=='N':
			sys.exit(1)
		else:
			module_name=sys.argv[1]
if os.path.exists(f"tb_{module_name}.v"):
	opt=input(f"Do you want to overwrite the testbench file: tb_{module_name}.v?[Y/N]:")
	if opt=='n'or opt=='N':
		sys.exit(1)
	else:
		os.remove(f"tb_{module_name}.v")
		op_file=open(f"tb_{module_name}.v","w")
else: 
	op_file=open(f"tb_{module_name}.v","w")

op_file.write(f"module tb_{module_name};\n")
i=0
io_list=[]
ip_file.seek(0)
for line in ip_file:
	if i==0:
		io_list.extend(re.split(r',\s',re.findall(r"(?<=\().*(?=\))",line)[0]))
		i=1
	else:
		match=re.findall(r".*(?=;)",line)
		if match:
			io_list.append(match[0])

print(io_list)
inputs=[]
outputs=[]
for item in io_list:
	if re.findall(r"[a-z]+(?=\s)",item)[0]=='input':
		ip=re.findall(r"(?<=t\s).*",item)[0]
		if re.findall(r".",ip)[0]=='[':
			inputs.extend(re.split(r',',re.findall(r"(?<=\s).*",ip)[0]))
		else:
			inputs.extend(ip.split(','))
		op_file.write(f"reg {ip};\n")
	elif re.findall(r"[a-z]+(?=\s)",item)[0]=='output' or re.findall(r"[a-z]+(?=\s)",item)[0]=='inout':
		op=re.findall(r"(?<=t\s).*",item)[0]
		if re.findall(r".",op)[0]=='r':
			op=re.findall(r"(?<=g\s).*",op)[0]
		if re.findall(r".",op)[0]=='[':
			outputs.extend(re.split(r',',re.findall(r"(?<=\s).*",op)[0]))
		else:
			outputs.extend(op.split(','))
		op_file.write(f"wire {op};\n")
op_file.write("a(")
i=0
for item in inputs:
	if i==0:
		op_file.write(f".{item}({item})")
		i=1
	else:
		op_file.write(f", .{item}({item})")
for item in outputs:
	if i==0:
		op_file.write(f".{item}({item})")
		i=1
	else:
		op_file.write(f", .{item}({item})")
file_name=re.findall(r".*(?=\.)",sys.argv[2])[0]
op_file.write(f");\n\ninitial begin\n\t#150\n\t$finish\nend\n\ninitial begin\n\t$recordfile(\"{module_name} {file_name}.trn\");\n\t$recordvars();\nend\n\nendmodule")

ip_file.close()
op_file.close()

	
