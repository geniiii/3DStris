#pragma once

#include <3dstris/gui.hpp>
#include <3dstris/state.hpp>

class MainMenu final : public State {
   public:
	MainMenu();

	void update(double dt) override;
	void draw(bool bottom) override;

   private:
	Text versionText;

	C2D_Image icon;

	GUI gui;

	Button& playButton;
	Button& settingsButton;
	Button& exitButton;

	Button& keybindsButton;
	Button& gamesButton;
	Button& languagesButton;
};
