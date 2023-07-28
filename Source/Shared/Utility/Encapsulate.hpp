#pragma once

#define LovelaceEncapsulateProp(type, name, variable) \
	type Get##name(void) { return variable; } \
	void Set##name(type _##name) { variable = _##name; }

#define LovelaceGetEncapsulatedProp(type, name, variable) \
	type Get##name(void) { return variable; }