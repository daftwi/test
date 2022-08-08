// 2yer2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>
#include<conio.h>
#include<iomanip>
#include<mutex>
#include<thread>
#include"Drevo.h"
using namespace std;


int main()
{
 	Drevo<int> a;
	//std::thread t1(&Drevo<int>::addtread, &a, 5);	t1.join();
	a << 4;
	//a.print();
	//b.add(3);
	//std::thread t2(&Drevo<int>::operator<<, &b, 2);	t2.join();
	//Drevo<int>c = b;
	//std::thread t3(&Drevo<int>::addtree, &a, c);	t3.join();
	//b.print();
	//a.print();
	//std::thread t4(&Drevo<int>::operator<<, &a, 1);	t4.join();
	//a.print();
	//std::thread t5(&Drevo<int>::del, &a, 2);	t5.join();
	//a.print();
	//std::thread t6(&Drevo<int>::clear, &a);	t6.join();
	//a.print();
	//std::thread t7(&Drevo<int>::addtree, &a, c);	t7.join();
	//a.print();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
