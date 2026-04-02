#pragma once

#include <SFML/Graphics.hpp>
#include "world.hpp"


class RendererSFML
{

    private :

        sf::RenderWindow m_window;
        sf::Color m_bg_color;
        bool m_is_paused;

    public :

        RendererSFML(float width, float height, const std::string &title);
        RendererSFML(float width, float height, const std::string &title, int frame_limit);
        RendererSFML(float width, float height, const std::string &title, sf::Color bg_color);
        RendererSFML(float width, float height, const std::string &title, int frame_limit, sf::Color bg_color);

        void set_bg_color(sf::Color color);

        bool is_open();
        bool is_paused();
        void handle_events();
        void draw_frame(World &world);
        void clear();
        void display();

};