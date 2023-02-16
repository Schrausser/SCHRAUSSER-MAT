//----------------------------------------------------------------------------------------------------| MAT2,3 header, SCHRAUSSER 2009, 2010	// 
//																										
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <process.h>
#include <time.h>

#include "calc_profil.h"
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

int iLauf, index=1, laenge,   
	klm_zlr=0, klm_zu_zlr=0, klm_auf_zlr=0, ist_zlr=0, dg_zlr=0, end_dg=0, 
	frml=0, erg_ln, ind = 1; 

    sw_fn=0, sw_fn_1=0, fn[400], operat[400];//fn_n=0

char dbuffer [9],tbuffer [9],
     
	formel[600], formel_[600], 
	arg, arg_[600], 
	tmp_clc[600], tmp_1[600], tmp_2[600], 
	cmd_[600],
	erg_[10]={""},
	erg_format_1[20], erg_format_2[20], erg_format_3[20], erg_vk[3], erg_nk[3], erg_f[2], null[30],
	c_1, c_2;

void ini_()
{
	FILE *iniStream; 
	
	if (fopen ("MAT.ini", "r") == NULL) //----------------------------------------------------------> fehlt MAT.ini wird eine Vorlage erstellt.
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

	//----------------------------------------------------------------------------------------------> ergebnisausgabeformat
	strcpy(erg_format_1,"\n\n%s= %"); 
	strcat(erg_format_1, erg_vk); //vorkommastellen  3
	strcat(erg_format_1,"."); 
	strcat(erg_format_1, erg_nk); //nachkommastellen  16
	strcat(erg_format_1, erg_f); //typ g,f..

	strcpy(erg_format_2,"%"); 
	strcat(erg_format_2, erg_vk); //vorkommastellen  3
	strcat(erg_format_2,"."); 
	strcat(erg_format_2, erg_nk); //nachkommastellen  16
	strcat(erg_format_2, erg_f); //typ g,f..
	strcat(erg_format_2,"\n");

	strcpy(erg_format_3,"= %"); 
	strcat(erg_format_3, erg_vk); //vorkommastellen  3
	strcat(erg_format_3,"."); 
	strcat(erg_format_3, erg_nk); //nachkommastellen  16
	strcat(erg_format_3, erg_f); //typ g,f..
	strcat(erg_format_3," ");
};