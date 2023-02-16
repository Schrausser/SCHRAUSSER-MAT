//----------------------------------------------------------------------------------------------------| calc  header, SCHRAUSSER 2009	//

void funktions_decl_1(char arg0_[200], int index0)
{
	
	if (arg0_[index0] == 'L' && arg0_[index0+1] == 'O' && arg0_[index0+2] == 'G') {sw_fn=1, sw_fn_1 = 1;} // log / log10
	if (arg0_[index0] == 'L' && arg0_[index0+1] == 'N' ) {sw_fn=1;sw_fn_1 = 1;}                         // ln / loge
	if (arg0_[index0] == '!' ) {sw_fn=1;sw_fn_1 = 1; }                                                // faktoriell
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'C' && arg0_[index0+3] == 'T') // faktoriell
	{sw_fn=1;sw_fn_1 = 1; }                                                                         
	if (arg0_[index0] == '!' && arg0_[index0+1] == '!') {sw_fn=1;sw_fn_1 = 1; }                         // doppelfaktoriell
	if (arg0_[index0] == '!' && arg0_[index0+1] == '.' && arg0_[index0+2] == '!' ) {sw_fn=1;sw_fn_1 = 1;} // tripel Faktoriell

	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'S') {sw_fn=1;sw_fn_1 = 1; } // absolutwert
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'T' && arg0_[index0+3] == 'R') // ganze zahl ohne rest	
	{sw_fn=1;sw_fn_1 = 1; }                                                                         
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'T' && arg0_[index0+3] == 'A') // ganze zahl aufgerundet
	{sw_fn=1;sw_fn_1 = 1; }
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'T' 
																		   && arg0_[index0+3] != 'R' 
																		   && arg0_[index0+3] != 'A') // ganze zahl (abgerundet)
	{sw_fn=1;sw_fn_1 = 1; }																			
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'S' && arg0_[index0+3] == 'T') // rest
	{sw_fn=1;sw_fn_1 = 1; }
	if (arg0_[index0] == 'N' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'R' ) {sw_fn=1;sw_fn_1 = 1;} // variation ohne wh
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'R' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} 
	if (arg0_[index0] == 'N' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'R' ) {sw_fn=1;sw_fn_1 = 1;} // kombination ohne wh = permutation zu 1 Klasse
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'M' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} 
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'M' 
												   && arg0_[index0+3] == 'M'&& arg0_[index0+4] == 'A')  // gammafunktion
																					{sw_fn=1;sw_fn_1 = 1; }
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'Q' && arg0_[index0+2] == 'U' ) {sw_fn=1;sw_fn_1 = 1;} // quadrat
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'Q' && arg0_[index0+2] == 'R' ) {sw_fn=1;sw_fn_1 = 1;} // quadratwurzel
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // vorzeichen des arguments
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'U' && arg0_[index0+2] == 'R' ) {sw_fn=1;sw_fn_1 = 1;} // kubikwurzel
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'U' && arg0_[index0+2] == 'B' ) {sw_fn=1;sw_fn_1 = 1;} // 3 Potenz
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // reziprok
	if (arg0_[index0] == 'L' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // logarithmus zur basis x
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // p -> z
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'Z' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // z -> p
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'R' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // variation mit wh
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // kombination mit wh
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'M' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // permutation zu 1 Klasse
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'I' && arg0_[index0+2] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // sinus
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // arcussinus
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'O' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // cosinus
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // arcuscosinus
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // tangens
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // arcustangens

	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // hyp sinus
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // hyp arcussinus
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // hyp cosinus
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'C' ) {sw_fn=1;sw_fn_1 = 1;} // hyp arcuscosinus
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // hyp tangens
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // hyp arcustangens
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // p -> t
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // t -> p
	if (arg0_[index0] == 'X' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // p -> x2
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // x2 -> p
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // p -> F
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // F -> p
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'D' ) {sw_fn=1;sw_fn_1 = 1;} // Quasizufallszahl
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'Z' && arg0_[index0+2] == 'R' ) {sw_fn=1;sw_fn_1 = 1;} // r -> Fisher-Z
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'Z' ) {sw_fn=1;sw_fn_1 = 1;} // Fisher-Z -> r
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'M' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // AM
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'U' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // SUM
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'D' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // SD
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'A' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // Varianz
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'G' ) {sw_fn=1;sw_fn_1 = 1;} // SD geschätzt
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'G' ) {sw_fn=1;sw_fn_1 = 1;} // Varianz geschätzt
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'G' ) {sw_fn=1;sw_fn_1 = 1;} // standardfehler des mittelwertes geschätzt
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'U' 
												       && arg0_[index0+3] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // Produktsumme
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'M' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // GM
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'M' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // HM
	if (arg0_[index0] == 'D' && arg0_[index0+1] == '_' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // Schrausser's d
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'V' && arg0_[index0+2] == 'A'  
						     && arg0_[index0+3] == 'R' && arg0_[index0+4] == 'O' ) {sw_fn=1;sw_fn_1 = 1;} // DvarO
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'O' && arg0_[index0+2] == 'R' ) {sw_fn=1;sw_fn_1 = 1;} // Produktmoment Korrelation r
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'O' && arg0_[index0+2] == 'V' ) {sw_fn=1;sw_fn_1 = 1;} // Kovarianz
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // Determinationskoeffizient
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'D' ) {sw_fn=1;sw_fn_1 = 1;} // Redundanz
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'Y' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // Regressionskoeffizient ayx
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'Y' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // Regressionskoeffizient byx
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'Y' ) {sw_fn=1;sw_fn_1 = 1;} // Regressionskoeffizient axy
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'Y' ) {sw_fn=1;sw_fn_1 = 1;} // Regressionskoeffizient bxy
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'R' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // r -> t
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'R' && arg0_[index0+2] == 'R' ) {sw_fn=1;sw_fn_1 = 1;} // Korrelationsdifferenz
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'Z' ) {sw_fn=1;sw_fn_1 = 1;} // SD zu Fishers Z
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // Permutation zu den Klassen k1,k2,...,kn
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'U' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // t-wert für unverbundene stichproben
	//if (arg0_[index0] == 'T' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'C' ) {sw_fn=1;sw_fn_1 = 1;} // df korrektur zu t-wert uv bei varianzheterogenität (t-wert korrektur ...)
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'V' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // t-wert für verbundene stichproben
	if (arg0_[index0] == 'E' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // eindimensionales chi2
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'Q' && arg0_[index0+2] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // Cochrans Q Test
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'I' && arg0_[index0+2] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // Minimalwert von vektor x
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // Maximalwert von vektor x
	if (arg0_[index0] == 'N' && arg0_[index0+1] == '_' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // Wertumfang n von vektor x
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'G' ) {sw_fn=1;sw_fn_1 = 1;} // Wertbreite von vektor x
	if (arg0_[index0] == 'U' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'S' 
												       && arg0_[index0+3] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // U-Test, U-Wert
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'U' && arg0_[index0+2] == 'T' 
												       && arg0_[index0+3] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // U-Test, sU-Wert
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'U' && arg0_[index0+2] == 'T' 
												       && arg0_[index0+3] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // U-Test, mU-Wert
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'U' && arg0_[index0+2] == 'T' 
												       && arg0_[index0+3] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // U-Test, z-Wert
	if (arg0_[index0] == 'W' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'S' 
												       && arg0_[index0+3] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // Wilcoxon-Test, T-Wert
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'T' 
												       && arg0_[index0+3] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // Wilcoxon-Test, sT-Wert
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'T' 
												       && arg0_[index0+3] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // Wilcoxon-Test, mT-Wert
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'T' 
												       && arg0_[index0+3] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // Wilcoxon-Test, z-Wert
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'U' 
												       && arg0_[index0+3] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // Rangsumme
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'R' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // Rangmittel
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'R' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // Rangkorrelation rs
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // Reduktion von x
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'D' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // Medianwert von Vektor x
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // 4-Felder chi2
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // McNemar chi2
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'Y' 
													   && arg0_[index0+3] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // 4-Felder chi2 kontinuitätskorrigiert
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'Y' 
													   && arg0_[index0+3] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // McNemar chi2 kontinuitätskorrigiert
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'H' ) {sw_fn=1;sw_fn_1 = 1;} // Phi Korrelation
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // Phi Korrelation max
	if (arg0_[index0] == 'X' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // x2 zur Phi Korrelation 
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'E' 
													   && arg0_[index0+3] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // Tetrachorische Korrelation
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'D' ) {sw_fn=1;sw_fn_1 = 1;} // DEG -> RAD 
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'G' ) {sw_fn=1;sw_fn_1 = 1;} // RAD -> DEG
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'R' && arg0_[index0+2] == 'A'  
	                                                   && arg0_[index0+3] == 'D' ) {sw_fn=1;sw_fn_1 = 1;} // DEG -> GRAD
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'R' ) {sw_fn=1;sw_fn_1 = 1;} // GRAD -> DEG
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'O' && arg0_[index0+2] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // cotangens
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'C' ) {sw_fn=1;sw_fn_1 = 1;} // sekans
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'E' ) {sw_fn=1;sw_fn_1 = 1;} // cosekans
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // hyp cotangens
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'E' ) {sw_fn=1;sw_fn_1 = 1;} // hyp secans
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'E' ) {sw_fn=1;sw_fn_1 = 1;} // hyp cosecans
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // arcuscotangens
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'E' ) {sw_fn=1;sw_fn_1 = 1;} // arcussecans
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'E' ) {sw_fn=1;sw_fn_1 = 1;} // arcuscosecans
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'G' ) {sw_fn=1;sw_fn_1 = 1;} // hyp arcuscotangens
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // hyp arcussecans
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'O' ) {sw_fn=1;sw_fn_1 = 1;} // hyp arcuscosecans
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'Z' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // z -> d
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'E' 
													   && arg0_[index0+3] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // s zur Tetrachorischen Korrelation
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'E' 
													   && arg0_[index0+3] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // z-wert zur Tetrachorischen Korrelation
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'B' ) {sw_fn=1;sw_fn_1 = 1;} // Punktbiserale Korrelation
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // biserale Korrelation
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // s zur biseralen Korrelation
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // z-wert zur biseralen Korrelation
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'K' ) {sw_fn=1;sw_fn_1 = 1;} // rpb (r) -> rbis
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'R' ) {sw_fn=1;sw_fn_1 = 1;} // biserale Rang Korrelation
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'R' ) {sw_fn=1;sw_fn_1 = 1;} // z-wert zur biseralen Rang Korrelation
	if (arg0_[index0] == ';' )                                                     {sw_fn=1;sw_fn_1 = 1;} // n über k
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // Binomialwahrscheinlichkeit
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // Binomialpunktwahrscheinlichkeit
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // Multinomialpunktwahrscheinlichkeit
	if (arg0_[index0] == 'N' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // Negative Binomialwahrscheinlichkeit 
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // Hypergeomerische Wahrscheinlichkeit
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // Hypergeomerische Punktwahrscheinlichkeit
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // Geomerische Wahrscheinlichkeit
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // Geomerische Punktwahrscheinlichkeit
	if (arg0_[index0] == 'N' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // Negative Binomialpunktwahrscheinlichkeit 
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // Poissonwahrscheinlichkeit
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // Poissonpunktwahrscheinlichkeit
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // d -> z
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'O' && arg0_[index0+2] == 'R' 
													   && arg0_[index0+3] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // Zahlenausgabeformat
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'A' 
                                                       && arg0_[index0+3] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // invers a gamma funktion
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'A' 
                                                       && arg0_[index0+3] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // invers b gamma funktion
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'A' ) {sw_fn=1;sw_fn_1 = 1;} // alternierende Reduktion
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'Z' && arg0_[index0+2] == 'D' ) {sw_fn=1;sw_fn_1 = 1;} // z -> p (integral)
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'G' ) {sw_fn=1;sw_fn_1 = 1;} // gewichtetes arithmetisches mittel
	if (arg0_[index0] == 'E' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // eulersche zahl (grenzwertformulierung)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'C' 
													   && arg0_[index0+3] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // arcuscotangens (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'S' 
													   && arg0_[index0+3] == 'E' ) {sw_fn=1;sw_fn_1 = 1;} // arcussecans (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'C' 
													   && arg0_[index0+3] == 'E' ) {sw_fn=1;sw_fn_1 = 1;} // arcuscosecans (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'H' 
													   && arg0_[index0+3] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // hyp arcussinus (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'H' 
													   && arg0_[index0+3] == 'C' ) {sw_fn=1;sw_fn_1 = 1;} // hyp arcuscosinus (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'H' 
													   && arg0_[index0+3] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // hyp arcustangens (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'H' 
													   && arg0_[index0+3] == 'G' ) {sw_fn=1;sw_fn_1 = 1;} // hyp arcuscotangens (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'H' 
													   && arg0_[index0+3] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // hyp arcussecans (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'H' 
													   && arg0_[index0+3] == 'O' ) {sw_fn=1;sw_fn_1 = 1;} // hyp arcuscosecans (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'Z' ) {sw_fn=1;sw_fn_1 = 1;} // Gemitteltes Fisher Z
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // t -> d
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // x -> d
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // F -> d
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'A' 
													   && arg0_[index0+3] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // gamma dichtefunktion
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'X' && arg0_[index0+2] == '0' ) {sw_fn=1;sw_fn_1 = 1;} // Fisher Exact P0
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'X' && arg0_[index0+2] == '1' ) {sw_fn=1;sw_fn_1 = 1;} // Fisher Exact p.exact 1-seitig
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'X' && arg0_[index0+2] == '2' ) {sw_fn=1;sw_fn_1 = 1;} // Fisher Exact p.exact 2-seitig
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'A' ) {sw_fn=1;sw_fn_1 = 1;} // Matrizen-Addition
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // Matrizen-Subtraktion
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // Matrizen-Transponierung
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // Spur einer Matrix
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'I' ) {sw_fn=1;sw_fn_1 = 1;} // Matrizen-Invertierung
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // Determinante einer Matrix
    if (arg0_[index0] == 'M' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'V' ) {sw_fn=1;sw_fn_1 = 1;} // Matrizen-Verkettung
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // Matrizen-Multiplikation
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'R' 
													   && arg0_[index0+3] == 'B' ) {sw_fn=1;sw_fn_1 = 1;} // Multiple-Partial Korrelation 
		if (arg0_[index0] == 'P' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'S' 
													   && arg0_[index0+3] == 'B' ) {sw_fn=1;sw_fn_1 = 1;} // Multiple-Semipartial Korrelation 
	
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'R' ) {sw_fn=1;sw_fn_1 = 1;} // Partial-Korrelation
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // Semipartial-Korrelation

	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'K' ) {sw_fn=1;sw_fn_1 = 1;} // Betagewicht zur Multiplen-Korrelation R
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'R' 
													   && arg0_[index0+3] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // Multiple-Korrelation Rc12k
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'R' ) {sw_fn=1;sw_fn_1 = 1;} // Multiple-Korrelation Rc12
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'C' ) {sw_fn=1;sw_fn_1 = 1;} // Multipler-Regressionskoeffizient ac12
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // Schrumpfungskorrektur
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'K' ) {sw_fn=1;sw_fn_1 = 1;} // F-wert zur Multiplen-Korrelation 
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'R' && arg0_[index0+2] == 'I' ) {sw_fn=1;sw_fn_1 = 1;} // rii zur inversen R 
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // t-wert zum Beta-Gewicht bi
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'C' ) {sw_fn=1;sw_fn_1 = 1;} // Rohwertgewicht bci
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'R' ) {sw_fn=1;sw_fn_1 = 1;} // z-wert zur Partialkorrelation
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // F-wert zur Multiplen Partialkorrelation
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'U' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // t-wert für 1 Gruppe
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'I' && arg0_[index0+2] == 'G' ) {sw_fn=1;sw_fn_1 = 1;} // signifikanzniveau
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'T' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // t-wert für 1 Gruppe
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'Q' ) {sw_fn=1;sw_fn_1 = 1;} // Matrizen-Quadrierung
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // Varianz x
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // SEM x
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'O' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // Covarianz x
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'O' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // Korrelation x
	if (arg0_[index0] == 'Q' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'U' 
													   && arg0_[index0+3] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // Quadratsumme
	if (arg0_[index0] == 'X' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'U' 
													   && arg0_[index0+3] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // xy summe
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // xy AM
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // SD geschätzt x
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'D' ) {sw_fn=1;sw_fn_1 = 1;} // SD von SD geschätzt
	if (arg0_[index0] == 'E' && arg0_[index0+1] == 'U' && arg0_[index0+2] == 'L' ) {sw_fn=1;sw_fn_1 = 1;} // Eulersche zahl
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'I' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // pi zahl
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'I' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // Vertrauensbereich
	if (arg0_[index0] == 'E' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'G' ) {sw_fn=1;sw_fn_1 = 1;} // Effektgrösse
	if (arg0_[index0] == 'X' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'A' ) {sw_fn=1;sw_fn_1 = 1;} // xcrit alpha
	if (arg0_[index0] == 'X' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'B' ) {sw_fn=1;sw_fn_1 = 1;} // xcrit beta
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'I' ) {sw_fn=1;sw_fn_1 = 1;} // alpha niveau
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'I' ) {sw_fn=1;sw_fn_1 = 1;} // beta niveau
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'B' ) {sw_fn=1;sw_fn_1 = 1;} // Teststärke
	if (arg0_[index0] == 'O' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // optimal n
	if (arg0_[index0] == 'E' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // Effektstärke
	if (arg0_[index0] == 'O' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // optimal p
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // schwellenwert
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '0' ) {sw_fn=1;sw_fn_1 = 1;} // Binomialtest P0
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '1' ) {sw_fn=1;sw_fn_1 = 1;} // Binomialtest pexact1
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '2' ) {sw_fn=1;sw_fn_1 = 1;} // Binomialtest pexact2
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'G' && arg0_[index0+2] == '0' ) {sw_fn=1;sw_fn_1 = 1;} // Hypergeo 2x2x2 P0
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'G' && arg0_[index0+2] == '1' ) {sw_fn=1;sw_fn_1 = 1;} // Hypergeo 2x2x2 p1 (z-approx)
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'G' ) {sw_fn=1;sw_fn_1 = 1;} // z-wert zu Hypergeo 2x2x2 
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // z-wert zu Binomialtest
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // z-wert zum 4-Feldertest
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'G' && arg0_[index0+2] == '2' ) {sw_fn=1;sw_fn_1 = 1;} // Hypergeo 2x2x2 p2 (permutiert)
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '1' ) {sw_fn=1;sw_fn_1 = 1;} // Funktionsgerüst 1
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '2' ) {sw_fn=1;sw_fn_1 = 1;} // Funktionsgerüst 2
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '3' ) {sw_fn=1;sw_fn_1 = 1;} // Funktionsgerüst 3
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '4' ) {sw_fn=1;sw_fn_1 = 1;} // Funktionsgerüst 4
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '5' ) {sw_fn=1;sw_fn_1 = 1;} // Funktionsgerüst 5
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '6' ) {sw_fn=1;sw_fn_1 = 1;} // Funktionsgerüst 6
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '7' ) {sw_fn=1;sw_fn_1 = 1;} // Funktionsgerüst 7
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '8' ) {sw_fn=1;sw_fn_1 = 1;} // Funktionsgerüst 8
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '9' ) {sw_fn=1;sw_fn_1 = 1;} // Funktionsgerüst 9
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '0' ) {sw_fn=1;sw_fn_1 = 1;} // Funktionsgerüst 0
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'V' ) {sw_fn=1;sw_fn_1 = 1;} // Zufallsvektorelement
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'L' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // kl Felder x2
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'A' ) {sw_fn=1;sw_fn_1 = 1;} // kfa
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'L' && arg0_[index0+2] == '0' ) {sw_fn=1;sw_fn_1 = 1;} // Hypergeo P0 kl
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'L' && arg0_[index0+2] == '2' ) {sw_fn=1;sw_fn_1 = 1;} // Hypergeo pexact2 kl
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '0' ) {sw_fn=1;sw_fn_1 = 1;} // Multinom P0 k
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '2' ) {sw_fn=1;sw_fn_1 = 1;} // Multinom pexact2 k
	if (arg0_[index0] == 'X' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'F' ) {sw_fn=1;sw_fn_1 = 1;} // x2-wert zu 2^k (2x2 fix)
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'F' && arg0_[index0+2] == '0' ) {sw_fn=1;sw_fn_1 = 1;} // Hypergeo P0 2^k (2x2 fix)
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'F' && arg0_[index0+2] == '2' ) {sw_fn=1;sw_fn_1 = 1;} // Hypergeo pexact2  2^k (2x2 fix)
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'F' ) {sw_fn=1;sw_fn_1 = 1;} // Kombinationen 2^k (2x2 fix)
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'L' ) {sw_fn=1;sw_fn_1 = 1;} // Kombinationen kl
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'G' ) {sw_fn=1;sw_fn_1 = 1;} // Kombinationen 2^k
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // Multiplikative Wkt
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'A' ) {sw_fn=1;sw_fn_1 = 1;} // Additive Wkt ausschl abh
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'U' ) {sw_fn=1;sw_fn_1 = 1;} // Additive Wkt einschl unabh
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // Additive Wkt unabh
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'A' ) {sw_fn=1;sw_fn_1 = 1;} // Additive Wkt einschl abh
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'A' ) {sw_fn=1;sw_fn_1 = 1;} // Bedingte Wkt 
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'A' ) {sw_fn=1;sw_fn_1 = 1;} // Totale Wkt
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'Y' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // Bayes Wkt
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'V' ) {sw_fn=1;sw_fn_1 = 1;} // Variationskoeffizient
	if (arg0_[index0] == 'L' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'O' ) {sw_fn=1;sw_fn_1 = 1;} // Lottosimulation
	if (arg0_[index0] == 'K' && arg0_[index0+1] == '_' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // C Matrix
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // wC Matrix
	if (arg0_[index0] == 'V' && arg0_[index0+1] == '_' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // V Matrix
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // wV Matrix
	if (arg0_[index0] == 'P' && arg0_[index0+1] == '_' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // P Matrix
	if (arg0_[index0] == 'P' && arg0_[index0+1] == '2' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // wP2 Matrix
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // wPm Matrix
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'Z' ) {sw_fn=1;sw_fn_1 = 1;} // z zu z_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'Z' ) {sw_fn=1;sw_fn_1 = 1;} // p zu z_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '1' && arg0_[index0+2] == 'Z' ) {sw_fn=1;sw_fn_1 = 1;} // pa1 zu z_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '2' && arg0_[index0+2] == 'Z' ) {sw_fn=1;sw_fn_1 = 1;} // pa2 zu z_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'Z' ) {sw_fn=1;sw_fn_1 = 1;} // d zu z_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // t zu t_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // p zu t_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '1' && arg0_[index0+2] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // pa1 zu t_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '2' && arg0_[index0+2] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // pa2 zu t_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // d zu t_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // x2 zu x2_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // p zu x2_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '1' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // pa1 zu x2_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '2' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // pa2 zu x2_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // d zu x2_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'F' ) {sw_fn=1;sw_fn_1 = 1;} // F zu F_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'F' ) {sw_fn=1;sw_fn_1 = 1;} // p zu F_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '1' && arg0_[index0+2] == 'F' ) {sw_fn=1;sw_fn_1 = 1;} // pa1 zu F_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '2' && arg0_[index0+2] == 'F' ) {sw_fn=1;sw_fn_1 = 1;} // pa2 zu F_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'F' ) {sw_fn=1;sw_fn_1 = 1;} // d zu F_wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'B' ) {sw_fn=1;sw_fn_1 = 1;} // Binomial P0 Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'B' ) {sw_fn=1;sw_fn_1 = 1;} // Binomial p  Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '1' && arg0_[index0+2] == 'B' ) {sw_fn=1;sw_fn_1 = 1;} // Binomial pexact1  Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '2' && arg0_[index0+2] == 'B' ) {sw_fn=1;sw_fn_1 = 1;} // Binomial pexact2  Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'H' ) {sw_fn=1;sw_fn_1 = 1;} // Hypergeo P0 Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'H' ) {sw_fn=1;sw_fn_1 = 1;} // Hypergeo p  Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '1' && arg0_[index0+2] == 'H' ) {sw_fn=1;sw_fn_1 = 1;} // Hypergeo pexact1  Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '2' && arg0_[index0+2] == 'H' ) {sw_fn=1;sw_fn_1 = 1;} // Hypergeo pexact2  Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'H' ) {sw_fn=1;sw_fn_1 = 1;} // 2x2C  Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'R' ) {sw_fn=1;sw_fn_1 = 1;} // RND  Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'K' ) {sw_fn=1;sw_fn_1 = 1;} // korr p  Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '1' && arg0_[index0+2] == 'K' ) {sw_fn=1;sw_fn_1 = 1;} // korr pa1  Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '2' && arg0_[index0+2] == 'K' ) {sw_fn=1;sw_fn_1 = 1;} // korr pa2  Tabelle
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // binomial µx
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // binomial sx
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // hypergeo µx
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // hypergeo sx
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'Y' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // Regressionskoeff ryx
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'V' && arg0_[index0+2] == 'A' ) {sw_fn=1;sw_fn_1 = 1;} // s zu s2g
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // s zu smg
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == '_' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // z-wert zu vektor x
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == '_' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // z-wert zu x
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'H' ) {sw_fn=1;sw_fn_1 = 1;} // schiefe
	if (arg0_[index0] == 'E' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'Z' ) {sw_fn=1;sw_fn_1 = 1;} // breite
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'H' ) {sw_fn=1;sw_fn_1 = 1;} // s zur schiefe
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // s zur breite
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'W' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // SW zu z
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'Q' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // IQ zu z
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'Q' && arg0_[index0+2] == 'K' ) {sw_fn=1;sw_fn_1 = 1;} // IQK zu z
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'W' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // C zu z
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // Sten zu z
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // stdnoten zu z
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '_' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // T zu z
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'H' ) {sw_fn=1;sw_fn_1 = 1;} // z zur schiefe
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // z zur breite
	if (arg0_[index0] == 'S' && arg0_[index0+1] == '_' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // S zu z
	if (arg0_[index0] == 'W' && arg0_[index0+1] == 'P' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // WP zu z
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'R' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // PR zu z
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == '_' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // Geschätzter pop z-wert zu vektor x
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // Geschätzte pop schiefe
	if (arg0_[index0] == 'E' && arg0_[index0+1] == 'Z' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // Geschätzte pop breite
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // F-Wert zu pa2 Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // t-Wert zu pa2 Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // x2-Wert zu pa2 Tabelle
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // R zu p
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // r zu p (t)
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'Z' ) {sw_fn=1;sw_fn_1 = 1;} // r zu p (Z)
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'R' && arg0_[index0+2] == 'P' ) {sw_fn=1;sw_fn_1 = 1;} // rxy.B zu p (Z)
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'R' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // r zu pa2 Tabelle (t)
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'Z' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // r zu pa2 Tabelle (Z)
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // R zu pa2 Tabelle 
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // rxy.B zu pa2 Tabelle (Z)
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'E' ) {sw_fn=1;sw_fn_1 = 1;} // pa2 zu e
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'E' ) {sw_fn=1;sw_fn_1 = 1;} // n zu e
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'E' ) {sw_fn=1;sw_fn_1 = 1;} // e zu pa2
	if (arg0_[index0] == 'O' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'Z' ) {sw_fn=1;sw_fn_1 = 1;} // optimal n(z)
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'D' ) {sw_fn=1;sw_fn_1 = 1;} // t -> p (integral)
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'D' ) {sw_fn=1;sw_fn_1 = 1;} // x2 -> p (integral)
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'D' ) {sw_fn=1;sw_fn_1 = 1;} // F -> p (integral)
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'V' ) {sw_fn=1;sw_fn_1 = 1;} // t vardiff korr
	if (arg0_[index0] == 'V' && arg0_[index0+1] == '_'                           ) {sw_fn=1;sw_fn_1 = 1;} // Gegen-faktoriell
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'N' ) {sw_fn=1;sw_fn_1 = 1;} // zufallsvektor nach verteilung
	if (arg0_[index0] == 'L' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // p -> L
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'L' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // L -> p
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'L' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // L -> d
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // Binomial Simulation
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // Hypergeo. Simulation
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'L' && arg0_[index0+2] == 'T' ) {sw_fn=1;sw_fn_1 = 1;} // Roulette Simulation
	if (arg0_[index0] == 'U' && arg0_[index0+1] == 'V' && arg0_[index0+2] == 'S' ) {sw_fn=1;sw_fn_1 = 1;} // 2 UV Simulation
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'X' ) {sw_fn=1;sw_fn_1 = 1;} // kurvenanpasung
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // p -> A
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // A -> p
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // A -> d
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // p -> V
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'V' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // V -> p
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'V' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // V -> d
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // p -> C
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // C -> p
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // C -> d
	if (arg0_[index0] == 'W' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // p -> W
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // W -> p
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'W' ) {sw_fn=1;sw_fn_1 = 1;} // W -> d
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'B' ) {sw_fn=1;sw_fn_1 = 1;} // zufallsmatrix bivar
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // GAMMA Integrale
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'M' ) {sw_fn=1;sw_fn_1 = 1;} // GAMMA Dichte
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'D' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // Kurven Differential
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'F' && arg0_[index0+2] == '_' ) {sw_fn=1;sw_fn_1 = 1;} // Kurven Integral
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'V' ) {sw_fn=1;sw_fn_1 = 1;} // z dichte vektor
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'V' ) {sw_fn=1;sw_fn_1 = 1;} // t dichte vektor
	if (arg0_[index0] == 'X' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'V' ) {sw_fn=1;sw_fn_1 = 1;} // x2 dichte vektor
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'V' ) {sw_fn=1;sw_fn_1 = 1;} // F dichte vektor
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'V' ) {sw_fn=1;sw_fn_1 = 1;} // Gamma vektor
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'V' ) {sw_fn=1;sw_fn_1 = 1;} // beta vektor
	if (arg0_[index0] == 'L' && arg0_[index0+1] == 'Z' && arg0_[index0+2] == 'V' ) {sw_fn=1;sw_fn_1 = 1;} // log z vektor
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'L' ) {sw_fn=1;sw_fn_1 = 1;} // Kurvenglättung
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'I' && arg0_[index0+2] == 'G' ) {sw_fn=1;sw_fn_1 = 1;} // GAMMA Volums-Integrale
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'D' && arg0_[index0+2] == '0' ) {sw_fn=1;sw_fn_1 = 1;} // Kurven Differential 0
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'F' && arg0_[index0+2] == '0' ) {sw_fn=1;sw_fn_1 = 1;} // Kurven Integral 0
	//////////////////////////////////////////////////////////////////////////////////////////////////////// Entsatz //
	
	
	// :
	// :
	// Funktionsdeklaration  //  1/4  
};


