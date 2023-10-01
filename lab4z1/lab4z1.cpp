/*
Лабораторная работа №4.
Потоки ввода-вывода.
Задание 1.
9. Перегрузите операцию << для класса, который будет просить ввести
любую строку, а затем должен опять вывести её на экран, но без больших букв и
цифр.
*/

#include <iostream>

class CustomString {
private:
    char* data;

public:
    CustomString() : data(nullptr) {}

    CustomString(const char* input) {
        size_t length = 0;
        while (input[length] != '\0') {
            ++length;
        }
        data = new char[length + 1];
        for (size_t i = 0; i < length; ++i) {
            char c = input[i];
            if (isLowercaseLetter(c)) {
                data[i] = c;
            }
            else {
                data[i] = ' ';
            }
        }
        data[length] = '\0';
    }

    ~CustomString() {
        delete[] data;
    }

    friend std::ostream& operator<<(std::ostream& os, const CustomString& customStr) {
        os << customStr.data;
        return os;
    }

    void inputString() {
        char input[100]; 
        std::cout << "Введите строку: ";
        std::cin.getline(input, sizeof(input));
        size_t length = 0;
        while (input[length] != '\0') {
            ++length;
        }
        data = new char[length + 1];
        for (size_t i = 0; i < length; ++i) {
            char c = input[i];
            if (isLowercaseLetter(c)) {
                data[i] = c;
            }
            else {
                data[i] = ' ';
            }
        }
        data[length] = '\0';
    }

private:
    bool isLowercaseLetter(char c) const {
        return (c >= 'a' && c <= 'z');
    }
};

int main() {
    setlocale(0, "Ru");

    CustomString customStr;
    customStr.inputString();

    std::cout << "Введённая строка без больших букв и цифр: " << customStr << std::endl << std::endl;

    system("pause");
    return 0;
}