#include <iostream>

int main() {
    // 배열
    int array[10] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    array[1] = 3;
    // 이걸 왜 에러 안띄우냐...
    array[13] = 4;
    printf("%d", *(array+13));
    // 포인터


    return 0;
}

