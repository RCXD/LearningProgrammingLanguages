#ggplot!

install.packages('ggplot2')
library(ggplot2)
#hadley wicom 교수 개발
# R의 기본 차트에 비하여 상세한 설정이 가능
#ggplot2는 데이터를 이해하기 위한 시각화 툴

#R에서 가장 중요한 툴
#Python Pandas의 ggplot, matplotlib... 느리다.
#Deep learning에서는 Python이 유리하나,
#데이터 분석은 R이 유리

#Python은 프로그래밍 전문, 
#R은 데이터 분석 전문 언어


library(dplyr)
library(tidyverse)

diamonds
#다이아몬드는 무조건 큰것이...
#가격이 올라갈리 없으니 팔 가치가 없고
#커팅도 불순물여부가 있다지만 의미는 없다고

#pie그래프

ggplot(diamonds)

#미학요소(aesthetics)
#데이터의 변수와 그래프의 크기, 형태, 색 등을 정의해야 ggplot의 그래프가 만들어짐.
diamonds$color
#diamonds의 color라는 열을 가지고 채우기... fill은 파이조각을 채울 각 요소인듯.
#x=factor(1) 이건 뭐지? 동영상 확인좀. geom_bar는 또 무엇? 있어야 색깔별로 뭔가 나오는데?
ggplot(diamonds, aes(x=factor(1), fill=color))
ggplot(diamonds, aes(x=factor(1), fill=color)) + geom_bar(width=1)

ggplot(diamonds, aes(x=factor(1), fill=color)) + geom_bar(width=1) + coord_polar('y') #원형 형태로 표시하기





