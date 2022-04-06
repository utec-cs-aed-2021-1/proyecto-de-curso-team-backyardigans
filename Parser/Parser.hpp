#pragma once

#include <string>
#include <vector>
#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include "Airport.hpp"
#include "DirectedGraph.h"
#include "UndirectedGraph.h"

/// @brief Parser for JSON files containing airports information
///
/// @note The data can be queried from this class as an undirected
/// graph, by using the method uGraphMake, and as a directed graph, by
/// using the method dGraphMake.

class Parser {
private:
  std::string json_file_name;
  std::map<Airport::t_id, Airport> data;
public:

  /// @brief Class constructor
  ///
  /// @param[in] json_file_name Name of the file from which the data is to be
  /// loaded

  Parser(const std::string& p_json_file_name): json_file_name (p_json_file_name) {
    // TODO: Check that the file exists
    // TODO: Check that the file is readable
  }

  /// @brief Free the needed memory for loading the JSON file.

  void clear() {
    data.clear();
  }

  /// @brief Load data from json_file_name and store the data in data.

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
	    Airport::t_destination destination = val.second.get_value<Airport::t_destination>();
	    a.destinations.push_back(destination);
	  }
	}
	else
	  throw std::runtime_error("Unhandled key");
      }

      if(well_formatted_airport)
	data[a.id] = a;
    }
  }

  /// @brief Get the manhattan distance between two airports
  ///
  /// @param[in] longitude1 The longitude of the first airport
  /// @param[in] latitude1 The latitude of the first airport
  /// @param[in] longitude2 The longitude of the second airport
  /// @param[in] latitude2 The latitude of the second airport
  ///
  /// @return The manhattan distance between two airports.

  double manhattanDistance(const double& latitude1,
			 const double& longitude1,
			 const double& latitude2,
			 const double& longitude2) {
    return abs(latitude1 - latitude2) +
      abs(longitude1 - longitude2);
  }

  /// @brief Load the previously loaded data into an undirected graph
  ///
  /// @param[in] tempGraph The undirected graph in which the data will
  /// be loaded. This graph need to be empty. Otherwise, an exception
  /// is thrown.

  void uGraphMake(UndirectedGraph<Airport, double> &tempGraph) {
    // TODO: Throw an exception when the graph is not empty.

    // Error if the data hasn't been loaded

    if(data.empty()) {
      throw std::runtime_error("The data hasn't been loaded. Use the readJSON() method before.");
      return;
    }

    // Error if the graph is not empty

    if(! tempGraph.empty()) {
      throw std::runtime_error("The provided graph is not empty.");
      return;
    }

    // Create the vertices in the graph

    for(auto airport: data)
      tempGraph.insertVertex(airport.second.id, airport.second);

    // Create the edges

    for(auto airport: data) {
      for(auto destination: airport.second.destinations) {
	Airport::t_id airport1_id = airport.first;
	Airport::t_id airport2_id = destination;
	double manhattan = manhattanDistance(airport.second.latitude,
					     airport.second.longitude,
					     data[destination].latitude,
					     data[destination].longitude);
	tempGraph.createEdge(airport1_id, airport2_id, manhattan);
      }
    }
  }


  /// @brief Load the previously loaded data into a directed graph
  ///
  /// @param[in] tempGraph The directed graph in which the data will be
  /// loaded. This graph need to be empty. Otherwise, an exception is thrown.

  void dGraphMake(DirectedGraph<Airport, double> &tempGraph) {
    // TODO: Throw an exception when the graph is not empty.

    // Error if the data hasn't been loaded

    if(data.empty()) {
      throw std::runtime_error("The data hasn't been loaded. Use the readJSON() method before.");
      return;
    }

    // Error if the graph is not empty

    if(! tempGraph.empty()) {
      throw std::runtime_error("The provided graph is not empty.");
      return;
    }

    // Create the vertices in the graph

    for(auto airport: data)
      tempGraph.insertVertex(airport.second.id, airport.second);

    // Create the edges

    for(auto airport: data) {
      for(auto destination: airport.second.destinations) {
	Airport::t_id airport1_id = airport.first;
	Airport::t_id airport2_id = destination;
	double manhattan = manhattanDistance(airport.second.latitude,
					     airport.second.longitude,
					     data[destination].latitude,
					     data[destination].longitude);
	tempGraph.createEdge(airport1_id, airport2_id, manhattan);
      }
    }
  }

  /// @brief Display all the laoded data
  ///
  /// @note This function has been created to help users determine
  /// whether the data was correctly loaded or not.

  void showLoadedData() {
    for(auto x: data) {
      // Print each airport
      cout << x.second << endl;
    }
  }

};
