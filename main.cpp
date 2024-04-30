#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


struct Lesson {
    string time;
    string subject;
};


class Schedule {
private:
    vector<vector<Lesson>> harmonogram;

public:
    Schedule() : harmonogram(5) {}


    void load() {
        ifstream file("data.txt");
        if (file.is_open()) {
            int day = 0;
            string line;
            while (getline(file, line)) {
                if (line.empty()) {
                    day++;
                } else {
                    Lesson lesson;
                    lesson.time = line.substr(0, 11 );
                    lesson.subject = line.substr(12);
                    harmonogram[day].push_back(lesson);
                }
            }
            file.close();
        }
    }


    void display(int day) {
        string days[] = {"poniedzialek", "wtorek", "srode", "czwartek", "piatek"};
        cout << "Plan zajec dla " << days[day - 1] << ":" << endl;
        for (const Lesson& lesson : harmonogram[day - 1]) {
            cout << lesson.time << " " << lesson.subject << endl;
        }
    }


    void save() {
        ofstream file("data.txt");
        if (file.is_open()) {
            string days[] = {"poniedzialek", "wtorek", "srode", "czwartek", "piatek"};
            for (int i = 0; i < 5; ++i) {
                file << days[i] << ":" << endl;
                for (const Lesson& lesson : harmonogram[i]) {
                    file << lesson.time << " " << lesson.subject << endl;
                }
                file << endl;
            }
            file.close();
        }
    }


    void menu() {
        int choice;
        do {
            cout << "Menu:" << endl;
            cout << "1. Odczytaj plan" << endl;
            cout << "2. Edytuj plan" << endl;
            cout << "3. Zapisz plan" << endl;
            cout << "4. Pomoc" << endl;
            cout << "5. Zakoncz" << endl;
            cout << "Wybierz opcje: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int day;
                    cout << "Podaj dzien tygodnia (poniedzialek - piatek): ";
                    string input;
                    cin >> input;
                    if (input == "poniedzialek") {
                        day = 1;
                    } else if (input == "wtorek") {
                        day = 2;
                    } else if (input == "sroda ") {
                        day = 3;
                    } else if (input == "czwartek") {
                        day = 4;
                    } else if (input == "piatek") {
                        day = 5;
                    } else {
                        cout << "Nieprawidlowy dzien tygodnia." << endl;
                        continue;
                    }
                    display(day);
                    break;
                }
                case 2: {

                    break;
                }
                case 3: {

                    save();
                    break;
                }
                case 4:
                    cout << "Pomoc: Pogram umozliwia sprawdzenie planu lekcji i edycje planu" << endl;
                    break;
                case 5:
                    cout << "Zakonczono program." << endl;
                    break;
                default:
                    cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
            }
        } while (choice != 5);
    }
};

int main() {
    Schedule harmonogram;
    harmonogram.load();
    harmonogram.menu();
    return 0;
}

