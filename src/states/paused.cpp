#include <3dstris/states/mainmenu.hpp>
#include <3dstris/states/paused.hpp>
#include <algorithm>

Paused::Paused(State* parent) : State(), pausedText("Paused"), parent(parent) {
	pausedText.setScale({2, 2});
	pausedText.setPos({(SCREEN_WIDTH - pausedText.getWH().x) / 2,
					   (SCREEN_HEIGHT - pausedText.getWH().y) / 2});
	unpauseButton =
		gui.addButton(ButtonFlags::CENTER, -1, 10, 200, 115, "Resume");
	menuButton = gui.addButton(ButtonFlags::HCENTER, -1,
							   BSCREEN_HEIGHT - 40 - 10, 100, 45, "Menu");
	colBackground = C2D_Color32(34, 34, 34, 255);
}

void Paused::update(double dt) {
	gui.update(dt);

	auto kDown = hidKeysDown();
	if (unpauseButton->pressed() || (kDown > KEY_A && kDown <= KEY_ZR)) {
		this->game.popState(false, true);
		return;
	}

	if (menuButton->pressed()) {
		this->game.setState(make_unique<MainMenu>());
	}
}

void Paused::draw(bool bottom) {
	if (!bottom) {
		parent->draw(bottom);
		C2D_DrawRectSolid(0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, PAUSED);

		pausedText.draw();
	} else {
		C2D_TargetClear(this->game.getBottom(), colBackground);

		gui.draw();
	}
}