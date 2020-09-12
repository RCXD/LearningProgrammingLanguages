#Data Frame : 매트릭스와 같은 행과 열로 이루어진 데이터 구조
# 서로다른 형태의 데이터 형태를 저장할 수 있는 구조

items <- c('콜라', '사이다', '오렌지쥬스', '커피')
prices <- c(1000, 1200, 1500, 3000)

df_drinks <- data.frame(items, prices)
df_drinks

#실습1 : df_drinks에서 items열을 조회
df_drinks[, 'items']
df_drinks$items

#실습2 df_drinks에서 prices열을 조회해서 총합 구하기
df_drinks[, 'prices']
sum(df_drinks[,'prices'])

#실습3 df_drinks에서 items의 2행, 4행 조회
df_drinks[c(2,4), ]

#데이터 프레임과 자주 사용되는 함수
# - merge : 기준에 따라 데이터를 결합할 수 있는 함수
#   inner join : 교집합
#   left(right) outer join : 왼쪽이나 오른쪽에 있는 데이터가 전부 나오도록 함
#   full outer join : 합집합
items2 <- c('콜라', '우유', '커피', '탄산수', '토마토쥬스')
etc <- c(T, F, F, T, T)
df_drinks2 <- data.frame(items=items2, etc)
df_drinks2
df_drinks

#inner join : 교집합
merge(df_drinks, df_drinks2, by='items')

#left(right) outer join : 왼족이나 오른쪽에 있는 데이터가 전부 나오도록 함
merge(df_drinks, df_drinks2, by='items', all.x = TRUE)

#실습 : df_drink와 df_drinks2의 prices의 총합 구하기
f3 <- merge(df_drinks, df_drinks2, by='items', all.x = TRUE)
sum(f3$prices, na.rm=T) #na값을 다루는걸 잘 알아야.