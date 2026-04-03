#pragma once
#include <vector>
#include <memory>
#include "body.hpp"

/**
 * @brief represent a physical world, where all Body will evoluate
 * 
 * a world manage gravity, collisions, and global evloution through time 
 */
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

        /**
         * @brief main constructor
         * @param width world's width
         * @param height world's width
         * 
         * default gravity is 981 and default restitution coefficient is 0.8
         */
        World(float width, float height);

        /**
         * @brief secondary constructor
         * @param width world's  width
         * @param height world's height
         * @param gravity set world's gravity
         * @param restitution set world's restitution coefficient
         */
        World(float width, float height, float gravity, float restitution);

        /**
         * @brief width getter
         */
        float get_width();

        /**
         * @brief height getter
         */
        float get_height();

        /**
         * @brief gravity geter
         */
        float get_gravity();

        /**
         * restitution coefficient getter
         */
        float get_restitution();

        /**
         * @brief list of bodies getter
         */
        std::vector<std::unique_ptr<Body>>& get_bodies();

        /**
         * @brief gravity setter
         * @param gravity new gravity
         */
        void set_gravity(float gravity);

        /**
         * @brief restitution coefficient setter
         * @param restitution new restitution coefficient
         */
        void set_restition(float restitution);

        /**
         * @brief add a Body to the world
         * @param body the body to add
         */
        void add_body(std::unique_ptr<Body> body);

        /**
         * @brief update all bodies
         * @param dt step time
         */
        void update_world(float dt);

};