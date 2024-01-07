#ifndef PROJECT_XX_CONSTANTS_H
#define PROJECT_XX_CONSTANTS_H
namespace CONSTANTS{
    namespace CONSOLE{
        enum DIRECTIONS{
            UP = 72,
            LEFT = 75,
            RIGHT = 77,
            DOWN = 80,
            LEFT_TO_RIGHT = -1,
            RIGHT_TO_LEFT = 1,
            RIGHT_AND_LEFT = 0,
        };
    }    
    namespace TEXTURES{
        namespace BOX{
            struct SINGLE_LINE{
                const char URC = 191; // ┐ line upper right corner
                const char LLC = 192; // └ line lower left corner
                const char LHU = 193; // ┴ line horizontal and up
                const char LHD = 194; // ┬ line horizontal down
                const char LVR = 195; // ├ line vertical and right
                const char HL_ = 196; // ─ horizontal line
                const char HV_ = 197; // ┼ line horizontal vertical
                const char LRC = 217; // ┘ line lower right corner
                const char ULC = 218; // ┌ line upper left corner
                const char VL_ = 179; // │ vertical line
                const char VLL = 180; // ┤ vertical and left line
            };
            struct DOUBLE_LINE{
                const char VLL = 185; // ╣ line vertical and left
                const char VL_ = 186; // ║ vertical line
                const char URC = 187; // ╗ line upper right corner
                const char LRC = 188; // ╝ line lower right corner
                const char LLC = 200; // ╚ line lower left corner
                const char ULC = 201; // ╔ line upper left corner
                const char H_U = 202; // ╩ line horizontal and up
                const char HLD = 203; // ╦ line horizontal down
                const char V_R = 204; // ╠ line vertical and right
                const char HL_ = 205; // ═ horizontal line
                const char HV_ = 206; // ╬ line horizontal vertical
            };
        }
        namespace SHADING{
            struct SHAPE{
                static const char LDD = 176; // ░ Graphic character, low density dotted
                static const char MDD = 177; // ▒ Graphic character, medium density dotted
                static const char HDD = 178; // ▓ Graphic character, high density dotted
                static const char BGC = 219; // █ Block, graphic character
                static const char BHB = 220; // ▄ Bottom half block
                static const char THB = 223; // ▀ Top half block
                static const char CBS = 254; // ■ black square
            };
        }
    }
}
#endif