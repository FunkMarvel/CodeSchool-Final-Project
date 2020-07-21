#include <iostream>
#include "ngon_random.h"

struct player {
  int health;

  int damage_max;
  int damage_min;

  int crit_chance;

  player(int aHealth, int aDamage_min, int aDamage_max, int aCritChance);
  int damage();
  bool is_critical_hit();

  ~player();
};

player::player(int aHealth, int aDamage_min, int aDamage_max, int aCritChance) {
  health = aHealth;
  damage_min = aDamage_min;
  damage_max = aDamage_max;
  crit_chance = aCritChance;
}

int player::damage() {
  int crit_count;
  int damage_result = random_number(damage_min, damage_max);
  if (is_critical_hit()) {
    crit_count++;
    return damage_result*2;
  }
  return damage_result;
}

bool player::is_critical_hit() {
  int crit_result = random_number(0, 100);
  return crit_result < crit_chance;
}

player::~player() {

}

int main(int argc, char const *argv[]) {

  player gabe(100, 5, 10, 30);
  player olafur(100, 5, 10, 5);

  while (gabe.health > 0 && olafur.health > 0) {
    gabe.health -= olafur.damage();
    olafur.health -= gabe.damage();
  }

  std::cout << "Gabe: " << gabe.health << ", Olafur: " << olafur.health << std::endl;
  return 0;
}
