// Credit to aMsk
void createBox2DImg(float x, float y, float sX, float sY, float alpha, uint32_t imgID)
{
    colored customColors;
    customColors.r = 255;
    customColors.g = 255;
    customColors.b = 255;
    customColors.a = alpha;

    GlStateManager::pushMatrix();
    GlStateManager::DisableTexture2D();
    GlStateManager::translatef(x, y, 0);
    GlStateManager::color4f(1, 1, 1, 1);

    GlStateManager::enableBlend();
    GlStateManager::blendFunc(MC_GL_SRC_ALPHA, MC_GL_ONE_MINUS_SRC_ALPHA);

    // Activer la texture
    Textures::bindTexture(imgID);
    GlStateManager::EnableTexture2D();

    BufferBuilder* builder = Tesselator2::getInstance()->getBuilder();

    builder->begin();
    builder->color(customColors, alpha);
    builder->vertexUV(0, sY, -90, 0, 1);
    builder->vertexUV(sX, sY, -90, 1, 1);
    builder->vertexUV(sX, 0, -90, 1, 0);
    builder->vertexUV(0, 0, -90, 0, 0);
    builder->end();

    GlStateManager::popMatrix();
}

createBox2DImg(40, 40, 128, 128, 150, finalIDtest);

// Coloring (if needed)
    customColors.r = 255;
    customColors.g = 255;
    customColors.b = 255;
    customColors.a = 50; //Opacity
