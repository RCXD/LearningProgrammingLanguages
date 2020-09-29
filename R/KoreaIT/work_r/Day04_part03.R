#Crawling을 통해서 모은 기사로 워드클라우드 만들기
#목표 : 빅데이터로 검색해서 나온 기사 50개에서 나온 단어들의
#트렌드는 무엇인지 확인해보자.


library(tidyverse)
library(KoNLP)
library(dplyr)
library(reshape2)
library(stringr)
library(wordcloud2)

txt1 <- read.csv('C:/GitHub/LearningProgrammingLanguages/R/KoreaIT/work_r/Crawling/my_crawling.csv')
mydata <- txt1[c(1:20), 2] #20개만 자르기
mydata %>% head()

#불필요한 공백 제거
str_trim(mydata) #해치웠나?

my_data_ko <- SimplePos09(str_trim(mydata))
my_data_ko

m_df <- my_data_ko %>% melt %>% as_tibble() #개수 세기, tibble만들기

#정규식 만들기
m_df1 <- m_df[, c('L1', 'value')]

m_df1 %>%
  mutate(noun=str_match(value, '([가-힣]+)/N')[, 2]) %>%
  na.omit() %>%
  mutate(noun_length=str_length(noun)) %>%
  filter(noun_length >= 2) %>%
  count(noun, sort=T)

m_df1 %>%
  mutate(noun=str_match(value, '([가-힣]+)/N')[, 2]) %>%
  na.omit() %>%
  mutate(noun_length=str_length(noun)) %>%
  filter(noun_length >= 2) %>%
  count(noun, sort=T) %>%
  #filter(n >= 10) %>% #너무 많아서 편집
  wordcloud2(backgroundColor = 'black') 
  #wordcloud2(backgroundColor = 'black', minRotation=90, maxRotation=-90)
  #왜 또 결과가 이렇지?
  #"빅데이터를"같은, 잘못된 데이터 삭제하기

#아마존 AWS가 아마존 수입의 대부분을 담당한다?
#아마존 AWS의 빅데이터? 클라우드? 무엇?