/*
	NOTE:
	This file was autogenerated by CppGen, changes may be overwritten and forever lost!
	Modify at your own risk!
	
	[ Generated on 2023.03.24 18:12:29 ]
*/

#include "Scripts.hpp"

namespace CppProject
{
	BoolType sortlist_draw_button(ScopeAny self, StringType name, VarType xx, VarType yy, RealType w, RealType h, BoolType highlight, IntType icon, BoolType isfirst, BoolType islast, BoolType listmouseon)
	{
		BoolType pressed, mouseon;
		RealType wlimit;
		VarType text;
		wlimit = w - IntType(16);
		mouseon = (app_mouse_box(self, xx, yy, w - IntType(5), h) && sBool(content_mouseon) && sInt(mouse_cursor) == cr_default);
		pressed = highlight;
		if (mouseon)
		{
			if (sBool(mouse_left) || sBool(mouse_left_released))
				pressed = true;
			sInt(mouse_cursor) = cr_handpoint;
		}
		if (!isfirst && listmouseon)
			draw_line_ext(xx - IntType(1), yy + IntType(4), xx - IntType(1), yy + h - IntType(4), global::c_text_tertiary, global::a_text_tertiary);
		draw_set_font(sInt(font_label));
		if (icon != null_ && mouseon)
			wlimit -= 28.0;
		wlimit = max({ IntType(0), wlimit });
		text = string_limit(text_get({ name }), wlimit);
		if (icon != null_ && mouseon && wlimit > IntType(28))
			draw_image({ ID_spr_icons, icon, xx + IntType(8) + string_width(text) + IntType(4) + IntType(12), yy + h / 2.0, IntType(1), IntType(1), global::c_text_secondary, global::a_text_secondary });
		if (!islast || isfirst)
		{
			draw_label(self, { text, xx + IntType(8), yy + h / 2.0, fa_left, fa_middle, global::c_text_secondary, global::a_text_secondary });
		}
		else
		{
			RealType textoff;
			if (icon != null_ && mouseon)
				textoff = IntType(28);
			else
				textoff = IntType(0);
			
			draw_label(self, { text, xx + (w - IntType(8)) - textoff, yy + h / 2.0, fa_right, fa_middle, global::c_text_secondary, global::a_text_secondary });
		}
		
		if (mouseon && sBool(mouse_left_released))
		{
			app_mouse_clear(self);
			return true;
		}
		return false;
	}
	
	void sortlist_event_create(Scope<obj_sortlist> self)
	{
		self->list = ds_list_create();
		self->columns = IntType(0);
		self->column_name[IntType(0)] = /*""*/ STR(0);
		self->column_text[IntType(0)] = /*""*/ STR(0);
		self->column_x[IntType(0)] = IntType(0);
		self->column_sort = null_;
		self->sort_asc = false;
		self->search = false;
		self->search_tbx = new_textbox(true, IntType(0), /*""*/ STR(0));
		self->display_list = ds_list_create();
		self->scroll = (new obj_scrollbar)->id;
		self->script = null_;
		self->can_deselect = false;
		self->filter_list = ds_list_create();
	}
	
	RealType sortlist_filters_draw(ScopeAny self)
	{
		IntType typelist, capwid;
		VarType scroll, itemname;
		typelist = null_;
		scroll = IntType(0);
		capwid = IntType(0);
		if (sVar(settings_menu_sortlist) == ObjType(obj_category, ObjType(obj_tab, global::_app->properties)->library)->list)
			typelist = global::temp_type_name_list;
		if (sVar(settings_menu_sortlist) == ObjType(obj_category, ObjType(obj_tab, global::_app->properties)->resources)->list)
			typelist = global::res_type_name_list;
		if (typelist == null_)
			return IntType(0);
		clip_begin(sVar(content_x), sVar(content_y), sVar(settings_menu_w), sVar(settings_menu_h));
		if (ObjType(obj_scrollbar, sInt(settings_menu_scroll))->needed)
			scroll = -ObjType(obj_scrollbar, sInt(settings_menu_scroll))->value;
		else
			scroll = IntType(0);
		
		draw_set_font(sInt(font_label));
		for (IntType i = IntType(0); i < ds_list_size(typelist); i++)
		{
			itemname = DsList(typelist).Value(i);
			if (typelist == global::res_type_name_list)
			{
				if (itemname == /*"packunzipped"*/ STR(525) || itemname == /*"legacyblocksheet"*/ STR(528) || itemname == /*"fromworld"*/ STR(530))
					continue;
			}
			capwid = max({ capwid, string_width(text_get({ /*"type"*/ STR(773) + itemname })) });
			BoolType active = ds_list_find_index(idInt(sVar(settings_menu_sortlist), filter_list), DsList(typelist).Value(i)) != -IntType(1);
			tab_control_checkbox(self);
			if (draw_checkbox(self, /*"type"*/ STR(773) + itemname, sVar(dx), sVar(dy) + scroll, active, null_))
			{
				if (active)
					ds_list_delete_value(idInt(sVar(settings_menu_sortlist), filter_list), DsList(typelist).Value(i));
				else
					ds_list_add({ idInt(sVar(settings_menu_sortlist), filter_list), DsList(typelist).Value(i) });
				
				sortlist_update(self, sVar(settings_menu_sortlist));
			}
			tab_next(self);
		}
		clip_end();
		sVar(settings_menu_w) = (IntType(32) + capwid) + IntType(32) + IntType(24);
		return 0.0;
	}
	
