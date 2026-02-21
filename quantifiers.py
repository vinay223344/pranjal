import re

print(re.search(r'123','123'))
'''
<re.Match object; span=(0, 3), match='123'>
'''


print(re.search(r'oc-*ean','ocean'))
'''
<re.Match object; span=(0, 5), match='ocean'>
'''
print(re.search(r'oc-*ean','oc-ean'))
'''
<re.Match object; span=(0, 6), match='oc-ean'>
'''
print(re.search(r'oc-*ean','oc--ean'))
'''
<re.Match object; span=(0, 7), match='oc--ean'>
'''
print(re.search(r'This.*nt','# ThisIsAStatement #'))
'''
<re.Match object; span=(2, 18), match='ThisIsAStatement'>
'''

print(re.search(r'oc-+ean','ocean'))
'''
None
'''
print(re.search(r'oc-+ean','oc-ean'))
'''
<re.Match object; span=(0, 6), match='oc-ean'>
'''
print(re.search(r'oc-+ean','oc--ean'))
'''
<re.Match object; span=(0, 7), match='oc--ean'>
'''

print(re.search(r'<.*>','#<first> <sec> <third>#'))
'''
<re.Match object; span=(1, 22), match='<first> <sec> <third>'>
'''
print(re.search(r'<.*?>','#<first> <sec> <third>#'))
'''
<re.Match object; span=(1, 8), match='<first>'>
'''
"""

"""
print(re.search(r'<.+>','#<first> <sec> <third>#'))
'''
<re.Match object; span=(1, 22), match='<first> <sec> <third>'>
'''
print(re.search(r'<.+?>','#<first> <sec> <third>#'))
'''
<re.Match object; span=(1, 8), match='<first>'>
'''
'''
'''
print(re.search(r'hey?','#heyyyyyyyy#'))
'''
<re.Match object; span=(1, 4), match='hey'>
'''

print(re.search(r'hey??','#heyyyyyyyy#'))
'''
<re.Match object; span=(1, 3), match='he'>
'''

print(re.search(r'x-{3}x','x--x'))
'''
None
'''
print(re.search(r'x-{3}x','x---x'))
'''
<re.Match object; span=(0, 5), match='x---x'>
'''
print(re.search(r'x-{3}x','x----x'))
'''
None
'''
print("=============================")
print(re.search(r'x-{2,4}x','x-x'))
'''
None
'''
print(re.search(r'x-{2,4}x','x--x'))
'''
<re.Match object; span=(0, 4), match='x--x'>
'''
print(re.search(r'x-{2,4}x','x---x'))
'''
<re.Match object; span=(0, 5), match='x---x'>
'''
print(re.search(r'x-{2,4}x','x----x'))
'''
<re.Match object; span=(0, 6), match='x----x'>
'''
print(re.search(r'x-{2,4}x','x-----x'))
'''
None
'''
print("=============================================")

print(re.search(r'x-{,4}x','x-x'))
'''
<re.Match object; span=(0, 3), match='x-x'>
'''
print(re.search(r'x-{,4}x','x--x'))
'''
<re.Match object; span=(0, 4), match='x--x'>
'''
print(re.search(r'x-{,4}x','x---x'))
'''
<re.Match object; span=(0, 5), match='x---x'>
'''
print(re.search(r'x-{,4}x','x----x'))
'''
<re.Match object; span=(0, 6), match='x----x'>
'''
print(re.search(r'x-{,4}x','x-----x'))
'''
None
'''
print("==============================================")
print(re.search(r'x-{2,}x','x-x'))
'''
None
'''
print(re.search(r'x-{2,}x','x--x'))
'''
<re.Match object; span=(0, 4), match='x--x'>
'''
print(re.search(r'x-{2,}x','x---x'))
'''
<re.Match object; span=(0, 5), match='x---x'>
'''
print(re.search(r'x-{2,}x','x----x'))
'''
<re.Match object; span=(0, 6), match='x----x'>
'''
print(re.search(r'x-{2,}x','x-----x'))
'''
<re.Match object; span=(0, 7), match='x-----x'>

'''
print("============================")
print(re.search(r'x-{}x','x-x'))
'''
None
'''
print(re.search(r'x-{}x','x--x'))
'''
None
'''
print(re.search(r'x-{}x','x---x'))
'''
None
'''
print(re.search(r'x-{}x','x----x'))
'''
None
'''
print(re.search(r'x-{}x','x-----x'))
'''
None

'''
print("============================")
print(re.search(r'a{to}z','a{to}z'))
'''
<re.Match object; span=(0, 6), match='a{to}z'>
'''
print(re.search(r'{replicates} the same','{replicates} the same'))
'''
<re.Match object; span=(0, 21), match='{replicates} the same'>
'''
