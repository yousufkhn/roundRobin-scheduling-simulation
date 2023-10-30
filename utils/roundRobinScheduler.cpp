#include <queue>
#include <algorithm>
#include <vector>
#include "../entities/Process.h"
#include "ganttChartGenerator.cpp"
#include "ganttChartPrinter.cpp"

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

    // this sort function is sorting the processes vector according to their arrival time so that its
    // easier to impliment the round robin scheduling
    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
         { return a.arrivalTime < b.arrivalTime; });

    int processesIndex = 0;
    int processesIndexForTurnAroundTime = 0;
    while (remainingProcesses > 0)
    {
        // Check for new arrivals and add them to the ready queue
        while (!processes.empty() && processes[processesIndex].arrivalTime <= currentTime)
        {
            readyQueue.push(processes[processesIndex]);
            processes[processesIndex].waitingTime = currentTime - processes[processesIndex].arrivalTime;
            processesIndex++;
        }

        if (!readyQueue.empty())
        {
            Process currentProcess = readyQueue.front();
            readyQueue.pop();

            int executionTime = min(timeQuantum, currentProcess.burstTime);
            currentProcess.burstTime -= executionTime;
            currentTime += executionTime;
            tabsCount += (executionTime + 8);

            ganttChartGeneratorData += ganttChartGenerator(tabsCount, currentProcess.id, executionTime);

            if (currentProcess.burstTime > 0)
            {
                readyQueue.push(currentProcess);
            }
            else
            {
                processes[processesIndexForTurnAroundTime].turnAroundTime = currentTime - processes[processesIndexForTurnAroundTime].arrivalTime;
                processesIndexForTurnAroundTime++;
                // cout << string(tabsCount, ' ') << "Task " << currentProcess.id << " has completed.\n";
                remainingProcesses--;
            }
        }
        else
        {
            // cout << "| IDLE |" << endl;
            currentTime++;
        }
    }

    cout << "\nProcess ID\tWaiting Time\tTurn Around Time" << endl;
    for (const Process &process : processes)
    {
        cout << process.id << "\t\t" << process.waitingTime << "\t\t" << process.turnAroundTime << endl;
        avgTurnaroundTime += process.turnAroundTime;
        avgWaitingTime += process.waitingTime;
    }
    avgTurnaroundTime /= processes.size();
    avgWaitingTime /= processes.size();
    cout << "Average Turnaround Time: " << avgTurnaroundTime << " units" << endl;
    cout << "Average Waiting Time: " << avgWaitingTime << " units" << endl;

    ganttChartPrinter(ganttChartGeneratorData);
}