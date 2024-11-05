#include <iostream>
#include <memory>
#include <string>
#include <windows.h>
using namespace std;

// Базовий клас для транспорту
class Transport {
public:
    virtual void deliver() const = 0; // Віртуальний метод для доставки
    virtual ~Transport() = default;
};

// Клас для автомобіля
class Car : public Transport {
public:
    void deliver() const override {
        cout << "Доставка автомобілем" << endl;
    }
};

// Клас для велосипеда
class Bike : public Transport {
public:
    void deliver() const override {
        cout << "Доставка велосипедом" << endl;
    }
};

// Базовий клас для фабрики транспорту
class TransportFactory {
public:
    virtual unique_ptr<Transport> createTransport() const = 0; // Метод для створення об'єкта транспорту
    virtual ~TransportFactory() = default;
};

// Фабрика для створення автомобілів
class CarFactory : public TransportFactory {
public:
    unique_ptr<Transport> createTransport() const override {
        return make_unique<Car>();
    }
};

// Фабрика для створення велосипедів
class BikeFactory : public TransportFactory {
public:
    unique_ptr<Transport> createTransport() const override {
        return make_unique<Bike>();
    }
};

// Функція, яка використовує фабрику для доставки
void deliverGoods(const TransportFactory& factory) {
    auto transport = factory.createTransport();
    transport->deliver();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    CarFactory carFactory;
    BikeFactory bikeFactory;

    cout << "Використання автомобільної фабрики:" << endl;
    deliverGoods(carFactory);

    cout << "Використання велосипедної фабрики:" << endl;
    deliverGoods(bikeFactory);

}

