#include <iostream>
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
