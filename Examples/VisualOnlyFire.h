int StopPacket = 0x4E800020;
void VisualOnlyFire(bool toggle) { if (toggle) { *(int*)0x0237BD0 = StopPacket; } else { *(int*)0x0237BD0 = 0xF821FF91; } }
