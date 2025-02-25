#pragma once
#include <string>
class Process
{
public:
	Process(int pid, int arrival_time, int burst_time, int priority, int memory_required, bool io_operations);
	void updateState(std::string newState);
	void execute();
	int getPid();
	int getArrivalTime();
	int getBurstTime();
	int getPriority();
	std::string getState();
	int getRemainingTime();
	int getWaitingTime();
	int getTurnaroundTime();
	int getMemoryRequired();
	bool ioOperations();

private:
	int pid;
	int arrival_time;
	int burst_time;
	int priority;
	std::string state;
	int remaining_time;
	int waiting_time;
	int turnaround_time;
	int memory_required;
	bool io_operations;

};

