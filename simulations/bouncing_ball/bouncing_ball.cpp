
#include "bouncing_ball.hpp"

#include "world.hpp"
#include "body.hpp"
#include "circleShape.hpp"
#include "rendererSFML.hpp"

void BouncingBallSimulation::run(AppContext config)
{
    World world(800, 600);
    world.set_gravity(981.f);
    world.set_restition(0.8f);

    world.add_circle(400.f, 100.f, 0.f, 0.f, 1.f, 10.f);

    RendererSFML renderer(world.get_width(), world.get_height(), "Bouncing ball", sf::Color(20,20,20,255));
    
    if(config.record_enable)
        renderer.enable_recording(config.output_file);

    sf::Clock clock;

    while(renderer.is_open())
    {

        float dt = clock.restart().asSeconds();

        renderer.handle_events();

        if(!renderer.is_paused())
        {
            world.update_world(dt);
        }

        renderer.clear();
        renderer.draw_frame(world);
        renderer.display();

    }

    if(config.record_enable)
        renderer.finalize_recording();

}