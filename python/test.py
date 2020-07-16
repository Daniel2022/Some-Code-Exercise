for i in range(1,20):
    try:
        lists
    except NameError:
        lists = []
    lists.append(i)
    print(lists)
    if i== 9:
        lists = [i]

class AB(object):
    def __init__(self, data):
        self.__data = data

a = AB(22)
#print(dir(a))
print(a._AB__data)