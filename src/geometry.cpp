
#include "geometry.h"

Geometry::Geometry()
        :scene_dims {510, 600}
        ,ball_radius {10}
        ,line_length {20}
        ,multiplier_radius {35}
        ,max_boost {5}
        ,ball_velocity {0,0}
        , num_balls(1)
        , initial_position{scene_dims.width / 2, scene_dims.height - 22}
        , width(70)
        , height(70)
        , lightning_pos(scene_dims.width - 60, 20)
        , lightning_dims{30,190}
        , lightningg_{false}
        , game_over{false}
        , in_play{false}
        , mouse{0,0}


{ }