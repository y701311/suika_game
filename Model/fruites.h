#pragma once

#include <Siv3D.hpp>


class Fruites {
public:
	const int FruitesRankNum = 11;
	const int FruitesNextQueueSize = 3;
	std::vector<Texture> fruites_texture;
	std::vector<double> fruites_texture_scale;
	std::vector<std::vector<Point>> fruites_pos;
	std::queue<int> fruites_next_queue;

	Fruites();
	int get_next_fruites();

private:
};
