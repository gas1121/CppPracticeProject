#include "TypeTraits.hpp"
#include <string>
#include <iostream>

using namespace std;
using namespace CppPractice;

class StringTraitsTester
{
public:
	typedef TraitsTestStringTag TestTraitsTag;

	explicit StringTraitsTester(const string &str):str_(str) {}

	void Print() const { cout << str_ << endl; }

private:
	string str_;
};

int main()
{
	TraitsTestFunction<StringTraitsTester>(StringTraitsTester("123"));
	system("pause");
	return 0;
}