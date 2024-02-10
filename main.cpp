#include <stdio.h>

int main(){
    //포인터 변수
    //주소 단위1byte
    //자료형 변수명
    int* pInt = nullptr;
    //주소를 저장
    char* pChar = nullptr;
    short* pShort = nullptr;
    //포인터 변수의 크기는 전부 같다.
    //플랫폼에따라 크기가 다름
    //32bit운영체재:포인터 변수 크기 : 32bit = 4byte
    //64bit운영체재:포인터 변수 크기 : 64bit = 8byte
    int iSize = sizeof(pInt);
    int i = 0;
    pInt = &i;
    pInt += 1;//포인트의 증감 단위는 해당 변수타입의 크기와 동일
    //정리
    //pInt 는 int* 변수 이기 때문에,가리키는 곳을 int로 해석한다.
    //따라서 주소값을 1증가하는 의미느 다음int위치로 접근하기 위해서 sizeof(int) 단위로
    //증가하게 된다.
    //포인터와 배열
    //배열의 특징
    //1.메모리가 연속적인 구조이다.
    //2.배열의 이름이 배열의 시작 주소이다.
    int iArr[10] = {};
    //int 단위 접근
    *(iArr + 1) = 10;//해석:  *(접근한다) (iArr+1)(iArr의 주소로부터+4byte변수에(Airr[1]))
    //=10(그 주소로부터 4byte크기의 변수에 10을 대입한다.)
    *(iArr) = 10;

    return 0;
}
