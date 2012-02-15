#ifndef SPROBJECT_H
#define SPROBJECT_H

struct sprObject
{
	float x,y;		
	float scale,rot;	
};

struct TexturePack
{
	TexturePack()
	{

	};

	TexturePack(std::string _nameTexture, HTEXTURE _texture)
	{
		nameTexture = _nameTexture;
		texture = _texture;
	};

	std::string nameTexture;		
	HTEXTURE texture;	
};

#endif