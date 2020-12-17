#pragma once
#include "SDLlib.h"

class Entity
{
public:
	Entity() = delete;
	Entity(const SDLlib::Renderer& renderer, SDLlib::Rect rectangle, const std::string& path);
	void Render(const SDLlib::Renderer& renderer) const;
private:
	int x_{};
	int y_{};
	SDLlib::Texture texture_;
	SDLlib::Rect source_;
	SDLlib::Rect destination_;
};

