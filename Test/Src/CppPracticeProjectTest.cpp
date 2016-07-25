#include "Core/TypeTraits.hpp"
#include <string>
#include <iostream>

using namespace std;
using namespace CppPractice;

class StringTraitsTester
{
public:
	typedef TraitsTestStringTag TestTraitsTag;

	explicit StringTraitsTester(const string &str):str_(str) {}

	void Print() { cout << str_ << endl; }

private:
	string str_;
};

class TestStruct 
{
public:
	static const int a = 0;
};

void Test(TestStruct test) 
{
	cout << TestStruct::a << endl;
}

int main()
{
	Test(TestStruct());
	system("pause");
	return 0;
}