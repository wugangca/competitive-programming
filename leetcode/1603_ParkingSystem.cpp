#include <bits/stdc++.h>
using namespace std;

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        space[0] = big;
        space[1] = medium;
        space[2] = small;
     }
    
    bool addCar(int carType) {
        int index = carType - 1;
        if (space[index] == 0) {
            return false;
        } else {
            space[index] --;
            return true;
        }
    }
    
    private:
    int space[3];
};
