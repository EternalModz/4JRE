// Credit to aMsk
class AABBox {
public:
    void AABB(double x1, double y1, double z1, double x2, double y2, double z2) {
        Call<void>(0x10408, x1, y1, z1, x2, y2, z2);
    }

    void AABB(Vec3 _min, Vec3 _max) {
        Call<void>(0x10408, _min.x, _min.y, _min.z, _max.x, _max.y, _max.z);
    }

    void AABB(int x1, int y1, int z1, int x2, int y2, int z2) {
        Call<void>(0x10408, toFloat(x1), toFloat(y1), toFloat(z1), toFloat(x2), toFloat(y2), toFloat(z2));
    }

    Vec3 min;
    Vec3 max;
};

void drawLine(BufferBuilder* builder, Nebula::Vec3 pos1, Nebula::Vec3 pos2) {
    builder->vertex(pos1.x, pos1.y, pos1.z, true);
    builder->vertex(pos2.x, pos2.y, pos2.z, true);
}

void drawLineBox(AABBox box, colored rgb, uint32_t a = 0xFF) 
{
    BufferBuilder* builder = Tesselator2::getInstance()->getBuilder();
    GlStateManager::disableTexture();
    GlStateManager::lineWidth(5);
    GlStateManager::pushMatrix();
    builder->begin(MC_GL_LINES);
    builder->color(rgb, a);
    // Bottom
    drawLine(builder, { box.min.x, box.min.y, box.min.z }, { box.max.x, box.min.y, box.min.z });
    drawLine(builder, { box.max.x, box.min.y, box.min.z }, { box.max.x, box.min.y, box.max.z });
    drawLine(builder, { box.max.x, box.min.y, box.max.z }, { box.min.x, box.min.y, box.max.z });
    drawLine(builder, { box.min.x, box.min.y, box.max.z }, { box.min.x, box.min.y, box.min.z });

    // Top
    drawLine(builder, { box.min.x, box.max.y, box.min.z }, { box.max.x, box.max.y, box.min.z });
    drawLine(builder, { box.max.x, box.max.y, box.min.z }, { box.max.x, box.max.y, box.max.z });
    drawLine(builder, { box.max.x, box.max.y, box.max.z }, { box.min.x, box.max.y, box.max.z });
    drawLine(builder, { box.min.x, box.max.y, box.max.z }, { box.min.x, box.max.y, box.min.z });

    // Lines from Buttom to Top
    drawLine(builder, { box.min.x, box.min.y, box.min.z }, { box.min.x, box.max.y, box.min.z });
    drawLine(builder, { box.max.x, box.min.y, box.min.z }, { box.max.x, box.max.y, box.min.z });
    drawLine(builder, { box.min.x, box.min.y, box.max.z }, { box.min.x, box.max.y, box.max.z });
    drawLine(builder, { box.max.x, box.min.y, box.max.z }, { box.max.x, box.max.y, box.max.z });

    builder->end();
    GlStateManager::popMatrix();
}
    drawLineBox({ {0, 0, 0}, {x, y, z} }, color, 0xFF);
