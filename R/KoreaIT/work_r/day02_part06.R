#day02_part06
#author : kch
#place : KoreaIT
#date : '20-08-29


#########################
# 자료구조 관련, 자주 사용되는 함수들
vec1 <- c(1:3)
vec2 <- c(4:6)
vec3 <- c(1:4)

#Union : 한 개의 벡터로 합치기. 매트릭스로 만드는건 matrix()를 쓰면 되겠지.
#합집합의 개념
union(vec1, vec2)
union(vec2, vec3) #중복값 4가 제거됨. 순서는 바뀌지 않음. 주의해야함.
#뭐 옵션이 뭔가 더 있겠지.

#중복이 되어도 합치는 방법 : c(=combine) 함수 이용
c(1,2,3,1,2,3,4)
c(vec2, vec3)

#차집합
setdiff(vec3, vec1)
setdiff(vec2, vec1)

#교집합
intersect(vec3, vec2)
intersect(vec1, vec3)
intersect(vec1, vec2) #공집합인 경우. #integer(0)??

#문자열, 데이터 붙이기
paste('a', 'b') #기본 구분자는 공백문자
paste0('a', 'b') #구분자 없음
paste(1, 2) #1 2 ... 숫자도 문자취급
paste0(1, 2) #12
paste0(1, TRUE) #1TRUE ... 모두 문자취급. 덧셈이 아니다.

###Practice###
#x변수 각 자리에 x1, x2, ..., x5가 출력되도록 완성

x <- paste0(rep('x', 5), (1:5))
x <- paste(c(rep('x', 5)), c(1:5)) 
x 
#굳이 c 남용할 필요가 없는거 같은데? 왜 1개 인자에 대해 c를 쓰는거지? 나중에 Vector~Matrix쪽 복습하면서 찾아봐야함!

#x변수의 각 자리에 1x, 2x, ..., 5x 출력
x <- paste0((1:5), rep('x',5))
x

#which() : 특정 값의 '위치(indexing No.)'를 찾을 수 있는 함수
x <- c(10:1)
which(x==2)

###Practice###
#x벡터에서 짝수 값의 위치 반환
x
which(x%%2==0)

###Indexing### 짝수만 골라내기
x[which(x%%2==0)]

#최댓값, 최솟값이 있는 위치(indexing No.) 찾아주는 매소드
which.max(x)
which.min(x)


############################
#Data Frame과 자주 사용되는 함수
df_snack <- data.frame(good=c('Sae', 'Mat', 'Corn', 'Gogu'),
                       price=c(1000, 1500, 1300, 1000))
df_drink <- data.frame(good=c('Cola','Cidar','Coffee'),
                       price=c(1200,1500,2000))

#rbind : row bind : 행(row)을 결합시켜주는 함수
# 위+아래의 결합을 출력 열의 개수가 중요
rbind(df_snack, df_drink)

#cbind: col bind
# 두 개의 인자를 좌+우로 합쳐서 출력. 행의 개수가 중요
df_snack
df_drink
cbind(df_snack, df_drink) #Error : 행의 개수가 달라서 안됨.

#paste랑은 무관. c() : combine 함수랑 일맥상통하는듯?

df_brand <- data.frame(brand=c('Coka', 'Chil', 'Star'))
cbind(df_drink, df_brand)
cbind(df_brand, df_drink)

name <- c('Kim', 'Kang', 'Lee', 'Hong')
qty <- c(100, 50, 80, 60)
df_buy_history <- data.frame(name, quality=qty)
df_buy_history

###Practice###
#df_buy_date 변수와 cbind하여 df_buy를 만들 것
df_buy_date <- data.frame(date=c(1931, 1910, 2013, 2015))
#data frame의 인자에 이름지정 form을 안지키면 개판되네
df_buy <- cbind(df_buy_history, df_buy_date)
df_buy

name2 <- c('Kim', 'So', 'Lee', 'Hwang', 'Hong', 'Kong')
owner <- c(TRUE, TRUE, FALSE, FALSE, TRUE, FALSE)
df_buy2 <- data.frame(name=name2, owner) #굳이 onwer=owner로 표현 안해도 됨!

df_buy
df_buy2

#binding 불가
#cbind(df_buy, df_buy2) #행의 개수가 다름
#rbind(df_buy, df_buy2) #열의 개수가 다름

