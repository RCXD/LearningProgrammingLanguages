#Review

#Vector
fruit <- c('apple', 'mango', 'banana', 'orange', 'Apple', 'pineapple')
fruit

#특정 조건 검색
#fruit 안에서 apple 값 검색하기
#grep(조건, 데이터)   .... Linux에서 많이 쓴다고 함.
grep('apple', fruit) #apple이 포함된 데이터의 Index를 찾아준다. 대소문자를 구분함.
#R은 1부터 센다!

#대소문자 구분 없애기
grep('apple', fruit, ignore.case = T) #Apple도 찾아준다.

#fruit 안에서 a가 포함된 값 검색
grep('a', fruit)

#grep을 이용해서 시작, 끝값 검색하기
grep('^a', fruit)
grep('e$', fruit) 
#"수업 끝나고 grep 관련 정보를 더 보내줄테니, 확인해보라"

#숫자값, 논리값 1개씩 추가하기
fruit <- c('apple', 'mango', 'banana', 'orange', 'Apple', 'pineapple')
fruit <- c(fruit, T, 123) #논리값, 숫자값은 문자열로 변경됨. T -> "TRUE"
#문자열 fruit을 다시 추가하는게 아님. 해석 주의

#숫자형만 검색하기 #T는...?
grep('\\d', fruit)
#숫자형태가 아닌 값만 검색하기
grep('\\D', fruit)

#임의의 텍스트 수를 지정하여 검색 : '.' 하나당 글자 하나 대체
grep('.......', fruit) #7글자 이상인 값만 검색
grep('..a', fruit) #a 시작 전 2글자 이상인 값만 검색
  # banana는 a가 3개지만, 만족하는 a가 있으면 검색됨!



#파일 불러오기(중요!)
#상대경로 : 특정 기준점이 필요하다.
# 1. 기준점 가져오기 : get work directory
#    컴퓨터마다 결과값이 다르다.
#    "기준점의 경로는 표시되지 않는다" : PC마다 바뀌기 때문
getwd() #작업공간 경로를 가져온다.
#R프로젝트를 열 때, 폴더를 열 때 등 이런 경우에 기준점이 설정되는 듯.
#VS Code는 열어놓은 폴더가 기준점임!
readLines('korea.txt') #Rstduio에서 Ctrl+Space를 누르면 내부의 파일을 보여줌
    #불완전한 마지막에 빈 줄이 없으면 불완전한 행이라고 함
readLines('FileAccessSample/korea2.txt') #특정 폴더로 들어가기
readLines('../korea3.txt') #상위 폴더로 나가기 : 윈도우 커맨드라인과 비슷

#절대경로 : 약속된 기준점으로 만들어진 경로. 별도 기준점 불필요
#1. 전체 경로가 모두 표시되는 형태
#방법 1
readLines('C:/GitHub/LearningProgrammingLanguages/R/KoreaIT/korea3.txt')
#방법 2
readLines('C:\\GitHub\\LearningProgrammingLanguages\\R\\KoreaIT\\korea3.txt')

#주소창에 naver.com을 검색하는건 절대경로의 개념

#github 경로 이용하기
# https://github.com/luxdolorosa/data_set/blob/master/etc/movie_review_01.txt
# 여기에 접속해서, RAW 클릭 후 링크 복사
# https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/movie_review_01.txt
# 상위 사이트가 바뀌었다는걸 확인 가능
readLines('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/movie_review_01.txt')


#다운받아서 읽기(실습)
getwd()
readLines('C:\\GitHub\\LearningProgrammingLanguages\\R\\KoreaIT\\movie_review_01.txt')


txt1 <- readLines('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/movie_review_01.txt')
# 벡터의 개수 확인
length(txt1)

#실습 : txt1의 데이터 중 영화라는 단어가 포함된 데이터 조회
grep('영화', txt1)
txt1[grep('영화', txt1)]

#영화 리뷰데이터를 처리할 때, 비즈니스마다 필요한대로 가공이 필요함
#비즈니스마다 최저 문자 길이가 다르다.

#최소 10글자 이상인 데이터만 검색하기
grep('..........', txt1) #이거는 .이 너무 많게 된다.
#"R이 개발된지 20년이 넘었으니, 필요한 함수와 알고리즘은 이미 다 만들어져 있다. 
#  검색해서 가져다 쓸 줄 아는게 중요"

#strrep() 활용
#특정 문자를 필요한만큼 반복해줌. 
#rep함수를 str값으로 만들어주는 개념
strrep('.',40) 
rep('.', 40)
grep(strrep('.',40),txt1)
txt1[grep(strrep('.',40),txt1)]

#실습 : 다음 조건을 만족하는 데이터 조회
intersect(txt1[grep(strrep('.',20),txt1)], txt1[grep('영화',txt1)])
txt1[intersect(grep(strrep('.',20),txt1), grep('영화',txt1))]

