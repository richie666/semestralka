#pragma once

#include "List.h"
#include "Iterator.h"
#include "Array.h"
#include "Structure.h"

namespace DS
{
	template<typename T>
	bool functionEqual(const T& a, const T& b) {
		return a == b;
	}
	template<typename T>
	class ArrayList :
		public List<T>
	{
	protected:
		class ArrayListIterator :
			//vnorena trieda ArrayList-u
			public StructureIterator<T>
		{
		public:
			ArrayListIterator(const ArrayList<T>* arrayList, int pos);
			bool operator!=(const StructureIterator<T>& other) const override;
			const T& operator*() const override;
			StructureIterator<T>& operator++() override;

			StructureIterator* clone() const override;
		private:
			const ArrayList<T>* iteratesOver_;
			int index_;
		};
	public:

		ArrayList(const size_t initialCapacity = 2, const EqualityFunction<T>& equalityFunction = functionEqual);
		ArrayList(const ArrayList<T>& other);
		~ArrayList() override;

		Structure* clone() const override;
		Structure& operator=(const Structure& other) override;
		List<T>& operator=(const List<T>& other) override;
		ArrayList<T>& operator=(const ArrayList<T>& other);

		size_t size() const override;
		T& operator[](const int index) override;
		const T& operator[](const int index) const override;

		void add(const T& data) override;
		void insert(const T& data, const int index) override;
		bool tryRemove(const T& data) override;
		T& removeAt(const int index) override;
		int getIndexOf(const T& data) override;
		void clear() override;

		void shrinkToFit();

		Iterator<T> begin() const override;
		Iterator<T> end() const override;
	private:
		size_t size_;
		Array<T>* array_;
		size_t minCapacity_;

		void ensureCapacity();
		void changeCapacity(size_t newCapacity);
	};

	template<typename T>
	ArrayList<T>::ArrayList(const size_t initialCapacity, const EqualityFunction<T>& equalityFunction) :
		List<T>(equalityFunction),
		size_(initialCapacity),
		array_(new Array<T>(initialCapacity * sizeof(T))),
		minCapacity_(5)
	{
	}

	template<typename T>
	ArrayList<T>::ArrayList(const ArrayList<T>& other) :
		List<T>(other),
		size_(other.size_),
		array_(new Array<T>(*other.array_)),
		minCapacity_(other.minCapacity_)
	{
	}

	template<typename T>
	ArrayList<T>::~ArrayList()
	{
		delete array_;
		size_ = 0;
	}

	template<typename T>
	Structure* ArrayList<T>::clone() const
	{
		return	new ArrayList<T>(*this);
	}

	template<typename T>
	Structure& ArrayList<T>::operator=(const Structure & other)
	{
		return (*this) = dynamic_cast<const ArrayList<T>&>(other);
	}

	template<typename T>
	List<T>& ArrayList<T>::operator=(const List<T>& other)
	{
		return (*this) = dynamic_cast<const ArrayList<T>&>(other);
	}

	template<typename T>
	ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other)
	{
		if (this != &other) {

			List<T>::operator=(other);
			if (array_->size() != other.array_->size()) {


				changeCapacity(other.array_->size());
			}

			size_ = other.size_;
			*array_ = *other.array_;

			return *this;
		}
		else {
			return *this;
		}
	}

	template<typename T>
	size_t ArrayList<T>::size() const
	{
		return size_;
	}

	template<typename T>
	T& ArrayList<T>::operator[](const int index)
	{
		DSRoutines::rangeCheck(index, size_, true);
		return (*array_)[index];
	}

	template<typename T>
	const T& ArrayList<T>::operator[](const int index) const
	{
		DSRoutines::rangeCheck(index, size_, true);
		return (*array_)[index];
	}

	template<typename T>
	void ArrayList<T>::add(const T& data)
	{
		ensureCapacity();
		(*array_)[size_++] = data;

	}

	template<typename T>
	void ArrayList<T>::insert(const T& data, const int index)
	{
		DSRoutines::rangeCheck(index, size_ + 1, true, &std::string("Index in ArrayList out of range!"));
		ensureCapacity();
		Array<T>::copy(*array_, index, *array_, index + 1, size_ - index);
		(*array_)[index] = data;
		size_++;

	}

	template<typename T>
	bool ArrayList<T>::tryRemove(const T& data)
	{
		int index = getIndexOf(data);
		if (index >= 0) {
			removeAt(index);
			return true;
		}
		else
			return false;
	}

	template<typename T>
	T& ArrayList<T>::removeAt(const int index)
	{
		T pom = (*array_)[index];
		Array<T>::copy(*array_, index + 1, *array_, index, size_ - index - 1);
		size_--;
		return pom;
	}

	template<typename T>
	int ArrayList<T>::getIndexOf(const T& data)
	{
		for (int i = 0; i < size_; i++) {
			if (equalityFunction_((*array_)[i], data))
				return i;
		}
		return -1;
	}

	template<typename T>
	void ArrayList<T>::clear()
	{
		changeCapacity(0);
	}

	template<typename T>
	void ArrayList<T>::shrinkToFit()
	{
		if (size_ > minCapacity_) changeCapacity(size_);
	}

	template<typename T>
	Iterator<T> ArrayList<T>::begin() const
	{
		return Iterator<T>(ArrayListIterator(this, 0));
	}

	template<typename T>
	Iterator<T> ArrayList<T>::end() const
	{
		return Iterator<T>(ArrayListIterator(this, size_));
	}

	template<typename T>
	inline void ArrayList<T>::ensureCapacity()
	{
		if (!DSRoutines::rangeCheck(size_, array_->size(), false))
			this->changeCapacity(size_ + 10);
	}

	template<typename T>
	void ArrayList<T>::changeCapacity(size_t newCapacity)
	{
		Array<T>* newArray = new Array<T>(newCapacity);
		Array<T>::copy(*array_, 0, *newArray, 0, size_);
		delete array_;
		array_ = newArray;

	}

	template<typename T>
	ArrayList<T>::ArrayListIterator::ArrayListIterator(const ArrayList<T>* arrayList, int pos) :
		iteratesOver_(arrayList),
		index_(pos)
	{
	}

	template<typename T>
	bool ArrayList<T>::ArrayListIterator::operator!=(const StructureIterator<T>& other) const
	{
		const ArrayListIterator& pom = dynamic_cast<const ArrayListIterator&>(other);
		return index_ != pom.index_;

	}

	template<typename T>
	const T& ArrayList<T>::ArrayListIterator::operator*() const
	{
		return (*iteratesOver_)[index_];
	}

	template<typename T>
	StructureIterator<T>& ArrayList<T>::ArrayListIterator::operator++()
	{
		index_++;
		return *this;
	}

	template<typename T>
	StructureIterator<T> * ArrayList<T>::ArrayListIterator::clone() const
	{
		return new ArrayListIterator(iteratesOver_, index_);
	}

}