#day02_part04
#author : kch
#place : KoreaIT
#date : '20-08-29

##################
# Data Frame
# 이제부터 다른 종류의 Data type을 다룰 수 있다.
# 가장 많이 사용하는 데이터 형태!
# 엑셀과 유사한 형태. 데이터의 유형과 상관없으며
# 2차원 형태를 가짐.
# Qeustion : 심도는 낮을까? DF는 array처럼 3차원을 구현할 수 없을까?


#Definition
name <- c('korea', 'kim', 'lee')
age <- c(20, 25, 30)

data.frame(name, age) 
#추가한 벡터가 열을 기본으로 합쳐진다.
#열의 이름은 변수명이다.
#모든 변수가 클래스로 잡혀서 이렇게 되는거겠지 싶다.

df1 <- data.frame(name, age)
df1
df1[1,1]
df1[1, 'name']
df1['1', 'name']

###Practice###
# df1에서 name열을 모두 출력하기
df1[,'name']
df1$name
#$연산자는 뭐라고 생각하면 되나? 호출하기?
#행도 $로 가능
rownames(df1) <- c('a', 'b', 'c')
df1$a

#Thinking
한글 <- data.frame(name, age)
한글$name #되긴 하는데 자동완성기능만 안되는거 뿐인가?

#Indexing Condition
#df1의 name column에서 값이 korea인 데이터 검색
df1
df1$name == 'korea'
df1[df1$name=='korea', ]

###Practice###
#age가 25이상인 모든 데이터 조회하기
df1
df1[age >= 25, ]



###############
# List
# 아무 제약이 없다.
# 벡터나 행렬 등 모든 데이터 구조를 한번에 취급가능한 구조

row <- c('row1', 'row2', 'row3')
col <- c('col1', 'col2', 'col3')
list(row, col)
#벡터는 보이는데 평면은 보이지않고, 다짜고짜 층부터 나오는데?

###Practicing### 2차원 데이터 Indexing
ls1 <- list(row, col)
ls1[[2]]

###Thinking : 뭔가 이상하다. 실수하기 좋아보이는데
#무슨 의미가 있길래 에러가 안날까?
ls1[1]
ls1[[1]]
ls1[2]
ls1[[2]]
#대괄호가 두 개인 것이 특징
list(row)[1] #원하는 결과 안나옴. 실수하기 딱 좋아보이는데?
list(row)[[1]][2] #차원 먼저 Indexing할 것


ls1 <- list(row=row, col=col) #차원 Naming
ls1
ls1$row #자동완성 사용 가능
#행?은 Naming을 어떻게 하나?


#List에 여러가지 자료구조 담기
a <- c(1:5)
b <- matrix(c(1:6), nrow=3)
df1

ls2 <- list(a, b, df1)
ls2

###Practice###
#ls2의 2차원 데이터 중 1열이 2이상인 데이터만 Indexing
b[b[,1] >= 2,]
l <- ls2[[2]]
l[l[, 1] >= 2,]
#어려운데???





#Vector Testing
c(1, '2', TRUE)[3]
c(1, 2, 3)[1]
TRUE
1

#DF Testing : 한 열은 데이터타입이 같아야하는지?
#벡터를 열로합치는거 말고 행으로 합치는건 가능한지?
#DF의 Transpose가 가능한지?

#List Testing
#List의 Transpose가 가능한지?