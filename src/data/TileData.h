#ifndef SDL_PLATFORMER_SPRITESHEETDATA_H
#define SDL_PLATFORMER_SPRITESHEETDATA_H

enum class TileID {
    Blank = 0,
    Crate = 9,
    GroundLeft = 84,
    GroundCenter = 85,
    GroundRight = 86,
    PlayerIdle = 240,
};

const int SPRITESHEET_TILE_SIZE = 16;
const int SPRITESHEET_COLUMNS = 20;
const int SPRITESHEET_ROWS = 20;

#endif //SDL_PLATFORMER_SPRITESHEETDATA_H
