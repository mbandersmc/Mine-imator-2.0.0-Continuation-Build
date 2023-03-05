/*
	NOTE:
	This file was autogenerated by CppGen, changes may be overwritten and forever lost!
	Modify at your own risk!
	
	[ Generated on 2023.03.04 18:21:23 ]
*/

#include "Scripts.hpp"

namespace CppProject
{
	RealType tl_update_values_ease(Scope<obj_timeline> self, IntType vid)
	{
		VarType oldval, curval, nextval, val;
		oldval = self->value.Value(vid);
		if (self->keyframe_animate)
		{
			curval = self->keyframe_current_values.Value(vid);
			nextval = self->keyframe_next_values.Value(vid);
			if ((oldval == curval) && (oldval == nextval))
				return IntType(0);
			val = tl_value_interpolate(vid, self->keyframe_progress_ease, curval, nextval);
		}
		else
			if (self->keyframe_next > 0)
				val = self->keyframe_next_values.Value(vid);
			else
				val = self->value_default.Value(vid);
		
		
		if (oldval != val)
		{
			self->update_matrix = true;
			self->value[vid] = val;
		}
		return 0.0;
	}
	
	RealType tl_update_values_progress(Scope<obj_timeline> self, VarType markerpos)
	{
		RealType kflength, kfprogress;
		RealType progress = IntType(0);
		if (!(global::_app->timeline_seamless_repeat > 0))
		{
			if (self->keyframe_current > 0 && self->keyframe_next > 0 && self->keyframe_current != self->keyframe_next)
			{
				kflength = (markerpos - ObjType(obj_keyframe, self->keyframe_current)->position);
				kfprogress = (ObjType(obj_keyframe, self->keyframe_next)->position - ObjType(obj_keyframe, self->keyframe_current)->position);
				progress = kflength / kfprogress;
			}
			return progress;
		}
		VarType loopstart, loopend;
		BoolType seamlessloop;
		if (global::_app->timeline_region_start != null_)
		{
			loopstart = global::_app->timeline_region_start;
			loopend = global::_app->timeline_region_end;
		}
		else
		{
			loopstart = IntType(0);
			loopend = global::_app->timeline_length;
		}
		
		seamlessloop = (global::_app->timeline_seamless_repeat > 0 && markerpos >= loopstart && markerpos < loopend);
		IntType kflistsize;
		RealType lastkf;
		BoolType loopnext, loopprev;
		kflistsize = ds_list_size(self->keyframe_list);
		lastkf = kflistsize - IntType(1);
		loopnext = false;
		loopprev = false;
		if (self->keyframe_next == self->keyframe_current || ObjType(obj_keyframe, self->keyframe_next)->position > loopend)
		{
			for (IntType k = IntType(0); k < kflistsize; k++)
			{
				IntType kf = DsList(self->keyframe_list).Value(k);
				if (ObjType(obj_keyframe, kf)->position < loopstart || ObjType(obj_keyframe, kf)->position > loopend)
					continue;
				else
				{
					if (ObjType(obj_keyframe, kf)->position < ObjType(obj_keyframe, self->keyframe_next)->position)
						self->keyframe_next = kf;
				}
				
			}
			loopnext = true;
		}
		else
			if (self->keyframe_current == null_ || ObjType(obj_keyframe, self->keyframe_current)->position < loopstart)
			{
				for (IntType k = IntType(0); k < kflistsize; k++)
				{
					IntType kf = DsList(self->keyframe_list).Value(k);
					if (ObjType(obj_keyframe, kf)->position < loopstart || ObjType(obj_keyframe, kf)->position > loopend)
						continue;
					else
					{
						if (self->keyframe_current == null_ || ObjType(obj_keyframe, kf)->position > ObjType(obj_keyframe, self->keyframe_current)->position)
							self->keyframe_current = kf;
					}
					
				}
				loopprev = true;
			}
		
		RealType regionsize = loopend - loopstart;
		if (self->keyframe_current > 0 && self->keyframe_next > 0 && self->keyframe_current != self->keyframe_next)
		{
			RealType range = ObjType(obj_keyframe, self->keyframe_next)->position - ObjType(obj_keyframe, self->keyframe_current)->position;
			if (loopnext)
				range += regionsize;
			else
				if (loopprev)
				{
					markerpos += regionsize;
					range += regionsize;
				}
			
			if (range != IntType(0))
				progress = (markerpos - ObjType(obj_keyframe, self->keyframe_current)->position) / range;
		}
		else
			self->keyframe_current = self->keyframe_next;
		
		return progress;
	}
	
