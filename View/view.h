#pragma once

#include <Siv3D.hpp>
#include "../Model/model.h"
#include "../Model/fruites.h"


class GameView {
public:
	GameView();
	void update_score();
	void update_playground();
	void get_drop_input();
	void draw_fall_line();
	void draw_next_fruites();
	void draw_next_fruites_list();

private:
	GameModel model;
	Fruites fruites;

	Point fix_input_point(Point);
};
