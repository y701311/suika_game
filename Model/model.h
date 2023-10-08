#pragma once

#include <Siv3D.hpp>
#include "fruites.h"


class GameModel {
public:
	GameModel();
	void update_score();
	void update_playground(Fruites*);
	void integrate_fruits(Fruites*);

private:
	const int vy = 10;
};
