	int StopPacket = 0x4E800020; // by nuptunia 
	void StopFallingBlocks(bool toggle) { if (toggle) { *(int*)0x2958B8 = StopPacket; } else { *(int*)0x2958B8 = 0xF821FEA1; } }
