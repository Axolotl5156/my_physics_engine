#pragma once

#include <SFML/Graphics.hpp>
#include "world.hpp"

/**
 * @brief renderer based on SFML Library
 * 
 * manage the window, and the display of all Body in the World
 */
class RendererSFML
{

    private :

        sf::RenderWindow m_window;
        sf::Color m_bg_color;
        bool m_is_paused;
        bool m_recording;
        std::string m_output_path;
        std::string m_tmp_folder;
        int m_frame_id;

    public :

        /**
         * @brief main constructor
         * @param width window width
         * @param height window height
         * @param title the window title
         * 
         * the width and height must be the same as the world's wigth and height
         * default frame limit is set to 60
         * default background color is set to (20,20,20,255)
         */
        RendererSFML(float width, float height, const std::string &title);

        /**
         * @brief secondary constructor
         * @param width window width
         * @param height window height
         * @param title the window title
         * @param frame_limit the window frame limit
         * 
         * the width and height must be the same as the world's wigth and height
         * default background color is set to (20,20,20,255)
         */
        RendererSFML(float width, float height, const std::string &title, int frame_limit);

        /**
         * @brief secondary constructor
         * @param width window widthint m_frame_id
         * @param height window height
         * @param title the window title
         * @param bg_color background color
         * 
         * the width and height must be the same as the world's wigth and height
         * default frame limit is set to 60
         */
        RendererSFML(float width, float height, const std::string &title, sf::Color bg_color);

        /**
         * @brief secondary constructor
         * @param width window width
         * @param height window height
         * @param title the window title
         * @param frame_limit the window frame limit
         * @param bg_color background color
         * 
         * the width and height must be the same as the world's wigth and height
         */
        RendererSFML(float width, float height, const std::string &title, int frame_limit, sf::Color bg_color);

        /**
         * @brief background color setter
         * @param color new background color
         */
        void set_bg_color(sf::Color color);

        /**
         * @brief check if window is still open
         */
        bool is_open();

        /**
         * @brief check if the simulation has been paused
         */
        bool is_paused();

        /**
         * @brief handle input events from user
         */
        void handle_events();

        /**
         * @brief render one frame of the simulation
         * @param world the world to draw
         */
        void draw_frame(World &world);

        /**
         * @brief clear window
         */
        void clear();

        /**
         * @brief display on window what has been drawn
         */
        void display();

        /**
         * @brief enable recording
         * @param output_pah path to save the video
         */
        void enable_recording(const std::string &output_path);

        /**
         * @brief check if recording has been activated
         */
        bool is_recording();

        /**
         * @brief capture a frame into a jpg file
         * 
         * all jpg files will be used to create the video of the simulation
         * only call if recording has been activate before
         */
        void capture_frame();

        /**
         * @brief combine all frame into a video
         * 
         * only call if recording has been activate before
         */
        void finalize_recording();
        
};