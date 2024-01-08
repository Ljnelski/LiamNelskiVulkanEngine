#pragma once
#include <glm/ext/vector_float3.hpp>


namespace lve
{
	struct LveKeyframe
	{
		glm::vec3* translation;
		glm::vec3* rotation;
		glm::vec3* scale;

		float keyTime;
	};

	const static std::vector<LveKeyframe> RISE_AND_FALL = {
		{
			new glm::vec3{.5f, 0.f, 0.f},
			nullptr,
			nullptr,
			1.f
		},
		{
			new glm::vec3{ .5f, -.25f, 0.f },
			nullptr,
			nullptr,
			1.f
		},
		{
			new glm::vec3{ .5f, -0.5f, 0.f},
			nullptr,
			nullptr,
			1.f
		}		
	};

	const static std::vector<LveKeyframe> WOBBLE = {
		{
			nullptr,
			new glm::vec3{0,0,0},
			nullptr,
			1.f,
		},
		{
			nullptr,
			new glm::vec3{0.25f,0,0.25f},
			nullptr,
			1.f,
		},
		{
			nullptr,
			new glm::vec3{0.375f,0,0.125f},
			nullptr,
			.5f,
		},
		{
			nullptr,
			new glm::vec3{0.5f,0,0},
			nullptr,
			.5f,
		},
		{
			nullptr,
			new glm::vec3{0.375f,0,-0.125},
			nullptr,
			.5f,
		},
		{
			nullptr,
			new glm::vec3{0.25f,0,-0.25},
			nullptr,
			.5f,
		},
	};

	const static std::vector<LveKeyframe> GROW_AND_SHRINK = {
		{
			nullptr,
			nullptr,
			new glm::vec3{1.f,1.f,1.f},
			2.f
		},
		{
			nullptr,
			nullptr,
			new glm::vec3{2.f,2.f,2.f},
			2.f
		},
	};

	const static std::vector<LveKeyframe> JUMP = {
		{
			new glm::vec3{0.5f, 0.5f, 0.f},
			nullptr,
			new glm::vec3{1.f, 1.f, 1.f},
			1.f
		},
		{
			new glm::vec3{0.5f, 0.5f, 0.f},
			nullptr,
			new glm::vec3{1.f, 0.5f, 1.f},
			1.f
		},
		{
			new glm::vec3{0.5f, -1.f, 0.f},
			nullptr,
			new glm::vec3{1.f, 1.25f, 1.f},
			0.5f
		},
		{
			new glm::vec3{0.5f, -0.9f, 0.f},
			nullptr,
			new glm::vec3{1.f, 1.f, 1.f},
			0.25f
		},
	};


}