	VarType sortlist_remove(IntType sl, IntType value)
	{
		RealType index = ds_list_find_index(idInt(sl, list), value);
		if (index < IntType(0))
			return null_;
		ds_list_delete(idInt(sl, list), (IntType)(index));
		ds_list_delete(idInt(sl, display_list), ds_list_find_index(idInt(sl, display_list), value));
		index = min({ ds_list_size(idInt(sl, list)) - IntType(1), index });
		if (index < IntType(0))
			return null_;
		return DsList(idInt(sl, list)).Value(index);
	}
	
	void sortlist_update(ScopeAny self, VarType slist)
	{
		ds_list_clear(idInt(slist, display_list));
		if (idInt(slist, column_sort) != null_)
		{
			IntType sortedlist, valuelist;
			sortedlist = ds_list_create();
			valuelist = ds_list_create();
			ds_list_copy(valuelist, idInt(slist, list));
			for (IntType p = IntType(0); p < ds_list_size(valuelist); p++)
				ds_list_add({ sortedlist, string_lower(sortlist_column_get(slist, DsList(valuelist).Value(p), idInt(slist, column_sort))) });
			ds_list_sort(sortedlist, !(idReal(slist, sort_asc) > 0));
			while (ds_list_size(sortedlist) > IntType(0))
			{
				for (IntType p = IntType(0); p < ds_list_size(valuelist); p++)
				{
					VarType val;
					StringType colval;
					val = DsList(valuelist).Value(p);
					colval = string_lower(sortlist_column_get(slist, val, idInt(slist, column_sort)));
					if (DsList(sortedlist).Value(IntType(0)) == colval)
					{
						ds_list_add({ idInt(slist, display_list), val });
						ds_list_delete(valuelist, p);
						ds_list_delete(sortedlist, IntType(0));
						break;
					}
				}
			}
			
			ds_list_destroy(sortedlist);
			ds_list_destroy(valuelist);
		}
		else
			ds_list_copy(idInt(slist, display_list), idInt(slist, list));
		
		StringType check = string_lower(ObjType(obj_textbox, idInt(slist, search_tbx))->text);
		if (idBool(slist, search) && check != /*""*/ STR(0) && (slist != ObjType(obj_bench_settings, sInt(bench_settings))->block_list && slist != ObjType(obj_tab, sInt(template_editor))->block_list))
		{
			for (IntType p = IntType(0); p < ds_list_size(idInt(slist, display_list)); p++)
			{
				VarType val;
				BoolType match;
				val = DsList(idInt(slist, display_list)).Value(p);
				match = false;
				for (IntType c = IntType(0); c < idInt(slist, columns); c++)
				{
					if (string_count(check, string_lower(string(sortlist_column_get(slist, val, c)))) > IntType(0))
					{
						match = true;
						break;
					}
				}
				if (!match)
				{
					ds_list_delete(idInt(slist, display_list), p);
					p--;
				}
			}
		}
		else
			if (idBool(slist, search) && check != /*""*/ STR(0) && (slist == ObjType(obj_bench_settings, sInt(bench_settings))->block_list || slist == ObjType(obj_tab, sInt(template_editor))->block_list))
			{
				for (IntType p = IntType(0); p < ds_list_size(idInt(slist, display_list)); p++)
				{
					VarType baseblock;
					BoolType match;
					baseblock = DsList(idInt(slist, display_list)).Value(p);
					match = false;
					if (sVar(setting_search_variants) > 0)
					{
						VarType blockobj = DsMap(ObjType(obj_minecraft_assets, global::mc_assets)->block_name_map).Value(baseblock);
						BoolType variantmatch = false;
						ArrType statearr = array_copy_1d(ObjType(obj_block, blockobj)->default_state);
						IntType statelen = array_length(VarType::CreateRef(statearr));
						for (IntType i = IntType(0); i < statelen; i += IntType(2))
						{
							VarType state = statearr.Value(i);
							VarType statename = text_get({ /*"blockstate"*/ STR(763) + state });
							IntType statecurrent = DsMap(ObjType(obj_block, blockobj)->states_map).Value(state);
							for (IntType s = IntType(0); s < idReal(statecurrent, value_amount); s++)
							{
								if (string_count(check, string_lower(minecraft_asset_get_name(/*"blockstatevalue"*/ STR(764), idVar(statecurrent, value_name).Value(s)))) > IntType(0))
								{
									variantmatch = true;
									break;
								}
							}
							if (string_count(check, string_lower(statename)) > IntType(0))
								variantmatch = true;
							if (variantmatch)
								break;
						}
						match = variantmatch;
					}
					if (!match && string_count(check, string_lower(minecraft_asset_get_name(/*"block"*/ STR(508), baseblock))) > IntType(0))
						match = true;
					if (!match)
					{
						ds_list_delete(idInt(slist, display_list), p);
						p--;
					}
				}
			}
		
		if (!ds_list_empty(idInt(slist, filter_list)))
		{
			for (IntType p = IntType(0); p < ds_list_size(idInt(slist, display_list)); p++)
			{
				VarType item = DsList(idInt(slist, display_list)).Value(p);
				if (sVar(settings_menu_sortlist) == ObjType(obj_category, ObjType(obj_tab, global::_app->properties)->library)->list)
				{
					if (ds_list_find_index(idInt(slist, filter_list), DsList(global::temp_type_name_list).Value(idVar(item, type))) == -IntType(1))
					{
						ds_list_delete(idInt(slist, display_list), p);
						p--;
					}
				}
				if (sVar(settings_menu_sortlist) == ObjType(obj_category, ObjType(obj_tab, global::_app->properties)->resources)->list)
				{
					if (ds_list_find_index(idInt(slist, filter_list), DsList(global::res_type_name_list).Value(idVar(item, type))) == -IntType(1))
					{
						ds_list_delete(idInt(slist, display_list), p);
						p--;
					}
				}
			}
		}
	}
	
