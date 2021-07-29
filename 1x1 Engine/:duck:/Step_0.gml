
if P.hsp == 0 && P.vsp == 0{
	sprite_index = Super_Duck_still;
	image_index += 0;
}

if P.hsp != 0 && P.vsp == 0{
	sprite_index = Super_Duck_walk;
	image_index += 0;
}

if P.vsp != 0{
	sprite_index = Super_Duck_fly;
	image_index += 0;
}

if P.hsp > 0{
	image_xscale = 1
}
if P.hsp < 0{
	image_xscale = -1
}

x = P.x
y = P.y