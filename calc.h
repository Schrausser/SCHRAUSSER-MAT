//----------------------------------------------------------------------------------------------------| calc_1  header, SCHRAUSSER 2009	//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <conio.h>

#include "calc_fn.h"
#include "calc_fn_fx.h"
#include "calc_fn_matrix.h"
#include "calc_fn_komb.h"
#include "calc_fn_k.h"
#include "calc_fn_kl.h"
#include "calc_fn_2k.h"
#include "calc_fn_2kx.h"
#include "calc_fn_tab.h"
#include "calc_fn_sim.h"
#include "calc_fn_.h"

void ini_();

int iLauf, index0=1, index1=1, 
	
	zlr=0, sw_1=0, sw_fn=0, sw_fn_1=0, fn_n=0,
	operat[400], fn[400], laenge, iwert=0,  erg0_var=0, 
	mod_Z, mod_N;

double wert[100], //---------------------------------------------------------------------------------> wertvektor 
	    erg=0;

char formel0[600], //--------------------------------------------------------------------------------> formel0zeichensatzvektor, formel0vektor
	 arg0, arg0_[600], 
	 //vgl. mat2,mat3; inpt_...erg0_, vektorumfang n=500;
	 inpt_[600],tmp[600],
	 wert_var_[600],
	 erg0_[600],
	 erg_format_1[20], erg_format_2[20], erg_vk[3], erg_nk[3], erg_f[2], null[30];


void ini_()
{
	FILE *iniStream; 
	
	if (fopen ("MAT.ini", "r") == NULL) //-----------------------------------------------------------> fehlt MAT.ini wird eine Vorlage erstellt.
	{
		iniStream = fopen ("MAT.ini", "w");
		
		fprintf( iniStream,"0\t\t//vorkommastellen\n"); 
		fprintf( iniStream,"16\t\t//nachkommastellen\n"); 
		fprintf( iniStream,"g\t\t//zahlenformat\n"); 
		fprintf( iniStream,"1\t\t//klammerzwischenergebnisse_ausgeben\n"); 
		fprintf( iniStream,"1\t\t//logschreiben\n"); 
		fprintf( iniStream,"MAT_log.txt\t\t//logdateiname\n"); 
		fprintf( iniStream,"0\t\t//log_editieren\n"); 
		fprintf( iniStream,"0\t\t//funkionsindex_editieren\n"); 
		fprintf( iniStream,"0\t\t//variablen_löschen\n"); 
	
		fclose( iniStream );
		//system("MAT.ini");
	}

	iniStream = fopen( "MAT.ini", "r" );
		
	fscanf(iniStream,"%s%s\n", &erg_vk, null ); 
	fscanf(iniStream,"%s%s\n", &erg_nk, null );
	fscanf(iniStream,"%s%s\n", &erg_f, null );

	fclose( iniStream  );

	//printf("vk= %s nk= %s f= %s\n", erg_vk, erg_nk, erg_f);

	//-----------------------------------------------------------------------------------------------> ergebnisausgabeformat
	strcpy(erg_format_1,"= %"); 
	strcat(erg_format_1, erg_vk); //vorkommastellen  3
	strcat(erg_format_1,"."); 
	strcat(erg_format_1, erg_nk); //nachkommastellen  16
	strcat(erg_format_1, erg_f); //typ g,f..
	strcat(erg_format_1," ");

	strcpy(erg_format_2,"%"); 
	strcat(erg_format_2, erg_vk); //vorkommastellen  3
	strcat(erg_format_2,"."); 
	strcat(erg_format_2, erg_nk); //nachkommastellen  16
	strcat(erg_format_2, erg_f); //typ g,f..
	strcat(erg_format_2,"\n");

};	
