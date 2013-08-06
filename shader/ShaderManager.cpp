
#include "ShaderManager.h"
#include "Poco/Hash.h"

ShaderManager ShaderManager::instance_;

ShaderManager::ShaderManager()
{
}

ShaderManager::~ShaderManager()
{
	for(s32 i = 0; i < SHADER_MAX; ++i) {
		if(shaders_[i].hash != 0) {
			shaders_[i].of_shader.unload();
		}
	}
}

Shader* ShaderManager::loadShader(string shader_name)
{
	string name_base = "shaders/"+shader_name;
	u32 hash = Poco::hash(shader_name);
	for(s32 i = 0; i < SHADER_MAX; ++i) {
		if(instance_.shaders_[i].hash == 0) {
			instance_.shaders_[i].hash = hash;
			instance_.shaders_[i].of_shader.load(name_base + ".vert", name_base + ".frag");
			return &instance_.shaders_[i];
		}
		else if(instance_.shaders_[i].hash == hash) {
			return &instance_.shaders_[i];
		}
	}
	return NULL;
}

Shader* ShaderManager::loadShader(string shader_name, const GeomSettings& settings)
{
	return loadShader(shader_name, settings.geom_input_type, settings.geom_output_type, settings.geom_output_count);
}

Shader* ShaderManager::loadShader(string shader_name, GLenum geom_input_type, GLenum geom_output_type, GLenum geom_output_count)
{
	string name_base = "shaders/"+shader_name;
	u32 hash = Poco::hash(shader_name);
	for(s32 i = 0; i < SHADER_MAX; ++i) {
		if(instance_.shaders_[i].hash == 0) {
			instance_.shaders_[i].hash = hash;
			instance_.shaders_[i].of_shader.setGeometryInputType(geom_input_type);
			instance_.shaders_[i].of_shader.setGeometryOutputType(geom_output_type);
			instance_.shaders_[i].of_shader.setGeometryOutputCount(geom_output_count);
			instance_.shaders_[i].of_shader.load(name_base + ".vert", name_base + ".frag", name_base + ".geom");
			return &instance_.shaders_[i];
		}
		else if(instance_.shaders_[i].hash == hash) {
			return &instance_.shaders_[i];
		}
	}
	return NULL;
}

void ShaderManager::unloadShader(string shader_name)
{
	u32 hash = Poco::hash(shader_name);
	for(s32 i = 0; i < SHADER_MAX; ++i) {
		if(instance_.shaders_[i].hash == hash) {
			instance_.shaders_[i].of_shader.unload();
			instance_.shaders_[i].hash = 0;
			return;
		}
	}
	ofLog(OF_LOG_ERROR, "shader not found: (name: %08x)", shader_name);
}

void ShaderManager::beginShader(string name)
{
	if(Shader* sh = getShader(name)) {
		beginShader(*sh);
	}
	else {
		beginShader(*loadShader(name));
	}
}

void ShaderManager::beginShader(u32 hash)
{
	beginShader(*getShader(hash));
}

void ShaderManager::beginShader(Shader& shader)
{
	ofShader& of_shader = shader.of_shader;
	ShaderParam& param = shader.param;
	of_shader.begin();
	if(shader.param.updated) {
		of_shader.setUniform1f("seed", param.seed);
		of_shader.setUniform4f("genf", param.genf[0], param.genf[1], param.genf[2], param.genf[3]);
		of_shader.setUniform4f("primary_color", param.primary_color.r, param.primary_color.g, param.primary_color.b, param.primary_color.a);
		of_shader.setUniform4f("secondary_color", param.secondary_color.r, param.secondary_color.g, param.secondary_color.b, param.secondary_color.a);
		param.updated = false;
	}
}

void ShaderManager::endShader()
{
	glUseProgram(0);
}


Shader* ShaderManager::getShader(string name)
{
	return getShader(Poco::hash(name));
}

Shader* ShaderManager::getShader(u32 hash)
{
	for(s32 i = 0; i < SHADER_MAX; ++i) {
		if(instance_.shaders_[i].hash == hash) {
			return &instance_.shaders_[i];
		}
	}
	ofLog(OF_LOG_ERROR, "shader not found: (hash: %08x)", hash);
	return NULL;
}



/* EOF */