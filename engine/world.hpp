#pragma once
#include <vector>
#include <memory>
#include "body.hpp"
#include "constraint.hpp"

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
        std::vector<std::unique_ptr<Constraint>> m_constraints; 

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
         * @brief get list of constraints
         */
        std::vector<std::unique_ptr<Constraint>> &get_constraints();

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
        Body * add_body(std::unique_ptr<Body> body);

        /**
         * @brief add a circle to the world
         * @param pos_x x position for the circle
         * @param pos_y y position for the circle
         * @param vel_x initiale x velocity
         * @param vel_y initiale y velocity
         * @param mass the body's mass
         * @param radius the circle's radius
         * @param type type of the circle, static or dynamic
         */
        Body * add_circle(float pos_x, float pos_y, float vel_x, float vel_y, float mass, float radius, BodyType type);

        /**
         * @brief add a circle to the world
         * @param pos_x x position for the circle
         * @param pos_y y position for the circle
         * @param vel_x initiale x velocity
         * @param vel_y initiale y velocity
         * @param mass the body's mass
         * @param width the rectangle's width
         * @param height the rectangle's height
         * @param type type of the rectangle, static or dynamic
         */
        Body * add_rectangle(float pos_x, float pos_y, float vel_x, float vel_y, float mass, float width, float height, BodyType type);

        /**
         * @brief add a new constraint to the world
         */
        void add_constraint(std::unique_ptr<Constraint> constraint);

        /**
         * @brief add a distance constraint between two bodies
         * @param body_a the first body to link
         * @param body_b the second body to link
         * 
         * the bodies will be constraint by the distance between theme at the creation of this link
         */
        void add_distance_constraint(Body *body_a, Body *body_b);

        /**
         * @brief update all bodies
         * @param dt step time
         */
        void update_world(float dt);

};