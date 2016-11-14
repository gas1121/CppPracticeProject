#pragma once

#include <type_traits>

namespace CppPractice {
	//alias templates
	template<typename U>
	struct remove_pointer
	{
		using type = U;
	};
	template<typename T>
	struct remove_pointer<T*>
	{
		using type = T;
	};
	template<typename W>
	using RemovePointer = typename remove_pointer<W>::type;

	//variadic templates
	template<typename... T>
	struct type_list
	{

	};
	using list = type_list<int, char, float, double, void>;
	
	void Cpp11TMPMain()
	{
		//static assert
		static_assert(std::is_same<RemovePointer<int*>, RemovePointer<int>>::value, "type is not same.");
	}
}