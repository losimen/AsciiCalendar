//
//  colormod.hpp
//  AsciiCalendar
//
//  Created by losirise on 06.06.2021.
//

#ifndef colormod_hpp
#define colormod_hpp

#include <ostream>
namespace Color {
    enum Code {
        //front
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        // back
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_YELLOW   = 43,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}
#endif /* colormod_hpp */
