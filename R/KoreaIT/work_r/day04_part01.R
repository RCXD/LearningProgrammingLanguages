#  Today : 리뷰
#한글은 처리하기 까다롭다는 사실

#1. 크롤링을 통한 데이터 수집
#install.packages('')


#rvest, dplyr 설치

install.packages('rvest')
install.packages('dplyr')
library('rvest')
library('dplyr')


# 크롤링하기
# 적당한 기사 크롤링
# 빅데이터 뉴스 http://jtbc.joins.com/search/news?term=%EB%B9%85%EB%8D%B0%EC%9D%B4%ED%84%B0
# 200926기준 1,143개 기사 중 데이터 수집하기
# 조건 : ...

# 사람은 일반적으로 반복적인 업무는 효율이 떨어진다.
# 기계는 반복횟수가 커져도 균일한 효율을 기대할 수 있음
# Digital Transformation : 사람의 능률이 떨어짐 > 디지털화


#해당 링크 페이지별 주소 확인

#1페이지 : http://jtbc.joins.com/search/news?term=%EB%B9%85%EB%8D%B0%EC%9D%B4%ED%84%B0
#2페이지 : http://jtbc.joins.com/search/news?page=2&term=%EB%B9%85%EB%8D%B0%EC%9D%B4%ED%84%B0
#3페이지 : http://jtbc.joins.com/search/news?page=3&term=%EB%B9%85%EB%8D%B0%EC%9D%B4%ED%84%B0
#...
#115페이지 : http://jtbc.joins.com/search/news?page=115&term=%EB%B9%85%EB%8D%B0%EC%9D%B4%ED%84%B0

#위에서 반복적인 패턴을 확인하고 활용
#1페이지 제외하고는 dage=N& 이 붙어있다.
#url 기본 :
#http://~부터 .com/까지가 domain.
#단,...news?까지를 domain으로 가정하자.
#? 뒤는 특정 조건이라고 생각
#사이트마다 url지정 규칙이 다르다. 표준이 존재하지 않는다.

#읽어올 페이지 지정
# jtbc의 뉴스 기사 크롤링하기

my_keyword <- '빅데이터'
my_url = NULL


#실습하기
#my_url의 1번~4번째 방에 값 1~4 입력

my_url[1] <- 1
my_url[2] <- 2
my_url[3] <- 3
my_url[4] <- 4


#page 패턴으로 url값 할당하기
for(x in c(1:5)) {
  my_url[x] <- paste0('http://jtbc.joins.com/search/news?page=', x, '&term=', my_keyword)
}

#html파일은 <head>와 <body>로 구성되어 있음.
# id는 #, class는 .

read_html(my_url[1]) #<head>와 <body>로 구성된 원소 2개짜리 벡터가 만들어짐.

#각각의 상세 기사에 대한 url
# e.g. http://news.jtbc.joins.com/article/article.aspx?news_id=NB11946461
# 예제 기사제목 : 한국경제신문 "국비지원 '빅데이터 전략 마에스트로과정' 훈련생 모집"
# 1페이지 1번 기사를 발췌하는게 목표. 위 기사가 아닐 수도 있음
# a tag 안에 id는 없고, txt_ttl 클래스는 명시되어 있다.

html_data <- read_html(my_url[1])
html_nodes(html_data, '.txt_ttl') #class이니까 이름에 '.' 추가
#10개의 txt_ttl 중 찾고자 하는 기사제목을 노드에서 확인 가능.
#a tag로 작성되어 있다. "markup language"임.
#<참고 : markup language>
#markup language의 대표 2개는 html과 xml임.
# markup: <꺾은 가로> 이 사이를 꾸미는 언어로</꺾은 가로>
#   - <a>꾸며지는 부분을 text라고 함.</a>
#   - <a 내부의 부분을 속성(attribute)라고 함></a>
#     a tag는 예시임.
# markdown: *꾸미는 언어, /꾸미는 언어

#필요한것은 href 속성에 저장된 값임.
html_a <- html_nodes(html_data, '.txt_ttl')
#html_a에서 속성 href를 가져오기
html_a[1]
#html_attr() html의 attribute 가져오는 함수
a <- html_attr(html_a[1], 'href') #문자열로 돌려준다.



#==================================================
#여기까지를 for문을 활용하여 특정 페이지까지 긁어오기

my_url = NULL
my_links = NULL
my_keyword = '빅데이터'

for(x in c(1:5)) {
  my_url[x] <- paste0('http://jtbc.joins.com/search/news?page=', x, '&term=', my_keyword)
}

