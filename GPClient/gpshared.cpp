#include "gpshared.h"

#include <plog/Log.h>
#include <cstring>

// options from command line arguments
char* gpServer = nullptr;
char* gpUser = nullptr;
char* gpPassword = nullptr;
bool gpAutoConnect = false;

// initialize shared variables
void initGpShared(int argc, char *argv[]) {
    PLOGI << "init shared ";

    int idx = 1;
    gpServer = argc >= (++idx) ? argv[idx - 1] : nullptr;
    gpUser = argc >= (++idx) ? argv[idx - 1] : nullptr;
    gpPassword = argc >= (++idx) ? argv[idx - 1] : nullptr;
    gpAutoConnect = strcmp((argc >= (++idx) ? argv[idx - 1] : ""), "autoConnect") == 0;
}
