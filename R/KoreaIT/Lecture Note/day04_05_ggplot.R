install.packages('ggplot2')
library(ggplot2)
library(dplyr)
library(tidyverse)

# ggolot2: 진화된 시각화 패키지
# 해들리 위컴 교수에 의하여 개발
# R의 기본 차트에 비하여 상세한 설정이 가능
# 해들리 위컴 교수에 따르면 R의 기본 그래픽은 그림을 그리기 위해 좋은 툴이고, ggplot2는 데이터를 이해하기 위한 시각화 툴함.

# R은 ggplot이전과 이후로 나뉜다.
diamonds

# pie 그래프
ggplot(diamonds)

# aes(aesthetics, 미학요소)
# 데이터의 변수와 그래프의 크기, 형태, 색등을 정의해야 ggplot의 그래프가 만들어짐
ggplot(diamonds, aes(x=factor(1), fill=color)) + geom_bar(width=1)

# coord_polar('y')옵션을 통하여 원형으로 변경이 가능
ggplot(diamonds, aes(x=factor(1), fill=color)) + geom_bar(width=1) +  coord_polar('y')



# 다이아몬드 cut에 따른 가격 분석하기
# - 전달 값이 1개인 경우 bar 그리기
ggplot(diamonds, aes(x=cut)) + geom_bar()

# - 전달 값이 2개인 경우 bar 그리기
ggplot(diamonds, aes(x=cut, y=price)) + geom_bar(stat='identity')

# 투명도에 따른 가격 총합
# - IF > VVS1 > VVS2 순으로 좋은 것이지만
#   개별 갯수의 차이가 있어서 SI2의 가격 총합이 제일 높다.
ggplot(diamonds, aes(x=clarity, y=price)) + geom_bar(stat='identity')

# 개별 데이터의 수가 다르므로 평균을 구해서 
# 그려보기
diamonds %>% 
    group_by(clarity) %>% 
    summarise(mean_price=mean(price)) %>%
    ggplot(aes(x=clarity, y=mean_price)) + geom_bar(stat='identity') 
# 산점도 그리기
# - 크기에 따른 가격의 분포
ggplot(diamonds, aes(x=carat, y=price, color=clarity)) + geom_point()


# 추세선
ggplot(diamonds, aes(x=carat, y=price, color=clarity)) + geom_point() + geom_smooth()




































