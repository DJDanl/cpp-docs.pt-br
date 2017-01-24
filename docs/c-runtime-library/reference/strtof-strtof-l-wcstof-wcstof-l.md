---
title: "strtof, _strtof_l, wcstof, _wcstof_l | Microsoft Docs"
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
  - "_strtof_l"
  - "wcstof"
  - "strtof"
  - "_wcstof_l"
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
  - "_tcstof"
  - "_tcstof_l"
  - "stdlib/strtof"
  - "strtof"
  - "stdlib/_strtof_l"
  - "_strtof_l"
  - "corecrt_wstdlib/wcstof"
  - "wcstof"
  - "corecrt_wstdlib/_wcstof_l"
  - "_wcstof_l"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função _strtof_l"
  - "Função _tcstof"
  - "Função _tcstof_l"
  - "Função _wcstof_l"
  - "Função strtof"
  - "Função wcstof"
ms.assetid: 52221b46-876d-4fcc-afb1-97512c17a43b
caps.latest.revision: 9
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strtof, _strtof_l, wcstof, _wcstof_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte cadeias de caracteres em um valor de ponto flutuante de precisão simples.  
  
## Sintaxe  
  
```  
float strtof(  
   const char *nptr,  
   char **endptr   
);  
float _strtof_l(  
   const char *nptr,  
   char **endptr,  
   _locale_t locale  
);  
float wcstof(  
   const wchar_t *nptr,  
   wchar_t **endptr   
);  
float wcstof_l(  
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
 `strtof` retorna o valor do número de ponto flutuante, exceto quando a representação resulta em um estouro, nesse caso a função retorna \+\/\-`HUGE_VALF`.  O sinal de `HUGE_VALF` corresponde ao sinal de valor que não pode ser representado.  `strtof` retorna 0 se nenhuma conversão puder ser executada ou ocorre um estouro negativo.  
  
 Valores de retornos do `wcstof` análogos a `strtof`.  Para ambas as funções, `errno` é definido como `ERANGE` se o estouro ou o estouro negativo ocorrerem e o manipulador de parâmetro inválido for invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  
  
 Para obter mais informações sobre códigos de retorno, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 Cada função converte a cadeia de caracteres `nptr` de entrada em um `float`.  A função de `strtof` converte `nptr` em um valor de precisão simples.  `strtof` deixa de ler a cadeia de caracteres `nptr` no primeiro caractere que ela não reconhece ser parte de um número.  Isso pode ser o caractere de terminação zero.  `wcstof` é uma versão de caractere amplo de `strtof`; seu argumento `nptr` é uma cadeira de caractere longo.  Do contrário, essas funções se comportam de forma idêntica.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tcstof`|`strtof`|`strtof`|`wcstof`|  
|`_tcstof_l`|`_strtof_l`|`_strtof_l`|`_wcstof_l`|  
  
 A configuração de categoria `LC_NUMERIC` da localidade atual determina o reconhecimento do caractere raiz em `nptr`; para obter mais informações, consulte [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md).  As funções que não têm o sufixo `_l` usam a localidade atual; aquelas que têm o sufixo são idênticas , com exceção que elas usam a localidade que é informada.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Se `endptr` não for `NULL`, um ponteiro para o caractere que parou a verificação é armazenado no local que é apontado por `endptr`.  Se nenhuma conversão puder ser executada \(nenhum dígito válido foi encontrado ou uma base inválida foi especificado\), o valor de `nptr` será armazenado no local que é apontado por `endptr`.  
  
 `strtof` espera `nptr` apontar para uma cadeia de caracteres de seguinte forma:  
  
 \[`whitespace`\] \[`sign`\] \[`digits`\] \[`.digits`\] \[ {`d` &#124; `D` &#124; `e` &#124; `E`}\[`sign`\]`digits`\]  
  
 Um `whitespace` pode consistir nos caracteres de espaço e de tabulação, que são ignorados; `sign` é mais \(`+`\) ou menos \(`–`\); and `digits` é um ou mais dígitos decimais.  Se nenhum dígito aparece antes do caractere raiz, pelo menos um deve aparecer após o caractere raiz.  Os dígitos decimais podem ser seguidos por um expoente, que consiste em uma letra introdutória \(`d`, `D`, `e` ou `E`\) e opcionalmente em um inteiro com sinal.  Se uma parte do expoente ou um caractere raiz não aparecem, um caractere de raiz seguirá o último dígito da cadeia de caracteres.  O primeiro caractere que não se ajusta a este formulário interrompe o exame.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strtof`, `_strtof_l`|\<stdlib.h\>|  
|`wcstof`, `_wcstof_l`|\<stdlib.h\> ou \<wchar.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_strtof.c  
// This program uses strtof to convert a  
// string to a single-precision value.  
  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char *string;  
   char *stopstring;  
   float x;  
  
   string = "3.14159This stopped it";  
   x = strtof(string, &stopstring);  
   printf("string = %s\n", string);  
   printf("   strtof = %f\n", x);  
   printf("   Stopped scan at: %s\n\n", stopstring);  
}  
```  
  
  **a cadeia de caracteres \= 3.14159 Isso a interrompe**  
 **strtof \= 3.141590**  
 **Verificação interrompida em: Isto a interrompe**   
## Equivalência do .NET Framework  
 [System::Convert::ToSingle](https://msdn.microsoft.com/en-us/library/system.convert.tosingle.aspx)  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Funções de valor da cadeia de caracteres para numérico](../../c-runtime-library/string-to-numeric-value-functions.md)   
 [strtod, \_strtod\_l, wcstod, \_wcstod\_l](../../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md)   
 [strtol, wcstol, \_strtol\_l, \_wcstol\_l](../../c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l.md)   
 [strtoul, \_strtoul\_l, wcstoul, \_wcstoul\_l](../../c-runtime-library/reference/strtoul-strtoul-l-wcstoul-wcstoul-l.md)   
 [atof, \_atof\_l, \_wtof, \_wtof\_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [\_create\_locale, \_wcreate\_locale](../../c-runtime-library/reference/create-locale-wcreate-locale.md)   
 [\_free\_locale](../../c-runtime-library/reference/free-locale.md)