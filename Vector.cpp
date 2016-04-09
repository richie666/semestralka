#include "Vector.h"
#include <cstdlib>
#include <cstring>
#include "DSRoutines.h"

using namespace DS;

Vector::Vector(size_t size) : 
	memory_(calloc(size, 1)),
	size_(size)
{
}

Vector::Vector(const Vector& other) :
	Vector(other.size_)
{
	memcpy(memory_, other.memory_, size_);
}

Vector::~Vector()
{
	free(memory_);
}

Structure* Vector::clone() const
{
	return new Vector(*this); //zdereferoval som smernik
}

Structure & Vector::operator=(const Structure & other)
{
	(*this) = (*dynamic_cast<const Vector*>(&other));
	return *this;
}

Vector& Vector::operator=(const Vector& other)
{
	size_ = other.size_;
	memory_ = realloc(memory_, size_);
	memcpy(memory_, other.memory_, size_);
	return *this;
}

bool Vector::operator==(const Vector& other) const
{
	return (size_ == other.size_) 
		&& (memory_, other.memory_, size_) == 0;
}

size_t Vector::size() const
{
	return size_;
}

byte& Vector::operator[](const int index)
{
	DSRoutines::rangeCheck(index, size_, true, &std::string("Index out of range!"));
	return *(reinterpret_cast<byte*>(memory_) + index);
}

byte Vector::operator[](const int index) const
{
	return *(byte*)memory_ + index; //zderefovanie
}

bool Vector::byteNthBitGet(int B, int n)
{
	return (*this)[B] & (1 << n); //bitove nasobenie
	//& nasobenie, ~ bitovy doplnok, ^ xor
}

byte Vector::byteNthBitTo0(int B, int n)
{
	return (*this)[B] &= ~(1 << n);
}

byte Vector::byteNthBitTo1(int B, int n)
{
	return (*this)[B] |= (1 << n);
}

byte Vector::byteNthBitToggle(int B, int n)
{
	return (*this)[B] ^= (1 << n);
}

byte& Vector::readBytes(const int index, const int count, byte& dest)
{
	DSRoutines::rangeCheck(index, size_, true, &std::string("Index out of range!"));
	// podobne ako if (index > size)
	DSRoutines::rangeCheck(index + count, size_, true, &std::string("Index out of range!"));
	memcpy(&dest, getByteAddress(index), count);
	return dest;
}

void DS::Vector::copy(const Vector& src, const int srcStartIndex, Vector& dest, const int destStartIndex, const int length)
{
	DSRoutines::rangeCheck(srcStartIndex, src.size_, true, &std::string("Index out of range!"));
	DSRoutines::rangeCheck(destStartIndex, dest.size_, true, &std::string("Index out of range!"));
	DSRoutines::rangeCheck(srcStartIndex + length, src.size_, true, &std::string("Index out of range!"));
	DSRoutines::rangeCheck(destStartIndex + length, dest.size_, true, &std::string("Index out of range!"));
					
	if (src == dest && srcStartIndex + length >= destStartIndex)
		memmove(dest.getByteAddress(destStartIndex), src.getByteAddress(srcStartIndex), length);
	else
		memcpy(dest.getByteAddress(destStartIndex), src.getByteAddress(srcStartIndex), length);
}

byte* DS::Vector::getByteAddress(const int index) const
{
	return (reinterpret_cast<byte*>(memory_) + index);
}
