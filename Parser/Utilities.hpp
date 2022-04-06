#pragma once

#include <ostream> // std::ostream

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& items) {
  for(auto& x: items) {
    os << x << std::endl;
  }
  return os;
}
