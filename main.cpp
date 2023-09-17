﻿#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};


// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

bool isStudentInDatabase(const std::vector<Student>& database, const std::string& studentName) {
    for (const Student& student : database) {
        if (student.name == studentName) {
            return true; // Студент найден
        }
    }
    return false; // Студент не найден
}


// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
    std::cout << "Список студентов:\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

bool compareByName(const Student& a, const Student& b) {
    return a.name < b.name;
}

bool compareByGpa(const Student& a, const Student& b) {
    return a.gpa > b.gpa;
}

class Tests{
    void Test1(){
        // Arrange
        std::vector<Student> database;
        Student student;

        student.name = "Katya";
        student.age = 20;
        student.major = "ICT";
        student.gpa = 4.9;
        database.push_back(student);

        student.name = "Dasha";
        student.age = 21;
        student.major = "ICT2";
        student.gpa = 4.7;
        database.push_back(student);

        student.name = "Max";
        student.age = 21;
        student.major = "ICT";
        student.gpa = 5.0;
        database.push_back(student);

        // Act
        std::sort(database.begin(),database.end(), compareByName);

        // Assert
        for (int i = 0; i < database.size() - 1; i++){
            if (database[i].name > database[i + 1].name){
                std::cout << "Invalid Test #1" << '\n';
                return;
            }
        }
        std::cout << "Valid Test #1" <<'\n';
    }

    void Test2(){
        // Arrange
        std::vector<Student> database;
        Student student;

        student.name = "Katya";
        student.age = 20;
        student.major = "ICT";
        student.gpa = 4.9;
        database.push_back(student);

        student.name = "Dasha";
        student.age = 21;
        student.major = "ICT2";
        student.gpa = 4.7;
        database.push_back(student);

        student.name = "Max";
        student.age = 21;
        student.major = "ICT";
        student.gpa = 5.0;
        database.push_back(student);

        // Act
        std::sort(database.begin(),database.end(), compareByGpa);

        // Assert
        for (int i = 0; i < database.size() - 1; i++){
            if (database[i].gpa < database[i + 1].gpa){
                std::cout << "Invalid Test #2" << '\n';
                return;
            }
        }
        std::cout << "Valid Test #2" << '\n';
    }

    void Test3(){
        // Arrange
        std::vector<Student> database;
        Student student;

        student.name = "Katya";
        student.age = 20;
        student.major = "ICT";
        student.gpa = 4.9;
        database.push_back(student);

        student.name = "Dasha";
        student.age = 21;
        student.major = "ICT2";
        student.gpa = 4.7;
        database.push_back(student);

        student.name = "Max";
        student.age = 21;
        student.major = "ICT";
        student.gpa = 5.0;
        database.push_back(student);

        // Act
        bool result = isStudentInDatabase(database, "Kirill");

        // Assert
        if (result){
            std::cout << "Invalid Test #3" << '\n';
        }
        else{
            std::cout << "Valid Test #3" << '\n';
        }
    }

    void Test4(){
        // Arrange
        std::vector<Student> database;
        Student student;

        student.name = "Katya";
        student.age = 20;
        student.major = "ICT";
        student.gpa = 4.9;
        database.push_back(student);

        student.name = "Dasha";
        student.age = 21;
        student.major = "ICT2";
        student.gpa = 4.7;
        database.push_back(student);

        student.name = "Max";
        student.age = 21;
        student.major = "ICT";
        student.gpa = 5.0;
        database.push_back(student);

        // Act
        bool result = isStudentInDatabase(database, "Dasha");

        // Assert
        if (!result){
            std::cout << "Invalid Test #4" << '\n';
        }
        else{
            std::cout << "Valid Test #4" << '\n';
        }
    }

    void Test5(){
        // Arrange
        Student student;
        student.name = "Katya";
        student.age = 20;
        student.major = "ICT";
        student.gpa = 4.9;

        Student student_2;
        student_2.name = "Dasha";
        student_2.age = 21;
        student_2.major = "ICT2";
        student_2.gpa = 4.7;

        // Act
        bool result = compareByName(student,student_2);

        //Assert
        if (result){
            std::cout << "Invalid Test #5" << '\n';
        }
        else{
            std::cout << "Valid Test #5" << '\n';
        }

    }
public:
    void AllTest(){
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
    }
};






int main() {
    //std::setlocale(LC_ALL, "Russian");
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Сортировка по имени\n";
        std::cout << "4. Сортировка по  среднему баллу\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(database);
                break;
            case 2:
                displayStudents(database);
                break;
            case 3:
                std::sort(database.begin(), database.end(), compareByName);
                std::cout << "Студенты отсортированы по имени.\n";
                break;
            case 4:
                std::sort(database.begin(), database.end(), compareByGpa);
                std::cout << "Студенты отсортированы по среднему баллу.\n";
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}