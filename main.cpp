#include <iostream>
#include "auth.h"
#include "Process.h"

using namespace std;

int main()
{
    cout << "Operative System is booting up\n" << endl;

    authenticateUser();

    Process process1(1, 1, 3, 1, 2, 1);

    cout << process1.getState() << endl;
    process1.execute();
    cout << process1.getState();
}
