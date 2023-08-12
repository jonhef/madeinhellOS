#include "../common.h"
#include "../drivers/screen.h"
#include "./utils.h"


s32		kmain()
{	
	clear_screen();
	

	kprint_colored("HELL YEAH!!!!", 0xf0);
    kprint("HELLOS");
	return 0;
}
