#include <iostream>
using namespace std;

#include "IsKernelDebuggerPresent.h"

int main()
{
	if (IsKernelDebuggerPresent() == KERNEL_DEBUGGER_DETECTED)
		cout << "KD Debugger: Detected!" << endl;
	else if (IsKernelDebuggerPresent() == KERNEL_DEBUGGER_NOT_DETECTED)
		cout << "KD Debugger: Not Detected!" << endl;
	else if (IsKernelDebuggerPresent() == INVALID_PTR)
		cout << "Invalid Ptr!";
	
	cin.get();
	return 0;
}