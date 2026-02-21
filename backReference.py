import re
print(re.search(r'(\w+),\1','true,true'))
'''
<re.Match object; span=(0, 9), match='true,true'>
'''
print(re.search(r'(\w+),\1','cat,cat'))
'''
<re.Match object; span=(0, 7), match='cat,cat'>
'''
print(re.search(r'(\w+),\1','true,cat'))
'''
None
'''
print(re.search(r'(tic)(tac)(toe)\1\3','tictactoetictoetac'))
'''
<re.Match object; span=(0, 15), match='tictactoetictoe'>
'''
