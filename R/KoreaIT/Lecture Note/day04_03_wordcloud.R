# crawling을 통해서 모은 기사 워드 클라우드 만들기
library(tidyverse)
library(KoNLP)
library(dplyr)
library(reshape2)
library(stringr)
library(wordcloud2)

txt1 <- read.csv('c:/dev/my_crawling.csv')
txt1

mydata <- txt1[c(1:20), 2]
mydata %>% head()

my_data_ko <- SimplePos09(str_trim(mydata))
my_data_ko

m_df <- my_data_ko %>% melt %>% as_tibble()

m_df1 <- m_df[, c('L1', 'value')]

m_df1 %>% 
    mutate(noun=str_match(value, '([가-힣]+)/N')[, 2]) %>%
    na.omit() %>%
    mutate(noun_length=str_length(noun)) %>%
    filter(noun_length >= 2) %>%
    count(noun, sort=T) %>%
    filter(n >= 10) %>%
    wordcloud2()


















































