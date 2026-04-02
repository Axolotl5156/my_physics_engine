#include "rendererSFML.hpp"

#include "circleShape.hpp"

RendererSFML::RendererSFML(float width, float height, const std::string &title):
m_is_paused(false),
m_bg_color((20,20,20,255))
{
    m_window.create({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}, title);
    m_window.setFramerateLimit(60);
}

RendererSFML::RendererSFML(float width, float height, const std::string &title, int frame_limit):
m_is_paused(false),
m_bg_color((20,20,20,255))
{
    m_window.create({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}, title);
    m_window.setFramerateLimit(frame_limit);
}

RendererSFML::RendererSFML(float width, float height, const std::string &title, sf::Color bg_color):
m_is_paused(false),
m_bg_color(bg_color)
{
    m_window.create({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}, title);
    m_window.setFramerateLimit(60);
}

RendererSFML::RendererSFML(float width, float height, const std::string& title, int frame_limit, sf::Color bg_color):
m_is_paused(false),
m_bg_color(bg_color)
{
    m_window.create({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}, title);
    m_window.setFramerateLimit(frame_limit);
}

void RendererSFML::set_bg_color(sf::Color color)
{
    m_bg_color = color;
}

bool RendererSFML::is_open()
{
    return m_window.isOpen();
}

bool RendererSFML::is_paused()
{
    return m_is_paused;
}

void RendererSFML::clear()
{
    m_window.clear(m_bg_color);
}

void RendererSFML::display()
{
    m_window.display();
}

void RendererSFML::handle_events()
{

    sf::Event event;

    while(m_window.pollEvent(event));
    {
        if (event.type == sf::Event::Closed)
            m_window.close();

        if (event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Escape)
                m_window.close();

            if(event.key.code == sf::Keyboard::Space)
                m_is_paused = !m_is_paused;
        }
    }
}

void RendererSFML::draw_frame(World &world)
{
     std::vector<std::unique_ptr<Body>> &bodies = world.get_bodies();

     for(std::unique_ptr<Body> &body : bodies)
     {

        Shape *shape = body->get_shape();

        if(CircleShape* circle = dynamic_cast<CircleShape*>(shape))
        {
            float radius = circle->get_radius();
            sf::CircleShape drawable_circle(radius);
            drawable_circle.setOrigin({radius, radius});
            drawable_circle.setPosition({body->get_pos_x(), body->get_pos_y()});
            drawable_circle.setFillColor(sf::Color::White);

            m_window.draw(drawable_circle);
        }
     }
}