int funktions_decl_2(char arg0_[200], int index0, int index1)
{
	
	
	if (arg0_[index0] == 'L' && arg0_[index0+1] == 'O' && arg0_[index0+2] == 'G') {fn[index1] = 1;index0 +=2;}// log10
	if (arg0_[index0] == 'L' && arg0_[index0+1] == 'N' )        				{fn[index1] = 2;index0 +=1;}// loge
	if (arg0_[index0] == '!' )											    {fn[index1] = 3;index0 +=0;}// faktoriell
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'C' && arg0_[index0+3] == 'T') 
																			{fn[index1] = 3;index0 +=3;}// faktoriell 
	if (arg0_[index0] == '!' && arg0_[index0+1] == '!')							{fn[index1] = 4;index0 +=1;}// doppelfaktoriell
	if (arg0_[index0] == '!' && arg0_[index0+1] == '.' && arg0_[index0+2] == '!') {fn[index1] =217;index0 +=2;}// tripel Faktoriell
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'S') {fn[index1] = 5;index0 +=2;}// absolutwert
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'T' && arg0_[index0+3] == 'R') 
																			{fn[index1] = 6;index0 +=3;}// ganze zahl ohne rest
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'T' && arg0_[index0+3] == 'A')  
																			{fn[index1] = 7;index0 +=3;}// ganze zahl (aufgerundet)																		
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'T' && arg0_[index0+3] != 'R' && arg0_[index0+3] != 'A') 
																			{fn[index1] = 8;index0 +=2;}// ganze zahl (abgerundet)																										
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'S' && arg0_[index0+3] == 'T')
																			{fn[index1] = 9;index0 +=3;}// rest
	if (arg0_[index0] == 'N' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'R') {fn[index1] =10;index0 +=2;}// variation ohne wh
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'R' && arg0_[index0+2] == '_') {fn[index1] =10;index0 +=2;} 	
	if (arg0_[index0] == 'N' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'R') {fn[index1] =11;index0 +=2;}// kombination ohne wh = permutation zu 1 Klasse
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'M' && arg0_[index0+2] == '_') {fn[index1] =11;index0 +=2;} 
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'M' 
												   && arg0_[index0+3] == 'M'&& arg0_[index0+4] == 'A')     // gammafunktion
																			{fn[index1] =12;index0 +=4;}
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'Q' && arg0_[index0+2] == 'U') {fn[index1] =13;index0 +=2;}// quadrat
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'Q' && arg0_[index0+2] == 'R') {fn[index1] =14;index0 +=2;}// quadratwurzel
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'N') {fn[index1] =15;index0 +=2;}// vorzeichen des arguments
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'U' && arg0_[index0+2] == 'R') {fn[index1] =16;index0 +=2;}// kubikwurzel
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'U' && arg0_[index0+2] == 'B') {fn[index1] =17;index0 +=2;}// 3 Potenz
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'P') {fn[index1] =18;index0 +=2;}// reziprok
	if (arg0_[index0] == 'L' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'X') {fn[index1] =19;index0 +=2;}// logrithmus zur basis x
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W') {fn[index1] =20;index0 +=2;}// p -> z
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'Z' && arg0_[index0+2] == 'W') {fn[index1] =21;index0 +=2;}// z -> p
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'R' && arg0_[index0+2] == 'W') {fn[index1] =22;index0 +=2;}// variation mit wh
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'W') {fn[index1] =23;index0 +=2;}// kombination mit wh
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'M' && arg0_[index0+2] == '_') {fn[index1] =24;index0 +=2;}// permutation zu 1 Klasse
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'I' && arg0_[index0+2] == 'N') {fn[index1] =25;index0 +=2;}// sinus
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'N') {fn[index1] =26;index0 +=2;}// arcussinus
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'O' && arg0_[index0+2] == 'S') {fn[index1] =27;index0 +=2;}// cosinus
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'S') {fn[index1] =28;index0 +=2;}// arcuscosinus
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'N') {fn[index1] =29;index0 +=2;}// tangens
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'N') {fn[index1] =30;index0 +=2;}// arcustangens

	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'N') {fn[index1] =31;index0 +=2;}// hyp sinus
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'S') {fn[index1] =32;index0 +=2;}// hyp arcussinus
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'S') {fn[index1] =33;index0 +=2;}// hyp cosinus
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'C') {fn[index1] =34;index0 +=2;}// hyp arcuscosinus
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'N') {fn[index1] =35;index0 +=2;}// hyp tangens
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'T') {fn[index1] =36;index0 +=2;}// hyp arcustangens
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W') {fn[index1] =37;index0 +=2;}// p -> t
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'W') {fn[index1] =38;index0 +=2;}// t -> p
	if (arg0_[index0] == 'X' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W') {fn[index1] =39;index0 +=2;}// p -> x2
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'W') {fn[index1] =40;index0 +=2;}// x2 -> p
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W') {fn[index1] =41;index0 +=2;}// p -> F
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'W') {fn[index1] =42;index0 +=2;}// F -> p
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'D') {fn[index1] =43;index0 +=2;}// Quasizufallszahl
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'Z' && arg0_[index0+2] == 'R') {fn[index1] =44;index0 +=2;}// r -> Fisher-Z
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'Z') {fn[index1] =45;index0 +=2;}// Fisher-Z -> r
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'M' && arg0_[index0+2] == '_') {fn[index1] =46;index0 +=2;}// AM
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'U' && arg0_[index0+2] == 'M') {fn[index1] =47;index0 +=2;}// SUM
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'D' && arg0_[index0+2] == '_') {fn[index1] =48;index0 +=2;}// SD
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'A' && arg0_[index0+2] == '_') {fn[index1] =49;index0 +=2;}// Varianz
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'G') {fn[index1] =188;index0 +=2;}// SD geschätzt 
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'G') {fn[index1] =189;index0 +=2;}// Varianz geschätzt
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'G') {fn[index1] =190;index0 +=2;}// standardfehler des mittelwertes geschätzt
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'U' 
												   && arg0_[index0+3] == 'M') {fn[index1] =50;index0 +=3;}// Produktsumme
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'M' && arg0_[index0+2] == '_') {fn[index1] =51;index0 +=2;}// GM
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'M' && arg0_[index0+2] == '_') {fn[index1] =52;index0 +=2;}// HM
	if (arg0_[index0] == 'D' && arg0_[index0+1] == '_' && arg0_[index0+2] == '_') {fn[index1] =53;index0 +=2;}// Schrausser's d
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'V' && arg0_[index0+2] == 'A'  
						   && arg0_[index0+3] == 'R' && arg0_[index0+4] == 'O') {fn[index1] =54;index0 +=4;}// DvarO
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'O' && arg0_[index0+2] == 'R') {fn[index1] =55;index0 +=2;}// Produktmoment Korrelation r
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'O' && arg0_[index0+2] == 'V') {fn[index1] =56;index0 +=2;}// Kovarianz
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'T') {fn[index1] =57;index0 +=2;}// Determinationskoeffizient
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'D') {fn[index1] =58;index0 +=2;}// Redundanz
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'Y' && arg0_[index0+2] == 'X') {fn[index1] =59;index0 +=2;}// Regressionskoeffizient ayx
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'Y' && arg0_[index0+2] == 'X') {fn[index1] =60;index0 +=2;}// Regressionskoeffizient byx
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'Y') {fn[index1] =61;index0 +=2;}// Regressionskoeffizient axy
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'Y') {fn[index1] =62;index0 +=2;}// Regressionskoeffizient bxy
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'R' && arg0_[index0+2] == 'W') {fn[index1] =63;index0 +=2;}// r -> t
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'R' && arg0_[index0+2] == 'R') {fn[index1] =64;index0 +=2;}// Korrelationsdifferenz
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'Z') {fn[index1] =65;index0 +=2;}// SD zu Fishers Z
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'W') {fn[index1] =66;index0 +=2;}// Permutation zu den Klassen k1,k2,...,kn
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'U' && arg0_[index0+2] == '_') {fn[index1] =67;index0 +=2;}// t-wert für unverbundene stichproben
	//if (arg0_[index0] == 'T' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'C') {fn[index1] =68;index0 +=2;}// df korrektur zu t-wert uv bei varianzheterogenität (t-wert korrektur ...)
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'V' && arg0_[index0+2] == '_') {fn[index1] =69;index0 +=2;}// t-wert für verbundene stichproben
	if (arg0_[index0] == 'E' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'X') {fn[index1] =70;index0 +=2;}// eindimensionales chi2
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'Q' && arg0_[index0+2] == 'T') {fn[index1] =71;index0 +=2;}// Cochrans Q Test
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'I' && arg0_[index0+2] == 'N') {fn[index1] =72;index0 +=2;}// Minimalwert von vektor x
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'X') {fn[index1] =73;index0 +=2;}// Maximalwert von vektor x
	if (arg0_[index0] == 'N' && arg0_[index0+1] == '_' && arg0_[index0+2] == '_') {fn[index1] =74;index0 +=2;}// Wertumfang n von vektor x
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'G') {fn[index1] =75;index0 +=2;}// Wertbreite von vektor x
	if (arg0_[index0] == 'U' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'S' 
												       && arg0_[index0+3] == '_') {fn[index1] =76;index0 +=3;}// U-Test, U-Wert
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'U' && arg0_[index0+2] == 'T' 
												       && arg0_[index0+3] == 'S') {fn[index1] =77;index0 +=3;}// U-Test, sU-Wert
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'U' && arg0_[index0+2] == 'T' 
												       && arg0_[index0+3] == 'S') {fn[index1] =78;index0 +=3;}// U-Test, mU-Wert
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'U' && arg0_[index0+2] == 'T' 
												       && arg0_[index0+3] == 'S') {fn[index1] =79;index0 +=3;}// U-Test, z-Wert
	if (arg0_[index0] == 'W' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'S' 
												       && arg0_[index0+3] == '_') {fn[index1] =80;index0 +=3;}// Wilcoxon-Test, T-Wert
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'T' 
												       && arg0_[index0+3] == 'S') {fn[index1] =81;index0 +=3;}// Wilcoxon-Test, sT-Wert
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'T' 
												       && arg0_[index0+3] == 'S') {fn[index1] =82;index0 +=3;}// Wilcoxon-Test, mT-Wert
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'T' 
												       && arg0_[index0+3] == 'S') {fn[index1] =83;index0 +=3;}// Wilcoxon-Test, z-Wert
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'U' 
												       && arg0_[index0+3] == 'M') {fn[index1] =84;index0 +=3;}// Rangsumme
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'R' && arg0_[index0+2] == '_') {fn[index1] =85;index0 +=2;}// Rangmittel
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'R' && arg0_[index0+2] == 'S') {fn[index1] =86;index0 +=2;}// Rangkorrelation rs
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'N') {fn[index1] =88;index0 +=2;}// Reduktion von x
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'D' && arg0_[index0+2] == '_') {fn[index1] =89;index0 +=2;}// Medianwert von Vektor x
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'X') {fn[index1] =90;index0 +=2;}// 4-Felder chi2
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'X') {fn[index1] =91;index0 +=2;}// McNemar chi2
    if (arg0_[index0] == 'V' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'Y' 
													   && arg0_[index0+3] == 'X') {fn[index1] =92;index0 +=3;}// 4-Felder chi2 kontinuitätskorrigiert
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'Y' 
													   && arg0_[index0+3] == 'X') {fn[index1] =93;index0 +=3;}// McNemar chi2 kontinuitätskorrigiert
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'H') {fn[index1] =94;index0 +=2;}// Phi Korrelation
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'M') {fn[index1] =95;index0 +=2;}// Phi Korrelation max
	if (arg0_[index0] == 'X' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'P') {fn[index1] =96;index0 +=2;}// x2 zur Phi Korrelation 
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'E' 
													   && arg0_[index0+3] == 'T') {fn[index1] =97;index0 +=3;}// Tetrachorische Korrelation
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'D') {fn[index1] =98;index0 +=2;}// DEG -> RAD 
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'G') {fn[index1] =99;index0 +=2;} // RAD -> DEG
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'R' && arg0_[index0+2] == 'A'  
	                                                   && arg0_[index0+3] == 'D') {fn[index1] =100;index0 +=3;}// DEG -> GRAD
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'R') {fn[index1] =101;index0 +=2;}// GRAD -> DEG
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'O' && arg0_[index0+2] == 'T') {fn[index1] =102;index0 +=2;}// cotangens
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'C') {fn[index1] =103;index0 +=2;}// secans
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'E') {fn[index1] =104;index0 +=2;}// cosecans
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'T') {fn[index1] =105;index0 +=2;}// hyp cotangens
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'E') {fn[index1] =106;index0 +=2;}// hyp secans
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'E') {fn[index1] =107;index0 +=2;}// hyp cosecans
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'T') {fn[index1] =108;index0 +=2;}// arcuscotangens
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'E') {fn[index1] =109;index0 +=2;}// arcussecans
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'E') {fn[index1] =110;index0 +=2;}// arcuscosecans
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'G') {fn[index1] =111;index0 +=2;}// hyp arcuscotangens
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'N') {fn[index1] =112;index0 +=2;}// hyp arcussecans
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'O') {fn[index1] =113;index0 +=2;}// hyp arcuscosecans
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'Z' && arg0_[index0+2] == 'W') {fn[index1] =114;index0 +=2;}// z -> d
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'E' 
													   && arg0_[index0+3] == 'T') {fn[index1] =115;index0 +=3;}// s zur Tetrachorischen Korrelation
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'E' 
													   && arg0_[index0+3] == 'T') {fn[index1] =116;index0 +=3;}// z-wert zur Tetrachorischen Korrelation
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'B') {fn[index1] =117;index0 +=2;}// Punktbiserale Korrelation
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'S') {fn[index1] =119;index0 +=2;}// biserale Korrelation
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'S') {fn[index1] =120;index0 +=2;}// s zur biseralen Korrelation
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'S') {fn[index1] =121;index0 +=2;}// z-wert zur biseralen Korrelation
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'K') {fn[index1] =122;index0 +=2;}// rpb (r) -> rbis
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'R') {fn[index1] =123;index0 +=2;}// biserale Rang Korrelation
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'R') {fn[index1] =124;index0 +=2;}// z-wert zur biseralen Rang Korrelation
	if (arg0_[index0] == ';' )                                                    {fn[index1] =125;index0 +=0;}// n über k
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'W') {fn[index1] =126;index0 +=2;}// Binomialwahrscheinlichkeit
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'P') {fn[index1] =127;index0 +=2;}// Binomialpunktwahrscheinlichkeit
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'P') {fn[index1] =128;index0 +=2;}// Multinomialpunktwahrscheinlichkeit
	if (arg0_[index0] == 'N' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'W') {fn[index1] =129;index0 +=2;}// Negative Binomialwahrscheinlichkeit 
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'W') {fn[index1] =130;index0 +=2;}// Hypergeomerische Wahrscheinlichkeit
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'P') {fn[index1] =131;index0 +=2;}// Hypergeomerische Punktwahrscheinlichkeit
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'W') {fn[index1] =132;index0 +=2;}// Geomerische Wahrscheinlichkeit
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'P') {fn[index1] =133;index0 +=2;}// Geomerische Punktwahrscheinlichkeit
	if (arg0_[index0] == 'N' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'P') {fn[index1] =134;index0 +=2;}// Negative Binomialpunktwahrscheinlichkeit
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'W') {fn[index1] =135;index0 +=2;}// Poissonwahrscheinlichkeit
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'P') {fn[index1] =136;index0 +=2;}// Poissonpunktwahrscheinlichkeit
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'W') {fn[index1] =137;index0 +=2;}// d -> z
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'O' && arg0_[index0+2] == 'R' 
													   && arg0_[index0+3] == 'M') {fn[index1] =138;index0 +=3;}// Zahlenausgabeformat
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'A' 
                                                       && arg0_[index0+3] == 'M') {fn[index1] =139;index0 +=3;}// invers a gamma funktion
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'A' 
                                                       && arg0_[index0+3] == 'M') {fn[index1] =140;index0 +=3;}// invers b gamma funktion
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'A') {fn[index1] =141;index0 +=2;}// alternierende Reduktion
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'Z' && arg0_[index0+2] == 'D') {fn[index1] =142;index0 +=2;}// z -> p (integral)
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'G') {fn[index1] =143;index0 +=2;}// gewichtetes arithmetisches mittel
	if (arg0_[index0] == 'E' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'P') {fn[index1] =144;index0 +=2;}// eulersche zahl (grenzwertformulierung)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'C' 
                                                       && arg0_[index0+3] == 'T') {fn[index1] =145;index0 +=3;}// arcuscotangens (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'S' 
                                                       && arg0_[index0+3] == 'E') {fn[index1] =146;index0 +=3;}// arcussecans (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'C' 
                                                       && arg0_[index0+3] == 'E') {fn[index1] =147;index0 +=3;}// arcuscosecans (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'H' 
                                                       && arg0_[index0+3] == 'S') {fn[index1] =148;index0 +=3;}// hyp arcussinus (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'H' 
                                                       && arg0_[index0+3] == 'C') {fn[index1] =149;index0 +=3;}// hyp arcuscosinus (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'H' 
                                                       && arg0_[index0+3] == 'T') {fn[index1] =150;index0 +=3;}// hyp arcustangns (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'H' 
                                                       && arg0_[index0+3] == 'G') {fn[index1] =151;index0 +=3;}// hyp arcuscotangns (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'H' 
                                                       && arg0_[index0+3] == 'N') {fn[index1] =152;index0 +=3;}// hyp arcussecans (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'H' 
                                                       && arg0_[index0+3] == 'O') {fn[index1] =153;index0 +=3;}// hyp arcuscosecans (Iteratives Näherungsverfahren)
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'Z') {fn[index1] =154;index0 +=2;}// Gemitteltes Fisher Z
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'W') {fn[index1] =155;index0 +=2;}// t -> d
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'W') {fn[index1] =156;index0 +=2;}// x -> d
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'W') {fn[index1] =157;index0 +=2;}// F -> d
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'A' 
                                                       && arg0_[index0+3] == 'M') {fn[index1] =158;index0 +=3;}// gamma dichtefunktion
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'X' && arg0_[index0+2] == '0') {fn[index1] =159;index0 +=2;}// Fisher Exact P0
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'X' && arg0_[index0+2] == '1') {fn[index1] =160;index0 +=2;}// Fisher Exact p.exact 1-seitig
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'X' && arg0_[index0+2] == '2') {fn[index1] =161;index0 +=2;}// Fisher Exact p.exact 2-seitig
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'A') {fn[index1] =162;index0 +=2;}// Matrizen-Addition
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'S') {fn[index1] =163;index0 +=2;}// Matrizen-Subtraktion
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'T') {fn[index1] =164;index0 +=2;}// Matrizen-Transponierung
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'P') {fn[index1] =165;index0 +=2;}// Spur einer Matrix
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'I') {fn[index1] =166;index0 +=2;}// Matrizen-Invertierung
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'T') {fn[index1] =167;index0 +=2;}// Determinante einer Matrix
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'V') {fn[index1] =168;index0 +=2;}// Matrizen-Verkettung
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'M') {fn[index1] =169;index0 +=2;}// Matrizen-Multiplikation
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'R' 
                                                       && arg0_[index0+3] == 'B') {fn[index1] =183;index0 +=3;}// Multiple-Partial Korrelation 
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'S' 
                                                       && arg0_[index0+3] == 'B') {fn[index1] =184;index0 +=3;}// Multiple-Semipartial Korrelation 


	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'R') {fn[index1] =170;index0 +=2;}// Partial-Korrelation
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'S') {fn[index1] =171;index0 +=2;}// Semipartial-Korrelation
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'K') {fn[index1] =173;index0 +=2;}// Betagewicht zur Multiplen-Korrelation R
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'R' 
                                                       && arg0_[index0+3] == 'N') {fn[index1] =174;index0 +=3;}// Multiple-Korrelation Rc12k
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'R') {fn[index1] =172;index0 +=2;}// Multiple-Korrelation Rc12
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'C') {fn[index1] =175;index0 +=2;}// Multipler-Regressionskoeffizient ac12
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'M') {fn[index1] =176;index0 +=2;}// Schrumpfungskorrektur
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'K') {fn[index1] =177;index0 +=2;}// F-wert zur Multiplen-Korrelation 
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'R' && arg0_[index0+2] == 'I') {fn[index1] =178;index0 +=2;}// rii zur inversen R 
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'M') {fn[index1] =179;index0 +=2;}// t-wert zum Beta-Gewicht bi 
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'C') {fn[index1] =180;index0 +=2;}// Rohwertgewicht bci
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'R') {fn[index1] =181;index0 +=2;}// z-wert zur Partialkorrelation
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'P') {fn[index1] =182;index0 +=2;}// F-wert zur Multiplen Partialkorrelation
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'U' && arg0_[index0+2] == 'X') {fn[index1] =185;index0 +=2;}// t-wert für 2 unverbundene Gruppen aus mittelwerten
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'T' && arg0_[index0+2] == '_') {fn[index1] =186;index0 +=2;}// t-wert für 1 Gruppe
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'I' && arg0_[index0+2] == 'G') {fn[index1] =187;index0 +=2;}// signifikanzniveau
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'Q') {fn[index1] =191;index0 +=2;}// Matrizen-Quadrierung
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'X') {fn[index1] =192;index0 +=2;}// Varianz x
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'X') {fn[index1] =193;index0 +=2;}// SEM x
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'O' && arg0_[index0+2] == 'X') {fn[index1] =194;index0 +=2;}// Covarianz x
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'O' && arg0_[index0+2] == 'X') {fn[index1] =195;index0 +=2;}// Korrelation x
	if (arg0_[index0] == 'Q' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'U' 
                                                       && arg0_[index0+3] == 'M') {fn[index1] =196;index0 +=3;}// Quadratsumme
	if (arg0_[index0] == 'X' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'U' 
                                                       && arg0_[index0+3] == 'M') {fn[index1] =197;index0 +=3;}// xy summe
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'X') {fn[index1] =198;index0 +=2;}// xy AM
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'X') {fn[index1] =199;index0 +=2;}// SD geschätzt x
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'D') {fn[index1] =200;index0 +=2;}// SD von SD geschätzt
	if (arg0_[index0] == 'E' && arg0_[index0+1] == 'U' && arg0_[index0+2] == 'L') {fn[index1] =201;index0 +=2;}// Eulersche Zahl
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'I' && arg0_[index0+2] == '_') {fn[index1] =202;index0 +=2;}// pi Zahl
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'I' && arg0_[index0+2] == '_') {fn[index1] =203;index0 +=2;}// vertrauensbereich
	if (arg0_[index0] == 'E' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'G') {fn[index1] =204;index0 +=2;}// Effektgrösse
	if (arg0_[index0] == 'X' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'A') {fn[index1] =205;index0 +=2;}// xcrit alpha
	if (arg0_[index0] == 'X' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'B') {fn[index1] =206;index0 +=2;}// xcrit beta
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'I') {fn[index1] =207;index0 +=2;}// alpha niveau
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'I') {fn[index1] =208;index0 +=2;}// beta niveau
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'B') {fn[index1] =209;index0 +=2;}// Teststärke
	if (arg0_[index0] == 'O' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'N') {fn[index1] =210;index0 +=2;}// optimal n
	if (arg0_[index0] == 'E' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'S') {fn[index1] =211;index0 +=2;}// Effektstärke
	if (arg0_[index0] == 'O' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'P') {fn[index1] =212;index0 +=2;}// optimal p
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'X') {fn[index1] =213;index0 +=2;}// schwellenwert
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '0') {fn[index1] =214;index0 +=2;}// Binomialtest P0
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '1') {fn[index1] =215;index0 +=2;}// Binomialtest pexact1
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '2') {fn[index1] =216;index0 +=2;}// Binomialtest pexact2
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'G' && arg0_[index0+2] == '0') {fn[index1] =218;index0 +=2;}// Hypergeo 2x2x2 P0
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'G' && arg0_[index0+2] == '1') {fn[index1] =219;index0 +=2;}// Hypergeo 2x2x2 p1 (z-approx)
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'G') {fn[index1] =220;index0 +=2;}// z-wert zu Hypergeo 2x2x2 	
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'N') {fn[index1] =221;index0 +=2;}// z-wert zu Binomialtest
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'X') {fn[index1] =222;index0 +=2;}// z-wert zum 4-Feldertest
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'G' && arg0_[index0+2] == '2') {fn[index1] =223;index0 +=2;}// Hypergeo 2x2x2 p2 (permutiert)
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '1') {fn[index1] =224;index0 +=2;}// Funktionsgerüst 1
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '2') {fn[index1] =225;index0 +=2;}// Funktionsgerüst 2
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '3') {fn[index1] =226;index0 +=2;}// Funktionsgerüst 3
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '4') {fn[index1] =227;index0 +=2;}// Funktionsgerüst 4
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '5') {fn[index1] =228;index0 +=2;}// Funktionsgerüst 5
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '6') {fn[index1] =229;index0 +=2;}// Funktionsgerüst 6
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '7') {fn[index1] =230;index0 +=2;}// Funktionsgerüst 7
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '8') {fn[index1] =231;index0 +=2;}// Funktionsgerüst 8
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '9') {fn[index1] =232;index0 +=2;}// Funktionsgerüst 9
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '0') {fn[index1] =344;index0 +=2;}// Funktionsgerüst 0
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'V') {fn[index1] =233;index0 +=2;}// Zufallsvektorelement
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'L' && arg0_[index0+2] == 'X') {fn[index1] =234;index0 +=2;}// kl Felder x2
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'A') {fn[index1] =235;index0 +=2;}// kfa
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'L' && arg0_[index0+2] == '0') {fn[index1] =236;index0 +=2;}// Hypergeo P0 kl
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'L' && arg0_[index0+2] == '2') {fn[index1] =237;index0 +=2;}// Hypergeo pexact2 kl
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '0') {fn[index1] =238;index0 +=2;}// Multinom P0 k
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '2') {fn[index1] =239;index0 +=2;}// Multinom pexact2 k
	if (arg0_[index0] == 'X' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'F') {fn[index1] =240;index0 +=2;}// x2-wert zu 2^k (2x2 fix)
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'F' && arg0_[index0+2] == '0') {fn[index1] =241;index0 +=2;}// Hypergeo P0 2^k (2x2 fix)
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'F' && arg0_[index0+2] == '2') {fn[index1] =242;index0 +=2;}// Hypergeo pexact2 2^k (2x2 fix)
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'F') {fn[index1] =243;index0 +=2;}// Kombinationen 2^k (2x2 fix)
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'L') {fn[index1] =244;index0 +=2;}// Kombinationen kl
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'G') {fn[index1] =245;index0 +=2;}// Kombinationen 2^k
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W') {fn[index1] =246;index0 +=2;}// Multiplikative Wkt
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'A') {fn[index1] =247;index0 +=2;}// Additive Wkt ausschl abh
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'U') {fn[index1] =248;index0 +=2;}// Additive Wkt einschl unabh
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'N') {fn[index1] =249;index0 +=2;}// Additive Wkt unabh
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'A') {fn[index1] =250;index0 +=2;}// Additive Wkt einschl abh
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'A') {fn[index1] =251;index0 +=2;}// Bedingte Wkt 
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'A') {fn[index1] =252;index0 +=2;}// Totale Wkt
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'Y' && arg0_[index0+2] == 'S') {fn[index1] =253;index0 +=2;}// Bayes Wkt
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'V') {fn[index1] =254;index0 +=2;}// Variationskoeffizient
	if (arg0_[index0] == 'L' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'O') {fn[index1] =255;index0 +=2;}// Lottosimulation
	if (arg0_[index0] == 'K' && arg0_[index0+1] == '_' && arg0_[index0+2] == 'M') {fn[index1] =256;index0 +=2;}// C Matrix
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'M') {fn[index1] =257;index0 +=2;}// wC Matrix
	if (arg0_[index0] == 'V' && arg0_[index0+1] == '_' && arg0_[index0+2] == 'M') {fn[index1] =258;index0 +=2;}// V Matrix
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'M') {fn[index1] =259;index0 +=2;}// wV Matrix
	if (arg0_[index0] == 'P' && arg0_[index0+1] == '_' && arg0_[index0+2] == 'M') {fn[index1] =260;index0 +=2;}// P Matrix
	if (arg0_[index0] == 'P' && arg0_[index0+1] == '2' && arg0_[index0+2] == 'M') {fn[index1] =261;index0 +=2;}// wP2 Matrix
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'M') {fn[index1] =262;index0 +=2;}// wPm Matrix
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'Z') {fn[index1] =263;index0 +=2;}// z zu z-wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'Z') {fn[index1] =264;index0 +=2;}// p zu z-wert Tabelle	
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '1' && arg0_[index0+2] == 'Z') {fn[index1] =265;index0 +=2;}// pa1 zu z-wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '2' && arg0_[index0+2] == 'Z') {fn[index1] =266;index0 +=2;}// pa2 zu z-wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'Z') {fn[index1] =267;index0 +=2;}// d zu z-wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'T') {fn[index1] =268;index0 +=2;}// t zu t-wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'T') {fn[index1] =269;index0 +=2;}// p zu t-wert Tabelle	
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '1' && arg0_[index0+2] == 'T') {fn[index1] =270;index0 +=2;}// pa1 zu t-wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '2' && arg0_[index0+2] == 'T') {fn[index1] =271;index0 +=2;}// pa2 zu t-wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'T') {fn[index1] =272;index0 +=2;}// d zu t-wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'X') {fn[index1] =273;index0 +=2;}// x2 zu x2-wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'X') {fn[index1] =274;index0 +=2;}// p zu x2-wert Tabelle	
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '1' && arg0_[index0+2] == 'X') {fn[index1] =275;index0 +=2;}// pa1 zu x2-wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '2' && arg0_[index0+2] == 'X') {fn[index1] =276;index0 +=2;}// pa2 zu x2-wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'X') {fn[index1] =277;index0 +=2;}// d zu x2-wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'F') {fn[index1] =278;index0 +=2;}// F zu F-wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'F') {fn[index1] =279;index0 +=2;}// p zu F-wert Tabelle	
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '1' && arg0_[index0+2] == 'F') {fn[index1] =280;index0 +=2;}// pa1 zu F-wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '2' && arg0_[index0+2] == 'F') {fn[index1] =281;index0 +=2;}// pa2 zu F-wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'D' && arg0_[index0+2] == 'F') {fn[index1] =282;index0 +=2;}// d zu F-wert Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'B') {fn[index1] =283;index0 +=2;}// Binomial P0 Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'B') {fn[index1] =284;index0 +=2;}// Binomial p Tabelle	
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '1' && arg0_[index0+2] == 'B') {fn[index1] =285;index0 +=2;}// Binomial pexact1 Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '2' && arg0_[index0+2] == 'B') {fn[index1] =286;index0 +=2;}// Binomial pexact2 Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'H') {fn[index1] =287;index0 +=2;}// Hypergeo P0 Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'H') {fn[index1] =288;index0 +=2;}// Hypergeo p Tabelle	
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '1' && arg0_[index0+2] == 'H') {fn[index1] =289;index0 +=2;}// Hypergeo pexact1 Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '2' && arg0_[index0+2] == 'H') {fn[index1] =290;index0 +=2;}// Hypergeo pexact2 Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'H') {fn[index1] =291;index0 +=2;}// 2x2C Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'B' && arg0_[index0+2] == 'R') {fn[index1] =292;index0 +=2;}// RND Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'K') {fn[index1] =293;index0 +=2;}// korr p Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '1' && arg0_[index0+2] == 'K') {fn[index1] =294;index0 +=2;}// korr pa1 Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '2' && arg0_[index0+2] == 'K') {fn[index1] =295;index0 +=2;}// korr pa2 Tabelle
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'M') {fn[index1] =296;index0 +=2;}// binomial µx
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'S') {fn[index1] =297;index0 +=2;}// binomial sx
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'M') {fn[index1] =298;index0 +=2;}// hypergeo µx
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'S') {fn[index1] =299;index0 +=2;}// hypergeo sx
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'Y' && arg0_[index0+2] == 'X') {fn[index1] =300;index0 +=2;}// Regressionskoeff ryx
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'V' && arg0_[index0+2] == 'A') {fn[index1] =301;index0 +=2;}// s zu s2g
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'M') {fn[index1] =302;index0 +=2;}// s zu smg
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == '_' && arg0_[index0+2] == 'W') {fn[index1] =303;index0 +=2;}// z-wert zu vektor x
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == '_' && arg0_[index0+2] == '_') {fn[index1] =304;index0 +=2;}// z-wert zu x
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'H') {fn[index1] =305;index0 +=2;}// schiefe
	if (arg0_[index0] == 'E' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'Z') {fn[index1] =306;index0 +=2;}// breite
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'H') {fn[index1] =307;index0 +=2;}// s zur schiefe
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'X') {fn[index1] =308;index0 +=2;}// s zur breite
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'W' && arg0_[index0+2] == '_') {fn[index1] =309;index0 +=2;}// SW zu z
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'Q' && arg0_[index0+2] == '_') {fn[index1] =310;index0 +=2;}// IQ zu z
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'Q' && arg0_[index0+2] == 'K') {fn[index1] =311;index0 +=2;}// IQK zu z
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'W' && arg0_[index0+2] == '_') {fn[index1] =312;index0 +=2;}// C zu z
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'N') {fn[index1] =313;index0 +=2;}// Sten zu z
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'N' && arg0_[index0+2] == '_') {fn[index1] =314;index0 +=2;}// stdnoten zu z
	if (arg0_[index0] == 'T' && arg0_[index0+1] == '_' && arg0_[index0+2] == '_') {fn[index1] =315;index0 +=2;}// T zu z
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'H') {fn[index1] =316;index0 +=2;}// z zur schiefe
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'X') {fn[index1] =317;index0 +=2;}// z zur breite
	if (arg0_[index0] == 'S' && arg0_[index0+1] == '_' && arg0_[index0+2] == '_') {fn[index1] =318;index0 +=2;}// S zu z
	if (arg0_[index0] == 'W' && arg0_[index0+1] == 'P' && arg0_[index0+2] == '_') {fn[index1] =319;index0 +=2;}// WP zu z
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'R' && arg0_[index0+2] == '_') {fn[index1] =320;index0 +=2;}// PR zu z
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == '_' && arg0_[index0+2] == 'P') {fn[index1] =321;index0 +=2;}// Geschätzter pop z-wert zu vektor x
	if (arg0_[index0] == 'S' && arg0_[index0+1] == 'H' && arg0_[index0+2] == 'P') {fn[index1] =322;index0 +=2;}// Geschätzte pop schiefe
	if (arg0_[index0] == 'E' && arg0_[index0+1] == 'Z' && arg0_[index0+2] == 'P') {fn[index1] =323;index0 +=2;}// Geschätzte pop breite
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'S') {fn[index1] =324;index0 +=2;}// F-wert zu pa2 Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'S') {fn[index1] =325;index0 +=2;}// t-wert zu pa2 Tabelle
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'S') {fn[index1] =326;index0 +=2;}// x2-wert zu pa2 Tabelle
	if (arg0_[index0] == 'M' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'P') {fn[index1] =327;index0 +=2;}// R zu p
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'T') {fn[index1] =328;index0 +=2;}// r zu p (t)
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'Z') {fn[index1] =329;index0 +=2;}// r zu p (Z)
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'R' && arg0_[index0+2] == 'P') {fn[index1] =330;index0 +=2;}// rxy.B zu p (Z)
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'R' && arg0_[index0+2] == 'S') {fn[index1] =331;index0 +=2;}// r zu pa2 Tabelle (t)
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'Z' && arg0_[index0+2] == 'S') {fn[index1] =332;index0 +=2;}// r zu pa2 Tabelle (Z)
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'M' && arg0_[index0+2] == 'S') {fn[index1] =333;index0 +=2;}// R zu pa2 Tabelle 
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'S') {fn[index1] =334;index0 +=2;}// rxy.B zu pa2 Tabelle (Z)
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'E') {fn[index1] =335;index0 +=2;}// pa2 zu e
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'E') {fn[index1] =336;index0 +=2;}// n zu e
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'E' && arg0_[index0+2] == 'E') {fn[index1] =337;index0 +=2;}// e zu pa2
	if (arg0_[index0] == 'O' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'Z') {fn[index1] =338;index0 +=2;}// optimal n(z)
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'T' && arg0_[index0+2] == 'D') {fn[index1] =339;index0 +=2;}// t -> p (integral)
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'X' && arg0_[index0+2] == 'D') {fn[index1] =340;index0 +=2;}// x2 -> p (integral)
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'D') {fn[index1] =341;index0 +=2;}// F -> p (integral)
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'K' && arg0_[index0+2] == 'V') {fn[index1] =342;index0 +=2;}// t vardiff korr
	if (arg0_[index0] == 'V' && arg0_[index0+1] == '_'                          ) {fn[index1] =343;index0 +=1;}// Gegen-faktoriell
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'N') {fn[index1] =345;index0 +=2;}// zufallsvektor nach verteilung
	if (arg0_[index0] == 'L' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W') {fn[index1] =346;index0 +=2;}// p -> L
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'L' && arg0_[index0+2] == 'W') {fn[index1] =347;index0 +=2;}// L -> p
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'L' && arg0_[index0+2] == 'W') {fn[index1] =348;index0 +=2;}// L -> d
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'M') {fn[index1] =349;index0 +=2;}// Binomial Simulation
	if (arg0_[index0] == 'H' && arg0_[index0+1] == 'S' && arg0_[index0+2] == 'M') {fn[index1] =350;index0 +=2;}// Hypergeo. Simulation
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'L' && arg0_[index0+2] == 'T') {fn[index1] =351;index0 +=2;}// Roulette Simulation
	if (arg0_[index0] == 'U' && arg0_[index0+1] == 'V' && arg0_[index0+2] == 'S') {fn[index1] =352;index0 +=2;}// 2 UV Simulation
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'X') {fn[index1] =353;index0 +=2;}// Kurvenanpassung
	if (arg0_[index0] == 'A' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W') {fn[index1] =354;index0 +=2;}// p -> A
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'W') {fn[index1] =355;index0 +=2;}// A -> p
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'A' && arg0_[index0+2] == 'W') {fn[index1] =356;index0 +=2;}// A -> d
	if (arg0_[index0] == 'V' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W') {fn[index1] =357;index0 +=2;}// p -> V
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'V' && arg0_[index0+2] == 'W') {fn[index1] =358;index0 +=2;}// V -> p
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'V' && arg0_[index0+2] == 'W') {fn[index1] =359;index0 +=2;}// V -> d
	if (arg0_[index0] == 'C' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W') {fn[index1] =360;index0 +=2;}// p -> C
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'W') {fn[index1] =361;index0 +=2;}// C -> p
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'C' && arg0_[index0+2] == 'W') {fn[index1] =362;index0 +=2;}// C -> d
	if (arg0_[index0] == 'W' && arg0_[index0+1] == 'P' && arg0_[index0+2] == 'W') {fn[index1] =363;index0 +=2;}// p -> W
	if (arg0_[index0] == 'P' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'W') {fn[index1] =364;index0 +=2;}// W -> p
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'W' && arg0_[index0+2] == 'W') {fn[index1] =365;index0 +=2;}// W -> d
	if (arg0_[index0] == 'R' && arg0_[index0+1] == 'N' && arg0_[index0+2] == 'B') {fn[index1] =366;index0 +=2;}// zufallsmatrix bivar
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'M') {fn[index1] =367;index0 +=2;}// GAMMA Integrale
	if (arg0_[index0] == 'D' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'M') {fn[index1] =368;index0 +=2;}// GAMMA Dichte
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'D' && arg0_[index0+2] == '_') {fn[index1] =369;index0 +=2;}// Kurven Differential
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'F' && arg0_[index0+2] == '_') {fn[index1] =370;index0 +=2;}// Kurven Integral
	if (arg0_[index0] == 'Z' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'V') {fn[index1] =371;index0 +=2;}// z-dichte vektor
	if (arg0_[index0] == 'T' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'V') {fn[index1] =372;index0 +=2;}// t-dichte vektor
	if (arg0_[index0] == 'X' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'V') {fn[index1] =373;index0 +=2;}// x2-dichte vektor
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'V') {fn[index1] =374;index0 +=2;}// F-dichte vektor
	if (arg0_[index0] == 'G' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'V') {fn[index1] =375;index0 +=2;}// Gamma vektor
	if (arg0_[index0] == 'B' && arg0_[index0+1] == 'F' && arg0_[index0+2] == 'V') {fn[index1] =376;index0 +=2;}// beta vektor
	if (arg0_[index0] == 'L' && arg0_[index0+1] == 'Z' && arg0_[index0+2] == 'V') {fn[index1] =377;index0 +=2;}// log z vektor
	if (arg0_[index0] == 'K' && arg0_[index0+1] == 'G' && arg0_[index0+2] == 'L') {fn[index1] =378;index0 +=2;}// Kurvenglättung
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'I' && arg0_[index0+2] == 'G') {fn[index1] =379;index0 +=2;}// GAMMA Volums-Integrale
	if (arg0_[index0] == 'F' && arg0_[index0+1] == 'D' && arg0_[index0+2] == '0') {fn[index1] =380;index0 +=2;}// Kurven Differential 0
	if (arg0_[index0] == 'I' && arg0_[index0+1] == 'F' && arg0_[index0+2] == '0') {fn[index1] =381;index0 +=2;}// Kurven Integral 0

	//                                                                                                
	// :
	// :
	// Funktionsdeklaration  //  2/4

	return index0;
};


