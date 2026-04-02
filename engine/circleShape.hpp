#pragma once

#include "shape.hpp"

class CircleShape: public Shape
{
    private :

        float m_radius;

    public :

        CircleShape(float radius);

        float get_radius();

        float get_half_height();
        float get_half_width();

};