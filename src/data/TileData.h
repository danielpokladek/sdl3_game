#ifndef SDL_PLATFORMER_SPRITESHEETDATA_H
#define SDL_PLATFORMER_SPRITESHEETDATA_H

enum class TileID {
    Blank = 0,
    Crate = 9,
    PlayerIdle = 240,
    GroundSecondaryLeft = 270,
    GroundSecondaryCenter = 271,
    GroundSecondaryRight = 272,
};

const int SPRITESHEET_TILE_SIZE = 16;
const int SPRITESHEET_COLUMNS = 20;
const int SPRITESHEET_ROWS = 20;

#endif //SDL_PLATFORMER_SPRITESHEETDATA_H