	VarType spline_get_point(RealType t, VarType points, VarType closed, VarType smooth, RealType amount)
	{
		RealType p0, p1, p2, seg, curvet;
		seg = floor(t / 2.0) * IntType(2);
		p0 = seg;
		p1 = p0 + IntType(1);
		p2 = p1 + IntType(1);
		curvet = percent(t, p0, p2);
		if (amount == IntType(0))
			amount = array_length(VarType::CreateRef(points));
		if (closed > 0)
		{
			p0 = mod_fix(p0, amount);
			p1 = mod_fix(p1, amount);
			p2 = mod_fix(p2, amount);
		}
		else
		{
			p0 = max({ IntType(0), min({ p0, amount - IntType(1) }) });
			p1 = max({ IntType(0), min({ p1, amount - IntType(1) }) });
			p2 = max({ IntType(0), min({ p2, amount - IntType(1) }) });
		}
		
		if (amount == array_length(VarType::CreateRef(points)))
			curvet = percent(t, p0, p2);
		if (!(closed > 0) && (t <= IntType(0) || t >= amount - IntType(1)))
		{
			RealType i;
			VarType point;
			VecType pos;
			if (t <= IntType(0))
			{
				i = IntType(0);
				pos = vec3_add(points.Value(i), vec3_mul(vec3_normalize(vec3_sub(points.Value(i), points.Value(i + IntType(1)))), abs(t)));
			}
			else
			{
				i = array_length(VarType::CreateRef(points)) - IntType(1);
				pos = vec3_add(points.Value(i), vec3_mul(ArrType::From({ points[i - IntType(1)][PATH_TANGENT_X], points[i - IntType(1)][PATH_TANGENT_Y], points[i - IntType(1)][PATH_TANGENT_Z] }), abs(t - i)));
			}
			
			point = array_copy_1d(points.Value(i));
			point[X_] = pos.Real(X_);
			point[Y_] = pos.Real(Y_);
			point[Z_] = pos.Real(Z_);
			point[PATH_TANGENT_X] = point.Value(PATH_TANGENT_X);
			return point;
		}
		if (smooth > 0)
			return bezier_curve_quad(points.Value(p0), points.Value(p1), points.Value(p2), curvet);
		else
		{
			if (curvet < 0.5)
				return point_lerp(points.Value(p0), points.Value(p1), curvet * IntType(2));
			else
				return point_lerp(points.Value(p1), points.Value(p2), (curvet - 0.5) * IntType(2));
			
		}
		
		return VarType();
	}
	
