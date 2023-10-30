#include <fstream>

void ganttChartPrinter(std::string data)
{
    std::ofstream outData("../data/ganttChart.txt");

    if (outData.is_open())
    {
        outData << data;
    }
}