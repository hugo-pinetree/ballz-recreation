
#include "model.h"
#include "Controller.h"
#include <string>
#include <vector>
#include "geometry.h"


// Code for handling user input and managing the overall flow
// of the game. Owns the model and view.




///
/// Constructors
///
// For passing in small word lists by hand.
Controller::Controller ()
        :
          model_()
        , view_(model_)
        , start_{0,0}
        , angle_{0,1}
//pass in a default of 90 degs
{}



///
/// Member functions
///
// Called by ge211 when it needs to redraw the screen. Delegates to
// the view.
void Controller::draw(ge211::Sprite_set& sprites) {
    view_.draw(sprites);
}
ge211::Dimensions Controller::initial_window_dimensions() const
{
    return view_.model_.geometry_.scene_dims;
}

// Called by ge211 when the game engine is ready. We use this to tell
// the model to react to time passing.
void Controller::on_frame(double dt) {
   time += dt;
    int rand_mult = get_random().between(0, 6);
    std::vector<int> rand_nums;
    std::vector<int> add_on;

    //printf("multiplier%d\n",rand_mult);

    //the number blocks to be displayed


    for (int i = 0; i <= 6; ++i) {
        int block_odds = get_random().between(0, 5);
        int empty_odds = get_random().between(0, 4);
        int empty_odds2 = get_random().between(0, 4);

        if (rand_mult != i && empty_odds != block_odds && empty_odds2 != block_odds) {
            rand_nums.push_back(i);
            //printf("ONE RAND POS %d\n",i);
            add_on.push_back(get_random().between(1, 4));
        }
    }
   // if(time == 3*dt) {
   //     view_.model_.update(rand_mult, rand_nums, add_on);
   //     time = 0;
  //  }

    //if(time == 3*dt) {
        view_.model_.update(rand_mult, rand_nums, add_on);
       // time = 0;

    //}


}


void Controller::on_mouse_down(ge211::Mouse_button, ge211::Position p) {


    //if(model_.play)

    //if(p.x < model_.geometry_.lightning_pos.x + 15 && p.y > model_.geometry_.lightning_pos.y +15 && p.y < model_.geometry_.lightning_pos.y + 15 && p.x > model_.geometry_.lightning_pos.x -15)
    if(p.x < model_.geometry_.lightning_pos.x + model_.geometry_.lightning_dims.width && p.x > model_.geometry_.lightning_pos.x && p.y > 20 && p.y < model_.geometry_.lightning_pos.y +model_.geometry_.height ){
        model_.geometry_.lightningg_ = true;

    }



}

void Controller::on_mouse_up(ge211::Mouse_button, ge211::Position p){

        view_.model_.launch_balls(p);



    }
   // }


    //hover_ = true;
    //the multiplier position


//the user must hover below the click and within 1oopx of click's x pos
void Controller::on_mouse_move(ge211::Position p){

}

// Called by ge211 when the user press the mouse. We forward the mouse_up
// to the model.




///
/// Member variables
///

