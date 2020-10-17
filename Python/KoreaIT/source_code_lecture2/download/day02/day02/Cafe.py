#카페 프로그램(LinkedList 사용)
#Node의 데이터필드 {메뉴이름:가격} 쌍으로 이루어진 원소 1개짜리 Dictionary
#주문하기, 주문취소, 주문목록 보기, 결제하기, 나가기
from 연결리스트 import *
print("카페 프로그램")
menu={"아메리카노":3000,"카페라떼":4000,"허니브레드":6000}
orderList = LinkedList()
while True:
    print("1. 주문하기\n2. 주문취소\n3. 주문목록\n4. 결제하기\n5. 나가기")
    choice=int(input())
    if(choice==1):
        for key in menu:
            print(key," : ",menu[key],"원",sep='')
        menuChoice = input("주문할 메뉴명 : ")
        orderList.append({menuChoice:menu[menuChoice]})
    elif(choice==2):
        #주문취소
        for i in range(orderList.count):
            for key in orderList.get(i).data:
                print(i+1,key," : ",orderList.get(i).data[key],"원",sep='')
        menuChoice=int(input("취소할 주문번호를 입력하세요 : "))
        orderList.delete(menuChoice-1)

    elif(choice==3):
        #주문목록
        for i in range(orderList.count):
            for key in orderList.get(i).data:
                print(key," : ",orderList.get(i).data[key],"원",sep='')
    elif(choice==4):
        #결제하기
        tot=0
        for i in range(orderList.count):
            for key in orderList.get(i).data:
                print(key," : ",orderList.get(i).data[key],"원",sep='')
        for i in range(orderList.count):
            tot+=list(orderList.get(i).data.values())[0]
        print(tot,"원 결제 완료!")
        orderList.head.next=None
        orderList.count=0
        
    elif(choice==5):
        print("안녕히 가세요")
        break
