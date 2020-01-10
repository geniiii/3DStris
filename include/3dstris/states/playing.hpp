#pragma once

#include <3dstris/board.hpp>
#include <3dstris/shapes.hpp>
#include <3dstris/ingame.hpp>
#include <3dstris/util.hpp>
#include <deque>
#include <random>

class Playing : public Ingame {
   public:
	Playing();

	void update(double dt) override;
};
