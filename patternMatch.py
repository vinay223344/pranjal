import re

str1="""Let's understand how regex works
"""

print(re.search('regex',str1))
'''
it will search for the word regex in the str1
'''
"""
output:<re.Match object; span=(21, 26), match='regex'>
"""

print(str1[21:26])
'''
output:regex
'''

print(re.search('works\n',str1))
'''
output:<re.Match object; span=(27, 33), match='works\n'>

Yes the new line character matched
'''


str2="regex,regex-same words are repeated"

print(re.search('regex',str2))
'''
output:
<re.Match object; span=(0, 5), match='regex'>
'''

print(re.findall('regex',str2))
'''
output:['regex', 'regex']
'''



