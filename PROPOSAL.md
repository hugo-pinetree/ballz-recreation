# Proposal: [PROPOSAL TODO: GAME TITLE]

## Synopsis

[PROPOSAL TODO]
### Elements:

My game is called Ballz and consists of the following elements:

1. an array of blocks at the top of the screen, randomly placed, but spaced out evenly, that descend on every turn
 and have the number of hits required to break them printed on them,
2. a white ball that sits at the bottom of the screen, that can be shot at an angle by the user every turn,

3. the ball will bounce in between the blocks
4. The player will advance levels on every descend of the blocks and will add on another ball to its trajectory
 when a ball hits a multiplier circle

### Goal:

The players goal is to destroy all the blocks before any one reaches the bottom of the screen
- which will result in game over-, otherwise, the player can continue leveling up. It is in the best interest of the user 
to try to hit as many multiplier circles to have more balls with which to hit bricks.

### Gameplay:
The blocks start out in a random formation on top of the screen. The user must click on the mouse and and drag it
horizontally to shoot it at the angle he/she wishes, the user can also simultaneously drag the mouse vertically
down to extend the projection. The ball will collide with the blocks, and destroy
after hitting them the number of times that is printed on them. The player wil continue off where the last ball lands on the bottom
and each brick will descend one unit length(This can be thought of as a complete round where the level will be incremented and
displayed on the screen). The user will have an additional ball added to their shot when a ball hits a circle like avatar.
The collection of balls is cumulative.

The game is over when the user does not destroy a block before it reaches the bottom.

## Functional requirements

## Functional requirements

The ball
--1 the ball is placed at the bottom of the screen
--2 the new position of the ball is reset to the position where the first ball lands on the x-axis

Ball Mechanics
  --3 when the ball hits the block it gets a random boost in the x direction
  --4 the ball only gets shot off after the mouse is released by the user AND the current round is not in play
  
  --5 when the ball hits the sides it gets reflected in the x direction
  --6when the ball hits the top of the screen it get reflected in the y direction
  -- 7 when the user clicks on the lightning bolt, the balls speed up to relieve impatient users

--the ball multipliers
           --8 these are randomly generated circles on the screen that get destroyed with one hit, there will be one on each new row
           --9 if the ball hits these it gets an additional ball added to the shot ,
            eg. if it hits one, the next time you shoot it is now two balls
                if 1 ball + 1 multiplier == 2 balls when you shoot
                if 2 balls + 1 multiplier == 3 balls when you shoot


--the blocks
         10  are numbered randomly and this specifies the number of times the ball has to hit the block to destroy it, updated in text sprite so user can see
         11 starts off with one row then keeps adding a new random row after the last ball has completed its travel
         12 blocks moove in smooth motion, not abruptly 


 Block Mechanics
     --13 when the ball hits the block the (destruction number) decreases and when this reaches zero the
           block is considered to be destroyed and disapears
     --14 the blocks keep moving down from the top of the screen down
            -- ** this only happens after the last ball has landed
      --15 when the blocks reach the bottom of the screen the game is over and the score of the player is the number of bricks they destroyed
 

[PROPOSAL TODO]

## Open questions
I am creating a seperate struct for the collection of all the balls accumulated as can be
seen in the Model.h These will be stored in an array; is it better to use a linked list or a vector to access them?
Ball will be its own class, we do have multiple balls that start behaving the same way (start at the same position,
 move in the same initial angle, at the same speed) BUT they will most likely have their trajections altered and will need to be
 readily modified individually.

 How could i generate new blocks? and how would i make the motion smooth?



