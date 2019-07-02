#pragma once
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

namespace lang
{
	template <typename T>
	class ArrayList{
	private:
		static const size_t DEFAULT_INITIAL_CAPACITY = 10;
		static const size_t ZERO_SIZE = 0;
		size_t m_capacity;
		size_t m_size;
		T** m_arr;

		bool checkOutOfBounds(size_t index) const;
		std::string outOfBoundsMsg(size_t index) const;
		void ensureCapacity(size_t capacity);
		void addAllNoResize(const ArrayList& other);

	public:
		typedef T** iterator;
		typedef const T** const_iterator;
		ArrayList(size_t capacity = DEFAULT_INITIAL_CAPACITY) :
		m_capacity(capacity), m_size(ZERO_SIZE), m_arr(new T*[capacity]) {}
		ArrayList(const ArrayList& obj);
		~ArrayList();
		iterator begin() const;
		iterator end() const;
		const const_iterator cbegin() const;
		const const_iterator cend() const;
		T* front();
		T* back();
		T& operator[](int index) const;
		T* toArray() const;
		T& get(int index) const;
		static ArrayList toArrayList(const T* arr, size_t size);
		void clear();
		void add(const T& elem);
		void add(size_t index, const T& elem);
		void addNew(T* p_elem);
		void addAll(const ArrayList& other);
		void set(int index, const T& elem);
		void trimToSize();
		void sort(bool(*compareFunction)(T*, T*));
		void reinitialize();
		bool remove(const T& elem);
		bool removeLast(const T& elem);
		bool removeNew(T* p_elem);
		bool removeAll(const T& elem);
		bool removeAllNew(T* p_elem);
		bool removeAt(size_t index);
		bool contains(T& elem) const;
		bool isEmpty() const;
		bool equals(const ArrayList& other) const;
		int indexOf(const T& elem) const;
		int lastIndexOf(const T& elem) const;
		size_t size() const;
		size_t capacity() const;
		std::string toString() const;
		template <typename U>
		friend std::ostream& operator<<(std::ostream& out, const ArrayList<U>& x);

		bool operator==(const ArrayList& other) const;
		bool operator!=(const ArrayList& other) const;
		ArrayList& operator=(const ArrayList& other);
		ArrayList operator+(const ArrayList& other) const;
		ArrayList operator+(T& elem) const;
		ArrayList& operator+=(const ArrayList& other);
		ArrayList& operator+=(T elem);
		ArrayList operator-(const ArrayList& other) const;
		ArrayList& operator-=(const ArrayList& other);
		ArrayList operator-(T& elem) const;
		ArrayList& operator-=(T& elem);
	};

	//测试数组下表是否越界
	template<typename T>
	bool ArrayList<T>::checkOutOfBounds(size_t index) const
	{
		if (index < 0 || index >= m_size)
			throw std::out_of_range(outOfBoundsMsg(index));
		return true;
	}

	//下标越界提示信息
	template<typename T>
	std::string ArrayList<T>::outOfBoundsMsg(size_t index) const
	{
		std::stringstream ss;
		ss << "Index: " << index << ", size: " << m_size;
		return ss.str();
	}

	//调整数组容量，以确保足够使用
	template<typename T>
	void ArrayList<T>::ensureCapacity(size_t capacity)
	{
		if (capacity >= m_capacity)
		{
			while (capacity >= m_capacity)
			{
				m_capacity *= 2;
			}
			T** newArr = new T*[m_capacity];
			memcpy(newArr, m_arr, m_size * sizeof(T*));
			delete[] m_arr;
			m_arr = newArr;
		}
	}

	//不调整大小，将新的数组列表添加进来
	template<typename T>
	void ArrayList<T>::addAllNoResize(const ArrayList& other)
	{
		size_t addSize = other.m_size;
		for (size_t i = 0; i < addSize; ++i)
			m_arr[m_size++] = new T(*other.m_arr[i]);
	}

	//复制构造函数
	template<typename T>
	ArrayList<T>::ArrayList(const ArrayList& obj) :
		m_capacity(obj.m_capacity), m_size(obj.m_size), m_arr(new T*[obj.m_capacity])
	{
		for (size_t i = 0; i < obj.m_size; ++i)
			m_arr[i] = new T(*obj.m_arr[i]);
	}

	//指向开始元素地址
	template<typename T>
	typename ArrayList<T>::iterator ArrayList<T>::begin() const
	{
		return m_arr;
	}

	//指向末尾元素地址
	template<typename T>
	typename ArrayList<T>::iterator ArrayList<T>::end() const
	{
		return m_arr + m_size;
	}

	//指向开始元素地址
	template<typename T>
	const typename ArrayList<T>::const_iterator ArrayList<T>::cbegin() const
	{
		return const_cast<const T**>(m_arr);
	}

	//指向末尾元素地址
	template<typename T>
	const typename ArrayList<T>::const_iterator ArrayList<T>::cend() const
	{
		return const_cast<const T**>(m_arr + m_size);
	}

