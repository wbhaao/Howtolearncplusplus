#include <iostream>
#include <string.h>

class MyString {
    char* string_content;
    int string_length;
    int memory_capacity;

public:
    MyString(char c);
    MyString(const char* str);
    MyString(const MyString& str);
    ~MyString();
    // const는 클래스의 어떤한 멤버변수도 수정하지 않을 것이라는 뜻
    // 읽기 전용 메소드
    int length() const;
    int capacity() const;
    void reserve(int size);

    void print() const;
    void println() const;

    MyString& assign(const MyString& str);
    MyString& assign(const char* str);

    char at(int i) const;

    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);

    MyString& erace(int loc, int num);

    int find(int find_from, const MyString &str) const;
    int find(int find_from, const char* str) const;
    int find(int find_from, char c) const;

    int compare(const MyString& str) const;
};

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}
MyString::MyString(const char *str) {
    // 길이 구함
    string_length = strlen(str);
    // 메모리 크기를 string 길이로
    memory_capacity = string_length;
    // 할당
    string_content = new char[string_length];

    // 대입
    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const {
    for (int i = 0; i != string_length; i ++) {
        std::cout << string_content[i];
    }
}

void MyString::println() const {
    for (int i = 0; i != string_length; i ++) {
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}
// 재할당
// str.assign("abc");
// str 자리에 abc가 들어감 (원래 있던 거 삭제)
MyString& MyString::assign(const MyString& str) {

    if (str.string_length > memory_capacity) {
        delete[] string_content;

        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    string_length = str.string_length;

    return *this;
}

MyString& MyString::assign(const char *str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        delete[] string_content;

        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    }

    string_length = str_length;

    return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++) {
            string_content[i] = prev_string_content[i];
        }
        delete[] prev_string_content;
    }
    // 만일 예약하려는 size가 현재 capacity보다 작다면
    // 아무것도 안해도 됌
    // 사이즈 초과시 패스
}

char MyString::at(int i) const {
    if (i >= string_length || i < 0) {
        return 0;
    }
    else {
        return string_content[i];
    }
}
MyString& MyString::insert(int loc, const MyString& str) {
    // 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
    // abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.

    // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
    if (loc < 0 || loc > string_length) return *this;

    if (string_length + str.string_length > memory_capacity) {
        // 새롭게 동적 할당을 해야한다
        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;

        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];

        int i;
        for (i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }
        for (int j = 0; j != str.string_length; j++) {
            string_content[i + j] = str.string_content[j];
        }
        for (; i < string_length; i++) {
            string_content[str.string_length + i] = prev_string_content[i];
        }

        delete[] prev_string_content;

        string_length = string_length + str.string_length;
        return *this;
    }
    // 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
    // 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.
    for (int i = string_length - 1; i >= loc; i--) {
        string_content[i + str.string_length] = string_content[i];
    }
    for (int i = 0; i < str.string_length; i++) {
        string_content[i + loc] = str.string_content[i];
    }
    string_length = string_length + str.string_length;
    return *this;
}
MyString& MyString::insert(int loc, const char *str) {
    MyString temp(str);
    return insert(loc, temp);
}

MyString& MyString::erace(int loc, int num) {
    // loc의 앞부터 시작해서 num 문자를 지운다.
    if (num < 0 || loc < 0 || loc > string_length) return *this;

    // 지운다는 것은 뒤의 문자를 ㅎ나칸 끌고 오는 것

    for (int i = loc + num; i < string_length; ++i) {
        string_content[i - num] = string_content[i];
    }

    string_length -= num;
    return *this;
}
int MyString::find(int find_from, const MyString &str) const {
    int i, j;
    if (str.string_length == 0) return -1;
    for (i = find_from; i <= string_length - str.string_length; i++) {
        for (int j = 0; j < str.string_length; ++j) {
            if (string_content[i + j] != str.string_content[j]) break;
        }
        if (j == str.string_length) return i;
    }
    return -1;
}
int MyString::find(int find_from, const char *str) const {
    MyString temp(str);
    return find(find_from, temp);
}
int MyString::find(int find_from, char c) const {
    MyString temp(c);
    return find(find_from, temp);
}
int MyString::compare(const MyString &str) const {
    for (int i = 0; i < std::min(string_length, str.string_length); i++) {
        if (string_content[i] > str.string_content[i])
            return 1;
        else if (string_content[i] < str.string_content[i])
            return -1;
    }

    if (string_length == str.string_length) return 0;

    else if (string_length > str.string_length)
        return 1;
    return -1;
}
int main() {
    MyString str1("abcdef");
    MyString str2("abcde");

    std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
}
