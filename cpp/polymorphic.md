##   why copy construction must need reference as parameter?
```c++
class myTest
{
    public:
    // default construction
    myTest()
    {
        std::cout << "con called..." << std::endl;
    }
    ~myTest()
    {
        std::cout << "des called..." << std::endl;
    }

    // code 1
    // right way: by ref
    /*myTest(const myTest& t)
    {
        std::cout << "copy con(pass by ref) called..." << std::endl;
    }*/

    // code 2
    // wrong: by value
    myTest(myTest t)
    {
        std::cout << "copy con(pass by value) called..." << std::endl;
    }

    // code 3
    // wrong: by pointer
    /*myTest(myTest* pt)
    {
        std::cout << "copy con(pass by pointer) called..." << std::endl;
    }*/
};

int main()
{
    myTest t;
    myTest s(t);
    return 0;
}
```
###  if pass by value(code 2):
*   while compile with ubuntu:
copy_con.cpp:10:20: error: invalid constructor; you probably meant ‘myTest (const myTest&)’
   10 |     myTest(myTest t)

*   while compile with vs2017:
1>test3\header_0208_2.h(295): error C2652: 'myTest': illegal copy constructor: first parameter must not be a 'myTest'
1>  test3\header_0208_2.h(292): note: see declaration of 'myTest'
1>test3\header_0208_2.h(295): error C2333: 'myTest::myTest': error in function declaration; skipping function body
1>test3\header_0208_2.h(304): error C2558: class 'myTest': no copy constructor available or copy constructor is declared 'explicit'

### why compile error? : recursive construction

### if pass by pointer(code 3)
*   while compile && run in ubuntu:
default con called.
desconstruction called.
desconstruction called.   
*   while compile && run in vs2017:
default con called...
desconstruction called.
desconstruction called.

##  why create 'reference' type in c++?
