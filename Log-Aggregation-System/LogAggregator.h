#pragma once
#include <string>
#include <vector>

class LogAggregator
{
public:
	LogAggregator(int machines, int services);
	void pushLog(int logId, int machineId, int serviceId, std::string message);
	std::vector<int> getLogsFromMachine(int machineId);
	std::vector<int> getLogsOfService(int serviceId);
	std::vector<std::string> search(int serviceId, std::string searchString);
private:
	int machines;
	int services;
	struct logInstance
	{
		int logId;
		int machineId;
		int serviceId;
		std::string message;
	};

	logInstance log;
	std::vector<logInstance> logList;
};

