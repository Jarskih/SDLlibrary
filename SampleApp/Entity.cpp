#include "Entity.h"

Entity::Entity(const SDLlib::Renderer& renderer, SDL_Rect rectangle, const std::string& path)
	: x_(rectangle.x)
	, y_(rectangle.y)
	, texture_(SDLlib::Texture(renderer, path))
	, source_{ 0,0, texture_.GetWidth(), texture_.GetHeight() }
	, destination_{ rectangle.x, rectangle.y, rectangle.w, rectangle.h }
{
}

void Entity::Render(const SDLlib::Renderer& renderer)
{
	renderer.RenderCopy(texture_, &source_, &destination_);
}
