#垃圾的杨辉三角形
def triangles(inp):
	a=[1]
	for i in range(inp):
		b=a.copy()
#		print('i=',i)
		b.insert(0,0)
	#	print('a=',a)
		b.append(0)
	#	print('a=',a)
#		print('Check B=',b)
		for i2 in range(i):
#			print('Generate Circle:','i2=',i2)
			a[i2]=b[i2]+b[i2+1]
#			print('Internal Circle:','a=',a)
		print(a)
		a.append(1)

c=int(input('Please'))
print(triangles(c))