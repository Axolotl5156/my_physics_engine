#include "body.hpp"

Body::Body(float pos_x, float pos_y, float vel_x, float vel_y, float fx, float fy, float mass, std::unique_ptr<Shape> shape):
m_pos_x(pos_x),
m_pos_y(pos_y),
m_vel_x(vel_x),
m_vel_y(vel_y),
m_fx(fx),
m_fy(fy),
m_mass(mass),
m_shape(std::move(shape))
{}

Body::Body(float pos_x, float pos_y, float vel_x, float vel_y, float mass, std::unique_ptr<Shape> shape):
m_pos_x(pos_x),
m_pos_y(pos_y),
m_vel_x(vel_x),
m_vel_y(vel_y),
m_fx(0.f),
m_fy(0.f),
m_mass(mass),
m_shape(std::move(shape))
{}

Body::Body(float pos_x, float pos_y, float mass, std::unique_ptr<Shape> shape):
m_pos_x(pos_x),
m_pos_y(pos_y),
m_vel_x(0.f),
m_vel_y(0.f),
m_fx(0.f),
m_fy(0.f),
m_mass(mass),
m_shape(std::move(shape))
{}

//getters
float Body::get_pos_x()
{
    return m_pos_x;
}

float Body::get_pos_y()
{
    return m_pos_y;
}

float Body::get_vel_x()
{
    return m_vel_x;
}

float Body::get_vel_y()
{
    return m_vel_y;
}

float Body::get_fx()
{
    return m_fx;
}

float Body::get_fy()
{
    return m_fy;
}

float Body::get_mass()
{
    return m_mass;
}

Shape* Body::get_shape()
{
    return m_shape.get();
}

//setters
void Body::set_pos_x(float pos_x)
{
    m_pos_x = pos_x;
}

void Body::set_pos_y(float pos_y)
{
    m_pos_y = pos_y;
}

void Body::set_vel_x(float vel_x)
{
    m_vel_x = vel_x;
}

void Body::set_vel_y(float vel_y)
{
    m_vel_y = vel_y;
}

void Body::set_fx(float fx)
{
    m_fx = fx;
}

void Body::set_fy(float fy)
{
    m_fy = fy;
}

void Body::set_mass(float mass)
{
    m_mass = mass;
}

void Body::apply_force(float fx, float fy)
{
    m_fx += fx;
    m_fy += fy;
}

void Body::reset_force()
{
    m_fx = 0.f;
    m_fy = 0.f;
}

void Body::update(float dt)
{
    float ax = m_fx / m_mass;
    float ay = m_fy / m_mass;

    m_vel_x += ax * dt;
    m_vel_y += ay * dt;

    m_pos_x += m_vel_x * dt;
    m_pos_y += m_vel_y * dt;

    reset_force();
}

