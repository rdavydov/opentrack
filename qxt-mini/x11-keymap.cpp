#include "x11-keymap.hpp"

#ifndef __APPLE__

#include <tuple>

#define XK_MISCELLANY
#define XK_LATIN1
#include <X11/keysymdef.h>

using tt = std::tuple<Qt::Key, unsigned>;

static tt keymap[] =
{
    { Qt::Key_Return, XK_Return },
    { Qt::Key_Enter, XK_Return },
    { Qt::Key_Delete, XK_Delete },
    { Qt::Key_Pause, XK_Pause },
    { Qt::Key_SysReq, XK_Sys_Req },
    { Qt::Key_Home, XK_Home },
    { Qt::Key_End, XK_End },
    { Qt::Key_Left, XK_Left },
    { Qt::Key_Up, XK_Up },
    { Qt::Key_Right, XK_Right },
    { Qt::Key_Down, XK_Down },
    { Qt::Key_PageUp, XK_Prior },
    { Qt::Key_PageDown, XK_Next },

    { Qt::Key_F1, XK_F1 },
    { Qt::Key_F2, XK_F2 },
    { Qt::Key_F3, XK_F3 },
    { Qt::Key_F4, XK_F4 },
    { Qt::Key_F5, XK_F5 },
    { Qt::Key_F6, XK_F6 },
    { Qt::Key_F7, XK_F7 },
    { Qt::Key_F8, XK_F8 },
    { Qt::Key_F9, XK_F9 },
    { Qt::Key_F10, XK_F10 },
    { Qt::Key_F11, XK_F11 },
    { Qt::Key_F12, XK_F12 },

    { Qt::Key_Space, XK_space },
    { Qt::Key_Exclam, XK_exclam },
    { Qt::Key_QuoteDbl, XK_quotedbl },
    { Qt::Key_NumberSign, XK_numbersign },
    { Qt::Key_Dollar, XK_dollar },
    { Qt::Key_Percent, XK_percent },
    { Qt::Key_Ampersand, XK_ampersand },
    { Qt::Key_Apostrophe, XK_apostrophe },
    { Qt::Key_ParenLeft, XK_parenleft },
    { Qt::Key_ParenRight, XK_parenright },
    { Qt::Key_Asterisk, XK_asterisk },
    { Qt::Key_Plus, XK_plus },
    { Qt::Key_Comma, XK_comma },
    { Qt::Key_Minus, XK_minus },
    { Qt::Key_Period, XK_period },
    { Qt::Key_Slash, XK_slash },

    { Qt::Key_0, XK_0 },
    { Qt::Key_1, XK_1},
    { Qt::Key_2, XK_2 },
    { Qt::Key_3, XK_3 },
    { Qt::Key_4, XK_4 },
    { Qt::Key_5, XK_5 },
    { Qt::Key_6, XK_6 },
    { Qt::Key_7, XK_7 },
    { Qt::Key_8, XK_8 },
    { Qt::Key_9, XK_9 },

    { Qt::Key_Colon, XK_colon },
    { Qt::Key_Semicolon, XK_semicolon },
    { Qt::Key_Less, XK_less },
    { Qt::Key_Equal, XK_equal },
    { Qt::Key_Greater, XK_greater },
    { Qt::Key_Question, XK_question },
    { Qt::Key_At, XK_at },

    { Qt::Key_A, XK_a },
    { Qt::Key_B, XK_b },
    { Qt::Key_C, XK_c },
    { Qt::Key_D, XK_d },
    { Qt::Key_E, XK_e },
    { Qt::Key_F, XK_f },
    { Qt::Key_G, XK_g },
    { Qt::Key_H, XK_h },
    { Qt::Key_I, XK_i },
    { Qt::Key_J, XK_j },
    { Qt::Key_K, XK_k },
    { Qt::Key_L, XK_l },
    { Qt::Key_M, XK_m },
    { Qt::Key_N, XK_n },
    { Qt::Key_O, XK_o },
    { Qt::Key_P, XK_p },
    { Qt::Key_Q, XK_q },
    { Qt::Key_R, XK_r },
    { Qt::Key_S, XK_s },
    { Qt::Key_T, XK_t },
    { Qt::Key_U, XK_u },
    { Qt::Key_V, XK_v },
    { Qt::Key_W, XK_w },
    { Qt::Key_X, XK_x },
    { Qt::Key_Y, XK_y },
    { Qt::Key_Z, XK_z },

    { Qt::Key_BracketLeft, XK_bracketleft },
    { Qt::Key_Backslash, XK_backslash },
    { Qt::Key_BracketRight, XK_bracketright },
    { Qt::Key_AsciiCircum, XK_asciicircum },
    { Qt::Key_Underscore, XK_underscore },
    { Qt::Key_QuoteLeft, XK_grave },
};

unsigned qt_key_to_x11(Display* disp, Qt::Key k)
{
    Qt::Key k_;
    unsigned keysym;

    for (const tt& tuple : keymap)
    {
        std::tie(k_, keysym) = tuple;

        if (k == k_)
        {
            const unsigned ret = XKeysymToKeycode(disp, keysym);

            if (ret == 0)
                return unsigned(-1);

            return ret;
        }
    }

    qDebug() << "qxt-mini: no keysym for" << k;
    return unsigned(-1);
}
#endif
