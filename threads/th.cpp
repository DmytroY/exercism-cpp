#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;

int compute(int a, int b) {
    this_thread::sleep_for(chrono::seconds(3));
    return a + b;
}

int main() {
    future<int> th_result = async(launch::async, compute, 1, 2); // async returns a future object
    for (int i = 0; i < 10; i++) {
        cout << "Working..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        if (th_result.wait_for(chrono::seconds(0)) == future_status::ready) {
            cout << "Result is ready!" << endl;
            break;
        }
    }
    int result = th_result.get();
    cout << "Result: " << result << endl;
    return 0;
}