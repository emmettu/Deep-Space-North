#include "player.h"

class game {
  //location *startingLoc;
  player *Player;
  std::map<std::string, std::string> commandMap;
 
 public:
  game ();
  bool is_over();
  std::string parse_command();
  int get_command();
  player *get_player();
  void set_player(player *);
};
