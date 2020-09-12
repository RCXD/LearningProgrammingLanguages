# R의 자료구조

## 1. scala라는건 데이터 1개를 의미
x <- 2.7
x
d <- 3
d
y <- 'cha'
y

# 달걀에 색깔이 존재하듯이 
# 스칼라에도 문자, 숫자, 논리값인지 형태가 존재함.
class(x)
class(d)
class(y)



# 2. 벡터(vector)
## - 같은 자료형을 가진 스칼라 값들을 순서를 가지고 일렬로 나열한 구조
a <- 1:5
a
b <- c(1:5)
b
c <- c('a', 'b', 'c')
c
class(a)

## 다른 자료형이 섞인다면?
e <- c(1, '가', '2', TRUE)
e
class(e)


## 데이터 조회
# - c 벡터의 2번쨰 방을 조회해주세요
c[2]
c[c(2, 3)]

w <- c[c(2, 3)]
# w의 1번쨰 방의 데이터를 조회해주세요
w[1]

# c 벡터의 2번째, 3번째방을 조회한 이후에 1번째 방의 데이터를 조회해주세요.
c[c(2, 3)][1]

# 실습하기. drink에서 사이다, 오렌지쥬스, 에너지드링크 값을 출력해주세요
drink <- c('콜라', '사이다', '오렌지쥬스', '에너지드링크')
drink[c(2, 3, 4)]
drink[c(2:4)]

## 벡터를 만드는 다른 방법들
#- 실수로도 가능
c(1.1:10.1)
8.5:10.5
10.5:1.5

#- 함수
# seq(시작값, 끝값, 증가치) 증가치의 기본은 1
seq(1, 10)
seq(1, 20, by = 5)
c(seq(1, 20, by = 5))[3]



# 벡터에 이름을 지정하기
a
names(a)

# 실습하기. a벡터에 이름을 지정해주세요. 
names(a) <- c('a', 'b', 'c', 'd', 'e')
# 'a', 'b', 'c', 'd', 'e'로 지정해주세요.
names(a)
a['c']

# 실습하기. a벡터의 a, c의 데이터를 조회해주세요
a[c('a', 'c')]


# 벡터연산
b * 2

a <- c(1:6)
a
a + 5
a * 5
a %% 2

# a의 1, 3, 5번째 방을 보여주세요
a[c((a %% 2) == 1 )]

# b의 짝수번째 방의 데이터를 모두 조회해주세요
b <- 1:100
b[b%%2==0]



# 3. 행렬(matrix): 행과 열로 이루어진 데이터 구조
# m x n의 형태
# 벡터처럼 동일한 자료형만 가능
# 2차원의 구조
matrix(
    데이터,
    행의개수,
    열의개수
)

matrix(
    c(1, 2, 4, 8, 16, 32),
    nrow=2
)

matrix(
    c(1, 2, 4, 8, 16, 32),
    ncol=2
)

# 데이터를 행으로 채우려면
matrix(
    c(1, 2, 4, 8, 16, 32),
    ncol=2,
    byrow = TRUE
)





f <- matrix(
    c(1, 2, 4, 8, 16, 32),
    ncol=2
)
f
# 실습하기. f에서 값 16을 출력해주세요.
#           (2행, 2열)
f[행, 열]
f[2, 2]

# 실습하기. f에서 1, 3행의 2열을 출력해주세요.
# - 8, 32
f[c(1, 3), 2]


## 매트릭스 이름 붙이기
rownames(f) <- c('a', 'b', 'c')
colnames(f) <- c('d', 'e')
f

## f에서 e열만 출력하기
f[, 'e']

## 실습하기. f에서 a행과 c행의 d열과 e열을 출력해주세요.
f[c('a', 'c'), c('d', 'e')]


# 4. 배열(array): 매트릭스를 3차원의 형태로 만든 구조
# 행, 열, 높이
#array(데이터,
#      (행, 열, 높이) )

arr1 <- array(c(1:16), dim=c(2, 2, 4))



# 배열의 조회
## 실습하기. arr1의 3층을 출력해주세요.
arr1[, , 3]


## 실습하기. arr1의 3층의 1행 2열을 출력해주세요.
arr1[1, 2, 3]
arr1[, , 3][1, 2]