	RealType tl_update_value_types(ScopeAny self)
	{
		for (IntType v = IntType(0); v < e_value_type_amount; v++)
			sArr(value_type)[v] = false;
		if (sVar(type) == e_tl_type_AUDIO)
		{
			sArr(value_type)[e_value_type_SOUND] = true;
			sArr(value_type)[e_value_type_AUDIO] = true;
			return IntType(0);
		}
		sArr(value_type)[e_value_type_KEYFRAME] = true;
		if (sVar(type) == e_tl_type_BACKGROUND)
		{
			sArr(value_type)[e_value_type_BACKGROUND] = true;
			return IntType(0);
		}
		if (sVar(type) == e_tl_type_PATH)
			sArr(value_type)[e_value_type_PATH] = true;
		if (sVar(type) == e_tl_type_PATH_POINT)
		{
			sArr(value_type)[e_value_type_TRANSFORM] = true;
			sArr(value_type)[e_value_type_TRANSFORM_POS] = true;
			sArr(value_type)[e_value_type_TRANSFORM_PATH_POINT] = true;
			sArr(value_type)[e_value_type_HIERARCHY] = true;
			return IntType(0);
		}
		sArr(value_type)[e_value_type_HIERARCHY] = true;
		sArr(value_type)[e_value_type_APPEARANCE] = true;
		if (sVar(type) == e_tl_type_CAMERA)
			sArr(value_type)[e_value_type_APPEARANCE] = false;
		sArr(value_type)[e_value_type_TRANSFORM] = true;
		sArr(value_type)[e_value_type_TRANSFORM_POS] = true;
		if (sVar(type) != e_tl_type_POINT_LIGHT)
			sArr(value_type)[e_value_type_TRANSFORM_ROT] = true;
		if (sVar(type) != e_tl_type_PARTICLE_SPAWNER && sVar(type) != e_tl_type_CAMERA && sVar(type) != e_tl_type_POINT_LIGHT && sVar(type) != e_tl_type_SPOT_LIGHT)
			sArr(value_type)[e_value_type_TRANSFORM_SCA] = true;
		if (sVar(type) == e_tl_type_BODYPART && sVar(model_part) != null_ && idInt(sVar(model_part), bend_part) != null_)
			sArr(value_type)[e_value_type_TRANSFORM_BEND] = true;
		if (sVar(type) != e_tl_type_POINT_LIGHT && sVar(type) != e_tl_type_SPOT_LIGHT)
			sArr(value_type)[e_value_type_MATERIAL_COLOR] = true;
		if (sVar(type) == e_tl_type_PARTICLE_SPAWNER)
			sArr(value_type)[e_value_type_PARTICLES] = true;
		if (sVar(type) == e_tl_type_POINT_LIGHT || sVar(type) == e_tl_type_SPOT_LIGHT)
			sArr(value_type)[e_value_type_LIGHT] = true;
		if (sVar(type) == e_tl_type_SPOT_LIGHT)
			sArr(value_type)[e_value_type_SPOTLIGHT] = true;
		if (sVar(type) == e_tl_type_CAMERA)
			sArr(value_type)[e_value_type_CAMERA] = true;
		if (sVar(type) != e_tl_type_CAMERA && sVar(type) != e_tl_type_POINT_LIGHT && sVar(type) != e_tl_type_SPOT_LIGHT && sVar(type) != e_tl_type_FOLDER)
			sArr(value_type)[e_value_type_MATERIAL_TEXTURE] = true;
		if (sVar(type) != e_tl_type_POINT_LIGHT && sVar(type) != e_tl_type_SPOT_LIGHT)
			sArr(value_type)[e_value_type_MATERIAL_COLOR] = true;
		if (sVar(type) != e_tl_type_CAMERA && sVar(type) != e_tl_type_POINT_LIGHT && sVar(type) != e_tl_type_SPOT_LIGHT)
			sArr(value_type)[e_value_type_MATERIAL_SURFACE] = true;
		if (sVar(type) != e_tl_type_CAMERA && sVar(type) != e_tl_type_POINT_LIGHT && sVar(type) != e_tl_type_SPOT_LIGHT)
			sArr(value_type)[e_value_type_MATERIAL_SUBSURFACE] = true;
		if (sVar(type) == e_tl_type_TEXT)
			sArr(value_type)[e_value_type_TEXT] = true;
		if (sVar(type) == e_tl_type_ITEM)
			sArr(value_type)[e_value_type_ITEM] = true;
		sArr(value_type)[e_value_type_ROT_POINT] = true;
		if (sVar(type) == e_tl_type_PARTICLE_SPAWNER || sVar(type) == e_tl_type_CAMERA || sVar(type) == e_tl_type_POINT_LIGHT || sVar(type) == e_tl_type_SPOT_LIGHT)
			sArr(value_type)[e_value_type_ROT_POINT] = false;
		sArr(value_type)[e_value_type_MATERIAL] = (sArr(value_type).Value(e_value_type_MATERIAL_TEXTURE) || sArr(value_type).Value(e_value_type_MATERIAL_COLOR) || sArr(value_type).Value(e_value_type_MATERIAL_SURFACE) || sArr(value_type).Value(e_value_type_MATERIAL_SUBSURFACE));
		return 0.0;
	}
	
