#include <iostream>
#include <random>

using namespace std;
random_device rd;
int generateRandomArrivalTime()
{

    uniform_int_distribution<int> dist(0, 100);
    // cout << dist(rd) << " ";
    return dist(rd);
}

int generateRandomBurstTime()
{
    // random_device rd;
    uniform_int_distribution<int> dist(0, 20);
    // cout << dist(rd) << " ";
    return dist(rd);
}