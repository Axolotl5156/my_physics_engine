#pragma once
#include <memory>

#include "shape.hpp"

class Body
{

    private :

        float m_pos_x, m_pos_y;
        float m_vel_x, m_vel_y;
        float m_fx, m_fy;
        float m_mass;

        std::unique_ptr<Shape> m_shape;

    public :

        Body(float pos_x, float pos_y, float vel_x, float vel_y, float fx, float fy, float mass, std::unique_ptr<Shape> shape);
        Body(float pos_x, float pos_y, float vel_x, float vel_y, float mass, std::unique_ptr<Shape> shape);
        Body(float pos_x, float pos_y, float mass, std::unique_ptr<Shape> shape);

        float get_pos_x();
        float get_pos_y();
        float get_vel_x();
        float get_vel_y();
        float get_fx();
        float get_fy();
        float get_mass();
        Shape *get_shape();

        void set_pos_x(float pos_x);
        void set_pos_y(float pos_y);
        void set_vel_x(float vel_x);
        void set_vel_y(float vel_y);
        void set_fx(float fx);
        void set_fy(float fy);
        void set_mass(float mass);

        void apply_force(float fx, float fy);
        void update(float dt);
        void reset_force();

};