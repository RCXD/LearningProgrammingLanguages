LinkedList??

New Node?

이게 대체 어디서부터 시작한거지? 몇분 안지난거같은데

강의자료는 무엇?

폴더 비밀번호는 무엇...?

링크드리스트
노드
뉴노드
리스트가 생성되는 방법
헤드, 데이터, 넥스트 데이터
끼워넣기(insert)하는 방법

링크드리스트 수정, 삭제, ...
연결은 포인터같은 뭐 그런건가?
append메소드, insert메소드, update메소드 ...
여러 자료구조들 중 하나겠지만...

------------------------------------------

원형연결리스트? 갑자기?

원형연결리스트 : 
마지막 노드가 리스트의 첫번째 노드를 가리키게 하여 리스트의 구조를 원형으로 만든 연결 리스트

장점 : 순화하여 이전 노드로 접근하는게 가능해진다
단점 : 구현이 더 어렵다.


이중 연결 리스트
    연결이 두 번 되어있는 리스트
    앞의 노드, 뒤의 노드 둘 다 연결이 되어있는 리스트.
    doubly linked list를 말하는 듯

    장점 : 이전노드로 이동하기가 편하기 때문에 탐색시에 속도가 굉장히 빠르다.
    단일연결리스트는 next로 계속 돌아야함.
    단점 : 구현이 어렵다. 메모리 사용이 더 많다.

~~~
class Node:
    data # 데이터 공간
    next # 다음 노드의 주소.. 파이썬에 딱히 포인터는 없지만 클래스를 가지고 포인터 개념을 다룰 수 있는 듯. 
    #C도 Linked List가 되는지, 어떻게 되는지 알아보자.
    prev # 이전 노드의 주소
~~~