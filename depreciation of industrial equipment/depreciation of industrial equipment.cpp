// depreciation of industrial equipment.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
using namespace std;

class Factory {
protected:
    string name;
    string manager;
    int count_workshops = 0;
    int count_workers = 0;

public:
    Factory() {
        cout << "Введите название завода: ";
        getline(cin, name);
        cin.ignore(32767, '\n');
        cout << endl;

        cout << "Введите ФИО директора завода: ";
        getline(cin, manager);
        cin.ignore(32767, '\n');
        cout << endl;

        cout << "Введите количество цехов: ";
        cin >> count_workshops;
        cout << endl;

        cout << "Введите количество рабочих на заводе: ";
        cin >> count_workers;
        cout << endl;
    }
};
class Dempartment:public Factory {
protected:
    string name_department;
    string products;
    int start_blanks = 0;
    int blanks = 0;
    int quality = 0;
    int defect = 0;

public:
    Dempartment() :Factory() {
        cout << "Введите продукт для изготовления: ";
        getline(cin, products);
        cin.ignore(32767, '\n');
        cout << endl;

        cout << "Введите количество пустых заготовок: ";
        cin >> start_blanks;
        cout << endl;

        cout << "Введите количество остальных заготовок: ";
        cin >> blanks;
        cout << endl;


        cout << "Введите процент дефектов продуктов: ";
        cin >> defect;
        cout << endl;

        cout << "Оцените качество продукта от 1 до 10: ";
        cin >> quality;
        cout << endl;
  
    }

};
class Type_of_machine:public Dempartment {
protected:
    string type;
public:
    Type_of_machine() :Dempartment(){
        cout << "Введите предмет для амортизации: ";
        cin >> type;
        cout << endl;

   }

};
class Machine :public Type_of_machine {
private:
    int count = 2;
    int subaccount = 0;
    int inventory_number = 0;
    int cost = 0;
    int annual_depreciation = 0;
    int month_of_use = 0;
    int residual_value = 0;
    int depreciation_for_the_period = 0;
    int likvidation_cost = 0;
    int spi = 0;
    int month = 0;
    int beginning_of_the_period = 0;
    int depreciation_for_the_year = 0;
public:
    Machine() :Type_of_machine() {
            cout << "Введите субсчет: ";
            cin >> subaccount;
            cout << endl;

            cout << "Введите инвентарный номер: ";
            cin >> inventory_number;
            cout << endl;

            cout << "Введите стоимость объекта: ";
            cin >> cost;
            cout << endl;

            cout << "Введите ликвидационную стоимость объекта: ";
            cin >> likvidation_cost;
            cout << endl;

            cout << "Введите (СПИ) срок полезного использования объекта: ";
            cin >> spi;
            cout << endl;

            cout << "Количество месяцев полезного испольовния: ";
            cin >> month;
            cout << endl;
    }

    void lineal_depreciation_file_output() {
        ofstream fout("depreciation_info.txt");
        int year = 0;
        cout << "Введите год расчета амортизации: ";
        cin >> year;
        cout << endl;
        if (!fout) {
            cerr << "Файл не открывается";
            exit(1);
        }
        else {
            depreciation_for_the_year = (cost - likvidation_cost) / spi;
            beginning_of_the_period = cost - depreciation_for_the_period;
            depreciation_for_the_period = (depreciation_for_the_year / 12) * month;
            fout << "\t\t\t\t\t\t\tРозрахунок амортизації засобів(крім інших необоротних матеріальних активів)" << endl;
            fout << "\t\t\t\t\t\t\t\t\t\t\tза " << year << " рік" << endl;
            fout << endl;
            fout << "\t\t\t\t\t\t\tCубра-" << "\t\t\t" << this->subaccount << endl << "\t\t\t\t\t\t\tхунок" << endl;
            fout << endl;
            fout << "\t\t\t\t\t\t\tІнвентар-" << "\t\t" << this->inventory_number << endl << "\t\t\t\t\t\t\tний номер" << endl;
            fout << endl;
            fout << "\t\t\t\t\t\t\tНазва об'єкта" << "\t\t" << this->type << endl;
            fout << endl;
            fout << "\t\t\t\t\t\t\tВартість" << "\t\t" << this->cost << endl << "\t\t\t\t\t\t\tяка" << endl << "\t\t\t\t\t\t\tамортизується" << endl;
            fout << endl;
            fout << "\t\t\t\t\t\t\tРічна" << "\t\t\t" << this->depreciation_for_the_year << endl << "\t\t\t\t\t\t\tcума" << endl << "\t\t\t\t\t\t\tаморти-" << endl << "\t\t\t\t\t\t\tзації" << endl;
            fout << endl;
            fout << "\t\t\t\t\t\t\tКількість міся-" << "\t\t" << this->month << endl << "\t\t\t\t\t\t\tців корисного" << endl << "\t\t\t\t\t\t\tвикористання" << endl;
            fout << endl;
            fout << "\t\t\t\t\t\t\tСумма" << "\t\t\t" << this->beginning_of_the_period << endl << "\t\t\t\t\t\t\tзносу" << endl << "\t\t\t\t\t\t\tна початок" << endl << "\t\t\t\t\t\t\tперіоду" << endl;
            fout << endl;
            fout << "\t\t\t\t\t\t\tСумма" << "\t\t\t" << this->depreciation_for_the_period << endl << "\t\t\t\t\t\t\tнарахованої" << endl << "\t\t\t\t\t\t\tамортизації" << endl << "\t\t\t\t\t\t\tза період" << endl;
        }
    }
    void console_output() {
        cout << "Название завода: " << this->name << endl;
        cout << "Директор: " << this->manager << endl;
        cout << "Количество цехов: " << this->count_workshops << endl;
        cout << "Количество рабочих: " << this->count_workers << endl;
        cout << "Продукт для изготовления: " << this->products << endl;
        cout << "Количество пустых заготовк: " << this->start_blanks << endl;
        cout << "Количество остальных заготовок: " << this->blanks << endl;
        cout << "Процент дефектов: " << this->defect << endl;
        cout << "Качество продукта: " << this->quality << endl;
        cout << "Предмет для амортизации: " << this->type << endl;
        cout << "Субсчет: " << this->subaccount << endl;
        cout << "Инвентарный номер: " << this->inventory_number << endl;
        cout << "Стоимость станка: " << this->cost << endl;
        cout << "СПИ: " << this->spi << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Machine m1;
    m1.lineal_depreciation_file_output();
    m1.console_output();
    return 0;
}
