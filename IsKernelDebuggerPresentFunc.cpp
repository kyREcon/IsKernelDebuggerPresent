#include "IsKernelDebuggerPresent.h"

int IsKernelDebuggerPresent()
{
	__try{
		if ((*(unsigned char*)(KUSER_SHARED_DATA_ADDRESS + KD_DEBUGGER_ENABLED_OFFSET) & 3) != 0)
			return KERNEL_DEBUGGER_DETECTED;
		else
		return KERNEL_DEBUGGER_NOT_DETECTED;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return INVALID_PTR;
	}
	


}