<?php

 

 

require_once './Etc.php';

 

 

 

 

/**

 *

 * @brief 테스트를 위한 클래스이다.

 * @details 내부에서 아무짓도 안한다.

 * @author oncellboy

 * @date 1234-12-12

 * @version 0.0.1

 *

 */

class Test{

 

public $test; 

 

 

 

public function __construct()

{

 

}

 

 

 

public function show()

{

 

$etc = new Etc();

 

$str = $etc->getText();

 

print_r($str);

}

 

 

/**

 *

 *        @brief 메서드 간략 설명

 *        @details 메서드 자세한 설명

 *        @param string a 파라미터 번

 *        @param string b

 *        이거는 테스트 파라미터

 *

 *        @return mixed|boolean

 *  성공시 숫자, 실패시 false 반환

 *        

 *        @throws ValidException 나쁜짓하면 예외발생        

 *

 *

 *

 *  @todo 다음주까지 해야할 업무

 * 

 *  @bug 반환이 언제나 false이다. 해결해야함

 *

 *

 *  @see 그냥 이것저것

 *  보여줘야하는 것

 *

 *        

 *        First Header  | Second Header

 *        ------------- | -------------

 *        Content Cell  | Content Cell

 *        Content Cell  | Content Cell

 *

 *  @li list 1

 *  @li list 2

 *

 *  [내 블로그](http://onecellboy.tistory.com)

 *

 *        @code{.py}

 *  #!/usr/bin/python

 *        print "Hello World! 뜸금없는 파이썬 코드"

 *  @endcode

 *

 *  이 클래스를 사용합니다. @ref Etc @n

 *  이 네임스페이스의 이 클래스를 사용합니다. @ret subFolder.Etc

 *

 */

public function add($a,$b)

{

$sum = $a + $b;

 

 

return $sum;

}

}



출처: https://onecellboy.tistory.com/342 [신불사 - 신현호라 불리는 사나이]