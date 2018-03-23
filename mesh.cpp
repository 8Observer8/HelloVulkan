﻿#include "mesh.h"

Mesh::Mesh(){
	meshHandle = unique_ptr<MeshHandle>(new MeshHandle);
	meshHandle->mesh = this;
	transformation = glm::mat4(1.f);
}

Mesh::~Mesh(){}

void Mesh::setTransform(const glm::mat4 &p_transformation){
	transformation = p_transformation;
	meshHandle->hasTransformationChange = true;
}