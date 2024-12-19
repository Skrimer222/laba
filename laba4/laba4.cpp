
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cstdlib>

using namespace std;

class Movement
{
public:
	virtual ~Movement() = default;
	virtual void gg() {
		cout << "Средства передвижения\n";
	};
};

class car : public Movement {
	void gg() override {
		cout << "Передвижние на машине\n";
	}
};

class bicycle : public Movement {
	void gg() override {
		cout << "Передвижение на велосипеде\n";
	}
};

class truck : public Movement {
	void gg() override {
		cout << "Передвижение на грузовике\n";
	}
};


class OverflowError : public Movement {
public:
	void gg() override {
		cout << "Ошибка переполнения\n";
	}
};


template <typename T>
class PointerArray {
private:
	vector<T*> items;
public:
	void add(T* item) {
		items.push_back(item);
	}

	T* operator[](std::size_t index) {
		if (index >= items.size()) {
			throw out_of_range("Индекс выходит за пределы допустимого диапазона\n");
		}
		return items[index];
	}
	~PointerArray() {
		for (T* item : items) {
			delete item;
		}
	}
};


int main() {
	setlocale(LC_ALL, "ru");
	try {
		PointerArray<Movement> errors;

		errors.add(new car());
		errors.add(new bicycle());
		errors.add(new truck());

		for (int i = 0; i < 3; i++) {
			errors[i]->gg();
		}

		errors[10]->gg();
	}
	catch (const out_of_range& e) {
		cerr << "Исключения из диапазона" << e.what() << endl;
	}
	catch (const exception& e) {
		cerr << "Исключение" << e.what() << endl;
	}
	return 0;
}


#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

class Base {
public:
    virtual ~Base() = default;
    virtual void gg() const = 0;
};

class Derived : public Base {
public:
    void gg() const override {
        cout << "This is Derived class.\n";
    }
};

void add(vector<unique_ptr<Base>>& storage, unique_ptr<Base> obj) {
    storage.push_back(move(obj));
}

int main() {
    try {

        vector<unique_ptr<Base>> storage;
      
        storage.reserve(static_cast<size_t>(-1));

        for (int i = 0; i < 10; ++i) {
            if (std::rand() % 2 == 0) {
                add(storage, make_unique<Derived>());
            }
            else {
                add(storage, make_unique<Derived>());
            }
        }

        for (const auto& obj : storage) {
            obj->gg();
        }
    }
    catch (const length_error& e) {
        cerr << "Caught length_error: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        cerr << "Caught exception: " << e.what() << "\n";
    }

    return 0;
}
