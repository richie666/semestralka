#pragma once

#include "List.h"
#include "StructureItem.h"
#include "Structure.h"

namespace DS
{

	template<typename T>
	class LinkedList :
		public List<T>
	{
	protected:
		class LinkedListIterator :
			public StructureIterator<T>
		{
		public:
			LinkedListIterator(const LinkedItem<T>* item);

			bool operator!=(const StructureIterator<T>& other) const override;
			const T& operator*() const override;
			const StructureIterator<T>& operator++() override;

			StructureIterator<T>* clone() const override;
		private:
			// atributy
			const LinkedItem<T>* current_;

		};

	public:
		LinkedList(const EqualityFunction<T>& equalityFunction = functionEqual);
		LinkedList(const LinkedList<T>& other);
		~LinkedList() override;

		Structure* clone() const override;
		Structure& operator=(const Structure& other) override;
		List<T>& operator=(const List<T>& other) override;
		LinkedList<T>& operator=(const LinkedList<T>& other);

		size_t size() const override;
		T& operator[](const int index) override;
		const T& operator[](const int index) const override;

		void add(const T& data) override;
		void insert(const T& data, const int index) override;
		bool tryRemove(const T& data) override;
		T& removeAt(const int index) override;
		int getIndexOf(const T& data) override;
		void clear() override;

		Iterator<T> begin() const override;
		Iterator<T> end() const override;
	private:
		// atributy
		size_t size_;
		LinkedItem<T>* first_; //smernik na zaciatok - LinkedItem<T> je akoby gulicka
		LinkedItem<T>* last_; //smernik na koniec

		LinkedItem<T>* getLinkedItemAt(const int index) const;
	};

	template<typename T>
	LinkedList<T>::LinkedList(const EqualityFunction<T>& equalityFunction) :
		List<T>(equalityFunction), //equalityFunction ma na starosti trieda List<T>
		size_(0), //na zaciatku je LinkedList prazdny
		first_(nullptr),
		last_(nullptr) //kedze je LinkedList na zaciatku prazdny, prva aj posledna gulicka je prazdna (neexistuje)
	{
	}

	template<typename T>
	LinkedList<T>::LinkedList(const LinkedList<T>& other) :
		LinkedList(other.equalityFunction_) //kopirovaci konstruktor
	{
		(*this) = other;
	}

	template<typename T>
	LinkedList<T>::~LinkedList()
	{
		clear(); //vsetko vymazeme
	}

	template<typename T>
	Structure* LinkedList<T>::clone() const
	{
		return new LinkedList<T>(*this); //ako clone v inych triedach - pomocou kopirovacieho konstruktora
	}

	template<typename T>
	Structure& LinkedList<T>::operator=(const Structure& other)
	{
		return (*this) = dynamic_cast<const LinkedList<T>&>(other);
		//podobne ako v inych Listoch
	}

	template<typename T>
	List<T>& LinkedList<T>::operator=(const List<T>& other)
	{
		return (*this) = dynamic_cast<const LinkedList<T>&>(other);
	}

	template<typename T>
	LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
	{
		List<T>::operator=(other);
		clear();
		for (T pom : other) { //cyklus foreach - kazdy prvok z other typu T vlozime do nasho LinkedList-u
			add(pom);
		}
		return *this;
	}

	template<typename T>
	size_t LinkedList<T>::size() const
	{
		return size_;
	}

	template<typename T>
	T& LinkedList<T>::operator[](const int index)
	{
		return getLinkedItemAt(index)->getData();
		//vratime data nachadzajuce sa na prvku, ktoremu zodpoveda index
	}

	template<typename T>
	const T& LinkedList<T>::operator[](const int index) const
	{
		return getLinkedItemAt(index)->getData();
	}

	template<typename T>
	void LinkedList<T>::add(const T& data)
	{
		LinkedItem<T>* pom = new LinkedItem<T>(data);
		if (size_ == 0) {
			first_ = pom;
			last_ = pom;
		}
		else {
			last_->setNext(pom);
			last_ = pom;
		}
		size_++;
	}

