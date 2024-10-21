// Credit to MayhemModding & aMsk
static void drawTracer(float x, float y, float z, float width, color rgb, int a, bool fixCoords = false) {
		GlStateManager::DisableTexture2D();

		GlStateManager::pushMatrix();
		GlStateManager::translatef(0, 0, 0);
		GlStateManager::color4f(1, 1, 1, 1);
		BufferBuilder* builder = Tesselator::getInstance()->getBuilder();

		Vector3 end2 = getEndPosition(100);
		end2 -= userOrigin;
		Vector3 end(end2.x, end2.z + 2, end2.y);

		float yAdj = 0;
		builder->begin(); // TOP
		builder->color(rgb, a);
		builder->vertex(x, y + width, z + width, fixCoords); // Y
		builder->vertex(x + width, y + width, z + width, fixCoords); // Y
		builder->vertex(x + width, y + width, z, fixCoords); // Y

		builder->vertex(end.x, end.y + width, end.z + width, fixCoords); // Y
		builder->vertex(end.x + width, end.y + width, end.z + width, fixCoords); // Y
		builder->vertex(end.x + width, end.y + width, end.z, fixCoords); // Y
		builder->end();

		builder->begin(); // BELOW
		builder->color(rgb, a);
		builder->vertex(x, y, z + width, fixCoords); // Y
		builder->vertex(x + width, y, z + width, fixCoords); // Y
		builder->vertex(x + width, y, z, fixCoords); // Y

		builder->vertex(end.x, end.y, end.z + width, fixCoords); // Y
		builder->vertex(end.x + width, end.y, end.z + width, fixCoords); // Y
		builder->vertex(end.x + width, end.y, end.z, fixCoords); // Y
		builder->end();

		builder->begin(); // SOUTH = THe OTHER THING
		builder->color(rgb, a);
		builder->vertex(x, y + width, z + width, fixCoords); // X
		builder->vertex(x, y + width, z, fixCoords); // X
		builder->vertex(x, y, z, fixCoords); // X

		builder->vertex(end.x, end.y + width, end.z + width, fixCoords); // X
		builder->vertex(end.x, end.y + width, end.z, fixCoords); // X
		builder->vertex(end.x, end.y, end.z, fixCoords); // X
		builder->end();

		builder->begin(); // WEST = LEFT
		builder->color(rgb, a);
		builder->vertex(x, y + width, z, fixCoords); // Z
		builder->vertex(x + width, y + width, z, fixCoords); // Z
		builder->vertex(x + width, y, z, fixCoords); // Z

		builder->vertex(end.x, end.y + width, end.z, fixCoords); // Z
		builder->vertex(end.x + width, end.y + width, end.z, fixCoords); // Z
		builder->vertex(end.x + width, end.y, end.z, fixCoords); // Z
		builder->end();

		builder->begin(); // NORTH = MIDDLE
		builder->color(rgb, a);
		builder->vertex(x + width, y + width, z, fixCoords); // X
		builder->vertex(x + width, y + width, z + width, fixCoords); // X
		builder->vertex(x + width, y, z + width, fixCoords); // X

		builder->vertex(end.x + width, end.y + width, end.z, fixCoords); // X
		builder->vertex(end.x + width, end.y + width, end.z + width, fixCoords); // X
		builder->vertex(end.x + width, end.y, end.z + width, fixCoords); // X
		builder->end();

		builder->begin(); // EAST = RIGHT
		builder->color(rgb, a);
		builder->vertex(x + width, y + width, z + width, fixCoords); // Z
		builder->vertex(x, y + width, z + width, fixCoords); // Z
		builder->vertex(x, y, z + width, fixCoords); // Z

		builder->vertex(end.x + width, end.y + width, end.z + width, fixCoords); // Z
		builder->vertex(end.x, end.y + width, end.z + width, fixCoords); // Z
		builder->vertex(end.x, end.y, end.z + width, fixCoords); // Z
		builder->end();

		GlStateManager::popMatrix();
	}
