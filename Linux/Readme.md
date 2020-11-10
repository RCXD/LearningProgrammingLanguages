컴퓨터 네트워크란?
자료를 공유하는 것. 통신 등 여러가지 방법을 동원하는 컴퓨터 디바이스의 집합
컴퓨터와 컴퓨터 사이의 연결을 네트워크라고 함.

전선으로 연결할 수도 있고, 무선(전파, 적외선 등)으로 연결할 수도 있다.

커리큘럼.... 

노드, 호스트(일반적으로 각 컴퓨터) : 네트워크상의 디바이스

속도란? 데이터가 이동하는 속도. Data transfer rate -> 네트워크의 key issue!

clinet / server: C/S model
    client  request ==>         server
            response <==
clinet가 요청하고, server가 response하는 모델이 client-server 모델.
거의 모든 시스템에 적용된다고 함.
현재 무수히 많은 서버들이 존재.
서버에는, web server, ftp server, ...

5G: 거리, 위치가 어디든, 엄청난 속도로 데이터를 전송한다. 이것들이 Data Transfer Rate로 결정된다.
- 초지연: 지연시간이 없다.

Network Type
    LAN: local are network
    WAN: Wide area network
    MAN: Metropolitan area network

    LAN: 지엽적인 개념
    ex) LAN: 학원 강의실 네트웍 / WAN: 학원 / MAN: 서울, 부산, 대전 등 대도시 중심 / 국가: Internet

우리가 주로 다루게 될 네트워크는 LAN
네트워크는 전부 통신가능 거리가 정해져있다. LAN은 그것이 매우 짧은편.
LAN 네트워크 거리가 너무 길어서 신호가 작아지면, 리피터로 키워줄 수 있다.
네트워크 용어나 지식은 사용자 입장에서는 아무 의미가 없다.
다만 공부하는 사람의 입장에서는 각각의 장비의 역할과 용어의 의미를 잘 파악해야 한다.

연결하는 상태(구성)를 Topology라고 함.

# LAN
Topology 종류:
Ring Topology: 인접한 노드와 연결되는 형태(?)
Star Topology: 중앙노드 하나에 다른 모든 노드가 연결되는 형태(?)
Bus Topology ==> Ethernet LAN의 산업 표준(Industrial standard): 노드가 아닌, '버스'에 모든 노드가 연결되는 형태

네트워크 Topology 관련 용어
출발Source ->(route)-> 도착Destination
router가 버스 네트워크의 중간자역할을 해줌.(라우터는 Interface)

# WAN
    Internetworking
    Gateway: LAN상의 하나의 Node를 말함
    Internet: WAN의 한계가 없는 것. entire Globe

# MAN
    Large Cities: 도시 기반 네트워킹

인터넷 연결
    internet Backbone
        고속도로...? 어쩌구?
    Internet service provider (ISP)
        톨게이트마냥... 인터넷 사용료...?
    Broadband
        전화망을 통한 디지털데이터 전송 기술!
        디지털 가입자회선(?)
        데이터를 어느정도 이상 보낼 능력이 되는 상태
        -> 대역폭(Bandwidth)

Bandwidth(대역폭)
    주어진 시간 내에 얼마만큼의 데이터를 보낼 능력이 되는가?
    브로드밴드는 초당 128비트이상 능력을 가지면 부르는 이름이었음.(초창기)

네트워크는 눈으로 볼 수 없는것들이 많다고 함... 
네트워크는 용어들이 많으니, 이것들을 많이 알아야 구축할 때 이해할 수 있다고 함.

패킷 스위칭
패킷: 데이터를 주고받을 때 ...
정보 vs 자료?
나에게 필요한 정보, 그렇지 않은 정보... 
필요한 데이터만 끌어오면, 그것이 나를 위한 정보(데이터)라나?

패킷(Packet): 메세지의 데이터를 일정한 크기로 잘라낸 것
    잘라냈으면 다시 조립도 해야함. 따라서, 조각의 순서도 알 수 있어야 한다. 상대방은 순서에 의해 다시 조립하게 됨.

    패킷은 메시지를 고정된 크기로 잘라서 효율성을 높이는 것
    순서가 정해진 패킷으로 나눈다.
    잘라낸것이 뒤섞여도 처음처럼 재조립이 되어야 원본을 알 수 있다.

    쌍방간에 자료를 주고 받는 것 ==> Packet Switching
        Hand shaking... Ack. 받았는지 알려주고, ...
        통신매체가 적당하게 자른 것(패킷)을 주고, 다 받았으면 받았다고 알려주고... 통신라인에서 이루어짐.
        
        이메일처럼 일방적으로 보낼 수도 있다. 신뢰성은 떨어지는 방식.
        전화: 안받으면 통화 못하는 방식...(Trusted/Untrusted)

