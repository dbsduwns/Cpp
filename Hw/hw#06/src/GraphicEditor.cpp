#include<iostream>
#include<vector>
using namespace std;

class Shape {
protected:
	virtual void draw() = 0;
public:
	void print() {
		draw();
	}
};

class Circle : public Shape{
protected:
	virtual void draw() {
		cout << "Circle" << endl;
	}
};

class Rect : public Shape {
protected:
	virtual void draw() {
		cout << "Rect" << endl;
	}
};

class Line : public Shape {
protected:
	virtual void draw() {
		cout << "Line" << endl;
	}
};

class UI {
public:
	int menu() {
		int num;
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> num;
		return num;
	}

	int inputShape() {
		int num;
		cout << "선:1, 원:2, 사각형:3 >> ";
		cin >> num;
		return num;
	}

	int inputDel() {
		int num;
		cout << "삭제하고자 하는 도형의 인덱스 >> ";
		cin >> num;
		return num;
	}
};

class GraphicEditor {
	vector<Shape*> v;
public:

	int run() {
		cout << "그래픽 에디터입니다." << endl;
		while (true) {
			int num = 0;
			num = UI::menu();
			switch (num) {
			case 1:
				num = inputShape();
				add(num);
				break;
			case 2:
				num = inputDel();
				del(num);
				break;
			case 3:
				show();
				break;
			case 4:
				exit(0);
				break;
			default:
				cout << "1-4까지 숫자만 입력하세요" << endl;
			}
		}
	}

	void add(int n) {
		switch (n) {
		case 1:
			v.push_back(new Line());
			break;
		case 2:
			v.push_back(new Circle());
			break;
		case 3:
			v.push_back(new Rect());
			break;
		default:
			cout << "메뉴를 잘못 선택하셨습니다." << endl;
		}
	}

	bool del(int n) {
		vector<Shape*>::iterator it;
		it = v.begin();

		if (n > v.size() || n < 0)
			return false;
		else {
			for (int i = 0; i < n; i++) {
				it++;
			}
			v.erase(it);
			return true;
		}
	}

	void show() {
		for (int i = 0; i < v.size(); i++) {
			cout << i << ": ";
			v[i]->paint();
		}
	}

};







