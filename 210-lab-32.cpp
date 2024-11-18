#include <iostream>
#include "Car.h"
#include <deque>
#include <random>
#include <ctime>

using namespace std;

const double PAY_PROB = 0.46;
const double JOIN_PROB = 0.39;
const double SHIFT_PROB = 0.15;

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
    for (int i = 0; i < 4; i++){
        cout << "Lane 1:" << endl;
        for (Car& car : lanes[i]){
            car.print();
        }
    }

    // Loop until all cars have payed tolls
    while(count < 20) {
        count++;
        cout << "Time: " << count << endl;

        for (int i = 0; i < 4; i++) {
            double rand_num = (rand() % 100) / 100.0; // Random probability number

            cout << "Lane: " << i << endl;
            // If probability is 55%, the front car pays it's toll
            if (rand_num <= PAY_PROB){
                cout << " Paid: ";
                lanes[i].front().print();
                lanes[i].pop_front();
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
    }

    return 0;
}