# review01

## Alt + enter: 실행 후에 해당 라인에 멈춤.(코드를 재실행 할 때 유용함)
## Ctrl + enter: 실행 후에 다음 실행 라인으로 이동.

## Hello World
print('Hello World')
'Hello World'
a <- 'Hello World'
a


## 기본 연산
# - 사칙연산
1 + 1
2 - 2
3 * 3
4 / 4

# 몫과 나머지를 같이 연산하는 방법
7 / 3
7 %/% 3 # 몫만 연산
7 %% 3  # 나머지만 연산


# - 비교 연산자
## : 결과 값이 논리값임.
x <- 10
y <- 20

x == y
x != y
x > y
x < y
x >= y
x <= y


# 논리 연산자
#! 아니다.(역)
!TRUE
!(1 == 1)

#| or: 둘 중에 하나라도 참이면 참
TRUE | FALSE
(1 == 1) | (1 != 1)
(1 != 1) | (1 == 1)

#& and: 두 조건이 모두 참이여야 참
(1 == 1) & (1 != 1)
(1 != 1) & (1 == 1)
TRUE & TRUE


# 조건문
if(TRUE) {
    print('조건이 참이므로 실행')
}

if(FALSE) {
    print('조건이 거짓이므로 실행 안됨')
}

# if조건문에 따라서 money의 값을 변경하기
money <- 17000
money

# 실습하기. money가 5000원 이상이면 money에서 5000원 빼기  
#           money가 5000원 미만이면 맥심을 마시자를 출력해주세요.
#           맥심은 1000원입니다.
if(money >= 5000) {
    money <- money - 5000
} else if(money < 1000){
    print('돈이 없네요.')
} else {
    print('맥심을 마시자')
    money <- money - 1000
}

money

# 조금 특별한 조건문
#ifelse(조건, 참일때, 거짓일때)
ifelse(money > 1000, '맥심을 마실 수 있겠네요.', '돈이 없네요.')

# 실습하기. y가 5의 배수이면 제곱을 출력하고, 아니면 0을 출력해주세요.
y <- 5
if(y %% 5 == 0) {
    print(y ^ 2)
} else {
    print(0)
}

ifelse(y %% 5 == 0, y^2, 0)



# 조건문2. switch문
# - 한글의 경우 switch문보다는 if문이 좋습니다.
x <- 'java'
switch(x
       , 'c언어' = print('임베디드에서 자주 사용됩니다.')
       , 'java' = print('웹 프로그래밍의 왕')
       , 'R' = print('통계분석, 빅데이터에서 사용')
       , print('해당 언어는 모르겠습니다.')
       )



# while조건문: 조건이 참일 동안에 계속
# ex) 다이어트를 하는데, 10kg 빠질 동안에 운동장을 뛰어야지.
#     10kg가 빠질 동안에 운동장을 몇 바퀴 뛰어야하는지는 모름
cnt <- 1
while(cnt < 7) {
    print(cnt)
    cnt <- cnt + 0.3 # cnt의 값을 변경하지 않으면 무한 루프에 빠집니다.
}


# for 조건문: 횟수의 정함이 있는 조건문
v <- 1:4
for(i in v) {
    print(i)
}


# 변수: 변화하는 수
# - 하나의 데이터를 담을 수 있는 공간을 부르는 이름
# - 변수에는 스칼라, 벡터, 매트릭스 등등의 데이터 구조가 저장되어있음.

## 변수에 값을 담는 방법(대입)
a <- 1
b = 2
3 -> c
a
b
c

# 현재 저장되어있는 변수를 조회하는 함수
ls()
objects()

# 변수의 초기화(삭제)
a <- 1
rm(a)
a

# 모든 변수를 초기화
rm(list=ls())
ls()


### 함수: 특정한 동작을 사전에 정의한 명령어 집합
# 내장 함수: r이 기본적으로 가지고 있는 함수
log10(100)   # 10의 몇 승인가

floor(3.14)    # 버림
ceiling(3.14)  # 올림
round(3.14)    # 반올림
round(3.54)    # 반올림

# round(반올림)는 홀수일 경우와 짝수일 경우에 연산 방식이 달라진다.
round(3.15, 1)    # 반올림
round(3.16, 1)    # 반올림
round(4.15, 1)    # 반올림
round(4.16, 1)    # 반올림

round(3.15, 2)    # 반올림


a <- 1:5
min(a)
max(a)
mean(a)
sum(a)


# 붙이기 
paste('앞의 값과', '뒤의 값을 붙입니다.', sep=', ')


### 데이터 형태(유형)
'문자'
typeof('문자')
1
typeof(1)
1.1
typeof(1.1)
TRUE
typeof(TRUE)


# NA형과 NULL
## - NA(Not Avaliable)로 결측치(값이 빠져있음)를 의미
##   : 데이터가 있지만 어떠한 값인지 모르는 경우. 값이 있는데 표현을 못하는 경우
## - NULL: 객체 없음. 미정의 값
##   : 현재 데이터가 아예 없는 경우

# NA 예제
1 + 1
1 + NA  # 연산의 결과는 NA
1 * NA

c(1, 2, 3)
sum(c(1, 2, 3))
sum(c(1, NA, 3))
# NA를 무시하고 연산하는 방법
sum(c(1, NA, 3), na.rm = T)

# NULL 예제
1 + NULL
1 * NULL
sum(c(1, NULL, 3))

































































