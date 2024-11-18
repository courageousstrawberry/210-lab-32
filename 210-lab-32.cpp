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
            
            // Check if the lane is empty
            if (!(lanes[i].empty())) {
                cout << "Lane: " << i << endl;
            
                if (rand_num <= SHIFT_PROB){
                    Car shifting = lanes[i].back();
                    lanes[i].pop_back();
                    int newLane = rand() % 4;
                    while (newLane == i) {
                        newLane = rand() % 4;
                    }
                    lanes[newLane].push_back(shifting);
                    cout << " Switched: ";
                    shifting.print();
                }
                // If 39% a new car enters the lane
                else if (rand_num <= JOIN_PROB){
                    Car add;
                    lanes[i].push_back(add);
                    cout << " Joined: ";
                    lanes[i].back().print();
                }
                // If probability is 46%, the front car pays it's toll
                else if (rand_num <= PAY_PROB){
                    cout << " Paid: ";
                    lanes[i].front().print();
                    lanes[i].pop_front();
                }

            }
            // Lane is empty
            else {
                // 50% probability if a new car is added or not
                if (rand_num <= 0.5) {
                    Car add;
                    lanes[i].push_back(add);
                    cout << " Joined: ";
                    lanes[i].back().print();
                }
            }

            // Display the queue of cars
            for (int i = 0; i < 4; i++){
                cout << "Lane: " << i << " Queue: " << endl;
                if (lanes[i].empty()) {
                    cout << "Empty" << endl;
                }
                for (Car& car : lanes[i]){
                    car.print();
                }
                cout << endl;
            }
        }
    }

    return 0;
}