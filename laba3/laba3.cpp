#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Detail
{
protected:
	Detail() {
		cout << "Создание Детали\n";
	}
public:
	virtual void gg() = 0;
	virtual ~Detail() = default;  // Виртуальный деструктор
};

class Assembly : public Detail
{
protected:
		Assembly() {
			cout << "Создание сборки\n";
	}
public:
	void gg() override {
		cout << "Это сборка";
	}

	static unique_ptr<Detail> create() {
		return std::unique_ptr<Detail>(new Assembly());
	}

};


int main() {
	setlocale(LC_ALL, "Russian");
	vector<unique_ptr<Detail>> storage;

	storage.emplace_back(Assembly::create());

	for (const auto& item : storage) {
		item->gg();
	}
	return 0;
}


#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cstdlib>

using namespace std;

class Base
{
public:
	virtual ~Base() = default;
	virtual void gg() = 0;
};

class Derived1 : public Base
{
public:
	void gg() override {
		cout << "Это Dirived1\n";
	}
};

class Derived2 : public Base
{
public:
	void gg() override {
		cout << "Это Derived2\n";
	}
};

void add(vector<unique_ptr<Base>>& b, unique_ptr<Base> obj) {
	b.push_back(move(obj));
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(static_cast<unsigned int>(time(nullptr)));
	vector<unique_ptr<Base>> b;
	for (int i = 0; i < 6; i++) {
		int random = 1 + rand() % 2;
		if (random == 1) {
			add(b, make_unique<Derived1>());
		}
		else {
			add(b, make_unique<Derived2>());
		}
	}
	for (const auto& obj : b) {
		obj->gg();
	}
}

