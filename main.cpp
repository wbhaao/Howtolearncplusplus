// 변수의 정의
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
int main() {
    //  변수선언은 c 랑 똑같다
    char c;
    double d;
    float f;
    // 포인터도 똑같음
    int arr[10];
    int *parr = arr;

    int i;
    int *pi = &i;
    // for,문도 똑같음
    for (int i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }

    // 다른 점은 변수를 최상단에서 선언하지 않아도 됌
    // 코드 중간에 선언해도 된다는 얘기

    int lucky_number = 3;
    std::cout << "내 비밀 수를 맞추어 보세요~" << std::endl;

    int user_input1;  // 사용자 입력

    while (1) {
        std::cout << "입력 : ";
        // 입력받는 "것"
        std::cin >> user_input1;
        if (lucky_number == user_input1) {
            std::cout << "맞추셨습니다~~" << std::endl;
            break;
        } else {
            std::cout << "다시 생각해보세요~" << std::endl;
        }
    }
    int user_input;
    cout << "저의 정보를 표시해줍니다" << endl;
    cout << "1. 이름 " << endl;
    cout << "2. 나이 " << endl;
    cout << "3. 성별 " << endl;
    cin >> user_input;

    switch (user_input) {
        case 1:
            cout << "Psi ! " << endl;
            break;

        case 2:
            cout << "99 살" << endl;
            break;

        case 3:
            cout << "남자" << endl;
            break;

        default:
            cout << "궁금한게 없군요~" << endl;
            break;
    }
    return 0;
}