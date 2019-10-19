#include "Ball.h"
#include "geometry.h"
#include <utility>


//returns a position a pixel above the bottom center


//a constructor for a ball
Ball::Ball(Geometry const& geometry, ge211::Position pos)
        : radius_   (geometry.ball_radius)
        , center_   (pos)
        , velocity_ (geometry.ball_velocity)//remember that we could start at the position where the ball lands after each round
        , live_     (false)

{ }

//using Blocks = std::vector<std::vector<Block>>; //defined in h file
ge211::Position Ball::top_left() const
{
    ge211::Position pos = this->center_;
    pos = pos.left_by(radius_);
    pos = pos.up_by(radius_);
    return pos;
}

bool Ball::hits_bottom(Geometry const& geometry) const
{
    return center_.y + radius_ > geometry.scene_dims.height;
}
//hits top too
bool Ball::hits_top(Geometry const& geometry) const
{
    return center_.y - radius_ < 0;
}

bool Ball::hits_side( Geometry const& geometry) const
{
    return center_.x - radius_ < 0 || center_.x + radius_ >= geometry.scene_dims.width;
}

Ball Ball::next() const
{
    Ball result(*this);
    result.center_.x = result.center_.x + result.velocity_.width;
    result.center_.y = result.center_.y + result.velocity_.height;
    return result;
}



void Ball::reflect_vertical()
{
    velocity_.height *= -1;
}

void Ball::reflect_horizontal()
{
    velocity_.width *= -1;
}
void Ball::reflect_horizontal(int n)
{
    velocity_.width *= -(n * (n+5)) ;
}





bool operator==(Ball const& b1, Ball const& b2)
{
    return (b1.center_ == b2.center_) && (b1.radius_ == b2.radius_) && (b1.velocity_ == b2.velocity_) && (b1.live_ == b2.live_ );
}
bool operator!=(Ball const& b1, Ball const& b2)
{
    return !(b1 == b2);
}