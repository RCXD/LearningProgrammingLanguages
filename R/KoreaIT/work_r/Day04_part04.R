#데이터 시각화
# -R의 시각화 배우기


#plot() : x와 y의 값을 기준으로 좌표를 그리는 함수

plot(1,1)
plot(2,2)
plot(2,1)

x <- c(1,2,2)
y <- c(1,2,1)

plot(x,y)


#수학시간에 배운 표 보는 방법을 다시 배워야 한다.
#plot의 가장 중요한 의미는?
#y는 정답으로 생각하라.
#x는 변하는 값.

#점들을 대표하는 선을 그릴 수 있다면, 미지의 점을 찾을 수 있을 것.
#이것이 머신러닝, 예측의 기본

#실습
# cars의 데이터를 이용하여 스피드(speed)에 따른 제동거리(dist)를 plot으로 그리기

cars

x <- cars$speed
y <- cars$dist

plot(x,y)

# barplot() 활용하기
#plot은 일반적인 수학적 평면도를 알고 싶을 때
#barplot은 서열을 알고 싶을 때
#pie()는 비율을 알고 싶을 때
#---은 ...
#plot은 모양새만이 중요한게 아니다.

#표현값에 비례하여 높이와 길이를 가지는 그래프
barplot(x,y)

#직사각형 막대로 데이터를 표현하는 형태

read.csv('https://raw.githubusercontent.com/luxdolorosa/data_set/master/hot_dog/hot-dog-contest-winners.csv') -> hot_dogs

hot_dogs %>% head()
barplot(hot_dogs$Dogs.eaten, xlab = '년도', ylab = '먹은 개수')
#label은 xlab, ylab!

#plot과 비교하기
plot(hot_dogs$Year, hot_dogs$Dogs.eaten)

#갑자기 소비량이 늘어난 이유에 대해 의문을 가질 수 있다.
#이 증가 시점에 빵이 없는 소시지로 규칙이 바뀌었기 때문.

#시계열 데이터 추가(plot에서는 기본으로 있던)
barplot(hot_dogs$Dogs.eaten, xlab = '년도', ylab = '먹은 개수', names.arg=hot_dogs$Year)

#녹색 칠하기
barplot(hot_dogs$Dogs.eaten, xlab = '년도', ylab = '먹은 개수', names.arg=hot_dogs$Year, col='green')

#10개의 무지개색으로 칠하기
barplot(hot_dogs$Dogs.eaten, xlab = '년도', ylab = '먹은 개수', names.arg=hot_dogs$Year, col=rainbow(10))

#pie chart 활용하기 : 원형 그래프. 전체에 대한 각 부분의 비율이 필요할 때
#국가별 우승비율 확인
hot_dogs$Country
#우승 국가의 개수 세기
#count를 쓰던지, 방법이 많다. ??? 하나하나 해보자!! Review!
table(hot_dogs$Country)

hd_labels <- names(table(hot_dogs$Country)) #열이름만 추출해서 레이블 벡터 만들기
class(table(hot_dogs$Country)) #table은 table이다. 벡터로 바꿔줘야함.

hd_values <- as.vector(table(hot_dogs$Country))
pie(hd_values, hd_labels, col=rainbow(4))


#ggplot은 python과는 비교도 안될정도라고 함. 대체 왜일까?

