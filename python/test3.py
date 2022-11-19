def trim(a):
	l=0
	while l!=-1:
		if a[l]==' ':
			l=l+1
		else:
			a=a[l:]
			break
	l=len(a)
	while l!=0:
		if a[l-1]==' ':
			l=l-1
		else:
			a=a[:l]
			break
	return a
aaa=input('Please state a sentence:')
print(trim(aaa))