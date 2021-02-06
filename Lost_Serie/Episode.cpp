#include "Episode.h"


Episode::Episode()
{
}


Episode::Episode(string deutsch_T,string englisch_T,string inhalt,double E_nr){

	this->deutsch_t = deutsch_T;
	this->englisch_t = englisch_T;
	this->episode_nr = E_nr;
	this->inhalt = inhalt;
}

Episode::~Episode()
{
}
