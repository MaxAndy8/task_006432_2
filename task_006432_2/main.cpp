#include <iostream>
#include <string>

class Engine
{
private:
    int horsepower;

public:
    Engine(int hp) : horsepower(hp) {}

    int getHorsepower() const
    {
        return horsepower;
    }
};

class Body
{
private:
    std::string color;

public:
    Body(std::string col) : color(col) {}

    std::string getColor() const
    {
        return color;
    }
};

class Wheel
{
private:
    int size;

public:
    Wheel(int s) : size(s) {}

    int getSize() const
    {
        return size;
    }
};

class Car
{
private:
    Engine engine;
    Body body;
    Wheel frontLeftWheel;
    Wheel frontRightWheel;
    Wheel rearLeftWheel;
    Wheel rearRightWheel;

public:
    // Конструктор класу Car
    Car(int hp, std::string col, int wheelSize)
        : engine(hp),
        body(col),
        frontLeftWheel(wheelSize),
        frontRightWheel(wheelSize),
        rearLeftWheel(wheelSize),
        rearRightWheel(wheelSize)
    {
    }

    // Конструктор копіювання
    Car(const Car& other)
        : engine(other.engine),
        body(other.body),
        frontLeftWheel(other.frontLeftWheel),
        frontRightWheel(other.frontRightWheel),
        rearLeftWheel(other.rearLeftWheel),
        rearRightWheel(other.rearRightWheel)
    {
    }

    // Метод для зміни кольору кузова
    void changeBodyColor(std::string newColor)
    {
        body = Body(newColor);
    }

    // Метод для виведення інформації про автомобіль
    void displayInfo() const
    {
        std::cout << "Характеристики автомобіля:\n";
        std::cout << "Двигун: " << engine.getHorsepower() << " к.с.\n";
        std::cout << "Кузов: " << body.getColor() << "\n";
        std::cout << "Розмір коліс: " << frontLeftWheel.getSize() << " дюймів\n";
    }
};

int main()
{
    system("chcp 1251>nul");

    // Створення автомобілю
    Car myCar(200, "червоний", 17);

    // Виведення інформації про автомобіль
    myCar.displayInfo();

    // Створення копії автомобілю і зміна кольору кузова
    Car myCarCopy = myCar;
    myCarCopy.changeBodyColor("синій");

    // Виведення інформації про копію автомобілю
    std::cout << "\nІнформація про копію автомобіля:\n";
    myCarCopy.displayInfo();

    return 0;
}
