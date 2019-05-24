#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_INPUT 50 // 最多輸入位數 
#define MAX_SPECIAL_UNITS 5 // 特殊單位個數 

int main() { 
char su[MAX_SPECIAL_UNITS][3] = {"萬", "億", "兆", "京", "垓"}; // 特殊單位 
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
//sprintf(tmp_ch, "零"); 
break; 
case '1': 
sprintf(tmp_ch, "壹"); 
break; 
case '2': 
sprintf(tmp_ch, "貳"); 
break; 
case '3': 
sprintf(tmp_ch, "參"); 
break; 
case '4': 
sprintf(tmp_ch, "肆"); 
break; 
case '5': 
sprintf(tmp_ch, "伍"); 
break; 
case '6': 
sprintf(tmp_ch, "陸"); 
break; 
case '7': 
sprintf(tmp_ch, "柒"); 
break; 
case '8': 
sprintf(tmp_ch, "捌"); 
break; 
case '9': 
sprintf(tmp_ch, "玖"); 
break; 
default: 
printf("輸入錯誤!\n"); 
system("pause"); 
exit(1); 
} 

if ((cnt_nu%4) > 0) { 
if (input[i] != '0') { 
switch(cnt_nu%4) { 
case 1: // 拾 
sprintf(tmp_ch, "%s拾", tmp_ch); 
break; 
case 2: // 佰 
sprintf(tmp_ch, "%s佰", tmp_ch); 
break; 
case 3: // 仟 
sprintf(tmp_ch, "%s仟", tmp_ch); 
break; 
default: 
printf("輸入錯誤!\n"); 
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
