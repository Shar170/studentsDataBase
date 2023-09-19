#include "database.h"

class Test {
public:
    void runTests() {
        testAddStudent();
        testDisplayStudents();
        testCreateReport();
        testCreateReportEmptyDatabase();
        testAddStudentMultiple();
        // Добавьте вызовы других тестов по необходимости
    }

private:
    void testAddStudent() {
        std::vector<Student> database;
        std::istringstream input("John\n20\nComputer Science\n3.5\n");
        std::cin.rdbuf(input.rdbuf());

        addStudent(database);

        // Проверяем, что студент был успешно добавлен
        assert(database.size() == 1);
        assert(database[0].name == "John");
        assert(database[0].age == 20);
        assert(database[0].major == "Computer Science");
        assert(database[0].gpa == 3.5);
    }

    void testDisplayStudents() {
        std::vector<Student> database;
        Student student1 = { "John", 20, "Computer Science", 3.5 };
        Student student2 = { "Alice", 22, "Mathematics", 3.8 };
        database.push_back(student1);
        database.push_back(student2);

        std::ostringstream output;
        std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
        displayStudents(database);
        std::cout.rdbuf(oldCoutBuffer);

        // Проверяем, что вывод на консоль содержит данные о студентах
        assert(output.str().find("John") != std::string::npos);
        assert(output.str().find("Alice") != std::string::npos);
    }

    void testCreateReport() {
        std::vector<Student> database;
        Student student1 = { "John", 20, "Computer Science", 3.5 };
        Student student2 = { "Alice", 22, "Mathematics", 3.8 };
        database.push_back(student1);
        database.push_back(student2);

        createReport(database);

        // Проверяем, что файл с отчетом был успешно создан
        std::ifstream reportFile("student_report.txt");
        assert(reportFile.is_open());
        reportFile.close();
    }
    void testAddStudentMultiple() {
        std::vector<Student> database;
        std::istringstream input("John\n20\nComputer Science\n3.5\n"
            "Alice\n22\nMathematics\n3.8\n");
        std::cin.rdbuf(input.rdbuf());

        addStudent(database);
        addStudent(database);

        // Проверяем, что два студента были успешно добавлены
        assert(database.size() == 2);
        assert(database[0].name == "John");
        assert(database[1].name == "Alice");
    }

    void testCreateReportEmptyDatabase() {
        std::vector<Student> database;

        createReport(database);

        // Проверяем, что файл с отчетом не был создан
        std::ifstream reportFile("student_report.txt");
        assert(!reportFile.is_open());
    }
};

int main() {
    Test test;
    test.runTests();

    return 0;
}
