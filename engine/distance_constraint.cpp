#include "distance_constraint.hpp"

#include <math.h>

DistanceConstraint::DistanceConstraint(Body *body_a, Body *body_b):
m_body_a(body_a),
m_body_b(body_b)
{
    float distance_x = std::abs(body_a->get_pos_x() - body_b->get_pos_x());
    float distance_y = std::abs(body_a->get_pos_y() - body_b->get_pos_y());
    m_lenght = sqrt(distance_x*distance_x + distance_y*distance_y);
}

void DistanceConstraint::solve()
{
    float distance_x = m_body_a->get_pos_x() - m_body_b->get_pos_x();
    float distance_y = m_body_a->get_pos_y() - m_body_b->get_pos_y();

    float distance = sqrt(distance_x*distance_x + distance_y*distance_y);

    if (distance < 0.0001f)
        return;

    float nx = distance_x/distance;
    float ny = distance_y/distance;

    float diff = distance-m_lenght;


    if(!m_body_a->is_static())
    {
        m_body_a->set_pos_x(m_body_a->get_pos_x() - nx * diff * 0.5f);
        m_body_a->set_pos_y(m_body_a->get_pos_y() - ny * diff * 0.5f);
    }
    if(!m_body_b->is_static())
    {
        m_body_b->set_pos_x(m_body_b->get_pos_x() + nx * diff * 0.5f);
        m_body_b->set_pos_y(m_body_b->get_pos_y() + ny * diff * 0.5f);
    }

    float rel_vel_x = m_body_a->get_vel_x() - m_body_b->get_vel_x();
    float rel_vel_y = m_body_a->get_vel_y() - m_body_b->get_vel_y();

    float rel_vel_along_line = rel_vel_x * nx + rel_vel_y * ny;

    if(!m_body_a->is_static())
    {
        m_body_a->set_vel_x(m_body_a->get_vel_x() - nx * rel_vel_along_line * 0.5f);
        m_body_a->set_vel_y(m_body_a->get_vel_y() - ny * rel_vel_along_line * 0.5f);
    }
    if(!m_body_b->is_static())
    {
        m_body_b->set_vel_x(m_body_b->get_vel_x() + nx * rel_vel_along_line * 0.5f);
        m_body_b->set_vel_y(m_body_b->get_vel_y() + ny * rel_vel_along_line * 0.5);
    }

}