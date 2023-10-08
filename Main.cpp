#include <Siv3D.hpp>
#include "View/view.h"


void Main() {
	GameView view = GameView();

	while (System::Update()) {
		view.update_playground();

		view.draw_next_fruites();
		view.draw_fall_line();

		if (MouseL.down()) {
			view.get_drop_input();
		}
	}
}
