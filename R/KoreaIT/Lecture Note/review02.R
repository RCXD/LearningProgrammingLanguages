# 1. scala: 데이터 1개를 의미
# - 노란색 달걀, 흰색 달걀이 존재하듯이 
#   문자, 숫자, 논리형이냐의 데이터 형태가 존재
a <- 2.7
b <- 'hello'

a
b

# 데이터 형태 확인
class(a)
class(b)



# 2. vector(벡터): 같은 자료형을 가진 스칼라 값들을 일렬로 나열한 구조
# - 순서를 가지고 있습니다. 순서(index)의 시작은 1로 시작
# - vector에서 요소가 1개인 것이 스칼리이기도 함.
vec1 <- 1:5
vec1

vec2 <- c('a', 'b', 'c', 'd')
vec2

vec3 <- c(TRUE, FALSE, TRUE)
vec3

vec4 <- c(1.1:10.1)
vec4

vec5 <- c(8.5:4.5)
vec5

vec6 <- seq(1, 10, by=2)
vec6

# 벡터에 다른 자료형이 섞인다면?
class(c(1, 2, 3))
class(c(1, '2', 3))
class(c(1, '2', 3, TRUE))

# 벡터의 조회
vec1[3]

# 벡터에 이름지정하기
names(vec1) # 이름 조회하기
names(vec1) <- c('a', 'b', 'c', 'd', 'e')
names(vec1)
vec1

# 실습하기. vec1에서 값 3을 이름으로 조회해주세요.
vec1['c']

# 실습하기. vec1에서 값2와 값4를 이름으로 조회해주세요.
vec1[c('b', 'd')]


vec7 <- vec1[c('b', 'd')]
vec7[1]
vec7[2]

# 벡터연산
# 기존의 프로그래밍과 다른 연산법
# 기존의 프로그래밍에서는 배열(혹은 리스트)의 모든 자리에
# 특정한 연산을 하려면 반복문을 통해서만 가능합니다.
# 벡터 연산은 한번에 모든 자리에 연산을 동시에 실행합니다.

vec1 + 5
vec1 * 2

# 실습하기. vec1의 각 자리의 값이 짝수인지 확인해주세요.
# ex)
vec1
vec1 %% 2
vec1 %% 2 == 0

# 벡터의 값 조회
# - 논리형 값을 가지고 벡터의 조회가 가능하다.
vec1[1]
vec1[2]
vec1[c(TRUE, FALSE, FALSE, FALSE, TRUE)]




# 2. 행렬(matrix): 행과 열로 이루어진 자료구조
# m x n의 형태
# 벡터처럼 동일한 자료형만 저장 가능
f <- matrix(c(1:6), nrow=3, ncol=2)
f

f2 <- matrix(c(1:6), nrow=2, ncol=3)
f2


# 실습하기. f에서 2행 2열을 조회해주세요.
f[2, 2]

# 실습하기. f2에서 2행 2열을 조회해주세요.
f2[2, 2]

# f에서 1열의 모든 행을 조회해주세요.
f[c(1, 2, 3), 1]
f[, 1]

# 실습하기. f에서 1행, 3행의 2열을 조회해서 합계를 구해주세요.
f[c(1, 3), 2]
sum(f[c(1, 3), 2])


# 3. 배열(array): 행과 열이 층으로 이루어진 구조
c(1:16)
array(c(1:16), dim=c(2, 2, 4))
arr1 <- array(c(1:16), dim=c(2, 2, 4))
arr1

# 실습하기. arr1의 2층 방의 총합을 구해주세요.
arr1[, , 2]
sum(arr1[, , 2])

# 실습하기. arr1의 3층 방의 1행의 모든 열을 조회해주세요.
# - 1번째 방법
arr1[, , 3]
arr1[, , 3][1, ]
# - 2째 방법
arr1[1, , 3]

# 실습하기. arr1의 4층 방의 2열의 모든 행을 조회해주세요.
arr1[, 2, 4]

