#데이터 정제
#Word cloud


install.packages('tidyverse')
library('tidyverse')
install.packages('dplyr')
library('dplyr')
library('rvest') #read_html, ...

#문대통령 연설문 : 데이터 관련 연설 > 크롤링해서 가져오고 한글 분석
#실습하기 : 문대통령 연설문 불러오기
#연설문 : https://www1.president.go.kr/articles/4122
#moon_txt에 대통령 연설문 저장하기

url = 'https://www1.president.go.kr/articles/4122'
html_page <- read_html(url)
txt <- html_nodes(html_page, '.text.left.cb') #공백은 .으로 구분!!
#.text.left.cb.text_wrap.motion.fadeIn.visible이라고 하면 너무 긴건가?
moon_txt <- html_text(my_html)
moon_txt

#기술적 문제로 github 내용 활용..
moon_ko <- readLines('http://raw.githubusercontent.com/luxdolorosa/data_set/master/etc/moon_UTF8.txt', encoding = 'UTF-8')
moon_ko
#UTF-8로 어떻게 바꿈??? encoding = 'UTF-8'

#한글분석에서는 형태소 분석이 필수적!
#미래에 음성비서사업은 크게 확장되겠지만... 기술적인 문제로 현재는 주춤
#구글 어시스턴트 : 한글버전 제작에 실패
#세종 형태소 분석기, KAIST 형태소 분석기
#현재의 형태소 분석기의 수준과 신뢰도가 매우 높다.

#형태소 분석
#KAIST 품사 태그셋 활용
# 9개의 단위로 형태로 분석, 22~23개의 상세 분석
#활용 : https://github.com/haven-jeon/KoNLP/blob/master/etcs/KoNLP-API.md
#KoNLP가 성능이 매우 높다.(세종 형태소분석기보다...)

#R은 외부패키지를 이용하기 어려우니 java를 활용하고있는 실정.
#Wane?Wave?에서 java처럼 데이터셋?패키지?를 가져오고 있었으나
# 모종의이유로 R에서 최근 끊음.
# 업데이트가 멈추었으나, 기존에 남아있는 패키지를 활용하는 방법도 있다.
# R의 '유산'을 활용하는 방법이 있다.
# 야후, 사이월드의 옛 페이지는 구글에 저장되어 있음.
# 유산? 관련 모아놓은 홈페이지?가 있다나??

#install.packages('KoNLP') #Not available
install.packages('devtools')
install.packages('remotes')
install.packages('backports') #뭔진 모르겠으나 없다고 함. 안됨
#remove.packages('backports') #뭔진 모르겠으나 없다고 함. 삭제도 안됨. 없는건가
#직접 라이브러리폴더(C:\Users\tpxdk\OneDrive\Dcuments\R\win-library\4.0)에서 삭제!

devtools::install_github('haven-jeon/KoNLP', force=TRUE)
remotes::install_github('haven-jeon/KoNLP', force=TRUE, upgrade = 'never', INSTALL_opts=c('--no-multiarch'))

library('KoNLP')
#흠.... 실패

#형태소 분석
# - 어떤 어절을 분석하는 것은 : 문장이 동사, 명사, 형용사인지 품사를 붙이는 것
SimplePos09('안녕하세요. 빅데이터 분석 전문가 시간입니다.')
# 출력내용을 KAIST 품사 태그셋을 활용하여 이해
# 체언(N) -> 시간, 관계언(J) -> 이 -> 용언(E) -> ㅂ니다

#문대통령 연설을 형태소 분석하기
#moon_ko <- SimplePos09(moon_txt)
moon_ko <- SimplePos09(moon_ko)
moon_ko

library('dplyr') #파이프라인 문법을 지원함
#파이프라인 문법
# - 물이 흐르듯이 앞의 결과가 %>% 뒤로 연결되듯이 코딩하는 문법
#   R에서 많이 사용되는 문법. 다른 분석가의 코드를 보려면 
#   필수적으로 보는 방법을 익혀야 함.

#파이프라인이 없는 상태의 문법
head(moon_ko)

#파이프라인 문법
moon_ko %>% head()

#대부분의 객체지향 언어
#-> 데이터.함수() 방식 사용
#R
#-> 함수(데이터) 방식 사용
#
#dplyr 패키지를 사용하면 데이터.함수() 형태로 코딩할 수 있다.
#외국 코더들은 대부분 파이프라인 문법을 활용함.


#실습하기 : 파이프라인 문법으로 moon_ko의 형태를 확인
# - class()함수로 확인
moon_ko %>% class()


install.packages('reshape2')
library(reshape2) #구조 변경을 도와주는 패키지


#데이터프레임 형태로 재구조화
moon_ko %>% head(5)
moon_ko %>% melt %>% head(5)

moon_ko %>% head(10)
moon_ko %>% melt %>% head(10)
#반갑습니다 -> L2계층, 반복 횟수 -> L1 계층, NLP분석결과 -> value
#L1계층은 같은 형태만 카운트해준다(?) 어떤 패턴이 있는데 잘 모르겠음.
#규제혁신을 -> 규제혁신의, 규제혁신, ... reshpae2 기능이니 KoNLP와 무관 
#value : 값 자체, L2는 key값, L1은 melt를 통한 재구조화 결과값(?)

#tibble 데이터 전환하기
m_df <- moon_ko %>% melt %>% as_tibble() #tibble형태로 변경하기
m_df #tibble은 데이터프레임과 유사한 형태

