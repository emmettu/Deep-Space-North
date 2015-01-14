#include "init.h"
#include <new>

void init(game *game) {
  //make the starting location
  location *startingLoc = new location("the SS Antsa",
				       "the SS Antsa", 
				       "You're in the SS Antsa a small, one man, deep space exploration vehicle.\nIt feels like home.",
				       "You slink back into your ship. This place creeps you out.", 
				       "You take a deep breath, and step out of your ship.",
				       "./pics/startingloc.bmp"
				       );

  location *loadingBay =  new location("the loading bay",
				       "the loading bay", 
				       "You're in a massive, decrepit loading bay. It stretches 100's\nof meters into the air and is riddled with pods\nfor loading cargo.",
				       "You enter the loading bay.", 
				       "You leave the loading bay.", 
				       "./pics/loadingbay.bmp"
				       );
  location *ventilation_shaft = new location ("the ventilation shaft", 
					      "the small vent", 
					      "You're in a cramped ventilation shaft.\nA metallic odour hangs in the air.", "you crawl into the ventilation shaft.", "you melt your way out with your plasma cutter and crawl out of the ventilation shaft.\nThe metal, still hot, fuses together behind you.", "./pics/ventilationshaft.bmp");
  ventilation_shaft->set_keyText("It's welded shut.");
  location *alien_ship = new location ("the alien ship", 
				       "the alien ship", 
				       "You're in an alien vessel of sorts, it's similar in size to yours.\nThe buttons and controls are incomprehensible to you.", 
				       "You walk up to the alien ship and smack it.\nA small hatch opens and you walk inside.", 
				       "You decide it's time to investigate other things.", "./pics/alienship.bmp");
  location *control_panel = new location("the control panel", 
					  "the control panel",
					  "You see a massive swathe of complicated looking controls.\nThere seem to be coordinates on the screen...",
					  "You approach the conrol panel.", "You walk away from the control panel.",
					  "./pics/controlpanel.bmp");
  location *deep_space = new location("deep space", "deep space coordinates",
				      "You sit in the dimly lit ship as it hurtles through the blackness of space.",
				      "Without warning the ship begins to hover off the ground.\nBefore you can even register what is going on you hear a loud bang\nand it hurtles off into space.","With a bit of luck and some guesswork you manage\nto make it back to the docking bay.","./pics/deepspace.bmp");
  
  location *earth = new location("Earth", "earth coordinates", "After what seems like hours your ship comes to a halt on\na bizarre icy lanscape. Your feet touch the frozen ground. It's so cold your suit barely manages to keep you warm.\nYou look out and see a large pole jutting out of the ground. A rellic of some forgotten world perhaps.", "...Without warning the ship begins to hover off the ground.\nBefore you can even register what is going on you hear a loud bang\nand it hurtles off into space. After what seems like hours your ship comes\nto a halt on a bizarre icy lanscape. Your feet touch the frozen\nground. It's so cold your suit barely manages to keep you warm.\nYou look out and see a large pole jutting out of the ice. A rellic\nof some forgotten world perhaps.", "With a bit of luck and some guesswork you manage\nto make it back to the docking bay.","./pics/earth.bmp");
  earth->set_keyText("A message flashes on the screen: INSUFFICIENT DATA.");
  location *manufacturing_room = new location("the manufacturing room", 
					      "the massive metal door", 
					      "It's truly astounding. You see conveyor belts all\nleading away from a massive metal pillar.\nFlickering on the screen is a strange symbol alien symbol.",
					      "The massive doors swing open as you approach revealing\nwhat looks like manufacturing room.",
					      "You walk through the massive metal door leaving the strange room behind you.",
					      "./pics/manufacturingroom.bmp");
  location *hallway = new location("the hallway", "the hallway", "You're in a long white hallway. It's in slightly better condition\nthan the rest of this godforsaken place.", "You walk into a long, empty hallway.", "You leave the hallway.","./pics/hallway.bmp");
  location *transport_room = new location("the transport room","the hallway security door","You're in another gargantuan complex. It's occupied\nentirely by a towering teleportation beam.","You walk into what you know to be large transport room.", "You leave the transport room.", "./pics/transportroom.bmp");
  transport_room->set_keyText("A garbled sounding voice blares from the door and it doesn't budge.");
  /////************ITEMS*****************//////
  
  //item *test = new item("test item", "the test item", "you pick up test item", "the ", false, false, NULL);
  item *access_card = new item("access card", "a small card, probably for accessing restricted areas.", "you pocket the access card.", "an ", false, false, NULL);
  access_card->setKeyText("You swipe the access card and the door slides open.");
  //item *testp2 = new item("testp2", "another piece of test", "pick up testp2", "the ", false, false, NULL);
  item *teddy_bear = new item("teddy bear", "It's a small alien object. It looks just like the symbol on the\nmachine. Perhaps this is what they were making in here you think.\nYou toss it around in your hands. It's light and squishy, like it's filled\nwith some kind of soft material. It resembles an alien creature.\nSome of the stitching looks odd...", 
			      "You pick up the strange alien item.", "a ", false, false, access_card);
  item *plasma_cutter = new item("plasma cutter", "A small portable tool for slicing metal.", "You pick up your trusty plasma cutter and slide\nit into your utility belt.", "a ", false, false, NULL);
  item *space_suit = new item("space suit", "Your model 6 space exploration suit. Rated for oxygen levels\nof zero and minor impacts.","You put on your space suit. It might get rough out there. Or oxygenless...", "your ", false, false, NULL);
  item *ship_databoard = new item("ship databoard", "A large metal circuitboard it looks like it stores\nspace travel information and coordinates.","You carefully place the databoard in your pack.","a ", false, false, NULL);
  ship_databoard->setKeyText("You slip the databoard into the control pannel.");
  item *transport_terminal = new item("transport terminal", "A large metal terminal for controlling the transport of material.\nEtched on the side it reads: TEDDY BEARS TO EARTH. What's that supposed to mean?.", "It's heavy but you manage to pick it up and put it in your pack.", "a ", false, false, ship_databoard);
  item *teleportation_cookie = new item("teleportation cookie", "A tiny alien food item, it glows with some kind of\nodd energy...",
			 "You pocket the extraterestrial food stuffs.", "a ", false, false, NULL);
  
  ///////////**********ITEM PLACEMENT*****************//////////
  startingLoc->addAdjLoc(loadingBay); loadingBay->addAdjLoc(startingLoc);
  loadingBay->addAdjLoc(ventilation_shaft); ventilation_shaft->addAdjLoc(loadingBay);
  loadingBay->addAdjLoc(alien_ship); alien_ship->addAdjLoc(loadingBay);
  loadingBay->addAdjLoc(manufacturing_room); manufacturing_room->addAdjLoc(loadingBay);
  alien_ship->addAdjLoc(control_panel); control_panel->addAdjLoc(alien_ship);
  control_panel->addAdjLoc(deep_space); deep_space->addAdjLoc(control_panel);
  control_panel->addAdjLoc(earth); earth->addAdjLoc(control_panel);
  ventilation_shaft->addAdjLoc(hallway); hallway->addAdjLoc(ventilation_shaft);
  hallway->addAdjLoc(transport_room); transport_room->addAdjLoc(hallway);
  startingLoc->addItem(space_suit);
  startingLoc->addItem(plasma_cutter);
  //  startingLoc->addItem(test);
  hallway->addItem(teleportation_cookie);
  transport_room->addItem(transport_terminal);
  manufacturing_room->addItem(teddy_bear);
  //startingLoc->addItem(test_key);
  ventilation_shaft->set_key(plasma_cutter);
  transport_room->set_key(access_card);
  earth->set_key(ship_databoard);
  
  player *Player =  new player("The Player");
  
  plasma_cutter->setKeyText("The plasma cutter cuts through the corroded metal like butter.");
  Player->set_curLoc(startingLoc);
  game->set_player(Player);
}

void print_start_message() {
  std::string name;
  std::cout << "You're name please: "; std::getline(std::cin, name);  
  std::string mp1, mp2, mp3, mp4, mp5;
  mp1 = "......................";
  mp2 = "...DEEP SPACE NORTH...";
  mp3 = "......................";
  mp4 = "An original game by: Emmett Underhill\n";
  mp5 = "You are Commander " + name +"."+\
"\nYour small one man craft has intercepted a strange, binary signal from" +\
"\ndeep space. Upon further investigation it seems you've discovered a large" +\
"\nabandoned space station. The eerie floating craft looks ancient and unlike" +\
"\nanything you've seen before. Yet without hesitation you suit up and decide to" +\
"\ninvestigate. You're ship docks with the alien construction." +\
"\nGood luck.\n";
  std::cout << mp1 << std::endl  << mp2 << std::endl << mp3 << std::endl << mp4 << std::endl << mp5 << std::endl;
}
