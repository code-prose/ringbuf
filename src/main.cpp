#include <print>
#include "lamport_queue.h"
#include <thread>


const int ITERATIONS = 1000;

void producer(SPSC::LamportQueue<int, ITERATIONS>& q);
void consumer(SPSC::LamportQueue<int, ITERATIONS>& q);

int main() {
    SPSC::LamportQueue<int, ITERATIONS> queue;
    std::thread p{producer, std::ref(queue)};
    std::thread c{consumer, std::ref(queue)};
    p.join();
    c.join();

    return 0;
}


void producer(SPSC::LamportQueue<int, ITERATIONS>& q) {
    for (int i = 0; i < ITERATIONS; i++) {
        q.push(i);
    }
}

void consumer(SPSC::LamportQueue<int, ITERATIONS>& q) {
    for (int i = 0; i < ITERATIONS; i++) {
        if (auto val = q.pop()) {
            std::print("consumer value: {}\n", *val);
        }
    }
}
