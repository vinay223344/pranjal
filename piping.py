import re

print(re.search(r'tic|tac|toe','tac'))
'''
<re.Match object; span=(0, 3), match='tac'>
'''
print(re.search(r'tic|tac|toe','toe'))
'''
<re.Match object; span=(0, 3), match='toe'>
'''

print(re.search(r'tic|tac|toe','tiger'))
'''
None
'''
print(re.search(r'(tic|tac|toe)+','tictictic'))
'''
<re.Match object; span=(0, 9), match='tictictic'>
'''
print(re.search(r'(tic|tac|toe)+','tactactactactoe' ))
'''
<re.Match object; span=(0, 15), match='tactactactactoe'>
'''

print(re.search(r'([0-9]+|[a-z]+)','alphabets'))
'''
<re.Match object; span=(0, 9), match='alphabets'>
'''
print(re.search(r'([0-9]+|[a-z]+)','123456'))
'''
<re.Match object; span=(0, 9), match='alphabets'>
'''
print(re.search(r'([0-9]+|[a-z]+)','abc123'))
'''
<re.Match object; span=(0, 3), match='abc'>
'''
