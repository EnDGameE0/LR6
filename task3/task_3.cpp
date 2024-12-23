#include <iostream>
#include <cstring>
#include <cctype>

void processString(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    // Худший случай: каждый символ заменяется на 3 символа (например, 'A' -> "65")
    char* newStr = new char[len * 4 + 1]; 
    int newLen = 0;

    for (int i = 0; i < len;) {
        char currentChar = str[i];
        int count = 1;

        while (i + 1 < len && str[i + 1] == currentChar) {
            ++i;
            ++count;
        }

        if (count > 1) {
            int asciiValue = static_cast<int>(currentChar);
            int digits = 0;
            int temp = asciiValue;

            while (temp > 0) {
                temp /= 10;
                digits++;
            }

            for (int j = digits - 1; j >= 0; --j) {
                newStr[newLen + j] = (asciiValue % 10) + '0';
                asciiValue /= 10;
            }
            newLen += digits;

            temp = count;
            digits = 0;
            while (temp > 0) {
                temp /= 10;
                digits++;
            }
            for (int j = digits - 1; j >= 0; --j) {
                newStr[newLen + j] = (count % 10) + '0';
                count /= 10;
            }
            newLen += digits;
        } else {
            newStr[newLen++] = currentChar;
        }

        ++i;
    }

    newStr[newLen] = '\0';

    strcpy(str, newStr);

    delete[] newStr;
}

int main() {
    const int ML = 100;
    char str[ML];

    std::cout << "Подготовил Белоусов Ашраф.Введите строку (не более 100 символов на латыне).Программа выдаст его ASCII номер в местах где символ повторяется и сколько раз он повторяется. Введите пустую строку для завершения ввода:\n";
    std::cin.getline(str, ML);

    processString(str);
    std::cout << "Обработанная строка: " << str << std::endl;

    return 0;
}