#pragma once

#include "shape.hpp"

/**
 * @brief geometry for a rectangle
 * 
 * inherite from Shape
 * a rectangle have a width and a height
 */
class RectangleShape : public Shape
{
    private : 

        float m_height;
        float m_width;

    public :

        /**
         * @brief main constructor
         * @param width the rectangle width
         * @param height the rectangle height
         */
        RectangleShape(float width, float height);

        /**
         * @brief width getter
         */
        float get_width();

        /**
         * @brief height getter
         */
        float get_height();

        /**
         * @brief return half of the rectangle height
         */
        float get_half_height();

        /**
         * @brief return half of the circle width
         */
        float get_half_width();
};