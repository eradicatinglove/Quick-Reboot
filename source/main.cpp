#include <string.h>
#include <stdio.h>

#include <switch.h>

//quick reboot switch
//*for mariko reboot only*
int main(int argc, char **argv)
{
    consoleInit(NULL);
   
    bpcInitialize();
   
    bpcRebootSystem();
   
    return 0;
}

