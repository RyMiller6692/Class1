#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int main() {
    // Seed for random number generation
    srand(time(0));

    cout << "Welcome to the Reflex Timing Test!" << endl;
    cout << "You will see a prompt. Press Enter as quickly as possible after you see the prompt." << endl;
    cout << "Press Enter to start the test..." << endl;
    cin.get();  // Wait for user to press Enter

    // Random delay before showing the prompt
    int delay = rand() % 5000 + 1000;  // Delay between 1 and 5 seconds
    this_thread::sleep_for(milliseconds(delay));

    // Show prompt
    cout << "Now!" << endl;

    // Record time when prompt is displayed
    auto start = high_resolution_clock::now();

    // Wait for user input
    cin.get();

    // Record time when user presses Enter
    auto end = high_resolution_clock::now();

    // Calculate the reaction time
    auto duration = duration_cast<milliseconds>(end - start).count();

    cout << "Your reaction time is " << duration << " milliseconds." << endl;

    return 0;
}
