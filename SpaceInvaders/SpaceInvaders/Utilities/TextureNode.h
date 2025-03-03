#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

// This class will be used to construct parent - children relashionship betwen models. 
// For example the space ship has engine, which has flames
class TextureNode
{
public:
    TextureNode(const sf::Texture& texture, sf::Sprite* sprite, const sf::Vector2f& offset);
    virtual ~TextureNode();

    void move(const sf::Vector2f& position);
    void addChild(TextureNode* child);

private:
    sf::Texture texture;
    sf::Sprite* sprite;
    sf::Vector2f offset; // Offset  from the position of the parrent
    std::vector<TextureNode*> children;
};