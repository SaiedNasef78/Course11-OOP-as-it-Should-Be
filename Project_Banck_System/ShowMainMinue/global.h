#pragma once
#include <iostream>
#include "clsUsers.h"

 clsUsers CurrentUser = clsUsers::Find("", "");
 enum enStaut {
	 Unlocked=1,
	 Locked
 };
 enStaut Statu = Unlocked;