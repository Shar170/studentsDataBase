#include <iostream>
#include <vector>
#include <string>

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

int main() {
    std::vector<Student> database;

    for (int i = 1; i <= 5; i++)
    {
        bool result;
        switch (i) {
            case 1:
                result = testFunction1(database);
            case 2:
                result = testFunction2(database);
            case 3:
                result = testFunction3(database);
            case 4:
                result = testFunction4(database);
            case 5:
                result = testFunction5(database);
        }

        if (result == false) {
            std::cerr << "TEST ERORR\n";
            exit(1); 
        }
    }
    return 0;
}
