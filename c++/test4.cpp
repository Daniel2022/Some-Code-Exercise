#include <iostream>
#include <thread>
#include <mutex>
std::once_flag flag1;
void printHello() { std::cout << "Hello\n"; }
void threadFunction(){
    //std::call_once(flag1, printHello);
    printHello();
}
int main(){
    std::thread st1(threadFunction);
    std::thread st2(threadFunction);
    std::thread st3(threadFunction);
    st1.join();
    st2.join();
    st3.join();
    return 0;
}