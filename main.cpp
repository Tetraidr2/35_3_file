#include <iostream>
#include <algorithm>
#include <filesystem>

int main() {
    auto  GetFileNames =[](std::filesystem::path path, const std::string extension) {
        std::vector<std::string> listName;
        auto print = [&listName, extension](auto p) {
            std::filesystem::path path1 = p.path();
            if(is_regular_file(path1) && path1.extension().string()==extension){
                listName.push_back(path1.filename().string());
            }
            //std::cout << p.path() << std::endl;
        };
        auto itt = std::filesystem::recursive_directory_iterator(path);
        std::for_each(begin(itt), end(itt), print);
        return listName;
    };
    auto vec = GetFileNames("D:\\Progect\\qvestexz",".dll");
    /* for(auto s : vec){
        std::cout<< s << std::endl;
    }
     */
    return 0;
}
