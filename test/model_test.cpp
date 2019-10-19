
//
// These tests should demonstrate at least six of the functional
// requirements.
//
#include "model.h"
#include <catch.h>
#include<ge211.h>
#include "ball.h"
#include <vector>


TEST_CASE("example test")
{
    //CHECK( 1 + 1 == 2 );
}
TEST_CASE("get_row"){
    Model model_;

    int rand_mult = 4;
    std::vector<int> rand_nums {1,3,5};
    std::vector<int> add_on {1,2,3};
    ge211::Position pos1{1 * model_.screen_dimensions_.width/5, 1 * model_.screen_dimensions_.height/5};
    ge211::Position pos2{3 * model_.screen_dimensions_.width/5, 3 * model_.screen_dimensions_.height/5};
    ge211::Position pos3{5 * model_.screen_dimensions_.width/5, 5 * model_.screen_dimensions_.height/5};

    Block b1{model_.geometry_, pos1, model_.level_ * add_on[0]};
    Block b2{model_.geometry_, pos1, model_.level_ * add_on[1]};
    Block b3{model_.geometry_, pos1, model_.level_ * add_on[2]};

    std::vector<Block> bb;
    bb.push_back(b1);
    bb.push_back(b2);
    bb.push_back(b3);

    std::vector<Block> test = model_.get_row(rand_mult,rand_nums,add_on);

    CHECK(test[0].top_left.x == bb[0].top_left.x);
    CHECK(test[1].destruction_num == bb[1].destruction_num);




}
TEST_CASE("UPDATE VECTOR"){
    Model model_;

    int rand_mult = 4;
    std::vector<int> rand_nums {1,3,5};
    std::vector<int> add_on {1,2,3};

    std::vector<Block> test = model_.get_row(rand_mult,rand_nums,add_on);
    model_.update_vector(test);
    CHECK(model_.blocks_.size() == 1);
    std::vector<Block> test2 = model_.get_row(rand_mult,rand_nums,add_on);
    std::vector<Block> test3 = model_.get_row(rand_mult,rand_nums,add_on);
    std::vector<Block> test4 = model_.get_row(rand_mult,rand_nums,add_on);
    std::vector<Block> test5 = model_.get_row(rand_mult,rand_nums,add_on);


    model_.update_vector(test2);
    CHECK(model_.blocks_.size() == 2);
    CHECK(model_.multipliers_.size() == 5);

    model_.update_vector(test3);
    CHECK(model_.blocks_.size() == 3);

    model_.update_vector(test4);
    CHECK(model_.blocks_.size() == 4);

    model_.update_vector(test5);
    CHECK(model_.blocks_.back()[0].top_left.x == test5[0].top_left.x);

    CHECK(model_.blocks_[0][2].top_left.x == test2[2].top_left.x);



}

TEST_CASE("MULTIPLY"){
    Model m_;

    Multiplier m1 {m_.geometry_,{0,0}};


    m_.multipliers_.push_back(m1);
    CHECK(m_.multipliers_.size() == 1);

    Ball ball(m_.geometry_, {0,0});
    CHECK(m_.multiply(ball));
    CHECK(m_.balls_.size() == 1);

}

TEST_CASE("launchball"){

    Model m_;

    Ball ball(m_.geometry_, {0,0});

    //initialize a mouse position
    //m_.geometry_.mouse =
    m_.launch_balls({0,0});

    m_.launch_ball();

    CHECK(!ball.live_);

    CHECK(m_.ball_.velocity_.width == 0);
    CHECK(m_.ball_.velocity_.height == -1);

    m_.launch_balls({496,500});

    printf("%d \n %d \n : now", m_.geometry_.mouse.x, m_.geometry_.mouse.y);

    m_.launch_ball();

    CHECK(ball.live_);
    // CHECK(m_.ball_.velocity_.width ==  )
    //  CHECK(m_.ball_.velocity_.height == )

}

TEST_CASE("Shift blocks"){

    Model m_;

    std::vector<Block>bb;
    std::vector<std::vector<Block>>bz;
    // m_.blocks_ = bb;
    Block b {m_.geometry_,{5,6},2};
    bb.push_back(b);
    Block c ={m_.geometry_,{10,6}, 1};
    bb.push_back(c);
    Block d = {m_.geometry_,{20,6}, 3};
    bb.push_back(d);

    bz.push_back(bb);

    m_.blocks_= bz;

    m_.shift_blocks();

    CHECK(m_.blocks_[0][0].top_left.y == b.top_left.y + b.height +2);
    CHECK(m_.blocks_[0][1].top_left.y == c.top_left.y + b.height+ 2 );


}

TEST_CASE("destroyblock"){
    Model m_;

    std::vector<Block>bb;
    std::vector<std::vector<Block>>bz;
    // m_.blocks_ = bb;
    Block b {m_.geometry_,{5,6},2};
    bb.push_back(b);
    Block c ={m_.geometry_,{10,6}, 1};
    bb.push_back(c);
    Block d = {m_.geometry_,{20,6}, 3};
    bb.push_back(d);

    bz.push_back(bb);


    Ball ball{m_.geometry_, {5,6}};
    ball.live_ = true;

    m_.destroy_block(bz,ball);

    CHECK(bz[0][0].destruction_num == 1);

    Ball ba{m_.geometry_,{10,6} };

    m_.destroy_block(m_.blocks_,ba);

    CHECK(bz[0][1].live);



}

