#pragma once
#include "SDLlib.h"

class Entity
{
public:
	Entity() = delete;
	Entity(const SDLlib::Renderer& renderer, SDL_Point position, SDLlib::Rectangle size, const std::string& path);
	void Update();
	void Render(const SDLlib::Renderer& renderer) const;
private:
	int x_{};
	int y_{};
	SDLlib::Texture texture_;
	SDL_Rect source_;
	SDL_Rect destination_;
};

