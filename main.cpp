#include <iostream>
#include <vector>
#include <algorithm>
#include "auth.h"
#include "Process.h"

using namespace std;

void FCFS(vector<Process> processes) {
    float averageWait;
    float averageTurnaround;
    int wait = 0;
    float sum = 0;

    for (int i = 0; i < processes.size(); i++) {
        processes.at(i).setWaitingTime(wait);
        processes.at(i).execute(0);
        processes.at(i).setTurnaroundTime(processes.at(i).getTurnaroundTime() + wait);
        wait += processes.at(i).getBurstTime();
    }

    for (int i = 0; i < processes.size(); i++) {
        sum += processes.at(i).getTurnaroundTime();
    }
    averageTurnaround = sum / processes.size();
    sum = 0;
    for (int i = 0; i < processes.size(); i++) {
        sum += processes.at(i).getWaitingTime();
    }
    averageWait = sum / processes.size();
    cout << "FCFS:" << endl << endl;
    for (int i = 0; i < processes.size(); i++) {
        cout << "P" << processes.at(i).getPid() << ":" << endl;
        cout << "Turnaround Time: " << processes.at(i).getTurnaroundTime() << endl;
        cout << "Wait Time: " << processes.at(i).getWaitingTime() << endl;
        cout << "Burst Time: " << processes.at(i).getBurstTime() << endl << endl;
    }
    cout << "Average Turnaround Time: " << averageTurnaround << endl;
    cout << "Average Wait Time: " << averageWait << endl << endl;
}

bool compareBurst(Process& a, Process& b) {
    return a.getBurstTime() < b.getBurstTime();
}

void SJF(vector<Process> processes) {
    float averageWait;
    float averageTurnaround;
    int wait = 0;
    float sum = 0;

    sort(processes.begin(), processes.end(), compareBurst);

    for (int i = 0; i < processes.size(); i++) {
        processes.at(i).setWaitingTime(wait);
        processes.at(i).execute(0);
        processes.at(i).setTurnaroundTime(processes.at(i).getTurnaroundTime() + wait);
        wait += processes.at(i).getBurstTime();
    }

    for (int i = 0; i < processes.size(); i++) {
        sum += processes.at(i).getTurnaroundTime();
    }
    averageTurnaround = sum / processes.size();
    sum = 0;
    for (int i = 0; i < processes.size(); i++) {
        sum += processes.at(i).getWaitingTime();
    }
    averageWait = sum / processes.size();
    cout << "SJF:" << endl << endl;
    for (int i = 0; i < processes.size(); i++) {
        cout << "P" << processes.at(i).getPid() << ":" << endl;
        cout << "Turnaround Time: " << processes.at(i).getTurnaroundTime() << endl;
        cout << "Wait Time: " << processes.at(i).getWaitingTime() << endl;
        cout << "Burst Time: " << processes.at(i).getBurstTime() << endl << endl;
    }
    cout << "Average Turnaround Time: " << averageTurnaround << endl;
    cout << "Average Wait Time: " << averageWait << endl << endl;
}

void SRT(vector<Process> processes) {
    int time = 0;
    int complete = 0;
    float sum = 0;
    float averageWait;
    float averageTurnaround;
    

    while (complete < processes.size()){
        Process* shortest = nullptr;

        for (int i = 0; i < processes.size(); i++) {
            if (processes.at(i).getArrivalTime() <= time && processes.at(i).getRemainingTime() > 0) {
                
                if (shortest == nullptr || processes.at(i).getRemainingTime() < shortest->getRemainingTime()) {
                    shortest = &processes.at(i);
                }
            }
        }

        if (shortest != nullptr) {
            shortest->execute(1);
            time++;

            if (shortest->getRemainingTime() == 0) {
                complete++;
                shortest->setWaitingTime(time - shortest->getBurstTime() - shortest->getArrivalTime());
                shortest->setTurnaroundTime(shortest->getWaitingTime() + shortest->getBurstTime());    
            }

        }
        else {
            time++;
        }
    }
    for (int i = 0; i < processes.size(); i++) {
        sum += processes.at(i).getTurnaroundTime();
    }
    averageTurnaround = sum / processes.size();
    sum = 0;
    for (int i = 0; i < processes.size(); i++) {
        sum += processes.at(i).getWaitingTime();
    }
    averageWait = sum / processes.size();
    cout << "SRT:" << endl << endl;
    for (int i = 0; i < processes.size(); i++) {
        cout << "P" << processes.at(i).getPid() << ":" << endl;
        cout << "Turnaround Time: " << processes.at(i).getTurnaroundTime() << endl;
        cout << "Wait Time: " << processes.at(i).getWaitingTime() << endl;
        cout << "Burst Time: " << processes.at(i).getBurstTime() << endl << endl;
    }
    cout << "Average Turnaround Time: " << averageTurnaround << endl;
    cout << "Average Wait Time: " << averageWait << endl << endl;

}


int main()
{
    cout << "Operative System is booting up\n" << endl;

    authenticateUser();

    vector<Process> processes = {
        {1, 0, 8, 0, 0, 1}, {2, 1, 4, 0, 0, 1}, {3, 2, 9, 0, 0, 1}, {4, 3, 5, 0, 0, 1}

    };

    FCFS(processes);
    SJF(processes);
    SRT(processes);
}
