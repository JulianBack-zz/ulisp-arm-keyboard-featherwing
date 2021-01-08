#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define VT100_SCREEN_WIDTH ili9340_width()
#define VT100_SCREEN_HEIGHT ili9340_height()
#define VT100_CHAR_WIDTH 6
#define VT100_CHAR_HEIGHT 8
#define VT100_HEIGHT (VT100_SCREEN_HEIGHT / VT100_CHAR_HEIGHT)
#define VT100_WIDTH (VT100_SCREEN_WIDTH / VT100_CHAR_WIDTH)

// Color definitions
#define ILI9341_BLACK 0x0000       ///<   0,   0,   0
#define ILI9341_NAVY 0x000F        ///<   0,   0, 123
#define ILI9341_DARKGREEN 0x03E0   ///<   0, 125,   0
#define ILI9341_DARKCYAN 0x03EF    ///<   0, 125, 123
#define ILI9341_MAROON 0x7800      ///< 123,   0,   0
#define ILI9341_PURPLE 0x780F      ///< 123,   0, 123
#define ILI9341_OLIVE 0x7BE0       ///< 123, 125,   0
#define ILI9341_LIGHTGREY 0xC618   ///< 198, 195, 198
#define ILI9341_DARKGREY 0x7BEF    ///< 123, 125, 123
#define ILI9341_BLUE 0x001F        ///<   0,   0, 255
#define ILI9341_GREEN 0x07E0       ///<   0, 255,   0
#define ILI9341_CYAN 0x07FF        ///<   0, 255, 255
#define ILI9341_RED 0xF800         ///< 255,   0,   0
#define ILI9341_MAGENTA 0xF81F     ///< 255,   0, 255
#define ILI9341_YELLOW 0xFFE0      ///< 255, 255,   0
#define ILI9341_WHITE 0xFFFF       ///< 255, 255, 255
#define ILI9341_ORANGE 0xFD20      ///< 255, 165,   0
#define ILI9341_GREENYELLOW 0xAFE5 ///< 173, 255,  41
#define ILI9341_PINK 0xFC18        ///< 255, 130, 198

class CTTy
{
    public:
        CTTy();

        void begin(Adafruit_ILI9341 *tft);
        void reset(void);
        void write(char c);

    private:
        void calcNextCursorPos(uint16_t &x, uint16_t &y);
        void moveCursor(void);
        void drawCursor(void);
        void clearCursor(void);
        void scrollUp(uint16_t &x, uint16_t &y);
        void processChar(void);

        void moveOneLeft(void);
        void moveOneRight(void) {};

    private:
        Adafruit_ILI9341 *m_tft;
        char m_curChar;
        uint16_t m_textColor;
        uint16_t m_backColor;
        uint16_t m_x;
        uint16_t m_y;
        uint16_t m_maxX;
        uint16_t m_maxY;
        uint16_t m_charWidth;
        uint16_t m_charHeight;
        bool m_cursorDrawn;
        
}; 
