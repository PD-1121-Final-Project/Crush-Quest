
#ifndef FUNCTION_H // If FUNCTION_H is not defined
#define FUNCTION_H // Define FUNCTION_H
#include <string>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
using namespace std;

void slowPrint(string s, termios* orig_termios = nullptr);
void sleep(int ms);
void rangePrint(double x);
void printDashedLine();
double mapLuckToRandomRatio(int luck);

#endif // FUNCTION_H
