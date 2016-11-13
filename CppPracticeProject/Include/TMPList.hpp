#pragma once

using namespace std;
namespace CppPractice {

    struct NIL 
    {
    };

    template<typename H, typename T=NIL>
    struct Lst
    {
        typedef H Head;
        typedef T Tail;
    };

    template<typename LST>
    struct Length
    {
        static const unsigned int result = 1 + Length<typename LST::Tail>::result;
    };
    template<>
    struct Length<NIL>
    {
        static const unsigned int result = 0;
    };

    template<typename LST, int N>
    struct Nth
    {
        typedef typename Nth<typename LST::Tail, N-1>::result result;
    };
    template<typename LST>
    struct Nth<LST, 0>
    {
        typedef typename LST::Head result;
    };

    template<typename X, typename Y>
    struct Eq
    {
        static const bool result = false;
    };
    template<typename X>
    struct Eq<X, X>
    {
        static const bool result = true;
    };

    template<typename Elm, typename LST>
    struct Includes
    {
        static const bool found = Eq<Elm, LST::Head>::result;
        static const bool found_tail = Includes<Elm, LST::Tail>::result;
        static const bool result = found || found_tail;
    };
    template<typename Elm>
    struct Includes<Elm, NIL>
    {
        static const bool result = false;
    };

    template<typename Elm, typename LST=NIL>
    struct Prepend
    {
        typedef Lst<Elm, LST> result;
    };

    template<typename Elm, typename LST=NIL>
    struct Append
    {
        typedef typename Append<Elm,typename LST::Tail>::result Next;
        typedef typename Lst<typename LST::Head, Next> result;
    };
    template<typename Elm>
    struct Append<Elm, NIL>
    {
        typedef Lst<Elm> result;
    };

    class Assertion {};
    template<bool cond, typename T=Assertion>
    struct Assert
    {
        typedef typename T::fail check;
    };
    template<>
    struct Assert<true>
    {
        typedef void check;
    };

    template<typename Elm, typename LST>
    struct _Position
    {
        static const bool found = Eq<LST::Head, Elm>::result;
        static const int result = found ? 0 : 1 + _Position<Elm, LST::Tail>::result;
    };
    template<typename Elm>
    struct _Position<Elm, NIL>
    {
        static const int result = 0;
    };

    template<typename Elm,typename LST>
    struct Position
    {
        typedef typename Assert<Includes<Elm, LST>::result>::check include;
        static const int result = _Position<Elm, LST>::result;
    };

    template<int N>
    struct Int
    {
        static const int result = N;
    };
    typedef Lst<Int<1>, Lst<Int<2>, Lst<Int<3>>>> OneTwoThree;

    void TMPListMain()
    {
        cout << Length<OneTwoThree>::result << endl;
        cout << Length<Lst<NIL>>::result << endl;
        cout << Nth<OneTwoThree, 1>::result::result << endl;
        cout << Includes<Int<4>, OneTwoThree>::result << endl;
        cout << Includes<Int<4>, Prepend<Int<4>, OneTwoThree>::result>::result << endl;
        cout << Includes<Int<5>, Prepend<Int<4>, OneTwoThree>::result>::result << endl;
        cout << Includes<Int<4>, Append<Int<4>, OneTwoThree>::result>::result << endl;
        cout << Includes<Int<1>, Append<Int<4>, OneTwoThree>::result>::result << endl;
        cout << Includes<Int<5>, Append<Int<4>, OneTwoThree>::result>::result << endl;
        cout << Append<Int<4>>::result::Head::result << endl;
        cout << Position<Int<1>, OneTwoThree>::result << endl;
    }
}