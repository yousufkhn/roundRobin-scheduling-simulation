#include <iostream>
#include <fstream>

using namespace std;
string ganttChartGenerator(int tabsCount, int id, int executionTime)
{
    string ganttChartGeneratorData;

    // cout << "Task " << id;
    ganttChartGeneratorData += "Task ";
    ganttChartGeneratorData += to_string(id);
    for (int i = 0; i < executionTime; i++)
    {
        // cout << "-";
        ganttChartGeneratorData += "-";
    }
    // cout << ">" << endl;
    ganttChartGeneratorData += ">\n";
    for (int i = 0; i < tabsCount; i++)
    {
        // cout << " ";
        ganttChartGeneratorData += " ";
    }

    return ganttChartGeneratorData;
}