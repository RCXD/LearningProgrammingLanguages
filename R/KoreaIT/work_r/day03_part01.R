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

