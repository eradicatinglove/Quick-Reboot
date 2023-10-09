#include <stdio.h>
#include <string.h>
#include <switch.h>

// quick reboot switch *for mariko reboot only*
int main(int argc, char **argv) {
  consoleInit(NULL);

  // supported input layout
  padConfigureInput(1, HidNpadStyleSet_NpadStandard);

  // initialize the default gamepad
  PadState pad;
  padInitializeDefault(&pad);

  printf("\x1b[0;33H Quick Reboot");
  printf("\x1b[16;30H press [-] to reboot");
  printf("\x1b[25;30H press [L] to exit");
  printf("\x1b[50;60H by eradicatinglove");

  // Main loop
  while (appletMainLoop()) {
    // scans the gamepad.
    padUpdate(&pad);
    u64 kDown = padGetButtonsDown(&pad);

    if (kDown & HidNpadButton_Minus) {
      spsmInitialize();
      spsmShutdown(true);
    } else if (kDown & HidNpadButton_L) {
      break;  // return to hbmenu
    }

    // update the console, sending a new frame to the display
    consoleUpdate(NULL);
  }

  // Deinitialize and clean up resources used by the console.
  consoleExit(NULL);
  return 0;
}
