#include <iostream>
#include <vector>
#include <string>
#include <limits>
#pragma once

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Ôóíêöèÿ äëÿ äîáàâëåíèÿ ñòóäåíòà â áàçó äàííûõ
void addStudent(std::vector<Student>& database) {
    Student student;

    // Çàïðàøèâàåì èìÿ ñòóäåíòà
    std::cout << "Ââåäèòå èìÿ ñòóäåíòà: ";
    std::cin.ignore(); // Î÷èùàåì áóôåð ââîäà
    std::getline(std::cin, student.name);

    // Çàïðàøèâàåì âîçðàñò ñòóäåíòà ñ îáðàáîòêîé îøèáîê
    while (true) {
        std::cout << "Ââåäèòå âîçðàñò ñòóäåíòà: ";
        if (std::cin >> student.age && student.age > 0) {
            break; // Ââîä êîððåêòåí, âûõîäèì èç öèêëà
        }
        else {
            std::cout << "Îøèáêà: Ââåäèòå êîððåêòíûé âîçðàñò (öåëîå ÷èñëî > 0).\n";
            std::cin.clear(); // Ñáðàñûâàåì ôëàã îøèáêè
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Î÷èùàåì áóôåð ââîäà
        }
    }

    // Çàïðàøèâàåì ñïåöèàëüíîñòü ñòóäåíòà
    std::cout << "Ââåäèòå ñïåöèàëüíîñòü ñòóäåíòà: ";
    std::cin.ignore(); // Î÷èùàåì áóôåð ââîäà
    std::getline(std::cin, student.major);

    // Çàïðàøèâàåì ñðåäíèé áàëë ñòóäåíòà ñ îáðàáîòêîé îøèáîê
    while (true) {
        std::cout << "Ââåäèòå ñðåäíèé áàëë ñòóäåíòà: ";
        if (std::cin >> student.gpa && student.gpa > 0) {
            break; // Ââîä êîððåêòåí, âûõîäèì èç öèêëà
        }
        else {
            std::cout << "Îøèáêà: Ââåäèòå êîððåêòíûé ñðåäíèé áàëë (÷èñëî).\n";
            std::cin.clear(); // Ñáðàñûâàåì ôëàã îøèáêè
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Î÷èùàåì áóôåð ââîäà
        }
    }

    database.push_back(student);
    std::cout << "Ñòóäåíò äîáàâëåí â áàçó äàííûõ.\n";
}

// Ôóíêöèÿ äëÿ âûâîäà âñåõ ñòóäåíòîâ èç áàçû äàííûõ
void displayStudents(const std::vector<Student>& database) {
    std::cout << "Ñïèñîê ñòóäåíòîâ:\n";
    for (const Student& student : database) {
        std::cout << "Èìÿ: " << student.name << "\n";
        std::cout << "Âîçðàñò: " << student.age << "\n";
        std::cout << "Ñïåöèàëüíîñòü: " << student.major << "\n";
        std::cout << "Ñðåäíèé áàëë: " << student.gpa << "\n\n";
    }
}

// Ôóíêöèÿ äëÿ ðàñ÷¸òà ñðåäíåãî âîçðàñòà ñòóäåíòîâ
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
