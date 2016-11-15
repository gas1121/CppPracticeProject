#pragma once

#include <type_traits>
#include <tuple>

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
	template<typename... T> struct mp_list {};

	template<typename A, template<typename...> typename B> struct mp_rename_impl;
	template<template<typename...> typename A, typename... T, template<typename...> typename B>
	struct mp_rename_impl<A<T...>, B>
	{
		using type = B<T...>;
	};
	template<typename A, template<typename...> typename B>
	using mp_rename = typename mp_rename_impl<A, B>::type;

    template<typename... T> 
    using mp_length = std::integral_constant<std::size_t, sizeof...(T)>;
    template<typename L>
    using mp_size = mp_rename<L, mp_length>;
    template<template<typename...> typename F, typename L>
    using mp_apply = mp_rename<L, F>;

	void Cpp11TMPMain()
	{
		//static assert
		static_assert(std::is_same<RemovePointer<int*>, RemovePointer<int>>::value, "type is not same.");

		//variadic templates
		mp_rename<std::pair<int, float>, std::tuple> testTuple;
		static_assert(std::is_same<std::tuple<int,float>, decltype(testTuple)>::value, "change failed.");

		static_assert(mp_size<mp_list<int, float, char>>::value == 3, "type count error.");
	}
}