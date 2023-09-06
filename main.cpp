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

// Функция редактирования студентов из базы данных
void editStudents(std::vector<Student>& database) {
    Student student;
    std::cout << "Список студентов:\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }

    std::string name_to_edit;
    std::string temp_name;
    int temp_age;
    std::string temp_major;
    double temp_gpa;

    std::cout << "Введите имя студента для редактирования: ";
    std::cin >> name_to_edit;
    for (Student& student : database) {
        if (student.name == name_to_edit) {
            std::cout << "Введите новое имя студента: ";
            std::cin >> temp_name;
            if (temp_name != "0") {
                student.name = temp_name;
            }
            std::cout << "Введите новый возраст студента: ";
            std::cin >> temp_age;
            if (temp_age != 0) {
                student.age = temp_age;
            }
            std::cout << "Введите новую специальность студента: ";
            std::cin >> temp_major;
            if (temp_major != "0") {
                student.major = temp_major;
            }
            std::cout << "Введите новый средний балл студента: ";
            std::cin >> temp_gpa;
            if (temp_gpa != 0) {
                student.gpa = temp_gpa;
            }

            std::cout << "Студент добавлен в базу данных.\n";
        }

    }
}

int main() {
    std::setlocale(LC_ALL, "Russian");

    std::vector<Student> database;

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Редактирование студентов\n";
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
            editStudents(database);
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
