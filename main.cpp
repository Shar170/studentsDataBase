#include <iostream>
#include <vector>
#include <string>
#include <gtest/gtest.h>

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
//template<typename Type>
// Функции изменения данных студента
//void editStudentData(Type &parametr, Type data) {
//    parametr = data;
//}

void editStudentName(std::string& name, std::string new_name) {
    if (new_name != "") {
        name = new_name;
    }
}

void editStudentAge(int& age, std::string new_age) {
    if (new_age != "") {
        age = std::stoi(new_age);
    }
}

void editStudentMajor(std::string& major, std::string new_major) {
    if (new_major != "") {
        major = new_major;
    }
}

void editStudentGpa(double& gpa, std::string new_gpa) {
    if (new_gpa != "") {
        gpa = std::stod(new_gpa);
    }
}


// Функция редактирования студентов из базы данных
void editStudents(std::vector<Student>& database) {
    Student student;
    displayStudents(database);

    std::string name_to_edit;
    std::string temp_name;
    int temp_age;
    std::string temp_major;
    double temp_gpa;

    std::cout << "Введите имя студента для редактирования: ";
    std::cin >> name_to_edit;
    bool search_student = false;

    for (Student& student : database) {
        if (student.name == name_to_edit) {
            int change = 0;

            std::string student_info = student.name + ";" + std::to_string(student.age) + ";" + student.major + ";" + std::to_string(student.gpa);

            std::cout << "Введите новое имя студента(" + student_info + ") : ";
            /*std::cin >> temp_name;
            if (temp_name != "0") {
                student.name = temp_name;
                change++;
            }*/
            std::cin.ignore();
            std::string name;
            std::getline(std::cin, name);

            std::cout << "Введите новый возраст студента: ";
            /*std::cin >> temp_age;
            if (temp_age != 0) {
                student.age = temp_age;
                change++;
            }*/
            std::string age;
            std::getline(std::cin, age);

            std::cout << "Введите новую специальность студента: ";
            /*std::cin >> temp_major;
            if (temp_major != "0") {
                student.major = temp_major;
                change++;
            }*/
            std::string major;
            std::getline(std::cin, major);

            std::cout << "Введите новый средний балл студента: ";
            /*std::cin >> temp_gpa;
            if (temp_gpa != 0) {
                student.gpa = temp_gpa;
                change++;
            }*/
            std::string gpa;
            std::getline(std::cin, gpa);


            /*if (name != "") {
                editStudentName(student.name, name);
                change++;
            }
            if (age != "") {
                editStudentData(student.age, std::stoi(age));
                change++;
            }
            if (major != "") {
                editStudentData(student.major, major);
                change++;
            }
            if (gpa != "") {
                editStudentData(student.gpa, std::stod(gpa));
                change++;
            }*/

            editStudentName(student.name, name);
            editStudentAge(student.age, age);
            editStudentMajor(student.major, major);
            editStudentGpa(student.gpa, gpa);

        }
    }
    if(search_student)
        std::cout << "Все изменения внесены в базу.\n\n";
    else
        std::cout << "Данный студент не найден.\n\n";
}

// Функция вызова тестов


// Тест 1. Тест изменения имени
TEST(StudentTests, TestNameChange){
    Student student;
    std::string old_name = "Max";
    std::string new_name = "Maxim";
    student.name = old_name;
    editStudentName(student.name, new_name);
    ASSERT_TRUE(student.name == new_name);
}

// Тест 2. Тест пропуска изменения имени
TEST(StudentTests, TestEditNameSkip){
    Student student;
    std::string old_name = "Max";
    std::string new_name = "";
    student.name = old_name;
    editStudentName(student.name, new_name);
    ASSERT_TRUE(student.name == old_name);
}


// Тест 3. Тест изменения возраста
TEST(StudentTests, TestEditNameSkip){
    Student student;
    int old_age = 21;
    std::string new_age = "22";
    student.age = old_age;
    editStudentAge(student.age, new_age);
    ASSERT_TRUE(student.age == std::stoi(new_age));
}


// Тест 4. Тест пропуска изменения возраста
TEST(StudentTests, TestEditAgeSkip){
    Student student;
    int old_age = 21;
    std::string new_age = "";
    student.age = old_age;
    editStudentAge(student.age, new_age);
    ASSERT_TRUE(student.age == old_age);
}


// Тест 5. Тест изменения специальности
TEST(StudentTests, TestEditMajor){
    Student student;
    std::string old_major = "Programmer";
    std::string new_major = "Teacher";
    student.major = old_major;
    editStudentMajor(student.major, new_major);
    ASSERT_TRUE(student.major == new_major);
}


// Тест 6. Тест пропуска изменения специальности
TEST(StudentTests, TestEditMajorSkip){
    Student student;
    std::string old_major = "Programmer";
    std::string new_major = "";
    student.major = old_major;
    editStudentMajor(student.major, new_major);
    ASSERT_TRUE(student.major == old_major);
}


// Тест 7. Тест изменения среднего балла
TEST(StudentTests, TestEditGPA){
    Student student;
    double old_gpa = 90.1;
    std::string new_gpa = "96,9";
    student.gpa = old_gpa;
    editStudentGpa(student.gpa, new_gpa);
    ASSERT_TRUE(student.gpa == std::stod(new_gpa));
}


// Тест 8. Тест пропуска изменения среднего балла
TEST(StudentTests, TestEditGPA){
    Student student;
    double old_gpa = 95.5;
    std::string new_gpa = "";
    student.gpa = old_gpa;
    editStudentGpa(student.gpa, new_gpa);
    ASSERT_TRUE(student.gpa == old_gpa);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
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

    return RUN_ALL_TESTS();
}
