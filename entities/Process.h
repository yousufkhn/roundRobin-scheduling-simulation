#ifndef PROCESS_H
#define PROCESS_H

class Process
{
public:
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnAroundTime;

    Process(int id, int arrivalTime, int burstTime, int waitingTime, int turnAroundTime);
};

#endif