	//将任意类型数组转化为ArrayList类型
	template<typename T>
	ArrayList<T> ArrayList<T>::toArrayList(const T* arr, size_t size)
	{
		size_t capacity = (size < DEFAULT_INITIAL_CAPACITY ? DEFAULT_INITIAL_CAPACITY : size);
		ArrayList newList(capacity);
		newList.m_capacity = capacity;
		for (size_t i = 0; i < size; ++i)
			newList.m_arr[newList.m_size++] = new T(arr[i]);
		return newList;
	}

	//将ArrayList类型数组转化为普通数组
	template<typename T>
	T* ArrayList<T>::toArray() const
	{
		T* newArr = new T[m_size];
		for (size_t i = 0; i < m_size; ++i)
			newArr[i] = T(*m_arr[i]);
		return newArr;
	}

	
	template<typename T>
	T * ArrayList<T>::front()
	{
		checkOutOfBounds(0);
		return m_arr[0];
	}


	template<typename T>
	T * ArrayList<T>::back()
	{
		checkOutOfBounds(0);
		return m_arr[m_size - 1];
	}

	template<typename T>
	ArrayList<T>::~ArrayList()
	{
		clear();
		delete[] m_arr;
	}

	template<typename T>
	T& ArrayList<T>::operator[](int index) const
	{
		checkOutOfBounds(index);
		return *m_arr[index];
	}

	template<typename T>
	void ArrayList<T>::clear()
	{
		for (size_t i = 0; i < m_size; ++i)
			delete m_arr[i];
		m_size = 0;
	}

	template<typename T>
	void ArrayList<T>::add(const T& elem)
	{
		ensureCapacity(m_size + 1);
		m_arr[m_size++] = new T(elem);
	}

	template<typename T>
	void ArrayList<T>::add(size_t index, const T& elem)
	{
		checkOutOfBounds(index);
		ensureCapacity(m_size + 1);
		if (index < m_size)
			memmove(m_arr + index + 1, m_arr + index, (m_size - index) * sizeof(T*));
		m_arr[index] = new T(elem);
		++m_size;
	}

	template<typename T>
	void ArrayList<T>::addNew(T* p_elem)
	{
		ensureCapacity(m_size + 1);
		m_arr[m_size++] = p_elem;
	}

	template<typename T>
	void ArrayList<T>::addAll(const ArrayList& other)
	{
		size_t addSize = other.m_size;
		ensureCapacity(m_size + addSize);
		for (size_t i = 0; i < addSize; ++i)
			m_arr[m_size++] = new T(*other.m_arr[i]);
	}

	template<typename T>
	void ArrayList<T>::set(int index, const T& elem)
	{
		checkOutOfBounds(index);
		delete m_arr[index];
		m_arr[index] = new T(elem);
	}

	template<typename T>
	bool ArrayList<T>::remove(const T& elem)
	{
		int index = indexOf(elem);
		return index == -1 ? false : removeAt(index);
	}

	template<typename T>
	bool ArrayList<T>::removeLast(const T& elem)
	{
		int index = lastIndexOf(elem);
		return index == -1 ? false : removeAt(index);
	}

	template<typename T>
	bool ArrayList<T>::removeNew(T* p_elem)
	{
		int index = indexOf(*p_elem);
		delete p_elem;
		return index == -1 ? false : removeAt(index);
	}

	template<typename T>
	bool ArrayList<T>::removeAll(const T& elem)
	{
		bool success = false;
		for (size_t i = 0; i < m_size; i++)
		{
			if (*m_arr[i] == elem)
			{
				success = removeAt(i);
				--i;
			}
		}
		return success;
	}

	template<typename T>
	bool ArrayList<T>::removeAllNew(T* p_elem)
	{
		bool success = false;
		for (size_t i = 0; i < m_size; ++i)
		{
			if (*p_elem == *m_arr[i])
			{
				success = removeAt(i);
				--i;
			}
		}
		delete p_elem;
		return success;
	}

	template<typename T>
	bool ArrayList<T>::removeAt(size_t index)
	{
		checkOutOfBounds(index);
		delete m_arr[index];
		memmove(m_arr + index, m_arr + index + 1, (m_size - 1 - index) * sizeof(T*));
		--m_size;
		return true;
	}

	template<typename T>
	int ArrayList<T>::indexOf(const T& elem) const
	{
		int index = -1;
		for (size_t i = 0; i < m_size && index == -1; ++i)
			if (*m_arr[i] == elem)
				index = i;
		return index;
	}

	template<typename T>
	int ArrayList<T>::lastIndexOf(const T& elem) const
	{
		int index = -1;
		// size_t 0 - 1 == 4294967295
		for (size_t i = m_size - 1; i < m_size && index == -1; --i)
			if (*m_arr[i] == elem)
				index = i;
		return index;
	}

	//判断数组中是否容纳了一个成员
	template<typename T>
	bool ArrayList<T>::contains(T& elem) const
	{
		return indexOf(elem) != -1;
	}

