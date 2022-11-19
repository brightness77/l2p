L = ['Hello', 'World', 18, 'Apple', None]
li=[s.upper() if isinstance(s,str) else s*s if isinstance(s,int) for s in L]
print(li)