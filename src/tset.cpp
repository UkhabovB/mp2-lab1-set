// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"
#include <iostream>
#include "algorithm"
#define IncorrectNumber 1

using namespace std;

TSet::TSet(int mp) : BitField(mp)
{
	this->MaxPower=mp;
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.BitField)
{
	this->MaxPower = s.MaxPower;
}


// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf)
{
	this->MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
	TBitField bf=(this->BitField);
	return bf;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
	return this->MaxPower;
}


int TSet::IsMember(const int Elem) const // элемент множества?
{
	
	if (this->BitField.GetBit(Elem)==0)
    return 0;
	else 
	return 1;		
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	if (Elem <= this->MaxPower)
		this->BitField.SetBit(Elem);
	else
		throw IncorrectNumber;
	
}


void TSet::DelElem(const int Elem) // исключение элемента множества
{
	if (Elem<=this->MaxPower)
	this->BitField.ClrBit(Elem);
	else 
	throw IncorrectNumber;
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
	this->MaxPower=s.MaxPower;
	this->BitField=s.BitField;
	return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
	if ((this->MaxPower==s.MaxPower)&&(this->BitField==s.BitField))
		return 1;
	else
    return 0;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
	if ((this->MaxPower!=s.MaxPower)||(this->BitField!=s.BitField))
		return 1;
	else
    return 0;
}

TSet TSet::operator+(const TSet &s) // объединение
{
	
	TSet sres(max(this->MaxPower, s.MaxPower));
	sres.BitField =this->BitField|s.BitField;
	return sres;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	this->InsElem(Elem);
	return *this;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	this->DelElem(Elem);
	return *this;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
	TSet sres(this->MaxPower);
	sres=this->BitField&s.BitField;
	return sres;
}

TSet TSet::operator~(void) // дополнение
{
	this->BitField=(~(this->BitField));
	return *this;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
	istr >> s.BitField;
	return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
	ostr << s.BitField;
	return ostr;
}