	void tl_update_value_types_show(Scope<obj_timeline> self)
	{
		self->value_type_show[e_value_type_TRANSFORM] = ObjType(obj_category, ObjType(obj_tab, global::_app->frame_editor)->transform)->show;
		self->value_type_show[e_value_type_CAMERA] = idReal(ObjType(obj_tab, global::_app->frame_editor)->camera, show);
	}
	
	VarType tl_value_clamp(VarType vid, VarType val)
	{
		if (global::_app->setting_unlimited_values > 0)
		{
			if (tl_value_is_string(vid) || tl_value_is_bool(vid) || tl_value_is_obj(vid))
				return val;
			else
				if (tl_value_is_color(vid))
					return clamp(val, c_black, c_white);
				else
					if ((vid == e_value_SCA_X || vid == e_value_SCA_Y || vid == e_value_SCA_Z) && val == IntType(0))
						return 0.0001;
					else
						return clamp(val, -no_limit, no_limit);
				
			
			
		}
		switch ((IntType)vid)
		{
			case e_value_POS_X:
			case e_value_POS_Y:
			case e_value_POS_Z:
			{
				return clamp(val, -global::_app->project_render_distance, global::_app->project_render_distance);
			}
			case e_value_SCA_X:
			case e_value_SCA_Y:
			case e_value_SCA_Z:
			{
				return max({ val, 0.0001 });
			}
			case e_value_ALPHA:
			case e_value_MIX_PERCENT:
			case e_value_METALLIC:
			case e_value_ROUGHNESS:
			case e_value_SUBSURFACE_RADIUS_RED:
			case e_value_SUBSURFACE_RADIUS_GREEN:
			case e_value_SUBSURFACE_RADIUS_BLUE:
			case e_value_WIND_INFLUENCE:
			case e_value_CAM_BLOOM_THRESHOLD:
			case e_value_CAM_VIGNETTE_RADIUS:
			case e_value_CAM_VIGNETTE_SOFTNESS:
			case e_value_CAM_VIGNETTE_STRENGTH:
			{
				return clamp(val, IntType(0), IntType(1));
			}
			case e_value_RGB_ADD:
			case e_value_RGB_SUB:
			case e_value_RGB_MUL:
			case e_value_HSB_ADD:
			case e_value_HSB_SUB:
			case e_value_HSB_MUL:
			case e_value_MIX_COLOR:
			case e_value_SUBSURFACE_COLOR:
			case e_value_GLOW_COLOR:
			case e_value_LIGHT_COLOR:
			case e_value_CAM_BLOOM_BLEND:
			case e_value_CAM_COLOR_BURN:
			case e_value_CAM_VIGNETTE_COLOR:
			case e_value_BG_SKY_COLOR:
			case e_value_BG_SKY_CLOUDS_COLOR:
			case e_value_BG_SUNLIGHT_COLOR:
			case e_value_BG_AMBIENT_COLOR:
			case e_value_BG_NIGHT_COLOR:
			case e_value_BG_GRASS_COLOR:
			case e_value_BG_FOLIAGE_COLOR:
			case e_value_BG_WATER_COLOR:
			case e_value_BG_LEAVES_OAK_COLOR:
			case e_value_BG_LEAVES_SPRUCE_COLOR:
			case e_value_BG_LEAVES_BIRCH_COLOR:
			case e_value_BG_LEAVES_JUNGLE_COLOR:
			case e_value_BG_LEAVES_ACACIA_COLOR:
			case e_value_BG_LEAVES_DARK_OAK_COLOR:
			case e_value_BG_LEAVES_MANGROVE_COLOR:
			case e_value_BG_FOG_COLOR:
			{
				return clamp(val, c_black, c_white);
			}
			case e_value_BEND_ANGLE_X:
			case e_value_BEND_ANGLE_Y:
			case e_value_BEND_ANGLE_Z:
			{
				return clamp(val, -IntType(180), IntType(180));
			}
			case e_value_CAM_FOV:
			{
				return clamp(val, IntType(1), IntType(170));
			}
			case e_value_CAM_BLADE_AMOUNT:
			{
				return clamp(val, IntType(0), IntType(32));
			}
			case e_value_CAM_BLADE_ANGLE:
			{
				return clamp(val, IntType(0), IntType(360));
			}
			case e_value_CAM_ROTATE_DISTANCE:
			{
				return max({ IntType(1), val });
			}
			case e_value_CAM_ROTATE_ANGLE_Z:
			{
				return clamp(val, -89.9, 89.9);
			}
			case e_value_CAM_EXPOSURE:
			case e_value_CAM_GAMMA:
			case e_value_BG_SUNLIGHT_STRENGTH:
			case e_value_LIGHT_STRENGTH:
			case e_value_EMISSIVE:
			case e_value_SUBSURFACE:
			case e_value_CAM_SHAKE_STRENGTH_X:
			case e_value_CAM_SHAKE_STRENGTH_Y:
			case e_value_CAM_SHAKE_STRENGTH_Z:
			case e_value_CAM_SHAKE_SPEED_X:
			case e_value_CAM_SHAKE_SPEED_Y:
			case e_value_CAM_SHAKE_SPEED_Z:
			case e_value_CAM_CA_RED_OFFSET:
			case e_value_CAM_CA_GREEN_OFFSET:
			case e_value_CAM_CA_BLUE_OFFSET:
			{
				return clamp(val, IntType(0), no_limit);
			}
			case e_value_CAM_WIDTH:
			case e_value_CAM_HEIGHT:
			{
				return max({ IntType(1), val });
			}
			case e_value_BG_SKY_MOON_PHASE:
			{
				return clamp(val, IntType(0), IntType(7));
			}
			case e_value_BG_FOG_DISTANCE:
			{
				return clamp(val, IntType(10), global::_app->project_render_distance);
			}
			case e_value_BG_FOG_SIZE:
			{
				return clamp(val, IntType(10), global::_app->project_render_distance);
			}
			case e_value_BG_FOG_HEIGHT:
			{
				return clamp(val, IntType(10), IntType(2000));
			}
			case e_value_BG_WIND_SPEED:
			{
				return clamp(val, IntType(0), IntType(1));
			}
			case e_value_BG_WIND_STRENGTH:
			{
				return clamp(val, IntType(0), IntType(8));
			}
			case e_value_BG_TEXTURE_ANI_SPEED:
			{
				return max({ val, IntType(0) });
			}
			case e_value_SOUND_VOLUME:
			{
				return clamp(val, IntType(0), IntType(1));
			}
			case e_value_SOUND_START:
			{
				return max({ val, IntType(0) });
			}
			case e_value_TEXT:
			case e_value_TEXT_HALIGN:
			case e_value_TEXT_VALIGN:
			case e_value_BG_BIOME:
			case e_value_TRANSITION:
			{
				return val;
			}
		}
		
		return clamp(val, -no_limit, no_limit);
	}
	
