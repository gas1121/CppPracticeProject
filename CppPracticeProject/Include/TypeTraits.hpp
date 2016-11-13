#pragma once

#include <string>
#include <iostream>

using namespace std;

namespace CppPractice {
	struct TraitsTestStringTag {};
	struct TraitsTestNumberTag {};
	struct TraitsTestIntegerTag: public TraitsTestNumberTag {};

	template<typename TestObject>
	struct TestTraits
	{
		typedef typename TestObject::TestTraitsTag TestTraitsTag;
	};

	template<typename TestObject>
	void TraitsTestFunction(const TestObject& object)
	{
		TraitsTestFunction(object, typename TestTraits<TestObject>::TestTraitsTag());
	}

	template<typename TestObject>
	void TraitsTestFunction(const TestObject& object, TraitsTestStringTag)
	{
		object.Print();
	}


    class StringTraitsTester
    {
    public:
        typedef TraitsTestStringTag TestTraitsTag;

        explicit StringTraitsTester(const string &str) :str_(str) {}

        void Print() const { cout << str_ << endl; }

    private:
        string str_;
    };

    void TypeTraitsMain()
    {
        TraitsTestFunction<StringTraitsTester>(StringTraitsTester("123"));
    }
}