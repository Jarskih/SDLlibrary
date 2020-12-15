#include "Entity.h"

Entity::Entity(const SDLlib::Renderer& renderer, SDL_Point position, SDLlib::Rectangle size, const std::string& path)
	: x_(position.x)
	, y_(position.y)
	, texture_(SDLlib::Texture(renderer, path))
	, source_{ 0,0, texture_.Size().w, texture_.Size().h }
	, destination_{ position.x, position.y, size.w, size.h }
{
}

void Entity::Update()
{
}

void Entity::Render(const SDLlib::Renderer& renderer) const
{
	renderer.RenderCopy(texture_, &source_, &destination_);
}
