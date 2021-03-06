#pragma once

#include <3dstris/game/board.hpp>
#include <3dstris/state.hpp>
#include <deque>
#include <pcg_random.hpp>

class Ingame : public State {
   public:
	Ingame();

	virtual void reset();

	void update(const double dt) override;
	void draw(const bool bottom) override;

   protected:
	Board board;
	const u32 tileSize;
	Pos origin;

	pcg32_fast bagRNG;
	const u32 upcoming;
	std::deque<PieceType> bag;

	Piece piece;

	PieceType hold;
	bool hasHeld;
};
