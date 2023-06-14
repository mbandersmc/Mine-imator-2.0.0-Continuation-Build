/// block_tile_entity_sign(map)
/// @arg map

function block_tile_entity_sign_text(map)
{
	var messagemap = value_get_array(map[?"messages"], "")
	var text = "";
	
	for (var i = 0; i < 4; i++)
	{
		var line = "";
		var textmap = json_decode(messagemap[i]);
			
		if (ds_map_valid(textmap))
		{
			if (is_string(textmap[?"text"]))
				line = textmap[?"text"]
				
			ds_map_destroy(textmap)
		}
			
		if (line = "")
			line = " "
			
		if (i > 0)
			text += "\n"
		text += line
	}
	
	return text;
}

function block_tile_entity_sign(map)
{
	var frontmap = map[?"front_text"];
	var backmap = map[?"back_text"];
	
	var text, colorind, color, glowind, glowcolor, glowing;
	
	// 1.20+
	if (ds_map_valid(frontmap))
	{
		// Front
		colorind = ds_list_find_index(minecraft_color_name_list, value_get_string(frontmap[?"color"], "black"))
		glowing = value_get_real(frontmap[?"has_glowing_text"], 0)
		glowind = minecraft_glowing_sign_list[|colorind]
		mc_builder.block_text_front_color_map[?build_pos] = (glowing ? glowind[0] : minecraft_color_list[|colorind])
		mc_builder.block_text_front_glow_color_map[?build_pos] = glowind[1]
		mc_builder.block_text_front_glowing_map[?build_pos] = glowing
		mc_builder.block_text_front_map[?build_pos] = block_tile_entity_sign_text(frontmap)
		
		// Back
		colorind = ds_list_find_index(minecraft_color_name_list, value_get_string(backmap[?"color"], "black"))
		glowing = value_get_real(backmap[?"has_glowing_text"], 0)
		glowind = minecraft_glowing_sign_list[|colorind]
		mc_builder.block_text_back_color_map[?build_pos] = (glowing ? glowind[0] : minecraft_color_list[|colorind])
		mc_builder.block_text_back_glow_color_map[?build_pos] = glowind[1]
		mc_builder.block_text_back_glowing_map[?build_pos] = glowing
		mc_builder.block_text_back_map[?build_pos] = block_tile_entity_sign_text(backmap)
	}
	else // Use legacy format if detected
	{
		colorind = ds_list_find_index(minecraft_color_name_list, value_get_string(map[?"Color"], "black"))
		glowing = value_get_real(map[?"GlowingText"], 0)
		glowind = minecraft_glowing_sign_list[|colorind]
		color = (glowing ? glowind[0] : minecraft_color_list[|colorind])
		glowcolor = glowind[1]
		text = ""
		
		for (var i = 0; i < 4; i++)
		{
			var line = map[?"Text" + string(i + 1)];
			if (!is_string(line))
				return 0
			
			var textmap = json_decode(line);
			if (ds_map_valid(textmap))
			{
				if (ds_list_valid(textmap[?"extra"]) && ds_list_size(textmap[?"extra"]) > 0)
				{
					var extramap = ds_list_find_value(textmap[?"extra"], 0);
					if (ds_map_valid(extramap) && is_string(extramap[?"text"]))
						textmap = extramap;
				}
				
				if (is_string(textmap[?"text"]))
					line = textmap[?"text"]
				
				ds_map_destroy(textmap)
			}
			
			if (line = "")
				line = " "
			
			if (i > 0)
				text += "\n"
			text += line
		}
		
		mc_builder.block_text_front_map[?build_pos] = text
		mc_builder.block_text_front_color_map[?build_pos] = color
		mc_builder.block_text_front_glow_color_map[?build_pos] = glowcolor
		mc_builder.block_text_front_glowing_map[?build_pos] = glowing
	}
}