class Node:
    def __init__(self, data):
        self.data = data
        self.prev=None
        self.next=None

class DoubleLinkedList:
    def __init__(self):
        self.head=Node('head')
        self.tail=Node('tail')
        self.head.next=self.tail
        self.tail.prev=self.head
        self.count=0
    #추가
    def append(self,data):
        newNode=Node(data)
        newNode.next=self.tail
        newNode.prev=self.tail.prev
        self.tail.prev.next=newNode
        self.tail.prev=newNode
        self.count+=1
        
    #삽입
    def insert(self,idx,data):
        if idx>self.count:
            return
        newNode=Node(data)
        if idx <= self.count/2:
            curr=self.head
            for i in range(idx-1):
                curr=curr.next
            newNode.prev=curr
            newNode.next=curr.next
            temp=curr.next
            curr.next=newNode
            temp.prev=newNode
            
        #idx가 꼬리에 가까운 위치
        else:
            curr=self.tail
            for i in range(self.count-idx+1):
                curr=curr.prev

            newNode.prev=curr.prev
            newNode.next=curr

            curr.prev.next=newNode
            curr.prev=newNode
            
                
        self.count+=1
    #수정
    def update(self,idx,newData):
        if idx>self.count:
            return
        curr=None
        if idx <= self.count/2:
            curr=self.head
            for i in range(idx):
                curr=curr.next
        else:
            curr=self.tail
            for i in range(self.count-idx+1):
                curr=curr.prev
        curr.data=newData
            
    #삭제
    def delete(self,idx):
        if idx>self.count:
            return
        curr=None
        if idx <= self.count/2:
            curr=self.head
            for i in range(idx-1):
                curr=curr.next
            curr.next.next.prev=curr
            curr.next=curr.next.next
                      
        else:
            curr=self.tail
            #curr=self.get(idx+1)
            for i in range(self.count-idx):
                curr=curr.prev
            curr.prev.prev.next=curr
            curr.prev=curr.prev.prev
        self.count-=1

    #조회
    def get(self,idx):
        if idx>self.count:
            return
        curr=None
        if idx <= self.count/2:
            curr=self.head
            for i in range(idx):
                curr=curr.next
        else:
            curr=self.tail
            for i in range(self.count-idx+1):
                curr=curr.prev
        #print(curr.data)
        return curr #주소를 주고 엑세스할 수 있도록 만듦
    #목록(인덱스 오름차순)
    def ascShow(self):
        curr=self.head
        for i in range(self.count):
            print(curr.data,end="→")
            curr=curr.next
        print(curr.data)
    #목록(인덱스 내림차순)
    def descShow(self):
        curr=self.tail
        for i in range(self.count):
            print(curr.data,end="→")
            curr=curr.prev
        print(curr.data)
    def show(self,flag=True):
        if flag:
            self.ascShow()
        else:
            self.descShow()
    def indexOf(self, data): 
        curr=self.head
        for i in range(self.count):
            curr=curr.next
            if curr.data == data: 
                return i+1 




class Book:
    #data = dict({bookName:'', writer:'', bookNum:0})
    #data = dict()

    def __init__(self, bookName='', writer='', bookNum=0):
        self.bookName = bookName
        self.writer = writer
        self.bookNum = int(bookNum)
        #self.data = {'도서명' : bookName, '저자' : writer, 'ISBN' : bookNum}


#from 이중연결리스트 import *
bookList = DoubleLinkedList()
while True:
    print("1. 도서등록\n2. 도서 삭제\n3. 도서검색\n4. 도서목록\n5. 끝내기")
    choice = int(input())
    if(choice==1): #도서 등록
        #입력 3개
        #도서번호, 도서명, 저자
        #print('도서번호, 도서명, 저자를 입력하세요.')
        #bookName, writer, bookNum = map(str, input())
        bookName = input('도서명: ')
        writer = input('저자: ')
        bookNum = int(input('도서번호: '))
        bk = Book(bookName, writer, bookNum)
        flag = False
        for i in range(bookList.count): #count=0일때 for문이 돌지 않음!! range(0)은 빈 리스트(?)임!
            if bookList.get(i+1).data.bookNum > bookNum: #노드 가져오기. index가 1부터 시작하므로 i+1
                #이전에 입력된 isbn보다 크면 추가한다.
                bookList.insert(i, bk)
                #스캔하면서 작거나 같을경우엔 추가되지 않는 개념

                #flag 설정
                #flag가 True로 바뀌지 않은 경우 : for문 못들어왔을 때(count==0)
                #if 문 못들어왔을 때(모든 isbn이 내꺼보다 작을 때)
                flag = True
                break
        if not flag: #count==0일때는 choice==4처럼 해결 가능
            #단, 모든 원래의 bookNum이 추가하려는 bookNum보다 작으면 그때도 처리해야 함
            bookList.append(bk)

    elif(choice==2): #도서 삭제
        #입력 1개
        #ISBN or 도서명
        bookNum = int(input('삭제할 ISBN 입력: '))
        flag = False
        for i in range(bookList.count):
            if(bookList.get(i+1).data.bookNum == bookNum):
                bookList.delete(i+1) #뭐지? delete함수 확인바람. 안지워짐
                #print('delete'+str(i+1)) #debug
                flag=True
                break #이걸 안쓰면 문제? tail, head를 가져오지 않기 위함
        if flag: #단지 안내문 출력을 위한 것...? 따로 안빼도 될거같은데.
            print('도서가 삭제되었습니다.')
        else:
            print('도서 삭제 실패')
    elif(choice==3): #도석 검색
        keyword = input('검색하실 도서명 / 저자를 입력하세요')
        #for i in range(): 마저 만들어보자....!!!
    elif(choice==4): #도서 목록
        if(bookList.count==0):
            bookList.append(bk)
        for i in range(bookList.count): #count=0일때 for문 안돈다?? 정말 그런가?
            print('제목:', bookList.get(i+1).data.bookName, \
                '/ 저자 :', bookList.get(i+1).data.writer, \
                    '/', bookList.get(i+1).data.bookNum) #기본 sep=' '
    elif(choice==5): #끝내기
        print('안녕히 가세요')
        break
