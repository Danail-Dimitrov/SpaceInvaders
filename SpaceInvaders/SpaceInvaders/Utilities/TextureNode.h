#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <string>

// This class will be used to construct parent - children relashionship betwen models. 
// For example the space ship has engine, which has flames
// In a case where this class will be reused more I would add id or name to the node
// It will be used to find a given tecture in the three
// But I will use it for a linear three whre I have 2 parents and 2 kids (A -> B -> C) I will skip it
// In order to save time and focus in the game itself I will just use their indexes in the vector
class TextureNode
{
public:
    TextureNode(sf::Texture* texture, sf::Sprite* sprite, sf::Vector2f offset);
    virtual ~TextureNode();

    void move(const sf::Vector2f& position);
    // Adds a child to the current node
    // The position of the child will be recalcuated based on the curent nodes position and the offset
    void addChild(sf::Texture* texture, sf::Sprite* sprite, sf::Vector2f offset);
	void setSpriteRect(const sf::IntRect& rect);

    void render(sf::RenderTarget& target);

    std::vector<TextureNode*> getChildren();
	sf::Sprite* getSprite();
	sf::Vector2f getPosition() const { return this->sprite->getPosition(); }
	sf::Vector2f getSize() const { return sf::Vector2f(this->sprite->getGlobalBounds().size.x, this->sprite->getGlobalBounds().size.y); }
    
private:
    sf::Texture* texture;
    sf::Sprite* sprite;
    // Offset  from the position of the parrent
    // The offset of the current child's parent. Not the top parrent
    // Do I need the offset. Perhaps I can use the sprites' positions to calcuate it
    // Removing it will mean I must be sure the positions don't get corrupted but will save some memory.
    // I finally decided to keep it. If some rounding error occures it can stack up and eventually can lead to the loss of the original offset
    sf::Vector2f offset; 
    std::vector<TextureNode*> children;
};