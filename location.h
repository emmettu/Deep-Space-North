#include <string>
#include <iostream>
#include <map>
#include "item.h"

class location {
  std::string locName;
  std::string entranceName;
  std::string description;
  std::string enterText;
  std::string leaveText;
  std::string path;
  item *key;
  std::string keyText; 
  std::map<std::string, location*> adjLocs;
  std::map<std::string, item*> items;
 public:
  location(std::string initName,
	   std::string initEntName,
	   std::string initDescription,
	   std::string initEnterText, 
	   std::string initLeaveText,
	   std::string initPath
	   ) {
    locName = initName;
    entranceName = initEntName;
    description = initDescription;
    enterText = initEnterText;
    leaveText = initLeaveText;
    path = initPath;
    key = NULL;
  };
  
  std::string get_name() {
    return locName;
  }
  item *get_key() {
    return key; 
  }
  std::string get_keyText() {
    return keyText;
  }
  void set_key(item *theKey) {
    key = theKey; 
  }
  void set_keyText(std::string text) {
    keyText = text;
  }
  void printKeyText() {
    std::cout << keyText << std::endl;
  }
  std::string get_description() {
    return description;
  }
  std::string get_path() {
    return path; 
  }
  
  std::string get_EntName() {
    return entranceName;
  }
  std::map<std::string, item*> get_items() {
    return items;
  }
  
  std::map<std::string, location*> get_adjLocs(){
    return adjLocs;
  }
  bool isItemless() {
    return items.empty();
  }
  
  void printLocName() {
    std::cout << locName << std::endl;
  }
  void printEnterText() {
    std::cout << enterText << std::endl;
  }
  void printLeaveText() {
    std::cout << leaveText << std::endl;
  }
  
  void printItems() {
    std::cout << "You see: " << std::endl; 
    for(std::map<std::string, item *>::iterator it = items.begin(); it != items.end();
	it++) {
      std::cout << "-" << it->second->get_preposition()  << it->first << std::endl;
    }
  }
  
  void printAdjLocs() {
    for(std::map<std::string, location *>::iterator it = adjLocs.begin(); 
	it != adjLocs.end(); it++) {
      std::cout << "You can see " << it->first << "." << std::endl;
   }
  }
  //checks if a location exists in adjLocs
  
  bool checkLocs(std::string newLocName) {
    if(adjLocs.find(newLocName) == adjLocs.end()) {
      return false;
    }
    else return true;
  }
  bool checkItems(std::string newItemName) {
    if(items.find(newItemName) == items.end()) {
      return false;
    }
    else return true;
  }
  
  void addAdjLoc(location *newLoc) {
    adjLocs[newLoc->get_EntName()] = newLoc;
  }
  
  void addItem(item *newItem) {
    items[newItem->get_name()] = newItem;
  }
  void removeItem(std::string itemToRemove) {
    items.erase(itemToRemove);
  }
};

