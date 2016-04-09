#pragma once

#include "Structure.h"
#include "DSRoutines.h"
#include "Vector.h"
#include <stdexcept>

namespace DS
{

	template<typename T>
	class Array :
		public Structure
	{
	public:
		Array(const size_t size);
		Array(const Array<T>& other);
		~Array() override;

		Structure* clone() const override;
		Structure& operator=(const Structure& other) override;
		Array<T>& operator=(const Array<T>& other);
		bool operator== (const Array<T>& other) const;

		size_t size() const;
		T& operator[](const int index);
		const T operator[](const int index) const;

		static void copy(const Array<T>& src, const int srcStartIndex, Array<T>& dest, const int destStartIndex, const int length);

	private:
		size_t size_;
		Vector* vector_;

	private:
		int mapArrayIndexToVectorIndex(const int index) const;
	};

	template<typename T>
	Array<T>::Array(const size_t size) :
		size_(size),
		vector_(new Vector(size_*sizeof(T)))
	{
	}

	template<typename T>
	Array<T>::Array(const Array<T>& other) :
		size_(other.size_),
		vector_(new Vector(*other.vector_))
	{
	}

	template<typename T>
	Array<T>::~Array()
	{
		delete vector_;
		size_ = 0;
	}

	template<typename T>
	Structure* Array<T>::clone() const
	{
		return new Array<T>(*this);
	}

	template<typename T>
	Structure& Array<T>::operator=(const Structure& other)
	{
		return (*this) = dynamic_cast<const Array<T>&>(other);
	}

	template<typename T>
	Array<T>& Array<T>::operator=(const Array<T>& other)
	{
		if (this != &other) {
			if (size_ == other.size_) {
				vector_ = other.vector_;
			}
			else {
				throw std::invalid_argument("Not equal size of vectors.");
			}
		}
		return *this;
	}

	template<typename T>
	inline bool Array<T>::operator==(const Array<T>& other) const
	{
		return (*vector_, *other.vector_, size_);
	}

	template<typename T>
	size_t Array<T>::size() const
	{
		return size_;
	}

	template<typename T>
	T& Array<T>::operator[](const int index) //vracia pamatove miesto
	{
		DSRoutines::rangeCheck(index, size_, true, &std::string("Index in array out of range!"));

		int indexVector = mapArrayIndexToVectorIndex(index);
		return *(reinterpret_cast<T*>(vector_->getByteAddress(indexVector)));
	}

	template<typename T>
	const T Array<T>::operator[](const int index) const //vracia kopiu 
	{
		DSRoutines::rangeCheck(index, size_, true, &std::string("Index in array out of range!"));

		int indexVector = mapArrayIndexToVectorIndex(index);
		byte* ptr = (vector_->getByteAddress(indexVector));
		return *(reinterpret_cast<T*>ptr);
	}

	template<typename T>
	void Array<T>::copy(const Array<T>& src, const int srcStartIndex, Array<T>& dest, const int destStartIndex, const int length)
	{
		DSRoutines::rangeCheck(srcStartIndex, src.size_, true, &std::string("Index in array out of range!"));
		DSRoutines::rangeCheck(destStartIndex, dest.size_, true, &std::string("Index in array out of range!"));
		DSRoutines::rangeCheck(srcStartIndex + length, src.size_, true, &std::string("Index in array out of range!"));
		DSRoutines::rangeCheck(destStartIndex + length, dest.size_, true, &std::string("Index in array out of range!"));
		DSRoutines::rangeCheck(length, dest.size_, true, &std::string("Index out of range!"));

		Vector::copy(*src.vector_, src.mapArrayIndexToVectorIndex(srcStartIndex),
			*dest.vector_, dest.mapArrayIndexToVectorIndex(destStartIndex), length * sizeof(T));
	}

	template<typename T>
	inline int Array<T>::mapArrayIndexToVectorIndex(const int index) const
	{
		DSRoutines::rangeCheck(index, size_, true, &std::string("Index out of size."));
		return index*sizeof(T);
	}
}