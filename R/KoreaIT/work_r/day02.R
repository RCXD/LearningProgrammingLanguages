#day02_part01
#author : kch
#place : KoreaIT
#date : '20-08-29

Comment1 = "
    if 조건문
    if(Condition) {

    }
"
#R에서 참, 거짓 대수는 TRUE, FALSE다. python은 앞글자만 대문자임. C는 아마 달랐던거같기도?
if(FALSE){
    print('조건이 참이므로 실행')
} else {
    print('조건이 거짓이면 실행')
}

x <- 1
if(TRUE) {
    x <- 3
}
x

#실습
#money

buck <- 10000
if(buck >= 5000){
    print('latte')
} else {
    print('maxim')
}

money <- 10000
if (money<1000) {
  print('insufficient budgets')
  money
} else if (money<5000) {
  print('drink maxim')
  money <- money - 1000
  money
} else {
  print('drink latte')
  money <- money - 5000
  money
}


####################
# Switch Sentence
# switch(Expression,
#        case1,
#        case2,
#        ...,
#        default
#        )
# What a wired gramma?
####################

switch('pwd',
       id='hong',
       pwd='1234',
       name='홍길동'
       )
#어떻게 변수형태인데 작동하는거지? 정의야 그렇다치고...

####################
#조금 특별한 조건문
#3항 조건문
#ifelse(Condition, TrueSentence, FalseSentence)

ifelse(TRUE, 'true', 'false')
ifelse(FALSE, 'true', 'false')

### Mission
y <- 3
ifelse(y%%3, y <- 0, y <- 3**2)
y
# power operator : **, ^ both Okay


###################
# For Sentence vs While Sentence
# For문은 반복횟수를 알고 있어야 한다?
# While은 조건만 중요하고 반복횟수는 중요하지 않다?
# 굳이 이런 구분이 필요한가?
# ANSWER : For 문에는 리스트를 매개변수로 쓰기 때문..!

cnt <- 1
while(cnt<7){
  print(cnt)
  cnt <- cnt+1
}

cnt2 <- 1:4  #특이하게도 이럴땐 정수integer네
for(i in cnt2){
  print(i)
}

###################
# Mission
###################
items <- c('Alpha', 'Bravo', 'Charlie', 'Delta')
for(i in items){
  if(i == 'Bravo'){
    print(i)
    print('Delicious')
  } else {
    print(i)
  }
}

items <- c('Alpha', 'Bravo', 'Charlie', 'Delta')
for(i in items){
  print(i)
  if(i == 'Bravo'){
    print('Delicious')
  }
}  

items <- c('Alpha', 'Bravo', 'Charlie', 'Delta')
for(i in items){
  print(i)
  switch(i,
         Bravo=print('Delicious')
  )
}     
### witch문, repeat라는 것도 있네...
#사용자 정의 함수
# function_name <- function(param){
#   expression
# }

fruits <- function(p){
  if(p == 'Banana'){
    'very good'
  } else if (p == 'Apple') {
    'good'
  } else if (p == 'Strawberry') {
    'good good'
  } else {
    'so so'
  }
}


fruits('Banana')
fruits('Apple')
fruits('Strawberry')
fruits('Peach')

# 내장함수
# sum(), mean() ...