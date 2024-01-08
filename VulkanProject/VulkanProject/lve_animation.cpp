#include "lve_animation.hpp"
#include <iostream>
#include <numbers>

namespace lve
{
	LveAnimation::LveAnimation()
	{
		gameObject = nullptr;
		currentTime = 0;
		currentKeyframeIndex = 0;

		defaultTranslation = { 0.f,0.f,0.f };
		defaultRotation = { 0.f,0.f,0.f };
		defaultScale = { 1.f,1.f,1.f };
	}

	LveAnimation::LveAnimation(LveGameObject* obj, std::vector<LveKeyframe> frames)
		: gameObject{ obj }, keyframes{ frames }
	{
		defaultTranslation = gameObject->transform.translation;
		defaultRotation = gameObject->transform.rotation;
		defaultScale = gameObject->transform.scale;
		currentTime = 0;
		currentKeyframeIndex = 0;
	}

	void LveAnimation::calculateTransform(float delta)
	{
		currentTime += delta;

		// Key Previous key and current key
		LveKeyframe key0 = keyframes[currentKeyframeIndex];
		LveKeyframe key1 = keyframes[(currentKeyframeIndex + 1) % keyframes.size()];

		// Check if its time for the next keyframe
		if (currentTime > key1.keyTime)
		{
			//std::cout << "currentKeyFrameIndex: " << currentKeyframeIndex << "\n";
			currentKeyframeIndex = (currentKeyframeIndex + 1) % keyframes.size();
			currentTime = 0;
		}
		//std::cout << "Current Time: " << currentTime << "\n";
		// t is a 0 - 1 of time between two keyframes
		float t = currentTime / key1.keyTime;

		if (currentTime > 0)
		{
			// Translation Interpolation
			if (key0.translation != nullptr)
			{

				// Get the translation values for x,y,z
				float x0 = key0.translation->x;
				float y0 = key0.translation->y;
				float z0 = key0.translation->z;

				float x1 = key1.translation->x;
				float y1 = key1.translation->y;
				float z1 = key1.translation->z;



				glm::vec3 interpolatedPosition = {
					lerp(x0, x1, t),
					lerp(y0, y1, t),
					lerp(z0, z1, t)
				};

				gameObject->transform.translation = defaultTranslation + interpolatedPosition;
			}

			// Rotation Interpolation
			if (key0.rotation != nullptr)
			{
				// Get the translation values for x,y,z
				float x0 = key0.rotation->x;
				float y0 = key0.rotation->y;
				float z0 = key0.rotation->z;

				float x1 = key1.rotation->x;
				float y1 = key1.rotation->y;
				float z1 = key1.rotation->z;

				glm::vec3 interpolatedRotation = {
					lerp(x0, x1, t),
					lerp(y0, y1, t),
					lerp(z0, z1, t)
				};

				gameObject->transform.rotation = defaultRotation + interpolatedRotation;
			}

			// Scale Interpolation
			if (key0.scale != nullptr)
			{
				// Get the translation values for x,y,z
				float x0 = key0.scale->x;
				float y0 = key0.scale->y;
				float z0 = key0.scale->z;

				float x1 = key1.scale->x;
				float y1 = key1.scale->y;
				float z1 = key1.scale->z;

				glm::vec3 interpolatedScale = {
					lerp(x0, x1, t),
					lerp(y0, y1, t),
					lerp(z0, z1, t)
				};

				gameObject->transform.scale = defaultScale * interpolatedScale;
			}
		}



		//std::cout << "Y component: " << gameObject->transform.translation.y << "\n";
		//std::cout << "Y component: " << gameObject->transform.translation. << "\n";
	}

	float LveAnimation::lerp(float a, float b, float t)
	{
		return (1 - t) * a + t * b;
	}
}