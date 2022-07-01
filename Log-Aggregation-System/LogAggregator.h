#pragma once
#include <string>

class LogAggregator
{
public:
	LogAggregator(int machines, int services);
	int pushLog(int logId, int machineId, int serviceId, std::string message);
private:
	int machines;
	int services;
};

