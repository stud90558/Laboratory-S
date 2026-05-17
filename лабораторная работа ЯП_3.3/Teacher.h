#pragma once
#include "Human.h"
#include <vector>
#include <string>

enum class Position {
    Unknown,
    Assistant,
    SeniorLecturer,
    Docent,
    Professor
};

class Teacher : public Human {
private:
    Position position;
    std::vector<std::string> subjects;
public:
    Teacher();
    Teacher(const std::string& name, const std::string& surname, const std::string& patronymic, Position pos, const std::vector<std::string>& subj);
    void addSubject(const std::string& s);
    std::string getShortTeacherInfo() const;
    std::string getFullTeacherInfo() const;
    Position getPosition() const { return position; }
    const std::vector<std::string>& getSubjects() const { return subjects; }
    // сериализация
    std::string serialize() const;
    static Teacher deserialize(const std::string& line);
    static std::string positionToString(Position p);
    static Position stringToPosition(const std::string& s);
};
