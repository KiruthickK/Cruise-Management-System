#include "Basics.h"
#include "FileManagement.h"
namespace fs = std::filesystem;

int main() {
    FileManager m;
    vector<string> res = m.getCruiseIds();
    for(string s:res){
        cout<<s<<endl;
    }
    return 0;
}