# 5. 데이터 프레임(DataFrame)
## 엑셀과 유사한 형태로 데이터의 유형과 상관없이 2차원의 형태를
## 가지는 데이터 구조

name <- c('korea', 'kim', 'lee')
age <- c(20, 25, 30)

df1 <- data.frame(name, age)
df1[1, 1]
df1[1, 'name']
df1['1', 'name']

# 실습하기. df1에서 name열을 모두 출력해주세요
df1[, 'name']
df1$name


# 조회를 하면서 조건을 부여하기
## df1의 name칼럼의 값이 korea인 데이터 검색하기
df1$name=='korea'
df1[df1$name=='korea', ]

## 실습하기. df1의 age가 25이상인 모든 데이터를 조회해주세요.
df1[age >= 25, ]


# 6. 리스트(list): 벡터나 행렬 등등 모든 데이터 구조를 한번에 
#                  취급가능한 구조
# 몽땅
row <- c('row1', 'row2', 'row3')
col <- c('col1', 'col2', 'col3')
list(row, col)

# 실습하기. 2차원의 데이터를 조회해주세요.
list(row, col)[[2]]
list(row)[[1]][2]


list01 <- list(row=row, col=col)
list01
list01$row


# 리스트에 여러가지 자료구조 담기
a <- c(1:5)
b <- matrix(c(1:6), nrow=3)
df1

list02 <- list(a, b, df1)

# 실습하기. list02의 2차원의 데이터 중에서 
#           1열의 값이 2이상인 데이터만 보여주세요.
#b[, 1] >= 2
#b[b[, 1] >= 2, ]
l <- list02[[2]]
l[l[, 1] >= 2, ]

# 7. 요인(factor)
# 팩터는 순위를 가질 수 있고, 순위가 없을 수 있다.
# 팩터는 문자처럼 보이지만 실제로는 숫자입니다.
# 팩터는 수준(level)이라고 알려진 사전에 정의된 값만 담을 수 있다.

gender <- factor(c('male', 'female', 'male', 'female'))
gender
class(gender)

# 팩터의 levels 조회하기
levels(gender)


# 팩터에 순위가 필요한 경우
a <- c('low', 'medium', 'high')
b <- rep(a, 3)
dust <- factor(b)
dust

## - 팩터를 만들 때 levels를 직접 지정하여 순서를 지정가능
dust <- factor(b, levels = a)
dust


dust <- factor(b, levels = a, ordered = TRUE)
dust
min(dust)
max(dust)


# 팩터는 사전에 정의된 값만 입력 및 수정이 가능합니다.
dust[10] <- 'l'
dust[11] <- 'low'
dust



# 자주 사용되는 함수들
vec1 <- c(1, 2, 3)
vec2 <- c(4, 5, 6)
vec3 <- c(1:4)

## 합치기 
union(vec1, vec2)
union(vec1, vec3) # 중복 값 없이 합쳐짐

## 중복이 되도 합치는 방법
c(1, 2, 3, 1, 2, 3, 4)
c(vec1, vec3)

# 차집합
setdiff(vec3, vec1)
setdiff(vec2, vec1)

# 교집합
intersect(vec3, vec2)
intersect(vec3, vec1)


# paste(붙이기)
paste('a', 'b')  # 기본 구분자는 띄어쓰기
paste('a', 'b', sep=',')
paste('a', 'b', sep='')
paste('a', 'b', 'c', 'd', sep='')
paste0('a', 'b')

# 실습하기. x변수의 각 자리에 x1, x2, x3, x4, x5가 출력되도록 완성시켜주세요.
x <- c(rep('x', 5))
x
paste0(x, c(1:5))

# x변수의 각 자리에 1x, 2x, 3x, 4x, 5x가 출려되도록 완성시켜주세요.
paste0(c(1:5), x)


## which(): 특정 값의 위치를 찾을 수 있는 함수
x <- c(10:1)

### x벡터에서 값 2의 위치를 반환해라.
which(x==2)

### 실습하기. x벡터에서 짝수 값의 위치를 반환해라.
x %% 2 == 0
which(x %% 2 == 0)
x

# x벡터에서 1, 3, 5, 7, 9 번쨰 방을 조회해주세요.
x[which(x %% 2 == 0)]

