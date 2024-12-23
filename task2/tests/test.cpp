#include <gtest/gtest.h>
#include <cstring>
#include <iostream>
#include <cctype>

// Ваша функция change
void change(char* a, const char* b, int d){
    int lenA = strlen(a);
    int lenB = strlen(b);
    int newLenA = lenA;

    for (int i = 0; i <= lenA - d; ++i) {
        bool match = true;
        for (int j = 0; j < d; ++j) {
            if (!isalpha(a[i + j])) {
                match = false;
                break;
            }
        }
        if (match && (i == 0 || !isalpha(a[i - 1])) && (i + d == lenA || !isalpha(a[i + d]))) {
            int diff = lenB - d;
            if (diff > 0) {
                for (int k = lenA; k >= i + d; --k) {
                    a[k + diff] = a[k];
                }
            } else if (diff < 0) {
                for (int k = i + d; k <= lenA; ++k) {
                    a[k + diff] = a[k];
                }
            }
            for (int j = 0; j < lenB; ++j) {
                a[i + j] = b[j];
            }
            i += lenB - 1; 
            newLenA += diff; 
            lenA = newLenA;
        }
    }
    a[newLenA] = '\0'; 
}

// Тесты
TEST(ChangeTest, ReplaceSingleWord) {
    char text[] = "hello world";
    const char* replacement = "test";
    int length = 5;
    change(text, replacement, length);
    EXPECT_STREQ(text, "test test");
}

TEST(ChangeTest, ReplaceMultipleWords) {
    char text[] = "hello word hello";
    const char* replacement = "test";
    int length = 4;
    change(text, replacement, length);
    EXPECT_STREQ(text, "hello test hello");
}

TEST(ChangeTest, ReplaceWordAtStart) {
    char text[] = "hello world";
    const char* replacement = "testing";
    int length = 4;
    change(text, replacement, length);
    EXPECT_STREQ(text, "hello world");
}

TEST(ChangeTest, ReplaceWordAtEnd) {
    char text[] = "     ";
    const char* replacement = "test";
    int length = 5;
    change(text, replacement, length);
    EXPECT_STREQ(text, "     ");
}

TEST(ChangeTest, ReplaceWordInMiddle) {
    char text[] = "one hello two";
    const char* replacement = "test";
    int length = 5;
    change(text, replacement, length);
    EXPECT_STREQ(text, "one test two");
}

TEST(ChangeTest, NoReplacement) {
    char text[] = "hello world";
    const char* replacement = "test";
    int length = 6;
    change(text, replacement, length);
    EXPECT_STREQ(text, "hello world");
}

TEST(ChangeTest, ReplaceWithLongerWord) {
    char text[50] = "hello world";
    const char* replacement = "replacement";
    int length = 5;
    change(text, replacement, length);
    EXPECT_STREQ(text, "replacement replacement");
}

TEST(ChangeTest, ReplaceWithShorterWord) {
    char text[] = "hello world";
    const char* replacement = "hi";
    int length = 5;
    change(text, replacement, length);
    EXPECT_STREQ(text, "hi hi");
}

TEST(ChangeTest, ReplaceWithEmptyWord) {
    char text[] = "hello world";
    const char* replacement = "";
    int length = 5;
    change(text, replacement, length);
    EXPECT_STREQ(text, " ");
}

TEST(ChangeTest, ReplaceWithSameLengthWord) {
    char text[] = "hello world";
    const char* replacement = "hi";
    int length = 2;
    change(text, replacement, length);
    EXPECT_STREQ(text, "hello world");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}