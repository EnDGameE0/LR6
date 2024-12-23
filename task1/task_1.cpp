#include <iostream>
#include <limits.h>

void findSmallestGroup(const char *str, char *result) {
    int n = 0;
    // Находим длину строки
    while (str[n] != '\0') {
        n++;
    }

    int start = -1, minStart = -1, minLength = 81;

    for (int i = 0; i < n; i++) {
        if (str[i] == '0' || str[i] == '1') {
            if (start == -1) {
                start = i;
            }
        } else {
            if (start != -1) {
                int length = i - start;
                if (length < minLength) {
                    minLength = length;
                    minStart = start;
                }
                start = -1;
            }
        }
    }

    // Проверяем последнюю группу, если строка заканчивается на группу 0 и 1
    if (start != -1) {
        int length = n - start;
        if (length < minLength) {
            minLength = length;
            minStart = start;
        }
    }


    // Копируем наименьшую группу в результат
    for (int i = 0; i < minLength; i++) {
        result[i] = str[minStart + i];
    }
    result[minLength] = '\0'; // Добавляем завершающий символ
}

int main() {
    char* str =new char[81]; // Максимальная длина строки 80 символов + 1 для завершающего символа
    char* result =new char[81];

    std::cout << "Введите строку (максимум 80 символов): ";
    bool flag = false;
    for(int i=0;i<80;++i){
        str[i]=getchar();
        if (str[i] == '\n'){
            break;
            flag = false;
        }
    }
    if (flag){
        std::cout << "user invalid\n";
        return -1;
    }

    // Удаляем символ новой строки, если он присутствует
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    findSmallestGroup(str, result);

    std::cout << "Наименьшая группа, состоящая из 0 и 1: " << result << std::endl;
    delete[] str;
    delete[] result;

    return 0;
}