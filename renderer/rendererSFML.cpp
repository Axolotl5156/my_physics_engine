#include <filesystem>
#include <iostream>

#include "rendererSFML.hpp"
#include "circleShape.hpp"

RendererSFML::RendererSFML(float width, float height, const std::string &title):
m_is_paused(false),
m_bg_color((20,20,20,255)),
m_recording(false)
{
    m_window.create({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}, title);
    m_window.setFramerateLimit(60);
}

RendererSFML::RendererSFML(float width, float height, const std::string &title, int frame_limit):
m_is_paused(false),
m_bg_color((20,20,20,255)),
m_recording(false)
{
    m_window.create({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}, title);
    m_window.setFramerateLimit(frame_limit);
}

RendererSFML::RendererSFML(float width, float height, const std::string &title, sf::Color bg_color):
m_is_paused(false),
m_bg_color(bg_color),
m_recording(false)
{
    m_window.create({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}, title);
    m_window.setFramerateLimit(60);
}

RendererSFML::RendererSFML(float width, float height, const std::string& title, int frame_limit, sf::Color bg_color):
m_is_paused(false),
m_bg_color(bg_color),
m_recording(false)
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
    if(m_recording)
        capture_frame();
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

void RendererSFML::enable_recording(const std::string &output_path)
{
    m_recording = true;
    m_output_path = output_path;
    m_tmp_folder = "tmp_frames/";
    std::filesystem::create_directories(m_tmp_folder);
    m_frame_id = 0;
}

bool RendererSFML::is_recording()
{
    return m_recording;
}

void RendererSFML::capture_frame()
{

    if(!m_recording)
        return;

    sf::Texture texture;
    texture.create(m_window.getSize().x, m_window.getSize().y);
    texture.update(m_window);

    sf::Image image = texture.copyToImage();

    std::ostringstream filename;
    filename << m_tmp_folder << "frame_" << std::setw(5) << std::setfill('0') << m_frame_id++ << ".jpg";

    image.saveToFile(filename.str());
}

void RendererSFML::finalize_recording()
{
    if(!m_recording)
        return;

    std::string command = "ffmpeg -loglevel quiet -y -framerate 60 -i " + m_tmp_folder + "frame_%05d.jpg -c:v libx264 -pix_fmt yuv420p " + m_output_path;

    system(command.c_str());
    std::filesystem::remove_all(m_tmp_folder);
    
}