#include <gtest/gtest.h>
#include <cstring>
#include <iostream>
#include <cctype>

// Ваша функция change
void change(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    // Худший случай: каждый символ заменяется на 3 символа (например, 'A' -> "65")
    char* newStr = new char[len * 4 + 1]; // Учитываем ASCII-код и количество повторений
    int newLen = 0;

    for (int i = 0; i < len;) {
        char currentChar = str[i];
        int count = 1;

        // Считаем количество повторений текущего символа
        while (i + 1 < len && str[i + 1] == currentChar) {
            ++i;
            ++count;
        }

        // Если символ повторяется более одного раза, заменяем его на ASCII-код и количество повторений
        if (count > 1) {
            int asciiValue = static_cast<int>(currentChar);
            int digits = 0;
            int temp = asciiValue;

            // Определяем количество цифр в ASCII-коде
            while (temp > 0) {
                temp /= 10;
                digits++;
            }

            // Преобразуем ASCII-код в строку
            for (int j = digits - 1; j >= 0; --j) {
                newStr[newLen + j] = (asciiValue % 10) + '0';
                asciiValue /= 10;
            }
            newLen += digits;

            // Добавляем количество повторений
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
            // Если символ не повторяется, просто копируем его
            newStr[newLen++] = currentChar;
        }

        ++i;
    }

    newStr[newLen] = '\0';

    // Копируем обратно в исходную строку
    strcpy(str, newStr);

    delete[] newStr;
}

// Тесты
TEST(ChangeTest, ReplaceSingleWord) {
    char text[100] = "hello";
    change(text);
    EXPECT_STREQ(text, "he1082o");
}

TEST(ChangeTest, ReplaceMultipleWords) {
    char text[100] = "hiiiiiii";
    change(text);
    EXPECT_STREQ(text, "h1057");
}

TEST(ChangeTest, ReplaceMultipleWords2) {
    char text[100] = "hiiiiiii againnnn";
    change(text);
    EXPECT_STREQ(text, "h1057 agai1104");
}

TEST(ChangeTest, ReplaceMultipleWords3) {
    char text[100] = "hhiiiiiii";
    change(text);
    EXPECT_STREQ(text, "10421057");
}

TEST(ChangeTest, ReplaceMultipleWords4) {
    char text[100] = "     ";
    change(text);
    EXPECT_STREQ(text, "325");
}

TEST(ChangeTest, ReplaceMultipleWords5) {
    const int j=500;
    char text[j] = "qqwweerrttyyuuiioopp[[]]'';;llkkjjhhggffddssaazzxccvvbbnnmm,,..//11223344556677889900";
    change(text);
    EXPECT_STREQ(text, "1132119210121142116212121172105211121122912932392592108210721062104210321022100211529721222x992118298211021092442462472492502512522532542552562572482");
}

TEST(ChangeTest, EmptyString) {
    char text[100] = "";
    change(text);
    EXPECT_STREQ(text, "");
}

TEST(ChangeTest, NewlineString) {
    char text[100] = "\n";
    change(text);
    EXPECT_STREQ(text, "\n");
}

TEST(ChangeTest, NoReplacement) {
    char text[100] = "poOpa";
    change(text);
    EXPECT_STREQ(text, "poOpa");
}

TEST(ChangeTest, NoReplacement2) {
    char text[100] = "privet";
    change(text);
    EXPECT_STREQ(text, "privet");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}