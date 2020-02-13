/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	spell_special(core_t *cor)
{
	float basic_dmg = my_percent(cor->ply.chrc[9], PERCENT);
	float strength = my_percent(cor->ply.chrc[8], PERCENT) * MULT;
	float critical = my_percent(cor->ply.chrc[9], PERCENT) * MULT;
	float armor = my_percent(cor->mob[cor->btl.mob_id].chrc[0], PERCENT);
	float defense = cor->mob[cor->btl.mob_id].chrc[1];
	float esquive = cor->mob[cor->btl.mob_id].chrc[4];

	if (cor->btl.total_elem[2] < 2 || cor->btl.total_elem[3] < 2)
		return;
	cor->btl.total_elem[2] -= 2;
	cor->btl.total_elem[3] -= 2;
	anim_ply_handling(cor, 7, 3, 10);
	txt_state_ply_handling(cor, 1);
	if (miss_ply_handling(cor, esquive) == 1)
		return;
	cor->btl.dmg[0] += get_damage(basic_dmg, strength);
	defense_ply_handling(cor, armor, defense);
	critical_ply_handling(cor, critical, 4);
	cor->btl.life[1] -= cor->btl.dmg[0];
	cor->obj_btl.dmg_txt[1] = my_itoa(cor->btl.dmg[0]);
}
