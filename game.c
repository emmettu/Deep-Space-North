#include "game.h"
#include <algorithm> //for transform (lower)

game::game () {
  commandMap["pick up"] = "pick up";
  commandMap["grab"] = "pick up";
  commandMap["take"] = "pick up";
  commandMap["snag"] = "pick up";
  commandMap["nab"] = "pick up";
  commandMap["snake"] = "pick up";
  commandMap["put on"] = "pick up"; 
  commandMap["don"] = "pick up";
  commandMap["eat"] = "eat";
  commandMap["chow"] = "eat";
  commandMap["consume"] = "eat"; 
  commandMap["devour"] = "eat";
  commandMap["chew"] = "eat";
  commandMap["munch"] = "eat";
  commandMap["munch on"] = "eat";
  commandMap["gobble"] = "eat";
  commandMap["gobble up"] = "eat";
  commandMap["ingest"] = "eat";
  commandMap["gorge on"] = "eat";
  commandMap["inhale"] = "eat";
  commandMap["gormandize"] = "eat";
  commandMap["go to"] = "move";
  commandMap["move to"] = "move";
  commandMap["march to"] = "move";
  commandMap["examine"] = "examine";
  commandMap["look at"] = "examine";
  commandMap["inventory"] = "inventory";
  commandMap["examine inventory"] = "inventory";
  commandMap["check inventory"] = "inventory";
  commandMap["look through pockets"]  = "inventory";
  commandMap["look around"] = "look around";
  commandMap["explore"] = "look around";
  commandMap["investigate"] = "look around";
  commandMap["analyze"] = "look around";
  commandMap["rip apart"] = "disassemble";
  commandMap["dismantle"] = "disassemble";
  commandMap["smash"] = "disassemble";
  commandMap["break open"] = "disassemble";
  commandMap["disassemble"] = "disassemble";
  commandMap["rip open"] = "disassemble";
  commandMap["dance"] = "dance";
  commandMap["dance around"] = "dance";
  commandMap["jump up jump up and get down"] = "dance";
  commandMap["jump around"] = "dance";
  commandMap["piss"] = "piss";
  commandMap["take a piss"] = "piss";
  commandMap["wet yourself"] = "piss";
  commandMap["take a number 1"] = "piss";
  commandMap["defecate"] = "defecate";
  commandMap["take a dump"] = "defecate";
  commandMap["tale a number 2"] = "defecate";
  commandMap["go home"] = "go home";
  commandMap["leave"] = "go home";
  commandMap["get out of here"] = "go home";
  commandMap["evacuate"] = "go home";
  commandMap["take a nap"] = "take a nap";
  commandMap["sleep"] = "take a nap";
  commandMap["lie down"] = "take a nap";
  commandMap["help"] = "help";
  commandMap["q"] = "quit";
  commandMap["quit"] = "quit";
  commandMap["finish"] = "quit";
  commandMap["i think i'm done for today"] = "quit";
  commandMap["that's enough for me"] = "quit"; 
} //NOTE:: the extra spaces are so an extra space character gets consumed between the command and the object

bool game::is_over() {
  if(!Player->get_health()) {
    return true;
  }
  if(Player->get_curLoc()->get_name() == "Earth") {
    std::string text;
    std::cout << "Congratulations! YOU WIN!\n";
    std::cout << "Thanks for playing and MERRY CHRISTMAS! Love you Mom!\n"; 
    std::cout << "Press any key to quit: ";
    std::cin >> text;
    return true; 
  }
  return false;
}
player *game::get_player() {
  return Player;
}
void game::set_player(player *thePlayer) {
  Player = thePlayer;
}
std::string game::parse_command() {
  std::string command;
  char ch;
  while(std::cin.get(ch)) {
    command += tolower(ch); 
    if(commandMap.find(command) != commandMap.end()) {
      command = commandMap[command];
      std::cin.get(ch);
      break;
    }
    else if(ch == '\n') { break; }
  }
  //std::cin.get(ch);
  return command; 
}

