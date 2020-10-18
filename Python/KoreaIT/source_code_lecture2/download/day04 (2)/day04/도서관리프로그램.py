#도서관리 프로그램
#1. 도서등록
#2. 도서삭제
#3. 도서검색
#4. 도서정보출력 (제목 : 어린왕자 / 저자 : 생택쥐베리 / 도서번호)
#5. 끝내기

#책 class

#도서번호(ISBN) 1~1000
#도서명
#저자

#(제목 : 어린왕자 / 저자 : 생택쥐베리 / 1)
#(제목 : 너무 쉬운 파이썬 / 저자 : 정다솔 / 28)

#데이터 입력 -> 처리(데이터가공) -> 결과 출력
from 이중연결리스트 import *
class Book:
    def __init__(self,isbn,title,author):
        self.isbn=isbn
        self.title=title
        self.author=author

bookList = DoubleLinkedList()
while True:
    print("1. 도서등록\n2. 도서삭제\n3. 도서검색\n4. 도서목록\n5. 끝내기")
    choice=int(input())
    if(choice==1):#도서등록
        #입력 세개
        #도서번호, 도서명, 저자
        isbn = int(input("도서번호 입력 : "))
        title = input("도서명 입력 : ")
        author = input("저자 입력 : ")
        b = Book(isbn,title,author)
        flag=False
        for i in range(bookList.count):
            if (bookList.get(i+1).data.isbn>isbn):
                bookList.insert(i+1,b)
                #flag가 True로 바뀌지 않는 경우 : for문을 못들어 왔을때(count==0) / if문을 못들어 왔을때(모든 isbn이 내꺼보다 작을때)
                flag=True
                break
        if not flag:
            bookList.append(b)
            
    elif(choice==2):#도서삭제
        #입력 한개
        #ISBN or 도서명
        isbn = int(input("삭제하실 ISBN을 입력하세요 : "))
        flag=False
        for i in range(bookList.count):
            if (bookList.get(i+1).data.isbn==isbn):
                print(bookList.get(i+1))
                bookList.delete(i+1)
                flag=True
                break
        if flag:
            print("도서가 삭제되었습니다.")
        else:
            print("도서 삭제 실패")
    elif(choice==3):#도서검색
        keyword=input("검색하실 도서명 / 저자를 입력하세요 : ")
        for i in range(bookList.count):
            if (bookList.get(i+1).data.title==keyword):
                print("제목 :",bookList.get(i+1).data.title,"/ 저자 :",bookList.get(i+1).data.author,"/",bookList.get(i+1).data.isbn)
        
    elif(choice==4):#도서목록
        for i in range(bookList.count):
            print("제목 :",bookList.get(i+1).data.title,"/ 저자 :",bookList.get(i+1).data.author,"/",bookList.get(i+1).data.isbn)
    elif(choice==5):#끝내기
        print("안녕히가세요")
        break
