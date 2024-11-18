#include <iostream>
#include "Car.h"
#include <deque>
#include <random>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    // Initialize deque with two cars
    deque<Car> lanes[4];
    int count = 0;

    // Initialize the 4 lanes with a random number of cars from 1-3
    for (int i = 0; i < 4; i++){
        int num_cars = 1 + rand() % 3;
        for (int j = 0; j < num_cars; j++) {
            lanes[i].emplace_back();
        }
    }

    cout << "Initial que: " << endl;
    for (Car& car : booth){
        car.print();
    }

    // Loop until all cars have payed tolls
    while(!(booth.empty())) {
        count++;
        cout << "Time: " << count;
        int rand_num = 1 + rand() % 100; // Random probability number

        // If probability is 55%, the front car pays it's toll
        if (rand_num <= 55){
            cout << " Operation: Car paid: ";
            booth.front().print();
            booth.pop_front();
        }
        else {
            // Otherwise, the last car enters the lane
            Car add;
            booth.push_back(add);
            cout << " Operation: Joined lane: ";
            booth.back().print();
        }

        // Display the queue of cars
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