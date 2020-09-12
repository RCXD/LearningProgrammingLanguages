# Rstudio 설치
# Rstudio 사용자 설정(Version 1.3.1073)
1. [참고 링크](http://freesearch.pe.kr/archives/3279)
2. 이 [링크](http://code.google.com/p/spellcheck-ko/downloads/list)에서 다운받는다.
   또는 동봉된 ko-aff-dic-0.5.6.zip 활용
3. dictionaries의 저장경로가 windows 10 기준으로
    %appdata%\RStudio-Desktop\dictionaries\languages-system 이다.
4. Rstudio 상단메뉴 -> Tools -> Global Options -> Spelling
   여기서 Custom dictionaries에 추가해도 되고,
   Main dictionary languages에서 ko를 추가하면 됨.
5. UTF-8 고정
   1. 간혹 인코딩때문에 귀찮은 팝업이 계속 뜰 때가 있다.
   2. 방법 : Tools > Global Options > Code > Saving > Default text encoding > UTF-8


# R notebook 설치(Rstudio)
1. R, Python, jupyter notebook 설치
2. R console에서 설치
   ~~~ R
   install.packages('IRkernel')
3. Jupyter에서 활성화하고싶다면 R console에서
   ~~~ R
   IRkernel::installspec(user = FALSE)
4. 3번은 경로 지정할 때 주의
   경로명에 한글이 있으면 영어로 바꿀 것
   만약 windows 10에서 onedrive 폴더에 지정된
   한글폴더명이 문제이면 이 [링크](https://support.microsoft.com/ko-kr/office/onedrive%EC%97%90%EC%84%9C-%EC%9C%A0%ED%9A%A8-%ED%95%98%EC%A7%80-%EC%95%8A%EC%9D%80-%EB%AC%B8%EC%9E%90%EA%B0%80-%ED%8F%AC%ED%95%A8-%EB%90%9C-%ED%8C%8C%EC%9D%BC%EC%9D%98-%EC%9D%B4%EB%A6%84%EC%9D%84-%EB%B0%94%EA%BF%80-%EC%88%98-%EC%9E%88%EC%9D%8C-99333564-c2ed-4e78-8936-7c773e958881) 확인
## Option : Refinitiv's API for R
1. Rtools 다운로드
   1. [R Version 4.0.0 이상](https://cran.r-project.org/bin/windows/Rtools/)
   2. [R Version 3.x.x](https://cran.r-project.org/bin/windows/Rtools/history.html)
2. [Eikon Data API 다운로드](https://developers.refinitiv.com/article/setup-jupyter-notebook-r)
3. [Plotly for R 다운로드](https://plot.ly/r/getting-started/)