#include <iostream>
#include <fstream>

using namespace std;
void ganttChartGenerator(int tabsCount, int id, int executionTime)
{
    cout << "Task " << id;
    for (int i = 0; i < executionTime; i++)
    {
        cout << "-";
    }
    cout << ">" << endl;
    for (int i = 0; i < tabsCount; i++)
    {
        cout << " ";
    }
}