#여러 형태의 파일 열기
# 1. pdf파일
readLines('C:\\GitHub\\LearningProgrammingLanguages\\R\\KoreaIT\\work_r\\FileAccessSample\\movie_review_02.pdf')
# 모든 파일은 안에 내용이 없어보여도 파일구조에 대한 메타데이터를 읽어들임.
# 외부 라이브러리를 이용해서 읽어들여야한다.
install.packages('pdftools') #adobe사에서 배포한 툴
library('pdftools')

pdf1 <- pdf_text('C:/GitHub/LearningProgrammingLanguages/R/KoreaIT/work_r/FileAccessSample/movie_review_02.pdf')
# 스칼라 값으로 텍스트가 들어왔다. 줄이 끝나는 자리마다 \r\n을 확인할 수 있음.
# \r\n : 개행문자... /r : 커서 초기화, \n : 개행

#strsplit() 이용해서 개행문자 처리하고 벡터로 나누기
#strsplit()의 반환형은 리스트다.
txt_pdf <- strsplit(pdf1, '\r\n')
txt_pdf[[1]][2]


#실습 : txt_pdf의 3번, 4번 값을 6번 값에 추가
txt_pdf[[1]][3]
txt_pdf[[1]][4]
paste0(txt_pdf[[1]][3], txt_pdf[[1]][4])
c(txt_pdf[[1]][3], txt_pdf[[1]][4])
txt_pdf[[1]][6] <- paste0(txt_pdf[[1]][3], txt_pdf[[1]][4])
txt_pdf

#txt_pdf에서 3, 4번방 삭제하기
txt_pdf[[1]][c(-3,-4)] #원본 데이터는 영향받지 않는다. 반복실행으로 에러나지 않음
txt_pdf<-txt_pdf[[1]][c(-3,-4)]
txt_pdf[[1]]

#구형 pdf의 모든 문자는 이미지이며, 쉽게 읽어들일 수 없다.
#별도의 OCR기법이 필요하다.
#txt_ocr_text()를 활용할 수 있다. 해볼필요가 있을 듯



#엑셀 형태를 가지는 데이터 읽어오기
#테이블 형태를 가짐
readLines('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/member_no_title.txt')
read.table('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/member_no_title.txt')
#맥에서 문자가 깨지면 cp949, utf-8
read.table('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/member_no_title.txt', encoding = 'cp949')
read.table('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/member_no_title.txt', encoding = 'utf-8')

#헤더정보가 없는 데이터 읽어오기
mem1 = read.table('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/member_no_title.txt')
names(mem1) <- c('이름', '성적', '평균')

#데이터 읽어오고 해야 할 작업
# 1. 요약정보 확인
summary(mem1) #각 열별로 요약정보 보여줌. 숫자가 있어야 기본 통계정보를 보여줌.

#헤더정보가 있는 데이터 읽어오기
mem2 = read.table('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/member_yes_title.txt')
mem2 #헤더정보로 잡하길 원하는 값이 하나의 행에 들어가 있다. 엑셀파일이 아닌 txt파일이기 때문

#헤더정보 처리
mem2 = read.table('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/member_yes_title.txt', header = T)
mem2

# 2. 상단 or 하단 6개 데이터 확인(눈으로 데이터 훑는 개념)
head(mem2); tail(mem2)
#"많은 데이터를 처리할 때 상당히 중요한 작업임."

# 실습 : 평균점수가 평균 이상인 데이터만 조회
summary(mem2)
mem2[mem2$'평균'>=80.83, 3] #열 이름이 한글일 때는 가급적 ''로 표시! 호환성을 높일 수 있다.
mem2[mem2$'평균'>=mean(mem2$'평균'), 3]

#grep으로 어떻게 푼다는거지??
#코드도 불러와서 ?표시된거만 싹다 긁어와도 되겠다.


#잡음이 섞인 데이터 처리
# skip 옵션을 사용
read.table('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/member_noise.txt')
#노이즈 데이터로 인해 정방형 데이터가 아니면 에러 발생
#노이즈가 있는 행이 어딘지 알고 있을 때, skip 가능
read.table('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/member_noise.txt', header=T, skip=3)
#스킵기능은 앞에밖에 안되나?
#5행까지만 채우기 : nrow옵션
read.table('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/member_noise.txt', header=T, skip=3, nrow=5)

#구분자가 있는 경우, 임의의 구분자 정의
read.table('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/member_yes_sep1.txt', header=T, sep=';')
#실습
read.table('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/member_yes_sep2.txt', header=T, sep=',')

