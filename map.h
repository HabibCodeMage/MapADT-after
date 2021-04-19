#pragma once
#ifndef MAP_H
#define MAP_H
#include<iostream>
#include"deque.h"
using namespace std;
template<typename K,typename V>
class map
{
public:
	class iterator;
	class entry 
	{
	private:
		K _key;
		V _value;
	public:
		entry(const K&k, const V& v ):_key(k),_value(v)
		{
		}
	private:
		entry()
		{

		}
		const K& key() const { return _key; }
		const V& value() const { return _value; }
		void setKey(const K& k) { key = k; }
		void setValue(const V& v) { value = v; }
		friend class deque<entry>;
		friend class iterator;
	};
	//typedef typename deque<entry>::iterator iterator;
	class iterator 
	{
	private:
		typename deque<entry>::iterator it;
	public:
		iterator(const typename deque<entry>::iterator&y):it(y)
		{
		}
		bool  operator!=(const iterator& that)
		{
			return it != that.it;
		}
		void operator++()
		{
			++it;
		}
		void operator--()
		{
			++it;
		}
		const K& key() const
		{
			return (*it).key();
		}
		const V& value() const
		{
			return (*it).value();
		}
	};
private:
	deque<entry>object;
	int n;
public:
	iterator begin()
	{
		return iterator(object.begin());
	}
	iterator end()
	{
		return object.end();
	}
	void put(const entry& v)
	{
		object.insertback(v);
	}
};
#endif // !MAP_H


