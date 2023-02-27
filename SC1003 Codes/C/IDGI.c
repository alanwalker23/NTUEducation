void reverse(char *s)
{
char c, *end;
int i=0;
end = s + (strlen(s) - 1);
//printf("end - %s\n",end); [End is last char of string s including null char]
//printf("strlen(s) - %d\n",strlen(s)); [Strlen is just len of str]
//printf("s - %s\n",s); [s is the string itself]
while (s < end) {   //Comparing with 'd' and '\0'
/* 2 ends approaching centre */
/* swapping operation */
printf("ORIGINAL VARIABLES\n");
printf("c - %c (UNDEFINED HENCE BLANK)\n",c); //blank is correct as undefined.
printf("s - %s\n",s);
printf("end - %s\n\n",end);

printf("c = *s;\n");
printf("OG c:%c\n",c);
printf("OG s:%s\n",s);
printf("OG end:%s\n",end);    
c = *s; //c is taking 1st char of string s
printf("NEW c:%c (TAKES FIRST CHAR OF STRING S)\n",c);
printf("NEW s:%s\n",s);
printf("NEW end:%s\n",end);


printf("\n*s++ = *end;\n");
printf("OG c:%c\n",c);
printf("OG s:%s\n",s);
printf("OG end:%s\n",end); 
*s++ = *end; /*postfix op*/
printf("NEW c:%c\n",c);
printf("NEW s:%s\n",s);
printf("NEW end:%s\n",end);


printf("\n*end-- = c;\n");
// i.e. *s = *end; s++;
printf("OG c:%c\n",c);
printf("OG s:%s\n",s);
printf("OG end:%s\n",end);
*end-- = c; // i.e. *end = c; end‐‐;
printf("NEW c:%c\n",c);
printf("NEW s:%s\n",s);
printf("NEW end:%s\n",end);   

i++;
printf("%d iteration done\n",i);
}