#R에 큰 기여를 한 교수 : Hadley Wickham
#tibble은 데이터프레임과 동일한 데이터구조 + 부가적인 정보

m_df <- moon_ko %>% melt %>% as_tibble()
m_df

#dataframe에서처럼 데이터를 조회할 수 있다.
m_df[, 1]
m_df[, 2]
m_df[, 3]

#L1에 count가 안나올 경우, github에서 데이터 읽을 것 (물론 그 상황을 모르겠다.)
#크롤링하면 벡터형태가 아님. 라고함.

#필요한 데이터 열인 L1과 value만 뽑아서 새로운 데이터프레임 만들기
m_df1 <- m_df[, c('L1', 'value')]

#워드클라우드를 그리기 위한 명사(N) 뽑기
#value 중에서 /N이 붙은 체언만 골라내기
#정규식을 통하여 필요한 정보를 골라내기
# /N이 붙어있는 한글만 뽑아라.
# 데이터에 오류가 있을 수 있음을 감안. 한글이 어렵기 때문에

tmp_txt <- c('사실/N', 'Korea/N', '알/P', '코리아/N정보/P')
tmp_txt

#string 관련 라이브러리 설치
library('stringr')
# str_match()
tmp_txt %>% str_match() #패턴값을 추가해줘야함
#"파이프라인은 라인이 달라도 상관없다" 단, 탭을 넣어줘야 함.
tmp_txt %>%
  str_match('(조건)/N')

#a-z 모든 영문자
#A-z 모든 영대소문자(?)
#0-9 모든 숫자
#가-힣 모든 한글

tmp_txt %>%
  str_match('([가-힣])/N') #'사'가 누락됨. 원하는 문자만 잘라냄
tmp_txt %>%
  str_match('([가-힣]+)/N') #나머지 문자까지
#NA NA행은 일치하는게 없는것임

#m_df1에 정규식을 적용하여 명사를 추출하면서
#noun이라는 새로운 열을 만들어서 값 입력하기
# - moutate() 복제라는 뜻으로 새로운 열을 생성 가능
m_df1 %>% mutate(noun=str_match('([가-힣]+)/N')) 
  #새 열의 이름을 noun으로, 데이터는 str_match 결과값으로 만든다는 의미
  #데이터프레임, tibble에서 str_match를 사용할 때에는, 해당 열의 이름을 주어야 한다.
m_df1 %>% mutate(noun=str_match(value, '([가-힣]+)/N')[,2]) 

#파이프라인 동작 없이 만들기
#mutate(m_df1, 생성된 열)
mutate(m_df1, noun=str_match(m_df1$value, '([가-힣]+)/N')) 
#파이프라인없이 코딩하는게 보기도 좋고, 편할지언정,
#R에 익숙해졌다면 파이프라인에 조금씩 익숙해지자.

#파이프라인 코드
m_df2 <- m_df1 %>%
    mutate(noun=str_match(value, '([가-힣]+)/N')[,2]) %>%
    na.omit()
#파이프라인의 장점은 여기서 나온다고 함.
  #논리 순서대로 적용할 수 있다고 보면 되는듯?


#noun 열의 단어별 갯수 세기
# - sort=T는 내림차순 정렬
m_df2 %>% count(noun, sort=T)
m_df2 %>% str_length(noun)
#=========================================
#실습하기
#워드클라우드를 돌리기 전에, '것, 수, 위'같이 1글자짜리 의미없는
#데이터는 삭제
# -> mutate를 통하여 noun_length열에 단어의 길이 값을 넣기
# - 단어의 길이는 str_length(단어)로 알 수 있음
# count는 안먹힐 것이라고 함...

m_df3 <- m_df2 %>%
  mutate(noun_length=str_length(noun)) %>%
  filter(noun_length >= 2) %>%
  count(noun, sort=T)
m_df3
#이 결과가 왜 강사와 조금 다른지 모르겠다. 8~10번이 다름.
#원본링크 내용으로 다시 해보고 비교해보자!! ???

#??? : Rstudio 메모리 뻑 안나게하려면?
#좁은 스크립트창에 코드 줄 한번에 보려면?Tools - Global options - Code - Soft-wrap R source files 



#워드클라우드 만들기
install.packages('wordcloud2')
library(wordcloud2)
m_df3 %>% wordcloud2() #왜 강사랑 다르지? 왜 데이터가 가장 큰게 아닐까?
#문제를 찾아보자...???



#단어가 너무 많아서 워드클라우드에 많이 표시가 되므로 2번 이상 출현하는 단어로만 워드 클라우드 그리기
m_df3 %>%
  filter(n>=2) %>%
  wordcloud2(minRotation = 0, maxRotation = 0) #회전 없애는 옵션

#====================================
#데이터 시각화
#단순히 외향만 개선하기 위한게 아님.
#정보시각화, 과학적시각화, 인포그래픽
#과학적 시각화 : 실험결과, 시뮬레이션 등 복잡한 데이터를 쉽게 탐색할 수 있도록 3차원 그래픽 기술을 활용하여 시각화하는 기술
#데이터분석 전문가 : 정보시각화, 인포그래픽 주로 활용
# 정보시각화 : 
# 대규모 데이터를 색체, 통계, 이미지 등을 활용, 요약적 표현
# 인포그래픽 : 
#   정보+그래픽
#   차트, 다이어그램, 로고 등을 활용하여 한눈에 파악할 수 있도록 하는 디자인

#이번에는 정보시각화에 포커스


#데이터 시각화(Data visualization)의 이유
# 정보전달의 효율성
# ...