#include <iostream>
#include <string>
#include <yaml-cpp/yaml.h>
#include <filesystem>
#include <cassert>

namespace fs = std::filesystem;

fs::path confg = "/home/void/Scripts/c/vtube-tui/conf.yaml";


int main () 
{

    YAML::Node userConfig = YAML::LoadFile(confg.string());
    YAML::Node data_node = userConfig["vtubers"];
    assert(userConfig["vtubers"].IsMap());
    for(YAML::const_iterator it = data_node.begin(); it != data_node.end(); ++it)
    {
        YAML::Node node = it->first;
        std::cout << data_node[node]["url"] << "\n";
        std::cout << node.as<std::string>() << "\n";
    }


    return 0;
}
