
import re
print(re.search(r'(tac)', 'tic tac toe'))
'''
<re.Match object; span=(4, 7), match='tac'>
'''
print(re.search(r'tac', 'tic tac toe'))
'''
<re.Match object; span=(4, 7), match='tac'>
'''
print(re.search(r'(tac)+', 'tic tactactac toe'))
'''
<re.Match object; span=(4, 13), match='tactactac'>
'''
print(re.search(r'tac+', 'tic taccc toe'))
'''
<re.Match object; span=(4, 9), match='taccc'>
'''
print(re.search(r'(t[ia]c){,5}(toe)?', 'tictactictoe'))
'''
<re.Match object; span=(0, 12), match='tictactictoe'>
'''
print(re.search(r'(t[ia]c){,5}(toe)??', 'tictactictoe'))
'''
<re.Match object; span=(0, 9), match='tictactic'>
'''
print("======================================")

print(re.search(r'(tic(tac)?)+(\w)+', 'tictactictoe'))
'''
<re.Match object; span=(0, 12), match='tictactictoe'>
'''

print("=======================================")

m= re.search(r'(\w+),(\w+),(\w+)', 'on,key,run')
print(m.groups())
'''
('on', 'key', 'run')
'''

print("==========================================")

print(m.group(1) ,m.group(2), m.group(3))
'''
on key run
'''
print(m.group(0))
'''
on,key,run
'''
print(m.group())
'''
on,key,run
'''
print(m.group(2,3))
'''
('key', 'run')
'''
print(m.group(3,2,1))
'''
('run', 'key', 'on')
'''
n=(m.group(3), m.group(2), m.group(1))
print(n)
'''
('run', 'key', 'on')
'''