	template<typename T>
	void LinkedList<T>::insert(const T& data, const int index)
	{
		DSRoutines::rangeCheck(index, size_ + 1, true, &std::string("Index out of range in LinkedList!"));
		if (index == size_) {
			add(data);
		}
		else {
			LinkedItem<T>* prvok = new LinkedItem<T>(data);
			if (index == 0) {
				prvok->setNext(first_);
				first_ = prvok;
			}
			else {
				LinkedItem<T>* pred = getLinkedItemAt(index - 1);
				prvok->setNext(pred->getNext());
				pred->setNext(prvok);
			}
			size_++;
		}
	}

	template<typename T>
	bool LinkedList<T>::tryRemove(const T& data)
	{
		int index = getIndexOf(data);
		if (index == -1) {
			return false;
		}
		else {
			removeAt(index);
			return true;
		}
	}

	template<typename T>
	T& LinkedList<T>::removeAt(const int index)
	{
		DSRoutines::rangeCheck(index, size_, true, &std::string("Index out of range in LinkedList!"));

		LinkedItem<T>* mazany;
		if (index == 0) {
			mazany = first_;
			first_ = first_->getNext();
			if (last_ == mazany) {
				last_ = nullptr;
			}
		}
		else {
			LinkedItem<T>* pred = getLinkedItemAt(index - 1);
			mazany = pred->getNext();
			pred->setNext(mazany->getNext());
			if (last_ == mazany) {
				last_ = pred;
			}
		}
		size_--;
		T data = mazany->getData();
		delete mazany;
		return data;
	}

	template<typename T>
	int LinkedList<T>::getIndexOf(const T& data)
	{
		LinkedItem<T>* next = first_;
		for (int i = 0; i < size_; i++)
		{
			if (equalityFunction_(next->getData(), data))
			{
				return i;
			}
			next = next->getNext();
		}
		return -1;
		//prechadzame vsetky prvy v LinkedList-e a pokial je aktualny prvok (next) rovnaky ako hladany prvok, vypiseme jeho index (premennu i z cyklu)
	}

	template<typename T>
	void LinkedList<T>::clear()
	{
		LinkedItem<T>* mazany = first_;
		while (mazany) {
			LinkedItem<T>* dalsi = mazany->getNext();
			delete mazany;
			mazany = dalsi;
		}
		first_ = nullptr;
		last_ = nullptr;
		size_ = 0;
	}

	template<typename T>
	Iterator<T> LinkedList<T>::begin() const
	{
		return Iterator<T>(LinkedList<T>::LinkedListIterator(first_));
		//podobne ako v ArrayList-e - princip je vsade rovnaky, vzdy vratime instanciu Iteratora danej triedu pretypovanu na predka - Iterator<T>
	}

	template<typename T>
	Iterator<T> LinkedList<T>::end() const
	{
		return Iterator<T>(LinkedList<T>::LinkedListIterator(nullptr));
	}

	template<typename T>
	LinkedItem<T>* LinkedList<T>::getLinkedItemAt(const int index) const
	{
		DSRoutines::rangeCheck(index, size_, true, &std::string("Index out of range in LinkedList!"));
		if (index != size_ - 1) {
			LinkedItem<T>* pom = first_;
			for (int i = 0; i < index; i++)
				pom = pom->getNext();
			return pom;
		}
		else {
			return last_;
		}
	}

	template<typename T>
	LinkedList<T>::LinkedListIterator::LinkedListIterator(const LinkedItem<T>* item) :
		current_(item)
	{
	}

	template<typename T>
	bool LinkedList<T>::LinkedListIterator::operator!=(const StructureIterator<T>& other) const
	{
		const LinkedListIterator& pom = dynamic_cast<const LinkedListIterator&>(other);
		/*najskor other pretypujeme na LinkedListIterator&,
		aby sme to potom mohli porovnat s current_ (other je
		typu StructureIterator => pretypuvavame na potomka)*/
		return current_ != pom.current_;
	}

	template<typename T>
	const T& LinkedList<T>::LinkedListIterator::operator*() const
	{
		return current_->getData();
	}

	template<typename T>
	const StructureIterator<T>& LinkedList<T>::LinkedListIterator::operator++()
	{
		current_ = current_->getNext();
		return *this;
	}

	template<typename T>
	StructureIterator<T>* LinkedList<T>::LinkedListIterator::clone() const
	{
		return new LinkedListIterator(current_); //clone ako vsade inde
	}
}