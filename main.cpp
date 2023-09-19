#include <iostream>
#include <vector>
#include <string>
#include <cassert>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;

    // Запрашиваем имя студента
    std::cout << "Введите имя студента: ";
    std::cin.ignore(); // Очищаем буфер ввода
    std::getline(std::cin, student.name);

    // Запрашиваем возраст студента с обработкой ошибок
    while (true) {
        std::cout << "Введите возраст студента: ";
        if (std::cin >> student.age && student.age > 0) {
            break; // Ввод корректен, выходим из цикла
        }
        else {
            std::cout << "Ошибка: Введите корректный возраст (целое число > 0).\n";
            std::cin.clear(); // Сбрасываем флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
        }
    }

    // Запрашиваем специальность студента
    std::cout << "Введите специальность студента: ";
    std::cin.ignore(); // Очищаем буфер ввода
    std::getline(std::cin, student.major);

    // Запрашиваем средний балл студента с обработкой ошибок
    while (true) {
        std::cout << "Введите средний балл студента: ";
        if (std::cin >> student.gpa && student.gpa > 0) {
            break; // Ввод корректен, выходим из цикла
        }
        else {
            std::cout << "Ошибка: Введите корректный средний балл (число).\n";
            std::cin.clear(); // Сбрасываем флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
        }
    }

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

// Функция для расчёта среднего возраста студентов
double averageAgeStudents(const std::vector<Student>& database) {
    double averageAge = 0.0;
    if (!database.empty()) {
        for (const Student& student : database) {
            averageAge += student.age;
        }
        averageAge /= database.size();
    }
    return averageAge;
}

int main() {
    setlocale(LC_ALL, "Ru");
    std::vector<Student> database;

    int choice;
    double averageAge; // Переменная объявлена здесь, вне switch

    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Вывести средний возраст студентов\n";
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
            averageAge = averageAgeStudents(database); // Используем переменную внутри switch
            if (averageAge == 0.0) {
                std::cout << "База данных пуста.\n";
            }
            else {
                std::cout << "Средний возраст студентов: " << averageAge << " лет\n";
            }
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