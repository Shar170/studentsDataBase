#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "DataBaseStudent.h"

bool T_or_F_sort_name(std::vector<Student> database) {
    for (int i = 0; i < database.size() - 1; i++) {
        if (database[i].name > database[i + 1].name) {
            return false;
        }
    }
    return true;
}

bool T_or_F_sort_gpa(std::vector<Student> database) {
    for (int i = 0; i < database.size() - 1; i++) {
        if (database[i].gpa < database[i + 1].gpa) {
            return false;
        }
    }
    return true;
}


TEST(tests, test_1_compare_by_name) {
    // Arrange
    std::vector<Student> database;
    Student student;

    student.name = "Katya";
    student.age = 20;
    student.major = "ICT";
    student.gpa = 4.9;
    database.push_back(student);

    student.name = "Dasha";
    student.age = 21;
    student.major = "ICT2";
    student.gpa = 4.7;
    database.push_back(student);

    student.name = "Max";
    student.age = 21;
    student.major = "ICT";
    student.gpa = 5.0;
    database.push_back(student);

    // Act
    std::sort(database.begin(), database.end(), compareByName);

    // Assert
    ASSERT_TRUE(T_or_F_sort_name(database));

}

TEST(tests, test_2_compare_by_gpa) {
    // Arrange
    std::vector<Student> database;
    Student student;

    student.name = "Katya";
    student.age = 20;
    student.major = "ICT";
    student.gpa = 4.9;
    database.push_back(student);

    student.name = "Dasha";
    student.age = 21;
    student.major = "ICT2";
    student.gpa = 4.7;
    database.push_back(student);

    student.name = "Max";
    student.age = 21;
    student.major = "ICT";
    student.gpa = 5.0;
    database.push_back(student);

    // Act
    std::sort(database.begin(), database.end(), compareByGpa);

    // Assert
    ASSERT_TRUE(T_or_F_sort_gpa(database));

}

TEST(tests, test_3_is_student_in_database_f) {
    // Arrange
    std::vector<Student> database;
    Student student;

    student.name = "Katya";
    student.age = 20;
    student.major = "ICT";
    student.gpa = 4.9;
    database.push_back(student);

    student.name = "Dasha";
    student.age = 21;
    student.major = "ICT2";
    student.gpa = 4.7;
    database.push_back(student);

    student.name = "Max";
    student.age = 21;
    student.major = "ICT";
    student.gpa = 5.0;
    database.push_back(student);

    // Act
    bool result = isStudentInDatabase(database, "Kirill");

    // Assert
    ASSERT_FALSE(result);
}

TEST(tests, test_4_is_student_in_database_t) {
    // Arrange
    std::vector<Student> database;
    Student student;

    student.name = "Katya";
    student.age = 20;
    student.major = "ICT";
    student.gpa = 4.9;
    database.push_back(student);

    student.name = "Dasha";
    student.age = 21;
    student.major = "ICT2";
    student.gpa = 4.7;
    database.push_back(student);

    student.name = "Max";
    student.age = 21;
    student.major = "ICT";
    student.gpa = 5.0;
    database.push_back(student);

    // Act
    bool result = isStudentInDatabase(database, "Dasha");

    // Assert
    ASSERT_TRUE(result);
}

TEST(tests, test_5_compare_two_names) {
    // Arrange
    Student student;
    student.name = "Katya";
    student.age = 20;
    student.major = "ICT";
    student.gpa = 4.9;

    Student student_2;
    student_2.name = "Dasha";
    student_2.age = 21;
    student_2.major = "ICT2";
    student_2.gpa = 4.7;

    // Act
    bool result = compareByName(student, student_2);

    //Assert
    ASSERT_FALSE(result);


}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

