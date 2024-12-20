#include "csv2ini.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        cout << "To set folder path, use --path key." << endl;
        return 1;
    }
    string path = argv[1];
    if (path.substr(0, 7) != "--path ") {
        cout << "To set folder path, use --path key." << endl;
        return 1;
    }
    path = path.substr(7, path.size());
    IniConverter conv;
    conv.FolderToIni(path);
    return 0;
}
