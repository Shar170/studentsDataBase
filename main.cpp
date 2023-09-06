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

/*
 *  Функция для расчёта среднего возраста студентов
 *  @database - База данных содержащая информацию о студентах
 */

void averageAgeStudents(const std::vector<Student>& database) {
    double averageAge = NULL;
    if (database == NULL) {
        break;
    }
    else {
        for (const Student& student : database) {
            averageAge += student.age;
        }
        averageAge = averageAge / database.size();

        std::cout << averageAge << std::endl;
    }
}

// Тест на пустую базу данных студентов
void testEmptyDatabase(const std::vector<Student>& database) {
    std::cout << "Тест на пустую базу данных:\n";
    averageAgeStudents(database);
    // Ожидается, что средний возраст будет равен 0
}

// Тест на одного студента
void testSingleStudent(const std::vector<Student>& database) {
    Student student;
    student.name = "Иван";
    student.age = 20;
    student.major = "Инженерия";
    student.gpa = 3.5;
    database.push_back(student);

    std::cout << "Тест на одного студента:\n";
    averageAgeStudents(database);
    // Ожидается, что средний возраст будет равен 20
}

// Тест на нескольких студентов с разными возрастами
void testMultipleStudents(const std::vector<Student>& database) {
    Student student1, student2, student3;
    student1.name = "Анна";
    student1.age = 21;
    student1.major = "Информатика";
    student1.gpa = 3.7;

    student2.name = "Петр";
    student2.age = 19;
    student2.major = "Физика";
    student2.gpa = 3.2;

    student3.name = "Елена";
    student3.age = 22;
    student3.major = "Химия";
    student3.gpa = 3.9;

    database.push_back(student1);
    database.push_back(student2);
    database.push_back(student3);

    std::cout << "Тест на нескольких студентов с разными возрастами:\n";
    averageAgeStudents(database);
    // Ожидается, что средний возраст будет правильно вычислен
}

// Тест на округление среднего возраста
void testRoundedAverageAge(const std::vector<Student>& database) {
    Student student1, student2, student3;
    student1.name = "Анна";
    student1.age = 21;
    student1.major = "Информатика";
    student1.gpa = 3.7;

    student2.name = "Петр";
    student2.age = 19;
    student2.major = "Физика";
    student2.gpa = 3.2;

    student3.name = "Елена";
    student3.age = 22;
    student3.major = "Химия";
    student3.gpa = 3.9;

    database.push_back(student1);
    database.push_back(student2);
    database.push_back(student3);

    std::cout << "Тест на округление среднего возраста:\n";
    averageAgeStudents(database);
    // Ожидается, что средний возраст будет округлен до ближайшего целого числа
}

int main() {
    setlocale(LC_ALL, "Ru");
    std::vector<Student> database;

    int choice;
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
            averageAgeStudents(database);
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    // Вызываем функции-тесты
    testEmptyDatabase(database);
    testSingleStudent(database);
    testMultipleStudents(database);
    testRoundedAverageAge(database);

    return 0;
}