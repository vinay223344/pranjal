def sample(arg):
	print("Hello"+arg)
	return
sample("Moschip")
'''
Output:HelloMoschip
'''
'''
(a)def used for defining the function in python
	arg is the parameter given to the function
	sample is the name of the function
	sample("Moschip")->Here Moschip is the argument given to the function
	
(b)parameter is the value given to the function while defining the function.
	argumnet i sthe value given to the function whil ecalling the function.
	
(c)If we give more arguments when function is called then error will be popped i.e
    sample("Moschip","analog")
TypeError: sample() takes 1 positional argument but 2 were given

'''

print("-------------------------------------------------------")



def myFunc(arg):
	print("num received:",arg)
	arg+=1
	print("Address within function:",(id(arg)))
	print("num within called function:",arg)
	return
	
var=1
print("Address before calling:",(id(var)))
print("num before function call:",var)
myFunc(var)
print("num after function call:",var)
print("Address after calling:",(id(var)))

print("----------------------------------------------------")

'''
Output:
Address before calling: 9788960
num before function call: 1
num received: 1
Address within function: 9788992
num within called function: 2
num after function call: 1
Address after calling: 9788960
'''
"""
id means address of that variable
evenif inside the function the argument is increasing as it is local to that function only so outside the function value of argument remain same.
"""




def myFunc(myList):
	print("List received: ",myList)
	myList.append(3)
	myList.extend([7,1])
	print("List after adding some elements:", myList)
	myList.remove(7)
	print("Address within function:", (id(myList)))
	print("List within called function:", myList)
	return
List1=[1]
print("Address before calling:",(id(List1)))
print("List before function call :",List1)
myFunc(List1)
print("List after function call: ",List1)
print("Address after calling:",(id(List1)))

'''
output:
Address before calling: 139660191435840
List before function call : [1]
List received:  [1]
List after adding some elements: [1, 3, 7, 1]
Address within function: 139660191435840
List within called function: [1, 3, 1]
List after function call:  [1, 3, 1]
Address after calling: 139660191435840

'''

"""
Observation:
Inside function also address is passing so in side function if we do chnage to that list except reassigning then that will be show out of the function also.
"""

print("------------------------------------------")


def myFunc(myList):
	print("List received: ",myList)
	myList.append(3)
	myList.extend([7,1])
	print("List after adding some elements:", myList)
	myList.remove(7)
	myList=[3, 4, 6]
	print("Address within function:")
	print((id(myList)))
	print("List within called function:", myList)
	return
List1=[1]
print("Address before calling:",(id(List1)))
print("List before function call :",List1)
myFunc(List1)
print("List after function call: ",List1)
print("Address after calling:",(id(List1)))

'''
output:
Address before calling: 139852541938816
List before function call : [1]
List received:  [1]
List after adding some elements: [1, 3, 7, 1]
Address within function:
139852542197696
List within called function: [3, 4, 6]
List after function call:  [1, 3, 1]
Address after calling: 139852541938816
'''

"""
Explanation:
untill i reassign the value of list ,the adrress remain same .after reassigning the list address is getting chnaged
"""
print("----------------------------------------------------")

def function(n):
	return 1 if (n==1 or n==0) else n * function(n - 1)
num = 5
print(function(num))

'''
output:120
'''
"""
Explanation:
Given n=5
so function(5)
	5*function(4)
		4*function(3)
			3*function(2)
				2*function(1)
as basecase so function(1) resturn 1 so answer will be 1*2*3*4*5=120
"""


print("----------------------------------------------------------------")


def sample(*arg):
	print("Hello "+arg[1])
	return
sample("Moschip","analog")
'''
output:
Hello analog
'''

print("------------------------------------------------------------")

def lib_mngr(lname,cname):
	print("library name is " + lname)
	print("cell name is " + cname)
lib_mngr(lname = "analogLib", cname = "pmos2v")
'''
output:
library name is analogLib
cell name is pmos2v
'''


print("---------------------------------------------------------")


def lib_mngr(lname,cname="nmos2v"):
	print("library name is " + lname)
	print("cell name is " + cname)
lib_mngr(lname = "analogLib", cname = "pmos2v")
'''
output:
library name is analogLib
cell name is pmos2v
'''

lib_mngr(lname = "analogLib")
'''
output:
library name is analogLib
cell name is nmos2v
'''

#lib_mngr()
'''
    lib_mngr()
TypeError: lib_mngr() missing 1 required positional argument: 'lname'
'''

print("--------------------------------------")
def lib_mngr(**kwargs):
	print("library name is " + kwargs["lname"])
	print("cell name is " + kwargs["cname"])
lib_mngr(lname = "analogLib", cname = "pmos2v")

'''
output:
library name is analogLib
cell name is pmos2v
'''

print("---------------------------------------")


def length(l):
	print(2*l)
length(1e-06)
'''
output:
2e-06
'''

print("---------------------------------------")

def width(w): return 2*w
length = lambda l : 2*l
print(width(1e-06))
print(length(1e-06))
'''
output:
2e-06
2e-06
'''
print("---------------------------------------------")

def mosfet():
	width = 1e-06
	length = 1e-06
	print("width is : ",width)
	print("length is : ",length)
	print(no_of_fingers)
no_of_fingers = 2
mosfet()

'''
output:
width is :  1e-06
length is :  1e-06
2
'''

print("-------------------------------------------------")
def swap(x, y):
	temp = x
	x = y
	y = temp
x = 2
y = 3
swap(x, y)
print(x)
print(y)
'''
output:
2
3
'''
print("----------------------------------------------------")

a = 1
def f():
	print('Inside f() : ', a)
def g():
	a = 2
	print('Inside g() : ', a)
def h():
	global a
	a = 3
	print('Inside h() : ', a)
print('global : ', a)
f()
print('global : ', a)
g()
print('global : ', a)
h()
print('global : ', a)

'''
output:
global :  1
Inside f() :  1
global :  1
Inside g() :  2
global :  1
Inside h() :  3
global :  3
'''
