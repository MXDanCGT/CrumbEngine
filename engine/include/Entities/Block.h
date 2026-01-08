namespace Crumb
{
	/*
	* Blocks are our voxels the world is made up out of...
	* 
	* This engine is designed for voxel worlds, so a lot of the voxel functionality itself is done by engine
	*/

	class Block
	{

	protected:

		/**
		* We are packing positions into one int - i.e.:
		* Position.x | Position.y << 10 | Position.z << 20
		*/
		int Position;
	};

}