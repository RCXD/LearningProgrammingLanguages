M=7
move=2
dataList = ['' for i in range(M)]

def h(x):
    return x%M

def digitFolding(s):
    tot=0
    for ch in s:
        tot+=ord(ch)
    return tot

def insertData(s):
    idx = h(digitFolding(s))
    while True:
        print("INSERT :",idx,"-",s)
        if dataList[idx]=='':
            dataList[idx]=s
            break
        else:
            idx=(idx+move)%M

def printData():
    for i in range(M):
        print(i,":",dataList[i])

def searchData(s):
    idx = h(digitFolding(s))
    while True:
        if s==dataList[idx]:
            print("SEARCH IDX :",idx)
            break
        else:
            idx=(idx+move)%M

insertData("apple")
insertData("banana")
insertData("cherry")
insertData("durian")
insertData("test")
insertData("hello")
printData()
searchData("hello")
