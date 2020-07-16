def func(t):
    if t == 1:
        return 1
    else:
        return t*func(t-1)

print(func(1000))