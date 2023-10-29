#include "Process.h"

Process::Process(int id, int arrivalTime, int burstTime, int waitingTime, int turnAroundTime)
    : id(id), arrivalTime(arrivalTime), burstTime(burstTime), waitingTime(waitingTime), turnAroundTime(turnAroundTime)
{
}