메시지 전송시 가장 효율적인 방법은, 크기를 정해서 한 페이지씩 빠르게 덤핑하는 것이 좋을 것이라고....
자료가 산처럼 쌓여있으면, 효율이 떨어져보이기도,...
데이터를 일정한 크기로 잘라낸 것을 패킷이라고 함.

Open System: 개방형 시스템. 앞으로 많이 등장!
    Proprietary system??
        특정인에 소속되어 있는 것. 특허권... MS Office 등
    Interoperability??
        Inter-operatability? 이쪽 저쪽에서 operate 할 수 있는 것.
        윈도우에서만 사용 가능하면, 이 능력이 없는 것.
    Open System
        무료개방, ...
        리눅스: 프리웨어인건 맞다. 단, 하나하나가 라이센스를 가지고 있다.
        GPL, GPL2, LGPL 등.
        사용할 때에 지켜야 하는 Rule이 있고, 지키지 않으면 소송당할 수 있다.
        오픈시스템은 잘 쓰면 좋다..! 
국제단체 ISO... 국제 표준화 기구
    International Organization for Standardization
    OSI: Open system Interconnection: 상호연결을 위한 모델
        네트워크: OSI 7 layored model -> 귀아프게 들을 것!
        데이터의 어디서부터 어디까지가 사이즈이고, 이름이고, 이런 메타데이터? 같은것, 형식같은 것을 알아야 알아들을 수 있다.

        실생활에서는 묵시적인 약속이 흔함.
        쌍방향에서 대화가 이뤄질 때... Protocol...

Network.pdf Pg4
    OSI 7단계 모델 / 기술이 발전했지만 모델은 거의 바뀌지 않았다고.
    Physical Layor: 장비...
    상세스펙도 공개되어 있다.
    명시된 상세스펙대로 프로그램을 짜면, 어느 프로그램과도 Communication을 할 수 있다.
    주어진대로 구성하면, 받는 입장에서도 무리없이 받을 수 있다는 것.

프로그래머, 하드웨어개발자, 자료 구성 개발자 모두 정상적으로 데이터를 주고받을 수 있다.

약 10년 후 변동: TCP/IP Model -> 오늘날 모든 인터넷에서 사용하는 표준 모델
    OSI모델이 너무 상세하므로, 일반적인 수준으로 단계를 줄여 사용하고 일부는 자율에 맡기는 것
Application Layor: 프로젝트의 계획...개념? 어떻게 표현할 것인지?
TCP/IP는 전세계에서 받아들여졌다고 함.
Transport, Internet Layor에서 실제로 패킷을 나누고.. 한다고 함.
    여기가 가장 중요한 Layor이고, 약자를 따서 TCP/IP라고 함
    TCP/IP Suite들의 각 요소를 아주 잘 알고있어야 한다.

    Interface: 레이어끼리의 관계
    프로토콜: 같은 레이어끼리의 관계
    데이터에서 OSI모델로, 또는 반대로 갈 때에는 프로토콜에 의해서...
    OSI모델에서 중요한 것은 흐름의 이해!
    Interface, protocol을 잘 배워야
    네트워크 관리, 네트워크 프로그래밍을 잘 이해할 수 있다.

TCP(Transmission control protocol): 가장 중요한 프로토콜
    message ==> Packet으로 나눈다 ==> IP로 내려보냄
    Destination에서 ==> Packet을 reassemble(순서에 입각) ==> 해석

IP(Internet Protocol)
    final destination을 찾기 위한 상호연결 네트워크로 패킷을 보낸다.
    ==> 라우팅(routing) 처리함.(미로처럼 구성되어 있다)
        IP가 이 미로를 탈출하게 해준다.
    
hostname: Koreaitacademy.com
    번역: network software??

예)
    IP Address: 192.168.186.200 (세계 공통, 네 부분의 주소를 보냄)
    
Domain name
    예) www.google.com / www.naver.com / ...
    .com, .net, .org, .edu, .gov, .mil... (최초 9개 도메인)
    .biz, .info, ...
    => Top level domain: 이미 만들어져 있다.

    2자리 국가코드
    우리나라: .kr

TCP, UDP
    -> TCP/IP Suite에서...
    TCP : Trusted(전화를 받아야...)
    UDP : Untrusted(이메일처럼)
        빠르다. 다만 상대가 받았는지, 안받았는지 모른다.
            단, 요즘은 아는 방법이 생겼다.