for(url in my_url) {
  print(url)
  html_data <- read_html(url)
  html_a <- html_nodes(html_data, '.txt_ttl') #긁어온 html에서 .txt_ttl 가져오기
  links <- html_attr(html_a, 'href') #attribute에서 링크 가져오기
  my_links <- c(my_links, links)
}
print(my_links)
# my_url 하나당 10개 정도의 txt_ttl에 할당된 링크가 저장되고,
# my_links는 총 50여개의 txt_ttl을 저장하게 됨


#실습하기 : my_links[1]을 이용하여 본문 크롤링하기
#핵심은, 가져오고자 하는데이터가 .인지, #인지 구분하는 것임
my_url2 = NULL
my_links2 = NULL
my_keyword = '빅데이터'

#타겟 기사 : http://news.jtbc.joins.com/article/article.aspx?news_id=NB11946461
my_url2[1] <- 'http://news.jtbc.joins.com/article/article.aspx?news_id=NB11946461'
html_articles <- read_html(my_url2[1])
#찾고자 하는 내용(본문)의 전체가 잡히는 구간을 찾아 id 또는 class를 찾는다.
#부모의 id를 기준으로 내려올 수도 있으나, 이번엔 class로.
#다음에는 articlebody라는 id로... 다시해보자
#html_a <- html_nodes(html_data, '.article_content')
#여러개는 html.nodes()로, 한개는 html_node()로. 여러개는 리스트로 만들어짐
html_tmp<- html_node(html_articles, '.article_content')
my_article <- html_text(html_tmp) #문자열만 전부 가져오기

#attr로 받아올 수는 없을까?
#html_font<- html_attr(html_tmp, 'font')... 어떻게 해결?


#반복문으로 가져오기
my_articles <- NULL
for (link in my_links) {
  html_articles <- read_html(link)
  html_tmp<- html_node(html_articles, '.article_content')
  my_articles <- c(my_articles, html_text(html_tmp))
}
my_articles


#파일에 저장하기
write.csv(my_articles, 'C:/GitHub/LearningProgrammingLanguages/R/KoreaIT/work_r/Crawling/my_crawling.csv')


#처리시간
#crawling은 긁어오는게 가장 오래걸린다.
#저장은 crawling보다 아주 빠르다. 비용적인 측면에서 csv로 가져오는것이 유리
#데이터베이스가 중요


#데이터 분석이란?
#데이터가 무엇인지 알아야 가능하다.
#"영어는 단어가 뜻을 가지고 있어서 분석이 상대적으로 쉽다."
#한글은 영어에 비해 어렵다. 고유 속성을 알아야 데이터를 분석할 때 유리하다.
#언어 유형
#- 굴절어
#   - 영어(라틴어) : 유럽권, 인도
#   - 특징: 형태가 계속 변함. 
#      예) '나'를 뜻하는 단어 : I, my, me, mine, ...
#      예) 각종 시제

#- 교착어
#   - 한국어, 일본어, 터키어
#     예) 가다 + ㅆ -> 갔다, ...
#     예) 기본 시제는 있으나 단어가 바뀜
#     받침, 조사, 어미에 따라 의미가 바뀜
#- 고립어
#   - 현대 영어, 중국어, 베트남어
#     예) 중국어는 시제에 따른 모양의 변동이 없다. 각 단어가 뜻이 정해져 있다.
#     문자에 다라 뜻이 바뀌지 않는다.
#     다른 문자와 합쳐지지 않는다. 분석에 유리함.
#- 포함어
#   메이저 언어는 해당 안됨. 
#   소수민족에서 사용하는 언어. 분석 가치는 상대적으로 떨어짐

#감사합니다의 출현 정도를 알려면?
#고립어(굴절어)인 영어 : Thank you, Thanks, appreciate 등의 반복 휫수만 알면 됨.
#한국어 분석은 감사+하+ㅂ니다 의 형태의 형태소로 분석이 선행되어야 함.
#감사라는 단어의 출현빈도로는 찾을 수 없다.
#국정감사, 외부감사, 내부감사, 감 사먹자 등
#Tx : 케바케 아닌가?

#언어유형별 난이도
#굴절어 > 교착어 > 고립어
# 한국어는 어려운 언어 Top5
# "굴절어보다 낮은 Level이지만 완성도가 학문적으로 매우 높다"
# Tx. 국어공부가 갑자기 하고싶어지네...

#데이터 빈도
#표로 보면 한눈에 이해하기에 불리하다.(불가능한건 아니지만)
#워드클라우드 기능을 이용하는게 한눈에 보기 좋다.
#그래픽, 차트를 만드는데는 이유가 있다.