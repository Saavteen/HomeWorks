#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include <chrono> 
//100000000

void sum_vector(const std::vector<int>& vec, int start, int end, long long& result) {
    result = std::accumulate(vec.begin() + start, vec.begin() + end, 0LL);
}

int main() {
    std::vector<int> vec(10000, 1);
    int num_threads = 1;
    std::vector<std::thread> threads(num_threads);
    std::vector<long long> results(num_threads);

    int chunk_size = vec.size() / num_threads;

    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < num_threads; ++i) {
        int start = i * chunk_size;
        int end = (i == num_threads - 1) ? vec.size() : (i + 1) * chunk_size;
        threads[i] = std::thread(sum_vector, std::cref(vec), start, end, std::ref(results[i]));
    }

    long long total_sum = 0;
    for (int i = 0; i < num_threads; ++i) {
        threads[i].join();
        total_sum += results[i];
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    std::cout << "Total sum: " << total_sum << std::endl;
    std::cout << "Time: " << duration << " ms" << std::endl;

    return 0;
}
