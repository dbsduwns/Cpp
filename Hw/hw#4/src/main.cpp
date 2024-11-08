#include <iostream>
#include <string>
using namespace std;

class printer {
protected:
    string model;
    string manufacturer;
    int printedCount = 0;
    int availableCount;
public:
    printer(int pages) : availableCount(pages) {}
    void setModel(string model) { this->model = model; }
    void setManufacturer(string manufacturer) { this->manufacturer = manufacturer; }
    string getModel() { return model; }
    string getManufacturer() { return manufacturer; }
    int getPages() { return availableCount; }
    void print(int pages) {
        if (pages > availableCount) {
            cout << "종이가 부족합니다." << endl;
            return;
        }
        printedCount += pages;
        availableCount -= pages;
        cout << "프린트하였습니다." << endl;
    }
};

class printerInkJet : public printer {
    int availableInk;
public:
    printerInkJet(int pages, int availableInk) : printer(pages), availableInk(availableInk) {}
    int getInk() { return availableInk; }
    void printInkJet(int pages) {
        print(pages);
        if (pages > availableInk) {
            cout << "잉크가 부족합니다." << endl;
            return;
        }
        availableInk -= pages;
    }
};

class printerLaser : public printer {
    int availableToner;
public:
    printerLaser(int pages, int availableToner) : printer(pages), availableToner(availableToner) {}
    int getToner() { return availableToner; }
    void printLaser(int pages) {
        print(pages);
        if (pages > availableToner * 2) {
            cout << "토너가 부족합니다." << endl;
            return;
        }
        availableToner -= (pages / 2);
    }
};

int main() {
    string InkModel = "Officejet V40";
    string LaserModel = "SCX-6x45";
    string InkManufacturer = "HP";
    string LaserManufacturer = "삼성전자";

    printerInkJet pj(5, 10);
    printerLaser pl(10, 20);
    pj.setModel(InkModel);
    pj.setManufacturer(InkManufacturer);
    pl.setModel(LaserModel);
    pl.setManufacturer(LaserManufacturer);

    cout << "현재 작동 중인 프린터는 아래와 같다." << endl;
    cout << "잉크젯 : " << pj.getModel() << ", " << pj.getManufacturer() << ", "
        << "남은 종이 " << pj.getPages() << ", " << "남은 잉크 " << pj.getInk() << endl;
    cout << "레이저 : " << pl.getModel() << ", " << pl.getManufacturer() << ", "
        << "남은 종이 " << pl.getPages() << ", " << "남은 토너 " << pl.getToner() << endl;

    int printerType;
    int page;
    char answer;

    while (true) {
        cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>> ";
        cin >> printerType >> page;

        if (printerType == 1) {
            pj.printInkJet(page);
            cout << "잉크젯 : " << pj.getModel() << ", " << pj.getManufacturer() << ", "
                << "남은 종이 " << pj.getPages() << ", " << "남은 잉크 " << pj.getInk() << endl;
        }
        else if (printerType == 2) {
            pl.printLaser(page);
            cout << "레이저 : " << pl.getModel() << ", " << pl.getManufacturer() << ", "
                << "남은 종이 " << pl.getPages() << ", " << "남은 토너 " << pl.getToner() << endl;
        }

        do {
            cout << "계속 프린트 하시겠습니까?(y/n)>>";
            cin >> answer;
            if (answer == 'y') break;
            else if (answer == 'n') return 0;
            else cout << "y/n 만 입력해주세요." << endl;
        } while (true);
    }

    return 0;
}
