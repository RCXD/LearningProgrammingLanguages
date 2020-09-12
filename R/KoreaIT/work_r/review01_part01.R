#Logical data
#Python에서는 True/False, R에서는 TRUE/FALSE, T/F도 가능!
print(T == TRUE)
###
print(T == 2)  #이건 거짓이다! (C언어였으면 참임.)
print(T == 1)  #이건 참이다.

#switch문
x <- 3
switch(x
       , '1' = print('C')
       , '2' = print('D')
       , #3 = print('E')  #이러면 에러
       )


switch(x
       , '1' = print('C')
       , '2' = print('D')
       , #3 = print('E')  #이러면 에러
)

#유니코드, 한글은 switch문에서 에러가 날 가능성이 있다.
#버전에 따라 안날 수도 있는데, 한글을 써야 할 경우 가급적 if문을
#사용하는것이 좋다고 함.

z <- 'C언어'
switch(z
       , 'C언어' = print('임베디드에서 자주 사용됩니다.')
       , 'java' = print('웹 프로그래밍의 왕')
       , 'R' = print('통계분석, 빅데이터에서 사용')
       , print('해당 언어는 모르겠습니다.')
       )
#4.0.0에서 에러가 나지는 않았음. 3.x.x.에서는 에러가 발생한다고 함.

### 심화 ###
#Rstudio 무한루프 빠져나오는 방법 : 
#  상단메뉴 - Terminate R, Restart R, interrupt R 하면 된다고 함.
#  반드시 되는건 아니라나?
#단축키가 필요하면 Tool 메뉴에서 Keymapping해서 사용할 수도 있다고 함.
#그래도 안되면 작업관리자에서 R을 종료
#몇백만건 이상의 데이터를 처리해야할 때 죽는 경우가 있다고 함.

#while문 : 조건이 중요한 경우?
cnt <- 1
while(cnt < 7)
{
        cnt <- cnt+1
        print(cnt)
}
        
#for 조건문 : 실행횟수 결정 가능
v <- 1:4
for(i in v) {
        print(i)
}

# 변수에 값 담는 방법
xx <- 1
1 -> yy
zz = 1
# 변수 삭제(초기화)
rm(xx, yy, zz)

### 심화 ###
#현재 저장된 변수를 조회하는 함수
ls() #R studio에 저장된겄가지 나와서 실제 저장된거와는 다를 수 있다나?
objects() #ls()와 같음

#모든 변수 초기화 방법
list = ls()
#rm(list) #왜 이건 반응이 없지?
rm(list=ls())

floor(3.14)
ceiling(3.14)
round(3.14)
round(3.54)
round(3.15, 1)  #3.15를 소수점 첫번째까지 표시
round(3.16, 1)
round(4.15, 1)
round(4.16, 1)
round(3.15, 2)

##참고 문헌 https://m.blog.naver.com/coder1252/220931274381


#최소, 최대, 평균, 총합
a <- 1:5
min(a)
max(a)
mean(a)
sum(a)
summary(a)

#문자열 연결하기
paste('앞의 값과', '뒤의 값을 붙인다.', sep=', ')

#현실에서 존재하는 자료형
'문자'
typeof('문자')  #character. string이라 부르지 않음
typeof(1)       #정수도 double임
typeof(1.1)
typeof(TRUE)    #logical

### 심화 ###
#NA형과 NULL
## NA(Not Available)로 결측치(값이 빠져있음)를 의미
## NULL : 객체가 없음을 의미
# 다른언어에서는 NA, NULL을 잘 구분하지 않는다.
# 데이터가 중요한 언어다보니 NA와 NULL을 구분하는것은 R에서 중요하다.

#예제
1+1
1+NA    #NA와의 연산결과는 NA다.
1*NA
1+NULL  #numeric(0)
1*NULL
length(c(1, NULL, 3))   #length = 2
length(c(1, NA, 3))     #length = 3

sum(c(1, NULL, 3))   #sum 가능. 엑셀에서 빈공간과도 합산이 가능한것처럼.
sum(c(1, NA, 3))     #sum 불가

# NA 무시하는 방법(NA 삭제)
sum(c(1, NA, 3), na.rm = T)
sum(c(1, NA, 3), na.rm = TRUE)


#참고문헌 : https://nittaku.tistory.com/329
#NaN, Inf도 있다.
#NaN : 수학적으로 정의 불가한 수
#Inf : 무한값
3/0 #Inf
0/0 #NaN