	VarType tl_value_default(VarType valueid)
	{
		switch ((IntType)valueid)
		{
			case e_value_SCA_X:
			case e_value_SCA_Y:
			case e_value_SCA_Z:
			{
				return IntType(1);
			}
			case e_value_ALPHA:
			{
				return IntType(1);
			}
			case e_value_ROUGHNESS:
			{
				return IntType(1);
			}
			case e_value_SUBSURFACE:
			{
				return IntType(0);
			}
			case e_value_SUBSURFACE_RADIUS_RED:
			case e_value_SUBSURFACE_RADIUS_GREEN:
			case e_value_SUBSURFACE_RADIUS_BLUE:
			{
				return IntType(1);
			}
			case e_value_WIND_INFLUENCE:
			{
				return IntType(1);
			}
			case e_value_GLOW_COLOR:
			case e_value_RGB_MUL:
			case e_value_HSB_MUL:
			case e_value_SUBSURFACE_COLOR:
			{
				return c_white;
			}
			case e_value_SPAWN:
			{
				return true;
			}
			case e_value_FREEZE:
			{
				return false;
			}
			case e_value_CLEAR:
			{
				return false;
			}
			case e_value_CUSTOM_SEED:
			{
				return false;
			}
			case e_value_SEED:
			{
				return ceil(random(32000.0));
			}
			case e_value_FORCE:
			{
				return IntType(1);
			}
			case e_value_FORCE_DIRECTIONAL:
			{
				return IntType(0);
			}
			case e_value_FORCE_VORTEX:
			{
				return IntType(0);
			}
			case e_value_LIGHT_COLOR:
			{
				return c_white;
			}
			case e_value_LIGHT_STRENGTH:
			case e_value_LIGHT_SPECULAR_STRENGTH:
			{
				return IntType(1);
			}
			case e_value_LIGHT_SIZE:
			{
				return IntType(2);
			}
			case e_value_LIGHT_RANGE:
			{
				return IntType(250);
			}
			case e_value_LIGHT_FADE_SIZE:
			{
				return 0.5;
			}
			case e_value_LIGHT_SPOT_RADIUS:
			{
				return IntType(50);
			}
			case e_value_LIGHT_SPOT_SHARPNESS:
			{
				return 0.5;
			}
			case e_value_CAM_FOV:
			{
				return IntType(45);
			}
			case e_value_CAM_EXPOSURE:
			{
				return IntType(1);
			}
			case e_value_CAM_GAMMA:
			{
				return 2.2;
			}
			case e_value_CAM_BLADE_AMOUNT:
			{
				return IntType(0);
			}
			case e_value_CAM_BLADE_ANGLE:
			{
				return IntType(0);
			}
			case e_value_CAM_ROTATE_DISTANCE:
			{
				return IntType(100);
			}
			case e_value_CAM_SHAKE_MODE:
			case e_value_CAM_SHAKE_STRENGTH_X:
			case e_value_CAM_SHAKE_STRENGTH_Y:
			case e_value_CAM_SHAKE_STRENGTH_Z:
			case e_value_CAM_SHAKE_SPEED_X:
			case e_value_CAM_SHAKE_SPEED_Y:
			case e_value_CAM_SHAKE_SPEED_Z:
			{
				return IntType(1);
			}
			case e_value_CAM_DOF_RANGE:
			{
				return IntType(200);
			}
			case e_value_CAM_DOF_FADE_SIZE:
			{
				return IntType(100);
			}
			case e_value_CAM_DOF_BLUR_SIZE:
			{
				return .01;
			}
			case e_value_CAM_DOF_BLUR_RATIO:
			{
				return IntType(0);
			}
			case e_value_CAM_DOF_BIAS:
			{
				return IntType(0);
			}
			case e_value_CAM_DOF_THRESHOLD:
			{
				return IntType(0);
			}
			case e_value_CAM_DOF_GAIN:
			{
				return IntType(0);
			}
			case e_value_CAM_DOF_FRINGE_RED:
			case e_value_CAM_DOF_FRINGE_GREEN:
			case e_value_CAM_DOF_FRINGE_BLUE:
			{
				return IntType(1);
			}
			case e_value_CAM_DOF_FRINGE_ANGLE_RED:
			{
				return IntType(90);
			}
			case e_value_CAM_DOF_FRINGE_ANGLE_GREEN:
			{
				return -IntType(135);
			}
			case e_value_CAM_DOF_FRINGE_ANGLE_BLUE:
			{
				return -IntType(45);
			}
			case e_value_CAM_BLOOM_THRESHOLD:
			{
				return .85;
			}
			case e_value_CAM_BLOOM_INTENSITY:
			{
				return .4;
			}
			case e_value_CAM_BLOOM_RADIUS:
			{
				return IntType(1);
			}
			case e_value_CAM_BLOOM_RATIO:
			{
				return IntType(0);
			}
			case e_value_CAM_BLOOM_BLEND:
			{
				return c_white;
			}
			case e_value_CAM_LENS_DIRT_BLOOM:
			{
				return true;
			}
			case e_value_CAM_LENS_DIRT_GLOW:
			{
				return true;
			}
			case e_value_CAM_LENS_DIRT_RADIUS:
			{
				return .5;
			}
			case e_value_CAM_LENS_DIRT_INTENSITY:
			{
				return .8;
			}
			case e_value_CAM_LENS_DIRT_POWER:
			{
				return 1.5;
			}
			case e_value_CAM_COLOR_CORRECTION:
			{
				return false;
			}
			case e_value_CAM_CONTRAST:
			{
				return IntType(0);
			}
			case e_value_CAM_BRIGHTNESS:
			{
				return IntType(0);
			}
			case e_value_CAM_SATURATION:
			{
				return IntType(1);
			}
			case e_value_CAM_VIBRANCE:
			{
				return IntType(0);
			}
			case e_value_CAM_COLOR_BURN:
			{
				return c_white;
			}
			case e_value_CAM_GRAIN_STRENGTH:
			{
				return .10;
			}
			case e_value_CAM_GRAIN_SATURATION:
			{
				return .10;
			}
			case e_value_CAM_GRAIN_SIZE:
			{
				return IntType(1);
			}
			case e_value_CAM_VIGNETTE_RADIUS:
			{
				return IntType(1);
			}
			case e_value_CAM_VIGNETTE_SOFTNESS:
			{
				return 0.5;
			}
			case e_value_CAM_VIGNETTE_STRENGTH:
			{
				return IntType(1);
			}
			case e_value_CAM_VIGNETTE_COLOR:
			{
				return c_black;
			}
			case e_value_CAM_CA_BLUR_AMOUNT:
			{
				return 0.05;
			}
			case e_value_CAM_CA_RED_OFFSET:
			{
				return .12;
			}
			case e_value_CAM_CA_GREEN_OFFSET:
			{
				return .08;
			}
			case e_value_CAM_CA_BLUE_OFFSET:
			{
				return .04;
			}
			case e_value_CAM_DISTORT_ZOOM_AMOUNT:
			{
				return IntType(1);
			}
			case e_value_CAM_DISTORT_AMOUNT:
			{
				return .05;
			}
			case e_value_CAM_WIDTH:
			{
				return IntType(1280);
			}
			case e_value_CAM_HEIGHT:
			{
				return IntType(720);
			}
			case e_value_CAM_SIZE_USE_PROJECT:
			{
				return true;
			}
			case e_value_CAM_SIZE_KEEP_ASPECT_RATIO:
			{
				return true;
			}
			case e_value_BG_IMAGE_SHOW:
			{
				return global::_app->background_image_show;
			}
			case e_value_BG_IMAGE_ROTATION:
			{
				return global::_app->background_image_rotation;
			}
			case e_value_BG_SKY_MOON_PHASE:
			{
				return global::_app->background_sky_moon_phase;
			}
			case e_value_BG_SKY_TIME:
			{
				return global::_app->background_sky_time;
			}
			case e_value_BG_SKY_ROTATION:
			{
				return global::_app->background_sky_rotation;
			}
			case e_value_BG_SUNLIGHT_STRENGTH:
			{
				return global::_app->background_sunlight_strength;
			}
			case e_value_BG_SUNLIGHT_ANGLE:
			{
				return global::_app->background_sunlight_angle;
			}
			case e_value_BG_TWILIGHT:
			{
				return global::_app->background_twilight;
			}
			case e_value_BG_SKY_CLOUDS_SHOW:
			{
				return global::_app->background_sky_clouds_show;
			}
			case e_value_BG_SKY_CLOUDS_SPEED:
			{
				return global::_app->background_sky_clouds_speed;
			}
			case e_value_BG_SKY_CLOUDS_HEIGHT:
			{
				return global::_app->background_sky_clouds_height;
			}
			case e_value_BG_SKY_CLOUDS_OFFSET:
			{
				return global::_app->background_sky_clouds_offset;
			}
			case e_value_BG_GROUND_SHOW:
			{
				return global::_app->background_ground_show;
			}
			case e_value_BG_GROUND_SLOT:
			{
				return global::_app->background_ground_slot;
			}
			case e_value_BG_BIOME:
			{
				return global::_app->background_biome;
			}
			case e_value_BG_SKY_COLOR:
			{
				return global::_app->background_sky_color;
			}
			case e_value_BG_SKY_CLOUDS_COLOR:
			{
				return global::_app->background_sky_clouds_color;
			}
			case e_value_BG_SUNLIGHT_COLOR:
			{
				return global::_app->background_sunlight_color;
			}
			case e_value_BG_AMBIENT_COLOR:
			{
				return global::_app->background_ambient_color;
			}
			case e_value_BG_NIGHT_COLOR:
			{
				return global::_app->background_night_color;
			}
			case e_value_BG_GRASS_COLOR:
			{
				return global::_app->background_grass_color;
			}
			case e_value_BG_FOLIAGE_COLOR:
			{
				return global::_app->background_foliage_color;
			}
			case e_value_BG_WATER_COLOR:
			{
				return global::_app->background_water_color;
			}
			case e_value_BG_LEAVES_OAK_COLOR:
			{
				return global::_app->background_leaves_oak_color;
			}
			case e_value_BG_LEAVES_SPRUCE_COLOR:
			{
				return global::_app->background_leaves_spruce_color;
			}
			case e_value_BG_LEAVES_BIRCH_COLOR:
			{
				return global::_app->background_leaves_birch_color;
			}
			case e_value_BG_LEAVES_JUNGLE_COLOR:
			{
				return global::_app->background_leaves_jungle_color;
			}
			case e_value_BG_LEAVES_ACACIA_COLOR:
			{
				return global::_app->background_leaves_acacia_color;
			}
			case e_value_BG_LEAVES_DARK_OAK_COLOR:
			{
				return global::_app->background_leaves_dark_oak_color;
			}
			case e_value_BG_LEAVES_MANGROVE_COLOR:
			{
				return global::_app->background_leaves_mangrove_color;
			}
			case e_value_BG_FOG_SHOW:
			{
				return global::_app->background_fog_show;
			}
			case e_value_BG_FOG_SKY:
			{
				return global::_app->background_fog_sky;
			}
			case e_value_BG_FOG_CUSTOM_COLOR:
			{
				return global::_app->background_fog_color_custom;
			}
			case e_value_BG_FOG_COLOR:
			{
				return global::_app->background_fog_color;
			}
			case e_value_BG_FOG_CUSTOM_OBJECT_COLOR:
			{
				return global::_app->background_fog_custom_object_color;
			}
			case e_value_BG_FOG_OBJECT_COLOR:
			{
				return global::_app->background_fog_object_color;
			}
			case e_value_BG_FOG_DISTANCE:
			{
				return global::_app->background_fog_distance;
			}
			case e_value_BG_FOG_SIZE:
			{
				return global::_app->background_fog_size;
			}
			case e_value_BG_FOG_HEIGHT:
			{
				return global::_app->background_fog_height;
			}
			case e_value_BG_WIND:
			{
				return global::_app->background_wind;
			}
			case e_value_BG_WIND_SPEED:
			{
				return global::_app->background_wind_speed;
			}
			case e_value_BG_WIND_STRENGTH:
			{
				return global::_app->background_wind_strength;
			}
			case e_value_BG_WIND_DIRECTION:
			{
				return global::_app->background_wind_direction;
			}
			case e_value_BG_WIND_DIRECTIONAL_SPEED:
			{
				return global::_app->background_wind_directional_speed;
			}
			case e_value_BG_WIND_DIRECTIONAL_STRENGTH:
			{
				return global::_app->background_wind_directional_strength;
			}
			case e_value_BG_TEXTURE_ANI_SPEED:
			{
				return global::_app->background_texture_animation_speed;
			}
			case e_value_PATH_OBJ:
			case e_value_IK_TARGET:
			case e_value_IK_TARGET_ANGLE:
			case e_value_ATTRACTOR:
			case e_value_TEXTURE_OBJ:
			case e_value_TEXTURE_MATERIAL_OBJ:
			case e_value_TEXTURE_NORMAL_OBJ:
			case e_value_SOUND_OBJ:
			case e_value_TEXT_FONT:
			{
				return null_;
			}
			case e_value_IK_BLEND:
			{
				return IntType(1);
			}
			case e_value_SOUND_VOLUME:
			{
				return IntType(1);
			}
			case e_value_VISIBLE:
			{
				return true;
			}
			case e_value_TEXT:
			case e_value_ITEM_NAME:
			{
				return /*""*/ STR(0);
			}
			case e_value_PATH_POINT_SCALE:
			{
				return IntType(1);
			}
			case e_value_TEXT_HALIGN:
			case e_value_TEXT_VALIGN:
			{
				return /*"center"*/ STR(1410);
			}
			case e_value_TRANSITION:
			{
				return /*"linear"*/ STR(534);
			}
			case e_value_EASE_IN_Y:
			case e_value_EASE_OUT_X:
			{
				return IntType(0);
			}
			case e_value_EASE_IN_X:
			case e_value_EASE_OUT_Y:
			{
				return IntType(1);
			}
		}
		
		return IntType(0);
	}
	
