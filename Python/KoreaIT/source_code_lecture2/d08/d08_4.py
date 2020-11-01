#실습
#연결리스트 구현
#연결리스트에 삽입하고 정렬하는 것 구현

class Node:
    def __init__(self,data):
        self.data=data
        self.next=None #모든 타입의 초기값

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
        return self
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

    #Practice: 정렬 구현
    def selSort(self):
        curr = self.head.next
        if curr is None:
            if curr.next is None:
                min = self.head.next
                print('-1-',min.data)
                return
            print('데이터가 없으므로 비교 불가합니다.')
            return
        size = self.count
        min = curr #맨앞거가 최소값이라 가정
        for i in range(size-1):
            #인덱스 찾는건 의미없는듯
            for j in range(i+1, size): #i+1번째 데이터 비교 순환
                if min.data >= curr.next.data: #최솟값 찾았을 때
                    min.data, curr.next.data = curr.next.data, min.data
                    curr=curr.next
            min = min.next

    '''
    #(채원)
    def sort(self):
        for i in range(self.count):
            curr=self.head
            for i in range(self.count-1-i):
                if curr.next.data > curr.next.next.data:
                    temp = curr.next.next
                    curr.net.next = curr.next.next.next
                    temp.next=curr.next
                    curr.next = temp
                self.show()
                curr=curr.next

    def show(self):
        curr=self.head
        for i in range(self.count):
            curr=curr.next
            print(curr.data, end=" ")
        print()
    #채원 End
    '''
    
    #수업 - 웹하드...



'''TABLE
curr 
'''
li = LinkedList()
li.append(4).append(2).append(3).append(6).append(8).append(1)
#Output
for i in range(li.count):
    print(li.get(i).data, end=' ')
print()

li.selSort()

#Output
for i in range(li.count):
    print(li.get(i).data, end=' ')
print()

#Testing output
print('hello world')

'''
li=LinkedList()
li.append('A')
li.append('B')
li.append('C')
li.insert(1,'D')
#head->A->D->B->C
li.selectAll()
#head->A->E->B->C
li.update(1,'E')
li.get(2)
li.delete(2)
#head->A->E->C
li.selectAll()
li2=LinkedList()
li2.append(1)
'''
