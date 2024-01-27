#include <iostream>
#include <sys/ioctl.h>

int getTerminalWidth() {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    return w.ws_col;
}

int main() {
    int terminalWidth = getTerminalWidth();

    std::cout << "Terminal width: " << terminalWidth << " columns" << std::endl;

    // Print '=' symbols based on the terminal width
    for (int i = 0; i < terminalWidth; ++i) {
        std::cout << "=";
    }

    std::cout << std::endl;

    return 0;
}
