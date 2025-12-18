//#include <iostream>
//
//template <typename T>
//class Auto_ptr1
//{
//private:
//	T* m_ptr{};
//
//public:
//	Auto_ptr1(T* ptr = nullptr)
//		:m_ptr(ptr)
//	{
//	}
//	~Auto_ptr1()
//	{
//		delete m_ptr;
//	}
//
//	Auto_ptr1(Auto_ptr1& a)
//	{
//		m_ptr = a.m_ptr;
//		a.m_ptr = nullptr;
//	}
//
//	Auto_ptr1& operator=(Auto_ptr1& a)
//	{
//		if (&a == this)
//			return *this;
//
//		delete m_ptr;
//		m_ptr = a.m_ptr;
//		a.m_ptr = nullptr;
//		return *this;
//	}
//	T& operator*() const { return *m_ptr; }
//	T* operator->() const { return m_ptr; }
//	bool isNull() const { return m_ptr == nullptr; }
//};
//
//class Resource
//{
//public:
//	Resource() { std::cout << "Resource acquired\n"; }
//	~Resource() { std::cout << "Resouce destroyed\n"; }
//};
//
//int main()
//{
//	Auto_ptr1<Resource> res1(new Resource());
//	Auto_ptr1<Resource> res2;
//
//	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
//	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
//
//	res2 = res1;
//
//	std::cout << "Ownership transferred\n";
//
//	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
//	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
//
//	return 0;
//}

//#include <iostream>
//
//void fun(const int& lref)
//{
//	std::cout << "l-value reference to const: " << lref << '\n';
//}
//
//void fun(int&& rref)
//{
//	std::cout << "r-value reference: " << rref << '\n';
//}
//
//int main()
//{
//	int x{ 5 };
//	fun(x);
//	fun(5);
//
//	return 0;
//}

//#include<iostream>
//
//template<typename T>
//class Auto_ptr4
//{
//private:
//	T* m_ptr{};
//public:
//	Auto_ptr4(T* ptr = nullptr)
//		: m_ptr{ ptr }
//	{
//	}
//
//	~Auto_ptr4()
//	{
//		delete m_ptr;
//	}
//
//	Auto_ptr4(const Auto_ptr4& a)
//	{
//		m_ptr = new T;
//		*m_ptr = *a.m_ptr;
//	}
//
//	Auto_ptr4(Auto_ptr4&& a) noexcept
//		: m_ptr{ a.m_ptr }
//	{
//		a.m_ptr = nullptr;
//	}
//
//	Auto_ptr4& operator=(const Auto_ptr4& a)
//	{
//		if (&a == this)
//			return *this;
//
//		delete m_ptr;
//
//		m_ptr = new T;
//		*m_ptr = *a.m_ptr;
//
//		return *this;
//	}
//
//	Auto_ptr4& operator=(Auto_ptr4&& a) noexcept
//	{
//		if (&a == this)
//			return *this;
//
//		delete m_ptr;
//
//		m_ptr = a.m_ptr;
//		a.m_ptr = nullptr;
//
//		std::cout << "Transfer resource\n";
//
//		return *this;
//	}
//
//	T& operator*() const { return *m_ptr; }
//	T* operator->() const { return m_ptr; }
//	bool isNull() const { return m_ptr == nullptr; }
//};
//
//class Resource
//{
//public:
//	Resource() { std::cout << "Resource acquired\n"; }
//	~Resource() { std::cout << "Resource destroyed\n"; }
//};
//
//Auto_ptr4<Resource> generateResource()
//{
//	Auto_ptr4<Resource> res{ new Resource };
//	return res;
//}
//
//int main()
//{
//	Auto_ptr4<Resource> mainres;
//	mainres = generateResource();
//
//	return 0;
//}

