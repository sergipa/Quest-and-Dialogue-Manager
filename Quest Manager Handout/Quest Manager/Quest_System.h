#ifndef QUEST_MANAGER
#define QUEST_MANAGER

#include <string>
#include "pugixml-1.8\src\pugixml.hpp"
// TODO 1: Create the needed Structures to save the data from the XML
class Quest_Manager {
public:
	Quest_Manager();
	~Quest_Manager();
pugi::xml_document quests_file;
pugi::xml_node quests_node;
// TODO 2: Create any variables you might need to store and manage all the quests.
// TODO 4: Create a method that updates the state of the quests. Example: If quest 1 is active and all the tasks are completed quest 1 state should be completed
};


























#endif