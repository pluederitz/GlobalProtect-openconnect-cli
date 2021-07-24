#ifndef GPSHARED_H
#define GPSHARED_H

// options from command line arguments
extern char* gpServer;
extern char* gpUser;
extern char* gpPassword;
extern bool gpAutoConnect;

// initialize shared variables
void initGpShared(int argc, char *argv[]);

#endif // GPSHARED_H
