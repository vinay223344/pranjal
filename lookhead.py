
import re
print(re.search(r'blo(?=[a-z])','blossoms'))
'''
<re.Match object; span=(0, 3), match='blo'>
'''
print(re.search(r'blo(?=[a-z])','blo123'))
'''
None
'''
print(re.search(r'blo(?=[0-9])','blo123'))
'''
<re.Match object; span=(0, 3), match='blo'>
'''
print(re.search(r'blo([0-9])','blo123'))
'''
<re.Match object; span=(0, 4), match='blo1'>
'''
print(re.search(r'blo(?![a-z])','blossoms'))
'''
None
'''
print(re.search(r'blo(?![a-z])','blo123'))
'''
<re.Match object; span=(0, 3), match='blo'>
'''
print(re.search(r'blo(?![a-z])','blo1ssoms'))
'''
<re.Match object; span=(0, 3), match='blo'>

'''