Extranet: 확장된 네트워크
Protocol: 규율, 약속
Port: 주소를 보낼 때, 최종 목적지를 정확하게 지정하는 것.
HUB: 리피터 형식... 중간에 뿌려주는 역할
Bridge: 네트워크 연결 시, 말그대로 다리 역할.
Switch: 네트워크 스위칭 장비: 연결을 바꿔주는...
    상대방에게 넘어가야 하는 정보인지 아닌지 구분해주는... 필터 역할
    역할이 매우 중요하다.
    요즘: 허브/브릿지/스위치/라우터 개념을 헷갈려 함.
        장비들이 발전해서 다른 역할도 수행할 수 있기 때문
MAC Address: Media Access Control...
    랜카드라는 장치가 랜포트를 연결해줌. NIC(Network Interface? Card)
    카드마다 '주소'가 '유일'하게 정해져 있다. 총 48비트로 구성. 24비트는 제조사 고유코드, 24비트는 시리얼 넘버
    랜카드는 전세계에서 고유한 값을 갖는다.
    데이터가 다른 PC로 가지 않고 정확히 전송될 수 있도록 해줌
CSMA/CD
    버스회사 종점에서 버스가 출발할지 여부를 판단하는 시스템처럼. 
    라인을 쓸 수 있는지 확인, 다중 접속...
    CD: 충돌 인지 => 제대로 갔는지 안갔는지를 판단
    하나의 데이터 전송라인을 공유해서 쓸 때 필요한 개념

ISDN: 전화망으로 데이터...?????
통합된 데이터..

VPN: Direct 연결할때 사용할 수 있다?

DHCP: Direct Host control protocol?
    IP가 낭비되는것을 방지

IP address: 각 필드가 8비트, 총 32비트
    2^32bit ==> 4.29Gbit ==> 약 43억개 ==> 실제 사용은 약 2.5억개
    ==> DHCP(IP를 더 만들어내는 기술) 
    통신사에서 공인된 IP를 받을 때, IP를 몇개 사용할건지, 동적/고정으로 쓸 건지 협조

    우리나라에서 쓸 수 있는 IP의 개수도 한정되어 있음.
    회사에서 쓸 수 있는 개수도 정해져 있음.
    공인IP
    사설IP => 임의 IP로는 인터넷 연결이 안됨.
    VMware guest OS

DHCP -> 연결할 때 필요?

DNS: Domain name system(server)
 => 각 회사 서버의 IP주소를 알 수가 없음(이름은 알고 있음)
 => 이름을 주소로 변환(주소 변환 서버가 따로 있음)
route?root? domain: 동양에는 13개


/etc/resolv.conf 파일 수정
    168.126.63.1 => KT 네임서버
    8.8.8.8 => 구글 네임서버
        네임서버를 주소로 바꿔줌: DNS가 하는 일

Flooding: 데이터가 나가는 것
Forwarding: 전달
Filtering: 데이터를 전달할 필요를 판단
Aging: 주소를 못찾으면 트래픽이 많아질 수 있으므로 도태시킴(생명주기를 줌) => 이메일주소 반송 등
Broadcasting: 
    카톡 => 단체메일 보내기
Looping: 반복 / 반복횟수 한정
    Local loop: 한바퀴 돌고 돌아옴?


# OSI 7 Layer
## Application Layer
    POP3: Post office Protocol 3 / 회사에서 쓰는 Outlook 등
        Outlook: 회사업무 처리 프로그램 세트
        보여짐과 동시에 다운받을지를 결정...?
    IMAP: 
        메일서버에서...?
## Presentation Layer
    읽는쪽에서 정상적으로 받을 수 있도록 표현을 일반화
    ex. 확장자, 약속, .. 보여지는 것에 대한 약속
## Session Layer
    A, B가 통신을 주고받을 때, 연결이 되면 하나의 세션이라고 함.
## Transmission Layer
    TCP가 하는 일. 자기 정보를 붙임(Encapsulation), 목적지 주소를 붙임, ...
    네트워크 프로그래밍 시 중요 
## Network Layer
    빠르고 안전한 경로 선택: IP가 하는 일
## Data Link Layer
    최종적으로 네트워크카드에 연결되도록 해야 함. 랜카드는 전세계 유일
## Physical Layer
    장비 수준의 레이어: 전압값에 따른 신호 등

AP(Access point)가 거리 내에 있다면, ...

프로토콜: 이름만 봐도 뭔지 알 수 있도록 감 잡을 것
ICMP
ARP: 맥주소를 읽어드리는 명령, ...
UDP: 상대를 무시하고 보내는/읽어들이는...

