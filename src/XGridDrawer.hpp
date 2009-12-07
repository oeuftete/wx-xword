// This file is part of XWord    
// Copyright (C) 2009 Mike Richards ( mrichards42@gmx.com )
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either
// version 3 of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#ifndef MY_GRID_DRAWER_H
#define MY_GRID_DRAWER_H

// For compilers that don't support precompilation, include "wx/wx.h"
#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
#    include <wx/wx.h>
#endif

#include "puz/XGrid.hpp"
#include "puz/XSquare.hpp"

const int MAX_POINT_SIZE = 150;
const int MIN_POINT_SIZE = 2;

//=============================================================================
// XGridDrawer is a template class designed to scale and draw various parts of
// the crossword grid.  The constructor requires a reference to a wxWindow
// or a wxDC (or any class with a GetTextExtent method).
// Of course, because it's a template class, everything has to be in the
// header file.
//=============================================================================


template <class C>
class XGridDrawer
{
public:
    XGridDrawer(C & measurer,
                XGrid * grid = NULL,
                const wxFont & font = *wxSWISS_FONT);

    // Sizes
    //------

    const wxRect & GetRect() const { return m_rect; }
    int    GetWidth()        const { return m_rect.GetWidth(); }
    int    GetHeight()       const { return m_rect.GetHeight(); }
    int    GetTop()          const { return m_rect.GetTop(); }
    int    GetLeft()         const { return m_rect.GetLeft(); }
    wxSize GetBestSize()     const;
    long   GetAlign()        const { return m_align; }
    int    GetBoxSize()      const { return m_boxSize; }
    int    GetBorderSize()   const { return m_borderSize; }
    int    GetSquareSize()   const { return m_boxSize + m_borderSize; }
    double GetLetterScale()  const { return m_letterScale; }
    double GetNumberScale()  const { return m_numberScale; }
    int    GetNumberHeight() const { return m_boxSize * m_numberScale; }
    int    GetLetterHeight() const { return m_boxSize * m_letterScale; }

    bool SetMaxSize(const wxSize & size) { return SetMaxSize(size.x, size.y); }
    bool SetMaxSize(int max_width, int max_height);
    void SetAlign(long align) { m_align = align; UpdateGridSize(); }
    void SetBoxSize(int size);
    void SetBorderSize(int size);
    void SetLetterScale(double scale);
    void SetNumberScale(double scale);

    // Fonts
    //------
    const wxFont & GetLetterFont()   const { return m_letterFont[0]; }
    const wxFont & GetNumberFont()   const { return m_numberFont; }

    void SetLetterFont(const wxFont & font);
    void SetNumberFont(const wxFont & font);

    // XGrid
    //------
    XGrid * GetGrid() { return m_grid; }
    const XGrid * GetGrid() const { return m_grid; }
    void SetGrid(XGrid * grid)
    {
        m_grid = grid;
        if (grid != NULL)
            UpdateGridSize();
    }

    void DrawSquare(wxDC & dc, const XSquare & square,
                    const wxColour & bgColor, const wxColour & textColor,
                    bool  drawOutline);
    void DrawGrid(wxDC & dc);

private:
    C & m_measurer;
    XGrid * m_grid;
    long m_align;
    int m_boxSize;
    int m_borderSize;
    double m_numberScale;
    double m_letterScale;
    wxRect m_rect;
    int m_maxWidth;
    int m_maxHeight;

    wxFont m_numberFont;
    wxFont m_letterFont[8];  // Cache fonts for all rebus lengths

    void UpdateGridSize();
    void ScaleFont(wxFont * font, int maxWidth, int maxHeight);
    void ScaleFonts() { ScaleNumberFont(); ScaleLetterFont(); }
    void ScaleNumberFont() { ScaleFont(&m_numberFont, -1, GetNumberHeight()); }
    void ScaleLetterFont();
    static double GetScale(int width, int height, int maxWidth, int maxHeight);
};




