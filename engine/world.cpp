#include "world.hpp"

#include "shape.hpp"
#include "circleShape.hpp"
#include "rectangleShape.hpp"

#include <iostream>
#include <math.h>

World::World(float width, float height):
m_width(width),
m_height(height),
m_gravity(981.f),
m_restitution(0.8f)
{}

World::World(float width, float height, float gravity, float restitution):
m_width(width),
m_height(height),
m_gravity(gravity),
m_restitution(restitution)
{}

float World::get_width()
{
    return m_width;
}

float World::get_height()
{
    return m_height;
}

float World::get_gravity()
{
    return m_gravity;
}

float World::get_restitution()
{
    return m_restitution;
}

std::vector<std::unique_ptr<Body>>& World::get_bodies()
{
    return m_bodies;
}

void World::set_gravity(float gravity)
{
    m_gravity = gravity;
}

void World::set_restition(float restitution)
{
    m_restitution = restitution;
}

void World::add_body(std::unique_ptr<Body> body)
{
    m_bodies.push_back(std::move(body));
}

void World::add_circle(float pos_x, float pos_y, float vel_x, float vel_y, float mass, float radius)
{
    std::unique_ptr<Shape> shape = std::make_unique<CircleShape>(radius);
    std::unique_ptr<Body> body = std::make_unique<Body>(pos_x, pos_y, vel_x, vel_y, mass, std::move(shape));
    add_body(std::move(body));
}

void World::add_rectangle(float pos_x, float pos_y, float vel_x, float vel_y, float mass, float width, float height)
{
    std::unique_ptr<Shape> shape = std::make_unique<RectangleShape>(width, height);
    std::unique_ptr<Body> body = std::make_unique<Body>(pos_x, pos_y, vel_x, vel_y, mass, std::move(shape));
    add_body(std::move(body));
}

void World::bodies_to_bodies_collision()
{
    for(size_t i = 0; i < m_bodies.size(); ++i)
    {
        for(size_t j = i+1; j < m_bodies.size(); ++j)
        {
            std::unique_ptr<Body>& body_a = m_bodies[i];
            std::unique_ptr<Body>& body_b = m_bodies[j];

            float dx = std::abs(body_a->get_pos_x() - body_b->get_pos_x());
            float dy = std::abs(body_a->get_pos_y() - body_b->get_pos_y());

            float overlap_x = body_a->get_shape()->get_half_width() + body_b->get_shape()->get_half_width() - dx;
            float overlap_y = body_a->get_shape()->get_half_width() + body_b->get_shape()->get_half_width() - dy;

            if(overlap_x > 0 && overlap_y > 0)
            {
                // normal vector to collision
                float normal_x = body_a->get_pos_x() - body_b->get_pos_x();
                float normal_y = body_a->get_pos_y() - body_b->get_pos_y();
                float dist = sqrt(normal_x*normal_x + normal_y*normal_y);
                normal_x = normal_x / dist;
                normal_y = normal_y / dist;

                // tangeante vector to collision
                float tangeante_x = -normal_y;
                float tangeante_y = normal_x;

                //project the velocity on normal and tangeante axis
                float velocity_a_normal = body_a->get_vel_x()*normal_x + body_a->get_vel_y()*normal_y;
                float velocity_a_tangeante = body_a->get_vel_x()*tangeante_x + body_a->get_vel_y()*tangeante_y;
                float velocity_b_normal = body_b->get_vel_x()*normal_x + body_b->get_vel_y()*normal_y;
                float velocity_b_tangeante = body_b->get_vel_x()*tangeante_x + body_b->get_vel_y()*tangeante_y;

                //calculate new velocity on normal axis
                float vel_a_normal_mass = (body_a->get_vel_x()*(body_a->get_mass()-body_b->get_mass())+2*body_b->get_mass()*velocity_b_normal)/(body_a->get_mass()+body_b->get_mass());
                float vel_b_normal_mass = (body_b->get_vel_x()*(body_b->get_mass()-body_a->get_mass())+2*body_a->get_mass()*velocity_a_normal)/(body_a->get_mass()+body_b->get_mass());

                //project new velicity on xy axis
                body_a->set_vel_x(vel_a_normal_mass*normal_x + velocity_a_tangeante*tangeante_x);
                body_a->set_vel_y(vel_a_normal_mass*normal_y + velocity_a_tangeante*tangeante_y);
                body_b->set_vel_x(vel_b_normal_mass*normal_x + velocity_b_tangeante*tangeante_x);
                body_b->set_vel_y(vel_b_normal_mass*normal_y + velocity_b_tangeante*tangeante_y);
            }

        }
    }
}

void World::update_world(float dt)
{
    for(std::unique_ptr<Body>& body : m_bodies)
    {
        //gravity
        body->apply_force(0.f, m_gravity*body->get_mass());
        body->update(dt);

        //collision
        float x = body->get_pos_x();
        float y = body->get_pos_y();
        float vx = body->get_vel_x();
        float vy = body->get_vel_y();

        float halfw = body->get_shape()->get_half_width();
        float halfh = body->get_shape()->get_half_height();

        if(y + halfh > m_height && vy > 0) //collide with ground
        {
            body->set_pos_y(m_height - halfh);
            body->set_vel_y(-vy * m_restitution);
        }
        if(y - halfh < 0 && vy < 0) //collide with top
        {
            body->set_pos_y(halfh);
            body->set_vel_y(-vy * m_restitution);
        }
        if(x + halfw > m_width && vx > 0) //collide with right wall
        {
            body->set_pos_x(m_width - halfw);
            body->set_vel_x(-vx * m_restitution);
        }
        if(x - halfw < 0 && vx < 0) //collide with left wall
        {
            body->set_pos_x(halfw);
            body->set_vel_x(-vx * m_restitution);
        }
    }

    bodies_to_bodies_collision();

}