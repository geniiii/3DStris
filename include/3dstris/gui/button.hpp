#pragma once

#include <3dstris/gui/widget.hpp>
#include <3dstris/util/text.hpp>

class Button : public Widget {
   public:
	static constexpr Color BUTTON = C2D_Color32(33, 34, 48, 255);
	static constexpr Color BUTTON_OUTLINE = C2D_Color32(35, 36, 51, 255);
	static constexpr Color BUTTON_HELD = C2D_Color32(26, 27, 38, 255);

	enum class Flags { NONE, HCENTER, VCENTER, CENTER };

	Button(GUI& parent, const Pos pos, const WH wh, sds text,
		   const Flags flags = Flags::NONE);
	Button(GUI& parent, const Pos pos, const WH wh, const char* __restrict text,
		   const Flags flags = Flags::NONE);

	void setText(sds text);

	void draw() const override;
	void update(const touchPosition touch,
				const touchPosition previous) override;

	bool inside(const float x, const float y) const noexcept;
	bool pressed();

   private:
	Text text;

	bool held = false;
	bool _pressed = false;
};
