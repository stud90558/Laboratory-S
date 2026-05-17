#pragma once
#include "Human.h"
#include <vector>
#include <string>

class Student : public Human {
private:
    std::vector<int> scores;
public:
    Student();
    Student(const std::string& name, const std::string& surname, const std::string& patronymic, const std::vector<int>& scores);
    void addScore(int s);
    double getAverageScore() const;
    std::string getShortStudentInfo() const;
    std::string getFullStudentInfo() const;
    const std::vector<int>& getScores() const { return scores; }
    // сериализация
    std::string serialize() const;
    static Student deserialize(const std::string& line);
};
