---
title: "strtod, _strtod_l, wcstod, _wcstod_l | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "wcstod"
  - "_wcstod_l"
  - "_strtod_l"
  - "strtod"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-convert-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_tcstod"
  - "strtod"
  - "wcstod"
  - "_strtod_l"
  - "_wcstod_l"
  - "stdlib/strtod"
  - "corecrt_wstdlib/wcstod"
  - "stdlib/_strtod_l"
  - "corecrt_wstdlib/_wcstod_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _strtod_l"
  - "Função _tcstod"
  - "Função _tcstod_l"
  - "Função _wcstod_l"
  - "conversão de cadeia de caracteres, para valores de ponto flutuante"
  - "Função strtod"
  - "Função strtod_l"
  - "Função tcstod"
  - "Função tcstod_l"
  - "Função wcstod"
  - "Função wcstod_l"
ms.assetid: 0444f74a-ba2a-4973-b7f0-1d77ba88c6ed
caps.latest.revision: 20
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strtod, _strtod_l, wcstod, _wcstod_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cadeias de caracteres de conversão como um valor de precisão dupla.  
  
## Sintaxe  
  
```  
double strtod(  
   const char *nptr,  
   char **endptr   
);  
double _strtod_l(  
   const char *nptr,  
   char **endptr,  
   _locale_t locale  
);  
double wcstod(  
   const wchar_t *nptr,  
   wchar_t **endptr   
);  
double wcstod_l(  
   const wchar_t *nptr,  
   wchar_t **endptr,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `nptr`  
 Cadeia de caracteres nula a ser convertida.  
  
 `endptr`  
 Ponteiro para o caractere que para o exame.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 `strtod` retorna o valor do número de ponto flutuante, exceto quando a representação resulta em um estouro, nesse caso a função retorna \+\/\-`HUGE_VAL`.  O sinal de `HUGE_VAL` corresponde ao sinal de valor que não pode ser representado.  `strtod` retorna 0 se nenhuma conversão puder ser executada ou ocorre um estouro negativo.  
  
 Valores de retornos do `wcstod` análogos a `strtod`.  Para ambas as funções, `errno` é definido como `ERANGE` se o estouro ou o estouro negativo ocorrerem e o manipulador de parâmetro inválido for invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  
  
 Consulte [\_doserrno, errno, \_sys\_errlist, e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) para obter mais informações sobre esse e outros códigos de retorno.  
  
## Comentários  
 Cada função converte a cadeia de caracteres `nptr` de entrada em um `double`.  A função de `strtod` converte `nptr` a um valor de precisão dupla.  `strtod` deixa de ler a cadeia de caracteres `nptr` no primeiro caractere que ela não reconhece ser parte de um número.  Isso pode ser o caractere de terminação zero.  `wcstod` é uma versão de caractere amplo de `strtod`; seu argumento `nptr` é uma cadeira de caractere longo.  Essas funções se comportam exatamente o contrário.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tcstod`|`strtod`|`strtod`|`wcstod`|  
|`_tcstod_l`|`_strtod_l`|`_strtod_l`|`_wcstod_l`|  
  
 A configuração da categoria de `LC_NUMERIC` de localidade atual determina o reconhecimento de caracteres raiz em `nptr`*;* para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  As funções sem o sufixo de `_l` usam a localidade atual; `_strtod_l` é idêntico a `_strtod_l` exceto que usam a localidade passada por vez.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Se `endptr` não for `NULL`, um ponteiro para o caractere que interrompeu a verificação é armazenado no local apontado por `endptr`.  Se nenhuma conversão puder ser executada \(nenhum dígito válido foi encontrado ou uma base inválida foi especificada\), o valor de `nptr` será armazenado no local apontado por `endptr`.  
  
 `strtod` espera `nptr` apontar para uma cadeia de caracteres de seguinte forma:  
  
 \[`whitespace`\] \[`sign`\] \[`digits`\] \[`.digits`\] \[ {`d` &#124; `D` &#124; `e` &#124; `E`}\[`sign`\]`digits`\]  
  
 Um `whitespace` pode consistir nos caracteres de espaço e de tabulação, que são ignorados; `sign` é mais \(`+`\) ou menos \(`–`\); and `digits` é um ou mais dígitos decimais.  Se nenhum dígito aparece antes do caractere raiz, pelo menos um deve aparecer após o caractere raiz.  Os dígitos decimais podem ser seguidos por um expoente, que consiste em uma letra introdutória \(`d`, `D`, `e` ou `E`\) e opcionalmente em um inteiro com sinal.  Se uma parte do expoente ou um caractere raiz não aparecem, um caractere de raiz seguirá o último dígito da cadeia de caracteres.  O primeiro caractere que não se ajusta a este formulário interrompe o exame.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strtod`, `_strtod_l`|\<stdlib.h\>|  
|`wcstod`, `_wcstod_l`|\<stdlib.h\> ou \<wchar.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_strtod.c  
// This program uses strtod to convert a  
// string to a double-precision value; strtol to  
// convert a string to long integer values; and strtoul  
// to convert a string to unsigned long-integer values.  
//  
  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char   *string, *stopstring;  
   double x;  
   long   l;  
   int    base;  
   unsigned long ul;  
  
   string = "3.1415926This stopped it";  
   x = strtod( string, &stopstring );  
   printf( "string = %s\n", string );  
   printf("   strtod = %f\n", x );  
   printf("   Stopped scan at: %s\n\n", stopstring );  
  
   string = "-10110134932This stopped it";  
   l = strtol( string, &stopstring, 10 );  
   printf( "string = %s\n", string );  
   printf("   strtol = %ld\n", l );  
   printf("   Stopped scan at: %s\n\n", stopstring );  
  
   string = "10110134932";  
   printf( "string = %s\n", string );  
  
   // Convert string using base 2, 4, and 8:  
   for( base = 2; base <= 8; base *= 2 )  
   {  
      // Convert the string:  
      ul = strtoul( string, &stopstring, base );  
      printf( "   strtol = %ld (base %d)\n", ul, base );  
      printf( "   Stopped scan at: %s\n", stopstring );  
   }  
}  
```  
  
  **a cadeia de caracteres \= 3.1415926This interrompê\-lo**  
 **strtod \= 3,141593**  
 **Verificação interrompida em: Isto a interrompe**  
**a cadeia de caracteres \= \-10110134932This pará\-lo**  
 **strtol \= \-2147483648**  
 **Verificação interrompida em: Isto a interrompe**  
**cadeia de caracteres \= 10110134932**  
 **strtol \= 45 \(base 2\)**  
 **Auditoria interrompido em: 34932**  
 **strtol \= 4423 \(base 4\)**  
 **Auditoria interrompido em: 4932**  
 **strtol \= 2134108 \(base 8\)**  
 **Auditoria interrompido em: 932**   
## Equivalência do .NET Framework  
 [System::Convert::ToDouble](https://msdn.microsoft.com/en-us/library/system.convert.todouble.aspx)  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Funções de valor da cadeia de caracteres para numérico](../../c-runtime-library/string-to-numeric-value-functions.md)   
 [strtol, wcstol, \_strtol\_l, \_wcstol\_l](../../c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l.md)   
 [strtoul, \_strtoul\_l, wcstoul, \_wcstoul\_l](../../c-runtime-library/reference/strtoul-strtoul-l-wcstoul-wcstoul-l.md)   
 [atof, \_atof\_l, \_wtof, \_wtof\_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [\_create\_locale, \_wcreate\_locale](../../c-runtime-library/reference/create-locale-wcreate-locale.md)   
 [\_free\_locale](../../c-runtime-library/reference/free-locale.md)