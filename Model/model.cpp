#include <Siv3D.hpp>
#include "model.h"
#include "fruites.h"


GameModel::GameModel() {

}

void GameModel::update_score() {

}

void GameModel::update_playground(Fruites* fruites) {
	for (int i = 0; i < fruites->FruitesRankNum; i++) {
		for (auto& pos : fruites->fruites_pos[i]) {
			pos.y += vy;
		}
	}
}

void GameModel::integrate_fruits(Fruites* fruites) {

}
