#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

class Airport {
public:
  using t_city = std::string;
  using t_dbtz = std::string;
  using t_name = std::string;
  using t_country = std::string;
  using t_iata_faa = std::string;
  using t_icao = std::string;
  using t_id = std::string;
  using t_latitude = std::string;
  using t_longitude = std::string;
  using t_timezone = std::string;
  using t_dst = std::string;
  using t_destinations = std::vector<int>;
  
  t_city city;
  t_dbtz dbtz;
  t_name name;
  t_country country;
  t_iata_faa iata_faa;
  t_icao icao;
  t_id id;
  t_latitude latitude;
  t_longitude longitude;
  t_timezone timezone;
  t_dst dst;
  t_destinations destinations;
public:
  friend std::ostream& operator<<(std::ostream& os, const Airport& a);
};

std::ostream& operator<<(std::ostream& os, const Airport& a) {
  os << a.city;
  return os;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& items) {
  for(auto& x: items) {
    os << x << std::endl;
  }
  return os;
}

int main() {
  boost::property_tree::ptree pt;
  boost::property_tree::read_json("Data/airports.json", pt);
  std::vector<Airport> airports;

  std::string city;

  // Iterate through all airports
  for(auto& item : pt) {
    Airport a;
    
    // Process each attribute 
    for(auto& prop : item.second) {
      if(prop.first == "City")
	a.city = prop.second.get_value<Airport::t_city>();
      else if(prop.first == "DBTZ")
	a.dbtz = prop.second.get_value<Airport::t_dbtz>();
      else if(prop.first == "Name")
	a.name = prop.second.get_value<Airport::t_name>();
      else if(prop.first == "Country")
	a.country = prop.second.get_value<Airport::t_country>();
      else if(prop.first == "IATA/FAA")
	a.iata_faa = prop.second.get_value<Airport::t_iata_faa>();
      else if(prop.first == "ICAO")
	a.icao = prop.second.get_value<Airport::t_icao>();
      else if(prop.first == "Airport ID")
	a.id = prop.second.get_value<Airport::t_id>();
      else if(prop.first == "Latitude")
	a.latitude = prop.second.get_value<Airport::t_latitude>();
      else if(prop.first == "Longitude")
	a.longitude = prop.second.get_value<Airport::t_longitude>();
      else if(prop.first == "Timezone")
	a.timezone = prop.second.get_value<Airport::t_timezone>();
      else if(prop.first == "DST")
	a.dst = prop.second.get_value<Airport::t_dst>();
      else if(prop.first == "destinations") {
	BOOST_FOREACH (boost::property_tree::ptree::value_type& val, prop.second) {
	  int destination = val.second.get_value<int>();
	  a.destinations.push_back(destination);
	}
      }
      else
	throw std::runtime_error("Unhandled key");
    }

    airports.push_back(a);
  }

  std::cout << airports;
}
