#version 450

#extension GL_KHR_vulkan_glsl : enable
#extension GL_EXT_nonuniform_qualifier : require
#extension GL_ARB_shader_draw_parameters : require
#extension GL_GOOGLE_include_directive: enable

#include "../GlobalBuffer.glsl"

layout(location = 0) out vec3 outUVW;

layout (set = 0, binding = 0) uniform CameraBuffer
{
    CameraData main_camera;
};

vec3 vertices[] = {
	    {-1.0, -1.0, -1.0},        // bottom-left
	    {1.0, 1.0, -1.0},          // top-right
	    {1.0, -1.0, -1.0},         // bottom-right
	    {1.0, 1.0, -1.0},          // top-right
	    {-1.0, -1.0, -1.0},        // bottom-left
	    {-1.0, 1.0, -1.0},         // top-left
	                                  // front face
	    {-1.0, -1.0, 1.0},         // bottom-left
	    {1.0, -1.0, 1.0},          // bottom-right
	    {1.0, 1.0, 1.0},           // top-right
	    {1.0, 1.0, 1.0},           // top-right
	    {-1.0, 1.0, 1.0},          // top-left
	    {-1.0, -1.0, 1.0},         // bottom-left
	                                  // left face
	    {-1.0, 1.0, 1.0},          // top-right
	    {-1.0, 1.0, -1.0},         // top-left
	    {-1.0, -1.0, -1.0},        // bottom-left
	    {-1.0, -1.0, -1.0},        // bottom-left
	    {-1.0, -1.0, 1.0},         // bottom-right
	    {-1.0, 1.0, 1.0},          // top-right
	                                  // right face
	    {1.0, 1.0, 1.0},           // top-left
	    {1.0, -1.0, -1.0},         // bottom-right
	    {1.0, 1.0, -1.0},          // top-right
	    {1.0, -1.0, -1.0},         // bottom-right
	    {1.0, 1.0, 1.0},           // top-left
	    {1.0, -1.0, 1.0},          // bottom-left
	                                  // bottom face
	    {-1.0, -1.0, -1.0},        // top-right
	    {1.0, -1.0, -1.0},         // top-left
	    {1.0, -1.0, 1.0},          // bottom-left
	    {1.0, -1.0, 1.0},          // bottom-left
	    {-1.0, -1.0, 1.0},         // bottom-right
	    {-1.0, -1.0, -1.0},        // top-right
	                                  // top face
	    {-1.0, 1.0, -1.0},         // top-left
	    {1.0, 1.0, 1.0},           // bottom-right
	    {1.0, 1.0, -1.0},          // top-right
	    {1.0, 1.0, 1.0},           // bottom-right
	    {-1.0, 1.0, -1.0},         // top-left
	    {-1.0, 1.0, 1.0},          // bottom-left
	};

void main()
{
	outUVW = vertices[gl_VertexIndex];

    vec4 clip_pos = main_camera.view_projection * vec4(outUVW + main_camera.position, 1.0);

    gl_Position  = clip_pos.xyww;
}