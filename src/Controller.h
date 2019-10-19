//#pragma once
#include "model.h"
#include <ge211.h>
#include <string>
#include <vector>
#include "view.h"

// Code for handling user input and managing the overall flow
// of the game. Owns the model and view.
class Controller :  public ge211::Abstract_game
{
public:

    ///
    /// Constructors
    ///
    // For passing in small word lists by hand.
    Controller ();
    ge211::Position angle_;
    ge211::Position start_;
    bool hover_ = false;
    double time = 0;

    ///
    /// Member functions
    ///
    // Called by ge211 when it needs to redraw the screen. Delegates to
    // the view.
    void draw(ge211::Sprite_set& sprites) override;

    ge211::Dimensions initial_window_dimensions() const override;
    // Called by ge211 when the game engine is ready. We use this to tell
    // the model to react to time passing.
    void on_frame(double dt) override;

    //void on_key_up(ge211::Position p);
    void on_mouse_move(ge211::Position p) override;

    void on_mouse_down(ge211::Mouse_button, ge211::Position p) override;

    // Called by ge211 when the user press the mouse. We forward the mouse_up
    // to the model.
    void on_mouse_up(ge211::Mouse_button, ge211::Position position) override;

private:

    ///
    /// Member variables
    ///
    Model model_;
    view view_;



};