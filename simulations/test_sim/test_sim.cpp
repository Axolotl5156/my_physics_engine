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
    world.set_gravity(0.f);

    
    // std::unique_ptr<Shape> shape_a = std::make_unique<CircleShape>(10.f);
    // std::unique_ptr<Body> body_a = std::make_unique<Body>(400.f, 100.f, 0.f, 0.f, 1.f, std::move(shape_a), BodyType::Static);
    
    // std::unique_ptr<Shape> shape_b = std::make_unique<CircleShape>(10.f);
    // std::unique_ptr<Body> body_b = std::make_unique<Body>(600.f, 300.f, 150.f, 0.f, 1.f, std::move(shape_b), BodyType::Dynamic);
    
    // world.add_body(std::move(body_a));
    // world.add_body(std::move(body_b));

    // Body *ba = world.get_bodies()[0].get();
    // Body *bb = world.get_bodies()[1].get();

    // world.add_distance_constraint(ba, bb);

    Body *body_a = world.add_circle(400.f, 200.f, 0.f, 0.f, 1.f, 10.f, BodyType::Dynamic);
    Body *body_b = world.add_circle(400.f, 400.f, 150.f, 0.f, 1.f, 10.f, BodyType::Dynamic);

    world.add_distance_constraint(body_a, body_b);

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