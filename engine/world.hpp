#pragma once
#include <vector>
#include <memory>
#include "body.hpp"

class World
{

    private : 

        float m_width;
        float m_height;
        float m_gravity;
        float m_restitution;

        std::vector<std::unique_ptr<Body>> m_bodies;

        void bodies_to_bodies_collision();

    public :

        World(float width, float height);
        World(float width, float height, float gravity, float restitution);

        float get_width();
        float get_height();
        float get_gravity();
        float get_restitution();

        std::vector<std::unique_ptr<Body>>& get_bodies();

        void set_gravity(float gravity);
        void set_restition(float restitution);

        void add_body(std::unique_ptr<Body> body);
        void update_world(float dt);

};