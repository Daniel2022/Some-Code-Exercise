def function(n):
    if n == 1:
        return 1
    else:
        return n * function(n-1)

x = 1
result = 0
for i in range(11):
    if i==0:
        frac = 1
    else:
        frac = x**i/function(i)
    result += frac

print(result)
print(function(3))