	VarType tl_value_find_save_id(VarType vid, VarType oldval, VarType newval)
	{
		if (vid == e_value_SOUND_OBJ && oldval != null_)
		{
			IntType obj = save_id_find(oldval);
			if (obj != null_)
				idInt(obj, count)--;
		}
		if (tl_value_is_texture(vid) && newval == /*"none"*/ STR(874))
			newval = IntType(0);
		else
			if (vid == e_value_PATH_OBJ || vid == e_value_ATTRACTOR || vid == e_value_IK_TARGET || vid == e_value_IK_TARGET_ANGLE || tl_value_is_texture(vid) || vid == e_value_SOUND_OBJ || vid == e_value_TEXT_FONT)
				newval = save_id_find(newval);
		
		if (vid == e_value_SOUND_OBJ && newval != null_)
			idInt(newval, count)++;
		return newval;
	}
	
	VarType tl_value_get_save_id(VarType vid, VarType val)
	{
		if (tl_value_is_texture(vid) && val == IntType(0))
			return /*"none"*/ STR(874);
		if (vid == e_value_PATH_OBJ || vid == e_value_ATTRACTOR || vid == e_value_IK_TARGET || vid == e_value_IK_TARGET_ANGLE || tl_value_is_texture(vid) || vid == e_value_SOUND_OBJ || vid == e_value_TEXT_FONT)
			return save_id_get(val);
		return val;
	}
	
