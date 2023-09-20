#include <iostream>
#include <vector>
#include <string>
#include "gtest/gtest.h"

using namespace std;

vector<string> groups = { "КС-40", "КС-43", "КС-46" };
int group_number = 0;

struct Student {
    string name;
    int age;
    string major;
    double gpa;
    string group;
};

bool get_group_number(int &group_number) {
    cin >> group_number;
    if (group_number < 1 || group_number > groups.size()) {
        cout << "Введите правильный номер: ";
        return false;
    }
    return true;
}

// Функция для добавления студента в базу данных
void addStudent(vector<Student>& database) {
    Student student;
    cout << "Введите имя студента: ";
    cin >> student.name;
    cout << "Введите возраст студента: ";
    cin >> student.age;
    cout << "Введите специальность студента: ";
    cin >> student.major;
    cout << "Введите средний балл студента: ";
    cin >> student.gpa;
    cout << "Выберите группу студента: " << "\n";
    for (int i = 1; i <= groups.size(); i++)
        cout << i << ". " << groups[i - 1] << "\n";
    while (!get_group_number(group_number))
        continue;
    student.group = groups[group_number - 1];
    database.push_back(student);
    cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const vector<Student>& database) {
    cout << "Список студентов:\n";
    for (const Student& student : database) {
        cout << "Имя: " << student.name << "\n";
        cout << "Возраст: " << student.age << "\n";
        cout << "Специальность: " << student.major << "\n";
        cout << "Средний балл: " << student.gpa << "\n";
        cout << "Группа: " << student.group << "\n\n";
    }
}

int main(int argc, char** argv) {
    vector<Student> database;

    int choice;
    do {
        cout << "Меню:\n";
        cout << "1. Добавить студента\n";
        cout << "2. Вывести список студентов\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(database);
            break;
        case 2:
            displayStudents(database);
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}

TEST(GroupTesting, HandlesBelowNormalInput) {
    group_number = 0;
    EXPECT_EQ(get_group_number(group_number), 0);
}

TEST(GroupTesting, HandlesNormalInput) {
    group_number = 1;
    EXPECT_EQ(get_group_number(group_number), 1);
    group_number = 2;
    EXPECT_EQ(get_group_number(group_number), 1);
    group_number = 3;
    EXPECT_EQ(get_group_number(group_number), 1);
}

TEST(GroupTesting, HandlesAboveNormalInput) {
    group_number = 4;
    EXPECT_EQ(get_group_number(group_number), 0);
}