#include "Process.h"

Process::Process(int pid, int arrival_time, int burst_time, int priority, int memory_required, bool io_operations)
	: pid(pid), arrival_time(arrival_time), burst_time(burst_time), priority(priority), memory_required(memory_required), io_operations(io_operations),
	state("NEW"), remaining_time(burst_time), waiting_time(0), turnaround_time(0) {}


void Process::updateState(std::string newState) {
	state = newState;
}

void Process::setWaitingTime(int time) {
	waiting_time = time;
}

void Process::setTurnaroundTime(int time) {
	turnaround_time = time;
}

void Process::execute(int type) {
	updateState("RUNNING");

	if (type == 1) {
		turnaround_time++;
		remaining_time--;
		return;
	}
	else {
		for (int i = 0; i < burst_time; i++) {
			turnaround_time++;
			remaining_time--;
		}
	}
	updateState("TERMINATED");
}

int Process::getPid() {
	return pid;
}

int Process::getArrivalTime() {
	return arrival_time;
}

int Process::getBurstTime() {
	return burst_time;
}

int Process::getPriority() {
	return priority;
}

std::string Process::getState() {
	return state;
}

int Process::getRemainingTime() {
	return remaining_time;
}

int Process::getWaitingTime() {
	return waiting_time;
}

int Process::getTurnaroundTime() {
	return turnaround_time;
}

int Process::getMemoryRequired() {
	return memory_required;
}

bool Process::ioOperations() {
	return io_operations;
}
