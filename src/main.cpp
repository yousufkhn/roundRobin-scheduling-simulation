#include <iostream>
#include "Random.cpp"
#include "Process.cpp"
#include <vector>
#include <random>

using namespace std;

int main()
{

    int numberOfProcess;

    cout << "Enter the number of random process u want to generate : ";
    cin >> numberOfProcess;

    vector<Process> processes;

    for (int i = 1; i <= numberOfProcess; i++)
    {
        int arrivalTime = generateRandomArrivalTime();
        int burstTime = generateRandomBurstTime();

        processes.push_back(Process(i, arrivalTime, burstTime));
    }
    for (const Process &process : processes)
    {
        cout << "Task Id: " << process.id << " Arrival Time: " << process.arrivalTime << " Burst Time: " << process.burstTime << "\n";
    }
}