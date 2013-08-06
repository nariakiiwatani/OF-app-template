
#pragma once

#include "ofShader.h"
#include "Def.h"

struct GeomSettings {
	GLenum geom_input_type;
	GLenum geom_output_type;
	GLenum geom_output_count;
};

struct ShaderParam {
	f32 seed;
	f32 genf[4];
	ofFloatColor primary_color;
	ofFloatColor secondary_color;

	bool updated;
};

struct Shader {
	u32 hash;
	ofShader of_shader;
	ShaderParam param;

	Shader():hash(0),param(){}
};

class ShaderManager
{
public:
	static const u32 SHADER_MAX = 16;

public:
	static Shader* loadShader(string shader_name);
	static Shader* loadShader(string shader_name, const GeomSettings& setting);
	static Shader* loadShader(string shader_name, GLenum geom_input_type,	GLenum geom_output_type, GLenum geom_output_count);
	static void unloadShader(string shader_name);

	static void beginShader(Shader& shader);
	static void beginShader(string name);
	static void beginShader(u32 hash);
	static void endShader();

	static Shader* getShader(string name);
	static Shader* getShader(u32 hash);

private:
	Shader  shaders_[SHADER_MAX];
private:
	ShaderManager();
	~ShaderManager();
	static ShaderManager instance_;
};

/* EOF */