#해석되지 않는 코드
'''여러줄 
주석''' #... 사실 주석이라기보다 여러줄 문자열.

#모든 프로그램은 입력 -> 처리 -> 출력 과정을 거침.
print("Hello World!")
print("ㅇㅇ?")

print('엔처 출력 없애기', end='')
print('이어서 출력하기')
print('첫번째', '두번째', sep=' : ')
print("%d"%10)
print('{}'.format(10))
print(f'{10}')

#입력함수 input()
input('정수를 입력하세요') #내부값은 설명임.

#아래와 같다.
print('정수를 입력하세요', end='');input()

#입력값은 문자열이다.
num=int(input('정수를 입력하세요')) #형변환 해야한다.
print(num+5)