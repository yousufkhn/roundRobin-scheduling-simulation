#include <iostream>
#include <vector>
#include "../utils/Random.cpp"
#include "../entities/Process.cpp"

std::vector<Process> randomProcessGenerator(int count)
{
    vector<Process> processes;
    for (int i = 1; i <= count; i++)
    {
        int arrivalTime = generateRandomArrivalTime();
        int burstTime = generateRandomBurstTime();

        processes.push_back(Process(i, arrivalTime, burstTime));
    }
    // for (const Process &process : processes)
    // {
    //     cout << "Task Id: " << process.id << " Arrival Time: " << process.arrivalTime << " Burst Time: " << process.burstTime << "\n";
    // }
    return processes;
}