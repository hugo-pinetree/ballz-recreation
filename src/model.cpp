#include <ge211.h>
#include <fstream>
#include <stdexcept>
#include <iostream>

#include <cstdlib>

#include "model.h"
#include <vector>
#include <memory>









//this represents the line that will guide the player in determining the angle of hit. By changing the
// angle relative to the horizontal cursor movement, the player can get a better sense of aim

Model::Model ()
            : screen_dimensions_(geometry_.scene_dims)
            //, random_(random)
            , level_(get_level())
            //, blocks_{} //what about the rest of the rows??
            , ball_(geometry_,{0,0})
            , position_{geometry_.initial_position}//not sure this will work

            //, block_(get_row(level))


{}
    //there will be enough space on the top of the screen to just place this new row of blocks
    //return new row of blocks to be played
    //maybe you should multiply level to a rand num to get a num to put on block


std::vector<Block> Model::get_row(int rand_mult, std::vector<int> rand_nums, std::vector<int> add_on){

        std::vector<Block> row;

        ge211::Position pos_m{rand_mult * geometry_.width + 3*rand_mult,0};
        Multiplier m{geometry_, pos_m};
        multipliers_.push_back(m);
        int count = 0;
        for(int i: rand_nums) {

            ge211::Position pos{i * geometry_.width + 3*i, 0};
            int num = add_on[count];
            Block b{geometry_,pos,level_ * num};
            //printf("add %d",add_on[count]);
            b.destruction_num = level_ * add_on[count];
            row.push_back(b);
            ++count;
        }
        return row;


}

    /*
     * the last row of blocks on the screen is stored first in the vector
     */
    int Model::get_level(){
        return 0;
    }
    bool Model::game_over() {

        std::vector<Block> row = blocks_[0];
        for(Block r: row){
            if (r.live)
                return true;
        }
        return false;


    }

    /*
     * clears out the first row after all blocks in the first row
     * have been removed by user
     */

    //******************
bool Model::hits_block(Block const& block, Ball const& ball) const
{
    if (ball.center_.x + ball.radius_ < block.top_left.x  || block.top_left.x + block.width < ball.center_.x - ball.radius_ )
        return false;
    if (ball.center_.y - ball.radius_ > block.top_left.y + block.height || ball.center_.y + ball.radius_ < block.top_left.y)
        return false;

    return true;


}
bool Model::hits_multiplier(Multiplier const& multiplier, Ball const&  ball) const {
    if (ball.center_.x + ball.radius_ < multiplier.top_left.x  || multiplier.top_left.x + multiplier.radi*2 < ball.center_.x - ball.radius_ )
        return false;
    if (ball.center_.y - ball.radius_ > multiplier.top_left.y + multiplier.radi*2 || ball.center_.y + ball.radius_ < multiplier.top_left.y)
        return false;

    return true;
}
bool Model::destroy_block(Blocks & blocks, Ball const& ball) const
{
    for(std::vector<Block>& row: blocks ){
        for(Block& block : row){
            if(hits_block(block, ball)) {
                if (block.destruction_num > 1) {
                    //printf("hit block: new%d ", block.destruction_num);
                    --block.destruction_num;

                    return true;
                }
                else if (block.destruction_num == 1) {
                //std::swap(blocks.back(), );
                //blocks.pop_back();
                --block.destruction_num;
                block.live = false;

                return true;
                }
            }


        }
    }


    return false;
}
bool Model::multiply( Ball& ball){
    for(Multiplier& m: multipliers_){

        if(hits_multiplier(m,ball)){
            std::swap(m, multipliers_.back());
            multipliers_.pop_back();
            //then we add one more ball to the ball vector
            //which will be made live when you launch
            //****** we need to figure out the position *****
            ++geometry_.num_balls;
            return true;
        }


    }

    return false;
}
//check the size!
void Model::update_vector(std::vector<Block> row){
    std::vector<std::vector<Block>> temp;
    if(blocks_.size() == 6) {
        if (game_over()) {

            geometry_.game_over = true;

        }
    }
    if(blocks_.size() == 7) { //we are assuming we have 5 rows

        for (int i = 1; i < blocks_.size(); ++i)
            temp.push_back(blocks_[i]);
        temp.push_back(row);

        std::swap(temp, blocks_);
    }
    else
        blocks_.push_back(row);
    ++level_;
}


   void Model::shift_blocks() {
        //south will increase, north will decrease, west wil increase, east will decrease
        //2 pixels of padding

        for (std::vector<Block>& bb: blocks_) {
            for (Block &b: bb) {
                b.top_left.y += 5;

            }

        }
        for(Multiplier& m: multipliers_){
            m.top_left.y += 5;

        }
        shifted_count_ += 5;
    }
    void Model::launch_ball(){



            if(geometry_.mouse.x ==0 && geometry_.mouse.y == 0)
            {}

            else {


                ratio = sqrt(pow((geometry_.mouse.y -geometry_.initial_position.y),2) +
                             pow((geometry_.mouse.x -geometry_.initial_position.x ),2)) ;

                double first = (geometry_.mouse.x - geometry_.initial_position.x)/ratio;

                double second = (geometry_.mouse.y - geometry_.initial_position.y)/ratio;

                Ball b{geometry_, geometry_.initial_position};
                b.velocity_.width = 10*first;
                b.velocity_.height = 10*second;



                b.live_ = true;

                balls_.push_back(b);
        }

    }
    void Model::launch_balls(ge211::Position angle){

        if(geometry_.in_play) {
            //if game is in play do not launch balls
            pending_ = 0;
        }
        else if (true) {
            pending_ = geometry_.num_balls;
            geometry_.in_play = true;
            //Added another variable clicked position to the model//
           // if (angle.y > geometry_.initial_position.y - 5 && angle.y < geometry_.initial_position.y - 80) {
                geometry_.mouse.x = angle.x;
                geometry_.mouse.y = angle.y;
           // }
        }


    }

