#ifndef GUIPART
#define GUIPART
#include "Basics.h"
int terminalWidth;
int getTerminalWidth() {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    return w.ws_col;
}
void linePrinter(){
    for(int i=0;i<terminalWidth;i++){
        cout<<"=";
    }
    cout<<endl;
}
#endif