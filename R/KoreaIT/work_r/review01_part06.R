#Factor(요인) : 데이터의 구조가 어떻게 이루어져있는가를 나타내는 자료구조
#순서(Index)가 있을수도 있고, 없을 수도 있다.(정렬될 수도 있고, 아닐 수도 있다.
#사전에 미리 정의된 값만 넣을 수 있다.(?)

dust <- c('low', 'medium', 'high')
dust

fac01 <- factor(dust)
fac01 #순서가 dust와 다르고 뒤섞여있음. 기본적으로 순위는 없다. 가중치를 줄 수 있다.

fac01 <- factor(dust, levels = dust)
fac01 #순서만 dust벡터 기준으로 만들어진것이고, 우선순위는 없다.

fac01 <- factor(dust, levels = dust, ordered = T)
fac01

#factor에 값 추가하기
fac01[4] <- 'law'   #레벨에 지정되지 않은 값
fac01               #사용할 수 없다. NA(누락값)으로 입력됨.(에러는 안남)

fac01[5] <- 'low'   #레벨에 지정된 값만 추가할 수 있다.
fac01
