#pragma once

#include "PriorityQueue.h"
#include "PriorityQueue_List.h"

namespace DS {
	template<typename T>
	class PriorityQueue_ArrayList_Sorted :
		public PriorityQueue_ArrayList<T>
	{
	public:
		PriorityQueue_ArrayList_Sorted();
		PriorityQueue_ArrayList_Sorted(const PriorityQueue_ArrayList_Sorted<T>& other);

		Structure* clone() const override;
    PriorityQueue_ArrayList_Sorted<T>& operator=(const PriorityQueue_ArrayList_Sorted<T>& other);

		void push(const int priority, const T& data) override;
		T pop() override;
	protected:
		int indexOfHighestPriority() const override;
	};

	template<typename T>
	PriorityQueue_ArrayList_Sorted<T>::PriorityQueue_ArrayList_Sorted() 
	{
    throw -1;
	}

	template<typename T>
	PriorityQueue_ArrayList_Sorted<T>::PriorityQueue_ArrayList_Sorted(const PriorityQueue_ArrayList_Sorted<T>& other) 
	{
    throw -1;
	}

	template<typename T>
	Structure* PriorityQueue_ArrayList_Sorted<T>::clone() const
	{
	  throw -1;
	}
  
	template<typename T>
	PriorityQueue_ArrayList_Sorted<T>& PriorityQueue_ArrayList_Sorted<T>::operator=(const PriorityQueue_ArrayList_Sorted<T>& other)
	{
	  throw -1;
	}

	template<typename T>
	void PriorityQueue_ArrayList_Sorted<T>::push(const int priority, const T& data)
	{
	  throw -1;
	}

	template<typename T>
	T PriorityQueue_ArrayList_Sorted<T>::pop()
	{
	  throw -1;
	}

	template<typename T>
	inline int PriorityQueue_ArrayList_Sorted<T>::indexOfHighestPriority() const
	{
	  throw -1;
	}
}