# Minecraft LCE / 4J Custom Item Texture Quirk

## Problem

A custom 16x16 Netherite Pickaxe texture rendered as a broken mess of scattered colored pixels/cubes on Minecraft PS3/LCE, while the item itself worked perfectly.

The Sword, Axe, Shovel, and Hoe all rendered correctly using the same custom texture system.

## Cause

The issue was **not the renderer, item code, transforms, mipmaps, or display lists**.

The actual Pickaxe PNG from Minecraft Java Edition was encoded differently from the other tool textures.

### Working tool textures

The Axe and other working textures were normal:

- 16x16
- 8-bit RGBA
- Standard alpha channel
- PNG chunks roughly:
  - `IHDR`
  - `IDAT`
  - `IEND`

### Broken Java Pickaxe texture

The Pickaxe was still a valid 16x16 PNG, but internally it used:

- 4-bit indexed/palette color
- `PLTE` palette data
- `tRNS` palette transparency
- PNG chunks:
  - `IHDR`
  - `PLTE`
  - `tRNS`
  - `IDAT`
  - `IEND`

Java Edition handles this perfectly, but the old 4J/LCE texture pipeline appears to mishandle this particular indexed/palette PNG format.

## Fix

Convert the Pickaxe texture to:

- 16x16
- 8-bit RGBA
- Normal alpha channel
- Non-interlaced PNG
- No indexed palette
- No `PLTE`
- No `tRNS`

The actual artwork does **not** need to change.

After converting the exact same pixels to normal RGBA, the Pickaxe rendered correctly immediately.

## Important

If a custom 4J/LCE texture looks completely corrupted but the item/rendering code otherwise works:

**Check the PNG encoding before assuming the renderer is broken.**

Two images can both be valid 16x16 PNGs while using very different internal formats.

For safest compatibility with 4J:

> Use standard 8-bit RGBA PNGs for custom item textures.

## In Short

The Java Netherite Pickaxe texture was the odd one out.

It looked like a normal 16x16 PNG, but it used indexed palette transparency instead of regular RGBA.

4J did not like it.

Converting it to standard RGBA fixed everything.
