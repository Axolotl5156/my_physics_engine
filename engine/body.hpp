#pragma once
#include <memory>

#include "shape.hpp"

/**
 * @brief Represent a physical object in the simulation
 * 
 * A body has a position, a velocity, a masse and a Shape.
 * It can receive forces and evoluate through time, in a World
 */
class Body
{

    private :

        float m_pos_x, m_pos_y;
        float m_vel_x, m_vel_y;
        float m_fx, m_fy;
        float m_mass;

        std::unique_ptr<Shape> m_shape;

    public :

        /**
         * @brief main constructor
         * @param pos_x initial x position
         * @param pos_y initial y position
         * @param vel_x initial x velocity
         * @param vel_y initial y velocity
         * @param mass the body's mass
         * @param shape geometrycal shape associate to this body 
         */
        Body(float pos_x, float pos_y, float vel_x, float vel_y, float mass, std::unique_ptr<Shape> shape);

        /**
         * @brief secondary constructor
         * @param pos_x initial x position
         * @param pos_y initial y position
         * @param vel_x initial x velocity
         * @param vel_y initial y velocity
         * @param fx initial x forces
         * @param fy initial y forces
         * @param mass the body's mass
         * @param shape geometrycal shape associate to this body 
         * 
         */
        Body(float pos_x, float pos_y, float vel_x, float vel_y, float fx, float fy, float mass, std::unique_ptr<Shape> shape);

        /**
         * @brief secondary constructor
         * @param pos_x initial x position
         * @param pos_y initial y position
         * @param mass the body's mass
         * @param shape geometrycal shape associate to this body 
         * 
         * initial velocity will be set to 0
         */
        Body(float pos_x, float pos_y, float mass, std::unique_ptr<Shape> shape);

        /**
         * @brief position x getter
         */
        float get_pos_x();

        /**
         * @brief position y getter
         */
        float get_pos_y();

        /**
         * @brief velocity x getter
         */
        float get_vel_x();

        /**
         * @brief velocity y getter
         */
        float get_vel_y();

        /**
         * @brief forces x getter
        */
        float get_fx();

        /**
         * @brief forces y getter
         */
        float get_fy();

        /**
         * @brief mass getter
         */
        float get_mass();

        /**
         * @brief shape getter
         */
        Shape *get_shape();

        /**
         * @brief position x setter
         * @param pos_x new x position
         */
        void set_pos_x(float pos_x);

        /**
         * @brief position y setter
         * @param pos_y new y position
         */
        void set_pos_y(float pos_y);

        /**
         * @brief velocity x setter
         * @param vel_x new x velocity
         */
        void set_vel_x(float vel_x);

        /**
         * @brief velocity y setter
         * @param vel_y new y position
         */
        void set_vel_y(float vel_y);

        /**
         * @brief force x setter
         * @param fx new x force
         * 
         * note that this will not juste add the new force, but replace it
         */
        void set_fx(float fx);

        /**
         * @brief force y setter
         * @param fx new y force
         * 
         * note that this will not juste add the new force, but replace it
         */
        void set_fy(float fy);

        /**
         * @brief mass setter
         * @param mass new mass
         */
        void set_mass(float mass);

        /**
         * @brief Apply a force to the body
         * @param fx the force to apply on x
         * @param fy the force to apply on y
         * 
         * will add fx and fy to the already existing forces
         */
        void apply_force(float fx, float fy);

        /**
         * @brief update the body state for the next time step
         * @param dt time step
         * 
         * will update body's position and velocity, by applying the forces
         * then reset forces to 0
         */
        void update(float dt);

        /**
         * @brief set forces to 0
         */
        void reset_force();

};