#외부(외장) 함수(패키지) 이용하기
#분석가들이 추가해놓은 패키지들

#외부함수 찾기

##1. cran에 들어가서 직접 찾기
##2. RPubs
##3. Amazon AWS

#step1. 설치(최초 1회)
install.packages('lubridate')
#설명 보기 : lubridate 누르고 F1

##이미 있는건지 찾기(??)
#installed.packages('lubridate') (?? 어떻게?)
#step2. 사용
library('lubridate')
now()

now_date <- now()

now_date

#실습1 : now_date에서 연도 출력
year(now_date)
year('2020-09-12') #반드시 문자열형태로 사용!
year('2020/09/12') 

#실습2 : now_date에서 월 출력
month(now_date)

#실습3 : now_date에서 일 출력
day(now_date)

#1day 라는 날짜를 만들기
days(1)

#실습1 : 오늘 날짜에서 1 더하기
now_date + days(1)
#실습2 : 오늘날짜에서 1주일 전 조회
now_date - days(7)
now_date - weeks(1)
#실습3 : now_date의 월을 2월로 변경
month(now_date) <- month(2)     
                  #다른 기본함수와는 다르게, 함수 연산이 객체를 아예 바꿔버린다.
now_date

#now_date에서 연도 변경하기
year(now_date) <- 2019

#생각
# <- 기능에 대한 이해를 R에서는 다시 해야한다. =과는 아주 다른것 같다.
# 반환값자체에 '대입'한다고 생각할 수 있으려나?


#현재날짜에서 now_date를 빼기
now() - now_date


#R에서 자주 사용하는 함수들
vec1 <- c(1:5)
vec1
min(vec1)
max(vec1)

#letters는 a~z까지 기본으로 등록된 데이터셋!
vec2 <- letters[1:5]
vec2
names(vec2) <- toupper(letters[1:5])
vec2

#R에서 기본으로 제공해주는 데이터셋 확인 가능
data()
Orange

#실습1 : Orage의 age의 가장 작은 값과 가장 큰 값을 조회
class(Orange['age'])    #data frame, ...
class(Orange$age)     #numeric
Orange['circumference']
Orange$circumference

min(Orange['age'])

max(Orange['age'])

#실습2 : Orange의 circumference의 평균 조회
mean(Orange['circumference'])   #error : 자료형
mean(Orange$circumference)
#실습3 : 중앙값 조회
median(Orange['circumference']) #error : 자료형
median(Orange$circumference)


#빈도수 계산
table(Orange$Tree)    #3, 1, 5, 2, 4가 각 7개씩 있다는 의미
#길이 계산
length(Orange)        #열이 몇개인지 계산
length(Orange$Tree)   #Tree의 길이 계산

#실습1 : Orange의 Tree가 2인 데이터의 age의 총합 조회
#접근 : 행렬조건을 확인. 행조건 : Tree ==2, 열조건 : age
#Matrix의 인덱싱은 matrix[row, col]임.
Orange[Orange$Tree==2,'age']
sum(Orange[Orange$Tree==2, 'age'])

#실습2 : Orange의 age가 1000이상인 데이터의 circumference의 총합 조회
Orange$age >= 1000
Orange[Orange$age >= 1000, 'circumference']
sum(Orange[Orange$age >= 1000, 'circumference'])

#head(), tail() : 앞끝6개, 뒤끝6개의 원소를 보여주는 함수.
#데이터의 개요를 볼 때 사용

#sample(데이터, 추출개수) : 랜덤한 값을 뽑는 함수
sample(45, 6)

Orange
sample(Orange$age, 6)  # 
sample(Orange$Tree, 6) # => 무작위한 수와 factor형이 만들어졌다...?
sample(Orange$circumference, 6)

#데이터 형변환
num <- c(1,2,3,'4',5)
num
typeof(num)
num <- as.integer(num)
typeof(num)
num <- as.double(num)
typeof(num)
num <- as.numeric(num) #numeric -> double
typeof(num)
sum(num)
#주의 : as.~는 원본 데이터를 변경시키지 않으니, num에 대입하여 사용

#숫자로 변경 불가능한 값(문자)이 껴 있는 경우
num2 <- c(1,2, 'a')
num2 <- as.numeric(num2)
num2            #변경불가능한 것은 NA처리

as.numeric(num2)
as.character(num2)


#대소문자 변경 함수
vec4 <- c('hello', 'HELLO')
toupper(vec4)             #자동고침기능이 있으니 다행이지만 toUpper가 아니다.
tolower(vec4)

#문자열 변경
a <- 'Hello world, korea'
#Hello를 Hi로 변경하기
#gsub(변경할 문자열, 변경될 문자열)
gsub('Hello', 'Hi', a)

#문자열 길이 확인
#length(a)는 데이터의 개수를 셈. 문자열의 길이는 length로 잴 수 없다.
a
length(a) == 1
nchar(a) #공백, 특수문자 문자취급. C언어처럼 마지막에 뭔가 하나 더 있지는 않음
nchar('Hello world, Korea\n') #특수문자는 1


#벡터 관련 함수
vec1 <- c('korea','it', 'r')
vec2 <- c('r', 'g class', 'it')
vec3 <- c('r', 'korea', 'it')


#union() : 합치기(중복 제거. 합집합 개념. 순서는 왼쪽인자 기준)
union(vec1, vec2)
union(vec1, vec3)
#intersect() : 교집합(중복 추출)
intersect(vec1, vec2)
#setdiff() : 차집합(왼쪽 - 오른쪽)
setdiff(vec1, vec2)
setdiff(vec1, vec3) #character(0) -> 자료형은 문자이나 값이 0처럼 없다는 얘기


#벡터 비교하기
vec1
vec3
vec1 == vec3 #이 경우, 같은 index에 있는 요소가 같은지 판단해서 새로운 벡터 반환
#setequal() : 순서에 관계없이 원소 비교
setequal(vec1, vec2)
setequal(vec1, vec3) #TRUE : 내용이 같다는 것

#반복해서 만들기 : rep()
x <- c(rep('x', 5))
x

#실습 : x를 paste0()를 이용해서 x1, x2, x3, x4, x5로 출력
x <- c(rep('x',5))
paste0(x, 1:5)
