#include "common.h"

void systemInfo(char *bufferaddr){
    struct utsname uname_pointer;

    uname(&uname_pointer);


    sprintf(bufferaddr, "System name - %s \nNodename    - %s \n"
                        "Release     - %s \nVersion     - %s\n"
                        "Machine     - %s",
            uname_pointer.sysname, uname_pointer.nodename,
            uname_pointer.release, uname_pointer.version,
            uname_pointer.machine);
}