TCP와 UDP
    TCP: 보안성 좋음 -> 안정성 / 데이터를 보내면 정확히 감
        동기: 데이터를 읽게 시킴
        3way handshake 방식
            char 하나 날림(Question) -> 준비됨 알림(Ack) -> 메시지 전송(Confirm)
    UDP: 안정성은 떨어지지만 속도가 높다.
        비동기: 재전송 요청 없음 / 한꺼번에 읽게 시킴

주소 IPv4(구식), IPv6
    앞으로 IP의 수요가 많다. 기존의 체계로는 부족.
    IPv6가 그 대안임.

IPv4 구성
    4Byte
    Network Address: 공간마다의 주소(강의실 주소같은)
    Host Address: 각 PC마다의 주소
        ex) ~~길: Network address / ~~번지: Host address

    각 클래스로 Network address의 길이, Host address의 길이를 구분!

    Class A에서는 Network Address가 1Byte -> 가질 수 있는 네트워크의 개수는 2^8 = 256개다.
    Class B에서는 2^16개
    Class C에서는 2^24개
    Mutlicast Address: 다중으로 네트워킹할 때...?
    Reserved: 나중을 위한 예약 

네트워크 IP:
    맨 첫차리 숫자가 127보다 작으면 Class A이다.
    네트워크 개수는 2^7 = 128개
    하나의 네트워크 내 IP갯수는 2^24개
    
    Class B는 네트워크 개수 2^14개, 각 네트워크당 IP갯수 2^16개
    네트워크/호스트의 각 비트수를 잘 기억할 것
    => 14페이지
    맨 앞의 주소값으로 각 Class를 알 수 있따!
    우리가 대부분 사용하는것은 C클래스이다.
    223~239: 우리가 알 필요는 없다고 함.
    255: 테스트를 위한 예비주소... 우리가 쓸 일은 없다고 함.

리눅스 네트워크 관리
    넷마스크(NetMask)
    호스트를 가장 적게 사용하는 것이 C Class.
    많은 네트워크들에 각각의 호스트를 가질 수 있음.
    네트워크는 통신사에서 부여받아야 쓸 수 있다. 마음대로는 못쓴다.
    할당하지 않아서 남는것이 있을 경우, 호스트 부분을 쪼갬.
        이것을 서브넷이라고 부름.
        여기서부터 호스트주소다... 를 알려줄 수 있어야 한다고 함...???
    
    네트워크 부하 감소. 사용자가 적으니까 트래픽이 줄어듦. 통신이 빨라짐.
    독립네트워크 구성 가능.(특정 클래스만 쓰도록...)

    0~127까지는 Class A 주소.

16p에 오류 있다고 함. 주의.
    서브네팅:... 마스킹해서...

마스킹: 세팅이 들어가는 것...(->1)
    마스킹이란, 그 부분을 셋하고 들어가는 것
언마스킹: 세팅을 지우는 것(->0)
    ex) C class
        192.170.32.xxx
        Network: 192.170.32.0
        Host: 0.0.0.xxx
        네트워크를 나누려는 개수에 따라 호스트 갯수가 줄어듦.
            이 때 필요한 넷마스크값은 pg17
            넷마스크값은 어떻게 계산하는가? 일단 외워야한다고 하는데...?? 각 값 구하는법 -> pa18
            (마스크값 10진수로 변경)
            넷마스크값으로 나눠서 쓴다?
    마스크값을 구하는건 알겠는데, 
    호스트 개수가 저렇게 나온 이유는? 계산법은?
    2^n-2처럼 보이는데? 수식으로 나타내보는게 쉬울듯!!

21페이지에서 16진수바꾸기에서 2^0이 아닌 16^0임.

주소값을 2인법, 16진법으로 표현할 줄 알아야 함!

서버가 2~3개가 필요하다...?
Copy해서 쓰면 될 것....
VM ware에서.

cat /etc/sysconfig/network
ls /etc/sysconfig/network-scripts/
ens-33? vmware가 지정한 네트워크 이름. (default)

NIC 정보 확인...
cat /etc/sysconfig/network-script/ifcfc-ens33
요즘은 Onboard.

BOOTPROTO="dhcp" -> dynamic host control protocol
    -> 네트워크주소는 이 시스템에서 자동으로 부여받은 것.
NAME="ens33"
UUID: 유일한 아이디..우리가 신경쓸 필요는 없다.

설정>네트워크>VPN가상사설망/네트워크프록시 꺼진 상태.

브라우저를 켜서...?

추가: 
IPADDR = "192.168.111.임의(ex. .100)"
NETMASK="255.255.255.0"
GATEWAY="192.168.111.2"
---
VMWARE Workstation 15 Pro를 다운받아야 한다고 함!
Centos7 다운받고, 네트워크는 NAT
vmware 옵션에서
-> 사용할 수 있는 주소범위...
192.(C class)부터 255. 로 되어 있다.
local dhcp 사용 안함으로..