int game::get_command() {
  std::string mappedCommand = parse_command();
  
  if(mappedCommand == "move") {  
    std::string loc; 
    if(std::getline(std::cin, loc)) {
      if(!Player->get_curLoc()->checkLocs(loc)) {
	std::cout << "There is no " << loc << "." << std::endl;
	return 1;
      }
      else { 
	if(!Player->in_inventory("space suit")) { std::cout << "You gasp for air and realize you have no space suit." << std::endl;  
	  std::cout << "You have died due to exposure to the vacuum of space." << std::endl; 
	  return 0;
	}
	if(Player->get_curLoc()->get_adjLocs()[loc]->get_key() != NULL) {
	  if(!Player->in_inventory((Player->get_curLoc()->get_adjLocs()[loc]->get_key()->get_name()))) {
	    Player->get_curLoc()->get_adjLocs()[loc]->printKeyText();
	    return 1;
	  }
	  else Player->get_curLoc()->get_adjLocs()[loc]->get_key()->printKeyText();
	}
	Player->get_curLoc()->printLeaveText();
	Player->move(Player->get_curLoc()->get_adjLocs()[loc]);
	Player->get_curLoc()->printEnterText();
	if(Player->get_curLoc()->get_name() == "deep space") {
	  std::cout << "The ship begins to slow and emits a strange whirring noise.\n";
	  std::cout << "Your ship loses power and you are trapped in the\nendless reaches of space.\n"; 
	  return 0;
	}
	return 1;
      }
    }
    else { 
      std::cout << "you look around and see "; 
      Player->get_curLoc()->printAdjLocs();
      return 1;
    }
  }
  
  else if(mappedCommand == "eat") {
    std::string itemToEat;
    if(std::getline(std::cin, itemToEat)) {
      //implement get_inventory() and eat commands
      if(Player->in_inventory(itemToEat)) {
	if(Player->get_inventory()[itemToEat]->is_edible()) {
	  Player->eat(Player->get_inventory()[itemToEat]);
	  std::cout << Player->get_inventory()[itemToEat]->edible_text() << std::endl;
	  return 1;
	}
	else { std::cout << "You take off your helmet to\ntake a bite of " << itemToEat << " and promptly suffocate." << std::endl; 
	  Player->set_health(0); 
	  std::cout << "You have died by trying to eat in space." << std::endl;
	} 
      }
      else {
	std::cout << "You don't have " << itemToEat << " but you wish you did" << "." << std::endl;
	return 1;
      }
    }
    else { 
      std::cout << "You think about how hungry you are..." << std::endl;
      return 1;
    }
  }
  
  else if(mappedCommand == "pick up") {
    std::string itemToPickUp;
    std::getline(std::cin, itemToPickUp);
    if(itemToPickUp != "") {
      if(Player->get_curLoc()->checkItems(itemToPickUp)) {
	if(Player->get_curLoc()->get_items()[itemToPickUp]->isImmovable()) {
	  std::cout << "You can't pick that up." << std::endl;
	  return 1; 
	}
	Player->add_item(Player->get_curLoc()->get_items()[itemToPickUp]);
	Player->get_curLoc()->removeItem(itemToPickUp);
	Player->get_inventory()[itemToPickUp]->printPickUpText(); 
	return 1;
      }
      else {
	std::cout << "There is no " << itemToPickUp << "." << std::endl; 
	return 1;
      }
    }
    else {
      std::cout << "You look around vainly for things to stuff in your pack." << std::endl;
      return 1;
    }
  }
  
  else if(mappedCommand == "look around") {
    std::cout << Player->get_curLoc()->get_description() << std::endl;
    Player->get_curLoc()->printAdjLocs();
    if(!Player->get_curLoc()->isItemless()) {
      Player->get_curLoc()->printItems();
    }
    else std::cout << "You don't see anything useful lying around." << std::endl;
    return 1;
  }
  
  else if(mappedCommand == "inventory") {
    if(!Player->is_itemless()) Player->print_items();
    else std::cout << "You're not carrying anything." << std::endl;
    return 1;
  }
  
  else if(mappedCommand == "examine") {
    std::string itemToExamine; 
    std::getline(std::cin, itemToExamine);
    if(Player->in_inventory(itemToExamine)) {
      Player->get_inventory()[itemToExamine]->print_description();
      return 1;
    }
    else if(Player->get_curLoc()->checkItems(itemToExamine)) {
      Player->get_curLoc()->get_items()[itemToExamine]->print_description();
      return 1;
    }
    else {std::cout << "There is no " << itemToExamine << "." << std::endl; return 1;}
  }
  else if(mappedCommand == "disassemble") {
    std::string itemToDisassemble;
    std::getline(std::cin, itemToDisassemble);
    if(Player->in_inventory(itemToDisassemble)) {
      Player->disassemble(itemToDisassemble);
      return 1; 
    }
    else { std::cout << "You're not carrying " << itemToDisassemble << std::endl; return 1; }
  }
  else if(mappedCommand == "dance") {
    std::cout << "You dance around awkwardly.\n";
    return 1;
  }
  else if(mappedCommand == "piss") {
    std::cout << "You wet yourself. Your space suit sticks to your leg.\nYou are uncomfortable.\n";
    return 1;
  }
  else if(mappedCommand == "defecate") {
    std::cout << "You're about to relieve yourself but then\nyou come to your senses.\n";
    return 1;
  }
  else if(mappedCommand == "go home") {
    std::cout << "You sob to yourself and think about how\nmuch you want to go home.\n";
    return 1;
  }
  else if(mappedCommand == "take a nap") {
    std::cout << "You lie down and take a nap.\n";
    return 1;
  }
  
  else if(mappedCommand == "help") {
    std::string answer; 
    std::cout << "Are you sure you want help (it will spoil the challenge)?\nAnswer (y/n)"; 
    std::cin >> answer;
    
    if(answer == "y") {
      std::cout << "Commands:" << std::endl;
      std::cout << "eat [object]\n";
      std::cout << "look around\n";
      std::cout << "examine [object]\n";
      std::cout << "inventory\n";
      std::cout << "disassemble [object]\n";
      std::cout << "go to [location]\n";
      std::cout << "pick up [object]\n";
      std::cout << "quit\n"; 
      return 1;
    }
    return 1;
  }
  else if(mappedCommand == "quit") {
    std::cout << "Thanks for playing! Merry Christmas!" << std::endl;
  }
  else {
    std::cout << "Unknown command " << "\"" << mappedCommand.substr(0, mappedCommand.size() - 1) << "\""  << std::endl;
    //std::string garbage;
    //std::getline(std::cin, garbage);
    return 1;
  }
  return 0;
}

