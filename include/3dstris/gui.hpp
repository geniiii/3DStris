#pragma once

#include <3dstris/gui/button.hpp>
#include <3dstris/gui/slider.hpp>
#include <3dstris/gui/widget.hpp>
#include <3dstris/util.hpp>
#include <vector>

enum ButtonFlags { NONE, HCENTER, VCENTER, CENTER };

class GUI {
   public:
	GUI(int width = BSCREEN_WIDTH, int height = BSCREEN_HEIGHT,
		Color primaryCol = BUTTON, Color textCol = WHITE,
		Color pressedCol = BUTTON_HELD);

	template <typename T>
	std::shared_ptr<Button> addButton(float x, float y, float w, float h,
									  const T text) {
		auto button = std::make_shared<Button>(*this, x, y, w, h, text);
		widgets.push_back(button);
		return button;
	}

	template <typename T>
	std::shared_ptr<Button> addButton(ButtonFlags flags, float x, float y,
									  float w, float h, const T text) {
		if (flags == ButtonFlags::HCENTER || flags == ButtonFlags::CENTER)
			x = width / 2.0f - w / 2.0f;
		if (flags == ButtonFlags::VCENTER || flags == ButtonFlags::CENTER)
			y = height / 2.0f - h / 2.0f;
		return this->addButton(x, y, w, h, text);
	}

	std::shared_ptr<Slider> addSlider(float x, float y, float w, float h,
									  float ballSize);

	void update(double dt);
	void draw();

	static void drawOutline(float x, float y, float w, float h, u8 scale = 2,
							Color color = BUTTON_BORDER);

	Color primaryCol, textCol, pressedCol;

   private:
	int width, height;
	std::vector<std::shared_ptr<Widget>> widgets;
	touchPosition previousTouch;
};
