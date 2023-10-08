#include <Siv3D.hpp>
#include <random>
#include "fruites.h"


Fruites::Fruites() {
	fruites_texture = *(new std::vector<Texture>(FruitesRankNum));
	fruites_texture_scale = *(new std::vector<double>(FruitesRankNum));
	fruites_pos = *(new std::vector<std::vector<Point>>(FruitesRankNum));

	for (int i = 0; i < FruitesNextQueueSize; i++) {
		fruites_next_queue.push(0);
	}

	// 画像ファイルからテクスチャを作成
	const Texture rank0{ U"../images/赤丸.png" };
	if (not rank0)	Print << U"rank0 image is empty.";
	fruites_texture[0] = rank0;
	fruites_texture_scale[0] = 0.5;

	const Texture rank1{ U"../images/オレンジ.png" };
	if (not rank1)	Print << U"rank1 image is empty.";
	fruites_texture[1] = rank1;
	fruites_texture_scale[1] = 0.5;

	const Texture rank2{ U"../images/星.png" };
	if (not rank2)	Print << U"rank2 image is empty.";
	fruites_texture[2] = rank2;
	fruites_texture_scale[2] = 0.5;

	// ... rank0 から rank(FruitesRankNum - 1) まで画像を読み込み
}

int Fruites::get_next_fruites() {
	fruites_next_queue.push(rand() % 3);

	const int next = fruites_next_queue.front();
	fruites_next_queue.pop();
	return next;
}
