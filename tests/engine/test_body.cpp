#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "body.hpp"
#include "circleShape.hpp"
#include <memory>

TEST_CASE("Test Body setters and getters", "[body]")
{

    std::unique_ptr<CircleShape> shape = std::make_unique<CircleShape>(8.f);
    Body body(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, std::move(shape), BodyType::Dynamic);

    REQUIRE(body.get_pos_x() == Catch::Approx(1.f));
    REQUIRE(body.get_pos_y() == Catch::Approx(2.f));
    REQUIRE(body.get_vel_x() == Catch::Approx(3.f));
    REQUIRE(body.get_vel_y() == Catch::Approx(4.f));
    REQUIRE(body.get_fx() == Catch::Approx(5.f));
    REQUIRE(body.get_fy() == Catch::Approx(6.f));
    REQUIRE(body.get_mass() == Catch::Approx(7.f));
    REQUIRE(body.get_shape()->get_half_height() == Catch::Approx(8.f));
    REQUIRE(body.get_shape()->get_half_width() == Catch::Approx(8.f));

    body.set_pos_x(11.f);
    body.set_pos_y(12.f);
    body.set_vel_x(13.f);
    body.set_vel_y(14.f);
    body.set_fx(15.f);
    body.set_fy(16.f);
    body.set_mass(17.f);

    REQUIRE(body.get_pos_x() == Catch::Approx(11.f));
    REQUIRE(body.get_pos_y() == Catch::Approx(12.f));
    REQUIRE(body.get_vel_x() == Catch::Approx(13.f));
    REQUIRE(body.get_vel_y() == Catch::Approx(14.f));
    REQUIRE(body.get_fx() == Catch::Approx(15.f));
    REQUIRE(body.get_fy() == Catch::Approx(16.f));
    REQUIRE(body.get_mass() == Catch::Approx(17.f));

}

TEST_CASE("Body update changes position with velocity", "[body]")
{
    std::unique_ptr<CircleShape> shape = std::make_unique<CircleShape>(10.f);
    Body body(0.f, 0.f, 1.f, std::move(shape), BodyType::Dynamic);

    body.set_vel_x(10.f);

    body.update(1.f); //dt = 1 seconde

    REQUIRE(body.get_pos_x() == Catch::Approx(10.f));
    REQUIRE(body.get_pos_y() == Catch::Approx(0.f));

}

TEST_CASE("Body reacts to applied force", "[body]")
{
    std::unique_ptr<CircleShape> shape = std::make_unique<CircleShape>(10.f);
    Body body(0.f, 0.f, 1.f, std::move(shape), BodyType::Dynamic);

    body.apply_force(10.f, 0.f);
    body.update(1.0f);

    REQUIRE(body.get_vel_x() == Catch::Approx(10.f));
}