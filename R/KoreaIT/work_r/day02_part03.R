#day02_part03
#author : kch
#place : KoreaIT
#date : '20-08-29

########
# Matrix
# 계란판을 연상. 엑셀과 유사
# 같은type의 데이터가 들어가야함.
# m x n 형태
# 2차원 구조
# matrix(
#     data
#     # of Raw
#     # of Column
# )

#행 정의해서 만들기
matrix(
    c(1, 2, 4, 8, 16, 32),
    nrow = 2
)
#행을 정의했으면 열을 굳이 정의하지 않아도 됨.
#기본 정의 순서 : 열 먼저 채우기

#열 정의해서 만들기
matrix(
    c(1, 2, 4, 8, 16, 32),
    ncol = 3
)

#데이터를 행으로 채우기
matrix(
    c(1, 2, 4, 8, 16, 32),
    ncol=2,
    byrow = TRUE
)
# byrow 말고도 옵션이 많음.

###Practice###
f <- matrix(
    c(1,2,4,8,16,32),
    ncol=2
)
f
#Matrix Indexing
f[2,2] #16

#대괄호에 index를 두 개 전달하면 Matrix이다.
#따라서 Vector에서 여러 인자를 전달할 때 c()를 사용하는 것임.

###Practice###
#1, 3행의 2열 출력하기
f[c(1,3),2]
#원하는 행에서 특정 데이터만 가져올 수 있다.
#f[(1,3),2] 
#당연히 이건 안된다! 인자가 2개이상인 소괄호는 c가 꼭 필요함!!

#Matrix Naming : rownames, colnames
rownames(f) <- c('a', 'b', 'c')
colnames(f) <- c('d', 'e')
f #출력창에 행, 열을 표시하던 문자가 대체됨


#f에서 e열만 출력하기
f['e'] #NA. 실수하기 딱 좋을듯? 아무것도 나오지 않으니
f['a'] #NA. 행이름도 의미없다. 벡터는 무조건 2개의 인자를 보내야.
     #근데 왜 오류처리를 하지않고 굳이 NA를 출력해주는건지?
f[,'e'] #답

###Practice###
#f에서 a행과 c행의 d열과 e열 출력하기
f[c('a','c'),c('d','e')]

#############
# Array
# 여러층의 Matrix 형태.
# 모든 원소의 data type은 동일하다.
# Data 분석때 많이 쓰지는 않는다고. 
# pandas에 배열과 비슷한게 있지만, '기본' Python에는 배열이 존재하지 않는다.
# 데이터 분석할 때 가치가 있다.
# 3차원은 사용이 어렵다. -> 범용성은 떨어진다.

#Array : 매트릭스를 3차원 형태로 만든 구조.
#행, 열, 높이
#array(Data,
#     (Raw, Column, Height)
#)

#Definition
array(c(1:16), dim=c(2,2,2))

#Indexing Practice
#arr1의 3층
arr1 <- array(c(1:16), dim=c(2,2,4))
arr1
arr1[,,3]

#arr1 3층 1행 2열
arr1[1,2,3]
arr1[,,3][1,2]
#두 방법 다 유용하다고. height를 일반적으로 의미부여하기에는 어려울테니까

#array에는 어떤 옵션이 있으려나?