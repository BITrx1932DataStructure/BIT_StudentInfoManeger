#pragma once
#include <cstring>
#include <cassert>
#include <algorithm>
#include <initializer_list>

namespace fy
{

	template <typename T>
	class vector
	{
	public:
		using value_type = T;              //值
		using iterator = T*;              //迭代器
		using const_iterator = T*;        //常量迭代器
		using reference = T&;             //引用
		using const_reference = const T&; //常量引用

		vector() : _begin(nullptr), _end(nullptr), _finish(nullptr) //构造函数，默认
		{
		}

		vector(const size_t capacity) //构造函数，指定容量
		{
			_begin = new value_type[capacity];
			_end = _finish = _begin + capacity;
		}

		vector(std::initializer_list<value_type> list) : vector() //构造函数，列表初始化，例：vector<int> v{1,2,3};
		{
			for (auto it = list.begin(); it != list.end(); it++)
				push_back(*it);
		}

		~vector()//析构函数
		{
			delete[] _begin;
		}

		void swap(vector<value_type>& v)//交换
		{
			swap(_begin, v._begin);
			swap(_end, v._end);
			swap(_finish, v._finish);
		}

		size_t size()//大小，已使用的容量
		{
			return _end - _begin;
		}

		size_t capacity()//容量
		{
			return _finish - _begin;
		}

		void reserve(size_t new_capacity)//重新分配容量
		{
			assert(new_capacity >= size());
			size_t _size = std::min(size(), new_capacity);
			T* new_begin = new T[new_capacity];
			memcpy(new_begin, _begin, _size * sizeof(T));
			delete[] _begin;
			_begin = new_begin;
			_end = new_begin + _size;
			_finish = new_begin + new_capacity;
		}

		reference operator[](size_t pos)//类似数组的下标运算符
		{
			assert(pos < size());
			return *(_begin + pos);
		}

		const_reference operator[](size_t pos) const
		{
			assert(pos < size());
			return *(_begin + pos);
		}

		iterator begin()//首迭代器
		{
			return _begin;
		}

		const_iterator begin() const//首常量迭代器
		{
			return _begin;
		}

		iterator end()//尾迭代器
		{
			return _end;
		}

		const_iterator end() const//尾常量迭代器
		{
			return _end;
		}

		reference front()
		{
			return *_begin;
		}

		const_reference front() const
		{
			return *_begin;
		}

		reference back()
		{
			return *(_end - 1);
		}

		const_reference back() const
		{
			return *(_end - 1);
		}

		void push_back(const value_type& value)//在末尾插入值
		{
			if (size() == capacity())
				reserve(std::max(size() + 1, size() * 2));
			*_end = value;
			_end++;
		}

		void pop_back(const value_type& value)//弹出末尾的值
		{
			end--;
			if (size() < capacity() / 3)
				reserve(capacity() / 2);
		}

		bool empty() const//是否为空
		{
			return _end == _begin;
		}

		iterator find(const value_type& value)//查询，返回迭代器
		{
			iterator it;
			for (it = begin(); it != end(); it++)
				if (*it == value)
					return it;
			return it;
		}

		const_iterator find(const value_type& value) const//查询，返回常量迭代器
		{
			iterator it;
			for (it = begin(); it != end(); it++)
				if (*it == value)
					return it;
			return it;
		}

		size_t count(const value_type& value) const//计数
		{
			size_t ans = 0;
			for (iterator it = begin(); it != end(); it++)
				if (*it == value)
					ans++;
			return ans;
		}

		void erase(iterator it)//删除迭代器所指向的元素
		{
			if (it == _end)
				return;
			while (it != _end)
			{
				*it = *(it + 1);
				it++;
			}
			_end--;
			if (size() < capacity() / 3)
				reserve(capacity() / 2);
		}

	private:
		T* _begin;
		T* _end;
		T* _finish;
	};

} // namespace fy
