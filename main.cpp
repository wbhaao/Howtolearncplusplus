#include <iostream>

int change_val(int *p) {
    *p = 3;

    return 0;
}
int main() {
    // 레퍼런스 라는 것이 있음
    // 참조자는 타입& 이름 = 참조변수이름으로 구성
    // 이름을 바꿀 떄 참조변수이름 값도 바뀜
    // 즉, 이름은 참조변수이름의 또 다른 이름이다

    // 특징1, 처음에 누구의 별명이 될지 정해야함
    // 즉, 한번 별명이 결정되면 바뀔 수 없음

    /*
    int a = 10;
    int &another_a = a; // another_a 는 이제 a 의 참조자!

    int b = 3;
    another_a = b; // ??
     에서 마지막 줄은 a=b와 같다
     */
    // 레퍼런스는 메모리 상에 존재하지 않을 수 도 있다.
    // 어차피 별명과 같은 기능을 하니까.

    /*
     #include <iostream>

    int change_val(int &p) {
      p = 3;

      return 0;
    }
    int main() {
      int number = 5;

      std::cout << number << std::endl;
      change_val(number);
      std::cout << number << std::endl;
    }
     에서 레퍼런스가 사용됨

     cpp에서 입력을 받을 때
     std::cin >> user_input;게 받음
     c에서는
     scanf("%d", &user_input);게 받음

     cin이 레퍼런스로 user_input을 받았기 때문
     리터럴 : 상수

     int &ref = 4;
     이건 안되는데

     const int &ref = 4;
     이건 가능

     레퍼런스의 배열과 배열의 레퍼런스
     - 씹어먹는 시리즈의 단골 코너 (ㅁㅁ의 00과 00의 ㅁㅁ)
     - 3번 돌려볼 준비

     int a, b;
     int& arr[2] = {a, b};
     이거 하면 에러가 난다. 왜냐?

     레퍼런스의 레퍼런스,레퍼런스의 배열, 레퍼런스의 포인터는 존재할 수 없다.
     라는 규칙이 있기 때문

     배열의 주소는 *arr이고 첫번째 요소 주소는 *(arr+1)이다
     하지만 레퍼런스는 메모리에 없기 때문에 저게 안됌

     레퍼런스를 리턴하는 함수
int function() {
  int a = 2;
  return a;
}

int main() {
  int b = function();
  return 0;
}
얘는 됨

int& function() {
  int a = 2;
  return a;
}
     레퍼런스를 리턴하고 있지만
     a는 사라짐
     즉, 별명만 남게됨

int main() {
  int b = function();
  b = 3;
  return 0;
}
얘는 안됨

int& function(int& a) {
  a = 5;
  return a;
}

int main() {
  int b = 2;
  int c = function(b);
  return 0;
}
     */
    int number = 5;

    std::cout << number << std::endl;
    change_val(&number);
    std::cout << number << std::endl;
}