#클립보드로부터 데이터 읽기
# Ctrl+C 데이터 읽기
""" 클립보드 데이터
이름;성적;평균
김가을;A;90
홍길동;C;70
김부장;F;65
"""
""" https://en.wikipedia.org/wiki/World_Tourism_rankings
Rank	Destination	International
tourist
arrivals
(2018)[1]	International
tourist
arrivals
(2017)[1]	Change
(2017 to
2018)
(%)	Change
(2016 to
2017)
(%)
1	 France	89.4 million	86.9 million	Increase 2.9	Increase 5.1
2	 Spain	82.8 million	81.9 million	Increase 1.1	Increase 8.7
3	 United States	79.6 million	76.9 million	Increase 3.5	Increase 0.7
4	 China	62.9 million	60.7 million	Increase 3.6	Increase 2.5
5	 Italy	62.1 million	58.3 million	Increase 6.7	Increase 11.2
6	 Turkey	45.8 million	37.6 million	Increase 21.7	Increase 24.1
7	 Mexico	41.4 million	39.3 million	Increase 5.5	Increase 12.0
8	 Germany	38.9 million	37.5 million	Increase 3.8	Increase 5.2
9	 Thailand	38.2 million	35.5 million	Increase 7.9	Increase 9.1
10	 United Kingdom	36.3 million	37.6 million	Decrease 3.5	Increase 5.1
"""

read.table('clipboard', header=T, sep=';')
read.table('clipboard', header=T, sep='\t')

#결측치 데이터 처리
mem_na = read.table('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/member_yes_NA.txt',header=T, sep=',')
# 결측치는 NA값으로 채워진다.
#결측치 존재여부 확인하기
is.na(mem_na)
#table 함수를 쓰면 빈도수를 알 수 있다.
table(is.na(mem_na))
#열을 정의하면 더 세부적으로 확인 가능
table(is.na(mem_na$'평균'))
#결측치 해결방법
#1. 결측치 채우기
mem_na[is.na(mem_na)] <- 0
mem_na
# 데이터 내용을 잘 알고 있을 때만 유용. 데이터 속성이 변경될 수 있다.
summary(mem_na) #평균이 많이 내려가는 등

#결측치가 이미 무언가로 채워져 있는 경우
#2. NA가 아닌 결측치 처리
read.table('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/member_yes_NA2.txt', header=T, sep=',')
#is.na로 추적할 수 없다.
#무의미 데이터를 NA로 변경하기
mem_na2 <- read.table('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/member_yes_NA2.txt', header=T, sep=',', na.strings = '-')
#실습 : 결측치를 평균열의 평균으로 채우기
mem_na2[is.na(mem_na2)] <- 0
mem_na2
mean(mem_na2$'평균')
mem_na2[mem_na2$'평균'==0,'평균'] <- as.integer(mean(mem_na2$'평균'))
summary(mem_na2)

#문제점..
mean(c(90, 70, 95, 100, 66, 92, 83, 88))
mean(c(90, 70, 95, 100, 66, 92, 83, 88, 0, 0, 0))
#이 둘이 너무 다른데...?
mem_na3 <- read.table('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/member_yes_NA2.txt', header=T, sep=',', na.strings = '-')
mem_na3
mem_na3[is.na(mem_na3)] <- 0
mem_na3
mem_na2[mem_na3$'평균'==0,'평균'] <- 85
mem_na3
summary(mem_na3)


#CSV는 comma seperated value
#Windows에서 호환성이 좋아서 많이 사용하는 포맷
#csv는 엑셀하고는 무관한 포맷임

#CSV용 함수
read.csv('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/fruits.csv')
#헤더 지정은 자동인 듯. 단, '순번' 메타데이터가 꼬이게 됨.
readLines('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/fruits.csv')


#'순번' 메타데이터를 rowname으로 설정해주기
read.csv('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/fruits.csv', row.names = '순번')
# '순번' 열이 1~7이 아니라 다른 것이라면 자동으로 순번을 매겨주겠지.


#엑셀 데이터 불러오기
#보안의 중요성... 네트워크에서 엑셀파일 불러오는 것은 불가능
#엑셀은 visual basic으로 프로그래밍이 가능하므로 해킹공격이 가능하다.
#주의사항 : 네트워크에서 불러오는 형태는 자동으로 암호가 걸려서 데이터가 읽어지지 않음.


#엑셀 패키지 설치
install.packages('xlsx')
library('xlsx')
# gsub('\\','/','C:\GitHub\LearningProgrammingLanguages\R\KoreaIT\work_r\FileAccessSample\')
# read.xlsx(gsub('\','/',C:\GitHub\LearningProgrammingLanguages\R\KoreaIT\work_r\FileAccessSample\'))
# getwd()
read.xlsx('FileAccessSample/fruits_etc.xlsx') #시트명때문에 에러
read.xlsx('FileAccessSample/fruits_etc.xlsx', sheetIndex = 1) #인코딩 에러
fruits2 <- read.xlsx('FileAccessSample/fruits_etc.xlsx', sheetIndex = 1, encoding = 'UTF-8')
#실습 : fruits2의 '구분'이 결측치인 데이터의 가격 평균 구하기
fruits2[is.na(fruits2)] <- 3 #수치값이 아니라면, 명시적인 값으로 정해줘도 되겠지..
fruits2[fruits2$'구분','가격'] #이건 NA값이 제외되어서 나오네?
fruits2[fruits2$'구분'==3,'가격']
mean(fruits2[fruits2$'구분'==3,'가격'])