# 실습하기. arr1의 총합을 구해주세요.
sum(arr1)


# 실습하기. arr1의 평균을 구해주세요.
mean(arr1)

# 4. 데이터 프레임: 매트릭스와 같은 행과 열로 이루어진 데이터 구조로
#                   서로 다른 형태의 데이터 형태를 저장할 수 있는 구조
items <- c('콜라', '사이다', '오렌지쥬스', '커피')
prices <- c(1000, 1200, 1500, 3000)

df_drinks <- data.frame(items, prices)
df_drinks

# 실습하기. df_drinks에서 items 열을 조회해주세요.
df_drinks[, 'items']
df_drinks$items

# 실습하기. df_drinks에서 prices 열을 조회해서 총합을 구해주세요.
df_drinks[, 'prices']
sum(df_drinks[, 'prices'])

# 실습하기. df_drinks에서 items의 2행, 4행을 조회해주세요.
df_drinks[c(2, 4), ]


# 데이터 프레임과 자주 사용되는 함수
# - merge: 기준에 따라 데이터를 결합할 수 있는 함수
#  : inner join: 교집합
#  : left(right) outer join: 왼쪽이나 오른쪽에 있는 데이터는 전부 나오도록
#  : full outer join: 합집합
items2 <- c('콜라', '우유', '커피', '탄산수', '토마토쥬스')
etc <- c(TRUE, FALSE, FALSE, TRUE, TRUE)
df_drinks2 <- data.frame('items'=items2, etc)
df_drinks2
df_drinks


# inner join: 교집합
merge(df_drinks, df_drinks2, by='items')

# left(right) outer join: 왼쪽이나 오른쪽에 있는 데이터는 전부 나오도록
merge(df_drinks, df_drinks2, by='items', all.x = TRUE)
merge(df_drinks, df_drinks2, by='items', all.y = TRUE)

# full outer join: 합집합
merge(df_drinks, df_drinks2, by='items', all = TRUE)


# 실습하기. df_drinks와 df_drinks2의 prices의 총합을 구해주세요.
f3 <- merge(df_drinks, df_drinks2, by='items', all = TRUE)
f3
sum(f3$prices, na.rm = T)


# 5. 리스트(list): 가장 큰 데이터 구조로
#                  벡터, 행렬, 배열 등의 모든 데이터 구조를 한번에 처리 가능한 구조

vec1  # 벡터
f     # 매트릭스
arr1  # 배열
f3    # 데이터 프레임

list01 <- list(vec1, f, arr1, f3)
list01

# 실습하기. list01의 4차원의 prices의 총합과 list01의 3차원의 총합의 합을 구해주세요.
list01[[4]]
list01[[4]][, 'prices']
sum(list01[[4]][, 'prices'], na.rm = T)
sum(list01[[3]])

sum(list01[[4]][, 'prices'], na.rm = T) + sum(list01[[3]])

# 실습하기. list01의 1차원의 총합과 2차원의 2열의 총합의 합을 구해주세요.
sum(list01[[1]]) + sum(list01[[2]][, 2])



# 6. 팩터(factor): 데이터구조가 어떤 요인으로 이루어져 있는가
# - 순서가 있을 수도 있고, 없을 수도 있다.
# - 사전에 미리 정의된 값만 넣을 수 있다.
dust <- c('low', 'medium', 'high')
dust

fac01 <- factor(dust, levels = dust, ordered = T)
fac01

min(fac01)
max(fac01)

# 팩터에 값을 추가하기
fac01[4] <- 'law'  # 미리 지정된 값이 아니기 때문에 추가가 불가능
fac01[5] <- 'low'
fac01



# 데이터 조작하기
# - 추가하기
vec1[6] <- 6
vec1
vec1['f'] <- 7
vec1

# - 수정하기
vec1[6] <- 60
vec1
vec1['f'] <- 'a'
vec1
























