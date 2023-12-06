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
    // ����������� ����� Car
    Car(int hp, std::string col, int wheelSize)
        : engine(hp),
        body(col),
        frontLeftWheel(wheelSize),
        frontRightWheel(wheelSize),
        rearLeftWheel(wheelSize),
        rearRightWheel(wheelSize)
    {
    }

    // ����������� ���������
    Car(const Car& other)
        : engine(other.engine),
        body(other.body),
        frontLeftWheel(other.frontLeftWheel),
        frontRightWheel(other.frontRightWheel),
        rearLeftWheel(other.rearLeftWheel),
        rearRightWheel(other.rearRightWheel)
    {
    }

    // ����� ��� ���� ������� ������
    void changeBodyColor(std::string newColor)
    {
        body = Body(newColor);
    }

    // ����� ��� ��������� ���������� ��� ���������
    void displayInfo() const
    {
        std::cout << "�������������� ���������:\n";
        std::cout << "������: " << engine.getHorsepower() << " �.�.\n";
        std::cout << "�����: " << body.getColor() << "\n";
        std::cout << "����� ����: " << frontLeftWheel.getSize() << " �����\n";
    }
};

int main()
{
    system("chcp 1251>nul");

    // ��������� ���������
    Car myCar(200, "��������", 17);

    // ��������� ���������� ��� ���������
    myCar.displayInfo();

    // ��������� ��ﳿ ��������� � ���� ������� ������
    Car myCarCopy = myCar;
    myCarCopy.changeBodyColor("����");

    // ��������� ���������� ��� ���� ���������
    std::cout << "\n���������� ��� ���� ���������:\n";
    myCarCopy.displayInfo();

    return 0;
}