	void spline_make_frames(VarType points, VarType closed, VarType smooth)
	{
		VarType p, pn, t, tn;
		VecType n, nn, rn;
		IntType j;
		p = spline_get_point(IntType(0), points, closed, smooth);
		pn = spline_get_point(IntType(1), points, closed, smooth);
		t = vec3_direction(p, pn);
		if (t.Value(Z_) == IntType(1) || t.Value(Z_) == -IntType(1))
			n = ArrType::From({ t.Value(Z_), IntType(0), IntType(0) });
		else
			n = vec3_normal(t, IntType(0));
		
		for (j = X_; j <= Z_; j++)
		{
			points.Arr()[IntType(0)][PATH_TANGENT_X + j] = t.Value(j);
			points.Arr()[IntType(0)][PATH_NORMAL_X + j] = n.Real(j);
		}
		p = pn;
		VecType axis;
		RealType angle;
		for (IntType i = IntType(1); i < array_length(VarType::CreateRef(points.Arr())); i++)
		{
			pn = spline_get_point(i + IntType(1), points, closed, smooth);
			tn = vec3_direction(p, pn);
			axis = vec3_normalize(vec3_cross(t, tn));
			angle = vec3_dot(t, tn);
			nn = vec3_normalize(vec3_mul_matrix(n, matrix_create_axis_angle(axis, angle)));
			rn = vec3_rotate_axis_angle(nn, tn, degtorad(pn.Value(W_)));
			for (j = X_; j <= Z_; j++)
			{
				points.Arr()[i][PATH_TANGENT_X + j] = tn.Value(j);
				points.Arr()[i][PATH_NORMAL_X + j] = rn.Real(j);
			}
			p = pn;
			n = nn;
			t = tn;
		}
		if (closed > 0)
		{
			RealType i;
			VarType p, pn;
			VecType t, n;
			i = array_length(VarType::CreateRef(points.Arr())) - IntType(2);
			p = points.Value(i - IntType(1));
			pn = points.Value(IntType(0));
			t = vec3_normalize(ArrType::From({ p.Value(PATH_TANGENT_X) + pn.Value(PATH_TANGENT_X), p.Value(PATH_TANGENT_Y) + pn.Value(PATH_TANGENT_Y), p.Value(PATH_TANGENT_Z) + pn.Value(PATH_TANGENT_Z) }));
			n = vec3_normalize(ArrType::From({ p.Value(PATH_NORMAL_X) + pn.Value(PATH_NORMAL_X), p.Value(PATH_NORMAL_Y) + pn.Value(PATH_NORMAL_Y), p.Value(PATH_NORMAL_Z) + pn.Value(PATH_NORMAL_Z) }));
			for (j = X_; j <= Z_; j++)
			{
				points.Arr()[i][PATH_TANGENT_X + j] = t.Real(j);
				points.Arr()[i][PATH_NORMAL_X + j] = n.Real(j);
			}
			i = array_length(VarType::CreateRef(points.Arr())) - IntType(1);
			for (j = X_; j <= Z_; j++)
			{
				points.Arr()[i][PATH_TANGENT_X + j] = pn.Value(PATH_TANGENT_X + j);
				points.Arr()[i][PATH_NORMAL_X + j] = pn.Value(PATH_NORMAL_X + j);
			}
		}
	}
	
	ArrType spline_subdivide(ArrType points, VarType closed)
	{
		ArrType arr;
		IntType amount;
		arr = ArrType::From({});
		amount = array_length(VarType::CreateRef(points));
		if (closed > 0)
			array_add(VarType::CreateRef(arr), point_lerp(points.Value(IntType(0)), points.Value(amount - IntType(1)), .5), false);
		for (IntType i = IntType(0); i < array_length(VarType::CreateRef(points)); i++)
		{
			RealType next = ((closed > 0) ? mod_fix(i + IntType(1), amount) : clamp(i + IntType(1), IntType(0), amount - IntType(1)));
			array_add(VarType::CreateRef(arr), points.Value(i), false);
			if (i > IntType(0) || closed > 0)
				array_add(VarType::CreateRef(arr), point_lerp(points.Value(i), points.Value(next), .5), false);
		}
		return arr;
	}
	
	IntType sprite_add_lib(VarArgs argument)
	{
		IntType argument_count = argument.Size();
		VarType origin_x, origin_y;
		origin_x = IntType(0);
		origin_y = IntType(0);
		if (argument_count > IntType(1))
		{
			origin_x = argument[IntType(1)];
			origin_y = argument[IntType(2)];
		}
		if (global::file_copy_temp)
		{
			StringType ext;
			VarType tmpfile;
			ext = filename_ext(argument[IntType(0)]);
			tmpfile = filename_new_ext(temp_file, ext);
			file_copy_lib(argument[IntType(0)], tmpfile);
			return sprite_add(tmpfile, IntType(1), false, false, (IntType)(origin_x), (IntType)(origin_y));
		}
		else
			return sprite_add(argument[IntType(0)], IntType(1), false, false, (IntType)(origin_x), (IntType)(origin_y));
		
		return IntType(0);
	}
	
