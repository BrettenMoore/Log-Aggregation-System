// Log-Aggregation-System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"LogAggregator.h"

int main()
{
    LogAggregator logAggregator = LogAggregator(3, 3);
    logAggregator.pushLog(2322, 1, 1, "Machine 1 Service 1 Log 1");
    logAggregator.pushLog(2312, 1, 1, "Machine 1 Service 1 Log 2");
    logAggregator.pushLog(2352, 1, 1, "Machine 1 Service 1 Log 3");
    logAggregator.pushLog(2298, 1, 1, "Machine 1 Service 1 Log 4");
    logAggregator.pushLog(23221, 1, 2, "Machine 1 Service 2 Log 1");
    logAggregator.pushLog(23121, 1, 2, "Machine 1 Service 2 Log 2");
    logAggregator.pushLog(23222, 2, 2, "Machine 2 Service 2 Log 1");
    logAggregator.pushLog(23122, 2, 2, "Machine 2 Service 2 Log 2");
    logAggregator.pushLog(23521, 1, 2, "Machine 1 Service 2 Log 3");
    logAggregator.pushLog(22981, 1, 2, "Machine 1 Service 2 Log 4");
    logAggregator.pushLog(23522, 2, 2, "Machine 2 Service 2 Log 3");
    logAggregator.pushLog(22982, 2, 2, "Machine 2 Service 2 Log 4");

    logAggregator.getLogsFromMachine(2); // return [23222, 23122, 23522, 22982]
                                         // Machine 2 added 4 logs, so we return them in the order
                                         // they were added.
    logAggregator.getLogsOfService(2);   // return [23221, 23121, 23222, 23122, 23521, 22981, 23522, 22982]
                                         // 8 logs were added while running service 2 on a machine.
    logAggregator.search(1, "Log 1");    // return ["Machine 1 Service 1 Log 1"]
                                         // There is only one log that was added while running service 1
                                         // and contains "Log 1".
    logAggregator.search(2, "Log 3");    // return ["Machine 1 Service 2 Log 3", "Machine 2 Service 2 Log 3"]
                                         // 2 logs were added while running service 2 that contain "Log 3".

    return 0;
}

