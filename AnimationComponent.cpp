#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet)
	: sprite(sprite), textureSheet(textureSheet)
{
}

AnimationComponent::~AnimationComponent()
{
}

void AnimationComponent::addAnimation(const std::string key)
{
}

void AnimationComponent::startAnimation(std::string animation)
{
}

void AnimationComponent::pauseAnimation(std::string animation)
{
}

void AnimationComponent::resetAnimation(std::string animation)
{
}

void AnimationComponent::update(const float& dt)
{
}
