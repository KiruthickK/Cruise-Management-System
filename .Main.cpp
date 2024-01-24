#include "Basics.h"
#include "FileManagement.h"
#include "Cruise.h"

namespace fs = std::filesystem;

int main() {
    FileManager m;
    vector<string> res = m.getUserIds();
    for(string s:res){
        cout<<s<<endl;
    }
    return 0;
}
