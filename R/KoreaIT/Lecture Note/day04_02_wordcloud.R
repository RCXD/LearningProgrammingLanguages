install.packages('tidyverse') 
library(tidyverse) 
library(rvest)

devtools::install_github('haven-jeon/KoNLP')
install.packages('remotes')
remotes::install_github('haven-jeon/KoNLP', upgrade = 'never', INSTALL_opts=c('--no-multiarch'))
library(KoNLP)




# 문대통령 연설문

# 실습하기. 문대통령 연설문 불러오기
# - https://www1.president.go.kr/articles/4122
## moon_txt에 대통령 연설문을 저장해주세요
url <- 'https://www1.president.go.kr/articles/4122'
html_page <- read_html(url) 
txt <- html_nodes(html_page, '.text.left.cb')
moon_txt <- html_text(txt)
moon_txt

# readLines로 읽기
moon_txt <- readLines('https://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/moon_UTF8.txt', encoding='UTF-8')

moon_txt
class(moon_txt)

# 형태소분석
# - 어떤 어절을 분석하는 것. 문장이 동사, 명사, 형용사 인지 품사를 붙이는 것
SimplePos09('안녕하세요. 빅데이터 분석 전문가 시간입니다.')

# 문대통령 연설문을 형태소 분석하기
moon_ko <- SimplePos09(moon_txt)
moon_ko %>% head(10)

class(moon_ko)

library('dplyr')

# 파이프라인 문법
# - 물이 흐르듯이 앞의 결과가 %>% 뒤로 연결되듯이 코딩하는 문법
#   r에서 많이 사용되는 문법으로 다른 분석가의 코드를 보려면
#   필수로 보는 방법을 익혀야 합니다.

# 파이프라인 없는 상태의 문법
head(moon_ko)

# 파이프라인 문법
moon_ko %>% head()


# 실습하기. 파이프라인문법으로 moon_ko의 형태를 확인해주세요.
# - class() 함수로 확인해주세요.
moon_ko %>% class()


install.packages('reshape2')
library(reshape2)
# reshape2: 구조 변경을 도와주는 패키지
moon_ko %>% head(10)

moon_ko %>% melt %>% head(10)

# tibble 데이터 전환하기
# - tibble은 dataframe과 동일한 데이터 구조 + 부가적인 정보
m_df <- moon_ko %>% melt %>% as_tibble()
m_df

m_df[, 1]
m_df[, 2]
m_df[, 3]

# 필요한 데이터 열인 L1과 value만 뽑아내서
# 새로운 데이터프레임 만들기
m_df1 <- m_df[, c('L1', 'value')]

# 워드클라우드를 그리기 위한 명사(N)뽑기
# - value중에서 /N이 붙은 체언만 골라내기
# - 정규식을 통하여 필요한 정보를 골라내기
#   : /N이 붙어있는 한글만 뽑아라.

tmp_txt <- c('사실/N', 'korea/N', '알/P', '코리아/N정보/P')
tmp_txt
library('stringr')

tmp_txt %>%
    str_match('([가-힣]+)/N')


# a - Z # 모든 영문자
# 0 - 9 # 모든 숫자
# 가 - 힣 # 모든 한글

# m_df1에 정규식을 적용하여 명사 추출하면서
# noun이라는 새로운 열을 만들어서 값 입력하기
# - mutate(): 복제라는 뜻으로 새로운 열을 생성 가능

# - 파이프라인이 없이 코딩
mutate(m_df1, noun=str_match(m_df1$value, '([가-힣]+)/N'))

# - 파이프라인 코드
m_df2 <- m_df1 %>% 
    mutate(noun=str_match(value, '([가-힣]+)/N')[, 2]) %>%
    na.omit()

# noun 열의 단어별 갯수 세기
# - sort=T는 내림차순 정렬
m_df2 %>% count(noun, sort=T)

# 실습하기. 것, 수, 위처럼 1글자인 현재의 데이터 분석에서 의미없는
# 짧은 단어를 삭제하기 위하여 mutate를 통하여
# noun_length열에 단어의 길이 값을 넣어주세요.
# - 단어 길이는 str_length(단어)로 알 수 있습니다.
m_df3<- m_df2 %>% 
    mutate(noun_length=str_length(noun)) %>%
    filter(noun_length >= 2) %>%
    count(noun, sort=T)

# 워드 클라우드 만들기
install.packages('wordcloud2')
library(wordcloud2)
m_df3 %>% wordcloud2()

# 단어가 너무 많아서 워드 클라우드에
# 많이 표시가 되므로 2번 이상 출현하는 단어로만
# 워드 클라우드 그리기
m_df3 %>% 
    filter(n >= 2) %>%
    wordcloud2(minRotation = 0, maxRotation = 0)








