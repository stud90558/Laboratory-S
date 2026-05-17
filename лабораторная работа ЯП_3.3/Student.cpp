#include "Student.h"
#include <sstream>
#include <iomanip>

Student::Student() : Human(), scores() {}

Student::Student(const std::string& name_, const std::string& surname_, const std::string& patronymic_, const std::vector<int>& sc)
    : Human(name_, surname_, patronymic_), scores(sc) {
}

void Student::addScore(int s) {
    scores.push_back(s);
}

double Student::getAverageScore() const {
    if (scores.empty()) return 0.0;
    double sum = 0;
    for (int v : scores) sum += v;
    return sum / scores.size();
}

std::string Student::getShortStudentInfo() const {
    std::ostringstream oss;
    oss << getSurnameAndInitials() << ": " << std::fixed << std::setprecision(2) << getAverageScore();
    return oss.str();
}

std::string Student::getFullStudentInfo() const {
    std::ostringstream oss;
    oss << getFullName() << ":";
    if (!scores.empty()) {
        oss << ' ';
        for (size_t i = 0; i < scores.size(); ++i) {
            if (i) oss << ' ';
            oss << scores[i];
        }
        oss << " –" << std::fixed << std::setprecision(2) << getAverageScore();
    }
    else {
        oss << " (нет оценок) –0.00";
    }
    return oss.str();
}

// простая текстовая сериализация: surname|name|patronymic|s1,s2,s3
std::string Student::serialize() const {
    std::ostringstream oss;
    oss << surname << '|' << name << '|' << patronymic << '|';
    for (size_t i = 0; i < scores.size(); ++i) {
        if (i) oss << ',';
        oss << scores[i];
    }
    return oss.str();
}

Student Student::deserialize(const std::string& line) {
    std::istringstream iss(line);
    std::string sname, sname2, spat, scoresPart;
    std::getline(iss, sname, '|');
    std::getline(iss, sname2, '|'); // name
    std::getline(iss, spat, '|');
    std::getline(iss, scoresPart);
    std::vector<int> sc;
    if (!scoresPart.empty()) {
        std::istringstream ss(scoresPart);
        std::string token;
        while (std::getline(ss, token, ',')) {
            if (!token.empty()) sc.push_back(std::stoi(token));
        }
    }
    return Student(sname2, sname, spat, sc);
}
