#include "thread_pool.h"
#include <iostream>
#include <chrono>

int main() {
    ThreadPool pool(8);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            pool.post([i, j]{
                std::cout << "hello world " << "i: " << i << " j: " << j << std::endl;
            });
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
