import re
print(re.search('ho[wtr]','howareyou'))
'''
<re.Match object; span=(0, 3), match='how'>
'''
print(re.search('ho[afux]','houareyou'))
'''
<re.Match object; span=(0, 3), match='hou'>
'''
print(re.search('[a-z]','HOWareYOU'))
'''
<re.Match object; span=(3, 4), match='a'>
'''
print(re.search('[A-Z]','HOWareYOU'))
'''
<re.Match object; span=(0, 1), match='H'>
'''
print(re.search('[0-9a-zA-Z]','--- 123abcABC ---'))
'''
<re.Match object; span=(4, 5), match='1'>
'''
print(re.search('[^0-9]',' 1234hello'))
'''
<re.Match object; span=(0, 1), match=' '>
'''
print(re.search('[^%:]',' 12^34h%el:lo'))
'''
<re.Match object; span=(0, 1), match=' '>
'''
print(re.search('[%^:]',' 12^34h%el:lo'))
'''
<re.Match object; span=(3, 4), match='^'>
'''
print(re.search('[0-9][0-9]','hi11hi'))
'''
<re.Match object; span=(2, 4), match='11'>
'''
print(re.search('[0-9][0-9][0-9]','hi11hi'))
'''
None
'''
print(re.search('[-abc]','123-abc'))
'''
<re.Match object; span=(3, 4), match='-'>
'''
print(re.search('[abc-]','abc-123'))
'''
re.Match object; span=(0, 1), match='a'>
'''
print(re.search('[ab-c]','ab-cd'))
'''
<re.Match object; span=(0, 1), match='a'>
'''
print(re.search('[ab\-c]','ab-cd'))
'''
<re.Match object; span=(0, 1), match='a'>
'''
print(re.search('[]]','fet[3]'))
'''
<re.Match object; span=(5, 6), match=']'>
'''
print(re.search('[ab\]cd]','fet[3]'))
'''
<re.Match object; span=(5, 6), match=']'>
'''
print(re.search('[)*+&]','ipl+match'))
'''
<re.Match object; span=(3, 4), match='+'>
'''
print(re.search('[ipl.match]','iplxmatch'))
'''
<re.Match object; span=(0, 1), match='i'>
'''
print(re.search('1.3','hi123hi'))
'''
<re.Match object; span=(2, 5), match='123'>
'''
print(re.search('1.3','hi13hi'))
'''
None
'''
print("--------------------------------------------")
print(re.search('\w','!@#a%^&'))
'''
<re.Match object; span=(3, 4), match='a'>
'''
print(re.search('\w','@_#ABC%^&'))
'''
<re.Match object; span=(1, 2), match='_'>
'''
print(re.search('\W','1ab!cd'))
'''
<re.Match object; span=(3, 4), match='!'>
'''
print(re.search('[^a-zA-Z0-9_]','1ab!cd'))
'''
<re.Match object; span=(3, 4), match='!'>
'''
print(re.search('[\d]','abc1efg'))
'''
<re.Match object; span=(3, 4), match='1'>
'''
print(re.search('[\D]','123S456'))
'''
<re.Match object; span=(3, 4), match='S'>
'''
print(re.search('[\s]','123 S\n 456'))
'''
<re.Match object; span=(3, 4), match=' '>
'''
print(re.search('[\s]','123\n S 456'))
'''
<re.Match object; span=(3, 4), match='\n'>
'''
print(re.search('[\S]',' \n 123 \n '))
'''
<re.Match object; span=(3, 4), match='1'>
'''
print(re.search('[\d\w\s]','++9++'))
'''
<re.Match object; span=(2, 3), match='9'>
'''
print(re.search('[\d\w\s]','++W++'))
'''
<re.Match object; span=(2, 3), match='W'>
'''
print(re.search('[\d\w\s]','++ ++'))
'''
<re.Match object; span=(2, 3), match=' '>
'''
print(re.search('.','ipl.match'))
'''
<re.Match object; span=(0, 1), match='i'>
'''
print(re.search('\.','ipl.match'))
'''
<re.Match object; span=(3, 4), match='.'>
'''
print(re.search('[.]','ipl.match'))
'''
<re.Match object; span=(3, 4), match='.'>
'''
#print(re.search('\\','C:\Windows'))
'''
Traceback (most recent call last):
  File "metaChar.py", line 160, in <module>
    print(re.search('\\','C:\Windows'))
  File "/usr/lib/python3.8/re.py", line 201, in search
    return _compile(pattern, flags).search(string)
  File "/usr/lib/python3.8/re.py", line 304, in _compile
    p = sre_compile.compile(pattern, flags)
  File "/usr/lib/python3.8/sre_compile.py", line 764, in compile
    p = sre_parse.parse(p, flags)
  File "/usr/lib/python3.8/sre_parse.py", line 940, in parse
    source = Tokenizer(str)
  File "/usr/lib/python3.8/sre_parse.py", line 232, in __init__
    self.__next()
  File "/usr/lib/python3.8/sre_parse.py", line 245, in __next
    raise error("bad escape (end of pattern)",
re.error: bad escape (end of pattern) at position 0

'''
"""
As the \\ pattern got to regex it will consider 1st \ as escape character and after that it will go to interpreter and then interpreter again consider that remaining \ to escape character so there is no pattern so error getting
"""

print(re.search('\\\\','C:\Windows'))
'''
<re.Match object; span=(2, 3), match='\\'>
'''
print(re.search(r'\\','C:\Windows'))
'''
<re.Match object; span=(2, 3), match='\\'>
'''

print(re.search(r'^star','start'))
'''
<re.Match object; span=(0, 4), match='star'>
'''
print(re.search(r'\Astar','start'))
'''
<re.Match object; span=(0, 4), match='star'>
'''
print(re.search('^star','shootingstar'))
'''
None
'''
print(re.search(r'end$','The-end'))
'''
<re.Match object; span=(4, 7), match='end'>
'''
print(re.search(r'end\Z','The-end'))
'''
<re.Match object; span=(4, 7), match='end'>
'''
print(re.search(r'end$','ending'))
'''
None
'''
print(re.search(r'\bword','a word'))
'''
<re.Match object; span=(2, 6), match='word'>
'''
print(re.search(r'\bword','a.word'))
'''
<re.Match object; span=(2, 6), match='word'>
'''
print(re.search(r'\bword','a&word'))
'''
<re.Match object; span=(2, 6), match='word'>
'''
print(re.search(r'\bword','a\nword'))
'''
<re.Match object; span=(2, 6), match='word'>
'''
print(re.search(r'\bword','aword'))
'''
None
'''
print(re.search(r'\bword','a_word'))
'''
None
'''
print(re.search(r'\bword\b','a word'))
'''
<re.Match object; span=(2, 6), match='word'>
'''
print(re.search(r'\Bword','.word.'))
'''
None
'''
print(re.search(r'\Bword',' word '))
'''
None
'''
print(re.search(r'\Bword','aword'))
'''
<re.Match object; span=(1, 5), match='word'>
'''
print(re.search(r'\Bword\B','aworda'))
'''
<re.Match object; span=(1, 5), match='word'>
'''

