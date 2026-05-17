#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Student.h"
#include "Teacher.h"

using namespace std;

void saveStudents(const string& filename, const vector<Student>& students) {
    ofstream ofs(filename);
    for (const auto& s : students) ofs << s.serialize() << '\n';
}

vector<Student> loadStudents(const string& filename) {
    vector<Student> res;
    ifstream ifs(filename);
    string line;
    while (getline(ifs, line)) {
        if (!line.empty()) res.push_back(Student::deserialize(line));
    }
    return res;
}

void saveTeachers(const string& filename, const vector<Teacher>& teachers) {
    ofstream ofs(filename);
    for (const auto& t : teachers) ofs << t.serialize() << '\n';
}

vector<Teacher> loadTeachers(const string& filename) {
    vector<Teacher> res;
    ifstream ifs(filename);
    string line;
    while (getline(ifs, line)) {
        if (!line.empty()) res.push_back(Teacher::deserialize(line));
    }
    return res;
}

int main() {
    setlocale(LC_ALL, "ru");
    // Пример заполнения 10 студентов
    vector<Student> students = {
        Student("Иван","Иванов","Иванович",{4,4,5,5}),
        Student("Пётр","Петров","Петрович",{5,5,5,4}),
        Student("Сергей","Сергеев","Сергеевич",{2,3,2}),
        Student("Алексей","Алексеев","Алексеевич",{4,5}),
        Student("Мария","Мариева","Мариевна",{5,4,5,5}),
        Student("Ольга","Ольгина","Ольговна",{3,2,3}),
        Student("Елена","Еленова","Еленовна",{4,4,4}),
        Student("Дмитрий","Дмитриев","Дмитриевич",{5,5,4,5,5}),
        Student("Наталья","Натальева","Натальевна",{1,2}),
        Student("Игорь","Игорев","Игоревич",{3,3,3,2})
    };

    // Пример заполнения 10 преподавателей
    vector<Teacher> teachers = {
        Teacher("Андрей","Андреев","Андреевич",Position::Docent,{"ОС","Информатика","Языки программирования"}),
        Teacher("Борис","Борисов","Борисович",Position::Assistant,{"Математика"}),
        Teacher("Виктор","Викторов","Викторович",Position::Professor,{"Информатика","Алгоритмы","Структуры данных","ОС"}),
        Teacher("Галина","Галина","Галиновна",Position::SeniorLecturer,{"Физика","Информатика"}),
        Teacher("Дана","Данова","Дановна",Position::Docent,{"Языки программирования","Базы данных"}),
        Teacher("Егор","Егоров","Егорович",Position::Professor,{"Теория вероятностей","Статистика"}),
        Teacher("Жанна","Жаннова","Жанновна",Position::Assistant,{"Информатика"}),
        Teacher("Зоя","Зоевa","Зоевна",Position::Docent,{"Информатика","Математика"}),
        Teacher("Ирина","Иринa","Ириневна",Position::SeniorLecturer,{"Базы данных","Сети"}),
        Teacher("Кирилл","Кириллов","Кириллович",Position::Professor,{"ОС","Информатика","Безопасность","Сети","Языки программирования"})
    };

    // Сохранить и загрузить для демонстрации
    saveStudents("students.txt", students);
    saveTeachers("teachers.txt", teachers);

    auto loadedStudents = loadStudents("students.txt");
    auto loadedTeachers = loadTeachers("teachers.txt");

    // 1) краткая информация обо всех студентах, у которых средний балл > 4
    cout << "Студенты со средним > 4:\n";
    for (const auto& s : loadedStudents) {
        if (s.getAverageScore() > 4.0) cout << s.getShortStudentInfo() << '\n';
    }
    cout << '\n';

    // 2) краткая информация обо всех студентах, у которых средний балл < 3
    cout << "Студенты со средним < 3:\n";
    for (const auto& s : loadedStudents) {
        if (s.getAverageScore() < 3.0) cout << s.getShortStudentInfo() << '\n';
    }
    cout << '\n';

    // 3) полная информация о студенте, у которого больше всего оценок
    auto itMaxScores = max_element(loadedStudents.begin(), loadedStudents.end(),
        [](const Student& a, const Student& b) { return a.getScores().size() < b.getScores().size(); });
    if (itMaxScores != loadedStudents.end()) {
        cout << "Студент с наибольшим количеством оценок:\n" << itMaxScores->getFullStudentInfo() << "\n\n";
    }

    // 4) краткая информация обо всех доцентах
    cout << "Краткая информация обо всех доцентах:\n";
    for (const auto& t : loadedTeachers) {
        if (t.getPosition() == Position::Docent) cout << t.getShortTeacherInfo() << '\n';
    }
    cout << '\n';

    // 5) полная информация о профессоре, у которого больше всего предметов
    auto itProfMax = max_element(loadedTeachers.begin(), loadedTeachers.end(),
        [](const Teacher& a, const Teacher& b) { return a.getSubjects().size() < b.getSubjects().size(); });
    if (itProfMax != loadedTeachers.end()) {
        // выбрать только среди профессоров
        size_t maxCount = 0;
        const Teacher* best = nullptr;
        for (const auto& t : loadedTeachers) {
            if (t.getPosition() == Position::Professor && t.getSubjects().size() > maxCount) {
                maxCount = t.getSubjects().size();
                best = &t;
            }
        }
        if (best) {
            cout << "Профессор с наибольшим числом предметов:\n" << best->getFullTeacherInfo() << "\n\n";
        }
        else {
            cout << "Профессоров нет.\n\n";
        }
    }

    // 6) полная информация обо всех преподавателях, которые ведут информатику
    cout << "Преподаватели, ведущие Информатику:\n";
    for (const auto& t : loadedTeachers) {
        for (const auto& subj : t.getSubjects()) {
            if (subj == "Информатика") {
                cout << t.getFullTeacherInfo() << '\n';
                break;
            }
        }
    }

    return 0;
}
