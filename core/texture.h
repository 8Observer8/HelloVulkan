﻿#ifndef TEXTURE_H
#define TEXTURE_H

#include "hellovulkan.h"

class OldVisualServer;
class VulkanServer;
class Mesh;

class Texture {
	friend class Mesh;
	friend class MeshHandle;

	VulkanServer *vulkanServer;
	VkImage image;
	VkDeviceMemory imageMemory;
	VkImageView imageView;
	VkSampler imageSampler;

	int width;
	int height;
	int channels_of_image;

public:
	Texture(VulkanServer *p_vulkanServer);
	Texture(OldVisualServer *p_visualServer);
	~Texture();
	bool load(const std::string &p_path);

private:
	bool _createSampler();
	void clear();
};

#endif // TEXTURE_H
