#include <iostream>
#include "test_sim.hpp"

#include "world.hpp"
#include "body.hpp"
#include "circleShape.hpp"
#include "rendererSFML.hpp"

void TestSim::run(AppContext config)
{

    World world(800, 800);
    world.set_gravity(0.f);
    world.set_restition(1.f);

    std::unique_ptr<Shape> shape_1 = std::make_unique<CircleShape>(10.f);
    std::unique_ptr<Body> body_1 = std::make_unique<Body>(200.f, 200.f, 100.f, 100.f, 1.f, std::move(shape_1));

    std::unique_ptr<Shape> shape_2 = std::make_unique<CircleShape>(10.f);
    std::unique_ptr<Body> body_2 = std::make_unique<Body>(600.f, 200.f, -100.f, 100.f, 1.f, std::move(shape_2));

    world.add_body(std::move(body_1));
    world.add_body(std::move(body_2));

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