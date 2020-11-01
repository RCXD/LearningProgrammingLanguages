#실습
#연결리스트 구현
#연결리스트에 삽입하고 정렬하는것 구현
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class LinkedList:
    def __init__(self):
        self.head=Node('head')
        self.count=0

    #추가
    def append(self,data):
        newNode = Node(data)
        curr=self.head
        for i in range(self.count):
            curr=curr.next
        curr.next=newNode
        self.count+=1
    #삽입
    def insert(self,idx,data):
        if(idx<0 or idx>self.count):
            print("해당 위치 삽입 불가")
            return
        newNode = Node(data)
        curr=self.head
        for i in range(idx):
            curr=curr.next
        if(curr.next is not None):
            temp=curr.next
            curr.next=newNode
            newNode.next=temp
        else:
            curr.next=newNode
        self.count+=1
    #수정
    def update(self,idx,data):
        curr=self.head
        for i in range(idx+1):
            curr=curr.next
        curr.data=data
    #삭제
    def delete(self,idx):
        if(idx<0 or idx>=self.count):
            print("존재하지 않는 인덱스")
            return
        curr=self.head
        for i in range(idx):
            curr=curr.next
        #print(idx,':',curr.next.data)
        temp=curr.next
        if(curr.next.next is not None):
            curr.next=curr.next.next
        else:
            curr.next=None
        del temp
        self.count-=1
    #조회
    def get(self,idx):
        if(idx<0 or idx>=self.count):
            print("존재하지 않는 인덱스")
            return
        curr=self.head
        for i in range(idx+1):
            curr=curr.next
        #print(idx,':',curr.data)
        return curr
    #목록
    def selectAll(self):
        curr=self.head
        while curr.next is not None:
            print(curr.data,end='->')
            curr=curr.next
        print(curr.data)
        curr=self.head
        for i in range(self.count):
            curr=curr.next
        curr.next=newNode
        self.count+=1
    #삽입
    def insert(self,idx,data):
        if(idx<0 or idx>self.count):
            print("해당 위치 삽입 불가")
            return
        newNode = Node(data)
        curr=self.head
        for i in range(idx):
            curr=curr.next
        if(curr.next is not None):
            temp=curr.next
            curr.next=newNode
            newNode.next=temp
        else:
            curr.next=newNode
        self.count+=1
    #수정
    def update(self,idx,data):
        curr=self.head
        for i in range(idx+1):
            curr=curr.next
        curr.data=data
    #삭제
    def delete(self,idx):
        if(idx<0 or idx>=self.count):
            print("존재하지 않는 인덱스")
            return
        curr=self.head
        for i in range(idx):
            curr=curr.next
        #print(idx,':',curr.next.data)
        temp=curr.next
        if(curr.next.next is not None):
            curr.next=curr.next.next
        else:
            curr.next=None
        del temp
        self.count-=1
    #조회
    def get(self,idx):
        if(idx<0 or idx>=self.count):
            print("존재하지 않는 인덱스")
            return
        curr=self.head
        for i in range(idx+1):
            curr=curr.next
        #print(idx,':',curr.data)
        return curr
    #목록
    def selectAll(self):
        curr=self.head
        while curr.next is not None:
            print(curr.data,end='->')
            curr=curr.next
        print(curr.data)

    def sort(self):
        jcP = self.head
        jc = jcP.next
        while jc.next is not None:
            curr=jc
            currP=jcP
            min=curr
            minP=currP
            curr2=curr.next
            curr2P=curr
            while curr2 is not None:
                if min.data>=curr2.data:
                    min=curr2
                    minP=curr2P
                curr2=curr2.next
                curr2P=curr2P.next
            if curr.next==min:
                curr.next=curr.next.next
                currP.next=min
                min.next=curr
            else:
                currP.next=min
                tmp=min.next
                min.next=curr.next
                minP.next=curr
                curr.next=tmp
            self.selectAll()
            jcP=jcP.next
            jc=jcP.next

li= LinkedList()
li.append(8)
li.append(2)
li.append(1)
li.append(5)
li.append(7)
li.append(3)
li.append(6)
li.append(4)
li.sort()
