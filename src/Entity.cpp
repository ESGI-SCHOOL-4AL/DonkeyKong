#include "Entity.h"

bool Entity::collidesWith(sf::Sprite entity) {
    bool collidesX = m_position.x + m_size.x >= entity.getPosition().x && m_position.x <= entity.getPosition().x + entity.getTexture()->getSize().x;
    bool collidesY = m_position.y + m_size.y >= entity.getPosition().y && m_position.y <= entity.getPosition().y + entity.getTexture()->getSize().y;

    return collidesX && collidesY;
}