	void sprite_save_lib(VarType spr, IntType subimg, VarType fn)
	{
		IntType surf = surface_create(sprite_get_width((IntType)(spr)), sprite_get_height((IntType)(spr)));
		surface_set_target(surf);
	{
		draw_clear_alpha(c_black, 0.0);
		gpu_set_blendmode_ext(bm_one, bm_inv_src_alpha);
		draw_sprite((IntType)(spr), subimg, IntType(0), IntType(0));
		gpu_set_blendmode(bm_normal);
	}
		surface_reset_target();
		surface_save_lib(surf, fn);
		surface_free(surf);
	}
	
	void state_vars_add(VarType dest, VarType src)
	{
		IntType srclen = array_length(VarType::CreateRef(src));
		for (IntType i = IntType(0); i < srclen; i += IntType(2))
		{
			IntType j;
			for (j = IntType(0); j < array_length(VarType::CreateRef(dest.Arr())); j += IntType(2))
				if (dest.Value(j) == src.Value(i))
					break;
			dest.Arr()[j] = src.Value(i);
			dest.Arr()[j + IntType(1)] = src.Value(i + IntType(1));
		}
	}
	
	VarType state_vars_get_value(VarType vars, VarType name)
	{
		IntType varslen = array_length(VarType::CreateRef(vars));
		for (IntType i = IntType(0); i < varslen; i += IntType(2))
			if (vars.Value(i) == name)
				return vars.Value(i + IntType(1));
		return null_;
	}
	
	BoolType state_vars_match(ArrType vars, VarType varscomp)
	{
		IntType varslen = array_length(VarType::CreateRef(vars));
		for (IntType i = IntType(0); i < varslen; i += IntType(2))
		{
			VarType name, val, valcomp;
			name = vars.Value(i);
			val = vars.Value(i + IntType(1));
			valcomp = state_vars_get_value(varscomp, name);
			if (valcomp == null_)
				return false;
			if (is_array(val))
			{
				if (!array_contains(val, valcomp))
					return false;
			}
			else
				if (val != valcomp)
					return false;
			
		}
		return true;
	}
	
	BoolType state_vars_match_state_id(VarType vars, IntType block, IntType stateid)
	{
		IntType varslen = array_length(VarType::CreateRef(vars));
		for (IntType i = IntType(0); i < varslen; i += IntType(2))
		{
			VarType name, val, valcomp;
			name = vars.Value(i);
			val = vars.Value(i + IntType(1));
			valcomp = block_get_state_id_value(block, stateid, name);
			if (is_array(val))
			{
				if (!array_contains(val, valcomp))
					return false;
			}
			else
				if (val != valcomp)
					return false;
			
		}
		return true;
	}
	
	RealType state_vars_set_value(VarType vars, VarType name, VarType value)
	{
		IntType varslen = array_length(VarType::CreateRef(vars.Arr()));
		for (IntType i = IntType(0); i < varslen; i += IntType(2))
		{
			if (vars.Value(i) == name)
			{
				vars.Arr()[i + IntType(1)] = value;
				return IntType(0);
			}
		}
		vars.Arr()[varslen] = name;
		vars.Arr()[varslen + IntType(1)] = value;
		return 0.0;
	}
	
	RealType string_contains(VarType str, StringType search)
	{
		return (string_pos(search, str) > IntType(0));
	}
	
	StringType string_decimals(VarType val)
	{
		if (floor(val) == val)
			return string(floor(val));
		StringType str;
		IntType p;
		str = string_format(val, IntType(1), IntType(5));
		for (p = string_length(str); p > IntType(0); p--)
		{
			StringType c = string_char_at(str, p);
			if (c == /*"."*/ STR(1073))
			{
				p--;
				break;
			}
			else
				if (c != /*"0"*/ STR(1032))
					break;
			
		}
		return string_copy(str, IntType(1), p);
	}
	
	StringType string_format_snakecase(VarType str)
	{
		return string_replace_all(string_upper(string_char_at(str, IntType(1))) + string_delete(str, IntType(1), IntType(1)), /*"_"*/ STR(1096), /*" "*/ STR(17));
	}
	
	VarType string_get_real(VarType str, VarType inv)
	{
		if (is_undefined(str))
			return inv;
		IntType len, state;
		len = string_length(str);
		while (len > IntType(1) && string_char_at(str, len) == /*" "*/ STR(17))
			len--;
		
		state = IntType(0);
		for (IntType i = IntType(1); i <= len; i++)
		{
			StringType c = string_char_at(str, i);
			if (c == /*" "*/ STR(17))
			{
				if (state == IntType(0))
					continue;
				else
					return inv;
				
			}
			else
				if (c == /*"-"*/ STR(1075) || c == /*"+"*/ STR(1076))
				{
					if (state == IntType(0) || state == IntType(5))
						state++;
					else
						return inv;
					
				}
				else
					if (ord(c) >= (IntType)'0' && ord(c) <= (IntType)'9')
					{
						if (state <= IntType(2))
							state = IntType(2);
						else
							if (state <= IntType(4))
								state = IntType(4);
							else
								if (state <= IntType(7))
									state = IntType(7);
								else
									return inv;
							
						
						
					}
					else
						if (c == /*"."*/ STR(1073))
						{
							if (state <= IntType(2))
								state = IntType(3);
							else
								return inv;
							
						}
						else
							return inv;
					
				
			
			
		}
		if (string_replace(string_replace(str, /*"-"*/ STR(1075), /*""*/ STR(0)), /*"."*/ STR(1073), /*""*/ STR(0)) == /*""*/ STR(0))
			return inv;
		if (string_contains(str, /*"-."*/ STR(2891)))
			str = string_replace(str, /*"-."*/ STR(2891), /*"-0."*/ STR(2892));
		if (state >= IntType(2))
			return real(str);
		return inv;
	}
	
