#include "IMaterialNode.hpp"

#include <Resource/Resource/Texture2D.hpp>

using namespace Ilum;

class ImageTexture : public MaterialNode<ImageTexture>
{
	std::vector<const char *> filters = {
	    "Nearest",
	    "Linear",
	};

	std::vector<const char *> address_modes = {
	    "Repeat",
	    "Mirror Repeat",
	    "Clamp Edge",
	    "Clamp Border",
	    "Mirror Clamp",
	};

	struct ImageConfig
	{
		SamplerDesc sampler;
		char        filename[200];
	};

  public:
	virtual MaterialNodeDesc Create(size_t &handle) override
	{
		MaterialNodeDesc desc;
		return desc
		    .SetHandle(handle++)
		    .SetName("ImageTexture")
		    .SetCategory("Texture")
		    .SetVariant(ImageConfig{})
		    .Input(handle++, "UV", MaterialNodePin::Type::RGB, MaterialNodePin::Type::RGB | MaterialNodePin::Type::Float3)
		    .Input(handle++, "dUVdx", MaterialNodePin::Type::RGB, MaterialNodePin::Type::RGB | MaterialNodePin::Type::Float3, glm::vec3(0.f))
		    .Input(handle++, "dUVdy", MaterialNodePin::Type::RGB, MaterialNodePin::Type::RGB | MaterialNodePin::Type::Float3, glm::vec3(0.f))
		    .Output(handle++, "Color", MaterialNodePin::Type::RGB)
		    .Output(handle++, "Alpha", MaterialNodePin::Type::Float);
	}

	virtual void OnImGui(MaterialNodeDesc &node_desc, Editor *editor) override
	{
		ImageConfig &config = *node_desc.GetVariant().Convert<ImageConfig>();

		auto edit_filter = [&](const std::string &name, size_t *filter) {
			ImGui::PushID(name.c_str());
			if (ImGui::BeginCombo("", name.c_str()))
			{
				for (size_t i = 0; i < filters.size(); i++)
				{
					if (ImGui::Selectable(filters[i], i == *filter))
					{
						*filter = i;
					}
				}
				ImGui::EndCombo();
			}
			ImGui::PopID();
		};

		auto edit_address_mode = [&](const std::string &name, size_t *address_mode) {
			ImGui::PushID(name.c_str());
			if (ImGui::BeginCombo("", name.c_str()))
			{
				for (size_t i = 0; i < address_modes.size(); i++)
				{
					if (ImGui::Selectable(address_modes[i], i == *address_mode))
					{
						*address_mode = i;
					}
				}
				ImGui::EndCombo();
			}
			ImGui::PopID();
		};

		edit_filter("Min Filter", (size_t *) (&config.sampler.min_filter));
		edit_filter("Mag Filter", (size_t *) (&config.sampler.mag_filter));
		edit_filter("Mipmap", (size_t *) (&config.sampler.mipmap_mode));
		edit_address_mode("Address U", (size_t *) (&config.sampler.address_mode_u));
		edit_address_mode("Address V", (size_t *) (&config.sampler.address_mode_v));
		edit_address_mode("Address W", (size_t *) (&config.sampler.address_mode_w));

		auto *resource_manager = editor->GetRenderer()->GetResourceManager();
		if (resource_manager->Has<ResourceType::Texture2D>(config.filename))
		{
			if (ImGui::ImageButton(resource_manager->Get<ResourceType::Texture2D>(config.filename)->GetTexture(), ImVec2(100, 100)))
			{
				std::memset(config.filename, '\0', 200);
			}
		}
		else
		{
			ImGui::Button(config.filename, ImVec2(100.f, 100.f));
		}

		if (ImGui::BeginDragDropTarget())
		{
			if (const auto *pay_load = ImGui::AcceptDragDropPayload("Texture2D"))
			{
				std::memset(config.filename, '\0', 200);
				std::memcpy(config.filename, pay_load->Data, std::strlen(static_cast<const char *>(pay_load->Data)));
			}
			ImGui::EndDragDropTarget();
		}
	}

	virtual void EmitHLSL(const MaterialNodeDesc &node_desc, const MaterialGraphDesc &graph_desc, ResourceManager *manager, MaterialCompilationContext *context) override
	{
		if (context->IsCompiled(node_desc))
		{
			return;
		}

		auto *config = node_desc.GetVariant().Convert<ImageConfig>();

		context->samplers[fmt::format("sampler_{}", node_desc.GetHandle())] = config->sampler;
		context->textures[fmt::format("texture_{}", node_desc.GetHandle())] = std::string(config->filename);

		std::map<std::string, std::string> parameters;

		context->SetParameter<glm::vec3>(parameters, node_desc.GetPin("UV"), graph_desc, manager, context);
		context->SetParameter<glm::vec3>(parameters, node_desc.GetPin("dUVdx"), graph_desc, manager, context);
		context->SetParameter<glm::vec3>(parameters, node_desc.GetPin("dUVdy"), graph_desc, manager, context);

		context->variables.emplace_back(fmt::format("float4 S_{} = SampleTexture2D(material_data.texture_{}, material_data.sampler_{}, {}.xy, {}.xy, {}.xy);", node_desc.GetHandle(), node_desc.GetHandle(), node_desc.GetHandle(), parameters["UV"], parameters["dUVdx"], parameters["dUVdy"]));
		context->variables.emplace_back(fmt::format("float3 S_{} = S_{}.xyz;", node_desc.GetPin("Color").handle, node_desc.GetHandle()));
		context->variables.emplace_back(fmt::format("float S_{} = S_{}.w;", node_desc.GetPin("Alpha").handle, node_desc.GetHandle()));
	}
};

CONFIGURATION_MATERIAL_NODE(ImageTexture)