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

#include <iostream>
#include <memory>

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
	{
		out << f1.m_numerator << '/' << f1.m_denominator;
		return out;
	}
};

void printFraction(const std::make_unique<Fraction*> ptr)
{
	if (ptr)
		std::cout << *ptr << '\n';
	else
		std::cout << "No fraction\n";
}

int main()
{
	auto ptr{ std::make_unique<Fraction>(3,5)};

	printFraction(ptr);

	delete ptr;

	return 0;
}