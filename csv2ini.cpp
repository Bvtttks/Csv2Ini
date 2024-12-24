#include "csv2ini.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    if (argc != 3) {
        cout << "To set folder or file path, use --path key." << endl;
        return 1;
    }
    string str = argv[1];
    if (str != "--path") {
        cout << "To set folder or file path, use --path key." << endl;
        return 1;
    }
    str = argv[2];
    IniConverter conv;
    if (str.substr(str.size() - 4, 4) == ".csv") {
        conv.FileToIni(argv[2]);
    } else {
        conv.FolderToIni(argv[2]);
    }
    return 0;
}
