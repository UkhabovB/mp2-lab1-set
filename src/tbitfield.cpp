// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"
#include "algorithm"
#define CreateBitfieldWithIncorrectLength 1
#define SetBitWithIncorrectNumber 2
#define ClrBitWithIncorrectNumber 3
#define GetBitWithIncorrectNumber 4



TBitField::TBitField(int len)
{
	if (len>0)
	{
		this->BitLen = len;
		this->MemLen = (len/32) + 1;
		this->pMem = new TELEM[this->MemLen];
		for (int i = 0; i < this->MemLen; i++)
		{
			(this->pMem[i]) = 0;
		}
	}
	else
		throw CreateBitfieldWithIncorrectLength;
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	this->BitLen = bf.BitLen;
	this->MemLen = bf.MemLen;
	this->pMem = new TELEM[this->MemLen];
	for (int i = 0; i < this->MemLen; i++)
	{
		this->pMem[i] = bf.pMem[i];
	}
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
	int pos = n%32;
	TELEM mask=1;
	for (int i=0; i<pos; i++)
	{
		mask*=2;
	}
	return mask;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	int i = this->BitLen;
	return i;
}

void TBitField::SetBit(const int n) // установить бит
{
	if ((n>=0) && (n < this->GetLength()))
	(this->pMem[GetMemIndex(n)]) |= GetMemMask(n);
	else 
		throw SetBitWithIncorrectNumber;
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if ((n >= 0) && (n < this->GetLength()))
		(this->pMem[GetMemIndex(n)]) &= (~GetMemMask(n));
	else
		throw ClrBitWithIncorrectNumber;
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if ((n >= 0) && (n < this->GetLength()))
	{
		if (((this->pMem[GetMemIndex(n)])&GetMemMask(n)) == 0)
			return 0;
		else
			return 1;
	}
	else
		throw GetBitWithIncorrectNumber;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	
		this->BitLen = bf.BitLen;
		
			this->MemLen = bf.MemLen;
			this->pMem = new TELEM[bf.MemLen];
			for (int i = 0; i < this->MemLen; i++)
				this->pMem[i] = bf.pMem[i];
			return *this;
	}


int TBitField::operator==(const TBitField &bf) const // сравнение
{
	int f=1;
	for (int i = 0; i<this->MemLen; i++)
{
		if (this->pMem[i] != bf.pMem[i])
	  f=0;
		break;
}
  return f;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
	int f=0;
	for (int i = 0; i<this->MemLen; i++)
{
		if (this->pMem[i] != bf.pMem[i])
	  f=1;
		break;
}
  return f;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
	TBitField bfres(this->BitLen);

	for (int i = 0; i < this->MemLen; i++)

	{
		bfres.pMem[i] = this->pMem[i];
	}

	for (int i = 0; i < bf.MemLen; i++)

	{
		bfres.pMem[i] |= bf.pMem[i];
	}
	return bfres;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
	int len = this->BitLen;

	if (BitLen < bf.BitLen)

	{

		len = bf.BitLen;

	}

	TBitField bfres(len);

	for (int i = 0; i < this->MemLen; i++)

	{

		bfres.pMem[i] = this->pMem[i];

	}

	for (int i = 0; i < bf.MemLen; i++)

	{

		bfres.pMem[i] &= bf.pMem[i];

	}

	return bfres;
}

TBitField TBitField::operator~(void) // отрицание
{
	int len = this->BitLen;
	TBitField bfres(len);
	for (int i = 0; i < this->GetLength(); i++)
	{
		if (this->GetBit(i) == 0)
		bfres.SetBit(i);
		else
			bfres.ClrBit(i);
	}
	return bfres;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{	
	for (int i=0; i<bf.GetLength(); i++)
		{
		bf.SetBit(i);
			istr >> bf;
		}	
	return istr;
}
ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
		
		for (int i=0; i<bf.GetLength(); i++)
		{
			ostr << bf.GetBit(i);
		}
		return ostr;
}
