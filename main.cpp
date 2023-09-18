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

// Функция для поиска студентов с наивысшим и наинизшим средним баллом
void findHighestLowestGPA(const std::vector<Student>& database) {
    bool temp = true;
    while (temp) {
        if (database.empty()) {
            std::cout << "База данных студентов пуста.\n";
            temp = false;
        }
        else {
            std::string choice2;
            std::cout << "a. Вывести студента с наивысшим средним баллом\n";
            std::cout << "b. Вывести студента с наименьшим средним баллом\n";
            std::cin >> choice2;
            if (choice2 == "a") {
                // Инициализируем наивысший балл значением первого студента в базе данных.
                Student highestGPAStudent = database[0];

                for (const Student& student : database) {
                    if (student.gpa > highestGPAStudent.gpa) {
                        highestGPAStudent = student;
                    }
                }

                std::cout << highestGPAStudent.name;
                std::cout << "\n";
                temp = false;
            }
            else if (choice2 == "b") {
                // Инициализируем наинизший балл значением первого студента в базе данных.
                Student lowestGPAStudent = database[0];

                for (const Student& student : database) {
                    if (student.gpa < lowestGPAStudent.gpa) {
                        lowestGPAStudent = student;
                    }
                }

                std::cout << lowestGPAStudent.name;
                std::cout << "\n";
                temp = false;
            }
            else {
                std::cout << "Введен некорректный символ\n";
                temp = false;
            }
        }
    }
}

void test1(std::vector<Student>& database) {
    std::cout << "Тест 1. Проверка на пустую базу данных(эта проверка осуществляется по умолчанию в функции).\n";
    if (database.empty()) {
        findHighestLowestGPA(database);
    }
    std::cout << "\n";
    std::cout << "Добавьте ОДНОГО студента в базу данных для демонстрации в дальнейшем работы Теста 3.\n\n";
    addStudent(database);
    std::cout << "Тест 2. Проверка на некорректный символ(введите любой символ, кроме символов <a> и <b>).\n";
    findHighestLowestGPA(database);
    std::cout << "Тест 3. Проверка на работу функции с одним студентом.\n";
    findHighestLowestGPA(database);
    findHighestLowestGPA(database);
    std::cout << "Добавьте ВТОРОГО студента с отличающимся значением среднего балла для демонстрации работы Теста 4 и 5.\n\n";
    addStudent(database);
    std::cout << "\n";
    std::cout << "Тест 4. Проверка, правильно ли функция выводит студента с наивысшим баллом(введите символ <a> на латинице).\n";
    findHighestLowestGPA(database);
    std::cout << "Тест 5. Проверка, правильно ли функция выводит студента с наинизшим баллом(введите символ <b> на латинице).\n";
    findHighestLowestGPA(database);
}

void mainFunction() {
    std::vector<Student> database;
    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Вывести студента с наивысшим и наинизшим средним баллом\n";
        std::cout << "4. Провести тесты с функцией\n";
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
            findHighestLowestGPA(database);
            break;
        case 4:
            test1(database);
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);
}



int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Student> database;
    mainFunction();


    return 0;
}