template <class C>
XGridDrawer<C>::XGridDrawer(C & measurer, XGrid * grid, const wxFont & font)
    : m_measurer(measurer),
      m_grid(grid)
{
    m_boxSize = 20;
    m_borderSize = 1;

    // This is a good default scale.
    // Allowing the square number to take up 5/12 of the square and the text
    // to take up 9/12 (=3/4) should introduce some overlap, but the character
    // height of a font seems to be larger than the actual text size (e.g.
    // GetCharHeight may report a height of 28 px when the letter itself only
    // takes up 24 px).
    m_numberScale = 42 / 100.;
    m_letterScale = 75 / 100.;

    m_numberFont = font;
    m_letterFont[0] = font;
    SetNumberFont(font);
    SetLetterFont(font);
    UpdateGridSize();
}
//-----------------------------------------------------------------------------
// Grid / Box / Border sizes
//-----------------------------------------------------------------------------
template <class C>
wxSize
XGridDrawer<C>::GetBestSize() const
{
    if (m_grid == NULL || m_grid->IsEmpty())
        return wxDefaultSize;

    return wxSize( m_grid->GetWidth()
                   * (m_boxSize + m_borderSize)
                   + m_borderSize,

                   m_grid->GetHeight()
                   * (m_boxSize + m_borderSize)
                   + m_borderSize );
}

template <class C>
void
XGridDrawer<C>::UpdateGridSize()
{
    if (m_grid == NULL)
        return;
    // Update width and height of grid
    m_rect.SetWidth ( m_grid->GetWidth()
                      * (m_boxSize + m_borderSize)
                      + m_borderSize );

    m_rect.SetHeight( m_grid->GetHeight()
                      * (m_boxSize + m_borderSize)
                      + m_borderSize );

    // Update left side of grid
    if ((m_align & wxALIGN_RIGHT) != 0)
        m_rect.SetX(m_maxWidth - m_rect.width);
    else if ((m_align & wxALIGN_CENTER_HORIZONTAL) != 0)
        m_rect.SetX( (m_maxWidth  - m_rect.width)  / 2 );
    else
        m_rect.SetX(0);

    // Update top of grid
    if ((m_align & wxALIGN_BOTTOM) != 0)
        m_rect.SetY(m_maxHeight - m_rect.height);
    else if ((m_align & wxALIGN_CENTER_VERTICAL) != 0)
        m_rect.SetY( (m_maxHeight - m_rect.height) / 2 );
    else
        m_rect.SetY(0);

    ScaleFonts();
}

template <class C>
bool
XGridDrawer<C>::SetMaxSize(int max_width, int max_height)
{
    m_maxWidth = max_width;
    m_maxHeight = max_height;

    if (m_grid == NULL)
        return false;

    // If the window is too small to fit the grid, catch it here
    if (m_maxWidth  < (m_grid->GetWidth()  + 1) * m_borderSize
     || m_maxHeight < (m_grid->GetHeight() + 1) * m_borderSize)
    {
        return false;
    }

    const size_t width =
        (m_maxWidth  - (m_grid->GetWidth() + 1)  * m_borderSize)
        / m_grid->GetWidth();

    const size_t height =
        (m_maxHeight - (m_grid->GetHeight() + 1) * m_borderSize)
        / m_grid->GetHeight();

    SetBoxSize(std::min(width, height));
    return true;
}

template <class C>
void
XGridDrawer<C>::SetBoxSize(int size)
{
    m_boxSize = size;
    UpdateGridSize();
}

template <class C>
void
XGridDrawer<C>::SetBorderSize(int size)
{
    m_borderSize = size;
    UpdateGridSize();
}





//-----------------------------------------------------------------------------
// Fonts
//-----------------------------------------------------------------------------
template <class C>
double
XGridDrawer<C>::GetScale(int width, int height, int maxWidth, int maxHeight)
{
    if      (maxWidth == -1)
        return static_cast<double>(maxHeight) / static_cast<double>(height);
    else if (maxHeight == -1)
        return static_cast<double>(maxWidth) / static_cast<double>(width);

    return std::min( static_cast<double>(maxWidth)  / static_cast<double>(width),
                     static_cast<double>(maxHeight) / static_cast<double>(height)    );
}