	template<typename T>
	T& ArrayList<T>::get(int index) const
	{
		checkOutOfBounds(index);
		return *m_arr[index];
	}

	template<typename T>
	size_t ArrayList<T>::size() const
	{
		return m_size;
	}

	template<typename T>
	bool ArrayList<T>::isEmpty() const
	{
		return m_size == ZERO_SIZE;
	}

	template<typename T>
	size_t ArrayList<T>::capacity() const
	{
		return m_capacity;
	}

	template<typename T>
	std::string ArrayList<T>::toString() const
	{
		std::stringstream ss;
		//ss << '[';
		if (m_size > 0)
			ss << (*m_arr[0]);
		for (size_t i = 1; i < m_size; ++i)
		{
			//ss << ", ";
			ss << endl;

			ss << (*m_arr[i]);
		}
		//ss << ']';
		return ss.str();
	}

	template<typename T>
	ArrayList<T> ArrayList<T>::operator+(const ArrayList& other) const
	{
		ArrayList result;
		result.ensureCapacity(m_size + other.m_size);
		result.addAllNoResize(*this);
		result.addAllNoResize(other);
		return result;
	}

	template<typename T>
	ArrayList<T> ArrayList<T>::operator+(T& elem) const
	{
		ArrayList result;
		result.ensureCapacity(m_size + 1);
		result.addAllNoResize(*this);
		result.add(elem);
		return result;
	}

	template<typename T>
	ArrayList<T>& ArrayList<T>::operator+=(const ArrayList& other)
	{
		addAll(other);
		return *this;
	}

	template<typename T>
	ArrayList<T>& ArrayList<T>::operator+=(T elem)
	{
		add(elem);
		return *this;
	}

	template<typename T>
	ArrayList<T> ArrayList<T>::operator-(const ArrayList& other) const
	{
		ArrayList result;
		if (this == &other)
		{
			return result;
		}
		else
		{
			result.ensureCapacity(m_size);
			result.addAllNoResize(*this);
			for (size_t i = 0; i < other.m_size; ++i)
				result.removeLast(*other.m_arr[i]);
		}
		return result;
	}

	template<typename T>
	void ArrayList<T>::reinitialize()
	{
		clear();
		delete[] m_arr;
		m_capacity = DEFAULT_INITIAL_CAPACITY;
		m_arr = new T*[DEFAULT_INITIAL_CAPACITY];
	}

	template<typename T>
	ArrayList<T>& ArrayList<T>::operator-=(const ArrayList& other)
	{
		if (this == &other)
		{
			reinitialize();
		}
		else
		{
			for (size_t i = 0; i < other.size(); ++i)
				removeLast(*other.m_arr[i]);
		}
		return *this;
	}

	//从列表的结尾删除元素后返回新的数组
	template<typename T>
	ArrayList<T> ArrayList<T>::operator-(T& elem) const
	{
		ArrayList result;
		result.ensureCapacity(m_size);
		result.addAllNoResize(*this);
		result.removeLast(elem);
		return result;
	}

	//从列表的结尾删除元素
	template<typename T>
	ArrayList<T>& ArrayList<T>::operator-=(T& elem)
	{
		removeLast(elem);
		return *this;
	}

	//将ArrayList对象送进输出流
	template<typename T>
	std::ostream& operator<<(std::ostream& out, const ArrayList<T>& x)
	{
		out << x.toString();
		return out;
	}

	//复制ArrayList
	template<typename T>
	ArrayList<T>& ArrayList<T>::operator=(const ArrayList& other)
	{
		if (this != &other)
		{
			clear();
			addAll(other);
		}
		return *this;
	}

	//判断两个ArrayList是否相等
	template<typename T>
	bool ArrayList<T>::equals(const ArrayList& other) const
	{
		bool result = true;
		if (m_size != other.m_size)
			result = false;
		for (size_t i = 0; result && i < m_size; ++i)
			if (!(*m_arr[i] == *other.m_arr[i]))
				result = false;
		return result;
	}

	//判断两个ArrayList是否相等
	template<typename T>
	bool ArrayList<T>::operator==(const ArrayList& other) const
	{
		return equals(other);
	}

	//判断两个ArrayList是否不相等
	template<typename T>
	bool ArrayList<T>::operator!=(const ArrayList& other) const
	{
		return !equals(other);
	}

	//对数组内容进行排序
	template<typename T>
	void ArrayList<T>::sort(bool(*compareFunction)(T*, T*))
	{
		std::sort(begin(), end(), compareFunction);
	}

	//裁剪数组大小
	template<typename T>
	void ArrayList<T>::trimToSize()
	{
		m_capacity = m_size;
		T** newArr = new T*[m_capacity];
		memcpy(newArr, m_arr, m_size * sizeof(T*));
		delete[] m_arr;
		m_arr = newArr;
	}
}

#endif//ARRAY_LIST_H