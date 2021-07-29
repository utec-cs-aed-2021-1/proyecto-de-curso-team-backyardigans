#pragma once

#include <string>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include "Airport.hpp"
#include "DirectedGraph.h"
#include "UndirectedGraph.h"

/**
 * @brief Parser for JSON files containing airports information
 *
 * @note The data can be queried from this class as an undirected
 * graph, by using the method uGraphMake, and as a directed graph, by
 * using the method dGraphMake.
 */

class Parser {
private:
  std::string json_file_name;
  std::vector<Airport> data;
public:

  /**
   * @brief Class constructor
   *
   * @param[in] json_file_name Name of the file from which the data is to be
   * loaded
   */

  Parser(const std::string& p_json_file_name): json_file_name (p_json_file_name) {
    // TODO: Check that the file exists
    // TODO: Check that the file is readable
  }

  /**
   * @brief Free the needed memory for loading the JSON file.
   */

  void aclear() {
    data.clear();
  }

  /**
   * @brief Load data from json_file_name and store the data in data.
   */

  void readJSON() {
    boost::property_tree::ptree pt;
    boost::property_tree::read_json(json_file_name, pt);

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
	    break;
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
	data.push_back(a);
    }
  }

  /**
   * @brief Load the previously loaded data into an undirected graph
   *
   * @param[in] tempGraph The undirected graph in which the data will
   * be loaded. This graph need to be empty. Otherwise, an exception
   * is thrown.
   */

  void uGraphMake(UnDirectedGraph<string, double> &tempGraph) {
    // TODO: Throw an exception when the graph is not empty.
  }

  /**
   * @brief Load the previously loaded data into a directed graph
   *
   * @param[in] tempGraph The directed graph in which the data will be
   * loaded. This graph need to be empty. Otherwise, an exception is thrown.
   */

  void dGraphMake(DirectedGraph<string, double> &tempGraph) {
    // TODO: Throw an exception when the graph is not empty.
  }

  /**
   * @brief Display all the laoded data
   *
   * @note This function has been created to help users determine
   * whether the data was correctly loaded or not.
   */

  void showLoadedData() {
    for(auto x: data) {
      // Print each airport
      cout << x << endl;
    }
  }

};
