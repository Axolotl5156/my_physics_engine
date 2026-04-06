#include <iostream>
#include "test_sim.hpp"

#include "world.hpp"
#include "body.hpp"
#include "circleShape.hpp"
#include "rectangleShape.hpp"
#include "rendererSFML.hpp"

void TestSim::run(AppContext config)
{

    World world(800, 800);
    // world.set_gravity(0.f);

    Body *body_a = world.add_circle(400.f, 200.f, 0.f, 0.f, 1.f, 10.f, BodyType::Static);
    Body *body_b = world.add_circle(550.f, 200.f, 0.f, 0.f, 1.f, 10.f, BodyType::Dynamic);
    Body *body_c = world.add_circle(700.f, 200.f, 0.f, 0.f, 1.f, 10.f, BodyType::Dynamic);

    world.add_distance_constraint(body_a, body_b);
    world.add_distance_constraint(body_b, body_c);

    RendererSFML renderer(world.get_width(), world.get_height(), "test sim");
    
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