#pragma once

#include "shape.hpp"

/**
 * @brief geometry for a circle
 * 
 * inherite from Shape
 * a circle have a radius
 */
class CircleShape: public Shape
{
    private :

        float m_radius;

    public :

        /**
         * @brief main constructor
         * @param radius the circle radius
         */
        CircleShape(float radius);

        /**
         * @brief radius getter
         */
        float get_radius();

        /**
         * @brief return half of the circle height
         * 
         * wil return the radius
         */
        float get_half_height();

        /**
         * @brief return half of the circle width
         * 
         * wil return the radius
         */
        float get_half_width();

};