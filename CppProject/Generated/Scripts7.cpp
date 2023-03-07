/*
	NOTE:
	This file was autogenerated by CppGen, changes may be overwritten and forever lost!
	Modify at your own risk!
	
	[ Generated on 2023.03.06 18:22:20 ]
*/

#include "Scripts.hpp"

namespace CppProject
{
	void action_project_render_glow(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_glow, sVar(project_render_glow), enable, true);
		sVar(project_render_glow) = enable;
	}
	
	void action_project_render_glow_falloff(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_glow_falloff, sVar(project_render_glow_falloff), enable, true);
		sVar(project_render_glow_falloff) = enable;
	}
	
	void action_project_render_glow_falloff_intensity(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_glow_falloff_intensity, sVar(project_render_glow_falloff_intensity), sVar(project_render_glow_falloff_intensity) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_glow_falloff_intensity) = sVar(project_render_glow_falloff_intensity) * add + val / 100.0;
	}
	
	void action_project_render_glow_falloff_radius(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_glow_falloff_radius, sVar(project_render_glow_falloff_radius), sVar(project_render_glow_falloff_radius) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_glow_falloff_radius) = sVar(project_render_glow_falloff_radius) * add + val / 100.0;
	}
	
	void action_project_render_glow_intensity(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_glow_intensity, sVar(project_render_glow_intensity), sVar(project_render_glow_intensity) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_glow_intensity) = sVar(project_render_glow_intensity) * add + val / 100.0;
	}
	
	void action_project_render_glow_radius(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_glow_radius, sVar(project_render_glow_radius), sVar(project_render_glow_radius) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_glow_radius) = sVar(project_render_glow_radius) * add + val / 100.0;
	}
	
	RealType action_project_render_import(ScopeAny self, StringType fn)
	{
		if (sReal(history_undo) > 0)
			history_copy_render_settings(self, ObjType(obj_history, global::history_data)->save_obj_old);
		else
			if (sReal(history_redo) > 0)
				history_copy_render_settings(self, ObjType(obj_history, global::history_data)->save_obj_new);
			else
			{
				if (fn == /*""*/ STR(0))
					fn = file_dialog_open_render();
				if (fn == /*""*/ STR(0))
					return IntType(0);
				IntType map = project_load_start(fn);
				if (map == null_)
					return IntType(0);
				VarType hobj;
				if (sArr(history).Value(IntType(0)) != null_ && ObjType(obj_history, sArr(history).Value(IntType(0)))->script == ID_action_project_render_settings)
					hobj = sArr(history).Value(IntType(0));
				else
					hobj = history_set(self, ID_action_project_render_import);
				
				ObjType(obj_history, hobj)->save_obj_old = (new obj_history_save)->id;
				ObjType(obj_history_save, ObjType(obj_history, hobj)->save_obj_old)->hobj = hobj;
				ObjType(obj_history, hobj)->save_obj_new = (new obj_history_save)->id;
				ObjType(obj_history_save, ObjType(obj_history, hobj)->save_obj_new)->hobj = hobj;
				ObjType(obj_history, hobj)->fn = fn;
				withOne (obj_history_save, ObjType(obj_history, hobj)->save_obj_old, self->id)
					history_copy_render_settings(ScopeAny(self), global::_app->id);
				
				project_load_render(self, DsMap(map).Value(/*"render"*/ STR(9)));
				ds_map_destroy(map);
				withOne (obj_history_save, ObjType(obj_history, hobj)->save_obj_new, self->id)
					history_copy_render_settings(ScopeAny(self), global::_app->id);
				
				log({ /*"Loaded render settings"*/ STR(10), fn });
			}
		
		
		return 0.0;
	}
	
	void action_project_render_indirect(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_indirect, sVar(project_render_indirect), enable, true);
		sVar(project_render_indirect) = enable;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_indirect_blur_radius(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_indirect_blur_radius, sVar(project_render_indirect_blur_radius), sVar(project_render_indirect_blur_radius) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_indirect_blur_radius) = sVar(project_render_indirect_blur_radius) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_indirect_precision(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_indirect_precision, sVar(project_render_indirect_precision), sVar(project_render_indirect_precision) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_indirect_precision) = sVar(project_render_indirect_precision) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_indirect_strength(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_indirect_strength, sVar(project_render_indirect_strength), sVar(project_render_indirect_strength) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_indirect_strength) = sVar(project_render_indirect_strength) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_liquid_animation(ScopeAny self, VarType value)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_liquid_animation, sVar(project_render_liquid_animation), value, IntType(1));
		sVar(project_render_liquid_animation) = value;
		toast_new(self, e_toast_WARNING, text_get({ /*"alertreloadobjects"*/ STR(11) }));
	}
	
	void action_project_render_material_maps(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_material_maps, sVar(project_render_material_maps), enable, IntType(1));
		sVar(project_render_material_maps) = enable;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_opaque_leaves(ScopeAny self, VarType value)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_opaque_leaves, sVar(project_render_opaque_leaves), value, true);
		sVar(project_render_opaque_leaves) = value;
		toast_new(self, e_toast_WARNING, text_get({ /*"alertreloadobjects"*/ STR(11) }));
	}
	
	void action_project_render_pass(ScopeAny self, VarType pass)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_pass, sInt(project_render_pass), pass, IntType(1));
		sInt(project_render_pass) = pass;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_reflections(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_reflections, sVar(project_render_reflections), enable, IntType(1));
		sVar(project_render_reflections) = enable;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_reflections_fade_amount(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_reflections_fade_amount, sVar(project_render_reflections_fade_amount), sVar(project_render_reflections_fade_amount) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_reflections_fade_amount) = sVar(project_render_reflections_fade_amount) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_reflections_precision(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_reflections_precision, sVar(project_render_reflections_precision), sVar(project_render_reflections_precision) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_reflections_precision) = sVar(project_render_reflections_precision) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_reflections_thickness(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_reflections_thickness, sVar(project_render_reflections_thickness), sVar(project_render_reflections_thickness) * add + val, IntType(1));
		sVar(project_render_reflections_thickness) = sVar(project_render_reflections_thickness) * add + val;
		global::render_samples = -IntType(1);
	}
	
	RealType action_project_render_reset(ScopeAny self)
	{
		if (sReal(history_undo) > 0)
			history_copy_render_settings(self, ObjType(obj_history, global::history_data)->save_obj_old);
		else
		{
			if (!(sReal(history_redo) > 0))
			{
				if (!question(text_get({ /*"questionresetrender"*/ STR(12) })))
					return IntType(0);
				IntType hobj = history_set(self, ID_action_project_render_reset);
				ObjType(obj_history, hobj)->save_obj_old = (new obj_history_save)->id;
				ObjType(obj_history_save, ObjType(obj_history, hobj)->save_obj_old)->hobj = hobj;
				withOne (obj_history_save, ObjType(obj_history, hobj)->save_obj_old, self->id)
					history_copy_render_settings(ScopeAny(self), global::_app->id);
				
			}
			project_reset_render(self);
		}
		
		return 0.0;
	}
	
	void action_project_render_samples(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_samples, sVar(project_render_samples), sVar(project_render_samples) * add + val, IntType(1));
		VarType valold = sVar(project_render_samples);
		sVar(project_render_samples) = sVar(project_render_samples) * add + val;
		if (sVar(project_render_samples) < valold)
			global::render_samples = -IntType(1);
	}
	
	RealType action_project_render_settings(ScopeAny self, VarType file)
	{
		if (sReal(history_undo) > 0)
		{
			file = ObjType(obj_history, global::history_data)->oldval;
			if (ObjType(obj_history, global::history_data)->save_obj_old != null_)
				history_copy_render_settings(self, ObjType(obj_history, global::history_data)->save_obj_old);
		}
		else
			if (sReal(history_redo) > 0)
			{
				file = ObjType(obj_history, global::history_data)->newval;
				if (ObjType(obj_history, global::history_data)->save_obj_new != null_)
					history_copy_render_settings(self, ObjType(obj_history, global::history_data)->save_obj_new);
			}
			else
			{
				if (file == /*""*/ STR(0) && global::trial_version > 0)
				{
					popup_show(self, sInt(popup_upgrade));
					ObjType(obj_popup, sInt(popup_upgrade))->page = IntType(2);
					ObjType(obj_popup, sInt(popup_upgrade))->custom_rendering = file;
					return IntType(0);
				}
				IntType hobj = history_set(self, ID_action_project_render_settings);
				ObjType(obj_history, hobj)->oldval = sVar(project_render_settings);
				ObjType(obj_history, hobj)->newval = file;
				ObjType(obj_history, hobj)->save_obj_new = null_;
				ObjType(obj_history, hobj)->save_obj_old = null_;
			}
		
		
		sVar(project_render_settings) = file;
		if (sVar(project_render_settings) != /*""*/ STR(0))
		{
			if (!(sReal(history_redo) > 0) && !(sReal(history_undo) > 0))
				action_project_render_import(self, render_directory + sVar(project_render_settings) + /*".mirender"*/ STR(13));
		}
		return 0.0;
	}
	
	void action_project_render_shadows(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_shadows, sVar(project_render_shadows), enable, IntType(1));
		sVar(project_render_shadows) = enable;
		global::render_samples = -IntType(1);
	}
	
	RealType action_project_render_shadows_point_buffer_size(ScopeAny self, VarType size)
	{
		if (size >= IntType(4096))
			if (!question(text_get({ /*"questionbuffersizewarning"*/ STR(14) })))
				return IntType(0);
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_shadows_point_buffer_size, sVar(project_render_shadows_point_buffer_size), size, IntType(1));
		sVar(project_render_shadows_point_buffer_size) = size;
		global::render_samples = -IntType(1);
		return 0.0;
	}
	
	RealType action_project_render_shadows_spot_buffer_size(ScopeAny self, VarType size)
	{
		if (size >= IntType(8192))
			if (!question(text_get({ /*"questionbuffersizewarning"*/ STR(14) })))
				return IntType(0);
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_shadows_spot_buffer_size, sVar(project_render_shadows_spot_buffer_size), size, IntType(1));
		sVar(project_render_shadows_spot_buffer_size) = size;
		global::render_samples = -IntType(1);
		return 0.0;
	}
	
	RealType action_project_render_shadows_sun_buffer_size(ScopeAny self, VarType size)
	{
		if (size >= IntType(8192))
			if (!question(text_get({ /*"questionbuffersizewarning"*/ STR(14) })))
				return IntType(0);
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_shadows_sun_buffer_size, sVar(project_render_shadows_sun_buffer_size), size, IntType(1));
		sVar(project_render_shadows_sun_buffer_size) = size;
		global::render_samples = -IntType(1);
		return 0.0;
	}
	
	void action_project_render_shadows_transparent(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_shadows_transparent, sVar(project_render_shadows_transparent), enable, IntType(1));
		sVar(project_render_shadows_transparent) = enable;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_ssao(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_ssao, sVar(project_render_ssao), enable, IntType(1));
		sVar(project_render_ssao) = enable;
	}
	
	void action_project_render_ssao_color(ScopeAny self, VarType color)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_ssao_color, sVar(project_render_ssao_color), color, IntType(1));
		sVar(project_render_ssao_color) = color;
	}
	
	void action_project_render_ssao_power(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_ssao_power, sVar(project_render_ssao_power), sVar(project_render_ssao_power) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_ssao_power) = sVar(project_render_ssao_power) * add + val / 100.0;
	}
	
	void action_project_render_ssao_radius(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_ssao_radius, sVar(project_render_ssao_radius), sVar(project_render_ssao_radius) * add + val, IntType(1));
		sVar(project_render_ssao_radius) = sVar(project_render_ssao_radius) * add + val;
	}
	
	void action_project_render_subsurface_highlight(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_subsurface_highlight, sVar(project_render_subsurface_highlight), sVar(project_render_subsurface_highlight) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_subsurface_highlight) = sVar(project_render_subsurface_highlight) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_subsurface_highlight_strength(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_subsurface_highlight_strength, sVar(project_render_subsurface_highlight_strength), sVar(project_render_subsurface_highlight_strength) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_subsurface_highlight_strength) = sVar(project_render_subsurface_highlight_strength) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_subsurface_samples(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_subsurface_samples, sVar(project_render_subsurface_samples), sVar(project_render_subsurface_samples) * add + val, IntType(1));
		sVar(project_render_subsurface_samples) = sVar(project_render_subsurface_samples) * add + val;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_texture_filtering(ScopeAny self, VarType filtering)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_texture_filtering, sVar(project_render_texture_filtering), filtering, IntType(1));
		sVar(project_render_texture_filtering) = filtering;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_texture_filtering_level(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_texture_filtering_level, sVar(project_render_texture_filtering_level), sVar(project_render_texture_filtering_level) * add + val, IntType(1));
		sVar(project_render_texture_filtering_level) = sVar(project_render_texture_filtering_level) * add + val;
		global::render_samples = -IntType(1);
		texture_set_mipmap_level(sVar(project_render_texture_filtering_level));
	}
	
	void action_project_render_tonemapper(ScopeAny self, VarType tonemapper)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_tonemapper, sVar(project_render_tonemapper), tonemapper, IntType(1));
		sVar(project_render_tonemapper) = tonemapper;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_transparent_block_texture_filtering(ScopeAny self, VarType filtering)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_transparent_block_texture_filtering, sVar(project_render_transparent_block_texture_filtering), filtering, IntType(1));
		sVar(project_render_transparent_block_texture_filtering) = filtering;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_water_reflections(ScopeAny self, VarType value)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_water_reflections, sVar(project_render_water_reflections), value, IntType(1));
		sVar(project_render_water_reflections) = value;
	}
	
	void action_project_tempo(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_tempo, sVar(project_tempo), sVar(project_tempo) * add + val, IntType(1));
		sVar(project_tempo) = sVar(project_tempo) * add + val;
		tl_update_length();
	}
	
	RealType action_project_video_height(ScopeAny self, RealType val, VarType add)
	{
		RealType ratio;
		if (sReal(history_undo) > 0)
		{
			sVar(project_video_width) = ObjType(obj_history, global::history_data)->old_width;
			sVar(project_video_height) = ObjType(obj_history, global::history_data)->old_height;
			return IntType(0);
		}
		else
			if (sReal(history_redo) > 0)
				val = ObjType(obj_history, global::history_data)->new_height;
			else
			{
				VarType hobj;
				history_pop(self);
				if (sReal(history_amount) > IntType(0) && ObjType(obj_history, sArr(history).Value(IntType(0)))->script == ID_action_project_video_height)
					hobj = sArr(history).Value(IntType(0));
				else
				{
					history_push(self);
					hobj = new_history(ID_action_project_video_height);
					ObjType(obj_history, hobj)->old_width = sVar(project_video_width);
					ObjType(obj_history, hobj)->old_height = sVar(project_video_height);
				}
				
				ObjType(obj_history, hobj)->new_height = sVar(project_video_height) * add + val;
				sArr(history)[IntType(0)] = hobj;
			}
		
		
		ratio = (RealType)sVar(project_video_width) / sVar(project_video_height);
		sVar(project_video_height) = sVar(project_video_height) * add + val;
		if (sVar(project_video_keep_aspect_ratio) > 0)
			sVar(project_video_width) = max({ IntType(1), round(sVar(project_video_height) * ratio) });
		return 0.0;
	}
	
	void action_project_video_keep_aspect_ratio(ScopeAny self)
	{
		sVar(project_video_keep_aspect_ratio) = !(sVar(project_video_keep_aspect_ratio) > 0);
	}
	
	RealType action_project_video_template(ScopeAny self, VarType argument0)
	{
		if (sReal(history_undo) > 0)
		{
			sVar(project_video_template) = ObjType(obj_history, global::history_data)->oldtemplate;
			sVar(project_video_width) = ObjType(obj_history, global::history_data)->oldwidth;
			sVar(project_video_height) = ObjType(obj_history, global::history_data)->oldheight;
			return IntType(0);
		}
		else
			if (sReal(history_redo) > 0)
				argument0 = ObjType(obj_history, global::history_data)->newtemplate;
			else
			{
				IntType hobj = history_set(self, ID_action_project_video_template);
				ObjType(obj_history, hobj)->oldtemplate = sVar(project_video_template);
				ObjType(obj_history, hobj)->newtemplate = argument0;
				ObjType(obj_history, hobj)->oldwidth = sVar(project_video_width);
				ObjType(obj_history, hobj)->oldheight = sVar(project_video_height);
			}
		
		
		sVar(project_video_template) = argument0;
		if (sVar(project_video_template) > IntType(0))
		{
			sVar(project_video_width) = ObjType(obj_videotemplate, sVar(project_video_template))->width;
			sVar(project_video_height) = ObjType(obj_videotemplate, sVar(project_video_template))->height;
		}
		return 0.0;
	}
	
	RealType action_project_video_width(ScopeAny self, RealType val, VarType add)
	{
		RealType ratio;
		if (sReal(history_undo) > 0)
		{
			sVar(project_video_width) = ObjType(obj_history, global::history_data)->old_width;
			sVar(project_video_height) = ObjType(obj_history, global::history_data)->old_height;
			return IntType(0);
		}
		else
			if (sReal(history_redo) > 0)
				val = ObjType(obj_history, global::history_data)->new_width;
			else
			{
				VarType hobj;
				history_pop(self);
				if (sReal(history_amount) > IntType(0) && ObjType(obj_history, sArr(history).Value(IntType(0)))->script == ID_action_project_video_width)
					hobj = sArr(history).Value(IntType(0));
				else
				{
					history_push(self);
					hobj = new_history(ID_action_project_video_width);
					ObjType(obj_history, hobj)->old_width = sVar(project_video_width);
					ObjType(obj_history, hobj)->old_height = sVar(project_video_height);
				}
				
				ObjType(obj_history, hobj)->new_width = sVar(project_video_width) * add + val;
				sArr(history)[IntType(0)] = hobj;
			}
		
		
		ratio = (RealType)sVar(project_video_width) / sVar(project_video_height);
		sVar(project_video_width) = sVar(project_video_width) * add + val;
		if (sVar(project_video_keep_aspect_ratio) > 0)
			sVar(project_video_height) = max({ IntType(1), round((RealType)sVar(project_video_width) / ratio) });
		return 0.0;
	}
	
	void action_recent_pin(VarType item)
	{
		idVar(item, pinned) = !(idVar(item, pinned) > 0);
		global::_app->recent_list_update = true;
	}
	
	void action_recent_remove(VarType item)
	{
		idBool(item, remove) = true;
		global::_app->recent_list_update = true;
	}
	
	void action_recent_sort(ScopeAny self, VarType sort)
	{
		sVar(recent_sort_mode) = sort;
		recent_update(self);
	}
	
	RealType action_load_render_settings(ScopeAny self, StringType fn)
	{
		IntType map = project_load_start(fn);
		if (map == null_)
			return IntType(0);
		project_load_render(self, DsMap(map).Value(/*"render"*/ STR(9)));
		ds_map_destroy(map);
		return 0.0;
	}
	
	RealType action_restore_controls(ScopeAny self)
	{
		if (!question(text_get({ /*"questionrestorecontrols"*/ STR(15) })))
			return IntType(0);
		keybinds_reset_default(self);
		sReal(setting_move_speed) = IntType(1);
		sReal(setting_look_sensitivity) = IntType(1);
		sReal(setting_fast_modifier) = IntType(3);
		sReal(setting_slow_modifier) = 0.25;
		return 0.0;
	}
	
	RealType action_res_export(ScopeAny self)
	{
		if (idVar(global::res_edit, type) == e_res_type_PACK)
		{
			VarType fn = file_dialog_save_image(filename_get_valid(idVar(global::res_edit, display_name)));
			if (fn == /*""*/ STR(0))
				return IntType(0);
			fn = filename_new_ext(fn, /*".png"*/ STR(6));
			texture_export(ObjType(obj_preview, sInt(res_preview))->texture, fn);
		}
		else
		{
			StringType ext;
			VarType fn;
			ext = filename_ext(idVar(global::res_edit, filename));
			fn = file_dialog_save_resource(filename_get_valid(idVar(global::res_edit, display_name)), ext);
			if (fn == /*""*/ STR(0))
				return IntType(0);
			fn = filename_new_ext(fn, ext);
			global::load_folder = sStr(project_folder);
			global::save_folder = filename_dir(fn);
			withOne (Object, global::res_edit, self->id)
			{
				res_save(self);
				file_rename_lib(global::save_folder + /*"/"*/ STR(16) + sVar(filename), fn);
			}
			
		}
		
		return 0.0;
	}
	
	void action_res_font_load(ScopeAny self, VarType fn)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_destroy_loaded(self);
			
		}
		else
		{
			IntType hobj, res;
			if (sReal(history_redo) > 0)
				fn = ObjType(obj_history, global::history_data)->filename;
			else
				hobj = history_set(self, ID_action_res_font_load);
			
			res = new_res(self, fn, e_res_type_FONT);
			withOne (obj_resource, res, self->id)
			{
				self->loaded = true;
				res_load(ScopeAny(self));
			}
			
			if (!(sReal(history_redo) > 0) && !ObjType(obj_resource, res)->replaced)
			{
				withOne (obj_history, hobj, self->id)
				{
					self->filename = fn;
					history_save_loaded(self);
				}
				
			}
		}
		
		project_reset_loaded(self);
	}
	
	void action_res_image_load(ScopeAny self, VarType fn, VarType type)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_destroy_loaded(self);
			
		}
		else
		{
			VarType itemsheetsize;
			IntType hobj, res;
			if (sReal(history_redo) > 0)
			{
				fn = ObjType(obj_history, global::history_data)->filename;
				type = ObjType(obj_history, global::history_data)->type;
				if (type == e_res_type_ITEM_SHEET)
					itemsheetsize = ObjType(obj_history, global::history_data)->item_sheet_size;
			}
			else
			{
				hobj = history_set(self, ID_action_res_image_load);
				if (type == e_res_type_ITEM_SHEET)
				{
					if (ObjType(obj_popup, sInt(popup_importitemsheet))->is_sheet)
						itemsheetsize = ObjType(obj_popup, sInt(popup_importitemsheet))->sheet_size;
					else
						type = e_res_type_TEXTURE;
					
				}
			}
			
			res = new_res(self, fn, type);
			withOne (obj_resource, res, self->id)
			{
				self->loaded = true;
				if (type == e_res_type_ITEM_SHEET)
					self->item_sheet_size = itemsheetsize;
				res_load(ScopeAny(self));
			}
			
			if (!(sReal(history_redo) > 0) && !ObjType(obj_resource, res)->replaced)
			{
				withOne (obj_history, hobj, self->id)
				{
					self->filename = fn;
					ObjType(obj_history, self->id)->type = type;
					ObjType(obj_history, self->id)->item_sheet_size = ObjType(obj_resource, res)->item_sheet_size;
					history_save_loaded(self);
				}
				
			}
		}
		
		project_reset_loaded(self);
	}
	
	IntType action_res_import_world(ScopeAny self, VarType name, VarType regionsdir, VarType boxstart, VarType boxend, VarType filtermode, VarType filterarray)
	{
		IntType res = null_;
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_destroy_loaded(self);
			
		}
		else
		{
			IntType hobj = null_;
			if (sReal(history_redo) > 0)
			{
				name = ObjType(obj_history, global::history_data)->name;
				regionsdir = ObjType(obj_history, global::history_data)->regionsdir;
				boxstart = ObjType(obj_history, global::history_data)->boxstart;
				boxend = ObjType(obj_history, global::history_data)->boxend;
				filtermode = ObjType(obj_history, global::history_data)->filtermode;
				filterarray = ObjType(obj_history, global::history_data)->filterarray;
			}
			else
				hobj = history_set(self, ID_action_res_import_world);
			
			IntType num = IntType(1);
			withAll (obj_resource, self->id)
				if (self->type == e_res_type_FROM_WORLD && self->world_regions_dir == regionsdir)
					num++;
			
			VarType fn = filename_get_valid(name) + (num > IntType(1) ? (/*" "*/ STR(17) + string(num)) : /*""*/ STR(0));
			res = new_res(self, fn, e_res_type_FROM_WORLD);
			withOne (obj_resource, res, self->id)
			{
				self->loaded = true;
				self->world_regions_dir = regionsdir;
				self->world_box_start = boxstart;
				self->world_box_end = boxend;
				self->world_filter_mode = filtermode;
				self->world_filter_array = filterarray;
				res_load(ScopeAny(self));
			}
			
			withOne (obj_history, hobj, self->id)
			{
				self->name = name;
				self->regionsdir = regionsdir;
				self->boxstart = boxstart;
				self->boxend = boxend;
				self->filtermode = filtermode;
				self->filterarray = filterarray;
				history_save_loaded(self);
			}
			
		}
		
		project_reset_loaded(self);
		return res;
	}
	
	void action_res_item_sheet_size(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_res_item_sheet_size, idVar(global::res_edit, item_sheet_size).Value(global::axis_edit), idVar(global::res_edit, item_sheet_size).Value(global::axis_edit) * add + val, true);
		withOne (Object, global::res_edit, self->id)
			sVar(item_sheet_size)[global::axis_edit] = sVar(item_sheet_size).Value(global::axis_edit) * add + val;
		
		withAll (obj_template, self->id)
			if (self->item_tex == global::res_edit)
				render_generate_item(ScopeAny(self));
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_res_list(ScopeAny self, VarType res)
	{
		action_tl_play_break(self);
		global::res_edit = res;
		ObjType(obj_preview, ObjType(obj_category, ObjType(obj_tab, sInt(properties))->resources)->preview)->select = res;
		ObjType(obj_preview, ObjType(obj_category, ObjType(obj_tab, sInt(properties))->resources)->preview)->update = true;
	}
	
	void action_res_material_format(ScopeAny self, VarType format)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_res_material_format, idVar(global::res_edit, material_format), format, true);
		withOne (Object, global::res_edit, self->id)
			sVar(material_format) = format;
		
	}
	
	void action_res_model_load(ScopeAny self, VarType fn)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_destroy_loaded(self);
			
		}
		else
		{
			IntType hobj, temp;
			if (sReal(history_redo) > 0)
				fn = ObjType(obj_history, global::history_data)->filename;
			else
				hobj = history_set(self, ID_action_res_model_load);
			
			IntType res = new_res(self, fn, e_res_type_MODEL);
			ObjType(obj_resource, res)->loaded = !ObjType(obj_resource, res)->replaced;
			if (ObjType(obj_resource, res)->replaced)
			{
				global::res_edit = res;
				action_res_replace(self, { fn });
			}
			else
				withOne (obj_resource, res, self->id)
					res_load(ScopeAny(self));
			
			
			temp = (new obj_template)->id;
			withOne (obj_template, temp, self->id)
			{
				self->loaded = true;
				self->type = e_temp_type_MODEL;
				self->model_tex = null_;
				self->model_tex_material = null_;
				self->model_tex_normal = null_;
				self->model = res;
				idInt(self->model, count)++;
				temp_update(ScopeAny(self));
				withOne (obj_timeline, temp_animate(ScopeAny(self)), self->id)
				{
					self->loaded = true;
					for (IntType p = IntType(0); p < ds_list_size(self->part_list); p++)
						idBool(DsList(self->part_list)[p], loaded) = true;
				}
				
				sortlist_add(idInt(self.otherId, lib_list), self->id);
			}
			
			if (!(sReal(history_redo) > 0))
			{
				withOne (obj_history, hobj, self->id)
				{
					self->filename = fn;
					history_save_loaded(self);
				}
				
			}
		}
		
		project_reset_loaded(self);
		tl_update_length();
		tl_update_list(self);
		tl_update_matrix(self);
	}
	
	void action_res_pack_load(ScopeAny self, VarType fn)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_destroy_loaded(self);
			
		}
		else
		{
			IntType res;
			if (sReal(history_redo) > 0)
			{
				fn = ObjType(obj_history, global::history_data)->filename;
				res = new_res(self, fn, e_res_type_PACK);
			}
			else
				res = new_res(self, fn, e_res_type_PACK_UNZIPPED);
			
			ObjType(obj_resource, res)->loaded = true;
			withOne (obj_resource, res, self->id)
				res_load(ScopeAny(self));
			
			if (!(sReal(history_redo) > 0) && !ObjType(obj_resource, res)->replaced)
			{
				withOne (obj_history, history_set(self, ID_action_res_pack_load), self->id)
				{
					self->filename = fn;
					history_save_loaded(self);
				}
				
			}
		}
		
		project_reset_loaded(self);
	}
	
	void action_res_preview_pack_block_sheet_ani(ScopeAny self, VarType ani)
	{
		ObjType(obj_preview, sInt(res_preview))->pack_block_sheet_ani = ani;
		ObjType(obj_preview, sInt(res_preview))->update = true;
		ObjType(obj_preview, sInt(res_preview))->reset_view = true;
	}
	
	void action_res_preview_pack_colormap(ScopeAny self, VarType colormap)
	{
		ObjType(obj_preview, sInt(res_preview))->pack_colormap = colormap;
		ObjType(obj_preview, sInt(res_preview))->update = true;
		ObjType(obj_preview, sInt(res_preview))->reset_view = true;
	}
	
	void action_res_preview_pack_image(ScopeAny self, VarType image)
	{
		ObjType(obj_preview, sInt(res_preview))->pack_image = image.Str();
		ObjType(obj_preview, sInt(res_preview))->update = true;
		ObjType(obj_preview, sInt(res_preview))->reset_view = true;
	}
	
	void action_res_preview_pack_image_material(ScopeAny self, VarType material)
	{
		ObjType(obj_preview, sInt(res_preview))->pack_image_material = material.Str();
		ObjType(obj_preview, sInt(res_preview))->update = true;
	}
	
	void action_res_preview_pack_model_texture(ScopeAny self, VarType texture)
	{
		ObjType(obj_preview, sInt(res_preview))->pack_model_texture = texture.Str();
		ObjType(obj_preview, sInt(res_preview))->update = true;
		ObjType(obj_preview, sInt(res_preview))->reset_view = true;
	}
	
	void action_res_preview_pack_particles(ScopeAny self, VarType particle)
	{
		ObjType(obj_preview, sInt(res_preview))->pack_particles = particle;
		ObjType(obj_preview, sInt(res_preview))->update = true;
		ObjType(obj_preview, sInt(res_preview))->reset_view = true;
	}
	
	void action_res_reload(ScopeAny self)
	{
		IntType hobj = null_;
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			global::load_folder = sStr(project_folder);
			global::save_folder = sStr(project_folder);
			withOne (Object, global::res_edit, self->id)
				res_load(self, true);
			
			hobj = history_set(self, ID_action_res_reload);
			withOne (obj_history, hobj, self->id)
			{
				self->part_amount = IntType(0);
				self->part_child_amount = IntType(0);
				history_save_tl_select(ScopeAny(self));
			}
			
			tl_deselect_all();
		}
		withAll (obj_template, self->id)
		{
			if (self->scenery == global::res_edit)
				temp_set_scenery(ScopeAny(self), self->scenery, !(global::_app->history_undo > 0), hobj);
			else
				if (self->item_tex == global::res_edit)
					render_generate_item(ScopeAny(self));
				else
					if (self->model == global::res_edit)
					{
						temp_update_model(ScopeAny(self));
						temp_update_model_timeline_tree(ScopeAny(self), { hobj });
						temp_update_model_shape(ScopeAny(self));
						temp_update_display_name(ScopeAny(self));
					}
					else
						if (self->model_tex == global::res_edit)
							temp_update_model_shape(ScopeAny(self));
				
			
			
		}
		
		if (sReal(history_undo) > 0)
			withOne (obj_history, global::history_data, self->id)
				history_restore_parts(self);
		
		tl_update_length();
		tl_update_list(self);
		tl_update_matrix(self);
		app_update_tl_edit(self);
		ObjType(obj_preview, sInt(lib_preview))->update = true;
		ObjType(obj_preview, sInt(res_preview))->update = true;
		ObjType(obj_preview, sInt(res_preview))->reset_view = true;
	}
	
}
