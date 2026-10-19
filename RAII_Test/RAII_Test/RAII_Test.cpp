#include "pch.h"
#include "CWorld.h"

int main()
{
    CWorld world;

	world.Initialize();

	while (!world.Get_Exit())
	{
		world.Update();
		world.LateUpdate();
		world.Render();
	}

	return 0;
}
