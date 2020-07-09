#include "MovementComponent.h"

//Constructor /Destructor
MovementComponent::MovementComponent(sf::Sprite &sprite,
	float maxVelocity, float acceleration, float deceleration)
	:sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{

}

MovementComponent::~MovementComponent()
{
}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

const bool MovementComponent::idle() const
{
	if (this->velocity.x == 0.f && this->velocity.y == 0.f) 
		return true;
	return false;
}

//Functions
void MovementComponent::move(const float dir_x, const float dir_y)
{
	/*Accelerating a Sprite until it reaches the max volocity*/
	this->velocity.x += this->acceleration * dir_x;
	this->velocity.y += this->acceleration * dir_y;
}

void MovementComponent::update(const float& dt)
{
	/*
	Decelerates the sprite and controls the maximum velocity.
	Moves the Sprite.
	*/

	//Deceleration 
	if (this->velocity.x > 0.f) // check for positive x
	{
		//Max velocity check 
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;

		//Deceleration 
		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;
	}
	else if(this->velocity.x < 0.f) //check for negative x
	{
		//Max velocity check
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;

		//Deceleration 
		this->velocity.x += deceleration;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}

	if (this->velocity.y > 0.f) // check for positive y
	{
		//Max velocity check 
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;

		//Deceleration 
		this->velocity.y -= deceleration;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;
	}
	else if (this->velocity.y < 0.f) //check for negative y
	{
		//Max velocity check
		if (this->velocity.y < -this->maxVelocity)
			this->velocity.y = -this->maxVelocity;

		//Deceleration 
		this->velocity.y += deceleration;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}

	//Final move
	this->sprite.move(this->velocity * dt); //Uses velocity
}
