#pragma once

#include "World/World.h"

using namespace Crumb;

/*The world for our game - uses our own generating code...*/
class MCWorld : public World
{
public:

	virtual void GenerateWorld() override;

};