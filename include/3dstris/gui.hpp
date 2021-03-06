#pragma once

#include <3dstris/gui/button.hpp>
#include <3dstris/util.hpp>
#include <vector>

class GUI {
   public:
	GUI(const u32 width = BSCREEN_WIDTH, const u32 height = BSCREEN_HEIGHT,
		const Color primaryCol = Button::BUTTON, const Color textCol = WHITE,
		const Color pressedCol = Button::BUTTON_HELD,
		const Color outlineCol = Button::BUTTON_OUTLINE);

	u32 getWidth() const noexcept;
	u32 getHeight() const noexcept;

	void update(double dt);
	void draw() const;

	template <typename T, typename... Args>
	T& add(Args&&... args) {
		static_assert(std::is_convertible<T*, Widget*>::value,
					  "T* must be convertible to Widget*");

		widgets.push_back(make_unique<T>(*this, std::forward<Args>(args)...));
		return static_cast<T&>(*widgets.back());
	}

	static void drawOutline(const Pos pos, const WH wh, const float scale = 2,
							const Color color = Button::BUTTON_OUTLINE,
							const float depth = 1);

	static void drawHLine(const Pos pos, const float w, const float scale = 2,
						  const Color color = Button::BUTTON_OUTLINE,
						  const float depth = 0.5f);

	static void drawVLine(const Pos pos, const float h, const float scale = 2,
						  const Color color = Button::BUTTON_OUTLINE,
						  const float depth = 0.5f);

	Color primaryCol, textCol, pressedCol, outlineCol;

   private:
	u32 width, height;
	std::vector<std::unique_ptr<Widget>> widgets;
	touchPosition previousTouch;
};