TEST_CASE("Game over"){
    Model m_;

    std::vector<Block>bb;
    std::vector<std::vector<Block>>bz;
    // m_.blocks_ = bb;
    Block b {m_.geometry_,{5,6},2};
    bb.push_back(b);
    Block c ={m_.geometry_,{10,6}, 1};
    bb.push_back(c);
    Block d = {m_.geometry_,{20,6}, 3};
    bb.push_back(d);

    bz.push_back(bb);
}


//
// TODO: Write preliminary model tests.
//check that if you hit the sides it gets reflected


//check that if you hit a multipier you have 1 more ball --

//check that if you hit a brick whose destruction number is more than 1 it does not get destroyed --

//check that if you hit a brick whose destruction number is 1 it gets destroyed --

// check that if you hit a brick you get a random boost in the x direction

//check that if the ball hits the bottom it is dead
/*
TEST_CASE("Hitting the multiplier")
{
    //here we initialize the geometry and which includes the the dimensions of the screen
    Geometry geometry;


    //it also inititializes the ball and puts it in the Ball_ vector
    //at position 1
    Model mod(geometry);

    //we clear the vector of the multiplier which is m
    mod.multipliers_.clear();
    //put multipliers on different positions in a the vector of multipliers


    //here we are putting one multiplier in the vector of multipliers

    //we call the constructor of the multiplier with the geometry and the position
    //it creates a single multiplier
    Multiplier m =  Multiplier({200, 300}, geometry);


    //we put it in the vector of multipliers
    mod.mm.pushback(m);



    mod.bb[0].center =({300,300});
    mod.bb[0].velocity = {-50,0};

    //this updates the state of the game
    mod.update(0);

    //checking that if there is no collision the size of the multiplier vector remains the same AND also the size of the
    //ball vector

    CHECK(mod.mm.size() == 1);
    CHECK(mod.bb.size() == 1);



    mod.update(0);

    //checking that if there are collisions the size of the multiplier vector goes down by the number of collisions

    CHECK(mod.mm.size() == 0);
    //Checking that the size of tha ball vector increases by the number of the balls tha the ball collided with
    CHECK(mod.bb.size() == 2);


};

TEST_CASE("Hitting a Blocks")
{

    // here we test that if you hit a block with destruction number 1 it gets destroyed and when you hit one with a destruction number greater than that it does
    //not get destroyed but the destruction number of the brick that has been hit increases

//here we initialize the geometry and which includes the the dimensions of the screen
    Geometry geometry;

    //it also inititializes the ball and puts it in the Ball_ vector
    //at position 1
    Model mod(geometry);

    //we firstly clear out the vector of blocks

    mod.Blocks.clear();

    //we create a block with a random distruction number

    Block b= Block({200,300},5);

    //put it in the blocks vector

    mod.Blocks.pushback(b);

//change the values of some of the values of the ball
    mod.bb[0].center =({100,200});
    mod.bb[0].velocity = ({50,50};

    //this updates the state of the game
    mod.update(0);

    //checking that if there is no collision the size of the blocks vector remains the same and also the destruction value
    // check that the destruction number of the has decreased by 1

    CHECK(mod.Blocks.size()== 1);

    CHECK(mod.Blocks[0].dest_val ==5)

    //check that the ball vector also remains the same
    CHECK(mod.bb.size() == 1));

    mod.update(0);

    //checking that if there are collisions the size of the ball vector remains the same but the destruction value of the vector decreases by 1

    CHECK(mod.Blocks.size()== 1);
    CHECK(mod.Blocks[0].dest_val ==4)


    //Checking that the size of tha ball vector remains the same
    CHECK(mod.bb.size() == 1);

    mod.Blocks.clear();

    //we create a block with a random distruction number (in this case this is one and we can test that if the ball hits a brick with a destruction number of 1
    //it gets destroyed

    Block b= Block({200,300},1);

    //put it in the blocks vector

    mod.Blocks.pushback(b);

//change the values of some of the values of the ball
    mod.bb[0].center =({100,200});
    mod.bb[0].velocity = ({50,50};


    mod.update(0);


    //check that the ball vector now has a size of zero
    CHECK(mod.Blocks.size()== 0);

    //check that the ball vector also remains the same
    CHECK(mod.bb.size() == 1);


    //we also check that the ball has gotten a random boost in the x bty comparing its now x to the initial test

    CHECK(mod.bb[0].velocity.width)





}

TEST_CASE("reflection if ball hit sides/TOP") {
    //here we initialize the geometry and which includes the the dimensions of the screen
    // Geometry geometry;

    //it also inititializes the ball and puts it in the Ball_ vector
    // Model mod(geometry);

//change the values of some of the values of the ball //first at the top
    mod.bb[0].center =({100,0});
    mod.bb[0].velocity = ({50,50};

    mod.update(0);

    //check that it has been reflected vertically

    CHECK(mob.bb[0].velocity.y == -50);

    mod.bb[0].center =({100,geometry.dimensions.screen_dims.width});
    mod.bb[0].velocity = ({50,50};

    mod.update(0);

    //check that it is reflected horizontaly
    CHECK(mob.bb[0].velocity.x == -50);










}

TEST_CASE("Hitting the bottom")
{

    //here we initialize the geometry and which includes the the dimensions of the screen
    Geometry geometry;

    //it also inititializes the ball and puts it in the Ball_ vector
    Model mod(geometry);

    //change the values of some of the values of the ball and put it at the bottom of the screen
    mod.bb[0].center =({100,geometry.dimensions.screen_dims.height});
    mod.bb[0].velocity = ({50,50};

    //call update; and check if this ball is dead

    mod.update(0);

    CHECK(mod.bb[0].live == false);
    CHECK(mod.bb[0].velocity == {0,0})



}
 */