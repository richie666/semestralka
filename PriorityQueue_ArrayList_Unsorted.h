#pragma once

#include "PriorityQueue.h"
#include "PriorityQueue_ArrayList.h"

namespace DS {
	template<typename T>
	class PriorityQueue_ArrayList_Unsorted :
		public PriorityQueue_ArrayList<T>
	{
	public:
		PriorityQueue_ArrayList_Unsorted();
		PriorityQueue_ArrayList_Unsorted(const PriorityQueue_ArrayList_Unsorted<T>& other);

		Structure* clone() const override;
		PriorityQueue_ArrayList_Unsorted<T>& operator=(const PriorityQueue_ArrayList_Unsorted<T>& other);

		void push(const int priority, const T& data) override;
		T pop() override;
		
	};

	template<typename T>
	PriorityQueue_ArrayList_Unsorted<T>::PriorityQueue_ArrayList_Unsorted()
	{
    throw -1;
	}

	template<typename T>
	PriorityQueue_ArrayList_Unsorted<T>::PriorityQueue_ArrayList_Unsorted(const PriorityQueue_ArrayList_Unsorted<T>& other) 
	{
    throw -1;
	}

	template<typename T>
	Structure* PriorityQueue_ArrayList_Unsorted<T>::clone() const
	{
	  throw -1;
	}

	template<typename T>
	PriorityQueue_ArrayList_Unsorted<T>& PriorityQueue_ArrayList_Unsorted<T>::operator=(const PriorityQueue_ArrayList_Unsorted<T>& other)
	{
	  throw -1;
	}

	template<typename T>
	void PriorityQueue_ArrayList_Unsorted<T>::push(const int priority, const T & data)
	{
	  throw -1;
	}

	template<typename T>
	T PriorityQueue_ArrayList_Unsorted<T>::pop()
	{
	  throw -1;
	}

}