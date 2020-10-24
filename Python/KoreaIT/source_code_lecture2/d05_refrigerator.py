#냉장고 만들기

#나는 지금 편돌이다.
#안녕하세요 GS25 입니다.
#====판매====
#1. 냉동식품
    #1. 냉동식품 추가하기
    #2. 폐기물 빼기(유통기한 빠른 것부터 뺌)
#2. 음료수
    #1. 음료수 추가하기
    #2. 음료수 빼기
from d05_2 import *
foodItems = LinkedQueue()
drinkItems = LinkedQueue()
print('안녕하세요 GS25입니다.')
print('1. 냉동식품')
print('2. 음료수')
choice = str(input('관리할 항목을 선택해주세요.'))
if choice == '1':
    while True:
        print('1. 냉동식품 추가하기')
        print('2. 폐기물 빼기')
        print('3. 목록 확인하기')
        print('4. 나가기')
        option = str(input('옵션을 선택하세요'))
        if option == '1':
            foodItems.enQueue(str(input('추가할 식품 이름을 입력하세요')))
            #due = int(input('유통기한을 입력하세요'))
        elif option == '2':
            print('폐기물 : ', foodItems.deQueue())
        elif option == '3':
            foodItems.show()
        elif option == '4':
            break
elif choice == '2':
    while True:
        print('1. 음료수 추가하기')
        print('2. 음료수 빼기')
        print('3. 목록 확인하기')
        print('4. 나가기')
        option = str(input('옵션을 선택하세요'))
        if option == '1':
            foodItems.enQueue(str(input('추가할 음료의 이름을 입력하세요')))
            #due = int(input('유통기한을 입력하세요'))
        elif option == '2':
            print('뺀 음료 : ', foodItems.deQueue())
        elif option == '3':
            drinkItems.show()
        elif option == '4':
            break



