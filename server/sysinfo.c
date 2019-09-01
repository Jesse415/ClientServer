#include "common.h"
#pragma comment(lib, "user32.lib")

void systemInfo(char *bufferaddr) {
#ifdef _WIN32
    SYSTEM_INFO sysInfo;

    // Copy the hardware information to the SYSTEM_INFO structure.
    GetSystemInfo(&sysInfo);

    // Display the contents of the SYSTEM_INFO structure.

    sprintf(bufferaddr, "Hardware information: \n"
                        "  OEM ID: %lu\n Number of processors: %lu\n"
           "  Page size: %lu\n"
           "  Processor type: %lu\n"
           "  Minimum application address: %lx\n"
           "  Maximum application address: %lx\n"
           "  Active processor mask: %llu\n",
           sysInfo.dwOemId, sysInfo.dwNumberOfProcessors,
           sysInfo.dwPageSize, sysInfo.dwProcessorType,
           sysInfo.lpMinimumApplicationAddress,
           sysInfo.lpMaximumApplicationAddress,
           sysInfo.dwActiveProcessorMask );

#else
    struct utsname uname_pointer;

    uname(&uname_pointer);


    sprintf(bufferaddr, "System name - %s \nNodename    - %s \n"
                        "Release     - %s \nVersion     - %s\n"
                        "Machine     - %s",
            uname_pointer.sysname, uname_pointer.nodename,
            uname_pointer.release, uname_pointer.version,
            uname_pointer.machine);
#endif
}