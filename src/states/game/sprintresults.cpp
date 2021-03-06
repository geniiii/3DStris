#include <3dstris/states/game/sprintresults.hpp>
#include <3dstris/states/menu/mainmenu.hpp>
#include <3dstris/states/menu/sprinttimes.hpp>

SprintResults::SprintResults(Ingame* parent, SavedGame&& saved)
	: State(),
	  parent(parent),

	  timeFormat(game.translate("results.sprint.time")),
	  timeText(sdscatprintf(sdsempty(), timeFormat, saved.time)),

	  restartButton(gui.add<Button>(Pos{-1, -1}, WH{150, 60},
									game.translate("results.restart"),
									Button::Flags::CENTER)),
	  timesButton(gui.add<Button>(Pos{-1, 15}, WH{80, 40},
								  game.translate("results.sprint.times"),
								  Button::Flags::HCENTER)),
	  menuButton(gui.add<Button>(Pos{-1, BSCREEN_HEIGHT - 45 - 10}, WH{100, 45},
								 game.translate("menu"),
								 Button::Flags::HCENTER)) {
	timeText.setScale({1.3f, 1.3f});
	timeText.align(Text::Align::SCREEN_CENTER);

	game.getGames().push(std::move(saved));
	game.getGames().save();
}

SprintResults::~SprintResults() {
	sdsfree(timeFormat);
}

void SprintResults::update(const double dt) {
	gui.update(dt);

	if (timesButton.pressed()) {
		game.pushState(make_unique<SprintTimes>());
		return;
	}

	if (restartButton.pressed()) {
		parent->reset();
		game.popState(false, true);
		return;
	}

	if (menuButton.pressed()) {
		game.setState(make_unique<MainMenu>());
		return;
	}
}

void SprintResults::draw(const bool bottom) {
	if (!bottom) {
		parent->draw(bottom);
		C2D_DrawRectSolid(0, 0, 1, SCREEN_WIDTH, SCREEN_HEIGHT, RESULTS);

		timeText.draw();
	} else {
		C2D_TargetClear(game.getBottom(), BACKGROUND);

		gui.draw();
	}
}