void funktions_decl_3(int index1,double wert[100])
{
	for(iLauf=1;iLauf<=index1;iLauf++)//--------------------------------------------------------------> index1 = anzahl der argumente (werte) 
	{	
		if(fn[iLauf] == 1) wert[iLauf]=log10(wert[iLauf]);//------------------------------------------> log10
		if(fn[iLauf] == 2) wert[iLauf]=log(wert[iLauf]);//--------------------------------------------> loge
		if(fn[iLauf] == 3){faktoriell(wert[iLauf]); wert[iLauf]=fn_erg;} //---------------------------> faktoriell
		if(fn[iLauf] == 4){faktoriell_2(wert[iLauf]); wert[iLauf]=fn_erg;} //-------------------------> doppelfaktoriell
		if(fn[iLauf] == 217){faktoriell_4(wert[iLauf]); wert[iLauf]=fn_erg;} //-----------------------> tripelfaktoriell
		if(fn[iLauf] == 343){faktoriell_V(wert[iLauf]); wert[iLauf]=fn_erg;} //-----------------------> Gegen-faktoriell
		if(fn[iLauf] == 5) wert[iLauf]=fabs(wert[iLauf]);//-------------------------------------------> absolutwert
		if(fn[iLauf] == 6){zahl_0(wert[iLauf]); wert[iLauf]=fn_erg;} //-------------------------------> ganze zahl (ohne rest)  // INR
		if(fn[iLauf] == 7) wert[iLauf]=ceil(wert[iLauf]); //------------------------------------------> ganze zahl (aufgerundet) // INA
		if(fn[iLauf] == 8) wert[iLauf]=floor(wert[iLauf]); //-----------------------------------------> ganze zahl (abgerundet) // INT
		if(fn[iLauf] == 9){zahl_r(wert[iLauf]); wert[iLauf]=fn_erg;} //-------------------------------> rest 
		if(fn[iLauf] == 10)//-------------------------------------------------------------------------> variation ohne wh	
		 if(operat[iLauf] == 8){variation_(wert[iLauf],wert[iLauf+1]); wert[iLauf+1]=fn_erg;} 
		if(fn[iLauf] == 10)
		 if(operat[iLauf] != 8){printf("bad Formula ','"); exit(0);}
		if(fn[iLauf] == 11)//-------------------------------------------------------------------------> kombination ohne wh = permutation mit 2 klassen	
		 if(operat[iLauf] == 8){kombination_(wert[iLauf],wert[iLauf+1]); wert[iLauf+1]=fn_erg;} 
		if(fn[iLauf] == 11)
		 if(operat[iLauf] != 8){printf("bad Formula ','"); exit(0);}
		if(fn[iLauf] == 12){gamma(wert[iLauf]); wert[iLauf]=fn_erg;} //-------------------------------> gamma
				
		if(fn[iLauf] == 139){inv_gamma(wert[iLauf], 1); wert[iLauf]=fn_erg;}//------------------------> AGAM
		if(fn[iLauf] == 140){inv_gamma(wert[iLauf], 2); wert[iLauf]=fn_erg;}//------------------------> BGAM

		if(fn[iLauf] == 13) wert[iLauf]=pow(wert[iLauf],2); //----------------------------------------> quadrat
		if(fn[iLauf] == 14) wert[iLauf]=pow(wert[iLauf],0.5); //--------------------------------------> quadratwurzel
		if(fn[iLauf] == 15){vzeichen(wert[iLauf]); wert[iLauf]=fn_erg;} //----------------------------> vorzeichen des arguments
		if(fn[iLauf] == 16) //------------------------------------------------------------------------> kubikwurzel
		{
			if(wert[iLauf]<0)//bei x<0, n ungerade
			{
				wert[iLauf]=pow(-wert[iLauf],1.0/3);
				wert[iLauf]=-wert[iLauf];
			}
			if(wert[iLauf]>=0) wert[iLauf]=pow(wert[iLauf],1.0/3);
		} 
		if(fn[iLauf] == 17) wert[iLauf]=pow(wert[iLauf],3); //----------------------------------------> 3 Potenz
		if(fn[iLauf] == 18) wert[iLauf]=1/wert[iLauf]; //---------------------------------------------> reziprok
		if(fn[iLauf] == 19)//-------------------------------------------------------------------------> logarithmus zur basis x	
		 if(operat[iLauf] == 8){log_x(wert[iLauf],wert[iLauf+1]); wert[iLauf+1]=fn_erg;} 
		if(fn[iLauf] == 19)
		 if(operat[iLauf] != 8){printf("bad Formula ','"); exit(0);}
		if(fn[iLauf] == 20){zp_funktion(wert[iLauf]); wert[iLauf]=fn_erg;}//--------------------------> p -> z
		if(fn[iLauf] == 21){pz_funktion(wert[iLauf]); wert[iLauf]=fn_erg;}//--------------------------> z -> p
		if(fn[iLauf] == 22)//-------------------------------------------------------------------------> variation mit wh	
		 if(operat[iLauf] == 8){variation_w(wert[iLauf],wert[iLauf+1]); wert[iLauf+1]=fn_erg;} 
		if(fn[iLauf] == 22)
		 if(operat[iLauf] != 8){printf("bad Formula ','"); exit(0);}
		if(fn[iLauf] == 23)//-------------------------------------------------------------------------> kombination mit wh 
		 if(operat[iLauf] == 8){kombination_w(wert[iLauf],wert[iLauf+1]); wert[iLauf+1]=fn_erg;} 
		if(fn[iLauf] == 23)
		 if(operat[iLauf] != 8){printf("bad Formula ','"); exit(0);}
		if(fn[iLauf] == 24){permutation_(wert[iLauf]); wert[iLauf]=fn_erg;} //------------------------> permutation zu 1 Klasse
		//--------------------------------------------------------------------------------------------> winkelfunktionen in rad
		if(fn[iLauf] == 25) wert[iLauf]=sin(wert[iLauf]); //------------------------------------------> sinus
		if(fn[iLauf] == 26) wert[iLauf]=asin(wert[iLauf]); //-----------------------------------------> arcussinus (1/sin)
		if(fn[iLauf] == 27) wert[iLauf]=cos(wert[iLauf]); //------------------------------------------> cosinus
		if(fn[iLauf] == 28) wert[iLauf]=acos(wert[iLauf]); //-----------------------------------------> arcuscosinus (1/cos)
		if(fn[iLauf] == 29) wert[iLauf]=tan(wert[iLauf]); //------------------------------------------> tangens
		if(fn[iLauf] == 30) wert[iLauf]=atan(wert[iLauf]); //-----------------------------------------> arcustangens (1/tan)
		if(fn[iLauf] == 31) wert[iLauf]=sinh(wert[iLauf]); //-----------------------------------------> hyperbolischer sinus
		if(fn[iLauf] == 32) {fn_wfkt(wert[iLauf], 10); wert[iLauf]=fn_erg;} //------------------------> hyperbolischer arcussinus (1/sinh)
		if(fn[iLauf] == 33) wert[iLauf]=cosh(wert[iLauf]); //-----------------------------------------> hyperbolischer cosinus
		if(fn[iLauf] == 34) {fn_wfkt(wert[iLauf], 11); wert[iLauf]=fn_erg;} //------------------------> hyperbolischer arcuscosinus (1/cosh)
		if(fn[iLauf] == 35) wert[iLauf]=tanh(wert[iLauf]); //-----------------------------------------> hyperbolischer tangens
		if(fn[iLauf] == 36) {fn_wfkt(wert[iLauf], 12); wert[iLauf]=fn_erg;} //------------------------> hyperbolischer arcustangens (1/tanh)
		if(fn[iLauf] == 37)//-------------------------------------------------------------------------> p -> t
		 if(operat[iLauf] == 8){tp_funktion(wert[iLauf], wert[iLauf+1]); wert[iLauf+1]=fn_erg;}
		if(fn[iLauf] == 37)
		 if(operat[iLauf] != 8){printf("bad Formula ','\n"); exit(0);}
		if(fn[iLauf] == 38)//-------------------------------------------------------------------------> t -> p
		 if(operat[iLauf] == 8){pt_funktion(wert[iLauf], wert[iLauf+1]); wert[iLauf+1]=fn_erg;}
		if(fn[iLauf] == 38)
		 if(operat[iLauf] != 8){printf("bad Formula ','\n"); exit(0);}
		if(fn[iLauf] == 39)//-------------------------------------------------------------------------> p -> x2
		 if(operat[iLauf] == 8){xp_funktion(wert[iLauf], wert[iLauf+1]); wert[iLauf+1]=fn_erg;}
		if(fn[iLauf] == 39)
		 if(operat[iLauf] != 8){printf("bad Formula ','\n"); exit(0);}
		if(fn[iLauf] == 40)//-------------------------------------------------------------------------> x2 -> p
		 if(operat[iLauf] == 8){px_funktion(wert[iLauf], wert[iLauf+1]); wert[iLauf+1]=fn_erg;}
		if(fn[iLauf] == 40)
		 if(operat[iLauf] != 8){printf("bad Formula ','\n"); exit(0);}
		if(fn[iLauf] == 41)//-------------------------------------------------------------------------> p -> F
		 if(operat[iLauf] == 8)
		 {fp_funktion(wert[iLauf], wert[iLauf+1], wert[iLauf+2]); wert[iLauf+2]=fn_erg; fn_n=3;}
		if(fn[iLauf] == 41)
		 if(operat[iLauf] != 8){printf("bad Formula ','\n"); exit(0);}
		if(fn[iLauf] == 42)//-------------------------------------------------------------------------> F -> p
		 if(operat[iLauf] == 8)
		 {pf_funktion(wert[iLauf], wert[iLauf+1], wert[iLauf+2]); wert[iLauf+2]=fn_erg; fn_n=3;}
		if(fn[iLauf] == 42)
		 if(operat[iLauf] != 8 ){printf("bad Formula ','\n"); exit(0);}
		if(fn[iLauf] == 43)//-------------------------------------------------------------------------> Quasizufallszahl
		 if(operat[iLauf] == 8)
		 {qzufall(wert[iLauf], wert[iLauf+1], wert[iLauf+2]); wert[iLauf+2]=fn_erg; fn_n=3;}
		if(fn[iLauf] == 43)
		 if(operat[iLauf] != 8){printf("bad Formula ','\n"); exit(0);}
		if(fn[iLauf] == 44) wert[iLauf]=fisher_z(wert[iLauf],1); //-----------------------------------> r -> Fisher-Z
		if(fn[iLauf] == 45) wert[iLauf]=fisher_z(wert[iLauf],2); //-----------------------------------> Fisher-Z -> r
		if(fn[iLauf] == 46 || //----------------------------------------------------------------------> AM_ 
		   fn[iLauf] == 47 || //----------------------------------------------------------------------> SUM 
		   fn[iLauf] == 48 || //----------------------------------------------------------------------> SD_
		   fn[iLauf] == 49 || //----------------------------------------------------------------------> VA_
		   fn[iLauf] == 50 || //----------------------------------------------------------------------> PSUM
		   fn[iLauf] == 51 || //----------------------------------------------------------------------> GM
		   fn[iLauf] == 52 || //----------------------------------------------------------------------> HM
		   fn[iLauf] == 53 || //----------------------------------------------------------------------> Schrausser's d
		   fn[iLauf] == 54 || //----------------------------------------------------------------------> DvarO
		   fn[iLauf] == 55 || //----------------------------------------------------------------------> KOR
		   fn[iLauf] == 56 || //----------------------------------------------------------------------> COV
		   fn[iLauf] == 57 || //----------------------------------------------------------------------> DET
		   fn[iLauf] == 58 || //----------------------------------------------------------------------> RED
		   fn[iLauf] == 59 || //----------------------------------------------------------------------> AYX
		   fn[iLauf] == 60 || //----------------------------------------------------------------------> BYX
		   fn[iLauf] == 61 || //----------------------------------------------------------------------> AXY
		   fn[iLauf] == 62 || //----------------------------------------------------------------------> BXY
		   fn[iLauf] == 66 || //----------------------------------------------------------------------> PMW
		   //fn[iLauf] == 68 || //----------------------------------------------------------------------> TDC
		   fn[iLauf] == 67 || //----------------------------------------------------------------------> TU_
		   fn[iLauf] == 69 || //----------------------------------------------------------------------> TV_
		   fn[iLauf] == 70 || //----------------------------------------------------------------------> EDX
		   fn[iLauf] == 71 || //----------------------------------------------------------------------> CQT
		   fn[iLauf] == 72 || //----------------------------------------------------------------------> MIN
		   fn[iLauf] == 73 || //----------------------------------------------------------------------> MAX
		   fn[iLauf] == 74 || //----------------------------------------------------------------------> N__
		   fn[iLauf] == 75 || //----------------------------------------------------------------------> RNG
		   fn[iLauf] == 76 || //----------------------------------------------------------------------> UTS_
		   fn[iLauf] == 77 || //----------------------------------------------------------------------> SUTS
		   fn[iLauf] == 78 || //----------------------------------------------------------------------> MUTS
		   fn[iLauf] == 79 || //----------------------------------------------------------------------> ZUTS
		   fn[iLauf] == 80 || //----------------------------------------------------------------------> WTS_
		   fn[iLauf] == 81 || //----------------------------------------------------------------------> SWTS
		   fn[iLauf] == 82 || //----------------------------------------------------------------------> MWTS
		   fn[iLauf] == 83 || //----------------------------------------------------------------------> ZWTS
		   fn[iLauf] == 84 || //----------------------------------------------------------------------> RSUM
		   fn[iLauf] == 85 || //----------------------------------------------------------------------> MR_
		   fn[iLauf] == 86 || //----------------------------------------------------------------------> KRS
		   fn[iLauf] == 89 || //----------------------------------------------------------------------> MD_
		   fn[iLauf] == 90 || //----------------------------------------------------------------------> VFX
		   fn[iLauf] == 91 || //----------------------------------------------------------------------> MNX
		   fn[iLauf] == 92 || //----------------------------------------------------------------------> VFYX
		   fn[iLauf] == 93 || //----------------------------------------------------------------------> MNYX
		   fn[iLauf] == 94 || //----------------------------------------------------------------------> KPH
		   fn[iLauf] == 95 || //----------------------------------------------------------------------> KPM
		   fn[iLauf] == 96 || //----------------------------------------------------------------------> XKP
		   fn[iLauf] == 97 || //----------------------------------------------------------------------> KTET
		   fn[iLauf] ==115 || //----------------------------------------------------------------------> STET
		   fn[iLauf] ==116 || //----------------------------------------------------------------------> ZTET
		   fn[iLauf] ==117 || //----------------------------------------------------------------------> KPB
		   fn[iLauf] ==119 || //----------------------------------------------------------------------> KBS
		   fn[iLauf] ==120 || //----------------------------------------------------------------------> SBS
		   fn[iLauf] ==121 || //----------------------------------------------------------------------> ZBS
		   fn[iLauf] ==122 || //----------------------------------------------------------------------> BSK
		   fn[iLauf] ==123 || //----------------------------------------------------------------------> KBR
		   fn[iLauf] ==124 || //----------------------------------------------------------------------> ZBR
	       fn[iLauf] ==126 || //----------------------------------------------------------------------> BNW
		   fn[iLauf] ==127 || //----------------------------------------------------------------------> BNP
		   fn[iLauf] ==128 || //----------------------------------------------------------------------> MNP
		   fn[iLauf] ==129 || //----------------------------------------------------------------------> NBW
		   fn[iLauf] ==130 || //----------------------------------------------------------------------> HGW
		   fn[iLauf] ==131 || //----------------------------------------------------------------------> HGP
		   fn[iLauf] ==132 || //----------------------------------------------------------------------> GMW
		   fn[iLauf] ==133 || //----------------------------------------------------------------------> GMP
		   fn[iLauf] ==134 || //----------------------------------------------------------------------> NBW
		   fn[iLauf] ==135 || //----------------------------------------------------------------------> PNW 
		   fn[iLauf] ==136 || //----------------------------------------------------------------------> PNP
		   fn[iLauf] ==138 || //----------------------------------------------------------------------> FORM
		   fn[iLauf] ==143 || //----------------------------------------------------------------------> AMG
		   fn[iLauf] ==142 || //----------------------------------------------------------------------> PZD
		   fn[iLauf] ==154 || //----------------------------------------------------------------------> GFZ
		   fn[iLauf] ==155 || //----------------------------------------------------------------------> DTW
		   fn[iLauf] ==156 || //----------------------------------------------------------------------> DXW
		   fn[iLauf] ==157 || //----------------------------------------------------------------------> DFW
		   fn[iLauf] ==158 || //----------------------------------------------------------------------> DGAM
		   fn[iLauf] ==159 || //----------------------------------------------------------------------> FX0
		   fn[iLauf] ==160 || //----------------------------------------------------------------------> FX1
		   fn[iLauf] ==161 || //----------------------------------------------------------------------> FX2
		   fn[iLauf] ==162 || //----------------------------------------------------------------------> MXA
		   fn[iLauf] ==163 || //----------------------------------------------------------------------> MXS
		   fn[iLauf] ==164 || //----------------------------------------------------------------------> MXT
		   fn[iLauf] ==165 || //----------------------------------------------------------------------> MSP
		   fn[iLauf] ==166 || //----------------------------------------------------------------------> MXI
		   fn[iLauf] ==167 || //----------------------------------------------------------------------> MDT
		   fn[iLauf] ==168 || //----------------------------------------------------------------------> MXV
		   fn[iLauf] ==169 || //----------------------------------------------------------------------> MXM
		   fn[iLauf] ==170 || //----------------------------------------------------------------------> PKR
		   fn[iLauf] ==171 || //----------------------------------------------------------------------> PKS
		   fn[iLauf] ==172 || //----------------------------------------------------------------------> MKR
		   fn[iLauf] ==173 || //----------------------------------------------------------------------> BMK
		   fn[iLauf] ==174 || //----------------------------------------------------------------------> MKRN
		   fn[iLauf] ==175 || //----------------------------------------------------------------------> MAC
		   fn[iLauf] ==176 || //----------------------------------------------------------------------> SKM
		   fn[iLauf] ==177 || //----------------------------------------------------------------------> FMK
		   fn[iLauf] ==178 || //----------------------------------------------------------------------> MRI
		   fn[iLauf] ==179 || //----------------------------------------------------------------------> TBM
		   fn[iLauf] ==180 || //----------------------------------------------------------------------> MBC
		   fn[iLauf] ==181 || //----------------------------------------------------------------------> ZKR
		   fn[iLauf] ==182 || //----------------------------------------------------------------------> FMP
		   fn[iLauf] ==183 || //----------------------------------------------------------------------> PKRB
		   fn[iLauf] ==184 || //----------------------------------------------------------------------> PKSB
		   fn[iLauf] ==185 || //----------------------------------------------------------------------> TUX
		   fn[iLauf] ==186 || //----------------------------------------------------------------------> TT_
		   fn[iLauf] ==188 || //----------------------------------------------------------------------> SDG
		   fn[iLauf] ==189 || //----------------------------------------------------------------------> VAG
		   fn[iLauf] ==190 || //----------------------------------------------------------------------> SMG
		   fn[iLauf] ==191 || //----------------------------------------------------------------------> MXQ
		   fn[iLauf] ==192 || //----------------------------------------------------------------------> VAX
		   fn[iLauf] ==193 || //----------------------------------------------------------------------> SMX
		   fn[iLauf] ==194 || //----------------------------------------------------------------------> COX
		   fn[iLauf] ==195 || //----------------------------------------------------------------------> KOX
		   fn[iLauf] ==196 || //----------------------------------------------------------------------> QSUM
		   fn[iLauf] ==197 || //----------------------------------------------------------------------> XSUM
		   fn[iLauf] ==198 || //----------------------------------------------------------------------> AMX
		   fn[iLauf] ==199 || //----------------------------------------------------------------------> SDX
		   fn[iLauf] ==200 || //----------------------------------------------------------------------> GSD
		   fn[iLauf] ==203 || //----------------------------------------------------------------------> CI_
		   fn[iLauf] ==204 || //----------------------------------------------------------------------> EFG
		   fn[iLauf] ==205 || //----------------------------------------------------------------------> XCA
		   fn[iLauf] ==206 || //----------------------------------------------------------------------> XCB
		   fn[iLauf] ==207 || //----------------------------------------------------------------------> ANI
		   fn[iLauf] ==208 || //----------------------------------------------------------------------> BNI
		   fn[iLauf] ==209 || //----------------------------------------------------------------------> IMB
		   fn[iLauf] ==210 || //----------------------------------------------------------------------> OPN
		   fn[iLauf] ==211 || //----------------------------------------------------------------------> EFS
		   fn[iLauf] ==212 || //----------------------------------------------------------------------> OPP
		   fn[iLauf] ==213 || //----------------------------------------------------------------------> SWX
		   fn[iLauf] ==214 || //----------------------------------------------------------------------> BN0
		   fn[iLauf] ==215 || //----------------------------------------------------------------------> BN1
		   fn[iLauf] ==216 || //----------------------------------------------------------------------> BN2 
		   fn[iLauf] ==218 || //----------------------------------------------------------------------> HG0
		   fn[iLauf] ==219 || //----------------------------------------------------------------------> HG1
		   fn[iLauf] ==220 || //----------------------------------------------------------------------> ZHG
		   fn[iLauf] ==221 || //----------------------------------------------------------------------> ZBN
		   fn[iLauf] ==222 || //----------------------------------------------------------------------> ZFX
		   fn[iLauf] ==223 || //----------------------------------------------------------------------> HG2
		   fn[iLauf] ==224 || //----------------------------------------------------------------------> FN1
		   fn[iLauf] ==225 || //----------------------------------------------------------------------> FN2
		   fn[iLauf] ==226 || //----------------------------------------------------------------------> FN3
		   fn[iLauf] ==227 || //----------------------------------------------------------------------> FN4
		   fn[iLauf] ==228 || //----------------------------------------------------------------------> FN5
		   fn[iLauf] ==229 || //----------------------------------------------------------------------> FN6
		   fn[iLauf] ==230 || //----------------------------------------------------------------------> FN7
		   fn[iLauf] ==231 || //----------------------------------------------------------------------> FN8
		   fn[iLauf] ==232 || //----------------------------------------------------------------------> FN9
		   fn[iLauf] ==233 || //----------------------------------------------------------------------> RNV
		   fn[iLauf] ==234 || //----------------------------------------------------------------------> KLX
		   fn[iLauf] ==235 || //----------------------------------------------------------------------> KFA
		   fn[iLauf] ==236 || //----------------------------------------------------------------------> KL0
		   fn[iLauf] ==237 || //----------------------------------------------------------------------> KL2
		   fn[iLauf] ==238 || //----------------------------------------------------------------------> MN0
		   fn[iLauf] ==239 || //----------------------------------------------------------------------> MN2
		   fn[iLauf] ==240 || //----------------------------------------------------------------------> XHF
		   fn[iLauf] ==241 || //----------------------------------------------------------------------> HF0
		   fn[iLauf] ==242 || //----------------------------------------------------------------------> HF2
		   fn[iLauf] ==243 || //----------------------------------------------------------------------> CHF
		   fn[iLauf] ==244 || //----------------------------------------------------------------------> CKL
		   fn[iLauf] ==245 || //----------------------------------------------------------------------> CHG
		   fn[iLauf] ==246 || //----------------------------------------------------------------------> MPW
		   fn[iLauf] ==247 || //----------------------------------------------------------------------> AAA
		   fn[iLauf] ==248 || //----------------------------------------------------------------------> AEU
		   fn[iLauf] ==249 || //----------------------------------------------------------------------> AWN
		   fn[iLauf] ==250 || //----------------------------------------------------------------------> AEA
		   fn[iLauf] ==251 || //----------------------------------------------------------------------> BWA
		   fn[iLauf] ==252 || //----------------------------------------------------------------------> TWA
		   fn[iLauf] ==253 || //----------------------------------------------------------------------> BYS
		   fn[iLauf] ==254 || //----------------------------------------------------------------------> SDV
		   fn[iLauf] ==255 || //----------------------------------------------------------------------> LTO
		   fn[iLauf] ==256 || //----------------------------------------------------------------------> K_M
		   fn[iLauf] ==257 || //----------------------------------------------------------------------> KWM
		   fn[iLauf] ==258 || //----------------------------------------------------------------------> V_M
		   fn[iLauf] ==259 || //----------------------------------------------------------------------> VWM
		   fn[iLauf] ==260 || //----------------------------------------------------------------------> P_M
		   fn[iLauf] ==261 || //----------------------------------------------------------------------> P2M
		   fn[iLauf] ==262 || //----------------------------------------------------------------------> PMM
		   fn[iLauf] ==263 || //----------------------------------------------------------------------> TBZ
		   fn[iLauf] ==264 || //----------------------------------------------------------------------> TPZ
		   fn[iLauf] ==265 || //----------------------------------------------------------------------> T1Z
		   fn[iLauf] ==266 || //----------------------------------------------------------------------> T2Z
		   fn[iLauf] ==267 || //----------------------------------------------------------------------> TDZ
		   fn[iLauf] ==268 || //----------------------------------------------------------------------> TBT
		   fn[iLauf] ==269 || //----------------------------------------------------------------------> TPT
		   fn[iLauf] ==270 || //----------------------------------------------------------------------> T1T
		   fn[iLauf] ==271 || //----------------------------------------------------------------------> T2T
		   fn[iLauf] ==272 || //----------------------------------------------------------------------> TDT
		   fn[iLauf] ==273 || //----------------------------------------------------------------------> TBX
		   fn[iLauf] ==274 || //----------------------------------------------------------------------> TPX
		   fn[iLauf] ==275 || //----------------------------------------------------------------------> T1X
		   fn[iLauf] ==276 || //----------------------------------------------------------------------> T2X
		   fn[iLauf] ==277 || //----------------------------------------------------------------------> TDX
		   fn[iLauf] ==278 || //----------------------------------------------------------------------> TBF
		   fn[iLauf] ==279 || //----------------------------------------------------------------------> TPF
		   fn[iLauf] ==280 || //----------------------------------------------------------------------> T1F
		   fn[iLauf] ==281 || //----------------------------------------------------------------------> T2F
		   fn[iLauf] ==282 || //----------------------------------------------------------------------> TDF
		   fn[iLauf] ==283 || //----------------------------------------------------------------------> TBB
		   fn[iLauf] ==284 || //----------------------------------------------------------------------> TWB
		   fn[iLauf] ==285 || //----------------------------------------------------------------------> T1B
		   fn[iLauf] ==286 || //----------------------------------------------------------------------> T2B
		   fn[iLauf] ==287 || //----------------------------------------------------------------------> TBH
		   fn[iLauf] ==288 || //----------------------------------------------------------------------> TWH
		   fn[iLauf] ==289 || //----------------------------------------------------------------------> T1H
		   fn[iLauf] ==290 || //----------------------------------------------------------------------> T2H
		   fn[iLauf] ==291 || //----------------------------------------------------------------------> TCH
		   fn[iLauf] ==292 || //----------------------------------------------------------------------> TBR
		   fn[iLauf] ==293 || //----------------------------------------------------------------------> TPK
		   fn[iLauf] ==294 || //----------------------------------------------------------------------> T1K
		   fn[iLauf] ==295 || //----------------------------------------------------------------------> T2K
		   fn[iLauf] ==296 || //----------------------------------------------------------------------> BNM
		   fn[iLauf] ==297 || //----------------------------------------------------------------------> BNS
		   fn[iLauf] ==298 || //----------------------------------------------------------------------> HGM
		   fn[iLauf] ==299 || //----------------------------------------------------------------------> HGS
		   fn[iLauf] ==300 || //----------------------------------------------------------------------> RYX
		   fn[iLauf] ==301 || //----------------------------------------------------------------------> GVA
		   fn[iLauf] ==302 || //----------------------------------------------------------------------> GSM
		   fn[iLauf] ==303 || //----------------------------------------------------------------------> Z_W
		   fn[iLauf] ==304 || //----------------------------------------------------------------------> Z__
		   fn[iLauf] ==305 || //----------------------------------------------------------------------> SCH
		   fn[iLauf] ==306 || //----------------------------------------------------------------------> EXZ
		   fn[iLauf] ==316 || //----------------------------------------------------------------------> ZSH
		   fn[iLauf] ==317 || //----------------------------------------------------------------------> ZEX
		   fn[iLauf] ==321 || //----------------------------------------------------------------------> Z_P
		   fn[iLauf] ==322 || //----------------------------------------------------------------------> SHP
		   fn[iLauf] ==323 || //----------------------------------------------------------------------> EZP
		   fn[iLauf] ==324 || //----------------------------------------------------------------------> TFS
		   fn[iLauf] ==325 || //----------------------------------------------------------------------> TTS
		   fn[iLauf] ==326 || //----------------------------------------------------------------------> TXS
		   fn[iLauf] ==327 || //----------------------------------------------------------------------> MKP
		   fn[iLauf] ==328 || //----------------------------------------------------------------------> RPT
		   fn[iLauf] ==329 || //----------------------------------------------------------------------> RPZ
		   fn[iLauf] ==330 || //----------------------------------------------------------------------> KRP
		   fn[iLauf] ==331 || //----------------------------------------------------------------------> TRS
		   fn[iLauf] ==332 || //----------------------------------------------------------------------> TZS
		   fn[iLauf] ==333 || //----------------------------------------------------------------------> TMS
		   fn[iLauf] ==334 || //----------------------------------------------------------------------> TPS
		   fn[iLauf] ==335 || //----------------------------------------------------------------------> TPE
		   fn[iLauf] ==336 || //----------------------------------------------------------------------> TNE
		   fn[iLauf] ==337 || //----------------------------------------------------------------------> TEE
		   fn[iLauf] ==338 || //----------------------------------------------------------------------> ONZ
		   fn[iLauf] ==339 || //----------------------------------------------------------------------> PTD
		   fn[iLauf] ==340 || //----------------------------------------------------------------------> PXD
		   fn[iLauf] ==341 || //----------------------------------------------------------------------> PFD
		   fn[iLauf] ==342 || //----------------------------------------------------------------------> TKV
		   fn[iLauf] ==344 || //----------------------------------------------------------------------> FN0
		   fn[iLauf] ==345 || //----------------------------------------------------------------------> RNN
		   fn[iLauf] ==346 || //----------------------------------------------------------------------> LPW
		   fn[iLauf] ==347 || //----------------------------------------------------------------------> PLW
		   fn[iLauf] ==348 || //----------------------------------------------------------------------> DLW
		   fn[iLauf] ==349 || //----------------------------------------------------------------------> BSM
		   fn[iLauf] ==350 || //----------------------------------------------------------------------> HSM
		   fn[iLauf] ==351 || //----------------------------------------------------------------------> RLT
		   fn[iLauf] ==352 || //----------------------------------------------------------------------> UVS
		   fn[iLauf] ==353 || //----------------------------------------------------------------------> APX
		   fn[iLauf] ==354 || //----------------------------------------------------------------------> APW
		   fn[iLauf] ==355 || //----------------------------------------------------------------------> PAW
		   fn[iLauf] ==356 || //----------------------------------------------------------------------> DAW
		   fn[iLauf] ==357 || //----------------------------------------------------------------------> VPW
		   fn[iLauf] ==358 || //----------------------------------------------------------------------> PVW
		   fn[iLauf] ==359 || //----------------------------------------------------------------------> DVW
		   fn[iLauf] ==360 || //----------------------------------------------------------------------> CPW
		   fn[iLauf] ==361 || //----------------------------------------------------------------------> PCW
		   fn[iLauf] ==362 || //----------------------------------------------------------------------> DCW
		   fn[iLauf] ==363 || //----------------------------------------------------------------------> WPW
		   fn[iLauf] ==364 || //----------------------------------------------------------------------> PWW
		   fn[iLauf] ==365 || //----------------------------------------------------------------------> DWW
		   fn[iLauf] ==366 || //----------------------------------------------------------------------> RNB
		   fn[iLauf] ==367 || //----------------------------------------------------------------------> IGM
		   fn[iLauf] ==368 || //----------------------------------------------------------------------> DGM
		   fn[iLauf] ==369 || //----------------------------------------------------------------------> FD_
		   fn[iLauf] ==370 || //----------------------------------------------------------------------> IF_
		   fn[iLauf] ==372 || //----------------------------------------------------------------------> TFV
		   fn[iLauf] ==371 || //----------------------------------------------------------------------> ZFV
		   fn[iLauf] ==372 || //----------------------------------------------------------------------> TFV
		   fn[iLauf] ==373 || //----------------------------------------------------------------------> XFV
		   fn[iLauf] ==374 || //----------------------------------------------------------------------> FFV
		   fn[iLauf] ==375 || //----------------------------------------------------------------------> GFV
		   fn[iLauf] ==376 || //----------------------------------------------------------------------> BFV
		   fn[iLauf] ==377 || //----------------------------------------------------------------------> LZV
           fn[iLauf] ==379 || //----------------------------------------------------------------------> IIG
		   fn[iLauf] ==380 || //----------------------------------------------------------------------> FD0
           fn[iLauf] ==381 )  //----------------------------------------------------------------------> IF0





		   {
			if(operat[iLauf] != 8){printf("bad Formula ','\n"); exit(0);}
			
			fn_n=0;
			if(iLauf == 1) operat[iLauf-1]=1;//-------------------------------------------------------> operator zu + wenn fn an erster stelle
			
			while(operat[iLauf+fn_n] == 8)
			{
				fn_wert[fn_n+1] = wert[iLauf+fn_n];//-------------------------------------------------> wertübergabe an funktionsvektor
				operat[iLauf+fn_n]=operat[iLauf-1];//-------------------------------------------------> operatormodifikation
				if(operat[iLauf-1]<=2) wert[iLauf+fn_n]=0;
				if(operat[iLauf-1] >2) wert[iLauf+fn_n]=1;//------------------------------------------> wertmodifikation
				
				fn_n++;	//----------------------------------------------------------------------------> argumentzähler 
			}
			fn_wert[fn_n+1] = wert[iLauf+fn_n]; fn_n++;//---------------------------------------------> letzter wert an funktionsvektor
			
			if(fn[iLauf] == 47) stat_theta(fn_wert, fn_n, 2);//---------------------------------------> SUM funktionsaufruf
			if(fn[iLauf] == 46) stat_theta(fn_wert, fn_n, 1);//---------------------------------------> AM_ funktionsaufruf 
			if(fn[iLauf] == 48) stat_theta(fn_wert, fn_n, 3);//---------------------------------------> SD_ funktionsaufruf 
			if(fn[iLauf] == 49) stat_theta(fn_wert, fn_n, 4);//---------------------------------------> VA_ funktionsaufruf
			if(fn[iLauf] == 188) stat_theta(fn_wert, fn_n, 9);//--------------------------------------> SDG funktionsaufruf 
			if(fn[iLauf] == 189) stat_theta(fn_wert, fn_n, 10);//-------------------------------------> VAG funktionsaufruf
			if(fn[iLauf] == 190) stat_theta(fn_wert, fn_n, 11);//-------------------------------------> SMG funktionsaufruf
			if(fn[iLauf] == 50) stat_theta(fn_wert, fn_n, 5);//---------------------------------------> PSUM funktionsaufruf
			if(fn[iLauf] == 51) stat_theta(fn_wert, fn_n, 6);//---------------------------------------> GM_ funktionsaufruf
			if(fn[iLauf] == 52) stat_theta(fn_wert, fn_n, 0);//---------------------------------------> HM_ funktionsaufruf
			if(fn[iLauf] == 53) stat_theta(fn_wert, fn_n, 7);//---------------------------------------> D__ funktionsaufruf
			if(fn[iLauf] == 54) stat_theta(fn_wert, fn_n, 8);//---------------------------------------> DVARO funktionsaufruf
			if(fn[iLauf] == 196) stat_theta(fn_wert, fn_n, 12);//-------------------------------------> QSUM funktionsaufruf
			if(fn[iLauf] == 197) stat_theta(fn_wert, fn_n, 13);//-------------------------------------> XSUM funktionsaufruf
			if(fn[iLauf] == 198) stat_theta(fn_wert, fn_n, 14);//-------------------------------------> AMX funktionsaufruf
			if(fn[iLauf] == 254) stat_theta(fn_wert, fn_n, 15);//-------------------------------------> SDV funktionsaufruf
			
			if(fn[iLauf] > 54 && fn[iLauf] < 63  || //------------------------------------------------> n geradzahlig prüfung
								 fn[iLauf] == 67 ||
							//	 fn[iLauf] == 68 ||
								 fn[iLauf] == 69 ||
								 fn[iLauf] == 76 ||
						         fn[iLauf] == 77 ||
							     fn[iLauf] == 78 ||
								 fn[iLauf] == 79 ||
								 fn[iLauf] == 80 ||
								 fn[iLauf] == 81 ||
								 fn[iLauf] == 82 ||
								 fn[iLauf] == 83 ||
								 fn[iLauf] == 84 ||
								 fn[iLauf] == 85 ||
								 fn[iLauf] == 86 ||
								 fn[iLauf] ==117 ||
								 fn[iLauf] ==118 ||
								 fn[iLauf] ==119 ||
								 fn[iLauf] ==120 ||
								 fn[iLauf] ==121 ||
								 fn[iLauf] ==123 ||
								 fn[iLauf] ==124 ||
								 fn[iLauf] ==143 ||
								 fn[iLauf] ==300    )
			 if(floor((1.0*fn_n)/2) != (1.0*fn_n)/2){printf("\n\nbad Formula '2\xC5n'"); exit(0);}

			if( fn[iLauf] ==128) //-------------------------------------------------------------------> n ungeradzahlig prüfung
			 if(floor((1.0*fn_n)/2) == (1.0*fn_n)/2){printf("\n\nbad Formula '2\xB3n'"); exit(0);}
		
			if(fn[iLauf] == 55) fn_lin_reg(fn_wert, fn_n, 1);//---------------------------------------> KOR funktionsaufruf
			if(fn[iLauf] == 56) fn_lin_reg(fn_wert, fn_n, 2);//---------------------------------------> COV funktionsaufruf
			if(fn[iLauf] == 57) fn_lin_reg(fn_wert, fn_n, 3);//---------------------------------------> DET funktionsaufruf
			if(fn[iLauf] == 58) fn_lin_reg(fn_wert, fn_n, 4);//---------------------------------------> RED funktionsaufruf
			if(fn[iLauf] == 59) fn_lin_reg(fn_wert, fn_n, 5);//---------------------------------------> AYX funktionsaufruf
			if(fn[iLauf] == 60) fn_lin_reg(fn_wert, fn_n, 6);//---------------------------------------> BYX funktionsaufruf
			if(fn[iLauf] == 61) fn_lin_reg(fn_wert, fn_n, 7);//---------------------------------------> AXY funktionsaufruf
			if(fn[iLauf] == 62) fn_lin_reg(fn_wert, fn_n, 8);//---------------------------------------> BXY funktionsaufruf
			if(fn[iLauf] == 300) fn_lin_reg(fn_wert, fn_n, 9);//--------------------------------------> RXY funktionsaufruf

			if(fn[iLauf] == 342) fn_tkv(fn_wert, fn_n);//---------------------------------------------> TKV funktionsaufruf

			if(fn[iLauf] == 66) permutation_k(fn_wert, fn_n);//---------------------------------------> PM_ funktionsaufruf

			if(fn[iLauf] == 67) fn_t_uv(fn_wert, fn_n, 1);//------------------------------------------> TU_ funktionsaufruf
			//if(fn[iLauf] == 68) fn_t_uv(fn_wert, fn_n, 2);//----------------------------------------> TDC funktionsaufruf
			if(fn[iLauf] == 69) fn_t_uv(fn_wert, fn_n, 3);//------------------------------------------> TV_ funktionsaufruf
			if(fn[iLauf] == 70) fn_chi2(fn_wert, fn_n);//---------------------------------------------> EDX funktionsaufruf
			if(fn[iLauf] == 71) fn_Q_test(fn_wert, fn_n);//-------------------------------------------> CQT funktionsaufruf
			if(fn[iLauf] == 90) fn_4chi2(fn_wert,1);//------------------------------------------------> VFX funktionsaufruf
			if(fn[iLauf] == 91) fn_4chi2(fn_wert,3);//------------------------------------------------> MNX funktionsaufruf
			if(fn[iLauf] == 92) fn_4chi2(fn_wert,2);//------------------------------------------------> VFYX funktionsaufruf
			if(fn[iLauf] == 93) fn_4chi2(fn_wert,4);//------------------------------------------------> MNYX funktionsaufruf
			if(fn[iLauf] == 94) fn_4chi2(fn_wert,5);//------------------------------------------------> KPH funktionsaufruf
			if(fn[iLauf] == 95) fn_4chi2(fn_wert,6);//------------------------------------------------> KPM funktionsaufruf
			if(fn[iLauf] == 96) fn_4chi2(fn_wert,7);//------------------------------------------------> XKP funktionsaufruf
			if(fn[iLauf] == 97) fn_4chi2(fn_wert,8);//------------------------------------------------> KTET funktionsaufruf
			if(fn[iLauf] == 115) fn_4chi2(fn_wert,9);//-----------------------------------------------> STET funktionsaufruf
			if(fn[iLauf] == 116) fn_4chi2(fn_wert,10);//----------------------------------------------> ZTET funktionsaufruf

			if(fn[iLauf] == 72) fn_sort(fn_wert, fn_n, 1);//------------------------------------------> MIN funktionsaufruf
			if(fn[iLauf] == 73) fn_sort(fn_wert, fn_n, 2);//------------------------------------------> MAX funktionsaufruf
			if(fn[iLauf] == 74) fn_erg=fn_n;//--------------------------------------------------------> N__ funktionsaufruf
			if(fn[iLauf] == 75) fn_sort(fn_wert, fn_n, 3);//------------------------------------------> RNG funktionsaufruf
			if(fn[iLauf] == 84) fn_sort(fn_wert, fn_n, 4);//------------------------------------------> RSUM funktionsaufruf
			if(fn[iLauf] == 85) fn_sort(fn_wert, fn_n, 5);//------------------------------------------> MR_ funktionsaufruf
			if(fn[iLauf] == 89) fn_sort(fn_wert, fn_n, 6);//------------------------------------------> MD_ funktionsaufruf

			if(fn[iLauf] == 86) fn_rs_(fn_wert, fn_n);//----------------------------------------------> KRS funktionsaufruf

			if(fn[iLauf] == 76) fn_U_test(fn_wert, fn_n, 1);//----------------------------------------> UTS_ funktionsaufruf
			if(fn[iLauf] == 77) fn_U_test(fn_wert, fn_n, 2);//----------------------------------------> SUTS funktionsaufruf
			if(fn[iLauf] == 78) fn_U_test(fn_wert, fn_n, 3);//----------------------------------------> MUTS funktionsaufruf
			if(fn[iLauf] == 79) fn_U_test(fn_wert, fn_n, 4);//----------------------------------------> ZUTS funktionsaufruf
			if(fn[iLauf] == 123) fn_U_test(fn_wert, fn_n, 5);//---------------------------------------> KBR funktionsaufruf
			if(fn[iLauf] == 124) fn_U_test(fn_wert, fn_n, 6);//---------------------------------------> ZBR funktionsaufruf

			if(fn[iLauf] == 80) fn_T_test(fn_wert, fn_n, 1);//----------------------------------------> WTS_ funktionsaufruf
			if(fn[iLauf] == 81) fn_T_test(fn_wert, fn_n, 2);//----------------------------------------> SWTS funktionsaufruf
			if(fn[iLauf] == 82) fn_T_test(fn_wert, fn_n, 3);//----------------------------------------> MWTS funktionsaufruf
			if(fn[iLauf] == 83) fn_T_test(fn_wert, fn_n, 4);//----------------------------------------> ZWTS funktionsaufruf

			if(fn[iLauf] == 117) fn_korr_pbis(fn_wert, fn_n, 1);//------------------------------------> KPB funktionsaufruf
			if(fn[iLauf] == 119) fn_korr_pbis(fn_wert, fn_n, 3);//------------------------------------> KBS funktionsaufruf
			if(fn[iLauf] == 120) fn_korr_pbis(fn_wert, fn_n, 4);//------------------------------------> SBS funktionsaufruf
			if(fn[iLauf] == 121) fn_korr_pbis(fn_wert, fn_n, 5);//------------------------------------> ZBS funktionsaufruf
			if(fn[iLauf] == 122) fn_korr_pbis(fn_wert, 0, 6);//---------------------------------------> BSK funktionsaufruf

			if(fn[iLauf] == 126) fn_binom(fn_wert, 1);//----------------------------------------------> BNW funktionsaufruf
			if(fn[iLauf] == 127) fn_binom(fn_wert, 2);//----------------------------------------------> BNP funktionsaufruf
			if(fn[iLauf] == 128) fn_mtnom(fn_wert, fn_n);//-------------------------------------------> MNP funktionsaufruf
			if(fn[iLauf] == 129) fn_nbinom(fn_wert, 1);//---------------------------------------------> NBW funktionsaufruf
			if(fn[iLauf] == 134) fn_nbinom(fn_wert, 2);//---------------------------------------------> NBP funktionsaufruf
			if(fn[iLauf] == 130) fn_hygeo(fn_wert, 1);//----------------------------------------------> HGW funktionsaufruf
			if(fn[iLauf] == 131) fn_hygeo(fn_wert, 2);//----------------------------------------------> HGP funktionsaufruf
			if(fn[iLauf] == 132) fn_geom(fn_wert, 1);//-----------------------------------------------> GMW funktionsaufruf
			if(fn[iLauf] == 133) fn_geom(fn_wert, 2);//-----------------------------------------------> GMP funktionsaufruf
			if(fn[iLauf] == 135) fn_poisson(fn_wert, 1);//--------------------------------------------> PNW funktionsaufruf
			if(fn[iLauf] == 136) fn_poisson(fn_wert, 2);//--------------------------------------------> PNP funktionsaufruf

			if(fn[iLauf] == 138) fn_format(fn_wert);//------------------------------------------------> FORM funktionsaufruf

			if(fn[iLauf] == 143) fn_amg(fn_wert, fn_n);//---------------------------------------------> AMG funktionsaufruf
			if(fn[iLauf] == 154) fn_gfz(fn_wert, fn_n);//---------------------------------------------> GFZ funktionsaufruf
			if(fn[iLauf] == 155) dt_funktion(fn_wert); //---------------------------------------------> DTW funktionsaufruf
			if(fn[iLauf] == 156) dx_funktion(fn_wert); //---------------------------------------------> DXW funktionsaufruf
			if(fn[iLauf] == 157) df_funktion(fn_wert); //---------------------------------------------> DFW funktionsaufruf
			if(fn[iLauf] == 158) dgam_funktion(fn_wert, fn_n); //-------------------------------------> DGAM funktionsaufruf
			
			if(fn[iLauf] == 142) pd_funktion(fn_wert); ////-------------------------------------------> PZD
			if(fn[iLauf] == 339) ptd_funktion(fn_wert); //--------------------------------------------> PTD funktionsaufruf
			if(fn[iLauf] == 340) pxd_funktion(fn_wert); //--------------------------------------------> PXD funktionsaufruf
			if(fn[iLauf] == 341) pfd_funktion(fn_wert); //--------------------------------------------> PFD funktionsaufruf

			if(fn[iLauf] == 346) Lp_funktion(fn_wert); //---------------------------------------------> LPW funktionsaufruf
			if(fn[iLauf] == 347) pL_funktion(fn_wert); //---------------------------------------------> PLW funktionsaufruf
			if(fn[iLauf] == 348) dL_funktion(fn_wert); //---------------------------------------------> DLW funktionsaufruf
			if(fn[iLauf] == 354) Ap_funktion(fn_wert); //---------------------------------------------> APW funktionsaufruf
			if(fn[iLauf] == 355) pA_funktion(fn_wert); //---------------------------------------------> PAW funktionsaufruf
			if(fn[iLauf] == 356) dA_funktion(fn_wert); //---------------------------------------------> DAW funktionsaufruf
			if(fn[iLauf] == 357) Vp_funktion(fn_wert); //---------------------------------------------> VPW funktionsaufruf
			if(fn[iLauf] == 358) pV_funktion(fn_wert); //---------------------------------------------> PVW funktionsaufruf
			if(fn[iLauf] == 359) dV_funktion(fn_wert); //---------------------------------------------> DVW funktionsaufruf
			if(fn[iLauf] == 360) Cp_funktion(fn_wert); //---------------------------------------------> CPW funktionsaufruf
			if(fn[iLauf] == 361) pC_funktion(fn_wert); //---------------------------------------------> PCW funktionsaufruf
			if(fn[iLauf] == 362) dC_funktion(fn_wert); //---------------------------------------------> DCW funktionsaufruf
			if(fn[iLauf] == 363) Wp_funktion(fn_wert); //---------------------------------------------> WPW funktionsaufruf
			if(fn[iLauf] == 364) pW_funktion(fn_wert); //---------------------------------------------> PWW funktionsaufruf
			if(fn[iLauf] == 365) dW_funktion(fn_wert); //---------------------------------------------> DWW funktionsaufruf



			//if(fn[iLauf] == 159) fn_fx(fn_wert,0); //-------------------------------------------------> FX0 funktionsaufruf
			//if(fn[iLauf] == 160) fn_fx(fn_wert,1); //-------------------------------------------------> FX1 funktionsaufruf
			//if(fn[iLauf] == 161) fn_fx(fn_wert,2); //-------------------------------------------------> FX2 funktionsaufruf
			if(fn[iLauf] == 159) fn_2kf0(fn_wert, fn_n); //-------------------------------------------> FX0 funktionsaufruf
			if(fn[iLauf] == 160) fn_2kf2(fn_wert, fn_n, 1); //----------------------------------------> FX1 funktionsaufruf
			if(fn[iLauf] == 161) fn_2kf2(fn_wert, fn_n, 0); //----------------------------------------> FX2 funktionsaufruf

			if(fn[iLauf] == 162) fn_matrix_a(fn_wert,fn_n, 1); //-------------------------------------> MXA funktionsaufruf
			if(fn[iLauf] == 163) fn_matrix_a(fn_wert,fn_n, 2); //-------------------------------------> MXS funktionsaufruf
			if(fn[iLauf] == 164) fn_matrix_a(fn_wert,fn_n, 3); //-------------------------------------> MXT funktionsaufruf
			if(fn[iLauf] == 165) fn_matrix_a(fn_wert,fn_n, 4); //-------------------------------------> MSP funktionsaufruf
			if(fn[iLauf] == 166) fn_matrix_a(fn_wert,fn_n, 5); //-------------------------------------> MXI funktionsaufruf
			if(fn[iLauf] == 167) fn_matrix_a(fn_wert,fn_n, 6); //-------------------------------------> MDT funktionsaufruf
			if(fn[iLauf] == 168) fn_matrix_a(fn_wert,fn_n, 7); //-------------------------------------> MXV funktionsaufruf
			if(fn[iLauf] == 169) fn_matrix_a(fn_wert,fn_n, 8); //-------------------------------------> MXM funktionsaufruf
			if(fn[iLauf] == 191) fn_matrix_a(fn_wert,fn_n, 9); //-------------------------------------> MXQ funktionsaufruf

			if(fn[iLauf] == 170) fn_pkr(fn_wert, 1);//------------------------------------------------> PKR funktionsaufruf
			if(fn[iLauf] == 171) fn_pkr(fn_wert, 2);//------------------------------------------------> PKS funktionsaufruf
			if(fn[iLauf] == 183) fn_pkr(fn_wert, 3);//------------------------------------------------> PKRB funktionsaufruf
			if(fn[iLauf] == 184) fn_pkr(fn_wert, 4);//------------------------------------------------> PKSB funktionsaufruf
			
			if(fn[iLauf] == 172) fn_Rc12(fn_wert);//--------------------------------------------------> MKR funktionsaufruf
			if(fn[iLauf] == 173) fn_betaR(fn_wert, fn_n);//-------------------------------------------> BMK funktionsaufruf
			if(fn[iLauf] == 174) fn_Rc12k(fn_wert, fn_n);//-------------------------------------------> MKRN funktionsaufruf
			if(fn[iLauf] == 175) fn_ac12k(fn_wert, fn_n);//-------------------------------------------> MAC funktionsaufruf
			if(fn[iLauf] == 176) fn_skm(fn_wert);//---------------------------------------------------> SKM funktionsaufruf
			if(fn[iLauf] == 177) fn_fmkr(fn_wert);//--------------------------------------------------> FMK funktionsaufruf

			if(fn[iLauf] == 178) fn_invR(fn_wert, fn_n);//--------------------------------------------> MRI funktionsaufruf

			if(fn[iLauf] == 179) fn_tbmr(fn_wert);//--------------------------------------------------> TBM funktionsaufruf
			if(fn[iLauf] == 180) fn_bci(fn_wert);//---------------------------------------------------> MBC funktionsaufruf
			if(fn[iLauf] == 181) fn_zkr(fn_wert);//---------------------------------------------------> ZKR funktionsaufruf
			if(fn[iLauf] == 182) fn_fmpk(fn_wert);//--------------------------------------------------> FMP funktionsaufruf

			if(fn[iLauf] == 327) fn_fmkp(fn_wert);//--------------------------------------------------> MKP funktionsaufruf
			if(fn[iLauf] == 328) fn_frpt(fn_wert);//--------------------------------------------------> RPT funktionsaufruf
			if(fn[iLauf] == 329) fn_frpz(fn_wert, 1);//-----------------------------------------------> RPZ funktionsaufruf
			if(fn[iLauf] == 330) fn_frpz(fn_wert, 2);//-----------------------------------------------> KRP funktionsaufruf

			if(fn[iLauf] == 185) fn_t_ux(fn_wert, 1);//-----------------------------------------------> TUX funktionsaufruf
			if(fn[iLauf] == 186) fn_t_ux(fn_wert, 2);//-----------------------------------------------> TT_ funktionsaufruf

			if(fn[iLauf] == 192) stat_thetax(fn_wert, 1);//-------------------------------------------> VAX funktionsaufruf
			if(fn[iLauf] == 193) stat_thetax(fn_wert, 2);//-------------------------------------------> SMX funktionsaufruf
			if(fn[iLauf] == 194) stat_thetax(fn_wert, 3);//-------------------------------------------> COX funktionsaufruf
			if(fn[iLauf] == 195) stat_thetax(fn_wert, 4);//-------------------------------------------> KOX funktionsaufruf
			if(fn[iLauf] == 199) stat_thetax(fn_wert, 5);//-------------------------------------------> SDX funktionsaufruf
			if(fn[iLauf] == 200) stat_thetax(fn_wert, 6);//-------------------------------------------> GSD funktionsaufruf
			if(fn[iLauf] == 301) stat_thetax(fn_wert, 7);//-------------------------------------------> GVA funktionsaufruf
			if(fn[iLauf] == 302) stat_thetax(fn_wert, 8);//-------------------------------------------> GSM funktionsaufruf
			if(fn[iLauf] == 303) stat_thetaz(fn_wert, fn_n, 1);//-------------------------------------> Z_W funktionsaufruf
			if(fn[iLauf] == 304) stat_thetaz(fn_wert, fn_n, 2);//-------------------------------------> Z__ funktionsaufruf
			if(fn[iLauf] == 305) stat_thetaz(fn_wert, fn_n, 3);//-------------------------------------> SCH funktionsaufruf
			if(fn[iLauf] == 306) stat_thetaz(fn_wert, fn_n, 4);//-------------------------------------> EXZ funktionsaufruf
			if(fn[iLauf] == 316) stat_thetaz(fn_wert, fn_n, 5);//-------------------------------------> ZSH funktionsaufruf
			if(fn[iLauf] == 317) stat_thetaz(fn_wert, fn_n, 6);//-------------------------------------> ZEX funktionsaufruf
			if(fn[iLauf] == 321) stat_thetaz(fn_wert, fn_n, 7);//-------------------------------------> Z_P funktionsaufruf
			if(fn[iLauf] == 322) stat_thetaz(fn_wert, fn_n, 8);//-------------------------------------> SHP funktionsaufruf
			if(fn[iLauf] == 323) stat_thetaz(fn_wert, fn_n, 9);//-------------------------------------> EZP funktionsaufruf


			if(fn[iLauf] == 203) fn_ci_(fn_wert);//---------------------------------------------------> CI_ funktionsaufruf
			
			if(fn[iLauf] == 204) fn_epsilon(fn_wert, 1);//---------------------------------------------> EFG funktionsaufruf
			if(fn[iLauf] == 205) fn_epsilon(fn_wert, 2);//---------------------------------------------> XCA funktionsaufruf
			if(fn[iLauf] == 206) fn_epsilon(fn_wert, 3);//---------------------------------------------> XCB funktionsaufruf
			if(fn[iLauf] == 207) fn_epsilon(fn_wert, 4);//---------------------------------------------> ANI funktionsaufruf
			if(fn[iLauf] == 208) fn_epsilon(fn_wert, 5);//---------------------------------------------> BNI funktionsaufruf
			if(fn[iLauf] == 209) fn_epsilon(fn_wert, 6);//---------------------------------------------> IMB funktionsaufruf
			if(fn[iLauf] == 210) fn_epsilon(fn_wert, 7);//---------------------------------------------> OPN funktionsaufruf
			if(fn[iLauf] == 211) fn_epsilon(fn_wert, 8);//---------------------------------------------> EFS funktionsaufruf
			if(fn[iLauf] == 212) fn_epsilon(fn_wert, 9);//---------------------------------------------> OPP funktionsaufruf
			if(fn[iLauf] == 213) fn_epsilon(fn_wert, 10);//--------------------------------------------> SWX funktionsaufruf
			if(fn[iLauf] == 338) fn_epsilon(fn_wert, 11);//--------------------------------------------> ONZ funktionsaufruf

			if(fn[iLauf] == 214) fn_binom_t(fn_wert, 1);//---------------------------------------------> BN0 funktionsaufruf
			if(fn[iLauf] == 215) fn_binom_t(fn_wert, 2);//---------------------------------------------> BN1 funktionsaufruf
			if(fn[iLauf] == 216) fn_binom_t(fn_wert, 3);//---------------------------------------------> BN2 funktionsaufruf
			if(fn[iLauf] == 221) fn_binom_t(fn_wert, 4);//---------------------------------------------> ZBN funktionsaufruf

			//if(fn[iLauf] == 218) fn_hg_(fn_wert, 1);//-------------------------------------------------> HG0 funktionsaufruf
		    if(fn[iLauf] == 218) fn_2khg(fn_wert, fn_n);//---------------------------------------------> HG0 funktionsaufruf
			if(fn[iLauf] == 219) fn_hg_(fn_wert, 2);//-------------------------------------------------> HG1 funktionsaufruf
			if(fn[iLauf] == 220) fn_hg_(fn_wert, 3);//-------------------------------------------------> ZHG funktionsaufruf
			//if(fn[iLauf] == 223) fn_hgx(fn_wert );//---------------------------------------------------> HG2 funktionsaufruf
			if(fn[iLauf] == 223) fn_2kp2(fn_wert, fn_n, 1 );//-----------------------------------------> HG2 funktionsaufruf
			if(fn[iLauf] == 245) fn_2kp2(fn_wert, fn_n, 2 );//-----------------------------------------> CHG funktionsaufruf
			if(fn[iLauf] == 234) fn_klx(fn_wert); //---------------------------------------------------> KLX funktionsaufruf
			if(fn[iLauf] == 235) fn_kfa(fn_wert, fn_n); //---------------------------------------------> KFA funktionsaufruf
			if(fn[iLauf] == 236) fn_klhg(fn_wert); //--------------------------------------------------> KL0 funktionsaufruf
			if(fn[iLauf] == 237) fn_klp2(fn_wert, 1); //-----------------------------------------------> KL2 funktionsaufruf
			if(fn[iLauf] == 244) fn_klp2(fn_wert, 2); //-----------------------------------------------> CKL funktionsaufruf
			if(fn[iLauf] == 238) fn_kmtn0(fn_wert, fn_n); //-------------------------------------------> MN0 funktionsaufruf
			if(fn[iLauf] == 239) fn_kmtn2(fn_wert, fn_n); //-------------------------------------------> MN2 funktionsaufruf
			if(fn[iLauf] == 240) fn_2kfx(fn_wert, fn_n); //--------------------------------------------> XHF funktionsaufruf
			if(fn[iLauf] == 241) fn_2kf0(fn_wert, fn_n); //--------------------------------------------> HF0 funktionsaufruf
			if(fn[iLauf] == 242) fn_2kf2(fn_wert, fn_n, 0); //-----------------------------------------> HF2 funktionsaufruf
			if(fn[iLauf] == 243) fn_2kfc(fn_wert, fn_n); //--------------------------------------------> CHF funktionsaufruf

			if(fn[iLauf] == 222) fn_zhg(fn_wert);//----------------------------------------------------> ZHG funktionsaufruf

			if(fn[iLauf] == 224) fn_grs_1(fn_wert);//--------------------------------------------------> FN1 funktionsaufruf
			if(fn[iLauf] == 225) fn_grs_2(fn_wert);//--------------------------------------------------> FN2 funktionsaufruf
			if(fn[iLauf] == 226) fn_grs_3(fn_wert, fn_n);//--------------------------------------------> FN3 funktionsaufruf
			if(fn[iLauf] == 227) fn_grs_4(fn_wert);//--------------------------------------------------> FN4 funktionsaufruf
			if(fn[iLauf] == 228) fn_grs_5(fn_wert);//--------------------------------------------------> FN5 funktionsaufruf
			if(fn[iLauf] == 229) fn_grs_6(fn_wert);//--------------------------------------------------> FN6 funktionsaufruf
			if(fn[iLauf] == 230) fn_grs_7(fn_wert, fn_n);//--------------------------------------------> FN7 funktionsaufruf
		    if(fn[iLauf] == 231) fn_grs_8(fn_wert);//--------------------------------------------------> FN8 funktionsaufruf
			if(fn[iLauf] == 232) fn_grs_9(fn_wert);//--------------------------------------------------> FN9 funktionsaufruf
			if(fn[iLauf] == 344) fn_grs_0(fn_wert);//--------------------------------------------------> FN0 funktionsaufruf

			if(fn[iLauf] == 233) qzfx(fn_wert, fn_n);//------------------------------------------------> RNV funktionsaufruf

			if(fn[iLauf] == 246) fn_wkt(fn_wert, fn_n, 1);//-------------------------------------------> MPW funktionsaufruf
			if(fn[iLauf] == 247) fn_wkt(fn_wert, fn_n, 2);//-------------------------------------------> AAA funktionsaufruf
			if(fn[iLauf] == 248) fn_wkt(fn_wert, fn_n, 3);//-------------------------------------------> AEU funktionsaufruf
			if(fn[iLauf] == 249) fn_wkt(fn_wert, fn_n, 4);//-------------------------------------------> AWN funktionsaufruf
			if(fn[iLauf] == 250) fn_wkt(fn_wert, fn_n, 5);//-------------------------------------------> AEA funktionsaufruf
			if(fn[iLauf] == 251) fn_wkt(fn_wert, fn_n, 6);//-------------------------------------------> BWA funktionsaufruf
			if(fn[iLauf] == 252) fn_wkt(fn_wert, fn_n, 7);//-------------------------------------------> TWA funktionsaufruf
			if(fn[iLauf] == 253) fn_wkt(fn_wert, fn_n, 8);//-------------------------------------------> BYS funktionsaufruf

			if(fn[iLauf] == 255) fn_lto(fn_wert, fn_n);//----------------------------------------------> LTO funktionsaufruf

			if(fn[iLauf] == 256) fn_komb_m(fn_wert, fn_n, 1);//----------------------------------------> K_M funktionsaufruf
			if(fn[iLauf] == 257) fn_komb_m(fn_wert, fn_n, 2);//----------------------------------------> KWM funktionsaufruf
			if(fn[iLauf] == 258) fn_komb_m(fn_wert, fn_n, 3);//----------------------------------------> V_M funktionsaufruf
			if(fn[iLauf] == 259) fn_komb_m(fn_wert, fn_n, 4);//----------------------------------------> VWM funktionsaufruf
			if(fn[iLauf] == 260) fn_komb_m(fn_wert, fn_n, 5);//----------------------------------------> P_M funktionsaufruf
			if(fn[iLauf] == 261) fn_komb_m(fn_wert, fn_n, 6);//----------------------------------------> P2M funktionsaufruf
			if(fn[iLauf] == 262) fn_komb_wp(fn_wert, fn_n);  //----------------------------------------> PMM funktionsaufruf

			if(fn[iLauf] == 263) fn_tab_z(fn_wert, 1);//-----------------------------------------------> TBZ funktionsaufruf
			if(fn[iLauf] == 264) fn_tab_z(fn_wert, 2);//-----------------------------------------------> TPZ funktionsaufruf
			if(fn[iLauf] == 265) fn_tab_z(fn_wert, 3);//-----------------------------------------------> T1Z funktionsaufruf
			if(fn[iLauf] == 266) fn_tab_z(fn_wert, 4);//-----------------------------------------------> T2Z funktionsaufruf
			if(fn[iLauf] == 267) fn_tab_z(fn_wert, 5);//-----------------------------------------------> TDZ funktionsaufruf

			if(fn[iLauf] == 268) fn_tab_t(fn_wert, 1);//-----------------------------------------------> TBT funktionsaufruf
			if(fn[iLauf] == 269) fn_tab_t(fn_wert, 2);//-----------------------------------------------> TPT funktionsaufruf
			if(fn[iLauf] == 270) fn_tab_t(fn_wert, 3);//-----------------------------------------------> T1T funktionsaufruf
			if(fn[iLauf] == 271) fn_tab_t(fn_wert, 4);//-----------------------------------------------> T2T funktionsaufruf
			if(fn[iLauf] == 272) fn_tab_t(fn_wert, 5);//-----------------------------------------------> TDT funktionsaufruf

			if(fn[iLauf] == 273) fn_tab_x2(fn_wert, 1);//----------------------------------------------> TBX funktionsaufruf
			if(fn[iLauf] == 274) fn_tab_x2(fn_wert, 2);//----------------------------------------------> TPX funktionsaufruf
			if(fn[iLauf] == 275) fn_tab_x2(fn_wert, 3);//----------------------------------------------> T1X funktionsaufruf
			if(fn[iLauf] == 276) fn_tab_x2(fn_wert, 4);//----------------------------------------------> T2X funktionsaufruf
			if(fn[iLauf] == 277) fn_tab_x2(fn_wert, 5);//----------------------------------------------> TDX funktionsaufruf

			if(fn[iLauf] == 278) fn_tab_F(fn_wert, 1);//-----------------------------------------------> TBF funktionsaufruf
			if(fn[iLauf] == 279) fn_tab_F(fn_wert, 2);//-----------------------------------------------> TPF funktionsaufruf
			if(fn[iLauf] == 280) fn_tab_F(fn_wert, 3);//-----------------------------------------------> T1F funktionsaufruf
			if(fn[iLauf] == 281) fn_tab_F(fn_wert, 4);//-----------------------------------------------> T2F funktionsaufruf
			if(fn[iLauf] == 282) fn_tab_F(fn_wert, 5);//-----------------------------------------------> TDF funktionsaufruf

			if(fn[iLauf] == 283) fn_tab_binom(fn_wert, 1);//-------------------------------------------> TBB funktionsaufruf
			if(fn[iLauf] == 284) fn_tab_binom(fn_wert, 2);//-------------------------------------------> TWB funktionsaufruf
			if(fn[iLauf] == 285) fn_tab_binom(fn_wert, 3);//-------------------------------------------> T1B funktionsaufruf
			if(fn[iLauf] == 286) fn_tab_binom(fn_wert, 4);//-------------------------------------------> T2B funktionsaufruf

			if(fn[iLauf] == 287) fn_tab_hygeo(fn_wert, 1);//-------------------------------------------> TBH funktionsaufruf
			if(fn[iLauf] == 288) fn_tab_hygeo(fn_wert, 2);//-------------------------------------------> TWH funktionsaufruf
			if(fn[iLauf] == 289) fn_tab_hygeo(fn_wert, 3);//-------------------------------------------> T1H funktionsaufruf
			if(fn[iLauf] == 290) fn_tab_hygeo(fn_wert, 4);//-------------------------------------------> T2H funktionsaufruf
			if(fn[iLauf] == 291) fn_tab_hygeo(fn_wert, 5);//-------------------------------------------> TCH funktionsaufruf

			if(fn[iLauf] == 292) fn_tab_rnd(fn_wert);//------------------------------------------------> TCH funktionsaufruf

			if(fn[iLauf] == 293) fn_tab_korr(fn_wert, 1);//--------------------------------------------> TPK funktionsaufruf
			if(fn[iLauf] == 294) fn_tab_korr(fn_wert, 2);//--------------------------------------------> T1K funktionsaufruf
			if(fn[iLauf] == 295) fn_tab_korr(fn_wert, 3);//--------------------------------------------> T2K funktionsaufruf

			if(fn[iLauf] == 324) fn_tab_F_sig(fn_wert);//----------------------------------------------> TFS funktionsaufruf
			if(fn[iLauf] == 325) fn_tab_sig(fn_wert, 1);//---------------------------------------------> TTS funktionsaufruf
			if(fn[iLauf] == 326) fn_tab_sig(fn_wert, 2);//---------------------------------------------> TXS funktionsaufruf
			if(fn[iLauf] == 331) fn_tab_sig(fn_wert, 3);//---------------------------------------------> TRS funktionsaufruf
			if(fn[iLauf] == 332) fn_tab_sig(fn_wert, 4);//---------------------------------------------> TZS funktionsaufruf
			if(fn[iLauf] == 333) fn_tab_sig(fn_wert, 5);//---------------------------------------------> TMS funktionsaufruf
			if(fn[iLauf] == 334) fn_tab_sig(fn_wert, 6);//---------------------------------------------> TPS funktionsaufruf

			if(fn[iLauf] == 335) fn_tab_epsilon(fn_wert, 1);//-----------------------------------------> TPE funktionsaufruf
			if(fn[iLauf] == 336) fn_tab_epsilon(fn_wert, 2);//-----------------------------------------> TNE funktionsaufruf
			if(fn[iLauf] == 337) fn_tab_epsilon(fn_wert, 3);//-----------------------------------------> TEE funktionsaufruf

			if(fn[iLauf] == 296) fn_wkt_x(fn_wert, 1);//-----------------------------------------------> BNM funktionsaufruf
			if(fn[iLauf] == 297) fn_wkt_x(fn_wert, 2);//-----------------------------------------------> BNS funktionsaufruf
			if(fn[iLauf] == 298) fn_wkt_x(fn_wert, 3);//-----------------------------------------------> HGM funktionsaufruf
			if(fn[iLauf] == 299) fn_wkt_x(fn_wert, 4);//-----------------------------------------------> HGS funktionsaufruf

			if(fn[iLauf] == 345) fn_rnd_var(fn_wert);//------------------------------------------------> RNN funktionsaufruf
			if(fn[iLauf] == 366) fn_rnd_bivar(fn_wert);//----------------------------------------------> RNB funktionsaufruf
			if(fn[iLauf] == 349) fn_bn_sim(fn_wert);//-------------------------------------------------> BSM funktionsaufruf
			if(fn[iLauf] == 350) fn_hg_sim(fn_wert);//-------------------------------------------------> HSM funktionsaufruf
			if(fn[iLauf] == 351) fn_rlt_sim(fn_wert);//------------------------------------------------> RLT funktionsaufruf
			if(fn[iLauf] == 352) fn_2uv_sim(fn_wert);//------------------------------------------------> UVS funktionsaufruf

			if(fn[iLauf] == 353) fn_approx(fn_wert);//-------------------------------------------------> APX funktionsaufruf

			if(fn[iLauf] == 367) igamma(fn_wert);//----------------------------------------------------> IGM funktionsaufruf
			if(fn[iLauf] == 379) iigamma(fn_wert);//---------------------------------------------------> IIG funktionsaufruf
			if(fn[iLauf] == 368) dgamma(fn_wert);//----------------------------------------------------> DGM funktionsaufruf
			
			if(fn[iLauf] == 371) fn_vektor(fn_wert,1);//-----------------------------------------------> ZFV funktionsaufruf
			if(fn[iLauf] == 372) fn_vektor(fn_wert,3);//-----------------------------------------------> TFV funktionsaufruf
			if(fn[iLauf] == 373) fn_vektor(fn_wert,5);//-----------------------------------------------> XFV funktionsaufruf
			if(fn[iLauf] == 374) fn_vektor(fn_wert,7);//-----------------------------------------------> FFV funktionsaufruf
			if(fn[iLauf] == 375) fn_vektor(fn_wert,0);//-----------------------------------------------> GFV funktionsaufruf
			if(fn[iLauf] == 376) fn_vektor(fn_wert,9);//-----------------------------------------------> BFV funktionsaufruf
			if(fn[iLauf] == 377) fn_vektor(fn_wert,11);//----------------------------------------------> LZV funktionsaufruf
				
			if(fn[iLauf] == 369) fn_di(fn_wert,1);//---------------------------------------------------> FD_ funktionsaufruf
			if(fn[iLauf] == 370) fn_di(fn_wert,2);//---------------------------------------------------> IF_ funktionsaufruf
			if(fn[iLauf] == 380) fn_di(fn_wert,3);//---------------------------------------------------> FD0 funktionsaufruf
			if(fn[iLauf] == 381) fn_di(fn_wert,4);//---------------------------------------------------> IF0 funktionsaufruf
			

			wert[iLauf+(fn_n-1)] = fn_erg;
			fn_n=0;
		}
		if(fn[iLauf] == 63)//-------------------------------------------------------------------------> r -> t
		 if(operat[iLauf] == 8){fn_trw(wert[iLauf], wert[iLauf+1]); wert[iLauf+1]=fn_erg;}
		if(fn[iLauf] == 63)
		 if(operat[iLauf] != 8){printf("bad Formula ','\n"); exit(0);}
		if(fn[iLauf] == 64)//-------------------------------------------------------------------------> Korrelationsdifferenz
		 if(operat[iLauf] == 8){fn_zrr(wert[iLauf], wert[iLauf+1], wert[iLauf+2], wert[iLauf+3]); wert[iLauf+3]=fn_erg; fn_n=4;}
		if(fn[iLauf] == 64)
		 if(operat[iLauf] != 8){printf("bad Formula ','\n"); exit(0);}
		if(fn[iLauf] == 65){fn_sfz(wert[iLauf]); wert[iLauf]=fn_erg;}//-------------------------------> SD zu Fishers Z
		if(fn[iLauf] == 88){fn_red_x(wert[iLauf], 1); wert[iLauf]=fn_erg;}//----------------------------> RDN
		if(fn[iLauf] == 141){fn_red_x(wert[iLauf], 2); wert[iLauf]=fn_erg;}//---------------------------> RDA
		if(fn[iLauf] == 98){fn_dgrad(wert[iLauf], 1); wert[iLauf]=fn_erg;}//----------------------------> RAD
		if(fn[iLauf] == 99){fn_dgrad(wert[iLauf], 2); wert[iLauf]=fn_erg;}//----------------------------> DEG
		if(fn[iLauf] == 100){fn_dgrad(wert[iLauf], 3); wert[iLauf]=fn_erg;}//---------------------------> GRAD
		if(fn[iLauf] == 101){fn_dgrad(wert[iLauf], 4); wert[iLauf]=fn_erg;}//---------------------------> DGR
		if(fn[iLauf] == 102){fn_wfkt(wert[iLauf], 1); wert[iLauf]=fn_erg;}//----------------------------> COT
		if(fn[iLauf] == 103){fn_wfkt(wert[iLauf], 2); wert[iLauf]=fn_erg;}//----------------------------> SEC
		if(fn[iLauf] == 104){fn_wfkt(wert[iLauf], 3); wert[iLauf]=fn_erg;}//----------------------------> CSE
		if(fn[iLauf] == 105){fn_wfkt(wert[iLauf], 4); wert[iLauf]=fn_erg;}//----------------------------> HCT
		if(fn[iLauf] == 106){fn_wfkt(wert[iLauf], 5); wert[iLauf]=fn_erg;}//----------------------------> HSE
		if(fn[iLauf] == 107){fn_wfkt(wert[iLauf], 6); wert[iLauf]=fn_erg;}//----------------------------> HCE
		if(fn[iLauf] == 108){fn_wfkt(wert[iLauf], 7); wert[iLauf]=fn_erg;}//----------------------------> ACT
		if(fn[iLauf] == 109){fn_wfkt(wert[iLauf], 8); wert[iLauf]=fn_erg;}//----------------------------> ASE
		if(fn[iLauf] == 110){fn_wfkt(wert[iLauf], 9); wert[iLauf]=fn_erg;}//----------------------------> ACE
		if(fn[iLauf] == 111){fn_wfkt(wert[iLauf], 13); wert[iLauf]=fn_erg;}//---------------------------> AHG
		if(fn[iLauf] == 112){fn_wfkt(wert[iLauf], 14); wert[iLauf]=fn_erg;}//---------------------------> AHN
		if(fn[iLauf] == 113){fn_wfkt(wert[iLauf], 15); wert[iLauf]=fn_erg;}//---------------------------> AHO

		if(fn[iLauf] == 114){dz_funktion(wert[iLauf]); wert[iLauf]=fn_erg;}//---------------------------> DZW
		if(fn[iLauf] == 137){zd_funktion(wert[iLauf]); wert[iLauf]=fn_erg;}//---------------------------> ZDW
		
		//if(fn[iLauf] == 999){dt_funktion(wert[iLauf]); wert[iLauf]=fn_erg;}//---------------------------> DTW
		//if(fn[iLauf] == 999){dx_funktion(wert[iLauf]); wert[iLauf]=fn_erg;}//---------------------------> DXW
		//if(fn[iLauf] == 999){dF_funktion(wert[iLauf]); wert[iLauf]=fn_erg;}//---------------------------> DFW

		if(fn[iLauf] == 125)//--------------------------------------------------------------------------> N_K
		 if(operat[iLauf] == 8){fn_nk(wert[iLauf], wert[iLauf+1]); wert[iLauf+1]=fn_erg;}
		if(fn[iLauf] == 125)
		 if(operat[iLauf] != 8){printf("bad Formula ','\n"); exit(0);}
		if(fn[iLauf] == 144){fn_e(wert[iLauf]); wert[iLauf]=fn_erg;}//----------------------------------> EXP

		if(fn[iLauf] == 145){fn_wfkt(wert[iLauf], 16); wert[iLauf]=fn_erg;}//---------------------------> IACT
		if(fn[iLauf] == 146){fn_wfkt(wert[iLauf], 17); wert[iLauf]=fn_erg;}//---------------------------> IASE
		if(fn[iLauf] == 147){fn_wfkt(wert[iLauf], 18); wert[iLauf]=fn_erg;}//---------------------------> IACE
		if(fn[iLauf] == 148){fn_wfkt(wert[iLauf], 19); wert[iLauf]=fn_erg;}//---------------------------> IAHS
		if(fn[iLauf] == 149){fn_wfkt(wert[iLauf], 20); wert[iLauf]=fn_erg;}//---------------------------> IAHC
		if(fn[iLauf] == 150){fn_wfkt(wert[iLauf], 21); wert[iLauf]=fn_erg;}//---------------------------> IAHT
		if(fn[iLauf] == 151){fn_wfkt(wert[iLauf], 22); wert[iLauf]=fn_erg;}//---------------------------> IAHG
		if(fn[iLauf] == 152){fn_wfkt(wert[iLauf], 23); wert[iLauf]=fn_erg;}//---------------------------> IAHN
		if(fn[iLauf] == 153){fn_wfkt(wert[iLauf], 24); wert[iLauf]=fn_erg;}//---------------------------> IAHO

		if(fn[iLauf] == 187){fn_sig(wert[iLauf]); wert[iLauf]=fn_erg;}//--------------------------------> SIG

		if(fn[iLauf] == 307) {stat_thetaz1(wert[iLauf], 1);wert[iLauf]=fn_erg;}//-----------------------> SSH 
		if(fn[iLauf] == 308) {stat_thetaz1(wert[iLauf], 2);wert[iLauf]=fn_erg;}//-----------------------> SEX 
		if(fn[iLauf] == 309) {stat_thetaz1(wert[iLauf], 3);wert[iLauf]=fn_erg;}//-----------------------> SW_ 
		if(fn[iLauf] == 310) {stat_thetaz1(wert[iLauf], 4);wert[iLauf]=fn_erg;}//-----------------------> IQ_ 
		if(fn[iLauf] == 311) {stat_thetaz1(wert[iLauf], 5);wert[iLauf]=fn_erg;}//-----------------------> IQK 
		if(fn[iLauf] == 312) {stat_thetaz1(wert[iLauf], 6);wert[iLauf]=fn_erg;}//-----------------------> CW_ 
		if(fn[iLauf] == 313) {stat_thetaz1(wert[iLauf], 7);wert[iLauf]=fn_erg;}//-----------------------> STN 
		if(fn[iLauf] == 314) {stat_thetaz1(wert[iLauf], 8);wert[iLauf]=fn_erg;}//-----------------------> SN_ 
		if(fn[iLauf] == 315) {stat_thetaz1(wert[iLauf], 9);wert[iLauf]=fn_erg;}//-----------------------> T__ 
		if(fn[iLauf] == 318) {stat_thetaz1(wert[iLauf], 10);wert[iLauf]=fn_erg;}//----------------------> S__ 
		if(fn[iLauf] == 319) {stat_thetaz1(wert[iLauf], 11);wert[iLauf]=fn_erg;}//----------------------> WP_ 
		if(fn[iLauf] == 320) {stat_thetaz1(wert[iLauf], 12);wert[iLauf]=fn_erg;}//----------------------> PR_ 

		if(fn[iLauf] == 201){fn_const(1); wert[iLauf]=fn_erg;}//----------------------------------------> EUL
		if(fn[iLauf] == 202){fn_const(2); wert[iLauf]=fn_erg;}//----------------------------------------> PI_
		
		if(fn[iLauf] == 378){fn_kgl(wert[iLauf]); wert[iLauf]=fn_erg;}//--------------------------------> KGL



		


		// :
		// :
		// Funktionsdeklaration  //  3/4  // calc_2 -> 4/4



		if(operat[iLauf] == 8)//----------------------------------------------------------------------> funktionen mit 2 oder mehr argumenten
		{	
				if(operat[iLauf-1]<=2) wert[iLauf]=0;
				if(operat[iLauf-1] >2) wert[iLauf]=1;//-----------------------------------------------> wertmodifikation
				
				if(iLauf == 1) operat[iLauf]=1;//-----------------------------------------------------> operatormodifikation
				if(iLauf > 1) operat[iLauf]=operat[iLauf-1];
				if(fn_n>=3) {operat[iLauf+1]=operat[iLauf];wert[iLauf+1]=wert[iLauf];}//--------------> funktion mit 3 oder mehr argumenten
				if(fn_n==4) {operat[iLauf+2]=operat[iLauf+1];wert[iLauf+2]=wert[iLauf+1];}//----------> funktion mit 4 argumenten
		}
	}
};



