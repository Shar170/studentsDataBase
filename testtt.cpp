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
    Student firstStudent;
    
    std::cout << "Тест 1. Проверка на пустую базу данных(эта проверка осуществляется по умолчанию в функции).\n";
    if (database.empty()) {
        findHighestLowestGPA(database);
    }
    std::cout << "\n";
    std::cout << "Добавлен ОДИН студент Amir в базу данных для демонстрации в дальнейшем работы Теста 3.\n\n";
    firstStudent.name = "Amir";
    firstStudent.age = 21;
    firstStudent.major = "No info";
    firstStudent.gpa = 85;
    database.push_back(firstStudent);
    std::cout << "Тест 2. Проверка на некорректный символ(введите любой символ, кроме символов <a> и <b>).\n";
    findHighestLowestGPA(database);
    std::cout << "Тест 3. Проверка на работу функции с одним студентом.\n";
    findHighestLowestGPA(database);
    findHighestLowestGPA(database);
    std::cout << "Добавлен ВТОРОЙ студент Rafael с отличающимся значением среднего балла для демонстрации работы Теста 4 и 5.\n\n";
    Student secondStudent;
    secondStudent.name = "Rafael";
    secondStudent.age = 20;
    secondStudent.major = "No info";
    secondStudent.gpa = 80;
    database.push_back(secondStudent);
    std::cout << "\n";
    std::cout << "Тест 4. Проверка, правильно ли функция выводит студента с наивысшим баллом(введите символ <a> на латинице).\n";
    findHighestLowestGPA(database);
    std::cout << "Тест 5. Проверка, правильно ли функция выводит студента с наинизшим баллом(введите символ <b> на латинице).\n";
    findHighestLowestGPA(database);
}





int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Student> database;
    test1(database);
    

    return 0;
}