#pragma once

#include <type_traits>
#include <tuple>

namespace CppPractice {
	//from http://pdimov.com/cpp2/simple_cxx11_metaprogramming.html

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

	template<typename T>
	using mp_add_pointer = T*;

	template<typename L, typename... T> struct mp_push_front_impl;
	template<template<typename...> typename L, typename... U, typename... T>
	struct mp_push_front_impl<L<U...>, T...>
	{
		using type = L<T..., U...>;
	};
	template<typename L, typename... T>
	using mp_push_front = typename mp_push_front_impl<L, T...>::type;

	template<template<typename...> typename F, typename L> struct mp_transform_impl;
	template<template<typename...> typename F, template<typename...> typename L, typename... T>
	struct mp_transform_impl<F, L<T...>>
	{
		using type = L<F<T>...>;
	};
	template<template<typename...> typename F, typename L>
	using mp_transform = typename mp_transform_impl<F, L>::type;

	void Cpp11TMPMain()
	{
		//static assert
		static_assert(std::is_same<RemovePointer<int*>, RemovePointer<int>>::value, "type is not same.");

		//variadic templates
		mp_rename<std::pair<int, float>, std::tuple> testTuple;
		static_assert(std::is_same<std::tuple<int,float>, decltype(testTuple)>::value, "change failed.");

		static_assert(mp_size<mp_list<int, float, char>>::value == 3, "type count error.");

		using input = std::tuple<int, void, float>;
		using expected = std::tuple<int*, void*, float*>;
		using result = mp_transform<mp_add_pointer, input>;
		static_assert(std::is_same<result, expected>::value, "");
	}
}