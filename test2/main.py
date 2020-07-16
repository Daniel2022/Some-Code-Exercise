import subprocess
import create
import mans

flag=1

while flag and flag<100000: 
    flag+=1
    s=create.getcase()
    with open('1.txt', 'w') as f: 
        f.write(s)
    s1="b'"+mans.mans(s)+r"\r\n\r\nF:\\programming\\exercise\\test2>'"
    s2=subprocess.check_output("cmd /k python ans.pyc < 1.txt",shell = True)
    #print("line")
    #print(s1)
    #print("line")
    #print([str(s2)])
    #print("line")
    flag*=(s1 in str(s2))
    if flag==0:
        print(s)
        print("line")
        print(s1)
        print("line")
        print(s2)
        print("line")
    print(flag)