####################################
# Merge : 병합. 기준에 따라 데이터를 결합할 수 있음
# database의 sql문에서 join과 유사(structure query language)
# inner join : 교집합
# left(=right) outer join : 왼쪽(=오른쪽)을 기준으로 병합
# full outer join : 전체 합집합


#inner join : 기준에 따라 교집합 만들기(단, 열값은 모두 살림)
df_buy
df_buy2
merge(df_buy, df_buy2, by='name') 
#R에서 우변엔 클래스명은 안쓴다고 생각하자. by=name은 에러남. 
#변수를 대입할 때 빼고는 by='name'을 꼭 갖추도록.

df_buy
df_buy2
#왼쪽 인자(df_buy)에 df_buy2를 흡수. 값이 없으면 NA를 가짐
merge(df_buy, df_buy2, by='name', all.x=TRUE)
#오른쪽 인자(df_buy2)에 df_buy를 흡수. 값이 없으면 NA를 가짐
merge(df_buy, df_buy2, by='name', all.y=TRUE)
#full outer join : 전체 병합(합집합) : 없는 값은 NA
merge(df_buy, df_buy2, by='name', all=TRUE)

##Thinking
#없는 값을 NA로 채울지, 뭘로 채울지는 옵션에 있을 것 같다. 분명.


#자주 사용되는 내장 함수
vec1 <- (1:5)
vec1

###Practice### letters를 이용해서 a~e를 vec2로 만들기
#letters는 알파벳 26자를 포함하는 벡터
#[~:~] 꼴에서 수식은 넣을 수 없음. indexing에서만 사용 가능
vec2 <- letters[1:5]
vec2

#합계 구하기
sum(vec1)
sum(vec2) #에러

#중앙값
vec1A <- c(1, 3, 2, 4, 5)
vec2A <- c('ab', 'cc', 'd', 'e','i')
median(vec1)
median(vec1A) 
median(vec2) #가중치가 적용된 알파벳의 중간값! 위치가 중간이 아님.
median(vec2A) #d?? 뭐지?
#통계학에서 평균보다 나은 정보라나...?

#벡터의 길이 확인 *문자열길이가 아님
length(vec1)
length(vec2)

#객체의 요약정보
##최소값, 최대값, 중앙값, 평균값, 사분지표(1/4, 3/4지점)
summary(vec1)
summary(vec1)['1st Qu.']
#통계학에서, "연봉, 소득, 키 등은 절대 평균으로 나타내어선 안된다"
#분포가 큰 데이터는 평균의 오류가 발생하기 쉽다는 말인가?


#table 함수 : 항목의 빈도수 계산
owner
table(owner)

# 데이터 조회(Access?) => 데이터 시각화할 때 사용
#head(), tail() > 앞에서부터 6개, 뒤에서부터 6개 출력
m <- c((200:180), (300:350))
head(m) #크기순서와는 상관없음.
tail(m)

##################
#외부 패키지 사용

##################
#데이터 가공 패키지
install.packages('dplyr')
install.packages('reshape2')
library('dplyr')
library('reshape2')

#reshape2 : 데이터의 모양 변환, 요약에서 많이 사용
#smiths : 교육용 데이터
smiths

#melt() : 가로 데이터를 세로 데이터로 가공함.
#transpose랑은 다르다!
melt(smiths)
#첫 열은 그대로 두고, 나머지 열 데이터를 variable로 담고
# 대응하는값은 value 에 담아 모양을 자동으로 '가공'함.
melt(id=(1:3), smiths)
#식별자(id)를 이용해서 놔둘 열을 선택할 수 있음


#교육용 데이터
tips
melt(id=(3:7), tips)

######################
#문자열 처리 관련 패키지
install.packages('stringr')
library('stringr')

s <- c('korea', 'academy', '2020/08/29')
length(s) #3 -> s 벡터의 길이
length(s[1]) #1 -> 스칼라값 'korea'의 길이

#길이 구하기
str_length(s)

#부분 참조
str_sub(s, 1, 3) #s 벡터의 각 문자열에서 첫번째~3번째 문자만 추출

#문자열 분리
s[3]
str_split(s[3], '/')

###practice###
#s[3]을 /로 split한 벡터의 2번째 값을 조회
a <- str_split(s[3], '/')
a[[1]][2]

str_split(s[3], '/')[[1]][2]
#반환값이 list이다! 출력창을 신경써서 보지않으면 실수한다.

