#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;

    Student() { }

    Student(std::string data[4]) {
        name = data[0];
        age = std::stoi(data[1]);
        major = data[2];
        gpa = std::stoi(data[3]);
    }
};

// ������� ��� ���������� �������� � ���� ������
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "������� ��� ��������: ";
    std::cin >> student.name;
    std::cout << "������� ������� ��������: ";
    std::cin >> student.age;
    std::cout << "������� ������������� ��������: ";
    std::cin >> student.major;
    std::cout << "������� ������� ���� ��������: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "������� �������� � ���� ������.\n";
}

// ������� ��� ������ ���� ��������� �� ���� ������
void displayStudents(const std::vector<Student>& database) {
    std::cout << "������ ���������:\n";
    for (const Student& student : database) {
        std::cout << "���: " << student.name << "\n";
        std::cout << "�������: " << student.age << "\n";
        std::cout << "�������������: " << student.major << "\n";
        std::cout << "������� ����: " << student.gpa << "\n\n";
    }
}

void readDataFromCSVFile(std::vector<Student>& database, std::string filename) {
    char delimiter = ',';
    std::string line;

    std::ifstream file(filename);

    if (file.fail()) {
        std::cout << "File doesn't exists" << std::endl;
        return;
    }

    int num_str = 0;

    while (std::getline(file, line)) {
        num_str++;
        bool correct_input = true;

        std::stringstream stream(line);

        std::string student_data[4];
        std::getline(stream, student_data[0], delimiter);
        std::getline(stream, student_data[1], delimiter);
        std::getline(stream, student_data[2], delimiter);
        std::getline(stream, student_data[3], delimiter);

        for (auto str : student_data) {
            if (str.empty()) {
                std::cout << "Value can't be null in " + std::to_string(num_str) + " row\n";
                correct_input = false;
                break;
            }
        }

        if (!correct_input)
            continue;

        Student student(student_data);
        database.push_back(student);
    }

    file.close();
}

void getDatabaseCSVFile(const std::vector<Student>& database) {
    std::ofstream file("��������.csv");
    for (Student student : database) {
        file << student.name << ','
            << student.age << ','
            << student.major << ','
            << student.gpa << std::endl;
    }

    file.close();
}
