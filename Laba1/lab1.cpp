#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    // Создаем массив динамически
    int* arr = new int[n];

    // Заполняем массив
    cout << "Введите " << n << " целых чисел: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Вывод содержимого массива
    cout << "Содержимое массива: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Вывод адреса начала массива
    cout << "Адрес начала массива: " << static_cast<void*>(arr) << endl;

    // Вывод расстояния каждого элемента от начала массива (в количестве элементов)
    cout << "Расстояние каждого элемента от начала массива: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Элемент " << i
            << " находится по адресу " << static_cast<void*>(&arr[i])
            << " (смещение " << i << " элементов от начала массива)" << endl;
    }

    // Освобождение памяти
    delete[] arr;

    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Перечисление для типа книги
enum BookType { FICTION, TECHNICAL };

// Класс Book, представляющий книгу
class Book {
private:
    string author;
    string title;
    BookType type;

public:
    // Пользовательский конструктор
    Book(string author, string title, BookType type) {
        if (author.empty() || title.empty()) {
            throw invalid_argument("Книга должна иметь автора и название.");
        }
        this->author = author;
        this->title = title;
        this->type = type;
    }

    // Метод для вывода информации о книге
    void displayInfo() const {
        cout << "Автор: " << author << ", Название: " << title
            << ", Тип: " << (type == FICTION ? "Художественная" : "Техническая") << endl;
    }
};

// Класс Library, представляющий библиотеку
class Library {
private:
    vector<Book> books;

public:
    // Метод для добавления книги в библиотеку
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Метод для вывода информации обо всех книгах
    void displayBooks() const {
        if (books.empty()) {
            cout << "В библиотеке нет книг." << endl;
        }
        else {
            cout << "Книги в библиотеке:" << endl;
            for (const auto& book : books) {
                book.displayInfo();
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Library library;

    // Добавление книг в библиотеку
    try {
        library.addBook(Book("Лев Толстой", "Война и мир", FICTION));
        library.addBook(Book("Исаак Ньютон", "Математические начала", TECHNICAL));
        library.addBook(Book("Фёдор Достоевский", "Преступление и наказание", FICTION));
        library.addBook(Book("Брайан Керниган", "Язык программирования C", TECHNICAL));

        // Вывод информации обо всех книгах в библиотеке
        library.displayBooks();
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}

