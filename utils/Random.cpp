#include <iostream>
#include <random>

using namespace std;
random_device rd;

int generateRandomArrivalTime()
{
    uniform_int_distribution<int> dist(0, 100);
    return dist(rd);
}

int generateRandomBurstTime()
{
    uniform_int_distribution<int> dist(0, 30);
    return dist(rd);
}