bool Model::all_alive() const{
        for(Ball const& b : balls_){
            if(!b.live_)
                return false;
        }
        return true;
    }

    bool Model::all_dead() const{
        for(Ball const& b : balls_){
            if(b.live_)
                return false;
        }

        return true;
    }
bool Model::ball_hits_block(Ball ball){
    for(std::vector<Block>& row: blocks_)
        for(Block block:row)
            if (hits_block(block, ball) && block.live)
                    return true;
            return false;

}
void Model::set_lightning() {
    geometry_.lightningg_ = true;
}
void Model::update(int rand_mult, std::vector<int> rand_nums, std::vector<int> add_on) {

    if (!geometry_.game_over ) {
        if (level_ == 0) {
            ++level_;
            update_vector(get_row(2, {0, 3, 4, 6}, {1, 2, 3, 1}));

            play = true;

        }


        if (pending_ > 0 ) {
            launch_ball();
            --pending_;
        }
        for (Ball &ball: balls_) {
            Ball updated = ball.next();

            if (!ball.live_) {

            } else {

                if(geometry_.lightningg_){
                    //printf("here\n");
                    ball.velocity_.height -= 3;
                    ball.velocity_.width += 3;
                    geometry_.lightningg_ = false;
                }
                if (multiply(updated)) {}
                if (updated.hits_bottom(geometry_)) {

                    if (all_alive()) {
                        geometry_.initial_position.x = updated.center_.x;

                    }
                    ball.live_ = false;


                }

                if (updated.hits_top(geometry_)) {

                    ball.reflect_vertical();

                }
                if (updated.hits_side(geometry_)) {

                    if (!lightning_) {

                        ball.reflect_horizontal();
                    } else {

                        ball.reflect_horizontal(rand_mult);
                    }

                }


                if (destroy_block(blocks_, updated)) {
                    if (!lightning_) {
                        ball.reflect_vertical();
                        ball.reflect_horizontal();
                    } else {
                        ball.reflect_vertical();
                        ball.reflect_horizontal(rand_mult);
                    }

                } else if (ball_hits_block(updated)) {
                    //ball.reflect_vertical();
                    ball.reflect_horizontal();

                }

                ball = ball.next();

            }
        }


        if (all_dead()) {

            if (!balls_.empty()) {
                update_vector(get_row(rand_mult, rand_nums, add_on));
                play = true;
                balls_.clear();
                shifted_count_ = 0;
                //geometry_.lightningg_ = false;
            }

            if (shifted_count_ < geometry_.height + 1 ) {
                shift_blocks();

            } else
                geometry_.in_play = false;


        }
    }
}






