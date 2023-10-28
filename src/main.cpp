#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "../utils/roundRobinScheduler.cpp"
// #include "../utils/Random.cpp"
#include "../entities/Process.h"
#include "../utils/ProcessGenerator.cpp"

using namespace std;

int main()
{
    int numberOfProcess;
    int timeQuantum;

    cout << "Enter the number of random process u want to generate : ";
    cin >> numberOfProcess;

    cout << "Enter the time quantum for Round Robin: ";
    cin >> timeQuantum;

    vector<Process> processes = randomProcessGenerator(numberOfProcess);

    for (const Process &process : processes)
    {
        cout << "Task Id: " << process.id << " Arrival Time: " << process.arrivalTime << " Burst Time: " << process.burstTime << "\n";
    }

    roundRobinScheduler(processes, timeQuantum);
}