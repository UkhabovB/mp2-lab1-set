// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"
#include "algorithm"

TBitField::TBitField(int len)
{
	this->BitLen=len;
	this->MemLen = len / 32 + 1;
	this->pMem = new TELEM[this->MemLen];
	for (int i = 0; i<this->MemLen; i++)
	{
		this->pMem[i] = 0;
	}
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	this->BitLen = bf.BitLen;
	this->MemLen = bf.MemLen;
	this->pMem = bf.pMem;
}

TBitField::~TBitField()
{
	delete[]this->pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	return n/32;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	TELEM mask=1;
	for (int i=0; i<n; i++)
	{
		mask*=2;
	}
	return mask;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return this->BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	(this->pMem[GetMemIndex(n)]) |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
	(this->pMem[GetMemIndex(n)]) &= (~GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if (((this->pMem[GetMemIndex(n)])&GetMemMask(n)) == 0);
  return 0;
  else
  return 1;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	this->BitLen = bf.BitLen;
	this->MemLen = bf.MemLen;
	for (int i=0; i<bf.GetLength; i++)
		this->pMem[i] = bf.pMem[i];
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
	int f=1;
	for (int i = 0; i<max(this->MemLen, bf.MemLen); i++)
{
		if (this->pMem[i] != bf.pMem[i])
	  f=0;
}
  return f;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
	int f=0;
	for (int i = 0; i<max(this->MemLen, bf.MemLen); i++)
{
		if (this->pMem[i] != bf.pMem[i])
	  f=1;
}
  return f;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
	bf.MemLen = this->MemLen = max(this->MemLen, bf.MemLen);
	for (int i = 0; i < this->MemLen; i++)
		this->pMem[i] | bf.pMem[i];
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
	bf.MemLen = this->MemLen = max(this->GetLength(), bf.GetLength());
	for (int i = 0; i<this->MemLen; i++)
	{
		this->pMem[i] & bf.pMem[i];
	}
}

TBitField TBitField::operator~(void) // отрицание
{
	for (int i = 0; i<(this->GetLength() / 32 + 1; i++)
	{
		~(this->pMem[i]);
	}
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{	
	for (int i=0; i<bf.GetLength; i++)
		{
		bf.SetBit(i);
			istr >> bf;
		}	
}
ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
		
		for (int i=0; i<bf.GetLength; i++)
		{
			ostr << bf.GetBit(i);
		}
}
