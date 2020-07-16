#include <vector>
#include <thread>
#include <iostream>
#include <mutex>
class Counter {
public:
    Counter() {
        m_value = 0;
    };
    int getValue() {
        return m_value;
    };
    int getValue2(){
        return m_value2;
    }
    void increment() {
        std::lock_guard<std::mutex> lock(m_mutex);
        ++m_value;
    };
    void increment2(){
        std::lock_guard<std::mutex> lock2(m_mutex2);
        ++m_value2;
    }
private:
    int m_value;
    int m_value2;
    std::mutex m_mutex;
    std::mutex m_mutex2;
};
void incrementCounterManyTimes(Counter & counter ) {
    for( int i = 0; i < 5000; i++ ) {
        counter.increment();
        counter.increment2();
    }
}
int main() {
    Counter counter;
    std::vector<std::thread> threads;
    for( int i = 0; i < 5; i++ ) {
        threads.push_back(std::thread(incrementCounterManyTimes,std::ref(counter)));
    }
    for( int i = 0; i < 5; i++ ) {
        threads[i].join();
    }
    std::cout << counter.getValue() << "\n";
    std::cout << counter.getValue2() << "\n";
    return 0;
}