which.max(x)
which.min(x)


## 데이터 프레임과 자주 사용되는 함수
df_snack <- data.frame(good=c('새우깡', '맛동산', '콘칩', '고구마깡'), 
                       price=c(1000, 1500, 1300, 1000))

df_drink <- data.frame(good=c('콜라', '사이다', '커피'), 
                       price=c(1200, 1500, 2000))

# rbind: row bind로 row(행)을 결합시켜주는 함수
# - rbind는 (위+아래)의 결합으로 열의 개수가 중요합니다.
rbind(df_snack, df_drink)

# cbind: column bind로 col(열)을 결합시켜주는 함수
# - cbind의 결합은 행의 개수가 중요합니다.
df_brand <- data.frame(brand=c('코카콜라', '칠성', '스타벅스'))
df_brand
df_drink
cbind(df_drink, df_brand)


name <- c('김유신', '강감찬', '이순신', '홍길동')
qty <- c(100, 50, 80, 20)
df_buy_history <- data.frame(name, qty)
df_buy_history
# 실습하기. df_buy_date라는 변수를 만드셔서 (입력되는 값은 자유)
#           cbind을 이용하여 df_buy_history와 값을 합쳐서
#           df_buy를 만들어주세요.
df_buy_date <- c(2018, 2015, 2002, 9999)
cbind(df_buy_history, df_buy_date)
df_buy <- cbind(df_buy_history, df_buy_date)

df_buy

name2 <- c('김유신', '김소월', '이순신', '맹장', '홍길동', '공자')
owner <- c(TRUE, TRUE, FALSE, FALSE, TRUE, FALSE)
df_buy2 <- data.frame(name = name2, owner)

df_buy
df_buy2

# row와 col의 개수가 상이하므로 작동하지 않는다.
cbind(df_buy, df_buy2)
rbind(df_buy, df_buy2)


# merge(): 기준에 따라 데이터를 결합할 수 있는 함수
# - sql문의 join과 유사하다.
# - inner join: 교집합
# - left(=right) outer join: 왼쪽(=오른쪽)을 기준으로 합치는 형태
# - full outer join: 전체 합집합

# 1) inner join
# - 두 데이터를 기준 값에 맞는 교집합을 구해라.
merge(df_buy, df_buy2, by='name')

# 2) left outer join: 왼쪽의 조건의 데이터는 다 보이도록 결합
merge(df_buy, df_buy2, by='name', all.x = TRUE)
merge(df_buy, df_buy2, by='name', all.y = TRUE)

# 3) full outer join: 전체
merge(df_buy, df_buy2, by='name', all = TRUE)



# 자주 사용되는 내장 함수
vec1 <- c(1:5)
vec1

## 실습하기. letters를 이용하여 a-e를 vec2로 만들어주세요.
letters
vec2 <- letters[c(1:5)]
vec2

# 합계구하기
sum(vec1)
sum(vec2) # 숫자가 아니므로 불가능

# 중앙값 구하기
median(vec1)
median(vec2)

# 길이 확인
length(vec1)
length(vec2)

# 객체 요약정보
## 최소값, 최대값, 중앙값, 평균값, 사분지표
summary(vec1)
vec1

# table(): 항목의 빈도수 계산
table(owner)

# 데이터 조회
# - head(): 앞에서부터 6개
# - tail(): 뒤에서 6개
m <- c(1:300)
head(m)
tail(m)


# 외부 패키지 사용
install.packages('dplyr')
install.packages('reshape2')
library(reshape2)

## reshape2 데이터의 모양 변환, 데이터 요약에서 많이 사용
smiths

### melt(): 가로 data를 세로 data로 만든다.
melt(smiths)

## melt(식별자)
melt(id=c(1:3), smiths)
smiths

tips
melt(id=c(3:7), tips)


# 문자열 처리 관련 패키지
install.packages('stringr')
library(stringr)

s <- c('korea', 'academy', '2020/08/29')
length(s)
length(s[1])

# 글자 길이 확인하기
str_length(s)

# 부분 참조
str_sub(s, 1, 3)

# 문자열 분리
s[3]
str_split(s[3], '/')
# 실습하기. s[3]을 /로 split하여 2번쨰 방을 조회해주세요.
str_split(s[3], '/')[[1]][2]








