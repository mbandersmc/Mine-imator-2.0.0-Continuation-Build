/// enums()
/// @desc Define enumerators used in the project.

function enums()
{
	// Platforms
	enum e_platform
	{
		WINDOWS = 0,
		MAC_OS = 1,
		LINUX = 2
	}
	
	// Formats
	enum e_project
	{
		FORMAT_01		  =	1,
		FORMAT_02		  =	2,
		FORMAT_05		  =	3,
		FORMAT_06		  =	4,
		FORMAT_07_DEMO	  =	5,
		FORMAT_100_DEMO_2 = 6,
		FORMAT_100_DEMO_3 = 7,
		FORMAT_100_DEMO_4 = 8,
		FORMAT_100_DEBUG  = 9,
		FORMAT_100		  = 10,
		FORMAT_105		  = 11,
		FORMAT_105_2	  = 12,
		FORMAT_106		  = 13,
		FORMAT_106_2	  = 14,
		FORMAT_CB_100	  = 20,
		FORMAT_CB_102_PRE = 21,
		FORMAT_CB_102	  = 22,
		FORMAT_CB_103	  = 23,
		FORMAT_110_PRE_1  = 24,
		FORMAT_110_PRE_3  = 25,
		FORMAT_110		  = 26,
		FORMAT_113		  = 27,
		FORMAT_120_PRE_1  = 28,
		FORMAT_120_PRE_3  = 29,
		FORMAT_122		  = 30,
		FORMAT_123_PRE_2  = 31,
		FORMAT_125		  = 32,
		FORMAT_200_PRE_1  = 33,
		FORMAT_200_PRE_5  = 34
	}
	
	enum e_settings
	{
		FORMAT_100_DEMO_4 =	0,
		FORMAT_100_DEMO_5 = 1,
		FORMAT_100		  = 2,
		FORMAT_103		  = 3,
		FORMAT_106		  = 4,
		FORMAT_106_2	  = 5,
		FORMAT_106_3	  = 6,
		FORMAT_CB_100	  = 20,
		FORMAT_CB_102	  = 22,
		FORMAT_CE_110	  = 23,
		FORMAT_110_PRE_1  = 24,
		FORMAT_110		  = 25,
		FORMAT_113		  = 26,
		FORMAT_114		  = 27,
		FORMAT_120		  = 28,
		FORMAT_200		  = 29
	}
	
	enum e_minecraft_assets
	{
		FORMAT_110_PRE_1  = 1,
		FORMAT_110_PRE_2  = 2,
		FORMAT_113		  = 3,
		FORMAT_120		  = 4,
		FORMAT_123		  = 5,
		FORMAT_128		  = 6, 
		FORMAT_129		  = 7,
		FORMAT_200		  = 8
	}
	
	enum e_minecraft_pack
	{
		FORMAT_161		  = 1,
		FORMAT_19		  = 2,
		FORMAT_111		  = 3,
		FORMAT_113		  = 4,
		FORMAT_115		  = 5,
		
		LATEST			  = 5
	}
	
	// Value types
	enum e_value_type
	{
		TRANSFORM,
		TRANSFORM_POS,
		TRANSFORM_ROT,
		TRANSFORM_SCA,
		TRANSFORM_BEND,
		TRANSFORM_PATH_POINT,
		
		MATERIAL,
		MATERIAL_TEXTURE,
		MATERIAL_COLOR,
		MATERIAL_SURFACE,
		MATERIAL_SUBSURFACE,
		
		PARTICLES,
		LIGHT,
		SPOTLIGHT,
		CAMERA,
		BACKGROUND,
		SOUND,
		TEXT,
		KEYFRAME,
		ROT_POINT,
		HIERARCHY,
		APPEARANCE,
		AUDIO,
		ITEM,
		PATH,
		amount
	}
	
	// Values
	enum e_value
	{
		POS_X,
		POS_Y,
		POS_Z,
		ROT_X,
		ROT_Y,
		ROT_Z,
		SCA_X,
		SCA_Y,
		SCA_Z,
		BEND_ANGLE_LEGACY,
		BEND_ANGLE_X,
		BEND_ANGLE_Y,
		BEND_ANGLE_Z,
		ALPHA,
		RGB_ADD,
		RGB_SUB,
		RGB_MUL,
		HSB_ADD,
		HSB_SUB,
		HSB_MUL,
		MIX_COLOR,
		GLOW_COLOR,
		MIX_PERCENT,
		EMISSIVE,
		METALLIC,
		ROUGHNESS,
		SUBSURFACE,
		SUBSURFACE_RADIUS_RED,
		SUBSURFACE_RADIUS_GREEN,
		SUBSURFACE_RADIUS_BLUE,
		SUBSURFACE_COLOR,
		WIND_INFLUENCE,
		SPAWN,
		FREEZE,
		CLEAR,
		CUSTOM_SEED,
		SEED,
		ATTRACTOR,
		FORCE,
		FORCE_DIRECTIONAL,
		FORCE_VORTEX,
		LIGHT_COLOR,
		LIGHT_STRENGTH,
		LIGHT_SPECULAR_STRENGTH,
		LIGHT_SIZE,
		LIGHT_RANGE,
		LIGHT_FADE_SIZE,
		LIGHT_SPOT_RADIUS,
		LIGHT_SPOT_SHARPNESS,
		CAM_FOV,
		CAM_BLADE_AMOUNT,
		CAM_BLADE_ANGLE,
		CAM_LIGHT_MANAGEMENT,
		CAM_TONEMAPPER,
		CAM_EXPOSURE,
		CAM_GAMMA,
		CAM_ROTATE,
		CAM_ROTATE_DISTANCE,
		CAM_ROTATE_ANGLE_XY,
		CAM_ROTATE_ANGLE_Z,
		CAM_SHAKE,
		CAM_SHAKE_MODE,
		CAM_SHAKE_STRENGTH_X,
		CAM_SHAKE_STRENGTH_Y,
		CAM_SHAKE_STRENGTH_Z,
		CAM_SHAKE_SPEED_X,
		CAM_SHAKE_SPEED_Y,
		CAM_SHAKE_SPEED_Z,
		CAM_DOF,
		CAM_DOF_DEPTH,
		CAM_DOF_RANGE,
		CAM_DOF_FADE_SIZE,
		CAM_DOF_BLUR_SIZE,
		CAM_DOF_BLUR_RATIO,
		CAM_DOF_BIAS,
		CAM_DOF_THRESHOLD,
		CAM_DOF_GAIN,
		CAM_DOF_FRINGE,
		CAM_DOF_FRINGE_ANGLE_RED,
		CAM_DOF_FRINGE_ANGLE_GREEN,
		CAM_DOF_FRINGE_ANGLE_BLUE,
		CAM_DOF_FRINGE_RED,
		CAM_DOF_FRINGE_GREEN,
		CAM_DOF_FRINGE_BLUE,
		CAM_BLOOM,
		CAM_BLOOM_THRESHOLD,
		CAM_BLOOM_INTENSITY,
		CAM_BLOOM_RADIUS,
		CAM_BLOOM_RATIO,
		CAM_BLOOM_BLEND,
		CAM_LENS_DIRT,
		CAM_LENS_DIRT_BLOOM,
		CAM_LENS_DIRT_GLOW,
		CAM_LENS_DIRT_RADIUS,
		CAM_LENS_DIRT_INTENSITY,
		CAM_LENS_DIRT_POWER,
		CAM_COLOR_CORRECTION,
		CAM_CONTRAST,
		CAM_BRIGHTNESS,
		CAM_SATURATION,
		CAM_VIBRANCE,
		CAM_COLOR_BURN,
		CAM_GRAIN,
		CAM_GRAIN_STRENGTH,
		CAM_GRAIN_SATURATION,
		CAM_GRAIN_SIZE,
		CAM_VIGNETTE,
		CAM_VIGNETTE_RADIUS,
		CAM_VIGNETTE_SOFTNESS,
		CAM_VIGNETTE_STRENGTH,
		CAM_VIGNETTE_COLOR,
		CAM_CA,
		CAM_CA_BLUR_AMOUNT,
		CAM_CA_DISTORT_CHANNELS,
		CAM_CA_RED_OFFSET,
		CAM_CA_GREEN_OFFSET,
		CAM_CA_BLUE_OFFSET,
		CAM_DISTORT,
		CAM_DISTORT_REPEAT,
		CAM_DISTORT_ZOOM_AMOUNT,
		CAM_DISTORT_AMOUNT,
		CAM_SIZE_USE_PROJECT,
		CAM_SIZE_KEEP_ASPECT_RATIO,
		CAM_WIDTH,
		CAM_HEIGHT,
		BG_IMAGE_SHOW,
		BG_IMAGE_ROTATION,
		BG_SKY_MOON_PHASE,
		BG_SKY_TIME,
		BG_SKY_ROTATION,
		BG_SUNLIGHT_STRENGTH,
		BG_SUNLIGHT_ANGLE,
		BG_TWILIGHT,
		BG_SKY_CLOUDS_SHOW,
		BG_SKY_CLOUDS_SPEED,
		BG_SKY_CLOUDS_HEIGHT,
		BG_SKY_CLOUDS_OFFSET,
		BG_GROUND_SHOW,
		BG_GROUND_SLOT,
		BG_BIOME,
		BG_SKY_COLOR,
		BG_SKY_CLOUDS_COLOR,
		BG_SUNLIGHT_COLOR,
		BG_AMBIENT_COLOR,
		BG_NIGHT_COLOR,
		BG_GRASS_COLOR,
		BG_FOLIAGE_COLOR,
		BG_WATER_COLOR,
		BG_LEAVES_OAK_COLOR,
		BG_LEAVES_SPRUCE_COLOR,
		BG_LEAVES_BIRCH_COLOR,
		BG_LEAVES_JUNGLE_COLOR,
		BG_LEAVES_ACACIA_COLOR,
		BG_LEAVES_DARK_OAK_COLOR,
		BG_LEAVES_MANGROVE_COLOR,
		BG_FOG_SHOW,
		BG_FOG_SKY,
		BG_FOG_CUSTOM_COLOR,
		BG_FOG_COLOR,
		BG_FOG_CUSTOM_OBJECT_COLOR,
		BG_FOG_OBJECT_COLOR,
		BG_FOG_DISTANCE,
		BG_FOG_SIZE,
		BG_FOG_HEIGHT,
		BG_WIND,
		BG_WIND_SPEED,
		BG_WIND_STRENGTH,
		BG_WIND_DIRECTION,
		BG_WIND_DIRECTIONAL_SPEED,
		BG_WIND_DIRECTIONAL_STRENGTH,
		BG_TEXTURE_ANI_SPEED,
		TEXTURE_OBJ,
		TEXTURE_MATERIAL_OBJ,
		TEXTURE_NORMAL_OBJ,
		SOUND_OBJ,
		SOUND_VOLUME,
		SOUND_PITCH,
		SOUND_START,
		SOUND_END,
		TEXT,
		TEXT_FONT,
		TEXT_HALIGN,
		TEXT_VALIGN,
		TEXT_AA,
		CUSTOM_ITEM_SLOT,
		ITEM_SLOT,
		ITEM_NAME,
		PATH_OBJ,
		PATH_OFFSET,
		PATH_POINT_ANGLE,
		PATH_POINT_SCALE,
		IK_TARGET,
		IK_BLEND,
		IK_TARGET_ANGLE,
		IK_ANGLE_OFFSET,
		VISIBLE,
		TRANSITION,
		EASE_IN_X,
		EASE_IN_Y,
		EASE_OUT_X,
		EASE_OUT_Y,
		amount
	} // Update app_startup_lists() when adding values
	
	// Template types
	enum e_temp_type
	{
		CHARACTER,
		SPECIAL_BLOCK,
		SCENERY,
		ITEM,
		BLOCK,
		BODYPART,
		PARTICLE_SPAWNER,
		TEXT,
		CUBE,
		CONE,
		CYLINDER,
		SPHERE,
		SURFACE,
		MODEL
	} // Update app_startup_lists() when adding types
	
	// Timeline types
	enum e_tl_type
	{
		CHARACTER,
		SPECIAL_BLOCK,
		SCENERY,
		ITEM,
		BLOCK,
		BODYPART,
		PARTICLE_SPAWNER,
		TEXT,
		CUBE,
		CONE,
		CYLINDER,
		SPHERE,
		SURFACE,
		MODEL,
		CAMERA,
		SPOT_LIGHT,
		POINT_LIGHT,
		FOLDER,
		BACKGROUND,
		AUDIO,
		PATH,
		PATH_POINT,
		
		LIGHT_SOURCE,
		SHAPE,
		AMOUNT
	} // Update app_startup_lists() when adding types
	
	// Resource types
	enum e_res_type
	{
		PACK,
		PACK_UNZIPPED,
		SKIN,
		DOWNLOADED_SKIN,
		ITEM_SHEET,
		LEGACY_BLOCK_SHEET,
		BLOCK_SHEET,
		SCENERY,
		FROM_WORLD,
		PARTICLE_SHEET,
		TEXTURE,
		FONT,
		SOUND,
		MODEL
	} // Update app_startup_lists() when adding types
	
	// Shape types
	enum e_shape_type
	{
		CUBE,
		CONE,
		CYLINDER,
		SPHERE,
		SURFACE,
		amount
	}
	
	// Model format
	enum e_model_format
	{
		MIMODEL,
		BLOCK
	}
	
	enum icons
	{
		ALIGN_BOTTOM,
		ALIGN_LEFT,
		ALIGN_MIDDLE,
		ALIGN_CENTER,
		ALIGN_RIGHT,
		ALIGN_TOP,
		ANNOUNCEMENT,
		ARROW_DOWN,
		ARROW_LEFT,
		ARROW_RIGHT,
		ARROW_UP,
		ASSET,
		ASSET_ADD,
		ASSET_EXPORT,
		ASSET_IMPORT,
		ASSET_INSTANCE,
		ASSET_LIST,
		AWARDS_RECENT,
		BACK,
		BEAKER,
		BELL,
		BELL_SLASH,
		BEND,
		BEND_SHARP,
		BETA,
		BIRTHDAY,
		BLOCK,
		BLOCK_SPECIAL,
		BOLD,
		BOUNDARY_BOX,
		BOUNDARY_CIRCLE,
		BOUNDARY_CUBE,
		BOX_SELECT,
		BROOM,
		BRUSH,
		BRUSH_SMALL,
		BUG,
		CALENDAR,
		CAMERA,
		CAMERA_PHOTO,
		CAMERA_PHOTO_SMALL,
		CAMERA_SMALL,
		CARDS,
		CHARACTER,
		CHARACTER_PARTS,
		CHECKBOX_INDETERMINATE,
		CHECKBOX_TICK,
		CHEVRON_DOWN,
		CHEVRON_DOWN_TINY,
		CHEVRON_LEFT,
		CHEVRON_LEFT_TINY,
		CHEVRON_RIGHT,
		CHEVRON_RIGHT_TINY,
		CHEVRON_UP,
		CHEVRON_UP_TINY,
		CIRCLE,
		CIRCLE_OUTLINE,
		CLAPPERBOARD,
		CLAPPERBOARD_SMALL,
		CLEAR_FORMAT,
		CLICK_LEFT,
		CLICK_MIDDLE,
		CLICK_RIGHT,
		CLOCK,
		CLOSE,
		CLOSE_SMALL,
		CLOUD,
		CODE,
		COMMENT,
		COMMENTS,
		COMPACT,
		CONE,
		CONE__DARK,
		CONTENT,
		COPY,
		COPY_ALL,
		COPY_KEYFRAME,
		COPY_SMALL,
		CROWN,
		CUBE,
		CUBE__DARK,
		CUBE_ADD,
		CUSTOMIZATION,
		CUT,
		CUT_ALL,
		CUT_KEYFRAME,
		CYLINDER,
		CYLINDER__DARK,
		DASHBOARD,
		DELETE,
		DELETE_KEYFRAME,
		DELETE_SELECTION,
		DISCORD,
		DONATE,
		DOT,
		DOWNLOAD,
		DRAG_LEFT,
		DRAG_MIDDLE,
		DRAG_RIGHT,
		DRAGGER,
		DUPLICATE,
		DUPLICATE_SELECTION,
		DUSK,
		EASE_BACK,
		EASE_BOUNCE,
		EASE_CIRCULAR,
		EASE_CUBIC,
		EASE_CUSTOM,
		EASE_ELASTIC,
		EASE_EXPONENTIAL,
		EASE_IN,
		EASE_IN_OUT,
		EASE_INSTANT,
		EASE_LINEAR,
		EASE_OUT,
		EASE_QUAD,
		EASE_QUART,
		EASE_QUINT,
		EASE_SINE,
		ELLIPSIS_HORIZONTAL,
		ELLIPSIS_VERTICAL,
		EMOJI,
		ENVELOPE,
		EXIT,
		EXTERNAL,
		FILE,
		FILE_ADD,
		FILE_EXPORT,
		FILE_IMPORT,
		FILE_OBJ,
		FILE_SMALL,
		FILE_TEMPLATE,
		FILTER,
		FIRE,
		FIREWORKS,
		FLAG,
		FOLDER,
		FOLDER_ADD,
		FOLDER_EDIT,
		FOLDER_IMPORT,
		FOLDER_RECENTS,
		FOLLOWED,
		FOLLOWED_SETTINGS,
		FORUM_STATS,
		FORWARD,
		FRAME_NEXT,
		FRAME_PREVIOUS,
		GHOST,
		GHOST_SMALL,
		GRID,
		GROUP,
		HEART,
		HEART_BROKEN,
		HELP,
		HELP_CIRCLE,
		HIDDEN,
		HIDDEN_SMALL,
		HIERARCHY,
		HIERARCHY_SMALL,
		HIGHLIGHTER,
		HISTORIAN,
		HOME,
		IGNORE,
		IMAGE,
		IMAGE_EXPORT,
		INFO,
		INTERNAL,
		ITALICS,
		ITEM,
		ITEM_SMALL,
		JOINT,
		JOINT_SMALL,
		KEY,
		KEYBOARD,
		KEYBOARD_SMALL,
		KEYFRAME,
		KEYFRAME_FILLED,
		KEYFRAME_FILLED_SMALL,
		KEYFRAME_NEXT,
		KEYFRAME_PREVIOUS,
		KEYFRAME_SMALL,
		LAPTOP,
		LETTERBOX,
		LIBRARY,
		LIBRARY_SMALL,
		LIGHT_OMNI,
		LIGHT_POINT,
		LIGHT_POINT_SMALL,
		LIGHT_SPOT,
		LIGHTBULB,
		LINK,
		LINK_REMOVE,
		LINK_SMALL,
		LIST_BULLETED_LTR,
		LIST_BULLETED_RTL,
		LIST_BULLETED_SMALL,
		LIST_NUMBERED_LTR,
		LIST_NUMBERED_RTL,
		LOCK,
		LOCK_SMALL,
		LOGOUT,
		LOUNGE,
		MAGNET,
		MANUAL,
		MARK,
		MARKER,
		MARKER_ADD,
		MAXIMIZE,
		MEDAL,
		MENU,
		MERGE,
		MINIMIZE,
		MIRROR_HORIZONTALLY,
		MIRROR_VERTICALLY,
		MOBILE,
		MODEL,
		MOON,
		MOVE,
		MOVIE,
		MOVIE_EXPORT,
		MULTITRANSFORM,
		MUTE,
		MUTE_SMALL,
		NEWSPAPER,
		NOTE,
		NOTE_SMALL,
		OVERLAYS,
		PALETTE,
		PART,
		PART_ADD,
		PART_IMPORT,
		PARTICLES,
		PARTICLES_SMALL,
		PASTE,
		PASTE_ALL,
		PASTE_FORMAT,
		PASTE_KEYFRAME,
		PASTE_SMALL,
		PATH,
		PATH_POINT,
		PATH_SMALL,
		PAUSE,
		PENCIL,
		PERSON,
		PERSON_ADD,
		PERSON_CLOSE,
		PERSON_EDIT,
		PERSON_ONLINE,
		PERSON_RECENTS,
		PERSON_SETTINGS,
		PERSON_STATS,
		PERSON_TICK,
		PHI,
		PICKER,
		PICKER_SMALL,
		PILLARBOX,
		PIN,
		PIN_SMALL,
		PIVOT,
		PLANE,
		PLANE_3D,
		PLANE_3D__DARK,
		PLANE_3D_ADD,
		PLANE_ADD,
		PLAY,
		PLAY_REGION,
		PLUS,
		POLL,
		POSING,
		POST_RECENTS,
		PROGRAM_SETTINGS,
		QUALITY,
		PUPPETRY,
		QUOTE,
		RANDOMIZE,
		RECENTS,
		RECENTS_REMOVE,
		REDO,
		REFRESH,
		RELOAD,
		RENAME,
		REPEAT,
		REPEAT_SEAMLESS,
		REPLACE,
		REPLY,
		RESET,
		RESET_ALL,
		RESET_SMALL,
		ROCKETSHIP,
		ROTATE,
		ROTATE_180,
		ROTATE_CCW,
		ROTATE_CW,
		RUN_CYCLE,
		SAVE,
		SAVE_AS,
		SAVE_KEYFRAME,
		SCALE,
		SCENERY,
		SCROLL,
		SEARCH,
		SELECT,
		SELECT_ALL,
		SELECT_ALL_KEYFRAME,
		SEND,
		SETTINGS,
		SETTINGS_EXPORT,
		SETTINGS_IMPORT,
		SETTINGS_SETDEFAULT,
		SETTINGS_SMALL,
		SHAPES,
		SHARE,
		SHIELD,
		SLIDERS,
		SORT_DOWN,
		SORT_UP,
		SPHERE,
		SPHERE__DARK,
		SPHERE_FLAT,
		SPHERE_MATERIAL,
		SPHERE_MATERIAL__DARK,
		SPHERE_MATERIAL_SMALL,
		SPHERE_MATERIAL_SMALL__DARK,
		SPHERE_SHADING,
		SPHERE_SHADING__DARK,
		SPHERE_SHADING_SMALL,
		SPHERE_SHADING_SMALL__DARK,
		SPHERE_TEXTURE,
		SPLIT_CORNER,
		SPLIT_HORIZONTAL,
		SPLIT_VERTICAL,
		STAR,
		STOP,
		STOPWATCH,
		STRIKETHROUGH,
		SUN,
		TAG,
		TAG_ADD,
		TAG_REMOVE,
		TEXT,
		TEXT_ALIGN_CENTER,
		TEXT_ALIGN_LEFT,
		TEXT_ALIGN_RIGHT,
		TEXT_COLOR,
		TEXT_SMALL,
		TEXTURE,
		TEXTURE_EXPORT,
		TICK,
		TOPIC,
		TRANSFORM,
		TRANSFORM_SMALL,
		TRANSFORMATION_GIMBAL,
		TRANSFORMATION_GLOBAL,
		TRANSFORMATION_LOCAL,
		TROPHY,
		TUTORIALS,
		TWITTER,
		UNDERLINE,
		UNDO,
		UNLOCK,
		UNLOCK_SMALL,
		UNMARK,
		UNREAD,
		VCARD,
		VIEW_GRID,
		VIEW_LIST,
		VIEWPORT_SECONDARY,
		VISIBLE,
		VISIBLE_SMALL,
		VOLUME,
		VOLUME_SMALL,
		WALK,
		WALK_CYCLE,
		WAND,
		WARNING_CIRCLE,
		WARNING_DIAMOND,
		WARNING_TRIANGLE,
		WAVE,
		WEB,
		WIND,
		WORKBENCH,
		WORLD,
		WORLD_SMALL,
		YOUTUBE
	}
	
	// Render modes
	enum e_render_mode
	{
		CLICK,
		SELECT,
		PLACE,
		PREVIEW,
		COLOR,
		COLOR_FOG,
		COLOR_FOG_LIGHTS,
		ALPHA_FIX,
		ALPHA_TEST,
		DEPTH,
		DEPTH_NO_SKY,
		HIGH_LIGHT_SUN_DEPTH,
		HIGH_LIGHT_SPOT_DEPTH,
		HIGH_LIGHT_POINT_DEPTH,
		HIGH_LIGHT_SUN,
		HIGH_LIGHT_SPOT,
		HIGH_LIGHT_POINT,
		HIGH_LIGHT_POINT_SHADOWLESS,
		HIGH_FOG,
		COLOR_GLOW,
		SCENE_TEST,
		HIGH_DEPTH_NORMAL,
		AO_MASK,
		MATERIAL,
		SUBSURFACE
	}
	
	// Viewport render mode
	enum e_view_mode
	{
		FLAT,
		SHADED,
		RENDER
	}
	
	// Menus
	enum e_menu
	{
		LIST,
		LIST_SEAMLESS,
		TIMELINE,
		BIOME,
		TRANSITION_LIST,
		CONTENT
	}
	
	// Buttons
	enum e_button
	{
		PRIMARY,
		SECONDARY,
		TERTIARY,
		TOOLBAR,
		BIG,
		
		NO_TEXT,
		TEXT,
		CAPTION,
		LABEL
	}
	
	// Input box types
	enum e_inputbox
	{
		LEFT,
		RIGHT,
		BIG
	}
	
	// Button anchor
	enum e_anchor
	{
		LEFT,
		CENTER,
		RIGHT
	}
	
	// Options
	enum e_option
	{
		BROWSE					= -10,
		IMPORT_WORLD			= -11,
		DOWNLOAD_SKIN			= -12,
		DOWNLOAD_SKIN_DONE		= -13,
		IMPORT_ITEM_SHEET_DONE	= -14
	}
	
	// Directions
	enum e_dir
	{
		EAST,
		WEST,
		SOUTH,
		NORTH,
		UP,
		DOWN,
		amount
	}
	
	// Parts
	enum e_part
	{
		RIGHT,
		LEFT,
		FRONT,
		BACK,
		UPPER,
		LOWER,
		amount
	}
	
	// Bend
	enum e_bend
	{
		FORWARD,
		BACKWARD,
		BOTH
	}
	
	// Scrollbar
	enum e_scroll
	{
		VERTICAL,
		HORIZONTAL
	}
	
	// Buffer Depth
	enum e_block_depth
	{
		DEPTH0, // Opaque
		DEPTH1, // Transparent
		DEPTH2, // Semi-transparent
		amount
	}
	
	// Buffers
	enum e_block_vbuffer
	{
		NORMAL,
		ANIMATED,
		GRASS,
		FOLIAGE,
		LEAVES_OAK,
		LEAVES_SPRUCE,
		LEAVES_BIRCH,
		LEAVES_JUNGLE,
		LEAVES_ACACIA,
		LEAVES_DARK_OAK,
		LEAVES_MANGROVE,
		WATER,
		amount
	}
	
	// Vertex wave
	enum e_vertex_wave
	{
		NONE,
		Z_ONLY,
		ALL,
	}
	
	// NBT
	enum e_nbt
	{
		TAG_END			= 0,
		TAG_BYTE		= 1,
		TAG_SHORT		= 2,
		TAG_INT			= 3,
		TAG_LONG		= 4,
		TAG_FLOAT		= 5,
		TAG_DOUBLE		= 6,
		TAG_BYTE_ARRAY	= 7,
		TAG_STRING		= 8,
		TAG_LIST		= 9,
		TAG_COMPOUND	= 10,
		TAG_INT_ARRAY	= 11,
		TAG_LONG_ARRAY	= 12,
		amount
	}
	
	// Toasts
	enum e_toast
	{
		INFO,
		POSITIVE,
		WARNING,
		NEGATIVE
	}
	
	// Viewport tools
	enum e_view_tool
	{
		SELECT,
		MOVE,
		ROTATE,
		SCALE,
		BEND,
		TRANSFORM,
		amount
	}
	
	enum e_view_control
	{
		POS_X,
		POS_Y,
		POS_Z,
		POS_XY,
		POS_XZ,
		POS_YZ,
		POS_PAN,
		
		ROT_X,
		ROT_Y,
		ROT_Z,
		
		SCA_X,
		SCA_Y,
		SCA_Z,
		SCA_XY,
		SCA_XZ,
		SCA_YZ,
		SCA_XYZ,
		
		BEND_X,
		BEND_Y,
		BEND_Z,
		
		ROT_ANGLE_XY,
		ROT_ANGLE_Z,
		ROT_DISTANCE
	}
	
	// Mouse controls
	enum e_mouse
	{
		CLICK_LEFT,
		CLICK_MIDDLE,
		CLICK_RIGHT,
		DRAG_LEFT,
		DRAG_MIDDLE,
		DRAG_RIGHT,
		SCROLL
	}
	
	// Render passes
	enum e_render_pass
	{
		COMBINED,
		DIFFUSE,
		SPECULAR,
		AO,
		SHADOWS,
		INDIRECT,
		INDIRECT_SHADOWS,
		REFLECTIONS,
		DEPTH_U24,
		NORMAL,
		MATERIAL,
		amount
	}
	
	// Raytracing type
	enum e_raytrace
	{
		REFLECTIONS,
		INDIRECT,
		SHADOWS_DIRECTIONAL
	}
	
	// Material map format
	enum e_material
	{
		FORMAT_NONE,
		FORMAT_SEUS,
		FORMAT_LABPBR
	}
	
	// Alpha mode
	enum e_alpha_mode
	{
		BLEND,
		HASHED,
		DEFAULT
	}
	
	// Tonemapper
	enum e_tonemapper
	{
		NONE,
		REINHARD,
		ACES
	}
	
	// Window
	enum e_window
	{
		MAIN,
		VIEW_SECOND,
		TIMELINE
	}
}
