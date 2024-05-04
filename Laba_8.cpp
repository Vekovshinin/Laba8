#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct student {
    string surname;
    string name;
    string patronymic;
    string datar;
    string adress;
    float rating;
    void enter_info(string s, string n, string p, string d, string a, float r) {
        surname = s;
        name = n;
        patronymic = p;
        datar = d;
        adress = a;
        rating = r;
    }
};

int main()
{
    setlocale(LC_ALL, "Ru");
    system("chcp1251");
    system("cls");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int count;
    student m[50];
    cout << "Введите количество студентов: ";
    cin >> count;
    for (int i = 0; i < count; i++) {
        string s, n, p, d, a;
        float r;
        cout << "Введите ФИО, дату рождения, адресс и рейтинг студента №" << i + 1 << endl;
        cin >> s >> n >> p >> d >> a >> r;
        m[i].enter_info(s, n, p, d, a, r);
    }
    int myd[50];
    int k = 0;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (m[i].datar == m[j].datar) {
                myd[k] = i;
                myd[k + 1] = j;
                k += 2;

            }
        }
    }
    bool f = false;
    int elfam;
    string fam;
    cout << "Введите фамилию человека, перед которым нужно поставить другого: ";
    cin >> fam;
    for (int i = 0; i < count; i++) {
        if (m[i].surname == fam) {
            elfam = i;
            f = true;

        }
    }
    for (int i = 0; i < count; ++i)
        cout << m[i].surname << " " << m[i].name << " " << m[i].patronymic << " " << m[i].datar << " " << m[i].adress << " " << m[i].rating << endl;
    if (f == true) {
        for (int i = count; i > elfam; i--) {
            m[i] = m[i - 1];
        }
        string s1, n1, p1, d1, a1;
        float r1;
        cout << "Введите ФИО, дату рождения, адрес, рейтинг нового студента: " << endl;
        cin >> s1 >> n1 >> p1 >> d1 >> a1 >> r1;
        m[elfam].enter_info(s1, n1, p1, d1, a1, r1);
        count++;
        for (int i = 0; i < k; i++) {
            if (myd[i] > elfam) {
                myd[i]++;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        cout << myd[i] << ' ';
    }
    cout << endl;

    for (int i =0; i < count; ++i)
        cout<< m[i].surname << " " << m[i].name << " " << m[i].patronymic << " " << m[i].datar << " " << m[i].adress << " " << m[i].rating << endl;

    cout << endl << count - k;
    ofstream f1("f1.txt");
    bool flag = true;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < k; j++) {
            if (i == myd[j]) {
                flag = false;
            }
        }
        if (flag) {
            f1 << m[i].surname << " " << m[i].name << " " << m[i].patronymic << " " << m[i].datar << " " << m[i].adress << " " << m[i].rating << endl;
        }
        flag = true;
    }
    f1.close();
    return 0;

}  
