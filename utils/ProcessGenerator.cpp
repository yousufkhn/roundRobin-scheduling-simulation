#include <vector>
#include "./Random.cpp"
#include "../entities/Process.h"

using namespace std;

std::vector<Process> randomProcessGenerator(int count)
{
    vector<Process> processes;
    for (int i = 1; i <= count; i++)
    {
        int arrivalTime = generateRandomArrivalTime();
        int burstTime = generateRandomBurstTime();

        processes.push_back(Process(i, arrivalTime, burstTime, 0, 0));
    }
    // for (const Process &process : processes)
    // {
    //     cout << "Task Id: " << process.id << " Arrival Time: " << process.arrivalTime << " Burst Time: " << process.burstTime << "\n";
    // }
    return processes;
}