/**
 * The MIT License (MIT)
 *
 * Copyright © 2017-2020 Ruben Van Boxem
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 **/

/*
 * native_visual::wgl
 * Native Visual implementation for WGL (Windows GL).
 */

#ifndef SKUI_GUI_NATIVE_VISUAL_WGL_H
#define SKUI_GUI_NATIVE_VISUAL_WGL_H

#include "gui/native_visual.h++"

#ifndef WIN32_MEAN_AND_LEAN
#define WIN32_MEAN_AND_LEAN
#endif
#include <windows.h>
#undef WIN32_MEAN_AND_LEAN

namespace skui::gui::native_visual
{
  class wgl : public base
  {
  public:
    wgl();
    ~wgl() override;

    void create_surface(std::uintptr_t window) override;
    void swap_buffers(const graphics::pixel_size&) const override;
    void make_current() const override;
    void make_release() const override;

    gl_get_function_type get_gl_function() const override;

  private:
    HDC device_context;
    HGLRC gl_context;
  };
}

#endif
