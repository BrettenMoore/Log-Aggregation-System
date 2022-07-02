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
}

std::vector<int> LogAggregator::getLogsFromMachine(int machineId)
{
    return std::vector<int>();
}

std::vector<int> LogAggregator::getLogsOfService(int serviceId)
{
    return std::vector<int>();
}

std::vector<std::string> LogAggregator::search(int serviceId, std::string searchString)
{
    return std::vector<std::string>();
}
