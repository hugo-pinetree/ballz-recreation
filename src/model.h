#include <ge211.h>
//#include "geometry.h"
#include "Ball.h"
#include <vector>


//this is the position of one block
#pragma once
struct Multiplier
{

    Multiplier()
            :top_left (0,0)
            ,live(false)
            ,radi(0)
    {}


    Multiplier(Geometry const& geometry,ge211::Position top_left1)
            :top_left(top_left1)
            ,radi (geometry.multiplier_radius)
            ,live(true)
    {}


    ge211::Position top_left;
    int radi;
    //this shows whether the multiplier has  been hit by the ball or not
    bool live;


};
#pragma once
struct Block
{


    Block()
            :top_left(0,0)
            ,width(0)
            ,height(0)
            ,destruction_num (0)
            ,live(false)

    {}

    Block(Geometry const& geometry, ge211::Position top_left1, int rand)
            :top_left(top_left1)
            , width (geometry.width)
            ,height (geometry.height)
            , destruction_num(rand)
            , live(true)
    {}

    //the top left position of the block
    ge211::Position  top_left;
    int width;
    int height;
    // specifies the number of times you have to hit the block to destroy
    int destruction_num ;

    //whether block has been destroyed
    bool live;


};
#pragma once
struct Pointing_line{

};
using Blocks = std::vector<std::vector<Block>>;
#pragma once
class Model {
public:



    Geometry geometry_;
    //this is the position of one block

//using Block = block;


    //Model(Geometry const& geometry, Ball& ball , ge211::Position pos);
    Model();





//this will be the bonus block that will give the user an additional ball on the next round







    //helper function that gets called when the ball hits the multiplier
    //shifts the position of all bricks down by the width + spacing
    //blocks should be shifting smoothly w/ the same velocity
    void shift_blocks();
    bool done_shifting = 0;
    int shifted_count_ = 0;
    int get_level();
    bool lightning_ = false;
    //generates random blocks above existing ones right before we shift them all down one level.
    void generate_blocks();

    //generates a random destruct num based off the level we are on
    int destruction_num(int level);

    //all numbers returned should be inside the range of dimensions [0 window_width]

    int rand_x();
    //all numbers returned should be inside the range of dimensions [0 window_height]
    int rand_y() ;

    //when the ball hits the bottom the state of the ball must be dead

    //sets the starting position of the ball to the last position where the last ball hit the bottom
    void set_pos(ge211::Position p);

    std::vector<Block> get_row(int rand_mult, std::vector<int> rand_nums, std::vector<int> add_on);
    // Returns the states of all the blocks in play that way we know when to start a new round (after all balls
    // in play are dead)

    //ge211::Position starting; *********** uncomment later

    void update_vector(std::vector<Block> row);

    //
    //some public members
    //

    bool hits_block(Block const& block, Ball const& ball) const;
    bool hits_multiplier(Multiplier const& multiplier, Ball const& ball) const;
    bool destroy_block(Blocks& blocks, Ball const& ball) const;
    bool multiply( Ball& ball);

    //bool game_over() const;

    //add a ball to the vector
    void add_ball() const;

    //empty the vector for testing purposes
    void empty_balls();

    // The geometry parameters of the model.  geometry.h will have a
    // description of what this determines. Models can be constructed
    // with different geometries, but the geometry never changes on an
    // existing model. This will mainly store some dimensions of the layout of the window and nothing specific to the objects
    //hence we felt it wasnt too important to show this declaration



    //returns the state of all the balls in play that way we know when to start a new round (after all balls
    // in play are dead)


    // Updates the model state for ball, bb, block, blocks, mm one time step.
    // Updates the state of the game for one frame (usually 1/60 s).
    //void update(int x);

    //returns true when a block hits the bottom
    bool game_over();

    // changes the angle proportionally to the given x (most likely will be the x val given from Controller).
    void move_angle(int x);

    //changes the length of the line, proportionally to the given y (most likely the y value given from Controller)
    void move_line(int y);

    //void launch_balls(ge211::Position angle);
    // Launches the ball if it's dead. void launch_ball ();
    void launch_ball();
    bool play = true;
    void update(int rand_mult, std::vector<int> rand_nums, std::vector<int> add_on);
    void launch_balls(ge211::Position angle);
    bool all_alive() const;
    bool all_dead() const;
    void set_lightning();
    bool ball_hits_block(Ball ball);
    //bool game_over_ = false;

    //ge211::Random&  random_;
    ge211::Dimensions screen_dimensions_;
    std::vector<Multiplier> multipliers_;
    Blocks blocks_;

    Block block_;
    Multiplier multiplier_;
    Pointing_line line_;
    Ball ball_;
    double ratio;
    int level_;
    int count_balls;
    std::vector<Ball> balls_;
    ge211::Position position_;

    int pending_ = 0;





};

