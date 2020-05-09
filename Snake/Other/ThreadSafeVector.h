#pragma once
#include <vector>
#include <mutex>

template <typename T>
class ThreadSafeVector 
{
private:
	std::vector<T> _items;
	std::mutex _mutex;
public:
	ThreadSafeVector();
	
	std::vector<T> GetVector() const;
	T GetItem(int index) const;
	void SetIten(T value, int index);

	void Add(T item);
	void Insert(T item, int index);
	void Remove(T item);
	void RemoveAt(int index);
	void Clear();
	int Count();

	T& operator[] (int index);
	T const& operator[] (int index) const;
};

template<typename T>
ThreadSafeVector<T>::ThreadSafeVector()
{
	_items = std::vector<T>();
}

template<typename T>
inline std::vector<T> ThreadSafeVector<T>::GetVector() const
{
	return _items;
}

template<typename T>
inline T ThreadSafeVector<T>::GetItem(int index) const
{
	_mutex.lock();
	T item = _items[index];
	_mutex.unlock();
	return item;
}

template<typename T>
inline void ThreadSafeVector<T>::SetIten(T value, int index)
{
	_items[index] = value;
}

template<typename T>
inline void ThreadSafeVector<T>::Add(T item)
{
	_mutex.lock();
	_items.push_back(item);
	_mutex.unlock();
}

template<typename T>
inline void ThreadSafeVector<T>::Insert(T item, int index)
{
	_mutex.lock();
	_items.insert(index, item);
	_mutex.unlock();
}

template<typename T>
inline void ThreadSafeVector<T>::Remove(T item)
{
	_mutex.lock();
	_items.erase(std::remove(_items.begin(), _items.end(), item), _items.end());
	_mutex.unlock();
}

template<typename T>
inline void ThreadSafeVector<T>::RemoveAt(int index)
{
	_mutex.lock();
	_items.erase(_items.begin() + index);
	_mutex.unlock();
}

template<typename T>
inline void ThreadSafeVector<T>::Clear()
{
	_items.clear();
}

template<typename T>
inline int ThreadSafeVector<T>::Count()
{
	return _items.size();
}

template<typename T>
inline T& ThreadSafeVector<T>::operator[](int index)
{
	return _items[index];
}

template<typename T>
inline T const& ThreadSafeVector<T>::operator[](int index) const
{
	return _items[index];
}
