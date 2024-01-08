#pragma once
#include "lve_game_object.hpp"
#include "lve_keyframe.h"

namespace lve
{
	class LveAnimation
	{
	public:
		LveAnimation();
		LveAnimation(LveGameObject* obj, std::vector<LveKeyframe> frames);
		void calculateTransform(float delta);

	private:
		LveGameObject* gameObject;
		
		glm::vec3 defaultTranslation;
		glm::vec3 defaultRotation;
		glm::vec3 defaultScale;
		
		std::vector<LveKeyframe> keyframes;

		float currentTime;
		int currentKeyframeIndex;

		float lerp(float a, float b, float t);
	};
}