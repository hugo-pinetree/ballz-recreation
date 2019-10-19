#pragma once
#include <ge211.h>


struct Geometry{

    Geometry()  ;

    ge211::Dimensions  scene_dims;

        using Dim = ge211::Basic_dimensions<double> ;
    Dim ball_velocity;
    ge211::Position initial_position;

    ge211::Position lightning_pos;
    ge211::Dimensions lightning_dims;





    int ball_radius;

    int line_length;

    int multiplier_radius;

    int max_boost;

    int width;

    int height;

    int num_balls;
    bool game_over;

    bool lightningg_;
    bool in_play;
    ge211::Position mouse;
};