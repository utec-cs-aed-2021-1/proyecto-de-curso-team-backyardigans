#pragma once

#include <vector>
#include "Utilities.hpp"

class Airport {
public:
  using t_city = std::string;
  using t_dbtz = std::string;
  using t_name = std::string;
  using t_country = std::string;
  using t_iata_faa = std::string;
  using t_icao = std::string;
  using t_id = std::string;
  using t_latitude = double;
  using t_longitude = double;
  using t_timezone = std::string;
  using t_dst = std::string;
  using t_destination = std::string;
  using t_destinations = std::vector<t_destination>;

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
  os << "(Airport "
     << "(ID: " << a.id << ")"
     << " "
     << "(Longitude: " << a.longitude << ")"
     << " "
     << "(Latitude: " << a.latitude << ")"
     << ")";
  return os;
};