	VarType string_get_state_vars(VarType argument0)
	{
		VarType str;
		ArrType vars, arr;
		IntType varslen;
		str = argument0;
		vars = string_split(str, /*","*/ STR(1022));
		varslen = array_length(VarType::CreateRef(vars));
		arr = array_create({ varslen * IntType(2) });
		for (IntType i = IntType(0); i < varslen; i++)
		{
			ArrType nameval = string_split(vars.Value(i), /*"="*/ STR(2893));
			arr[i * IntType(2)] = nameval.Value(IntType(0));
			if (array_length(VarType::CreateRef(nameval)) > IntType(1))
				arr[i * IntType(2) + IntType(1)] = nameval.Value(IntType(1));
			else
				return null_;
			
		}
		return arr;
	}
	
	VarType string_limit(VarType str, VarType wid, StringType ellipsis)
	{
		if (string_width(ellipsis) > wid)
			return /*""*/ STR(0);
		if (string_width(str) <= wid)
			return str;
		StringType nstr;
		IntType pos;
		nstr = /*""*/ STR(0);
		pos = IntType(1);
		while (pos <= string_length(str))
		{
			StringType char_ = string_char_at(str, pos);
			if (char_ == /*"\n"*/ STR(937))
				char_ = /*" "*/ STR(17);
			if (string_width(nstr + char_ + ellipsis) >= wid)
				break;
			nstr += char_;
			pos++;
		}
		
		return nstr + /*"..."*/ STR(2894);
	}
	
	StringType string_limit_ext(VarType str, VarType w, VarType h)
	{
		StringType nstr;
		IntType lh, dx, dy, c, linestart, wordstart;
		nstr = /*""*/ STR(0);
		lh = string_height(/*" "*/ STR(17));
		dx = IntType(0);
		dy = IntType(0);
		if (lh > h || string_width(/*"..."*/ STR(2894)) > w)
			return /*""*/ STR(0);
		linestart = IntType(1);
		wordstart = IntType(1);
		for (c = IntType(1); c <= string_length(str); c++)
		{
			StringType char_;
			IntType charwid;
			char_ = string_char_at(str, c);
			charwid = string_width(char_);
			if (char_ == /*"\n"*/ STR(937))
			{
				dx = IntType(0);
				dy += lh;
				if (dy + lh > h)
				{
					while (c > linestart && string_width(string_copy(str, linestart, (IntType)(c - linestart)) + /*"..."*/ STR(2894)) > w)
						c--;
					
					nstr += string_copy(str, linestart, (IntType)(c - linestart)) + /*"..."*/ STR(2894);
					c = linestart;
					break;
				}
				nstr += string_copy(str, linestart, (IntType)(c - linestart)) + /*"\n"*/ STR(937);
				linestart = c + IntType(1);
			}
			else
			{
				if (char_ == /*" "*/ STR(17) || char_ == /*", "*/ STR(1011) || char_ == /*"."*/ STR(1073) || char_ == /*"/"*/ STR(16) || char_ == /*"-"*/ STR(1075))
					wordstart = c + IntType(1);
				dx += charwid;
				if (dx > w && c > IntType(1))
				{
					dy += lh;
					if (dy + lh > h)
					{
						while (c > linestart && string_width(string_copy(str, linestart, (IntType)(c - linestart)) + /*"..."*/ STR(2894)) > w)
							c--;
						
						nstr += string_copy(str, linestart, (IntType)(c - linestart)) + /*"..."*/ STR(2894);
						c = linestart;
						break;
					}
					if (linestart == wordstart)
						wordstart = c;
					nstr += string_copy(str, linestart, (IntType)(wordstart - linestart)) + /*"\n"*/ STR(937);
					dx = string_width(string_copy(str, wordstart, (IntType)(c - wordstart + IntType(1))));
					linestart = wordstart;
				}
			}
			
		}
		nstr += string_copy(str, linestart, (IntType)(c - linestart));
		return nstr;
	}
	
