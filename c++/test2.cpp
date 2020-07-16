#include <iostream>
#include <thread>
//using namespace std;
void threadFunction() {
    std::cout << "Hello from thread 1\n";
}
int main() {
    std::thread th(threadFunction);
    std::cout << "Hello from thread 0\n";
    th.join();
}