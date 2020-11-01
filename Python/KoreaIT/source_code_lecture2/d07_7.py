#체이닝

M=7
def h(x):
    return x%M

def digitFolding(s):
    tot=0
    for ch in s:
        tot+=ord(ch)
    return tot

class Node:
    def __init__(self, data):
        self.data=data
        self.next=None


class Chain:
    def __init__(self):
        self.head=None
        self.count=0

dataList=[Chain() for i in range(M)] #생성자는 새 객체를 만들고 그 객체의 주소값을 반환!
#예) chain = Chain()
def insertData(data):
    newNode=Node(data)
    idx=h(digitFolding(data))
    print("INSERT: ",idx,'-',data)
    if dataList[idx].head is None:
        dataList[idx].head=newNode
    else: #충돌 발생시
        curr=dataList[idx].head
        for i in range(dataList[idx].count-1):
            curr=curr.next
        #for문 끝난 후의 curr는 가장 마지막 node
        curr.next=newNode
    dataList[idx].count+=1

def printData():
    for i in range(M):
        curr=dataList[i].head
        print(i, end=" : ")
        for j in range(dataList[i].count-1):
            print(curr.data, end='⇒ ')
            curr = curr.next
            if curr is not None:
                print(curr.data)
            else:
                print()

def searchData(data):
    idx = h(digitFolding(data))
    curr=dataList[idx].head
    for i in range(dataList[idx].count):
        if curr.data==data:
            print(idx,'의',i,'번째에 위치')
            break
        curr=curr.next

def deleteData(data):
    idx=h(digitFolding(data))
    curr=dataList[idx].head
    if curr.data==data: #먼저 물어봐야함!
        dataList[idx].head=curr.next #걸러주기... 무엇을?
    else:
        for i in range(dataList[idx].count-1):
            if curr.next.data==data:
                curr.next=curr.next.next
                break
            curr=curr.next
    dataList[idx].count -= 1
    

#출력 왜 엉망임??
insertData('apple')
insertData('banna')
insertData('cherry')
insertData('durian')
insertData('test')
insertData('hello')
insertData('world')
insertData('grance')
insertData('google')
printData()
searchData('france')
searchData('world')
deleteData('france')
deleteData('apple')
printData()

#역시나 출력이 다르니, 비교해보자.
#이게 결국엔 겹치면 링크드리스트로 물어준다는거네.(체인마냥)