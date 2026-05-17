#include "Teacher.h"
#include <sstream>

Teacher::Teacher() : Human(), position(Position::Unknown), subjects() {}

Teacher::Teacher(const std::string& name_, const std::string& surname_, const std::string& patronymic_, Position pos, const std::vector<std::string>& subj)
    : Human(name_, surname_, patronymic_), position(pos), subjects(subj) {
}

void Teacher::addSubject(const std::string& s) {
    subjects.push_back(s);
}

std::string Teacher::positionToString(Position p) {
    switch (p) {
    case Position::Assistant: return "ассистент";
    case Position::SeniorLecturer: return "старший преподаватель";
    case Position::Docent: return "доцент";
    case Position::Professor: return "профессор";
    default: return "Неизвестно";
    }
}

Position Teacher::stringToPosition(const std::string& s) {
    if (s == "ассистент") return Position::Assistant;
    if (s == "старший преподаватель") return Position::SeniorLecturer;
    if (s == "доцент") return Position::Docent;
    if (s == "профессор") return Position::Professor;
    return Position::Unknown;
}

std::string Teacher::getShortTeacherInfo() const {
    std::ostringstream oss;
    oss << getSurnameAndInitials() << ' ' << positionToString(position) << ": " << subjects.size();
    return oss.str();
}

std::string Teacher::getFullTeacherInfo() const {
    std::ostringstream oss;
    oss << getFullName() << ' ' << positionToString(position) << ": ";
    for (size_t i = 0; i < subjects.size(); ++i) {
        if (i) oss << ", ";
        oss << subjects[i];
    }
    return oss.str();
}

// сериализация: surname|name|patronymic|positionString|sub1,sub2,...
std::string Teacher::serialize() const {
    std::ostringstream oss;
    oss << surname << '|' << name << '|' << patronymic << '|' << positionToString(position) << '|';
    for (size_t i = 0; i < subjects.size(); ++i) {
        if (i) oss << ',';
        oss << subjects[i];
    }
    return oss.str();
}

Teacher Teacher::deserialize(const std::string& line) {
    std::istringstream iss(line);
    std::string s_surname, s_name, s_pat, posStr, subs;
    std::getline(iss, s_surname, '|');
    std::getline(iss, s_name, '|');
    std::getline(iss, s_pat, '|');
    std::getline(iss, posStr, '|');
    std::getline(iss, subs);
    std::vector<std::string> subjects;
    if (!subs.empty()) {
        std::istringstream ss(subs);
        std::string token;
        while (std::getline(ss, token, ',')) {
            if (!token.empty()) subjects.push_back(token);
        }
    }
    return Teacher(s_name, s_surname, s_pat, stringToPosition(posStr), subjects);
}
