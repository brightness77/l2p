def is_palindrome(n):
    n1=str(n)
    i1=True
    i2=0
    for cha in n1:
        if n1[i2] == n1[-i2-1]:
            pass
        else:
            i1 = False
    if i1 == True:
        return n

output = filter(is_palindrome, range(1, 1000))
print('1~1000:', list(output))
if list(filter(is_palindrome, range(1, 200))) == [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 111, 121, 131, 141, 151, 161, 171, 181, 191]:
    print('测试成功!')
else:
    print('测试失败!')
