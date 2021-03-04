/**
 *  \file framebuffer.hpp
 *  \brief Defines a generic framebuffer, and implements a lightweight 32-bit color specialization
 */

#pragma once

#include <array>
#include <cstdint>

#include "color.hpp"

namespace lgw {
	namespace detail {
		/**
		 *  \class detail::framebuffer
		 *  \brief A format-agnostic/generic framebuffer, meant to be inherited and implemented
		 */
		template <typename T, size_t W, size_t H> class framebuffer {
			typedef std::array <T, W * H> buf_t;

		public:
			virtual void clear(T) = 0;
			virtual void init(T) {};
			virtual void draw(size_t, size_t, T) = 0;
			virtual T& read(size_t, size_t) = 0;
			virtual T* get_buffer() = 0;
		};
	}

	/**
	 *  \brief A 32-bit color pixel framebuffer
	 */
	template <size_t W, size_t H> class framebuffer : public detail::framebuffer<uint32_t, W, H> {
		typedef std::array <uint32_t, W * H> buf_t;

		uint32_t dummy = 0;

		buf_t buf;

	public:
		framebuffer() = default;
		framebuffer(uint32_t color) { clear(color); }

		/**
		 *  \brief Clear the framebuffer, and fill with the specified color
		 *  
		 *  \param color Color to set all pixels in the framebuffer to
		 */
		void clear(uint32_t color = color::black) override {
			for (uint32_t& p : buf) p = color;
		}

		/**
		 *  \brief Draw a pixel at location (x, y) with the specified color
		 *  
		 *  \param x Pixel X coord
		 *  \param y Pixel Y coord
		 *  \param color Color to set the pixel to
		 */
		void draw(size_t x, size_t y, uint32_t color) override {
			size_t index = x + (y * W);

			if (index >= buf.size()) return;

			buf[index] = color;
		}

		/**
		 *  \brief Get a reference to the pixel at location (x, y)
		 *  
		 *  \param x Pixel X coord
		 *  \param y Pixel Y coord
		 */
		uint32_t& read(size_t x, size_t y) override {
			size_t index = x + (y * W);

			if (index > buf.size()) return dummy;

			return buf.at(index);
		}

		/**
		 *  \brief Get a pointer to the underlying array
		 */
		uint32_t* get_buffer() override {
			return buf.data();
		}
	};
}