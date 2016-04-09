#pragma once

#include "PriorityQueue.h"

namespace DS {
	template<typename T>
	class PriorityQueue_Heap :
		public PriorityQueue<T>
	{
	public:
		PriorityQueue_Heap();
		PriorityQueue_Heap(const PriorityQueue_Heap<T>& other);
		virtual ~PriorityQueue_Heap();

		Structure* clone() const override;
		Structure& operator=(const Structure& other) override;
		PriorityQueue<T>& operator=(const PriorityQueue<T>& other) override;
		virtual PriorityQueue_Heap<T>& operator=(const PriorityQueue_Heap<T>& other);

		size_t size() const override;
		bool isEmpty() const override;
		void clear() override;

		void push(const int priority, const T& data) override;
		T pop() override;
		T& peek() override;
		const T& peek() const override;
		int peekPriority() const override;
	private:
		//atributy

		int getParentIndex(const int index);
		int getGreaterSonIndex(const int index);
	};

	template<typename T>
	PriorityQueue_Heap<T>::PriorityQueue_Heap()
	{
	throw -1;
	}

	template<typename T>
	PriorityQueue_Heap<T>::PriorityQueue_Heap(const PriorityQueue_Heap<T>& other)
	{
	throw -1;
	}

	template<typename T>
	PriorityQueue_Heap<T>::~PriorityQueue_Heap()
	{
	}

	template<typename T>
	Structure* PriorityQueue_Heap<T>::clone() const
	{
	throw -1;
	}

	template<typename T>
	Structure& PriorityQueue_Heap<T>::operator=(const Structure& other)
	{
	throw -1;
	}

	template<typename T>
	PriorityQueue<T>& PriorityQueue_Heap<T>::operator=(const PriorityQueue<T>& other)
	{
	throw -1;
	}

	template<typename T>
	PriorityQueue_Heap<T>& PriorityQueue_Heap<T>::operator=(const PriorityQueue_Heap<T>& other)
	{
	throw -1;
	}

	template<typename T>
	size_t PriorityQueue_Heap<T>::size() const
	{
	throw -1;
	}

	template<typename T>
	bool PriorityQueue_Heap<T>::isEmpty() const
	{
	throw -1;
	}

	template<typename T>
	void PriorityQueue_Heap<T>::clear()
	{
	throw -1;
	}

	template<typename T>
	void PriorityQueue_Heap<T>::push(const int priority, const T& data)
	{
	throw -1;
	}

	template<typename T>
	T PriorityQueue_Heap<T>::pop()
	{
	throw -1;
	}

	template<typename T>
	inline int PriorityQueue_Heap<T>::getParentIndex(const int index)
	{
	throw -1;
	}

	template<typename T>
	inline int PriorityQueue_Heap<T>::getGreaterSonIndex(const int index)
	{
	throw -1;
	}

	template<typename T>
	T& PriorityQueue_Heap<T>::peek()
	{
	throw -1;
	}

	template<typename T>
	const T& PriorityQueue_Heap<T>::peek() const
	{
	throw -1;
	}

	template<typename T>
	int PriorityQueue_Heap<T>::peekPriority() const
	{
	throw -1;
	}

}