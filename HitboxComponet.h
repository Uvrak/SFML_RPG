#ifndef HITBOXCOMPONENT
#define HITBOXCOMPONENT

class HitboxComponet
{
private:
	sf::Sprite& sprite;
	sf::RectangleShape hitbox;
	float offsetX;
	float offsetY;

public:
	HitboxComponet(sf::Sprite& sprite, 
		float offset_x, float offset_y, 
		float width, float height);
	virtual ~HitboxComponet();

	//Functions
	bool checkIntersect(const sf::FloatRect &frect);
	void update();
	void render(sf::RenderTarget& target);
};
#endif

