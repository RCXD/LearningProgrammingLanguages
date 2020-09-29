# 외부(외장) 함수(패키지)
# - R이 처음 나왔을 때에나 R이 버전업 되면서 추가되는 함수 이외에
#   전세계 분석가가 추가해 놓은 패키지들
#   ex) 스마트폰의 마켓에서 다운받는 앱과 같은 역할

# 외부 함수 이용하는 방법

# step 1. 설치하기(1번만 하면 됨.) ex) 스마트폰에서 어플을 설치하는 개념
install.packages('lubridate')

# step 2. 이용하기(사용할 때마다 해야함) ex) 스마트폰에서 해당 어플을 이용하는 개념
library('lubridate')

now_date <- now()

now_date

# 실습하기. now_date에서 년도를 조회해주세요.
year(now_date)
year('2020/09/12')
year('2020-09-12')

# 실습하기. now_date에서 월을 조회해주세요.
month(now_date)

# 실습하기. now_date에서 일을 조회해주세요.
day(now_date)


# 1day라는 날짜를 만들기
days(1)

# 실습하기. 오늘 날짜에서 1루 더해주세요
now_date + days(1)

# 실습하기. 오늘 날짜에서 1주일 전을 조회해주세요.
now_date - days(7)
now_date - weeks(1)

# 실습하기. now_date의 월을 2월로 변경해주세요.
month(now_date) <- 2
now_date

# now_date의 년도를 변경하기
year(now_date) <- 2019
now_date


# 현재 날짜에서 now_date를 뺴기
now() - now_date



# R에서 자주 사용하는 함수들
vec1 <- c(1:5)
vec1

vec2 <- letters[1:5]
vec2

min(vec1)
max(vec1)


# R에서 제공하는 데이터 집합
data()
Orange

# 실습하기. Orange의 age의 가장 작은 값과 가장 큰 값을 조회해주세요.
min(Orange$age)
max(Orange$age)

# 실습하기. Orange의 circumference 의 평균을 조회해주세요.
mean(Orange$circumference)

# 실습하기. Orange의 circumference 의 중앙값 조회해주세요.
median(Orange$circumference)


# 빈도수 계산 
table(Orange$Tree)


# 데이터의 길이 확인
length(Orange)  # 열의 갯수 확인
length(Orange$Tree)  # 행의 갯수 확인


# 실습하기. Orange의 Tree가 2인 데이터의 age의 총합을 조회해주세요.
head(Orange)
Orange[Orange$Tree==2,]
Orange[Orange$Tree==2, 'age']
sum(Orange[Orange$Tree==2, 'age'])

# 실습하기. Orange의 age가 1000 이상인 데이터의 circumference의 총합을 조회해주세요.
Orange$age >= 1000
Orange[Orange$age >= 1000, ]
sum(Orange[Orange$age >= 1000, 'circumference'])


# sample(데이터, 추출개수): 랜덤한 값을 뽑는 함수
sample(45, 6)

# Orange데이터에서 랜덤하게 age의 데이터를 6개 추출해주세요.
Orange
sample(Orange$age, 6)


# 데이터 형변환
num <- c(1, 2, 3, '4', 5)
num
typeof(num)
as.numeric(num)  # 원본 데이터에는 변경을 시키지 않음
                 # num을 숫자형태로 변경해서 조회해라.
num <- as.numeric(num)
sum(num)

# as.numeric기준으로 숫자로 변경이 불가능한 데이터를 변경하려고 하면
# NA로 변환됩니다.
num2 <- c(1, 2, 'a')
num2
as.numeric(num2)

as.character(num2)


# 대소문자 변경 함수
vec4 <- c('hello', 'HeLLo')
# - 대문자로 변경
toupper(vec4)
# - 소문자로 변경
tolower(vec4)


# 문자열을 변경하기
# - Hello를 Hi 변경하기
a <- 'Hello World, Korea It'
#gsub(변경할 문자열, 변경될 문자열, 데이터)
gsub('Hello', 'Hi', a)


# 문자열의 길이 확인하기
length(a) 
nchar(a) # 공백이나 특수문자로 문자로 취급















# 벡터관련 함수
vec1 <- c('korea', 'it', 'r')
vec2 <- c('r', 'g class', 'it')
vec3 <- c('r', 'korea', 'it')


# union: 합치기(중복된 값을 제거한 이후에 합치기)
union(vec1, vec2)
union(vec1, vec3)

# intersect: 교집합(중복된 값을 추출)
intersect(vec1, vec2)
intersect(vec1, vec3)

# setdiff: 차집합(중복되지 않은 값을 추출)
setdiff(vec1, vec2)
setdiff(vec1, vec3)

# setequal: 순서에 관계없이 모든 원소들이 동일한지 확인
setequal(vec1, vec2)
setequal(vec1, vec3)



# paste(붙이기)
x <- c(rep('x', 5))
x

# 실습하기. x를 paste0을 이용하여  x1, x2, x3, x4, x5로 출력해주세요.
paste0(x, c(1:5))








