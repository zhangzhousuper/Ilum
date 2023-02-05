function add_material_node_plugin(category, name)
    target(string.format("Material.%s.%s", category, name))

    set_kind("shared")
    set_group(string.format("Plugin/MaterialNode/%s", category))

    add_rules("plugin")
    add_files(string.format("%s/%s.cpp", category, name))
    add_headerfiles("IMaterialNode.hpp")
    add_includedirs("./")
    add_deps("Core", "RHI", "Material", "Renderer", "Editor", "Resource")
    add_packages("imgui")

    target("Plugin")
        add_deps(string.format("Material.%s.%s", category, name))
    target_end()

    target_end()
end

add_material_node_plugin("Output", "MaterialOutput")
add_material_node_plugin("Texture", "ImageTexture")
add_material_node_plugin("Input", "RGB")
add_material_node_plugin("Input", "SurfaceInteraction")
add_material_node_plugin("Converter", "Calculate")
add_material_node_plugin("Converter", "VectorCalculate")
add_material_node_plugin("Converter", "VectorMerge")
add_material_node_plugin("Converter", "VectorSplit")
add_material_node_plugin("BSDF", "BlendBSDF")
add_material_node_plugin("BSDF", "DiffuseBSDF")
add_material_node_plugin("BSDF", "MirrorBSDF")
add_material_node_plugin("BSDF", "DielectricBSDF")
add_material_node_plugin("BSDF", "ConductorBSDF")
add_material_node_plugin("BSDF", "DisneyBSDF")