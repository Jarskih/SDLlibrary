#pragma once
#include "SDLlib.h"

class Entity
{
public:
	Entity() = delete;
	Entity(const SDLlib::Renderer& renderer, SDL_Rect rectangle, const std::string& path);
	void Render(const SDLlib::Renderer& renderer);
private:
	int x_{};
	int y_{};
	SDLlib::Texture texture_;
	SDL_Rect source_;
	SDL_Rect destination_;
};

