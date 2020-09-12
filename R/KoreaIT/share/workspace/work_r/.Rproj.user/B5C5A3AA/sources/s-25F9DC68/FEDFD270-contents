# 조건문
## 조건을 검사하여 참(True)일 때와 거짓(False)일 때
## 실행이 다르게 되는 기법(문법)

### 1. if조건문
#if(조건) {
#    조건이 참일 경우 실행
#}

if(TRUE) {
    print('조건이 참이므로 실행')
}


### 2. if else 조건문
### - if 혹은 else 둘 중에 하나는 무조건 실행
if(FALSE) {
    print('조건이 참이면 실행')
} else {
    print('조건이 거짓이면 실행')
}
x <- 1
if(FALSE) {
    x <- 3
}
x


# 실습하기. money가 5000원 이상이면 라떼를 마시고,
# 5000원 미만이면 맥심을 마시는 조건문을 만들어주세요.
money <- 10000
if(money >= 5000) {
    print('라떼를 마시자')
} else {
    print('맥심을 마시자')
}

# if - else if - else
## - else if는 무한대로 만들 수 있습니다.
# money가 실행될 때마다 값을 변경
## - money가 1000원 미만이면 잔액이 부족합니다를 출력
money
if(money < 5000 & money >= 0) {
    print('맥심을 마시자')
    money <- money - 1000
} else if(money < 1000) {
    print('잔액이 부족합니다.')
} else {
    print('라떼를 마시자')
    money <- money - 5000
}



# switch 문
## - if문과 동일한 기능의 조건문이지만 가독성이 더 뛰어남
#switch(표현식,
#    case1,
#    case2,
#    case...,
#    default
#)


switch("pwd",
       id='hong',
       pwd='1234',
       name='홍길동'
       )

# 조금 특별한 조건문
## 삼항조건문
#ifelse(조건, 참일경우, 거짓일경우)
ifelse(TRUE, '참', '거짓')
ifelse(FALSE, '참', '거짓')

# 실습하기. y가 3의 배수면 제곱을 출력하고, 아니면 0을 출력해주세요.
## - 어떤 수를 3으로 나눈 나머지가 0이면 3의 배수입니다.
y <- 3
y %% 3 == 0
ifelse(y %% 3 == 0, y^2, 0)


# while 반복문
## - 조건이 만족하는 동안 계속 반복
## - 횟수는 중요하지 않음
cnt <- -5

## cnt가 7보다 작을 때까지 실행해라.
while(cnt < 7) {
    print(cnt)
    cnt <- cnt + 0.3
}


# for는 반복 횟수의 정함이 존재함
v <- 1:4
for(i in v) {
    print(i)
}

# 실습하기. items를 반복실행하여 과자를 출력해주시고, 
#           맛동산일 경우에만 정말 맛있겠다를 추가로 출력해주세요.
# ex) 새우깡
#     고구마깡
#     맛동산
#     정말 맛있겠다
#     꼬북칩
items <- c('새우깡', '고구마깡', '맛동산', '꼬북칩')
for(item in items) {
    print(item)
    if(item == '맛동산') {
        print('정말 맛있겠다.')
    }
}


## 함수: 미리 정의한 명령 집합
# 내장함수: R에서 기본으로 가지고 있는 함수
# 외장함수: 외부 패키지 설치를 하면 사용할 수 있는 함수
# 사용자 정의 함수: 직접 만드는 함수
함수이름 <- function(param){
    실행코드
}


fruits <- function(p){
    if(p == '바나나') {
        'very good'
    } else if(p == '사과') {
        'good'
    } else if(p == '딸기') {
        'good good'
    } else {
        'Soso'
    }
}

fruits('바나나')
fruits('배')
fruits('사과')




















