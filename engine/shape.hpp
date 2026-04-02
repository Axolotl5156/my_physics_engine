#pragma once

class Shape
{
    public :

        Shape() = default;
        virtual ~Shape() = default;
        
        virtual float get_half_height() = 0;
        virtual float get_half_width() = 0;
};