#include "Entity.h"

Entity::Entity(const SDLlib::Renderer& renderer, SDLlib::Rect rectangle, const std::string& path)
	: x_(rectangle.GetX())
	, y_(rectangle.GetY())
	, texture_(SDLlib::Texture(renderer, path))
	, source_{ 0,0, texture_.GetWidth(), texture_.GetHeight() }
	, destination_{ rectangle.GetX(), rectangle.GetY(), rectangle.GetWidth(), rectangle.GetHeight() }
{
}

void Entity::Render(const SDLlib::Renderer& renderer) const
{
	renderer.RenderCopy(texture_, source_, destination_);
}
