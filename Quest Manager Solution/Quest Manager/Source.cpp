#include "Quest_System.h"
#include <iostream>






void main() {
	Quest_Manager test;
	//Print all the quests and its state
	test.update_progress();
	for (int i = 0; i < test.vquest.size(); i++) {
		std::cout << "\nQuest id: " << test.vquest[i].id;
		std::cout << "\nQuest name: " << test.vquest[i].name.c_str();
		std::cout << "\nQuest description: " << test.vquest[i].description.c_str();
		std::cout << "\nQuest state(0 unavailable, 1 available, 2 active, 3 complete): " << test.vquest[i].state << "\n\n";
	}
	
	scanf_s("%d");
}