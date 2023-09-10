#include <iostream>
#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "pch.h"

using namespace std;

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

int countStudents(const std::vector<Student>& database) {

    return database.size();
}

TEST(countStudentsFromDataBase, EmptyDB)
{
    vector<Student> database;

    int count = countStudents(database);

    EXPECT_EQ(count, 0);
}

TEST(countStudentsFromDataBase, OneStudentInDB)
{
    vector<Student> database;

    database.push_back({ "bob", 21, "", 7.09 });

    int count = countStudents(database);

    EXPECT_EQ(count, 1);
}

TEST(countStudentsFromDataBase, TenStudentsInDB)
{
    vector<Student> database;

    for (int i = 0; i < 10; i++) {
        database.push_back({ "", 10+i, "", 2.32+i });
    }

    int count = countStudents(database);

    EXPECT_EQ(count, 10);
}

TEST(countStudentsFromDataBase, HundredStudentsInDB)
{
    vector<Student> database;

    for (int i = 0; i < 100; i++) {
        database.push_back({ "", 10 + i, "", 2.32 + i });
    }

    int count = countStudents(database);

    EXPECT_EQ(count, 100);
}

TEST(countStudentsFromDataBase, ThousandStudentsInDB)
{
    vector<Student> database;

    for (int i = 0; i < 1000; i++) {
        database.push_back({ "", 10 + i, "", 2.32 + i });
    }

    int count = countStudents(database);

    EXPECT_EQ(count, 1000);
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru");

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}