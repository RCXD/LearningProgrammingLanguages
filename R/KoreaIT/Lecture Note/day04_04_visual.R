# 데이터 시각화
# - R의 시각화 배우기

# plot(): x와 y의 2개의 값을 기준으로 좌표를  그리는 함수
plot(1, 1)
plot(2, 2)
plot(2, 1)

x <- c(1, 2, 2)
y <- c(1, 2, 1)
plot(x, y)


# R의 기본 데이터를 이용한 plot 알아보기
cars

# 실습하기. cars의 데이터를 이용하여 스피드(speed)에 따른
#           제동거리(dist)를 plot으로 그려주세요.
plot(cars$speed, cars$dist)

# barplot(): 표현 값에 비례하여 높이와 길이를 가지는 그래프
# 직사각형 막대로 데이터를 표현하는 형태
hot_dogs <- read.csv('https://raw.githubusercontent.com/luxdolorosa/data_set/master/hot_dog/hot-dog-contest-winners.csv')
hot_dogs %>% head()

barplot(hot_dogs$Dogs.eaten, xlab = '년도', ylab='개수', names.arg = hot_dogs$Year, col='green')

barplot(hot_dogs$Dogs.eaten, xlab = '년도', ylab='개수', names.arg = hot_dogs$Year, col=rainbow(10))

plot(hot_dogs$Year, hot_dogs$Dogs.eaten)

# piechart(): 원형 그래프. 전체에 대한 각 부분의 비율
hot_dogs$Country
# 우승국가의 갯수 세기
table(hot_dogs$Country)

hd_labels <- names(table(hot_dogs$Country))

# 테이블로 얻은 데이터 값을 vector 변경
hd_values <- as.vector(table(hot_dogs$Country))
pie(hd_values, labels = hd_labels)




























