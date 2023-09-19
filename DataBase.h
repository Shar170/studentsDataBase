#pragma once
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