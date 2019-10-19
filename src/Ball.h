#pragma once

#include "geometry.h"

#include <vector>

//using Blocks = std::vector<std::vector<Block>>;
struct Ball {
public:
    //this is a ball constructor
    explicit Ball(Geometry const& geometry, ge211::Position pos);

    //checks if the ball has hit the top
    ge211::Position top_left() const;

    //checks if the ball has hit the bottom

    bool hits_bottom(Geometry const& geometry) const;

    //checks if the ball has hit any of the sides

    bool hits_side(Geometry const& geometry) const;

    //ball hits the top of the screen
    bool hits_top (Geometry const& geometry) const;
    //checks the next status of the ball by considering its velocity and
    //current position

    Ball next() const;

    //checks if the ball hits a block

    //bool hits_block(Block const& block) const;

    //checks if the ball hits a multiplier

    //bool hits_multiplier(Multiplier const& multiplier) const;

    //reflects the y part of the balls velocity

    void reflect_vertical();

    //reflects the ball horizontally

    void reflect_horizontal();

    void reflect_horizontal(int n);

    //destroys the brick thats been hit if its count is 1//decrement the count

    //bool destroy_brick(Blocks& blocks) const;

    //determines if the ball has hit any multiplier and then adds more balls into the balls vector

    //bool Multiply(std::vector<Multiplier>& Multipliers) const;


    //Model model_;


    //Member variables
    int radius_;

    using Dimensions = ge211::Basic_dimensions<double>;
    //the velocity of the ball
    Dimensions velocity_;

    //the center of the ball
    ge211::Position center_;

    //the status of the ball
    bool live_;


};