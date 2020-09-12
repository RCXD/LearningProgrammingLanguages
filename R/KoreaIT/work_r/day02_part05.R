#day02_part05
#author : kch
#place : KoreaIT
#date : '20-08-29

###########
# Factor
# 담겨져 있는 데이터가 어떻게 구성되어 있는가?
# 요인들이 어떻게 구성되어 있는가?
# 순위를 가질 수 있고, 순위가 없을 수 있다.
# 지금까지 Scalar를 제외하고 모두 순서가 있었다.
# Factor는 문자처럼 보이지만 실제로는 숫자이다.(??)
  #levels 벡터에 대해 정의된 상대적인 가중치 벡터로 생각하면 될 듯.
# 수준(level)이라고 알려진 사전에 정의된 값만 다룰 수 있다.


#Factor와 vector 비교
gen <- c('male', 'female', 'male', 'female')
gen
class(gen)

gender <- factor(c('male', 'female', 'male', 'female'))
gender
class(gender)
#level값이 추가되어 있다. female, male level 추가됨.
   # level이 정의된 순서는? 무관하겠지...?
  
#level 조회
levels(gender)

#factor에 순위가 필요한 경우
a <- c('low', 'med', 'high')
b <- rep(a, 3) #rep : 반복해서 정의 : 그냥 길게 늘어진 벡터 정의

# 벡터를 이용해서 factor 정의
fineDust <- factor(b)
fineDust

# Factor를 만들 때 levels를 직접 지정하여 순서 지정 가능
fineDust <- factor(b, levels = a)
fineDust

#순서(order)를 주지 않았기 때문에 min, max는 의미가 없다.
min(dust) #Error

#oder를 주게되면 min, max가 만들어진다. 일단 기본은 오름차순
fineDust <- factor(b, levels = a, ordered = TRUE)
fineDust


min(fineDust)
max(fineDust)

#Factor는 사전에 정의된 값만 입력 및 수정이 가능하다.
fineDust[10] <- 'l' #정의되지 않은 값은 NA가 추가됨.
    #Question : NA는 무슨 특징?
fineDust[11] <- 'low' #정의된 값들 : low, med, high
fineDust



