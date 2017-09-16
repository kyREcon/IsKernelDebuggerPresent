# IsKernelDebuggerPresent

WTF?!?
------
Detects if a Kernel mode debugger is active by reading the value of KUSER_SHARED_DATA.KdDebuggerEnabled. 
It is a high level and portable implementation  between 32 and 64-bit architectures which has several
advantages compared to abusing NtQuerySystemInformation as described in the following article:
http://www.anti-reversing.com/detecting-kmds-with-a-single-instruction/

The KUSER_SHARED_DATA is always located in userland at address 0x7FFE0000 in the virtual
address space of every process. Furthemore, the relative offset of KdDebuggerEnabled member
remains the same as well in all recent Windows versions between XP and Windows 10 v1703.

The function has a fail safe in case the predefined address of KUSER_SHARED_DATA is not valid
anymore, in terms of avoiding a page fault that would crash your program.

However, if that address belongs to an allocated memory page that is now being used by something
else due to an internal update in Windows, then the result returned by the function will be wrong.

That being said, you should verify yourself that the above information remains valid before
using this method.

　
Disclaimer
----------
I wrote this for fun to use in other private projects. Use at your own risk.

　
Author
------
Author: Kyriakos Economou (@kyREcon) / www.anti-reversing.com

　
MIT License
-----------

Copyright (c) [2017] [Kyriakos Economou]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
