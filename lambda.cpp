/*
  One of the new features introduced in modern C++ starting from C++ 11 
  is the lambda expression.
  It is a convenient way to define an anonymous function object or *functor, 
  because we can define it locally where we want to call it or pass it to a 
  function as an argument

  *Functor: An object or structure that can be called like a function 
            by overloading the function call operator ()
*/

#include <cassert>

struct PlusOne
{
    int operator()(const int value) const
    {
        return value + 1;
    }
};

int main ()
{   
    PlusOne plusOne;
    assert(plusOne(2) == 3);

    return 0;
}