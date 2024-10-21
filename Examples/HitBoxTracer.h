// Credit to aMsk & MayhemModding
void renderHitbox_Stub(uint32_t renderer, uint32_t ref, uint32_t unk, float x, float y, float z, float a, float b)
{
    __nop(); __nop(); __nop(); __nop(); __nop();
}

void renderHitbox_Hook(uint32_t renderer, uint32_t ref, uint32_t unk, float x, float y, float z, float a, float b)
{
    ESP::DrawTracer(x, y, z);
}

HookFunctionStart(0xA5C0C8, *(uint32_t*)(renderHitbox_Hook), *(uint32_t*)(renderHitbox_Stub));

void DrawTracer(float x, float y, float z)
{
    colored color = { 255, 0, 0 };

    GlStateManager::DisableTexture2D();
    GlStateManager::disableCull();
    GlStateManager::disableDepth();
    GlStateManager::enableBlend();
    GlStateManager::blendFunc(4, 5);

    GlStateManager::color4f(1, 1, 1, 1);

    DisplayBox3D(x - 0.5f, y, z - 0.5f, 1, 2, 1, color, 150);

    BufferBuilder* builder = Tesselator2::getInstance()->getBuilder();
    GlStateManager::DisableTexture2D();
    GlStateManager::lineWidth(5);
    GlStateManager::pushMatrix();
    builder->begin(MC_GL_LINES);
    builder->color(color, 0xFF);
    builder->vertex(0, 0, 0);
    builder->vertex(x, y, z);
    builder->end();
    GlStateManager::popMatrix();

    GlStateManager::disableBlend();
    GlStateManager::enableDepth();
}
