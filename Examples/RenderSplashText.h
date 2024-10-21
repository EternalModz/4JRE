// Credit to aMsk
float scaleFactor = 1.0f;
float scaleStep = 0.004f;
bool growing = true;

void RenderSplashText(const wchar_t* text, float x, float y, int argb, bool shadow)
{
    // Update scale factor
    if (growing) {
        scaleFactor += scaleStep;
        if (scaleFactor >= 1.1f) // Adjust the maximum scale factor as needed
            growing = false;
    }
    else {
        scaleFactor -= scaleStep;
        if (scaleFactor <= 1.0f) // Adjust the minimum scale factor as needed
            growing = true;
    }

    uint32_t font = mc->theMinecraft->fontRenderer;
    GlStateManager::pushMatrix();
    GlStateManager::scalef(scaleFactor, scaleFactor, 0.0f);
    GlStateManager::rotatef(-10.0f, 0.0f, 0.0f, 1.0f);
    GlStateManager::translatef(1.0f, 1.0f, 0.0f);

    if (!shadow)
        UI::DrawText(font, (uint32_t)&getString(text), x, y, argb, 0, 1);
    else
        UI::DrawTextWithShadow(g_GuiComponent, mc->theMinecraft->fontRenderer, (uint32_t)&getString(text), x, y, argb);
    GlStateManager::popMatrix();
}
