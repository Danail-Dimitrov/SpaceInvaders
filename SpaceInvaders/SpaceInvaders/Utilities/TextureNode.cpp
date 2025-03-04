#include "TextureNode.h"

TextureNode::TextureNode(sf::Texture* texture, sf::Sprite* sprite, sf::Vector2f offset)
{
	this->texture = texture;
	this->sprite = sprite;
	this->offset = offset;
}

TextureNode::~TextureNode()
{
	delete this->sprite;
	delete this->texture;
	for (auto child : children) 
		delete child;
	
	children.clear();
}

void TextureNode::move(const sf::Vector2f& position)
{
	float x = position.x + this->offset.x;
	float y = position.y + this->offset.y;
	this->sprite->setPosition({ x, y});

	for (auto child : children)
		child->move({ x,y });
}

void TextureNode::addChild(sf::Texture* texture, sf::Sprite* sprite, sf::Vector2f offset)
{
	float x = this->sprite->getPosition().x + offset.x;
	float y = this->sprite->getPosition().y + offset.y;

	sprite->setPosition({ x, y });

	TextureNode* child = new TextureNode(
		texture,
		sprite,
		offset
	);

	this->children.push_back(child);
}

void TextureNode::render(sf::RenderTarget& target)
{
	target.draw(*this->sprite);
	for (auto child : children)
		child->render(target);
}

std::vector<TextureNode*> TextureNode::getChildren()
{
	return this->children;
}
