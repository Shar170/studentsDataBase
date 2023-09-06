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
                // После добавления студента, проверяем, есть ли он в базе данных
                if (isStudentInDatabase(database, database.back().name)) {
                    std::cout << "Студент уже существует в базе данных.\n";
                } else {
                    std::cout << "Студент добавлен в базу данных.\n";
                }
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