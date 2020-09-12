#day02_part02
#author : kch
#place : KoreaIT
#date : '20-08-29


##################
# R의 자료구조
##################
# Scalar
# 데이터 1개를 의미
x <- 2.7
x
d <- 3
d
y <- 'cha'
y
z <- TRUE
z

#Data structure return
class(x) #numeric
typeof(x) #double
mode(x) #numeric

class(d) #numeric
typeof(d) #double"
mode(d) #numeric"

class(y) #character
typeof(y) #character
mode(y) #character

class(z) #logical
typeof(z) #logical
mode(z) #logical

#?? -> https://buillee.tistory.com/83
class(1:4) #integer
typeof(1:4) #integer
mode(1:4) #numeric

class(c(1,2,3,4))  #numeric
typeof(c(1,2,3,4)) #double
mode(c(1,2,3,4)) #numeric

#typeof()와 class()는 무슨차이?

############
# Vector
# 데이터가 한 개의 열로만 나열될 수 있다.
# 원소는 같은 data type을 가져야 한다.

#Vector 정의 방법 2가지
a <- 1:5 #integer (why?)
b <- c(1:5) #numeric (why?)
a
b
#c()는 벡터정의문이다. 
#c는 예약어가 아니어서 변수명으로 사용 가능. 
#다만 썼다간 헷갈릴 뿐

#Complicated Elements
e <- c(1, 'alpha', '2', TRUE)
e
class(e) #character
typeof(e) #character
mode(e) #character
#chracter : 가장 큰 자료형으로 변경된다.
#가장 큰 자료형은 작은 자료형을 표현할 수 있으므로.
#물론 할당되는 메모리가 중요하겠지만.
# '문자열'이 당연 가장 큰 자료형이겠지.

####### Confusing point #######
# 스칼라, 벡터, 리스트, 데이터프레임, ... => Data Structure
# integer, numeric, character, logical, ... => Data type


#Indexing
#R의 벡터는 Indexing이 1부터 센다! 수학처럼.
vec = c('a', 'b', 'c')
vec[2]
# vec[2, 3] #Error. 2개 이상의 인자는 벡터로 전달해야 함
vec[c(2, 3)]

w <- vec[c(2,3)]
w[1]

#c벡터의 2번째, 3번째방을 조회하고 1번째 방의 데이터 조회
vec[c(2,3)][1] #이런 형태 잘 안쓴다나?? 왜? 좋아보이는데

drink <- c('Cola', 'cidar', 'Orange_Juice', 'Redbull')
#범위 Indexing
drink[2:4]
drink[c(2:4)] 


#Alternative
c(1.1:10.1)

#Internal Function seq() 이용
#seq(시작값, 끝값, 증가치) 증가치 default = 1
seq(1, 10) #증가치 = 1
seq(1, 20, by = 5) #아래랑 무슨차이?
c(seq(1, 20, by =5))

#indexing
c(seq(1, 20, by =5))[3] #3번째거 찾기


#Vector Naming
a = c(seq(1,5))
names(a) #Default : NULL

a = c(seq(1,5))
names(a) <- c('a','b','c','d','e')
names(a)
#Naming은 일괄적으로 가능하다. 데이터 대입기능이
#다른 언어에서 보던 것과 매우 다름
#Naming 중복 가능하나 조회시 문제될 수 있다고 함.

a['c'] #c \n 3 ... 이름과 데이터가 출력!

#Practice#
#'a', 'c'의 데이터 조회
a[c('a','c')]
class(a[c('a','c')]) #integer
typeof(a[c('a','c')]) #integer
mode(a[c('a','c')]) #numeric

#Thinking# 이름이 중복되는 경우
b <- a
names(b) <- c('a', 'a', 'b', 'c', 'd')
b['a'] #2도 이름은 a이지만 뒤에있다보니 무시되었음.
b[c('a','a')] #두번 해줘도 무시되었음. 즉, 호출 불가

#벡터 스칼라곱
a * 2
#스칼라를 같은 크기의 벡터로 만들어 원소끼리 곱한다.
#연산이 빠른 것이 특징
#블로그 설명은 엉터리라나...

a*c(2, 3) #연산불가. 원소개수가 배수관계에 있어야 한다!
a*c(1:10) #우변이 커도 가능하다.
#수학에서는 안다루던 곱셈까지 포괄하는거같긴 한데?
#알고리즘은 단순한 것 같다. 아무튼 편리한 기능이라고.

a <- c(1:6)
a+5
a*5
a %% 2

#a의 홀수번째 값 찾기
a[c((a%%2)==1)] #수식/관계식을 만족하는 index를 찾을 수도 있다
a[c(1, 0, 1, 0, 1, 0)==1]

#b의 짝수번째 방의 데이터 모두 조회
b <- 1:100
b[c(b%%2)==0]