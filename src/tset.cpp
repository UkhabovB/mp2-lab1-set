// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"
#include <iostream>

using namespace std;

TSet::TSet(int mp) : BitField(-1)
{
	this.MaxPower=mp;
	TBitField BitField(mp);
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(-1)
{
	this.MaxPower=s.MaxPower;
	this.BitField=s.BitField;
}



// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(-1)
{
	this.MaxPower=bf.GetLength();
	this.BitField=bf
}

TSet::operator TBitField()
{
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
	return this.MaxPower;
}


int TSet::IsMember(const int Elem) const // элемент множества?
{
	
	if this.BitField.GetBit(Elem)=0;
    return 0;
	else 
	return 1;		
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
if Elem<=this.MaxPower	
 this.BitField.SetBit(Elem);
	else 
	cout << "Неверный номер элемента";
	
}


void TSet::DelElem(const int Elem) // исключение элемента множества
{
	if Elem<=this.MaxPower	
	this.BitField.ClrBit(Elem);
	else 
	cout << "Неверный номер элемента";
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
}

int TSet::operator==(const TSet &s) const // сравнение
{
    return 0;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
}

TSet TSet::operator+(const TSet &s) // объединение
{
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
}

TSet TSet::operator*(const TSet &s) // пересечение
{
}

TSet TSet::operator~(void) // дополнение
{
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
}
