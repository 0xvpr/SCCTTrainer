#include "drawing.h"

void drawing_draw_border_box(int x, int y, int w, int h, int thickness, D3DCOLOR color, LPDIRECT3DDEVICE9 d3dDevice)
{ 
    drawing_draw_filled_rect(x, y, w, thickness, color, d3dDevice);                 // Top horizontal line
    drawing_draw_filled_rect(x, y, thickness, h, color, d3dDevice);                 // Left vertical line
    drawing_draw_filled_rect((x + w), y, thickness, h, color, d3dDevice);           // Right vertical line
    drawing_draw_filled_rect(x, y + h, w + thickness, thickness, color, d3dDevice); // Bottom horizontal line
}

void drawing_draw_filled_rect(int x, int y, int w, int h, D3DCOLOR color, LPDIRECT3DDEVICE9 d3dDevice)
{
    D3DRECT BarRect = { x, y, x + w, y + h };
    IDirect3DDevice9_Clear(d3dDevice, 1, &BarRect, D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER | D3DCLEAR_TARGET, color, 0, 0);
}