	ArrType string_line_array(VarType str)
	{
		str = str + /*"\n"*/ STR(937);
		ArrType arr = array_create({ string_count(/*"\n"*/ STR(937), str) });
		for (RealType i = array_length(VarType::CreateRef(arr)) - IntType(1); i > -IntType(1); i--)
		{
			IntType linepos = string_pos(/*"\n"*/ STR(937), str);
			arr[i] = string_copy(str, IntType(0), (IntType)(linepos - IntType(1)));
			str = string_delete(str, IntType(1), linepos);
		}
		return arr;
	}
	
	VarType string_remove_newline(VarType str)
	{
		return string_replace_all(str, /*"\n"*/ STR(937), /*" "*/ STR(17));
	}
	
	ArrType string_split(VarType str, StringType sep)
	{
		ArrType arr;
		IntType arrlen;
		VarType pos;
		StringType escapestr;
		arr = ArrType();
		arrlen = IntType(0);
		str += sep;
		escapestr = /*""*/ STR(0);
		while (true)
		{
			IntType pos = string_pos(sep, str);
			if (pos == IntType(0))
				break;
			IntType escapepos = string_pos(/*"\\"*/ STR(1099) + sep, str);
			if (escapepos > IntType(0) && escapepos < pos)
			{
				escapestr += string_copy(str, IntType(1), (IntType)(escapepos - IntType(1))) + sep;
				str = string_delete(str, IntType(1), escapepos + IntType(1));
				continue;
			}
			arr[arrlen++] = escapestr + string_copy(str, IntType(1), (IntType)(pos - IntType(1)));
			str = string_delete(str, IntType(1), pos);
			escapestr = /*""*/ STR(0);
		}
		
		return arr;
	}
	
	StringType string_time(RealType hours, RealType mnts, RealType secs)
	{
		StringType sep = /*":"*/ STR(755);
		return string_repeat(/*"0"*/ STR(1032), (IntType)(hours < IntType(10))) + string(hours) + sep + string_repeat(/*"0"*/ STR(1032), (IntType)(mnts < IntType(10))) + string(mnts) + sep + string_repeat(/*"0"*/ STR(1032), (IntType)(secs < IntType(10))) + string_replace_all(string_format(secs, IntType(2), IntType(3)), /*" "*/ STR(17), /*""*/ STR(0));
	}
	
	VarType string_time_seconds(RealType secs)
	{
		return string_time((IntType)(secs / IntType(3600)), (IntType)(mod(secs, IntType(3600)) / IntType(60)), mod(secs, IntType(60)));
	}
	
	VarType string_wrap(VarType str, RealType wid)
	{
		IntType pos, insertpos, linewid;
		pos = IntType(1);
		insertpos = -IntType(1);
		linewid = IntType(0);
		for (pos = IntType(1); pos <= string_length(str); pos++)
		{
			StringType ch = string_char_at(str, pos);
			if (ch == /*"\n"*/ STR(937))
			{
				linewid = IntType(0);
				continue;
			}
			linewid += string_width(ch);
			if (linewid >= wid)
			{
				if (insertpos == -IntType(1))
				{
					str = string_insert(/*"\n"*/ STR(937), str, pos);
					linewid = IntType(0);
				}
				else
				{
					str = string_insert(/*"\n"*/ STR(937), str, insertpos);
					linewid = string_width(string_copy(str, insertpos, (IntType)(pos - insertpos + IntType(1))));
					insertpos = -IntType(1);
				}
				
			}
			if (ch == /*" "*/ STR(17) || ch == /*"-"*/ STR(1075))
				insertpos = pos + IntType(1);
		}
		return str;
	}
	
	IntType surface_duplicate(VarType surf, RealType scale)
	{
		IntType newsurf;
		if (surface_exists((IntType)(surf)))
			newsurf = surface_create((IntType)(surface_get_width((IntType)(surf)) * scale), (IntType)(surface_get_height((IntType)(surf)) * scale));
		else
			newsurf = surface_create(IntType(32), IntType(32));
		
		surface_set_target(newsurf);
	{
		draw_clear_alpha(c_black, 1.0);
		if (!surface_exists((IntType)(surf)))
			draw_missing(IntType(0), IntType(0), IntType(32), IntType(32));
		if (surface_exists((IntType)(surf)))
			draw_surface_ext((IntType)(surf), IntType(0), IntType(0), scale, scale, 0.0, c_white, 1.0);
	}
		surface_reset_target();
		return newsurf;
	}
	
	ArrType surface_get_alpha_array(IntType surf)
	{
		IntType wid, hei;
		ArrType arr;
		wid = surface_get_width(surf);
		hei = surface_get_height(surf);
		global::buffer_current = buffer_create((IntType)(wid * hei * IntType(4)), buffer_fixed, IntType(4));
		buffer_get_surface(global::buffer_current, surf, IntType(0));
		for (IntType py = IntType(0); py < hei; py++)
			for (IntType px = IntType(0); px < wid; px++)
				arr[px][py] = buffer_read_alpha(px, py, wid);
		buffer_delete(global::buffer_current);
		return arr;
	}
	
