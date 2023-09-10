#include <iostream>
#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "pch.h"

using namespace std;

struct Student {
    string name;
    int age;
    string major;
    double gpa;
};

void deleteStudent(vector<Student>& database, string name)
{
    if (database.empty()) { cout << "The database is empty, the search for students is impossible!" << endl; return; };

    int count = 0;

    for (int i = 0; i < database.size(); i++)
    {
        if (database[i].name == name)
        {
            database.erase(database.begin() + i);
            count++;
            i--;
        }
    }

    if (count == 0) 
    {
        cout << "No matches found!" << endl;
    }
}

TEST(DeleteStudentsFromDataBase, EmptyDB)
{
    vector<Student> database;

    deleteStudent(database, "bob");

    EXPECT_EQ(database.size(), 0);
}

TEST(DeleteStudentsFromDataBase, DeleteStudentWithCorrectName)
{
    vector<Student> database;

    database.push_back({ "bob", 21, "", 7.09 });
    database.push_back({ "alice", 24, "", 5.70 });
    database.push_back({ "max", 43, "", 21 });

    deleteStudent(database, "bob");

    EXPECT_EQ(database.size(), 2);
}

TEST(DeleteStudentsFromDataBase, DeleteStudentWithNameIsntInDB)
{
    vector<Student> database;

    database.push_back({ "jack", 21, "", 7.09 });
    database.push_back({ "jane", 24, "", 5.70 });
    database.push_back({ "logan", 43, "", 21 });

    deleteStudent(database, "mickle");

    EXPECT_EQ(database.size(), 3);
}

TEST(DeleteStudentsFromDataBase, DeleteStudentWithEmptyName)
{
    vector<Student> database;

    database.push_back({ "bob", 21, "", 7.09 });
    database.push_back({ "alice", 24, "", 5.70 });

    deleteStudent(database, "");

    EXPECT_EQ(database.size(), 2);
}

TEST(DeleteStudentsFromDataBase, DeleteSeveralStudentsWithTheSameNames)
{
    vector<Student> database;

    database.push_back({ "aaron", 21, "", 7.09 });
    database.push_back({ "aaron", 32, "", 9.87 });
    database.push_back({ "claire", 24, "", 5.70 });

    deleteStudent(database, "aaron");

    EXPECT_EQ(database.size(), 1);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}