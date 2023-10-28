#include <iostream>
#include "../utils/ProcessGenerator.cpp"
#include <vector>
#include <queue>

using namespace std;

int main()
{

    int numberOfProcess;
    int timeQuantum;

    cout << "Enter the number of random process u want to generate : ";
    cin >> numberOfProcess;

    cout << "Enter the time quantum for Round Robin: ";
    cin >> timeQuantum;

    vector<Process> processes;
    queue<Process> readyQueue;

    processes = randomProcessGenerator(numberOfProcess);

    for (const Process &process : processes)
    {
        cout << "Task Id: " << process.id << " Arrival Time: " << process.arrivalTime << " Burst Time: " << process.burstTime << "\n";
    }
}