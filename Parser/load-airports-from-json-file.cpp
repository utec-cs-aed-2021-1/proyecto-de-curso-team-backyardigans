#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>
#include <fstream>

int main()
{
    boost::property_tree::ptree pt;
    boost::property_tree::read_json("Data/airports.json", pt);

    for(auto& airport : pt) {
      for(auto& prop : airport.second)
          std::cout << prop.first
                    << ": "
                    << prop.second.get_value<std::string>()
                    << std::endl;
      
      std::cout << std::endl;
    }
	
}
