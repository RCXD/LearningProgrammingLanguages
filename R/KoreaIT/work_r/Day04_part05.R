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


#다이아몬드 cut에 따른 가격 분석하기
#1. geom_bar의 기본 동작 : x의 count를 y로 표시
ggplot(diamonds, aes(x=cut)) + geom_bar()

#전달값이 2개인 경우
ggplot(diamonds, aes(x=cut, y=price)) + geom_bar() #에러남
ggplot(diamonds, aes(x=cut, y=price)) + geom_bar(stat='identity')

#투명도에 따른 가격 총합(diamonds$clarity)
ggplot(diamonds, aes(x=clarity, y=price)) + geom_bar(stat='identity')
#IF > VVS1 > VVS2 순으로 좋음. 
#단, 개별 갯수의 차이가 있으므로 SI2의 가격총합이 제일 높게 잘못 나옴.

diamonds %>% 
  group_by(clarity) %>% 
  summarize(mean_price=mean(price)) %>%
  ggplot(aes(x=clarity, y=mean_price)) + geom_bar(stat='identity')
  #가격을 결정하는 요인이 투명도 뿐이 아니므로 
  #데이터가 실제와는 다르게 보인다.

#산점도(데이터 분포도) 그리기
# 크기에 따른 가격의 분포

ggplot(diamonds, aes(x=carat, y=price)) + geom_point()
#색 넣기 : clarity에 준하여 색 입히기
ggplot(diamonds, aes(x=carat, y=price, color=clarity)) + geom_point()
#Clarity가 일반적으로 가격 상승에 영향을 미친다는 것을 알 수 있다.


#추세선(예측, 머신러닝)
ggplot(diamonds, aes(x=carat, y=price, color=clarity)) + geom_point() + geom_smooth()

#ggplot은 사실 쉽지 않다!
#러닝 커브가 있다!
#세세한 설정을 요구한다!
#하지만 데이터 분석을 하려면 꼭 배워야한다.

#Data Visualization 이유
# - 데이터를 모으기 위해, crawling을 매번 하는 것은 바보같은 행동.
# 아마존, 알리바바 상품정보 크롤링 : 특가세일정보...
# Tx. 오,... 이거 매우 유용할듯?
# 아마존, 알리바바 : crawling을 여러번 하면 IP차단을 당할 수 있다.
# 새벽시간대에 데이터를 수집하는 등...
# 중요한건, 파일형태로 저장해두는것!
#   단, 데이터가 너무 많으면 관리가 쉽지않다!
#   이 때, Database 툴을 사용해야 함.

# Database
#  체계화된 데이터의 모임을 만들 수 있도록 지원해주는 프로그램
#  여러사람과 공유 목적으로 통합 관리
#  중복을 없애고 구조화해서 저장
#  필요할 때 사용할 수 있도록 저장
#  데이터를 지속적으로 관리하고 보호
#  DBMS : Database management System
#   서버에 데이터를 저장해보고..... R은 그래서...?
#   데이터의 추가, 조회, 변겨으 삭제
#   데이터의 무결성 유지
#   트랜잭션 관리
#   데이터 백업, 복원, 보안
# R은 그래서 DB 관련해서 어떻다는거지??
#내 모든 데이터를 DB소프트웨어를 이용해 잘 정리, 관리할 수 있을까?