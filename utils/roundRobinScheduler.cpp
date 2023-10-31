#include <queue>
#include <algorithm>
#include <vector>
#include "../entities/Process.h"
#include "ganttChartGenerator.cpp"
#include "ganttChartPrinter.cpp"
#include <map>

using namespace std;

void roundRobinScheduler(vector<Process> &processes, int timeQuantum)
{
    queue<Process> readyQueue;
    int currentTime = 0;
    int remainingProcesses = processes.size();
    int tabsCount = 0;
    string ganttChartGeneratorData;
    double avgTurnaroundTime = 0.0;
    double avgWaitingTime = 0.0;
    map<int, int> tatMap;

    // this sort function is sorting the processes vector according to their arrival time so that its
    // easier to impliment the round robin scheduling
    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
         { return a.arrivalTime < b.arrivalTime; });

    int processesIndex = 0;
    while (remainingProcesses > 0)
    {
        if (!readyQueue.empty())
        {
            Process currentProcess = readyQueue.front();
            readyQueue.pop();

            int executionTime = min(timeQuantum, currentProcess.burstTime);
            currentProcess.burstTime -= executionTime;
            currentTime += executionTime;
            tabsCount += (executionTime + 8);
            ganttChartGeneratorData += ganttChartGenerator(tabsCount, currentProcess.id, executionTime);

            if (currentProcess.burstTime == 0)
            {
                tatMap[currentProcess.id] = currentTime - currentProcess.arrivalTime;
                remainingProcesses--;
            }

            while (processes[processesIndex].arrivalTime <= currentTime)
            {
                readyQueue.push(processes[processesIndex]);
                processesIndex++;
            }
            if (currentProcess.burstTime > 0)
            {
                readyQueue.push(currentProcess);
            }
        }
        else
        {
            // cout << "| IDLE |" << endl;
            currentTime++;
            while (!processes.empty() && processes[processesIndex].arrivalTime <= currentTime)
            {
                readyQueue.push(processes[processesIndex]);
                processesIndex++;
            }
        }
    }

    cout << "\nProcess ID\tWaiting Time\tTurn Around Time" << endl;
    for (const Process &process : processes)
    {
        cout << process.id << "\t\t" << tatMap[process.id] - process.burstTime << "\t\t" << tatMap[process.id] << endl;
        avgTurnaroundTime += tatMap[process.id];
        avgWaitingTime += tatMap[process.id] - process.burstTime;
    }
    avgTurnaroundTime /= processes.size();
    avgWaitingTime /= processes.size();
    cout << "Average Turnaround Time: " << avgTurnaroundTime << " units" << endl;
    cout << "Average Waiting Time: " << avgWaitingTime << " units" << endl;

    ganttChartPrinter(ganttChartGeneratorData);
}