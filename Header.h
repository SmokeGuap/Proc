#ifndef HEADER_H
#define HEADER_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//����� "������"
class Car {
    int Motor_power; //�������� ������
    double Fuel; //������ �������
public:
    void Set_Motor_power(int _Motor_power);
    int Get_Motor_power();

    void Set_Fuel(double _Fuel);
    double Get_Fuel();

    static Car* In_Car(ifstream& ifst); //������� ����� ���������� � ������
    virtual void In_Data(ifstream& ifst) = 0; //����� ����������� ������� ����� ����������
                                              //� ������, ��� ����� ���������� ���
                                              //������� ������ �����
    virtual void Out_Data(int Motor_power, double Fuel, ofstream& ofst) = 0; //����� ����������� ������� ������ ����������
                                              //� ������, ��� ����� ���������� ���
                                              //������� ������ �����
    virtual double Load_to_capacity_ratio(int Motor_power) = 0; //������� �������� ��������� ����� � ��������
    bool Compare(Car* Other); //������� ��������� ��������� ����� � ��������
    virtual void Out_Only_Truck(int Motor_power, double Fuel, ofstream& ofst); //������� ������ ������ ����������
protected:
    Car() {};
};

//����� "��������"
class Truck : public Car {
    int Load_cap; //����������������
public:
    void Set_Load_cap(int _Load_cap);
    int Get_Load_cap();

    void In_Data(ifstream& ifst); //������� ����� ���������� � ��������
    void Out_Data(int Motor_power, double Fuel, ofstream& ofst); //������� ������ ���������� � ���������
    double Load_to_capacity_ratio(int Motor_power); //������� �������� ��������� ����� � ��������
    void Out_Only_Truck(int Motor_power, double Fuel, ofstream& ofst); //������� ������ ������ ����������
    Truck() {};
};

//����� "�������"
class Bus : public Car {
    short int Passenger_cap; //��������������������
public:
    void Set_Passenger_cap(short int _Passenger_cap);
    short int Get_Passenger_cap();

    void In_Data(ifstream& ifst); //������� ����� ���������� �� ��������
    void Out_Data(int Motor_power, double Fuel, ofstream& ofst); //������� ������ ���������� �� ��������
    double Load_to_capacity_ratio(int Motor_power); //������� �������� ��������� ����� � ��������
    Bus() {};
};

//����� "�������� ����������"
class Passenger_car : public Car {
    short int Max_speed; //������������ ��������
public:
    void Set_Max_speed(short int _Max_speed);
    short int Get_Max_speed();

    void In_Data(ifstream& ifst); //������� ����� ���������� � �������� ����������
    void Out_Data(int Motor_power, double Fuel, ofstream& ofst); //������� ������ ���������� � �������� ����������
    double Load_to_capacity_ratio(int Motor_power); //������� �������� ��������� ����� � ��������
    Passenger_car() {};
};

//���� ����������
struct Node {
    Node* Next, * Prev; //��������� �� ��������� � ���������� �������� ����������
    Car* Cont; //��������� �� ������
};

//���������
class Container {
    Node* Head, *Tail; //��������� �� "������" � "�����" ����������
    int Len; //����������� ����������
public:
    void Set_Head(Node* _Head);
    Node* Get_Head();

    void Set_Tail(Node* _Tail);
    Node* Get_Tail();

    void Set_Len(int _Len);
    int Get_Len();

    void In(ifstream& ifst); //������� ����� �������� � ���������
    void Out(ofstream& ofst); //������� ������ �������� �� ����������
    void Clear(); //������� �������� ����������
    void Sort(); //������� ���������� ����������
    void Out_Only_Truck(ofstream& ofst); //������� ������ ������ ����������
    Container(); //�����������
    ~Container() { Clear(); } //����������
};

#endif //HEADER_H