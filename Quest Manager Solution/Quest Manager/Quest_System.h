#ifndef QUEST_MANAGER
#define QUEST_MANAGER

#include <string>
#include <vector>
#include "pugixml-1.8\src\pugixml.hpp"
struct Objectives {
	int current_progress;
	int requirement;
};
enum Quest_State {
	unavailable,
	available,
	active,
	completed
};
struct Quest {
	int id;
	std::string name;
	std::string description;
	Quest_State state;
	std::vector<Objectives> tasks;
	Quest* pre_requirement;
};
class Quest_Manager {
public:
	Quest_Manager();
	~Quest_Manager();
pugi::xml_document quests_file;
pugi::xml_node quests_node;

public:
	void change_state(int id,Quest_State new_state);
	void update_progress();
	std::vector<Quest> vquest;


};


























#endif