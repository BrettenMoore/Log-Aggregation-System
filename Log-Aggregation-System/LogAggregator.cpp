#include "LogAggregator.h"

LogAggregator::LogAggregator(int machines, int services)
{
    this->machines = machines;
    this->services = services;
}

void LogAggregator::pushLog(int logId, int machineId, int serviceId, std::string message)
{
    log.logId = logId;
    log.machineId = machineId;
    log.serviceId = serviceId;
    log.message = message;

    logList.push_back(log);
}

std::vector<int> LogAggregator::getLogsFromMachine(int machineId)
{
    std::vector<int> result;
    for (auto& i : logList)
    {
        if (i.machineId == machineId)
        {
            result.push_back(i.logId);
        }
    }
    return result;
}

std::vector<int> LogAggregator::getLogsOfService(int serviceId)
{
    std::vector<int> result;
    for (auto& i : logList)
    {
        if (i.serviceId == serviceId)
        {
            result.push_back(i.logId);
        }
    }
    return result;
}

std::vector<std::string> LogAggregator::search(int serviceId, std::string searchString)
{
    std::vector<std::string> result;
    for (auto& i : logList)
    {
        if (i.serviceId == serviceId && i.message.find(searchString) != std::string::npos)
        {
            result.push_back(i.message);
        }
    }

    return result;
}
