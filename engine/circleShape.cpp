#include "circleShape.hpp"

CircleShape::CircleShape(float radius):
m_radius(radius)
{}
 
float CircleShape::get_radius()
{
    return m_radius;
}

float CircleShape::get_half_height()
{
    return m_radius;
}

float CircleShape::get_half_width()
{
    return m_radius;
}