vi /etc/sysconfig/network-scripts/ifcfg-ens33
vi /etc/resolv.conf
systemctl restart network


/etc/hosts/
FQDN은 url이라고 보면 된다고 함.
www.~...
호스트이름으로 사용할 수도 있다?

네임서버를 vmware꺼로 연결할 수 있다?
name서버는 무엇?
초창기에는 Dns가 없어도 연결하는게 무리가 없었으나,
지금은 번호로 찾을 수가 없어서, 전화번호부 등록하듯 지정이 되어 있는 것.
사람은 숫자를 외우는건 거의 불가능
문자는 잘 외움


====================
Day2
CentOS7은 시장에서 많이 사용되고 있음.
8을 배워도 크게 차이는 없다고 함
명령어는 조금 다르다고 함.

슈퍼데몬...?
xinetd
Daemon
PS: process status
    현재 상태에서 process status들이 어떻게 되어있는지 확인하는것: 
    작업관리자 같은거인듯

TTY: 터미널...? 우리가 쓰는 터미널과 연관이 없으면, ?가 나온다고 함
TTY에 pts/0이라고 나와있는건, 화면에서 작업하는 중인 것임.
?는 나와는 상관 없는, 백그라운드 프로세스임.

=> 데몬: 백그라운드 프로세스(?)
    클라이언트서버 모델에서, 항시 대기하고 있는 것들

PS에서,
unix버전, GNU버전(리눅스), BSC버전이 있다. __로 된게 뭐라고?
백그라운드 프로세스들 -> 데몬이라 부름...
데몬은 항상 떠 있다.

데몬은 일반적으로 메모리를 많이 차지: 시스템이 돌아가는 방식???

단독으로 실행되는 대몬: ... 
httpd -> 웹서버
named -> dns서버... ip주소를 변환해주는 프로세스
sendmail: 메일서비스
crond: 클럭 대몬.. 주어진 ?에 의해 실행?
rsyslogd -> r-: 리모트를 의미함. => local, remote 모두 컨트롤하는..
dhcp: ...


슈퍼대몬: inetd -> 인터넷 슈퍼 서버
네트웍 관련 많은 서비스들을 총괄함.
    연결요청을 받으면, 자격이 있는지를 판단하고....
    자주 실행되지 않는 대몬을 관리
    클라이언트 요청에 의해 실행
    요즘은 PC성능이 매우 좋아져서 응답시간이 체감이 힘들 정도
    이름이 xinetd로 바뀜

    파일처리는 inetd를 아직 사용중이라고 함.

LINUX18 pg6 오탈자 -> logi가 아니라, login임.
텔넷은 보안상의 문제가 많아서, 요즘은 사용하지 않는다고 함.
로그인 패스워드가 암호화되지 않는다고.
테스트용으로만 텔넷을 쓴다고 함.

ftp: 파일 다운로드, 업로드... 파일전송에 쓰임
finger: 리모트도 확인할 수 있다고 함...
    일반 커맨드: w명령... -> 
    yum install finger: 리모트 프로세스까지 확인할 수 있음
auth: 인증
shell: 
TCPD: TCP wrapper...? 시스템을 감싸는 것...?
    보호하기 위해 감쌈. 보안분야...

inetd: 접속요청시 대몬을 떠야...(?)
여러 프로세스들은 메모리를 평소에 많이 사용하지 않으니, 아직 올리지 않고
가만히 있는다.
super daemon인 inetd가 전부 받아들이고, tcpd로 넘김.
    성공/실패를 log함. 시스템 보안을 위해.
    access 권한 판단. 있으면 연결, 없으면 끊음.

xinetd: 확장 inetd
    8p 오탈자: RCP서비스가 아니라, RPC(Remote procedure call)임.
    xinetd는 기본적인 공격 방어수단으로 작용

standalone: 상주 -> 서버부하 증가

inetd, xinetd를 쓰면 일반대몬들을 관리.
메모리 상주가 없어 반응이 느리나, 부하가 줄어든다! 시스템 입장에서는 괜찮음
-> 제어(control)이 가능하다. => authentication(인증) 등 일차적인 필터링이 가능함. -> 수퍼대몬을 쓰는게 일반적으로 좋다.

xinetd: TCPd가 어디에 들어가는지 확인해서 걸러준다. 
    TCPd를 통해서만 사용이 가능하다.
standalone: 단독으로 운영됨. => 자체 제어 매커니즘을 가지고 있다.


    



