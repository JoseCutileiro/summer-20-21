/// @DnDAction : YoYo Games.Gamepad.If_Gamepad_Button_Pressed
/// @DnDVersion : 1.1
/// @DnDHash : 2767398D
/// @DnDArgument : "gp" "P.player"
/// @DnDArgument : "btn" "gp_face1"
var l2767398D_0 = P.player;
var l2767398D_1 = gp_face1;
if(gamepad_is_connected(l2767398D_0) && gamepad_button_check_pressed(l2767398D_0, l2767398D_1))
{
	/// @DnDAction : YoYo Games.Instances.Create_Instance
	/// @DnDVersion : 1
	/// @DnDHash : 1670C872
	/// @DnDParent : 2767398D
	/// @DnDArgument : "xpos_relative" "1"
	/// @DnDArgument : "ypos_relative" "1"
	/// @DnDArgument : "objectid" "Super_Duck_Atack"
	/// @DnDSaveInfo : "objectid" "Super_Duck_Atack"
	instance_create_layer(x + 0, y + 0, "Instances", Super_Duck_Atack);
}

/// @DnDAction : YoYo Games.Gamepad.If_Gamepad_Button_Pressed
/// @DnDVersion : 1.1
/// @DnDHash : 3F298BDD
/// @DnDArgument : "gp" "P.player"
/// @DnDArgument : "btn" "gp_face3"
var l3F298BDD_0 = P.player;
var l3F298BDD_1 = gp_face3;
if(gamepad_is_connected(l3F298BDD_0) && gamepad_button_check_pressed(l3F298BDD_0, l3F298BDD_1))
{
	/// @DnDAction : YoYo Games.Loops.Repeat
	/// @DnDVersion : 1
	/// @DnDHash : 5318A054
	/// @DnDParent : 3F298BDD
	/// @DnDArgument : "times" "fury"
	repeat(fury)
	{
		/// @DnDAction : YoYo Games.Instances.Create_Instance
		/// @DnDVersion : 1
		/// @DnDHash : 29795D18
		/// @DnDParent : 5318A054
		/// @DnDArgument : "xpos_relative" "1"
		/// @DnDArgument : "ypos_relative" "1"
		/// @DnDArgument : "objectid" "Super_Duck_eltroFury_obj"
		/// @DnDSaveInfo : "objectid" "Super_Duck_eltroFury_obj"
		instance_create_layer(x + 0, y + 0, "Instances", Super_Duck_eltroFury_obj);
	}
}