	VarType surface_require(VarType surf, VarType w, VarType h, BoolType depth, BoolType hdr)
	{
		IntType starttime;
		w = max({ IntType(1), w });
		h = max({ IntType(1), h });
		starttime = current_time();
		if (surf < IntType(0))
			surf = surface_create_ext2(w, h, depth, hdr);
		else
			if (!surface_exists((IntType)(surf)) || surface_get_width((IntType)(surf)) < IntType(0))
			{
				surface_free((IntType)(surf));
				surf = surface_create_ext2(w, h, depth, hdr);
			}
			else
				if (surface_get_width((IntType)(surf)) != w || surface_get_height((IntType)(surf)) != h)
					surface_resize((IntType)(surf), (IntType)(w), (IntType)(h));
		
		
		global::render_surface_time += current_time() - starttime;
		return surf;
	}
	
	void surface_save_lib(VarType surf, VarType fn)
	{
		file_delete_lib(temp_image);
		surface_save((IntType)(surf), temp_image);
		file_copy_lib(temp_image, fn);
	}
	
	IntType tab_add_category(Scope<obj_tab> self, StringType name, VarType icon, IntType script, BoolType show)
	{
		IntType cat = (new obj_category)->id;
		self->category[self->category_amount] = cat;
		self->category_amount++;
		withOne (obj_category, cat, self->id)
		{
			ObjType(obj_category, self->id)->name = name;
			ObjType(obj_category, self->id)->icon = icon;
			ObjType(obj_category, self->id)->script = script;
			ObjType(obj_category, self->id)->show = show;
			self->enabled = true;
			return self->id;
		}
		
		return IntType(0);
	}
	
	RealType tab_close(ScopeAny self, VarType tab)
	{
		IntType panel;
		panel = idInt(tab, panel);
		if (!(idReal(tab, show) > 0))
			return IntType(0);
		if (tab == sInt(settings))
			settings_save(self);
		panel_tab_list_remove(panel, tab);
		idReal(tab, show) = false;
		sVar(tab_move) = null_;
		return 0.0;
	}
	
	void tab_collapse_end(ScopeAny self, BoolType divider)
	{
		global::collapse_ani = IntType(1);
		global::collapse_groups--;
		draw_box(sVar(content_x), sVar(dy), sVar(content_width), sVar(content_height), false, global::c_level_middle, IntType(1));
		if (global::collapse_groups > IntType(0))
			draw_box(sVar(content_x), sVar(dy), sVar(content_width), sVar(content_height), false, global::c_level_bottom, .5 * global::collapse_groups);
		sVar(dx) -= 16.0;
		sVar(dw) += IntType(16);
		if (divider)
		{
			draw_divide(sVar(content_x), sVar(dy), sVar(content_width) - (floor((IntType)ObjType(obj_scrollbar, idInt(sVar(tab), scroll))->needed * IntType(12)) + IntType(1)));
			sVar(dy) += IntType(8);
		}
	}
	
	void tab_collapse_start(ScopeAny self)
	{
		global::collapse_groups++;
		draw_box(sVar(content_x), sVar(dy), sVar(content_width), sVar(content_height), false, global::c_level_bottom, .5 * global::collapse_groups);
		sVar(dx) += IntType(16);
		sVar(dw) -= 16.0;
		sVar(dy) += -IntType(8) + (global::collapse_ani * IntType(8));
		sVar(dy) += IntType(8);
	}
	
	void tab_control(ScopeAny self, RealType height)
	{
		sReal(tab_control_h) = height;
		if (sVar(tab_collumns) > 0)
		{
			sVar(dw) = (sVar(tab_collumns_width) - ((sVar(tab_collumns_count) - IntType(1)) * IntType(8))) / sVar(tab_collumns_count);
			sVar(dx) = sVar(tab_collumns_start_x) + ceil(sVar(dw) * (sReal(tab_collumns_index))) + (IntType(8) * sReal(tab_collumns_index));
		}
	}
	
	void tab_control_button_label(ScopeAny self)
	{
		tab_control(self, IntType(32));
	}
	
	void tab_control_checkbox(ScopeAny self)
	{
		tab_control(self, sReal(ui_small_height));
	}
	
	void tab_control_color(ScopeAny self)
	{
		if (!(global::_app->panel_compact > 0) && sVar(tab_collumns_count) > IntType(1))
			tab_control(self, sReal(ui_small_height) + (label_height + IntType(8)));
		else
			tab_control(self, sReal(ui_small_height));
		
	}
	
	void tab_control_dragger(ScopeAny self)
	{
		tab_control(self, sReal(ui_small_height));
	}
	
}
