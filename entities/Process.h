#ifndef PROCESS_H
#define PROCESS_H

class Process
{
public:
    int id;
    int arrivalTime;
    int burstTime;

    Process(int id, int arrivalTime, int burstTime);
};

#endif