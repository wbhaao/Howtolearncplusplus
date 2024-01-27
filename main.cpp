// iostream이라는 헤더파일을 include 하고 있다
#include <iostream>
// 아래꺼 쓰면 std 안써도 자동으로 std 붙여짐
//using namespace std;
int main() {
    // std::cout : 출력해주는 것
    // std::endl 한줄 개행
    // std : C++ 표준 라이브러리의 모든 함수, 객체 등이 정의된 이름 공간(namespace) 입니다.
    std::cout << "Hello, World!" << std::endl;
    // std::cout << /* 출력할 것 */ << /* 출력할 것 */ << ... << /* 출력할 것 */;
    return 0;
}
