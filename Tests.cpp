#include <gtest/gtest.h> 
#include <gmock/gmock.h> 
#include "StudentDatabase.h"

TEST(TestGroupName, Test_1) {
    // Arrange
    std::vector<Student*> database;
    Student student1;

    student1.name = "Даша";
    student1.age = 21;
    student1.major = "IT";
    student1.gpa = 5;
    database.push_back(&student1);

    Student student2;
    student2.name = "Саша";
    student2.age = 18;
    student2.major = "Менеджер";
    student2.gpa = 3;
    database.push_back(&student2);

    Student student3;
    student3.name = "Сергей";
    student3.age = 20;
    student3.major = "Сварщик";
    student3.gpa = 4;
    database.push_back(&student3);

    // Act
    Student* student_name = findStudentByName(database, "Даша");

    // Assert
    ASSERT_TRUE(student_name->name == "Даша");
}

TEST(TestGroupName, Test_2) {
    // Arrange
    std::vector<Student*> database;
    Student student1;

    student1.name = "Даша";
    student1.age = 21;
    student1.major = "IT";
    student1.gpa = 5;
    database.push_back(&student1);

    Student student2;
    student2.name = "Саша";
    student2.age = 18;
    student2.major = "Менеджер";
    student2.gpa = 3;
    database.push_back(&student2);

    Student student3;
    student3.name = "Сергей";
    student3.age = 20;
    student3.major = "Сварщик";
    student3.gpa = 4;
    database.push_back(&student3);

    // Act
    Student* student_major = findStudentByMajor(database, "Менеджер");

    // Assert
    ASSERT_TRUE(student_major->major == "Менеджер");
}

TEST(TestGroupName, Test_3) {
    // Arrange
    std::vector<Student*> database;
    Student student1;

    student1.name = "Даша";
    student1.age = 21;
    student1.major = "IT";
    student1.gpa = 5;
    database.push_back(&student1);

    Student student2;
    student2.name = "Саша";
    student2.age = 18;
    student2.major = "Менеджер";
    student2.gpa = 3;
    database.push_back(&student2);

    Student student3;
    student3.name = "Сергей";
    student3.age = 20;
    student3.major = "Сварщик";
    student3.gpa = 4;
    database.push_back(&student3);

    // Act
    Student* student_name = findStudentByName(database, "Света");

    // Assert
    ASSERT_TRUE(student_name == nullptr);
}

TEST(TestGroupName, Test_4) {
    // Arrange
    std::vector<Student*> database;
    Student student1;

    student1.name = "Даша";
    student1.age = 21;
    student1.major = "IT";
    student1.gpa = 5;
    database.push_back(&student1);

    Student student2;
    student2.name = "Саша";
    student2.age = 18;
    student2.major = "Менеджер";
    student2.gpa = 3;
    database.push_back(&student2);

    Student student3;
    student3.name = "Сергей";
    student3.age = 20;
    student3.major = "Сварщик";
    student3.gpa = 4;
    database.push_back(&student3);

    // Act
    Student* student_major = findStudentByMajor(database, "Врач");

    // Assert
    ASSERT_TRUE(student_major == nullptr);
}

TEST(TestGroupName, Test_5) {
    // Arrange
    std::vector<Student*> database;
    Student student1;

    student1.name = "Саша";
    student1.age = 21;
    student1.major = "IT";
    student1.gpa = 5;
    database.push_back(&student1);

    Student student2;
    student2.name = "Саша";
    student2.age = 18;
    student2.major = "Менеджер";
    student2.gpa = 3;
    database.push_back(&student2);

    Student student3;
    student3.name = "Сергей";
    student3.age = 20;
    student3.major = "Сварщик";
    student3.gpa = 4;
    database.push_back(&student3);

    // Act
    Student* student_name = findStudentByName(database, "Саша");
    Student* student_major = findStudentByMajor(database, "Менеджер");

    // Assert
    ASSERT_TRUE(student_major->major == "Менеджер" && student_name->name == "Саша");
}

int main(int argc, char **argv) { 

	::testing::InitGoogleTest(&argc, argv); 

	return RUN_ALL_TESTS(); 
}
