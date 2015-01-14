#include "location.h"

class player {
  location *curLoc;
  std::string name;
  std::map<std::string, item *> inventory;
  int health;
  int hunger;
  
 public:
  player(std::string initName) {
    name = initName;
    health = 100;
    hunger = 100;
  }
  std::map<std::string, item *> get_inventory() {
    return inventory;
  }
  
  location *get_curLoc(){
    return(curLoc);
  }
  void set_curLoc(location *loc) {
    curLoc = loc;
  }
  void disassemble(std::string i) { 
    if(in_inventory(i) && get_inventory()[i]->getComponent() != NULL) {
      std::cout << "You take apart the " << get_inventory()[i]->get_name() << "." << std::endl;
      add_item(get_inventory()[i]->getComponent());
      std::cout << "You recover " << get_inventory()[i]->getComponent()->get_preposition() << 
	get_inventory()[i]->getComponent()->get_name() << "." <<  std::endl;
      remove_item(i);
    } 
    else std::cout << "You can't take this item appart." << std::endl;
  }
  std::string get_name() {
    return name;
  }
  bool is_itemless() {
    return inventory.empty();
  }
  
  void move(location *newLoc) {
    curLoc = newLoc;
  }
  
  bool in_inventory(std::string thing) {
    if(inventory.find(thing) == inventory.end()) {
      return false;
    }
    else return true;
  }
  int get_health() {
    return health;
  }
  void set_health(int newHealth) {
    health = newHealth;
  }
  void print_items() {
    for(std::map<std::string, item *>::iterator it = inventory.begin(); it != inventory.end();
	it++) {
      std::cout << it->first << std::endl;
    }
  }
  void add_item(item *addedItem) {
    inventory[addedItem->get_name()] = addedItem;
  }
  void remove_item(std::string itemToRemove) {
    inventory.erase(itemToRemove);
  }
  
  void eat(item* itemToEat) {
    health += itemToEat->health_val();
    remove_item(itemToEat->get_name());
  }
};
