/// action_tl_hide_select(hide)

function action_tl_hide_select(hide)
{
	if (history_undo)
	{
		with (history_data)
			for (var t = 0; t < save_var_amount; t++)
				with (save_id_find(save_var_save_id[t]))
					id.hide = other.save_var_old_value[t]
	}
	else if (history_redo)
	{
		with (history_data)
			for (var t = 0; t < save_var_amount; t++)
				with (save_id_find(save_var_save_id[t]))
					id.hide = other.save_var_new_value[t]
	}
	else
	{
		var hobj = history_save_var_start(action_tl_hide_select, false);
		
		with (obj_timeline)
		{
			if (!selected)
				continue
			
			action_tl_hide_tree(id, hide, hobj)
		}
	}
}