M=7
def h(x):
    return x%M

def digitFolding(s):
    tot=0
    for ch in s:
        tot+=ord(ch)
    return tot

class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class Chain:
    def __init__(self):
        self.head=None
        self.count=0

dataList = [Chain() for i in range(M)]

def insertData(data):
    newNode=Node(data)
    idx = h(digitFolding(data))
    print("INSERT :",idx,"-",data)
    if dataList[idx].head is None:
        dataList[idx].head=newNode
    else:#충돌 발생
        curr=dataList[idx].head
        for i in range(dataList[idx].count-1):
            curr=curr.next
        #for문이 끝난 후의 curr는 가장 마지막 node
        curr.next=newNode
       
    dataList[idx].count+=1

def searchData(data):
    idx = h(digitFolding(data))
    curr = dataList[idx].head
    for i in range(dataList[idx].count):
        if curr.data == data:
            print(idx,'의',i,'번째에 위치')
            break
        curr=curr.next

def printData():
    for i in range(M):
        curr=dataList[i].head
        print(i,end=" : ")
        for j in range(dataList[i].count-1):
            print(curr.data,end='⇛')
            curr=curr.next
        if curr is not None:
            print(curr.data)
        else:
            print()

def deleteData(data):
    idx=h(digitFolding(data))
    curr=dataList[idx].head
    if curr.data==data:
        dataList[idx].head=curr.next
    else:
        for i in range(dataList[idx].count-1):
            if curr.next.data==data:
                curr.next=curr.next.next
                break
            curr=curr.next
    dataList[idx].count-=1

insertData("apple")
insertData("banana")
insertData("cherry")
insertData("durian")
insertData("hello")
insertData("test")
insertData("world")
insertData("france")
insertData("google")
printData()
searchData('france')
searchData('world')
deleteData('france')
deleteData('apple')
printData()