template <class C>
void
XGridDrawer<C>::ScaleFont(wxFont * font, int maxWidth, int maxHeight)
{
    // Don't test numbers and symbols because they're probably not as wide.
    const wxString text = _T("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    // Adjust width to fit the test string
    if (maxWidth != -1)
        maxWidth *= text.length();

    int h, w;
    m_measurer.GetTextExtent(text, &w, &h, NULL, NULL, font);

    // First "guess" should speed things up
    font->SetPointSize(font->GetPointSize() * GetScale(w, h, maxWidth, maxHeight));

    // Make the font larger if needed.
    m_measurer.GetTextExtent(text, &w, &h, NULL, NULL, font);
    while ( (maxHeight == -1 ? true : h < maxHeight) &&
            (maxWidth  == -1 ? true : w < maxWidth) &&
            font->GetPointSize() < MAX_POINT_SIZE )
    {
        font->SetPointSize(font->GetPointSize()+1);
        m_measurer.GetTextExtent(text, &w, &h, NULL, NULL, font);
    }

    // Make the font smaller if needed.
    while ( (maxHeight == -1 ? true : h > maxHeight) &&
            (maxWidth  == -1 ? true : w > maxWidth) &&
            font->GetPointSize() > MIN_POINT_SIZE )
    {
        font->SetPointSize(font->GetPointSize()-1);
        m_measurer.GetTextExtent(text, &w, &h, NULL, NULL, font);
    }

    // This happens if desiredHeight is very small or zero
    if (font->GetPointSize() < MIN_POINT_SIZE)
        font->SetPointSize(MIN_POINT_SIZE);
}

template <class C>
inline void
XGridDrawer<C>::ScaleLetterFont()
{
    // This function should be called after setting the first letter
    // font.

    // Provide a scaled font for a variable number of letters (1 - 8) in 
    // a given square.

    // 1 letter
    ScaleFont(&m_letterFont[0], -1, GetLetterHeight());

    // 2-3 letters
    m_letterFont[1] = m_letterFont[0];
    ScaleFont(&m_letterFont[1], GetSquareSize() / 4, GetLetterHeight());
    m_letterFont[2] = m_letterFont[1];

    // 4-5 letters
    m_letterFont[3] = m_letterFont[2];
    ScaleFont(&m_letterFont[3], GetSquareSize() / 6, GetLetterHeight());
    m_letterFont[4] = m_letterFont[3];

    // 6+ (6-8) letters
    m_letterFont[5] = m_letterFont[4];
    ScaleFont(&m_letterFont[5], GetSquareSize() / 8, GetLetterHeight());
    m_letterFont[6] = m_letterFont[5];
    m_letterFont[7] = m_letterFont[6];
}


template <class C>
void
XGridDrawer<C>::SetNumberScale(double scale)
{
    m_numberScale = scale;
    ScaleNumberFont();
}


template <class C>
void
XGridDrawer<C>::SetLetterScale(double scale)
{
    m_letterScale = scale;
    ScaleLetterFont();
}

template <class C>
void
XGridDrawer<C>::SetLetterFont(const wxFont & font)
{
    m_letterFont[0] = font;
    ScaleLetterFont();
}

template <class C>
void
XGridDrawer<C>::SetNumberFont(const wxFont & font)
{
    m_numberFont = font;
    ScaleNumberFont();
}


template <class C>
void
XGridDrawer<C>::DrawSquare(wxDC & dc,
                           const XSquare & square,
                           const wxColour & bgColor,
                           const wxColour & textColor,
                           bool  drawOutline)
{
    // The order of drawing is important to make sure that we don't draw over
    // the more important parts of a square:
    // 1. The background
    // 2. An incorrect / revealed indicator (the little triangle in the corner)
    // 3. A circle
    // 4. The number (with an opaque background so it draws over the circle)
    // 5. The text
    // 6. An X over everything if necessary

    // If the user has pressed <insert> we are in rebus mode.  The focused square
    // will be outlined in the selected color (and have a white background).
    // Certain features will not be drawn in this case:
    //    - The number
    //    - The incorrect/revealed indicator
    //    - The X (if applicable).


    const int x = m_rect.x + m_borderSize + square.GetCol() * GetSquareSize();
    const int y = m_rect.y + m_borderSize + square.GetRow() * GetSquareSize();

    // Draw the square background
    if (drawOutline)
    {
        const int outlineSize = std::max(m_boxSize / 15, 1);

        wxPen outlinePen(bgColor, outlineSize * 2);
        outlinePen.SetJoin(wxJOIN_MITER);

        dc.SetPen(outlinePen);
        dc.SetBrush(wxBrush(bgColor));
        dc.DrawRectangle(x + outlineSize,
                         y + outlineSize,
                         m_boxSize - outlineSize * 2 + 1,
                         m_boxSize - outlineSize * 2 + 1);

    }
    else
    {
        dc.SetBrush(wxBrush(bgColor));
        dc.SetPen  (wxPen(bgColor));

        dc.DrawRectangle(x, y, m_boxSize, m_boxSize);
    }

    // Draw square's flag if any (top right)
    if (square.HasFlag(XFLAG_RED | XFLAG_BLACK) && ! drawOutline)
    {
        if (square.HasFlag(XFLAG_RED))
        {
            dc.SetBrush(*wxRED_BRUSH);
            dc.SetPen(*wxRED_PEN);
        }
        else
        {
            dc.SetBrush(*wxBLACK_BRUSH);
            dc.SetPen(*wxBLACK_PEN);
        }
        wxPoint pts[3];
        pts[0] = wxPoint(x + 2./3.*m_boxSize, y);
        pts[1] = wxPoint(x + m_boxSize - 1, y);
        pts[2] = wxPoint(x + m_boxSize - 1, y + 1./3.*m_boxSize);
        dc.DrawPolygon(3, pts);
    }


    if (square.HasFlag(XFLAG_CIRCLE))
    {
        dc.SetBrush(*wxTRANSPARENT_BRUSH);
        dc.SetPen(wxPen(*wxBLACK, 1));
        dc.DrawCircle(x + m_boxSize/2, y + m_boxSize/2, m_boxSize/2);
    }

    dc.SetTextForeground(textColor);

    // Draw square's number if applicable (top left).
    if (square.GetNumber() != 0 && ! drawOutline)
    {
        // Set a solid text background so it will draw over any circles.
        dc.SetTextBackground(bgColor);
        dc.SetBackgroundMode(wxSOLID);

        dc.SetFont(m_numberFont);
        dc.DrawText(wxString::Format(_T("%d"), square.GetNumber()), x+1, y);
        dc.SetBackgroundMode(wxTRANSPARENT);
    }

    // Draw square's text (bottom and center to avoid conflicts with numbers)
    if (! square.IsBlank())
    {
        wxString text = square.GetText();

        if (text.length() > 4)
        {
            const int len = (text.length() + 1) / 2;
            text.insert(len, _T("\n"));

            dc.SetFont(m_letterFont[3]);
        }
        else
            dc.SetFont(m_letterFont[text.length() - 1]);

        if (text.length() == 1)
        {
            int width, height;
            dc.GetTextExtent(text, &width, &height);
            dc.DrawText(text,
                        x + (m_boxSize - width)/2,
                        y + (m_boxSize - height));
        }
        else
        {
            dc.DrawLabel(text,
                         wxRect(x, y + m_boxSize - GetLetterHeight(),
                                m_boxSize, GetLetterHeight()),
                         wxALIGN_CENTER);
        }
    }

    // Draw an X across the square
    if (square.HasFlag(XFLAG_X) && ! drawOutline)
    {
        dc.SetPen(wxPen(*wxRED, 2));
        // Funky math here because of the way that DCs draw lines
        dc.DrawLine(x + 1, y + 1, x + m_boxSize - 2, y + m_boxSize - 2);
        dc.DrawLine(x + m_boxSize - 2, y + 1, x + 1, y + m_boxSize - 2);
    }
}


template <class C>
void
XGridDrawer<C>::DrawGrid(wxDC & dc)
{
    if (m_grid.IsEmpty())
    {
        wxLogDebug(_T("Grid is empty"));
        return;
    }

    // Draw black as crossword background
    dc.SetBrush(wxBrush(GetBlackSquareColor()));
    dc.SetPen  (wxPen(GetBlackSquareColor()));

    dc.DrawRectangle(m_rect);

    XSquare * square;

    for (square = m_grid->First(); square != NULL; square = square->Next())
        DrawSquare(dc, *square);
}


#endif // MY_GRID_DRAWER_H