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
        if (std::cin >> student.age) {
            break; // Ввод корректен, выходим из цикла
        }
        else {
            std::cout << "Ошибка: Введите корректный возраст (целое число).\n";
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
        if (std::cin >> student.gpa) {
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

// Тестовая функция, в которую передается база данных для тестирования
void runTests(std::vector<Student>& database) {
    // Тест 1: Расчет среднего возраста для пустой базы данных
    std::cout << "Запуск теста 1: Расчет среднего возраста для пустой базы данных...\n";
    double averageAge1 = averageAgeStudents(database);
    if (averageAge1 == 0.0) {
        std::cout << "Тест 1 успешно пройден. Результат: " << averageAge1 << "\n\n";
    }
    else {
        std::cout << "Тест 1 не пройден. Ожидалось значение 0.0, но получено: " << averageAge1 << "\n\n";
    }

    // Тест 2: Расчет среднего возраста для нескольких студентов
    std::cout << "Запуск теста 2: Расчет среднего возраста для нескольких студентов...\n";
    Student student1 = { "Иванов", 20, "Математика", 4.5 };
    Student student2 = { "Петров", 22, "Физика", 3.8 };
    Student student3 = { "Сидорова", 21, "Биология", 4.2 };
    database.push_back(student1);
    database.push_back(student2);
    database.push_back(student3);
    double averageAge2 = averageAgeStudents(database);
    double expectedAverage2 = (20.0 + 22.0 + 21.0) / 3;
    if (averageAge2 == expectedAverage2) {
        std::cout << "Тест 2 успешно пройден. Результат: " << averageAge2 << "\n\n";
    }
    else {
        std::cout << "Тест 2 не пройден. Ожидалось значение " << expectedAverage2 << ", но получено: " << averageAge2 << "\n\n";
    }

    // Тест 3: Добавление студента
    std::cout << "Запуск теста 3: Добавление студента...\n";
    size_t initialSize = database.size();
    addStudent(database);
    if (database.size() == initialSize + 1) {
        std::cout << "Тест 3 успешно пройден. Размер базы данных увеличен.\n\n";
    }
    else {
        std::cout << "Тест 3 не пройден. Ожидалось увеличение размера базы данных.\n\n";
    }

    // Тест 4: Вывод списка студентов
    std::cout << "Запуск теста 4: Вывод списка студентов...\n";
    // Здесь тест осуществляется путем визуальной проверки вывода, так что нет assert
    displayStudents(database);

    // Тест 5: Попытка расчета среднего возраста для пустой базы данных
    std::cout << "Запуск теста 5: Попытка расчета среднего возраста для пустой базы данных...\n\n";
    database.clear(); // Очистим базу данных
    double averageAge3 = averageAgeStudents(database);
    if (averageAge3 == 0.0) {
        std::cout << "Тест 5 успешно пройден. Результат: " << averageAge3 << "\n\n";
    }
    else {
        std::cout << "Тест 5 не пройден. Ожидалось значение 0.0, но получено: " << averageAge3 << "\n\n";
    }

    // Тест 6: Попытка добавления студента с отрицательным возрастом
    std::cout << "Запуск теста 6: Попытка добавления студента с отрицательным возрастом...\n";
    Student student4 = { "Иванова", -1, "История", 3.0 };
    initialSize = database.size();
    database.push_back(student4);
    if (database.size() == initialSize) {
        std::cout << "Тест 6 успешно пройден. Студент с отрицательным возрастом не добавлен.\n\n";
    }
    else {
        std::cout << "Тест 6 не пройден. Ожидалось, что студент с отрицательным возрастом не будет добавлен.\n\n";
    }
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
        std::cout << "4. Запустить ряд тестов для базы данных\n";
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
        case 4:
            // Вызываем тестовую функцию и передаем базу данных для тестирования
            runTests(database);
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