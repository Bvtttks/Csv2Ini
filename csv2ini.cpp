#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

class IniConverter
{
public:
    void FolderToIni(filesystem::path CsvFolderPath) {
        string IniFolderPath = CsvFolderPath.string() + "_ini";
        fs::create_directory(IniFolderPath);
        IniFolderPath += '/';
        size_t size = CsvFolderPath.string().size() + 1;
        
        for (const auto & csv : fs::directory_iterator(CsvFolderPath)) {
            string str = csv.path();
            if(str.substr(str.size() - 4, 4) != ".csv")
                continue;
            ifstream CsvRead(csv);
            str = IniFolderPath + str.substr(size, str.size() - size - 4) + ".ini";
            ofstream IniWrite(str);
            _convert(CsvRead, IniWrite);
            IniWrite.close();
            CsvRead.close();
        }
    }
    
private:
    void _convert(ifstream& CsvRead, ofstream& IniWrite) {
        vector<string> chapters;
        string str;
        getline(CsvRead, str);
        while(!str.empty())
            chapters.push_back(_parse(str));
        
        int counter = 1;
        while(getline(CsvRead, str)) {
            IniWrite << "[#" << counter << ']' << endl;
            ++counter;
            for (auto& chap : chapters)
                IniWrite << chap << '=' << _parse(str) << endl;
        }
    }

    string _parse(string& str) {
        string result = str;
        
        if (str[0] == '"') {
            result[0] = '-';
            size_t pos = result.find_first_of('"');
            result = result.substr(1, pos - 1);
            str = str.substr(pos + 2, str.size());
            return result;
        }
        
        size_t pos = result.find_first_of(',');
        
        result = result.substr(0, pos);
        if (pos == -1) {
            str.clear();
        } else {
            str = str.substr(pos + 1, str.size());
        }
        return result;
    }
    
};
