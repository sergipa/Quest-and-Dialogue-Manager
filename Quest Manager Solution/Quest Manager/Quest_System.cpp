#include "Quest_System.h"

Quest_Manager::Quest_Manager()
{
	pugi::xml_parse_result result = quests_file.load_file("Quests.xml", pugi::parse_default | pugi::parse_declaration);
	quests_node = quests_file.child("quests");
	for (pugi::xml_node loop_tool = quests_node.child("quest"); loop_tool; loop_tool = loop_tool.next_sibling("quest")) {
		Quest* quest = new Quest;

		quest->id = loop_tool.attribute("id").as_int();

		quest->name = loop_tool.attribute("name").as_string();

		quest->description = loop_tool.attribute("description").as_string();

		switch (loop_tool.attribute("state").as_int())
		{
		case 0: {
			quest->state = (unavailable);
			break; }
		case 1: {
			quest->state = (available);
			break; }
		case 2: {
			quest->state = (active);
			break; }
		case 3: {
			quest->state = (completed);
			break; }
		default:
			break;
		}

		for (pugi::xml_node tool = loop_tool.child("task"); tool; tool = tool.next_sibling("task"))
		{
			Objectives obj;
			obj.current_progress = tool.attribute("current").as_int();
			obj.requirement = tool.attribute("complete").as_int();
			quest->tasks.push_back(obj);
		}

		int preid = loop_tool.attribute("prerequisite").as_int();
		if (preid != 0) {
			for (int i = 0; i < vquest.size(); i++) {
				if (vquest[i].id == preid) {
					quest->pre_requirement = &vquest[i];
					break;
				}
			}
		}
		else quest->pre_requirement = nullptr;
		vquest.push_back(*quest);
	}
}

Quest_Manager::~Quest_Manager()
{
}

void Quest_Manager::change_state(int id,Quest_State new_state)
{
	for (int i = 0; i < vquest.size(); i++) {
		if (vquest[i].id == id) {
			vquest[i].state = new_state;
			break;
		}
	}
}

void Quest_Manager::update_progress()
{
	for (int i = 0; i < vquest.size(); i++) {
		if (vquest[i].state == unavailable) {
			if (vquest[i].pre_requirement->state == completed) vquest[i].state = available;
		}
		if (vquest[i].state == active) {
			int tasks_completed = 0;
			for (int j = 0; j < vquest[i].tasks.size(); j++) {
				if (vquest[i].tasks[j].current_progress == vquest[i].tasks[j].requirement) tasks_completed++;
			}
			if (tasks_completed == vquest[i].tasks.size()) vquest[i].state = completed;
		}
	}
}
