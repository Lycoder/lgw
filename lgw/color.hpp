/**
 *  \file color.hpp
 *  \brief Defines pixel format conversion primitives, implements a list of colors
 *         depending on the pixel format chosen, and color encoding functions
 */

#pragma once

#include <cstdint>

namespace lgw {
    namespace detail {
#ifdef LGW_FORMAT_ARGB8888
        static const size_t
            conv_alpha_shift = 24,
            conv_red_shift   = 16,
            conv_green_shift = 8,
            conv_blue_shift  = 0;
#endif

#ifdef LGW_FORMAT_RGBA8888
        static const size_t
            conv_red_shift   = 24,
            conv_green_shift = 16,
            conv_blue_shift  = 8
            conv_alpha_shift = 0;
#endif
    }
	
    namespace color {
#ifdef LGW_FORMAT_ARGB8888
		static const constexpr uint32_t
			transparent = 0x00000000,
			black 		= 0xff000000,
			white 		= 0xffffffff,
			red 		= 0xffff0000,
			green 		= 0xff00ff00,
			blue 		= 0xff0000ff,
			yellow 		= 0xffffff00,
			magenta 	= 0xffff00ff,
			cyan 		= 0xff00ffff;
#endif

#ifdef LGW_FORMAT_RGBA8888
		static const constexpr uint32_t
			transparent = 0x00000000,
			black 		= 0x000000ff,
			white 		= 0xffffffff,
			red 		= 0xff0000ff,
			green 		= 0x00ff00ff,
			blue 		= 0x0000ffff,
			yellow 		= 0xffff00ff,
			magenta 	= 0xff00ffff,
			cyan 		= 0x00ffffff;
#endif
	}

	/**
	 *  \brief Generate a color given RGB components
	 *  
	 *  \param r Color's red component
	 *  \param g Color's green component
	 *  \param b Color's blue component
	 */
	inline uint32_t rgb(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0xff) {
		return (a << detail::conv_alpha_shift) |
               (r << detail::conv_red_shift)   |
               (g << detail::conv_green_shift) |
               (b << detail::conv_blue_shift);
	}
	
	/**
	 *  \brief Generate a color given a Y value (r = g = b = y)
	 *  
	 *  \param y Color's grayscale value
	 */
	inline uint32_t rgb(uint8_t y, uint8_t a = 0xff) {
        return (a << detail::conv_alpha_shift) |
               (y << detail::conv_red_shift)   |
               (y << detail::conv_green_shift) |
               (y << detail::conv_blue_shift);
	}
}