#include "gambling.h"
#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;

GamblingGame::GamblingGame() {
    cout << "***** ���� ������ �����մϴ�. *****\n";
    srand(time(NULL));
}

void GamblingGame::nameSet() {
    string name;
    cout << "ù��° ���� �̸�>>";
    cin >> name;
    p[0].setName(name);
    cout << "�ι�° ���� �̸�>>";
    cin >> name;
    p[1].setName(name);
}

string GamblingGame::random(string n) {
    int r[3];
    cout << "\t\t";
    for (int i = 0; i < 3; i++) {
        r[i] = rand() % 3;
        cout << r[i] << "\t";
    }
    if (r[0] == r[1] && r[0] == r[2]) {
        n += "�� �¸�!!";
        return n;
    }
    else
        return "�ƽ�����!";
}

void GamblingGame::startGame() {
    string n, m;
    int cnt = 0;
    while (true) {
        cout << p[cnt % 2].getName() << ":\n";
        getline(cin, n);
        m = p[cnt % 2].getName();
        n = random(n);
        if (n == "�� �¸�!!") {
            cout << m + n;
            break;
        }
        else
            cout << n << endl;
        cnt++;
    }
}


GamblingGame::~GamblingGame() {
    delete[] p;
}


