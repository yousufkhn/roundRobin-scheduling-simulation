#include <iostream>

class Process
{
public:
    int id;
    int arrivalTime;
    int burstTime;

    Process(int id, int arrivalTime, int burstTime)
        : id(id), arrivalTime(arrivalTime), burstTime(burstTime)
    {
    }
};