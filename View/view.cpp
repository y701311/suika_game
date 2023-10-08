#include <Siv3D.hpp>
#include "view.h"
#include "../Model/model.h"
#include "../Model/fruites.h"


GameView::GameView() {
	Window::Resize(1000, 780);
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });
}

void GameView::update_score() {

}

void GameView::update_playground() {
	Rect{ 250, 100, 500, 650 }.draw();

	// 物理演算の適用
	model.update_playground(&fruites);
	model.integrate_fruits(&fruites);

	// draw fruites
	for (int i = 0; i < fruites.FruitesRankNum; i++) {
		for (const auto& pos : fruites.fruites_pos[i]) {
			fruites.fruites_texture[i]
				.scaled(fruites.fruites_texture_scale[i])
				.drawAt(pos);
		}
	}
}

Point GameView::fix_input_point(const Point point) {
	// verify user input range
	// 250 <= x <= 750
	// y = 50
	Point fixed_point = point;

	fixed_point.y = 50;
	if (point.x < 250) {
		fixed_point.x = 250;
	}
	if (point.x > 750) {
		fixed_point.x = 750;
	}

	return fixed_point;
}

void GameView::draw_next_fruites_list() {
	// 次に落ちるフルーツの待機列を描画
}

void GameView::get_drop_input() {
	const Point point = Cursor::Pos();
	const Point fixed_point = fix_input_point(point);

	// 物理演算対象に追加して、フルーツを落とす
	fruites.fruites_pos[fruites.get_next_fruites()].push_back(fixed_point);

	// draw next fruites list
	draw_next_fruites_list();
}

void GameView::draw_fall_line() {
	const Point point = Cursor::Pos();
	const Point fixed_point = fix_input_point(point);

	// 落下の予測線を描画
}

void GameView::draw_next_fruites() {
	const Point point = Cursor::Pos();
	const Point fixed_point = fix_input_point(point);

	// 次に落ちるフルーツを描画
	const int next_fruites = fruites.fruites_next_queue.front();
	fruites.fruites_texture[next_fruites]
		.scaled(fruites.fruites_texture_scale[next_fruites])
		.drawAt(fixed_point);
}
