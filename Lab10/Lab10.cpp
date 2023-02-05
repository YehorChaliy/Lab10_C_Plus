#include <iostream>
#include <math.h>
#include <locale.h>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

int i;

struct Elementary_Particles_str
{
	string particle_f;
	char group_f;
	double charge_f;
	float rest_mass_f;
};

class Elementary_Particles
{
private:
	string particle;
	char group;
	double charge;
	float rest_mass;
public:
	void set(string particle_f, char group_f, double charge_f, float rest_mass_f);
	void get(string particle_f, char &group_f, double &charge_f, float &rest_mass_f);
	void showtable(Elementary_Particles* arr, int n);
};

void Elementary_Particles::set(string particle_f, char group_f, double charge_f, float rest_mass_f)
{
	particle = particle_f;
	group = group_f;
	charge = charge_f;
	rest_mass = rest_mass_f;  
}

void Elementary_Particles::get(string particle_f, char& group_f, double& charge_f, float& rest_mass_f)
{
	particle = particle_f;
	group = group_f;
	charge = charge_f;
	rest_mass = rest_mass_f;
}

void Elementary_Particles::showtable(Elementary_Particles* arr, int n)
{
	cout << "----------------------------------------------------------" << endl;
	cout << "| " << "Элементарные частицы                                   |" << endl;
	cout << "|--------------------------------------------------------|" << endl;
	cout << "|";
	cout.width(12);
	cout << left << "Частица" << setw(4) << "|" << setw(9) << "Группа" << setw(4) << "|" << setw(9) << "Заряд" << setw(5) << "|" << setw(13) << "Масса покоя" << "|" << "\n";
	cout << "|--------------------------------------------------------|" << endl;
	while (n != NULL)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "|";
			cout.width(12);
			cout << left << arr[i].particle << setw(6) << "|" << setw(7) << arr[i].group << setw(6) << "|" << setw(7) << arr[i].charge << setw(8) << "|" << setw(10) << arr[i].rest_mass << "|" << "\n";
		}
		cout << "----------------------------------------------------------" << endl;
		break;
	}
}

void menu()
{
	cout << "1. Указать повторно данные." << endl;
	cout << "2. Вывести таблицу." << endl;
	cout << "3. Выход из программы." << endl;
	cout << "Выберите необходимую функцию: ";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
note:cout << "Введите количество элементарных частиц:" << endl;
	cin >> n;
	if (n < 1)
	{
		cout << "Ошибка! Введите натуральное число:" << endl;
		goto note;
	}

	Elementary_Particles* arr = new Elementary_Particles[n];
	for (i = 0; i < n; i++)
	{
		string particle_f;
		char group_f;
		double charge_f;
		float rest_mass_f;
		cout << "Укажите " << i + 1 << " частицу:" << endl;
		cout << "Укажите " << i + 1 << " группу:" << endl;
		cout << "Укажите " << i + 1 << " заряд:" << endl;
		cout << "Укажите " << i + 1 << " массу покоя:" << endl;
		cin >> particle_f;
		cin >> group_f;
		cin >> charge_f;
		cin >> rest_mass_f;
		arr[i].set( particle_f, group_f, charge_f, rest_mass_f);
		arr[i].get( particle_f, group_f, charge_f, rest_mass_f);
	}
	system("cls");

menu:menu();

	int m;
	cin >> m;
	system("cls");
	switch (m)
	{
	default:
		cout << "Ошибка! Выберите вариант из представленных!" << endl;
		system("cls");
		goto menu;
	case(1):
		goto note;
		system("cls");
		goto menu;
	case(2):
		arr->showtable(arr, n);
		cout << endl;
		goto menu;
	case(3):
		system("cls");
		cout << "Вы вышли из программы.";
		cout << endl;
		return 0;
	}
	delete[] arr;
	system("pause");
}