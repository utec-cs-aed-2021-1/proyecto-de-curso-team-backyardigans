#include <iostream>
#include <fstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include "airport.hpp"
#include "utilities.hpp"

int main() {
  boost::property_tree::ptree pt;
  boost::property_tree::read_json("Data/airports.json", pt);
  std::vector<Airport> airports;

  std::string city;

  // Iterate through all airports
  for(auto& item : pt) {
    Airport a;
    bool well_formatted_airport = true;

    // Process each attribute in the dictionary
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

      else if(prop.first == "Latitude") {
	std::string value = prop.second.get_value<std::string>();

	// We need to check that the airport doesn't have the
	// following values as values, since those strings can't be
	// converted to a numerical value. Doing that produces thrown
	// exception.

	if(value == "EGCN"
	   || value == "GVNP"
	   || value == "GVSF") {
	  well_formatted_airport = false;
	  continue;
	}

	a.latitude = std::stod(value);
      }

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

    if(well_formatted_airport)
      airports.push_back(a);
  }

  std::cout << airports;
}
