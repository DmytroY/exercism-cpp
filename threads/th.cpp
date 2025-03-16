#include <iostream>
#include <thread>
#include <future>

void backgroundTask(std::promise<int> resultPromise) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
    int result = 42; // The result of the background task
    resultPromise.set_value(result); // Set the result
}

int main() {
    std::promise<int> resultPromise;
    std::future<int> resultFuture = resultPromise.get_future();

    std::jthread workerThread(backgroundTask, std::move(resultPromise));

    std::cout << "Waiting for the result from the background task...\n";
    int result = resultFuture.get(); // Wait for the result
    std::cout << "Result from the background task: " << result << std::endl;

    return 0;
}