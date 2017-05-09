#include "Ship.hpp"
#include <string>

std::vector<Ship*> Ship::ships;

int main() {
  Ship endeavour(36.158, -5.357, "2FBA7", "Endeavour", 20.0);
  Ship seaswan(36.180, -5.390, "2CEU8", "Sea Swan", 10.0);
  seaswan.setEmergency();
  seaswan.broadcast();
  endeavour.update(36.179, -5.391);
  return 0;
}
