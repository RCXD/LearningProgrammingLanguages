#데이터 수집하기 - crawling(=scraping)

#웹페이지를 그대로 가져가서 데이터를 추출해내는 기법
#crawling 소프트웨어 : crawler
#구글이 크롤링 기술을 적용해서 성공한 대표적인 회사
#웹 상에는 없지만 구글에는 있는 페이지가 존재
#없어진 사이트도 구글에는 있다.

#크롤링 : 웹사이트로 접속 가능한 곳의 모든 데이터를 수집할 수 있다.
#즉, 제공되지 않는 데이터베이스는 가져올 수 없다.

#정형 데이터
 # 메타정보가 있다.
 # 구조화되어 있다.

#비정형 데이터
 # 블로그에 올라간 글

# "데이터만 주는 사이트는 API라고 부른다"...? API란 무엇인가
#Crawling : 원하는 부분만 긁어내는 행위

#웹페이지상에서 보여지는 웬만한 데이터는 PC가 다운로드한 데이터를
#복구시켜서 사용자에게 보게 되는 것.
#즉, PC는 웹에서 받은 소스코드를 처리하는 것이고
#소스코드를 이용하면 원하는 데이터를 추출할 수 있다.

"""
연습 링크 : https://en.wikipedia.org/wiki/World_Tourism_rankings
"""

#day03 part3 : Crawling
#웹 데이터 긁어오기

#수강신청 소프트웨어, 티케팅도 crawling 소프트웨어가 성행한다.
#티케팅 crawling은 불법
#주식에 활용되기도 한다고.(위험은 개인책임)

install.packages('rvest')
library('rvest')

#읽어 올 패키지 지정
url <- 'https://en.wikipedia.org/wiki/World_Tourism_rankings'

#html : hyper text markup language
#모든 웹페이지는 거의 대부분이 html로 작성되어 있다.

read_html(url)

#모든 html파일은 <head>와 <body>로 구성되어 있다.
#head : 설정 부분
#body : 시각적인 부분
#head를 지워도 내용은 남아있다.(구조는 깨짐)
#body를 지우면 내용이 사라진다

#중요!!
#id는 '#', class는 '.'으로 시작한다.
#id는 여러번 나올 수 없다. 반면 class는 여러번 나올 수 있다.

#"같은 페이지에 id가 2번 나오면 아주 엉성하게 프로그래밍된 사이트"라고 함.
#왠만해선 id는 중복되지 않는다고.

#F12 -> 요소 -> 마우스클릭아이콘 활용
#테이블 선택은 근처 적당한 셀을 선택하고 상위로 올라가면 테이블 전체를 선택할 수 있다.

#데이터를 가져오는 방법은 매우 다양하다.
#id나 class 둘 중 하나는 무조건 있다.
#id, class명에서 공백에 유의할 것. 무슨 의미(기능)가 있다고 함.

tour_rank <- read_html(url)
#node : "웹페이지의 요소(element)와 비슷한 개념"
#id를 가져올 땐 html_node()를, class를 가져올 때에는 html_nodes()를 활용
#중복된 id가 있을 수 있으므로.
tables <- html_nodes(tour_rank,'.wikitable') 
    #결과값이 13개인 것은 이러한 유형의 표가 그 페이지에 13개가 있다는 것

#html_table(), indexing을 이용해 원하는 table을 선택할 수 있다.
html_table(tables[1]) #자료형은 List
df <- html_table(tables[1])[[1]]
df
#열 정보 확인
str(df);head(df);tail(df)

#Rank, Destination, International 3개의 열만 남기기
df2 <- df[, c(1,2,3)]

#dplyr 활용해서도 할 수 있다
#library('dplyr') 
#select(df, Rank, Destination, International ...???? 어떻게 쳐야?)

df에서 열 이름 바꾸기
colnames(df2) <- c('rank', 'des', 'tour')
df2

#barplot으로 나라별 관광객 나타내기
#barplot(값축(y), 구분 축(x)
barplot(df2$rank, names.arg = df2$des) #Plot 창이 너무 작으면 에러남

barplot(df2$tour, names.arg = df2$des)
#tour 값을 이해하지 못하고 등차로 나타내는 오류가 나옴.

#tour 열의 million은 사람에게만 숫자임.
#tour열을 숫자 형태로 변경해야만 plot을 그릴 수 있다.

##gsub 활용하기
#gsub(치환할 값, 치환될 값, 데이터) -> 원본 영향은 없다.
df2$tour <- as.numeric(gsub(' million', '', df2$tour))
#자료형도 잘 고려해야 한다. 숫자처럼 보여도 숫자가 아닐 수 있음.
class(df2$tour)

barplot(df2$tour, names.arg = df2$des)



