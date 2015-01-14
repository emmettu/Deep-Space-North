#include <string>
#include <iostream>

class item {
  std::string name;
  std::string description;
  bool isEdible;
  int healthVal;
  bool immovable;
  std::string pickUpText; 
  std::string edibleText;
  std::string preposition;
  std::string keyText;
  item *component;
  item *combines;
 public:
  item(std::string initName, 
       std::string initDescription,
       std::string initPickUpText,
       std::string initPrep,
       bool initEdible,
       bool initImmovable,
       item *initComponent) {
    name = initName;
    description = initDescription;
    pickUpText = initPickUpText;
    preposition = initPrep;
    isEdible = initEdible;
    immovable = initImmovable;
    component = initComponent;
  };
  
  std::string get_name() {
    return name;
  }
  item *getComponent() {
    return component;
  }
  void setComponent(item * theComponent) {
    component = theComponent;
  }
  bool isImmovable() {
    return immovable;
  }
  void printPickUpText() {
    std::cout << pickUpText << std::endl;
  }
  void printKeyText() {
    std::cout << keyText << std::endl;
  }
  void setKeyText(std::string text) {
    keyText = text;
  }
  void printName() {
    std::cout << preposition  << name << std::endl;
  }
  void print_description() {
    std::cout << description << std::endl;
  }
  std::string get_preposition() {
    return preposition;
  }
  bool is_edible() {
    return isEdible;
  }
  int health_val() {
    return healthVal;
  }
  std::string edible_text() {
    return edibleText;
  } 
};

