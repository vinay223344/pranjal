
import re
print(re.search(r'(?<=can)did','candid'))
'''
<re.Match object; span=(3, 6), match='did'>
'''
print(re.search(r'(?<=not)did','candid'))
'''
None
'''
print(re.search(r'(?<=a)def','aaadef'))
'''
<re.Match object; span=(3, 6), match='def'>
'''
print(re.search(r'(?<=a{3})def','aaadef'))
'''
<re.Match object; span=(3, 6), match='def'>
'''
print(re.search(r'(?<!can)did','candid'))
'''
None
'''
print(re.search(r'(?<!not)did','candid'))
'''
<re.Match object; span=(3, 6), match='did'>
'''












print("========================")

str3="I like PYTHON programming"
print(re.findall(r'[A-Z]+',str3))
'''
output:['I', 'PYTHON']
'''
print("==============================")
str4="Numbers are 8,23,886,4567,78453"
print(re.search(r'\d{5}',str4))
'''
output:<re.Match object; span=(26, 31), match='78453'>
'''
print(re.findall(r'\d{2,4}',str4))
'''
['23', '886', '4567', '7845']
'''
print("================================")

str5="I am doing \n Assignment on regular expressions in PYTHON."
print(re.findall(r'\w+[^\n.]',str5))
'''
['I ', 'am ', 'doing ', 'Assignment ', 'on ', 'regular ', 'expressions ', 'in ', 'PYTHON']
'''
print("===================================")

str6= "There are emails of different users tom.jerry@moschip.com, beauty.beast@moschip.com,nobitha.nobi@gmail.com mr.bean@gmail.edu motu.patlu@nick.tic power.rangers@nick.com"
print(re.findall(r'\w+\.\w+@\w+\.\w+',str6))
'''
['tom.jerry@moschip.com', 'beauty.beast@moschip.com', 'nobitha.nobi@gmail.com', 'mr.bean@gmail.edu', 'motu.patlu@nick.tic', 'power.rangers@nick.com']
'''

print("==================================")

str7 = '''
123		Integer number with 3 digits
123.4567		Real number with 3-digits in whole number & 4-Digits in fractional portion.
1234.0		Real number with 4-digits in whole number and 1-digit in fractional portion.	
4		Integer number with 1-digit
4567		Integer number with 4-digits
6.0		Real number with 1-digit in whole number and 1-digit in fractional portion.
78901		Integer number with 5-Digits
56		Integer number with 2-Digits
3.456		Real number with 1-digit in whole number and 3-digits in fractional portion.
This line doesn't contain any numbers
10.		is not a valid number
.10		is not a valid number
100e-10		Real number in scientific notation
100.0e-01		Real number in scientific notation
100.123e+1		Real number in scientific notation
123.e-		Invalid number
123.e+		Invalid number
.e-12		Invalid number
^		Caret
.		Dot
$		Dollar
*		Asterix
+		Plus
?		Question mark
{		Flower bracket
[		Square bracket
|		Pipe
(		Small bracket
&		Ampersand
'''
print(re.findall(r'(?<=\n)[0-9]+(?=\t)',str7))
'''
['123', '3', '123', '4567', '3', '4', '1234', '0', '4', '1', '4', '1', '4567', '4', '6', '0', '1', '1', '78901', '5', '56', '2', '3', '456', '1', '3', '10', '10', '100', '10', '100', '0', '01', '100', '123', '1', '123', '123', '12']
'''
print(re.findall(r'\d+\.\d+',str7))
'''
['123.4567', '1234.0', '6.0', '3.456', '100.0', '100.123']
'''

print(re.findall(r'(?<=\n)\W(?=\t)',str7))
'''
['^', '.', '$', '*', '+', '?', '{', '[', '|', '(', '&']
'''
print("===============================")


str8='''
Design		OP("I0/I1/M0" "vdsat") (V)
1.			2.656514e-02
Design		OP("I0/I1/M1" "vds") (V)
1.			5.087847e-01
Design		OP("I0/I1/M2" "id") (A)
1.			1.000000e-06
Design		OP("I0/I1/M3" "vth") (V)
1.			4.558458e-01
'''

print(re.findall(r'(?<=OP\(").*?(?=")',str8))
'''
['I0/I1/M0', 'I0/I1/M1', 'I0/I1/M2', 'I0/I1/M3']
'''
print(re.findall(r'(?<=)',str8)





