#include <gtest/gtest.h>
#include <cstring>

void findSmallestGroup(const char *str, char *result) {
    int n = std::strlen(str);
    int start = -1, minStart = -1, minLength = n + 1;

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

    if (minStart != -1) {
        for (int i = 0; i < minLength; i++) {
            result[i] = str[minStart + i];
        }
        result[minLength] = '\0';
    } else {
        result[0] = '\0'; // No valid group found
    }
}

TEST(FindSmallestGroupTest1, BasicTest) {
    char o[] = "010 10010";
    char res[10];
    findSmallestGroup(o, res);
    EXPECT_STREQ(res, "010");
}

TEST(FindSmallestGroupTest11, SingleGroup) {
    char o[] = "0    10010";
    char res[10];
    findSmallestGroup(o, res);
    EXPECT_STREQ(res, "0");
}

TEST(FindSmallestGroupTest111, NoGroup) {
    char o[] = "      ";
    char res[10];
    findSmallestGroup(o, res);
    EXPECT_STREQ(res, "");
}

TEST(FindSmallestGroupTest1111, EmptyString) {
    char o[] = "";
    char res[10];
    findSmallestGroup(o, res);
    EXPECT_STREQ(res, "");
}

TEST(FindSmallestGroupTest11111, MixedCharacters) {
    char o[] = "a01b10c01";
    char res[10];
    findSmallestGroup(o, res);
    EXPECT_STREQ(res, "01");
}
TEST(FindSmallestGroupTest111111, Group1) {
    char o[] = "     1 ";
    char res[10];
    findSmallestGroup(o, res);
    EXPECT_STREQ(res, "1");
}
TEST(FindSmallestGroupTest221, NoGroup1) {
    char o[] = "AB0BA      ";
    char res[20];
    findSmallestGroup(o, res);
    EXPECT_STREQ(res, "0");
}
TEST(FindSmallestGroupTest44, NoGroup2) {
    char o[] = "0101010101010101010101010101010101010101010110101 1";
    char res[40];
    findSmallestGroup(o, res);
    EXPECT_STREQ(res, "1");
}
TEST(FindSmallestGroupTest54, NoGroup22) {
    char o[] = "  ";
    char res[1];
    findSmallestGroup(o, res);
    EXPECT_STREQ(res, "");
}
TEST(FindSmallestGroupTest55, NoGroup222) {
    char o[] = "8 ";
    char res[10];
    findSmallestGroup(o, res);
    EXPECT_STREQ(res, "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}