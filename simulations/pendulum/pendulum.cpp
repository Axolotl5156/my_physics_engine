#include "pendulum.hpp"

#include <iostream>

#include "world.hpp"
#include "body.hpp"
#include "circleShape.hpp"
#include "rendererSFML.hpp"

void PendulumSimulation::run(AppContext config)
{

    World world(800, 800);

    Body *pivot = world.add_circle(400.f, 100.f, 0.f, 0.f, 1.f, 10.f, BodyType::Static);
    Body *mass = world.add_circle(600.f, 100.f, 0.f, 0.f, 1.f, 10.f, BodyType::Dynamic);

    world.add_distance_constraint(pivot, mass);

    RendererSFML renderer(world.get_width(), world.get_height(), "pendulum");

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