#include <iostream>
#include <stdlib.h>
#include <locale>
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#define fflush while (getchar() != '\n')
#define AMOUNTCAR 3 

class car {
private:
    std::string marka; //Марка
    std::string model; //Модель
    float engine; //Объём двигателя
    int power; //Кол-во л.с.
    std::string transmission; //Коробка передач
    std::string color; //Цвет машины
    int year; //Год автомобиля
    int price; //Цена:
    static int count;
    std::string* people; //владельцы
    int countPeople; //кол-во владельцев
public:
    //Конструктор без параметров
    car() {
        marka = " ";
        model = " ";
        engine = 0;
        power = 0;
        transmission = " ";
        color = " ";
        year = 0;
        price = 0;
        countPeople = 0;
        count++;
    }
    //Конструктор с одним параметром
    car(std::string _marka) {
        marka = " ";
        marka = _marka;
        model = " ";
        engine = 0;
        power = 0;
        transmission = " ";
        color = " ";
        year = 0;
        price = 0;
        countPeople = 0;
        count++;
    }
    //Конструктор со всеми параметрами
    car(std::string _marka, std::string _model, float _engine, int _power, std::string _transmission, std::string _color, int _year, int _price, int _countPeople, std::string* _people) {
        marka = " ";
        model = " ";
        marka = _marka;
        model = _model;
        engine = _engine;
        power = _power;
        transmission = " ";
        color = " ";
        transmission = _transmission;
        color = _color;
        year = _year;
        price = _price;
        countPeople = _countPeople;
        //Динамический обьект
        people = new std::string[countPeople];
        for (int i = 0; i < countPeople; i++) {
            people[i] = _people[i];
        }
        count++;
    }

    //Глубокий конструктор копирования
    car(car& a) {
        marka = " ";
        model = " ";
        marka = a.marka;
        model = a.model;
        engine = a.engine;
        power = a.power;
        transmission = " ";
        color = " ";
        transmission = a.transmission;
        color = a.color;
        year = a.year;
        price = a.price;
        countPeople = a.countPeople;
        //Динамический обьект
        people = new std::string[countPeople];
        for (int i = 0; i < countPeople; i++) {
            people[i] = a.people[i];
        }
        count++;
    }
    //Деструктор
    ~car() {
        car::RemoveItem();
    }
    void Read() {
        printf("Введите марку машины: ");
        std::cin >> marka;
        printf("Введите модель машины: ");
        std::cin >> model;
        printf("Введите объём двигателя: ");
        scanf_s("%f", &engine);
        fflush;
        printf("Введите кол-во л.с.: ");
        scanf_s("%d", &power);
        fflush;
        printf("Введите тип трансмиссии(коробка передач): ");
        std::cin >> transmission;
        printf("Введите цвет автомобиля: ");
        std::cin >> color;
        printf("Введите год автомобиля: ");
        scanf_s("%d", &year);
        fflush;
        printf("Введите цену за данный автомобиль: ");
        scanf_s("%d", &price);
        fflush;
        printf("\n");
    }
    void Display() {
        if (marka != " ")std::cout << marka << std::endl;
        if (model != " ") std::cout << model << std::endl;
        if (engine != 0) std::cout << engine << std::endl;
        if (power != 0)std::cout << power << std::endl;
        if (transmission != " ")std::cout << transmission << std::endl;
        if (color != " ")std::cout << color << std::endl;
        if (year != 0)std::cout << year << std::endl;
        if (price != 0)std::cout << price << std::endl;
        if (countPeople != 0) {
            for (int i = 0; i < countPeople; i++)
                std::cout << people[i] << " ";
        }
        std::cout << std::endl << std::endl;

    }
    void Add(car object) {
        int sum = price + object.price;
        if (sum > 350000) {
            marka = "Ferrari"; model = "F430"; engine = 5.0; power = 440; transmission = "Автомат", color = "Красный", year = 2018; price = 350000;
        }
        else if (sum > 250000) {
            marka = "Nissan"; model = "Skyline"; engine = 3.0; power = 270; transmission = "Автомат", color = "Серебристый", year = 2004; price = 250000;
        }
        else if (sum > 150000) {
            marka = "ВАЗ"; model = "2101"; engine = 1.0; power = 60; transmission = "Механика", color = "Красный", year = 1988; price = 150000;
        }
        else {
            marka = "ЗАЗ"; model = "966"; engine = 0.8; power = 40; transmission = "Механика", color = "Синий", year = 1966; price = 0;
        }
    }
    void Sale(int& _balance) {
        _balance += price;
    }
    void Paint() {
        std::string newColor;
        std::cout << "\nСтарый цвет: " << color << "\tНовый цвет: ";
        std::cin >> newColor;
        color = newColor;
    }
    int* getPrice() {
        return &price;
    }
    int setPrice(int* price) {
        return *price;
    }
    int* getPower() {
        return &power;
    }
    int& setPower(int* power) {
        return *power;
    }

    //Дружественная функция
    friend int getYear(car& CAR);
    //Перегрузка операторов '+', '++'
    car& operator++(); // версия префикс
    car operator++(int); // версия постфикс

    static void RemoveItem() {
        count--;
    }

    static int infoCount() {
        return count;
    }
    car& operator= (const car& a)
    {
        marka = " ";
        model = " ";
        marka = a.marka;
        model = a.model;
        engine = a.engine;
        power = a.power;
        transmission = " ";
        color = " ";
        transmission = a.transmission;
        color = a.color;
        year = a.year;
        price = a.price;
        countPeople = a.countPeople;
        people = new std::string[countPeople];
        for (int i = 0; i < countPeople; i++) {
            people[i] = a.people[i];
        }
        return *this;
    }
    void showRate() {
        try {
            if (price <= 0) throw price;
            std::cout << year * 200 / price;
        }
        catch (int price) {
            std::cout << "Цена автомобиля " << price << ", меньше или равно 0" << std::endl;
        }
    }
};

car& car::operator++() {
    power++;
    return *this;
}

car car::operator++(int) {
    engine++;
    return *this;
}

car operator+(car& a, car& b) {
    car c = a;
    c.Add(b);
    return c;
}

int getYear(car& CAR) {
    return CAR.year;
}

int car::count = 0;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    system("color 70");

    int balance = 0;

    //Динамический обьект
    std::string people[2] = { "vova", "petya" };
    //Обьект со всеми параметрами
    car toyota("toyota", "carib", 1.3, 83, "автомат", "зелёный", 1998, 100000, 2, people);
    toyota.Display();
    //Обьект с одним параметром
    car bmw("bmw");
    bmw.Display();
    //Обьект без параметров
    car nissan;
    nissan.Display();
    nissan.showRate();
}