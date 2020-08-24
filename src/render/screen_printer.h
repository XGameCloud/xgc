/// 2020/08/24 zhangzhong
/// screen printer

#include <string>
#include <array>

struct Pixel
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;

    std::string ConvertToString() const 
    {
        std::string context;
        context.push_back(static_cast<char>(red));
        context.push_back(static_cast<char>(green));
        context.push_back(static_cast<char>(blue));
        context.push_back(static_cast<char>(alpha));
        return context;
    }
};

class ScreenPrinter
{
public:

    static constexpr size_t SCREEN_WIDTH = 16 * 120;
    static constexpr size_t SCREEN_HEIGHT = 9 * 120;
    using Screen = std::array<Pixel, SCREEN_WIDTH * SCREEN_HEIGHT>;

public:

    std::string ConvertScreenToBuffer(const Screen& screen)
    {
        std::string context;
        for (const auto& pixel : screen)
        {
            context += pixel.ConvertToString();
        }
        return context;
    }

    Screen ConvertBufferToScreen(const std::string& buffer)
    {
        Screen screen;
        for (size_t screen_index = 0, buffer_index = 0; 
            screen_index < screen.size() && buffer_index < buffer.size(); 
            ++screen_index, buffer_index += 4)
        {
            screen[screen_index].red = static_cast<uint8_t>(buffer[buffer_index]);
            screen[screen_index].green = static_cast<uint8_t>(buffer[buffer_index + 1]);
            screen[screen_index].blue = static_cast<uint8_t>(buffer[buffer_index + 2]);
            screen[screen_index].alpha = static_cast<uint8_t>(buffer[buffer_index + 3]);
        }
        return screen;
    }

    /// use Windows API 
    Screen GetScreen();

    std::string GetBuffer()
    {
        return ConvertScreenToBuffer(GetScreen());
    }

};