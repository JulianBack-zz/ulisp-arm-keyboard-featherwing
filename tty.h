#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

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
