//----------------------------------------------------------------------------------------------------| MAT3 von Dietmar Schrausser 2009    
//                                                                                                      calc_1 berechnungsprozedur über calc_1.h
#include "MAT2.h"
#include "MAT3.h"
#include "calc_1.h"
#include <process.h>

main(int argc, char *argv[])
{
	FILE *tmpStream, *calcStream, *outStream;

	system("color 78");//----------------------------------------------------------------------------> farbprofil

	if (argc == 1 ) _profil();//---------------------------------------------------------------------> profil

	ini_();//----------------------------------------------------------------------------------------> voreinstellungen

	if (strcmp(argv[1], "//") == 0 ) exit(0);//------------------------------------------------------> Kommentar
	if (strcmp(argv[1], "FN") == 0 ) _funktionsindex();//--------------------------------------------> funktionsindex
	if (strcmp(argv[1], "FNg") == 0 ) _funktionsindex_g();//-----------------------------------------> funktionsindex
	if (strcmp(argv[1], "MAT") == 0 ) //-------------------------------------------------------------> funktionsindex PDF
	{
		_spawnlp( _P_NOWAIT, "acrobat.exe", "acrobat.exe", "MAT_Funktionsindex.pdf", NULL );exit(0);
	}
	if (strcmp(argv[1], "DAT") == 0 ) //-------------------------------------------------------------> datenoutput
	{
		_spawnlp( _P_NOWAIT, "notepad.exe", "notepad.exe", "MAT_fn.txt", NULL );exit(0);
	}
	if (strcmp(argv[1], "DATR") == 0 ) //-------------------------------------------------------------> Reportfile
	{
		_spawnlp( _P_NOWAIT, "notepad.exe", "notepad.exe", "MAT_rep.txt", NULL );exit(0);
	}
	if (strcmp(argv[1], "DATX") == 0 ) //-------------------------------------------------------------> Rohdatenmatrix
	{
		_spawnlp( _P_NOWAIT, "notepad.exe", "notepad.exe", "MAT_X.txt", NULL );exit(0);
	}

	if (strcmp(argv[1], "REP") == 0 )//--------------------------------------------------------------> datenoutput->Reportfile
	{
		tmpStream = fopen( "MAT_fn.txt", "r" );
		outStream = fopen( "MAT_rep.txt","a" );
		 
		_strdate( dbuffer );_strtime( tbuffer );
		fprintf(outStream,"MAT-Report / %s @ %s\n\n", dbuffer , tbuffer);
	
		do{
			                          c_1 = fgetc(tmpStream);
			if (ind > 1) fputc (c_2, outStream); 
			                    c_2 = c_1;
			    ind++;

		}while (feof (tmpStream) == 0); 

		fprintf(outStream,"\n\n\n");

		fclose( tmpStream  );
		fclose( outStream );

		exit(0);
	}

	if (strcmp(argv[1], "R//") == 0 )//--------------------------------------------------------------> kommentaroutput->Reportfile
	{
		
		outStream = fopen( "MAT_rep.txt","a" );
		 
		_strdate( dbuffer );_strtime( tbuffer );
		fprintf(outStream,"MAT-Report / %s @ %s // ", dbuffer , tbuffer);
	
		for(iLauf=2;iLauf<argc;iLauf++)fprintf(outStream,"%s ", argv[iLauf]);
			                        
		fprintf(outStream,"//\n\n");

	
		fclose( outStream );

		exit(0);
	}

	if (strcmp(argv[1], "(X)") == 0 )//--------------------------------------------------------------> datenoutput->Rohdatenmatrix
	{
		tmpStream = fopen( "MAT_fn.txt", "r" );
		outStream = fopen( "MAT_X.txt","w" );
		 
	
		do{
			                          c_1 = fgetc(tmpStream);
			if (ind > 1) fputc (c_2, outStream); 
			                    c_2 = c_1;
			    ind++;

		}while (feof (tmpStream) == 0); 

		fclose( tmpStream  );
		fclose( outStream );

		exit(0);
	}	
	
	calcStream = fopen( "clc_", "w" );fprintf(calcStream," ");fclose(calcStream);//------------------> initialisierung
	
	strcpy(formel, argv[1]);
    for (iLauf=2; iLauf < argc; iLauf++) strcat(formel,argv[iLauf]);//-------------------------------> formelzeichensatzzusammenbau aus vektorzeiger argv

	laenge = strlen(formel);//-----------------------------------------------------------------------> bestimmug der formel zeichensatzlänge
	if(laenge>600){printf("\nformula n%i>600 .0\n",laenge); exit(0);}//------------------------------> formel zu lang
	
	printf("\n");
	//printf("Formelzeichensatz: %s\n", formel);//---------------------------------------------------> bildschirmausgabe	
	strcpy(formel_, formel);//-----------------------------------------------------------------------> formel zeichensatzspiegelung zur ergebnisausgabe

	outStream = fopen( "MAT_log.txt", "a" );
	_strdate( dbuffer );_strtime( tbuffer );
	fprintf(outStream,"MAT (c) SCHRAUSSER 2009; %s %s;\n\n", dbuffer , tbuffer);
	fprintf(outStream,"%s:\n", formel);//------------------------------------------------------------> dateiausgabe der formel	
	fclose(outStream);

	tmpStream = fopen( "~tmp1", "w" );
	fprintf(tmpStream,"%s",formel);//----------------------------------------------------------------> formelzeichensatzausgabe in tmp stream
	fclose(tmpStream);

	tmpStream = fopen( "~tmp1", "r" );
	for(iLauf=1;iLauf<=laenge;iLauf++)
	{
		arg = fgetc (tmpStream );
		arg_[iLauf]=arg;//---------------------------------------------------------------------------> formelvektorzusammenbau
	}
	fclose(tmpStream);
	
	for(iLauf=1;iLauf<=laenge;iLauf++) if (arg_[iLauf] == '=') ist_zlr++;//--------------------------> = zähler

	if (ist_zlr > 1) {printf("bad formula '='\n"); exit(0);}//-----------------------------------------> istprüfung

	if (ist_zlr == 1)//------------------------------------------------------------------------------> ergebnisvariablentrennung
	{
		tmpStream = fopen( "~tmp1", "r" );arg = ' '; 
		for(iLauf=1;iLauf<=laenge;iLauf++)
		{
			arg = fgetc (tmpStream );
			if(arg=='=') {frml = 1; erg_ln=iLauf;}//-------------------------------------------------> bei erreichung von =, 
			if(frml==0) erg_[iLauf-1]=arg;//---------------------------------------------------------> ergebnisvariablennamenvektor (zu beachten:  erg_[0],erg_[1]... -> erg_[iLauf-1])
			if(frml==2) arg_[iLauf-erg_ln]=arg;//----------------------------------------------------> formelvektorneuzusammenbau
			if(frml==1) frml=2;//--------------------------------------------------------------------> zwischenschaltung zur = zeichen überspringung		
		}
		fclose(tmpStream);
		laenge = laenge - erg_ln;//------------------------------------------------------------------> formellängen anpassung (länge - länge ergebnisvariablenteil)
	
		tmpStream = fopen( "~tmp1", "w" );
		for(iLauf=1;iLauf<=laenge;iLauf++) fprintf(tmpStream,"%c",arg_[iLauf]);//--------------------> formelzeichensatzausgabe in tmp stream bei berechnung ohne klammerebenen
		fclose(tmpStream);
	}

	for(iLauf=1;iLauf<=laenge;iLauf++)//-------------------------------------------------------------> argumentbewertung 
	{	
		if (arg_[iLauf] == '(') klm_auf_zlr++;//-----------------------------------------------------> klammerzähler
		if (arg_[iLauf] == ')') klm_zu_zlr++;
		
		//-------------------------------------------------------------------------------------------> klammersetzungsprüfung	
		klammer_();

	}//argumentbewertung end
	
	if (klm_auf_zlr ==1 && klm_zu_zlr == 1)
	if (arg_[1] == '(' && arg_[laenge] == ')') {printf("bad formula '(x)'\n"); exit(0);}//-------------> klammerprüfung auf sinn
	
	if (klm_auf_zlr > klm_zu_zlr) {printf("bad formula '(()'\n"); exit(0);}//--------------------------> klammerprüfung
	if (klm_auf_zlr < klm_zu_zlr) {printf("bad formula '())'\n"); exit(0);}//--------------------------> klammerprüfung
	

	if (klm_auf_zlr > 0 ) while( dg_zlr <= klm_auf_zlr)//---------------------------------------------| Klammerebenenschleife	
	{ 	
		if (dg_zlr > 0) //---------------------------------------------------------------------------> formelneuzusammenbau ~tmp1 + calc_ergebnis + ~tmp2
		{
			strcpy(tmp_1 ," ");//--------------------------------------------------------------------> ZEICHENSATZ SÄUBERUNG!
			tmpStream = fopen( "~tmp1", "r" );//-----------------------------------------------------> öffnen von ~tmp1
			fscanf (tmpStream,"%s",tmp_1);//---------------------------------------------------------> einlesn des formelbeginnteils
			fclose(tmpStream);
			
			strcpy(tmp_clc ," ");//------------------------------------------------------------------> ZEICHENSATZ SÄUBERUNG!
			tmpStream = fopen( "clc_", "r" );//------------------------------------------------------> öffnen der berechnungsergebnisdatei
			fscanf (tmpStream,"%s",tmp_clc);//-------------------------------------------------------> einlesen des subformelergebnisses
			fclose(tmpStream);

			strcpy(tmp_2 ," ");//--------------------------------------------------------------------> ZEICHENSATZ SÄUBERUNG!
			tmpStream = fopen( "~tmp2", "r" );//-----------------------------------------------------> öffnen von ~tmp2
			fscanf (tmpStream,"%s",tmp_2);//---------------------------------------------------------> einlesen des formelendteils
			fclose(tmpStream);

			tmpStream = fopen( "~tmp1", "w" );//-----------------------------------------------------> öffnen von ~tmp1
			fprintf (tmpStream, "%s%s%s",tmp_1,tmp_clc, tmp_2);//------------------------------------> formelzusammenbau 
			
			fclose(tmpStream);
		
			tmpStream = fopen( "~tmp1", "r" );//-----------------------------------------------------> öffnen von ~tmp1
			fscanf (tmpStream,"%s",formel);//--------------------------------------------------------> einlesen des formelendteils
			fclose(tmpStream);

			laenge = strlen(formel);//---------------------------------------------------------------> bestimmung der neuen formellänge 
			//printf("\nFormelzeichensatz': %s\n", formel);//----------------------------------------> bildschirmausgabe
			printf("\n");
			
			tmpStream = fopen( "~tmp1", "w" );
			fprintf(tmpStream,"%s",formel);//--------------------------------------------------------> formelzeichensatzausgabe in tmp stream
			fclose(tmpStream);

			tmpStream = fopen( "~tmp1", "r" );
			for(iLauf=1;iLauf<=laenge;iLauf++)
			{
				arg = fgetc (tmpStream );
				arg_[iLauf]=arg;//-------------------------------------------------------------------> formelvektorneuzusammenbau
			}
			fclose(tmpStream);

			index=1;klm_zlr=0;
		}
		if(dg_zlr == klm_auf_zlr) dg_zlr++;//--------------------------------------------------------> letzter durchgang ohne klammerlösungen
		if(dg_zlr < klm_auf_zlr) tmpStream = fopen( "~tmp1", "w" );//--------------------------------> öffnen der beginn formel datei ~tmp1
		if(dg_zlr < klm_auf_zlr) while(index <= laenge)//--------------------------------------------> klammerlösungsschleife
		{
			while( arg_[index] != '(' && index <= laenge)//------------------------------------------> bis auf_klammer 
			{
					fprintf(tmpStream,"%c",arg_[index]);index++;//-----------------------------------> wertausgabe in tmpstream
			}
			
			if(arg_[index] == '(')//-----------------------------------------------------------------> bei auf_klammer  
			{
				klm_zlr++;//-------------------------------------------------------------------------> klammerzähler
				
				if( klm_zlr == klm_auf_zlr-dg_zlr)//-------------------------------------------------> bei erreichen der letzten auf_klammer 
				{
					calcStream = fopen( "~calc", "w" );
					
					while( arg_[index] != ')' )//----------------------------------------------------> bis zu_klammer 
					{   
						if(arg_[index] != '(') fprintf(calcStream,"%c",arg_[index]);//---------------> subformel ausgabe in calc stream  
						   /*&& arg_[index] != ')'*/
						index++; 
					}
					fclose(calcStream);
					calcStream = fopen( "~calc", "r" );
	
					fgets (tmp_clc,600,calcStream );//-----------------------------------------------> einlesen der subformelargumente
					//printf("calc_1 clc_= %s\n", tmp_clc);//----------------------------------------> bildschirmausgabe (berechnung via calc_1 nach clc_)
					printf("(%s)", tmp_clc);//-------------------------------------------------------> bildschirmausgabe der subformel
					
					outStream = fopen( "MAT_log.txt", "a" );
					fprintf(outStream,"\n(%s)= ", tmp_clc);//----------------------------------------> dateiausgabe der subformel	
					fclose(outStream);

					strcpy(cmd_ ," ");//-------------------------------------------------------------> befehlszusammenbau für calc_1
					strcat(cmd_, "calc_1 clc_=");strcat(cmd_, tmp_clc);
					//printf("cmd_: %s\n", cmd_);

					//////////////////////////////////////////////////////////////////////////////////////////////////
					
					fn_calc_1(); //------------------------------------------------------------------> Subformelübergabe calc_1.h
					
					//////////////////////////////////////////////////////////////////////////////////////////////////
					
					fclose(calcStream);

					dg_zlr++;//----------------------------------------------------------------------> durchgangszähler
	
					fclose(tmpStream);
					tmpStream = fopen( "~tmp2", "w" );//---------------------------------------------> öffnen der end formel datei ~tmp2

				}
				if(arg_[index] != ')' ) fprintf(tmpStream,"%c",arg_[index]);
				index++;
			}	
		}
		fclose(tmpStream);	
	
	}//Klammerebenenschleife end

	calcStream = fopen( "~tmp1", "r" );
					
	fgets (tmp_clc,600,calcStream );//---------------------------------------------------------------> einlesen der letzten formelargumente
	//printf("calc_1 clc_= %s\n", tmp_clc);//--------------------------------------------------------> bildschirmausgabe (endberechnung via calc_1 nach clc_)			
	printf("%s", tmp_clc);//-------------------------------------------------------------------------> bildschirmausgabe der subformel
	fclose(calcStream);
	
	outStream = fopen( "MAT_log.txt", "a" );
	fprintf(outStream,"\n(%s)= ", tmp_clc);//--------------------------------------------------------> dateiausgabe der subformel	
	fclose(outStream);

	strcpy(cmd_ ," ");//-----------------------------------------------------------------------------> befehlszusammenbau für calc_1
	strcat(cmd_, "calc_1 clc_=");strcat(cmd_, tmp_clc);
	//printf("cmd_: %s\n", cmd_);
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	
	fn_calc_1(); //----------------------------------------------------------------------------------> Subformelübergabe calc_1.h
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	tmpStream = fopen( "clc_", "r" );//--------------------------------------------------------------> öffnen der berechnungsergebnisdatei 
	fgets (tmp_clc,600,tmpStream );//----------------------------------------------------------------> einlesen des endergebnisses
	fclose(tmpStream);

	if(klm_auf_zlr > 0) printf(erg_format_1, formel_, atof(tmp_clc));
	
	printf("\n");
	
	outStream = fopen( "MAT_log.txt", "a" );
	//-----------------------------------------------------------------------------------------------> dateiausgabe des ergebnisses
	if(klm_auf_zlr > 0) fprintf(outStream,erg_format_1, formel_, atof(tmp_clc));
	
	fprintf(outStream,"\n\n\n");

	fclose(outStream);

	if(frml==2)//------------------------------------------------------------------------------------> bei ergbnisvariablen definition 
	{
		outStream = fopen( erg_, "w" );
		//-------------------------------------------------------------------------------------------> ergebnisausgabe in variablenfile
		fprintf (outStream,erg_format_2, atof(tmp_clc));
		
		//printf ("\nergebisvariablendateiname: %s\n", erg_);
		fclose(outStream);
	}
	
	//_spawnlp( _P_NOWAIT, "acrobat.exe",  "acrobat.exe", "MAT_log.txt", NULL );
	if(klm_auf_zlr>0)//------------------------------------------------------------------------------> wenn klammern vorhanen
	{
		system("del ~tmp2");//-----------------------------------------------------------------------> tmp stream löschung
		system("del ~calc");//-----------------------------------------------------------------------> tmp stream löschung
	}
	system("del ~tmp1");//---------------------------------------------------------------------------> tmp stream löschung
	system("del clc_");//----------------------------------------------------------------------------> tmp stream löschung
	
	return 0;	
}

