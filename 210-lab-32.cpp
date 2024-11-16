#include <iostream>
#include "Car.h"
#include <deque>
#include <random>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    // Initialize deque with two cars
    deque<Car> booth(2);
    int count = 0;

    cout << "Initial que: " << endl;
    for (Car& car : booth){
        car.print();
    }

    
    while(!(booth.empty())) {
        count++;
        cout << "Time: " << count;
        int rand_num = 1 + rand() % 100;

        if (rand_num <= 55){
            cout << " Operation: Car paid: ";
            booth.front().print();
            booth.pop_front();
        }
        else {
            Car add;
            booth.push_back(add);
            cout << " Operation: Joined lane: ";
            booth.back().print();
        }

        cout << "Queue: " << endl;
        if (booth.empty()) {
            cout << "Empty" << endl;
        }
        for (Car& car : booth){
            car.print();
        }
        cout << endl;
    }

    return 0;
}