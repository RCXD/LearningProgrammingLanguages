# 크롤링을 통한 데이터 수집하기
#install.packages('rvest')
#install.packages('dplyr')
library(rvest)
library(dplyr)

# 읽어올 페이지 지정
# - jtbc의 뉴스 기사를 크롤링하기
my_keyword <- '빅데이터'
my_url <- NULL

for(x in c(1:5)) {
    my_url[x] <- paste0('http://jtbc.joins.com/search/news?page=', x, '&term=', my_keyword)
}


# 실습하기. my_url의 1번쨰 방에 값 1을 입력해주세요
# my_url[1] <- 1


my_url


## html파일은 <head>와 <body>로 구성되어 있습니다.
### id는 #, class는 .
html_data <- read_html(my_url[1]) 
html_a <- html_nodes(html_data, '.txt_ttl')

# - 마크업: <꺽은 가로>이 사이를 꾸미는 언어</꺽은 가로>
#   <a>꾸며지는 부분을 text라고 함.</a>
#   <a 내부의 부분을 속성(attribute)라고 함></a

# - 마크다운: *꾸미는 언어, /꾸미는 언어

# html_a에서 속성 href를 가져오기
html_attr(html_a[10], 'href')

# my_url의 페이지들로부터 상세보기 url을 얻기 위한 반복문 작성
my_links <- NULL
for(url in my_url) {
    html_data <- read_html(url) 
    html_a <- html_nodes(html_data, '.txt_ttl')
    links <- html_attr(html_a, 'href')
    my_links <- c(my_links, links)
    
}
my_links
length(my_links)

# 실습하기. my_links[1]을 이용하여 본문을 크롤링해주세요
txts <- NULL
for(link in my_links) {
    html_articles <- read_html(link)
    html_tmp <- html_node(html_articles, '.article_content')
    txts <- c(txts, html_text(html_tmp) )
}
txts

# 파일로 저장
write.csv(txts, 'c:/dev/my_crawling.csv')



















