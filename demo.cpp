#include <iostream>
#include "Basics.h"
int main() {
    queue<int> qu;
    qu.push(10);
    cout<<qu.back();
    cout<<endl;
    qu.push(11);
    qu.push(12);
    qu.pop();
    cout<<qu.back();
    cout<<endl;
    return 0;
}