//#include <iostream>
//
//template<typename T>
//class Auto_ptr5
//{
//	T* m_ptr{};
//public:
//	Auto_ptr5(T* ptr = nullptr)
//		: m_ptr{ ptr }
//	{
//	}
//
//	~Auto_ptr5()
//	{
//		delete m_ptr;
//	}
//
//	// Copy constructor -- no copying allowed!
//	Auto_ptr5(const Auto_ptr5& a) = delete;
//
//	// Move constructor
//	// Transfer ownership of a.m_ptr to m_ptr
//	Auto_ptr5(Auto_ptr5&& a) noexcept
//		: m_ptr{ a.m_ptr }
//	{
//		a.m_ptr = nullptr;
//	}
//
//	// Copy assignment -- no copying allowed!
//	Auto_ptr5& operator=(const Auto_ptr5& a) = delete;
//
//	// Move assignment
//	// Transfer ownership of a.m_ptr to m_ptr
//	Auto_ptr5& operator=(Auto_ptr5&& a) noexcept
//	{
//		// Self-assignment detection
//		if (&a == this)
//			return *this;
//
//		// Release any resource we're holding
//		delete m_ptr;
//
//		// Transfer ownership of a.m_ptr to m_ptr
//		m_ptr = a.m_ptr;
//		a.m_ptr = nullptr;
//
//		return *this;
//	}
//
//	T& operator*() const { return *m_ptr; }
//	T* operator->() const { return m_ptr; }
//	bool isNull() const { return m_ptr == nullptr; }
//};
//
//class Resource
//{
//public:
//	Resource() { std::cout << "Resource acquired\n"; }
//	~Resource() { std::cout << "Resource destroyed\n"; }
//};
//
//int main()
//{
//	Auto_ptr5<Resource> res1{};
//	Auto_ptr5<Resource> res2;
//
//	res2 = res1;
//}

//#include <iostream>
//#include <memory>
//#include <string>
//
//class Person
//{
//private:
//	std::string m_name;
//	std::weak_ptr<Person> m_partner;
//public:
//	Person(const std::string& name) : m_name{ name }
//	{
//		std::cout << m_name << " created\n";
//	}
//	~Person()
//	{
//		std::cout << m_name << " destroyed\n";
//	}
//
//	friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
//	{
//		if (!p1 || !p2)
//			return false;
//
//		p1->m_partner = p2;
//		p2->m_partner = p1;
//
//		std::cout << p2->m_name << " is now parter with " << p2->m_partner.lock()->m_name << '\n';
//
//		return true;
//	}
//};
//
//int main()
//{
//	auto lucy{ std::make_shared<Person>("Lucy") };
//	auto ricky{ std::make_shared<Person>("Ricky") };
//
//	partnerUp(lucy, ricky);
//
//	return 0;
//}

#include <algorithm> // for std::copy()
#include <cassert>   // for assert()
#include <initializer_list> // for std::initializer_list
#include <iostream>

class IntArray
{
private:
	int m_length{};
	int* m_data{};

public:
	IntArray() = default;

	IntArray(int length)
		: m_length{ length }
		, m_data{ new int[static_cast<std::size_t>(length)] {} }
	{

	}

	IntArray(std::initializer_list<int> list) // allow IntArray to be initialized via list initialization
		: IntArray(static_cast<int>(list.size())) // use delegating constructor to set up initial array
	{
		// Now initialize our array from the list
		std::copy(list.begin(), list.end(), m_data);
	}

	~IntArray()
	{
		delete[] m_data;
	}

	//	IntArray(const IntArray&) = delete; // to avoid shallow copies
	//	IntArray& operator=(const IntArray& list) = delete; // to avoid shallow copies

	IntArray& operator=( std::initializer_list<int> list)
	{
		if (m_length != static_cast<int>(list.size()))
		{
			m_length = static_cast<int>(list.size());
			delete[] m_data;
			m_data = new int[m_length];
		}
		std::copy(list.begin(), list.end(), m_data);
		return *this;
	}

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength() const { return m_length; }
};

int main()
{
	IntArray array{ 5, 4, 3, 2, 1 }; // initializer list
	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 3, 5, 7, 9, 11 };

	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	return 0;
}