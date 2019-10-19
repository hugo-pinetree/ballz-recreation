#include "view.h"


view::view(Model model)
        : model_(model)
        , builder(font)



{}

void view::draw(ge211::Sprite_set& sprites) {
    int j = 0;
    //for(int i = model_.blocks_.size() - 1; i >= 0; --i ) {
    //    for (Block& block : model_.blocks_[i]) {
    for (std::vector<Block> &bb: model_.blocks_) {
        for (Block &block : bb) {
            if (block.live) {

                //std::string const& s = std::to_string(block.destruction_num);

                //builder.message();
                //destroy_nums.reconfigure(builder);
                //printf("N%d ",block.destruction_num );
                std::string s = std::to_string(block.destruction_num);
                //ss.push_back(ge211::Text_sprite::Builder(font).message(s).build());




                //printf("aaaa %d",block.destruction_num);
                destroy_nums.reconfigure(ge211::Text_sprite::Builder(font) << block.destruction_num);
                sprites.add_sprite(block_sprite_, block.top_left, 0);
                sprites.add_sprite(destroy_nums,
                                   {block.top_left.x + block.width / 2, block.top_left.y + block.height / 2}, 1);
                destroy_nums = ge211::Text_sprite::Builder(font).message(s).build();
                ++j;
            }
        }


        level_sprite.reconfigure(ge211::Text_sprite::Builder(font) << "LEVEL  " << model_.level_ - 1);
        sprites.add_sprite(level_sprite, {model_.geometry_.scene_dims.width / 2 - 60, 20});

        for (Multiplier m : model_.multipliers_)
            sprites.add_sprite(multiplier_sprite_, m.top_left);
        if (!model_.geometry_.in_play)
            sprites.add_sprite(ball_sprite_, model_.geometry_.initial_position);
        for (Ball ball : model_.balls_) {
            if (ball.live_)
                sprites.add_sprite(ball_sprite_, ball.center_);
        }
        sprites.add_sprite(lightning_sprite, model_.geometry_.lightning_pos, 2);
        if (model_.geometry_.game_over) {
            ge211::Position pos{model_.geometry_.scene_dims.width / 2, 500};
            sprites.add_sprite(g_o, pos, 3);
        }
    }
}