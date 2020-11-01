M=7
c=13
j=1
dataList = ['' for i in range(M)]

def h(x):
    return x%M

def d(x):
    return x%c+j

#idx : h(x)*d(x) % M + j

def digitFolding(s):
    tot=0
    for ch in s:
        tot+=ord(ch)
    return tot

def insertData(s):
    global j
    idx=h(digitFolding(s))
    while True:
        if dataList[idx%M]=='':
            dataList[idx%M]=s
            print("INSERT :",idx%M,"-",s)
            j=1
            break
        else:
            idx=h(digitFolding(s))*d(digitFolding(s))%M+j
            j+=1

def printData():
    for i in range(M):
        print(i,":",dataList[i])

insertData("apple")
insertData("banana")
insertData("cherry")
insertData("durian")
insertData("hello")
insertData("test")
insertData("hello")
printData()



