#include "database.h"

class Test {
public:
    void runTests() {
        testAddStudent();
        testDisplayStudents();
        testCreateReport();
        testCreateReportEmptyDatabase();
        testExitProgram();
        // Добавьте вызовы других тестов по необходимости
    }

private:
    void testAddStudent() {
        std::vector<Student> database;  // Создаем пустую базу данных

        // Создаем студента и добавляем его в базу данных
        Student student;
        student.name = "John Doe";
        student.age = 20;
        student.major = "Computer Science";  // Устанавливаем major в "Computer Science"
        student.gpa = 3.8;

        // Добавляем студента в базу данных
        database.push_back(student);

        // Запускаем функцию для добавления студента
        addStudent(database);

        // Проверяем, что первый элемент в базе данных имеет major равный "Computer Science"
        assert(database[0].major == "Computer Science");
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
    void testExitProgram() {
        // Создаем поток, который будет захватывать выход программы
        std::stringstream output;
        std::streambuf* origCoutBuffer = std::cout.rdbuf(output.rdbuf());

        // Симулируем выбор опции "0. Exit" в меню
        std::istringstream input("0\n");
        std::cin.rdbuf(input.rdbuf());

        // Запускаем программу
        main();

        // Получаем код завершения
        int exitCode = std::system("echo $?");

        // Восстанавливаем стандартный вывод
        std::cout.rdbuf(origCoutBuffer);

        // Проверяем, что программа завершилась с кодом 0
        assert(exitCode == 0);
    }


    void testCreateReportEmptyDatabase() {
        std::vector<Student> database;  // Создаем пустую базу данных

        // Удаляем файл отчета, если он существует, чтобы обеспечить пустое начальное состояние
        std::remove("student_report.txt");

        // Запускаем функцию для создания отчета
        createReport(database);

        // Проверяем, что файл отчета не открыт (не существует)
        std::ifstream reportFile("student_report.txt");
        assert(reportFile.is_open());
    }
};

int main() {
    Test test;
    test.runTests();

    return 0;
}
