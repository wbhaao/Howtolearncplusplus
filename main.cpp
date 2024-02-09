#include <iostream>

#define HELLO 0x1
#define MYNAME 0x2
#define TIRED 0x4
#define HEL 0x8
#define COLD 0x10
#define FIRE 0x20
#define
#define

// 가독성, 유지보수를 위해 사용하는 define

int main() {
    int isStatus = HELLO;
    // 32가지
    // 비트 연산 종류
    // & : and
    // | : or
    // ^ : xor
    // ~ : 반전
    // << 왼쪽으로 이동
    // >> 오른쪽으로 이동
    isStatus |= MYNAME;
    std::cout << isStatus << "\n";
    if (isStatus & MYNAME)
    {
        std::cout << "hello\n";
    }
    // 특정 자리 비트 제거
    // 오 진짜 된다 싱기
    isStatus &= ~TIRED;



    return 0;
}