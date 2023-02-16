UB = ['0', '1']
TAC = ['0', '1', '2']
V = ['0', '1', '2', '3', '4']
MB = lambda s: '0' if s == '00' else ('1' if s == '01' else ('2' if s == '10' else '3'))
MA = lambda s: '0' if s == '00' else ('1' if s == '01' else ('2' if s == '10' else '3'))
MC = lambda s: '0' if s == '0' else '1'

def find_secret_string(left, right, u, v, s):
    if left > right:
        return
    
    substring = s[left:right+1]
    
    if MB(substring[:2]) != u:
        return
    if MA(substring[1:4]) != TAC.index(v):
        return
    if MC(substring[-1]) != v[-1]:
        return
    
    if substring == s:
        print(substring)
    else:
        mid = (left + right) // 2
        find_secret_string(left, mid, v[-1] + MB(substring[2:5]), V[TAC.index(v)+1] + MA(substring[4:7]), s)
        find_secret_string(mid+1, right, V[TAC.index(v)+1] + MA(substring[7:]), v[-1] + MC(substring[-2:]), s)

# example usage
s = '101202220302012032230031010121112'
find_secret_string(0, len(s)-1, '0', '0', s)
