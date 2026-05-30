#include "lamport_queue.h"
#include "mutex_queue.h"
#include "optimized_ring_buffer.h"
#include <thread>
#include <benchmark/benchmark.h>

template <typename Queue> static void BM_Queue_Spec(benchmark::State &state) {
    Queue q;
    for (auto _ : state) {
        std::thread producer{[&]() {
            for (size_t i = 0; i < 1024; i++) {
                while(!q.push(1));
            }
        }};

        for (size_t i = 0; i < 1024; i++) {
            while(!q.pop());
        }
        producer.join();
    }

}

BENCHMARK_TEMPLATE(BM_Queue_Spec, Mutex::MutexQueue<int, 1024>);
BENCHMARK_TEMPLATE(BM_Queue_Spec, Lamport::LamportQueue<int, 1024>);
BENCHMARK_TEMPLATE(BM_Queue_Spec, SPSC::RingBuffer<int, 1024>);
