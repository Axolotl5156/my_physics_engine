#include "rectangleShape.hpp"

RectangleShape::RectangleShape(float height, float width):
m_width(width),
m_height(height)
{}

float RectangleShape::get_height()
{
    return m_height;
}

float RectangleShape::get_width()
{
    return m_width;
}

float RectangleShape::get_half_height()
{
    return m_height/2;
}

float RectangleShape::get_half_width()
{
    return m_width/2;
}