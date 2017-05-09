#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

constexpr double pi() { return std::atan(1) * 4; }

class Ship;

class Ship {
  static std::vector<Ship*> ships;
  static const int EARTH_RADIUS = 3956;
  double lat;
  double lon;
  std::string callSign;
  std::string name;
  double range;
  bool emergency;
  double hav(double theta) {
    return sin(theta / 2.0) * sin(theta / 2.0);
  }
  double radian(double degree) {
    return pi() * degree / 180.0;
  }
  double distance(Ship& _ship) {
    return 2 * EARTH_RADIUS * asin(sqrt(
      hav(radian(_ship.lat - lat) +
	  cos(radian(lat)) * cos(radian(_ship.lat)) * hav(radian(_ship.lon - lon))
	  )));
  }
public:
  Ship(double _lat, double _lon, std::string _callSign, std::string _name, double _range) :
    lat(_lat), lon(_lon), callSign(_callSign), name(_name), range(_range), emergency(false) {
    ships.push_back(this);
    std::cout << "Constructed and pushed into static vector of ships, now at size: " << ships.size() << "\n";
  }
  Ship(const Ship& _ship) {
    lat = _ship.lat; lon = _ship.lon; callSign = _ship.callSign; name = _ship.name;
    range = _ship.range; emergency = _ship.emergency;
  }
  Ship& operator =(const Ship& _other) {
    lat = _other.lat; lon = _other.lon; callSign = _other.callSign; name = _other.name;
    range = _other.range; emergency = _other.emergency;
    return *this;
  }
  ~Ship() {
    auto it = std::find(ships.begin(), ships.end(), this);
    ships.erase(it);
  }
  void update(double _lat, double _lon) {
    std::cout << "Ship::update(double, double)\n";
    lat = _lat; lon = _lon;
  }
  void setEmergency() { emergency = true; }
  void broadcast() {
    std::cout << "Ship::broadcast() for Ship " << callSign << " " << name << " at lat "
	      << lat << " and lon " << lon << " with range " << range << "\n";
    for (auto i : ships) {
      if (distance(*i) < range && i != this) {
	std::cout << "Found ship within range: " << i->callSign << "\n";
      }
    }
  }
};
