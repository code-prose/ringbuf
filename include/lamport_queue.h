#include <atomic>
#include <optional>

namespace SPSC {

    template <typename T, std::size_t N>
    class LamportQueue {
    public:
        LamportQueue() = default;
        bool push(T elem);
        std::optional<T> pop();
    private:
        std::atomic_size_t front_{0};
        std::atomic_size_t back_{0};
        T data_[N];
    };

}
