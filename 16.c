
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_INPUT 50 // ³Ì¦h¿é¤J¦ì¼Æ 
#define MAX_SPECIAL_UNITS 5 // ¯S®í³æ¦ì­Ó¼Æ 

int main() { 
char su[MAX_SPECIAL_UNITS][3] = {"¸U", "»õ", "¥ü", "¨Ê", "«²"}; // ¯S®í³æ¦ì 
//¸U¡B»õ¡B¥ü¡B¨Ê¡B«²¡BÒñ¡Böø¡B·¾¡B¼î¡B¥¿¡B¸ü¡B·¥ 

char input[MAX_INPUT]; 
char output[MAX_INPUT*4 + 1]; 
char output_tmp[MAX_INPUT*4 + 1]; 
output[0] = '\0'; 
char tmp_ch[5]; 

printf("input: "); 
scanf("%s", input); 

int i, cnt_su, cnt_nu; 
for (i = (strlen(input) - 1), cnt_su = 0, cnt_nu = 0; i >= 0; i--) { 

tmp_ch[0] = '\0'; 
output_tmp[0] = '\0'; 

switch (input[i]) { 
case '0': 
//sprintf(tmp_ch, "¹s"); 
break; 
case '1': 
sprintf(tmp_ch, "³ü"); 
break; 
case '2': 
sprintf(tmp_ch, "¶L"); 
break; 
case '3': 
sprintf(tmp_ch, "°Ñ"); 
break; 
case '4': 
sprintf(tmp_ch, "¸v"); 
break; 
case '5': 
sprintf(tmp_ch, "¥î"); 
break; 
case '6': 
sprintf(tmp_ch, "³°"); 
break; 
case '7': 
sprintf(tmp_ch, "¬m"); 
break; 
case '8': 
sprintf(tmp_ch, "®Ã"); 
break; 
case '9': 
sprintf(tmp_ch, "¨h"); 
break; 
default: 
printf("¿é¤J¿ù»~!\n"); 
system("pause"); 
exit(1); 
} 

if ((cnt_nu%4) > 0) { 
if (input[i] != '0') { 
switch(cnt_nu%4) { 
case 1: // ¬B 
sprintf(tmp_ch, "%s¬B", tmp_ch); 
break; 
case 2: // ¨Õ 
sprintf(tmp_ch, "%s¨Õ", tmp_ch); 
break; 
case 3: // ¥a 
sprintf(tmp_ch, "%s¥a", tmp_ch); 
break; 
default: 
printf("¿é¤J¿ù»~!\n"); 
system("pause"); 
exit(1); 
} 
sprintf(output_tmp, "%s", output); 
sprintf(output, "%s%s", tmp_ch, output_tmp); 
} 
} else { 
if (i == (strlen(input) - 1)) { 
sprintf(output, "%s", tmp_ch); 
} else { 
sprintf(tmp_ch, "%s%s", tmp_ch, su[cnt_su]); 
sprintf(output_tmp, "%s", output); 
sprintf(output, "%s%s", tmp_ch, output_tmp); 
cnt_su++; 
} 
} 
cnt_nu++; 
} 

printf("output: %s\n", output); 
return 0; 
} 