	VarType tl_value_interpolate(IntType vid, VarType p, VarType val1, VarType val2)
	{
		switch ((IntType)vid)
		{
			case e_value_RGB_ADD:
			case e_value_RGB_SUB:
			case e_value_RGB_MUL:
			case e_value_HSB_ADD:
			case e_value_HSB_SUB:
			case e_value_HSB_MUL:
			case e_value_MIX_COLOR:
			case e_value_GLOW_COLOR:
			case e_value_SUBSURFACE_COLOR:
			case e_value_LIGHT_COLOR:
			case e_value_CAM_BLOOM_BLEND:
			case e_value_CAM_COLOR_BURN:
			case e_value_CAM_VIGNETTE_COLOR:
			case e_value_BG_SKY_COLOR:
			case e_value_BG_SKY_CLOUDS_COLOR:
			case e_value_BG_SUNLIGHT_COLOR:
			case e_value_BG_AMBIENT_COLOR:
			case e_value_BG_NIGHT_COLOR:
			case e_value_BG_GRASS_COLOR:
			case e_value_BG_FOLIAGE_COLOR:
			case e_value_BG_WATER_COLOR:
			case e_value_BG_LEAVES_OAK_COLOR:
			case e_value_BG_LEAVES_SPRUCE_COLOR:
			case e_value_BG_LEAVES_BIRCH_COLOR:
			case e_value_BG_LEAVES_JUNGLE_COLOR:
			case e_value_BG_LEAVES_ACACIA_COLOR:
			case e_value_BG_LEAVES_DARK_OAK_COLOR:
			case e_value_BG_LEAVES_MANGROVE_COLOR:
			case e_value_BG_FOG_COLOR:
			{
				return merge_color((IntType)(val1), (IntType)(val2), clamp(p, IntType(0), IntType(1)));
			}
			case e_value_BG_FOG_OBJECT_COLOR:
			{
				return merge_color((IntType)(val1), (IntType)(val2), clamp(p, IntType(0), IntType(1)));
			}
			case e_value_CAM_BLADE_AMOUNT:
			case e_value_CAM_WIDTH:
			case e_value_CAM_HEIGHT:
			case e_value_ITEM_SLOT:
			{
				return floor(val1 + p * (val2 - val1));
			}
			case e_value_SPAWN:
			case e_value_FREEZE:
			case e_value_CLEAR:
			case e_value_CUSTOM_SEED:
			case e_value_SEED:
			case e_value_PATH_OBJ:
			case e_value_IK_TARGET:
			case e_value_IK_TARGET_ANGLE:
			case e_value_ATTRACTOR:
			case e_value_CAM_LIGHT_MANAGEMENT:
			case e_value_CAM_TONEMAPPER:
			case e_value_CAM_ROTATE:
			case e_value_CAM_SHAKE:
			case e_value_CAM_SHAKE_MODE:
			case e_value_CAM_DOF:
			case e_value_CAM_DOF_FRINGE:
			case e_value_CAM_BLOOM:
			case e_value_CAM_LENS_DIRT:
			case e_value_CAM_LENS_DIRT_BLOOM:
			case e_value_CAM_LENS_DIRT_GLOW:
			case e_value_CAM_COLOR_CORRECTION:
			case e_value_CAM_GRAIN:
			case e_value_CAM_VIGNETTE:
			case e_value_CAM_CA:
			case e_value_CAM_CA_DISTORT_CHANNELS:
			case e_value_CAM_DISTORT:
			case e_value_CAM_DISTORT_REPEAT:
			case e_value_CAM_SIZE_USE_PROJECT:
			case e_value_CAM_SIZE_KEEP_ASPECT_RATIO:
			case e_value_BG_IMAGE_SHOW:
			case e_value_BG_SKY_MOON_PHASE:
			case e_value_BG_TWILIGHT:
			case e_value_BG_SKY_CLOUDS_SHOW:
			case e_value_BG_GROUND_SHOW:
			case e_value_BG_GROUND_SLOT:
			case e_value_BG_BIOME:
			case e_value_BG_FOG_SHOW:
			case e_value_BG_WIND:
			case e_value_VISIBLE:
			case e_value_TEXTURE_OBJ:
			case e_value_TEXTURE_MATERIAL_OBJ:
			case e_value_TEXTURE_NORMAL_OBJ:
			case e_value_SOUND_OBJ:
			case e_value_SOUND_VOLUME:
			case e_value_SOUND_START:
			case e_value_SOUND_END:
			case e_value_TEXT:
			case e_value_TEXT_FONT:
			case e_value_TEXT_HALIGN:
			case e_value_TEXT_VALIGN:
			case e_value_TEXT_AA:
			case e_value_CUSTOM_ITEM_SLOT:
			case e_value_TRANSITION:
			case e_value_EASE_IN_X:
			case e_value_EASE_IN_Y:
			case e_value_EASE_OUT_X:
			case e_value_EASE_OUT_Y:
			{
				return val1;
			}
		}
		
		return val1 + p * (val2 - val1);
	}
	
}
