#include "stdafx.h"
#include "util.h"

int changeColor(WORD wAttributes) {
	// EXTRACTED CODE FROM
	// https://stackoverflow.com/questions/33446296/how-to-use-setconsoletextattribute-c

	HANDLE hCon;
	CONSOLE_SCREEN_BUFFER_INFO csbiScreenInfo;
	COORD coordStart = { 0, 0 };
	DWORD dwNumWritten = 0;
	DWORD dwScrSize;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!GetConsoleScreenBufferInfo(hCon, &csbiScreenInfo))
		return 1;

	dwScrSize = csbiScreenInfo.dwMaximumWindowSize.X * csbiScreenInfo.dwMaximumWindowSize.Y;
	SetConsoleTextAttribute(hCon, wAttributes);
	return 0;
}

void colorPrint(WORD color, char* str, DWORD param) {
	changeColor(color);
	printf(str, param);
}



void printChunkIncBuffer(char* logo, WORD color, int *start, int *end, int NumBytes) {
	*start = *end;
	*end = *start + NumBytes;
	changeColor(color);
	for (int i = *start; i < *end; i++)
		printf("%c", logo[i]);
}


void printNecureLogo() {
	char* logo;
	int start = 0;
	int end = 0;
	WORD colorLetter = DARKGREEN;
	WORD colorLine = RED;
	WORD colorComputer = WHITE;
	WORD colorComputerBase = GRAY;

	logo = R"delimiter(
                                                                @EEEEEEEEEEEEE@
 RRRR   RRR              :?RRRRR~                               Q             B
 RRRR   RRR             !RRRRRRRR                               Q      /\     B
 RRRR?  RRR   ';?RR?!.  RRRR   RR RRR  ^RRR  RRR:?R   ^?RR*!    @_    /  \  __B
 RRRRR! RRR  ,RRRRRRR?  RRR!      RRR  *RRR  RRRRRR  RRRRRRR>   Q \  /    \/  Q
 RRRRRR RRR  >RR   RRR  RRR:      RRR  *RRR  RRRR:: ?RR   RRR   Q  \/         B
 RRR:RRRRRR `RRR   RRR  RRR:      RRR  *RRR  RRR,  .RRR   RRR   Q             B
 RRR`^RRRRR `RRR?YYYY   RRR;      RRR  *RRR  RRR,  `RRR?YYYY    @CCCCCCCCCCCCC@
 RRR .RRRRR  RRR?       RRRR:,,:` RRR:,?RRR  RRR,   ?RR*            \NAv4Q/    
 RRR  :RRRR  'RRRR?RR:  :RRRRRRR' RRRRRRRRR  RRR,   ,RRRR?RR:      NevvvvvoQ   
 RRR   ^RRR   'RRRRR>    'RRRRR,  ^RRRRRRRR  RRR'    'RRRRR>       v444444Rv PP
                                                                               
 Necurs Removing Tool                                                          
)delimiter";
	printChunkIncBuffer(logo, colorLetter, &start, &end, 65);
	printChunkIncBuffer(logo, colorComputer, &start, &end, 15);
	for (int i = 0; i < 6; i++) {
		printChunkIncBuffer(logo, colorLetter, &start, &end, 65);
		printChunkIncBuffer(logo, colorComputer, &start, &end, 1);
		printChunkIncBuffer(logo, colorLine, &start, &end, 13);
		printChunkIncBuffer(logo, colorComputer, &start, &end, 1);
	}
	printChunkIncBuffer(logo, colorLetter, &start, &end, 65);
	printChunkIncBuffer(logo, colorComputer, &start, &end, 15);
	for (int i = 0; i < 3; i++) {
		printChunkIncBuffer(logo, colorLetter, &start, &end, 65);
		printChunkIncBuffer(logo, colorComputerBase, &start, &end, 15);
	}
	printChunkIncBuffer(logo, RED, &start, &end, 160);
	colorPrint(WHITE, "\n\n", NULL);

}


void printNecsistsLogo() {
	char* logo;
	int start = 0;
	int end = 0;
	WORD colorLetter = DARKGREEN;
	WORD colorShoot_ = DARKRED;

	logo = R"delimiter(
                                                            aaaaaaaa           
                                                         aaqDqygQC4HHaa        
                                                       aug  ad {O    ;XR/      
                                                     \Hl  aa   HR       eR     
                                                    vD  ugP    !i         :Q:  
                                                   !H  :Q                  :Q  
 @@   Q@           o@@@@y         )e          >@  3Q* D4       8@           4t 
 @@u  Q@    ____  >@@  @@   __         ___    k@  za ___       W@            @ 
 @@@" Q@   D@Q@Q: a@Q  @@  Q@B@   B@  ;@@Q@  4@@@QOQOKQHK:  i@@@@@@Q   }bQWKO@;
 @Q@6 Q@  l@8  @O w@B     y@y p@  Q@  d@  Q@  N@!  B@C H@!     D@       Q!  Ul 
 @bN@ Q@  p@S  @B w@B      @Q  !  Q@  j@8  !  N@!  L@Q  !      D@      Bl  /Q  
 @gP@XN@  H@BXH@H w@B       @Q    B@   B@N    N@!   a@Q              tH!  :Q!  
 @B a@Q@  H@q     w@B        @@   B@    j@Q:  N@!    l@@L      @@  Hp>   iH    
 @B  @@@  K@o   ! o@B  Q@ !   @@  Q@  rL 7@Q  N@!  !  =@@      @@\:    !K6     
 @B  e@@  s@R  @9 >@@  @@ l@  K@  B@  8@: Q@! W@!  E@  H@|a!   @@    \d9P      
 @B   @@   Q@B@Q!  q@QQ@U  @@H@g  B@  c@@H@A  7@@N  @@H@Q  odd$6@9Kdpv         
 PP   PP    PPP     PPPP    PPP   PP   PPPP    PPP   PPP     PPPPPPP           )delimiter";

	printChunkIncBuffer(logo, colorShoot_, &start, &end, 480);

	printChunkIncBuffer(logo, colorLetter, &start, &end, 50);
	printChunkIncBuffer(logo, colorShoot_, &start, &end, 30);

	printChunkIncBuffer(logo, colorLetter, &start, &end, 50);
	printChunkIncBuffer(logo, colorShoot_, &start, &end, 3);
	printChunkIncBuffer(logo, colorLetter, &start, &end, 4);
	printChunkIncBuffer(logo, colorShoot_, &start, &end, 23);

	for (int i = 0; i < 9; i++) {
		printChunkIncBuffer(logo, colorLetter, &start, &end, 58);
		printChunkIncBuffer(logo, colorShoot_, &start, &end, 22);
	}

	printf("\n");
	changeColor(WHITE);

}

void printRkInfo(RK_INFO_S* info) {
	SYSTEMTIME st;
	WORD colHead = WHITE;
	WORD colLeft = CYAN;
	WORD colRight = WHITE;
	colorPrint(colHead, "\n EXTRACTED INFO\n -----------------------------------------------\n", NULL);
	colorPrint(colLeft, " Install Date:     ", NULL);

	changeColor(colRight);
	if (info->installDate.dwLowDateTime == NULL && info->installDate.dwHighDateTime == NULL)
		printf(" Not found!!\n");
	else {
		if (FileTimeToSystemTime(&(info->installDate), &st))
			printf("%02d-%02d-%04d %02d:%02d:%02d (UTC)\n", st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond);
		else
			printf("Unknown error parsing date\n");
	}

	colorPrint(colLeft, " Status:           ", NULL);
	info->execNumber == 0 ? colorPrint(RED, "Active\n",NULL) : colorPrint(YELLOW, "SemiActive\n", NULL) ;

	colorPrint(colLeft, " Execution Number: ", NULL);
	colorPrint(colRight, "%d\n", (DWORD)info->execNumber);

	colorPrint(colLeft, " Service Name:     ", NULL);
	colorPrint(colRight, "%ls\n", (DWORD)info->nameRootkit);

	colorPrint(colHead, " -----------------------------------------------\n", NULL);
}