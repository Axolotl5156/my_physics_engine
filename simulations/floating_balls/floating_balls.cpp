
#include "floating_balls.hpp"

#include "world.hpp"
#include "body.hpp"
#include "circleShape.hpp"
#include "rendererSFML.hpp"

void FloatingBalls::run()
{
    
    World world(800, 600, 0.f, 1.f);

    std::unique_ptr<Shape> shape_1 = std::make_unique<CircleShape>(20.f);
    std::unique_ptr<Body> ball_1 = std::make_unique<Body>(200.f, 150.f, 150.f, 150.f, 1.f, std::move(shape_1));

    std::unique_ptr<Shape> shape_2 = std::make_unique<CircleShape>(20.f);
    std::unique_ptr<Body> ball_2 = std::make_unique<Body>(600.f, 150.f, 150.f, -150.f, 1.f, std::move(shape_2));

    std::unique_ptr<Shape> shape_3 = std::make_unique<CircleShape>(20.f);
    std::unique_ptr<Body> ball_3 = std::make_unique<Body>(400.f, 300.f, -150.f, 150.f, 1.f, std::move(shape_3));

    std::unique_ptr<Shape> shape_4 = std::make_unique<CircleShape>(20.f);
    std::unique_ptr<Body> ball_4 = std::make_unique<Body>(200.f, 450.f, -150.f, -150.f, 1.f, std::move(shape_4));

    std::unique_ptr<Shape> shape_5 = std::make_unique<CircleShape>(20.f);
    std::unique_ptr<Body> ball_5 = std::make_unique<Body>(600.f, 450.f, 150.f, 0.f, 1.f, std::move(shape_5));

    world.add_body(std::move(ball_1));
    world.add_body(std::move(ball_2));
    world.add_body(std::move(ball_3));
    world.add_body(std::move(ball_4));
    world.add_body(std::move(ball_5));

    RendererSFML renderer(world.get_width(), world.get_height(), "floating balls");
    // renderer.enable_recording("video.mp4");

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

    if(renderer.is_recording())
        renderer.finalize_recording();
}