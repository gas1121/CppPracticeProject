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
}