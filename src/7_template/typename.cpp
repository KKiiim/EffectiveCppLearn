#include <iostream>
#include <vector>

template <typename C>
void print2nd(const C& container){
    if(container.size()>=2){

        // nested dependent name must use typename to connfirm it is a type
        typename C::const_iterator iter(container.begin());
        ++iter;
        int value = *iter;
        std::cout << value << '\n';
    }
}

int main(){
    std::vector<int> vec{3,4,5};
    print2nd(vec);
    int x;
    
    //print2nd(x);
    /*
    typename.cpp: In instantiation of ‘void print2nd(const C&) [with C = int]’:
    typename.cpp:20:13:   required from here
    typename.cpp:6:18: error: request for member ‘size’ in ‘container’, which is of non-class type ‘const int’
        6 |     if(container.size()>=2){
        |        ~~~~~~~~~~^~~~
    typename.cpp:9:36: error: ‘int’ is not a class, struct, or union type
        9 |         typename C::const_iterator iter(container.begin());
        |                                    ^~~~
    typename.cpp:9:36: error: ‘int’ is not a class, struct, or union type
    */
}