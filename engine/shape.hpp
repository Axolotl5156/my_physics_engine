#pragma once

/**
 * @brief Abstract class for geometry
 * 
 * this abstract class will inherite different shapes
 * all shapes will be able to get half of their height and width
 */
class Shape
{
    public :

        Shape() = default;
        virtual ~Shape() = default;
        
        virtual float get_half_height() = 0;
        virtual float get_half_width() = 0;
};