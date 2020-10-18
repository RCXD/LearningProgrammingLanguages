# 다시 해결해보자...
from 연결스택 import *

urlList = LinkedStack()


while True:
    flag = False
    if flag:
        print('현재 페이지:'+urlList.head.next.data)
    if not flag:
        print('현재 페이지: 없음')
    print('1. URL 이동')
    print('2. 뒤로가기')
    print('3. 앞으로 가기')
    print('4. 방문 기록')
    print('5. 나가기')

    menu = int(input())

    if menu == 1: #URL 이동
        go()
        curr = urlList.head
        urlList.push(input('URL을 입력하세요: '))
        print('pushed '+urlList.curr.next.data)
        flag = True
    elif menu == 2: #뒤로 가기
        pass
    elif menu == 3: #앞으로 가기
        
        pass
    elif menu == 4: #방문 기록
        urlList.selectAll()
        pass
    elif menu == 5:
        print('안녕히 가세요')
        break
