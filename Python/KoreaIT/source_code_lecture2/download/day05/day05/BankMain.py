from BankManager import *
bm = BankManager()
while True:
    print("안녕하세요 DS은행입니다.")
    print("1. 대기번호 발급\n2. 순서확인\n3. 다음번호 부르기\n4. 나가기")
    choice=int(input())
    if choice==1:
        #대기번호
        choice=int(input("1. 입출금 관련업무\n2. 예금, 대출 관련업무\n"))
        #함수호출
        bm.numIssue(choice)
    elif choice==2:
        #순서확인
        num=int(input("대기번호 : "))
        #함수호출
        bm.numFind(num)
    elif choice==3:
        #다음번호
        choice=int(input("1. 입출금 관련업무\n2. 예금, 대출 관련업무\n"))
        #함수호출
    elif choice==4:
        print("안녕히가세요")
        break
