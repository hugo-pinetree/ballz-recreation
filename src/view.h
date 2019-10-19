#pragma once
#include "ge211.h"
#include "model.h"
extern ge211::Font const font;
class view{
public:
    explicit view(Model model);
    void draw(ge211::Sprite_set& sprites) ;
    Model  model_;
    ge211::Text_sprite::Builder builder;

private:
    ///
    /// Private helper functions
    ///

    // The view can look at the model but doesn't change it.

    ge211::Color const ball_color {255, 127, 127};
    ge211::Color const block_color {40, 120, 12};
    ge211::Color const multiplier_color {255,255 , 255};
    ge211::Circle_sprite const
        ball_sprite_ {model_.geometry_.ball_radius, ball_color};
    ge211::Circle_sprite const
            multiplier_sprite_ {model_.geometry_.multiplier_radius, multiplier_color};
    ge211::Rectangle_sprite const

            block_sprite_ {{ model_.geometry_.width, model_.geometry_.height}, block_color};

    ge211::Text_sprite  destroy_nums = ge211::Text_sprite("",font);
    ge211::Font font {"sans.ttf", 20};
    ge211::Image_sprite const
            lightning_sprite {"yellow-lightning-clipart-png--30.png"};
    ge211::Text_sprite  g_o = ge211::Text_sprite("Game Over :(",font);
    ge211::Text_sprite  level_sprite = ge211::Text_sprite("Level 1",font);
    std::vector<ge211::Text_sprite> ss;
    //ge211::Text_sprite::Builder(font);






};