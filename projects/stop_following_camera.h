void StopFollowingCamera(bool toggle) { if (toggle) *(int*)0xBC8DB0 = 0x4E800020; else *(int*)0xBC8DB0 = 0xF821FEF1; } // by Nuptunia / kqni
// Stops following where your looking and makes your character look somewhere else.
