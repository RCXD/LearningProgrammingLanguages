#데이터 분석이 끝났다면, 어떻게 저장할 것인지도 중요.
#왜 CSV파일을 많이 쓰는지 이해해야 한다.
# 1. 파일 용량이 xlsx보다 훨씬 작다.
# 2. CSV는 읽고 쓰기가 매우 빠르다.

#데이터 가공하기(Preprocessing)
#  분석에 적합한 데이터로 가공하는 작업
#  Data Processing
#  데이터 분석의 핵심
#  dplyr 패키지를 주로 사용
#    데이버 분석 툴이 많이 모여있다.

# 양질의 데이터가 가치를 창조
# 데이터 가공과정 : Key > data > Split > Apply > Combine(??)
#    교안 다운받아서 참고...

#day03 part2 : 데이터 전처리

df_web <- read.csv('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/my_lib.csv')
df_web

# 결측치 확인
is.na(df_web)
table(is.na(df_web))

#데이터 정보 추출 : data.go.kr
# 전국 도서관 현황 데이터 추출
# 통계청 데이터도 결측치가 많음

#열별 정보 확인
str(df_web) # 자료형, 자료 크기 및 열 별로 데이터 유형을 확인할 수 있다.
#훑어보기
head(df_web)

#데이터 분석을 도와주는 패키지 설치
install.packages('dplyr')
library('dplyr')

#행, 열 추출(조건 조회에서도 쓸 수 있던 기능)
#filter() : 행 추출
#select() : 열 추출
#arragne() : 정렬
#mutate() : 열 추가
#group_by() : 집단(그룹) 추가

# 데이터 분석 목표 : 전국 도서관의 시도명, 시군구명, 도서관유형을 그룹화
head(df_web)
df_web[, c('시도명', '시군구명', '도서관유형')]
## 매트릭스 INDEXING과 $ 연산자의 차이를 좀 복습해보자

#시도명으로 그룹화하기 : INDEX과는 개념이 다른것이라고함... 찾아보자
df_lib_g <- subset(df_web, select = c('시도명', '시군구명', '도서관유형'))
head(df_lib_g)

group_by(df_lib_g, 시도명) #dataframe이 아닌 tibble 형태로 만들어준다.
   #특정 열을 선택해서 정리해주는건가?
   #열별 데이터유형, 줄 수 등 부가정보도 가지고 있음
   #마이클 힐튼교수?가 만든 새 데이터 타입.
   #tibble은 통계학에서 사용하는 자료형. table과 크게 다를건 없다
   #추가적인 개념이 들어가는 정도
   #tabular? 등등
   #열의 이름을 문자열로 넣으면 안됨. 유의.(만든 사람의 철학대로 가는 것)
   #기능이 뭔지 다시 공부해야 할 듯


cnt <- group_by(df_lib_g, 시도명)
count(cnt)

# 시도명, 시군구명으로 그룹화하기... combine은 먹히지 않는다.
#그냥 그렇게 만들어진거임.
cnt <- group_by(df_lib_g, 시도명, 시군구명, 도서관유형)
count(cnt)

#열 이름 바꾸기
colnames(df_lib_g) <- c('sido', 'sigungu', 'type')
head(df_lib_g)
group_by(df_lib_g, sido)
count(group_by(df_lib_g, sido))



#Mission : dplyr을 이용하지 않고 시도명이 서울특별시인 데이터의 개수를 구하시오
df_web <- read.csv('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/my_lib.csv')
head(df_web)
#dplyr을 쓰지 않으면 조건개념이 들어갈 수 없다고?
#count를 전부 따로 써야한다나?
#group의 개념이 핵심이라는데 group이 뭐지?





# 정렬
# arrange()로도 할 수는 있으나, 여기서는 다른 방법
cnt <- count(group_by(df_lib_g, 시도명, 시군구명))
cnt
c(order(cnt$n)) # cnt의 순서대로 정렬?? #오름차순
c(order(-cnt$n)) #내림차순
#오름차순 : 내려갈수록, 또는 진행할수록 값이 커져야 오름차순. vise versa

cnt[c(order(cnt$n)), ] #지역별로 도서관 갯수 세기 : 오름차순으로
cnt[c(order(-cnt$n)), ] # 내림차순
#그래서 arrange()는 어떻게 써야 하는가??


#데이터 저장
lib_cnt <- cnt[c(order(-cnt$n)), ]
write.table(lib_cnt, 'C:/GitHub/LearningProgrammingLanguages/R/KoreaIT/work_r/FileAccessSample/Lib_cnt.txt')
write.csv(lib_cnt, 'C:/GitHub/LearningProgrammingLanguages/R/KoreaIT/work_r/FileAccessSample/Lib_cnt.csv')
getwd()
write.csv(lib_cnt, 'Lib_cnt2.csv') #R 프로젝트 폴더 등의 작업폴더에 생성

#별도의 row명 삭제하기
write.csv(lib_cnt, 'C:/GitHub/LearningProgrammingLanguages/R/KoreaIT/work_r/FileAccessSample/Lib_cnt2.csv', row.names=F)