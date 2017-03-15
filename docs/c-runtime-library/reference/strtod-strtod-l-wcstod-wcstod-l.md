---
title: strtod, _strtod_l, wcstod, _wcstod_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- wcstod
- _wcstod_l
- _strtod_l
- strtod
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-convert-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _tcstod
- strtod
- wcstod
- _strtod_l
- _wcstod_l
- stdlib/strtod
- corecrt_wstdlib/wcstod
- stdlib/_strtod_l
- corecrt_wstdlib/_wcstod_l
dev_langs:
- C++
helpviewer_keywords:
- wcstod_l function
- tcstod_l function
- _tcstod_l function
- strtod function
- _wcstod_l function
- wcstod function
- strtod_l function
- tcstod function
- _tcstod function
- _strtod_l function
- string conversion, to floating point values
ms.assetid: 0444f74a-ba2a-4973-b7f0-1d77ba88c6ed
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 9ca01e10def2b84a07724c418c5c785259569bca
ms.lasthandoff: 02/25/2017

---
# <a name="strtod-strtodl-wcstod-wcstodl"></a>strtod, _strtod_l, wcstod, _wcstod_l
Converte cadeias de caracteres em um valor de precisão dupla.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
## <a name="parameters"></a>Parâmetros  
 `nptr`  
 Cadeia de caracteres terminada em nulo a ser convertida.  
  
 `endptr`  
 Ponteiro para o caractere que interrompe a verificação.  
  
 `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 `strtod` retorna o valor do número de ponto flutuante, exceto quando a representação causaria um estouro — nesse caso, a função retorna + / –`HUGE_VAL`. O sinal de `HUGE_VAL` coincide com o sinal do valor que não pode ser representado. `strtod` retorna 0 se nenhuma conversão pode ser realizada ou ocorrerá um estouro negativo.  
  
 `wcstod` retorna valores de maneira semelhante a `strtod`. Para ambas as funções, `errno` é definido como `ERANGE` se ocorre estouro ou estouro negativo e o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  
  
 Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.  
  
## <a name="remarks"></a>Comentários  
 Cada função converte a cadeia de caracteres de entrada `nptr` para um `double`. A função `strtod` converte `nptr` para um valor de precisão dupla. `strtod` interrompe a leitura da cadeia de caracteres `nptr` no primeiro caractere que ele não reconhece como parte de um número. Este pode ser o caractere nulo de terminação. `wcstod` é uma versão de caractere largo de `strtod`; seu argumento `nptr` é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcstod`|`strtod`|`strtod`|`wcstod`|  
|`_tcstod_l`|`_strtod_l`|`_strtod_l`|`_wcstod_l`|  
  
 A configuração `LC_NUMERIC` de categoria da localidade atual determina o reconhecimento do caractere fracionário em `nptr`*;* para mais informações, consulte [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md). As funções sem o `_l` sufixo usam a localidade atual; `_strtod_l` é idêntico ao `_strtod_l`, exceto que usam a localidade que é informada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Se `endptr` não é `NULL`, um ponteiro para o caractere que parou a verificação é armazenado no local apontado pela `endptr`. Se nenhuma conversão pode ser executada (Nenhum dígito válido foi encontrado ou uma base inválida foi especificada), o valor de `nptr` é armazenado no local apontado pela `endptr`.  
  
 `strtod` espera que `nptr` aponte para uma cadeia de caracteres do seguinte formato:  
  
 [`whitespace`] [`sign`] [`digits`] [`.digits`] [ {`e` &#124; `E`}[`sign`]`digits`]  
  
 Um `whitespace` consiste em caracteres de espaço ou tabulação, que são ignorados; `sign` é um sinal de mais (`+`) ou menos (`–`); e `digits` é composto por um ou mais dígitos decimais. Se nenhum dígito aparecer antes do caractere fracionário, pelo menos um deverá aparecer após o caractere fracionário. Os dígitos decimais podem ser seguidos por um expoente, que consiste em uma letra de apresentação (`e` ou `E`) e um inteiro opcionalmente com sinal. Se nem um expoente nem um caractere fracionário aparecer, supõe-se que um caractere fracionário siga o último dígito na cadeia de caracteres. O primeiro caractere que não é adequado a esse formato interrompe o exame.  
 
 As versões UCRT dessas funções não dão suporte para a conversão do estilo Fortran (`d` ou `D`) letras de expoente. Essa extensão não padrão tinha suporte em versões anteriores do CRT e pode ser uma alteração significativa para seu código.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`strtod`, `_strtod_l`|C: \<stdlib.h> C++: &lt;cstdlib> ou \<stdlib.h> |  
|`wcstod`, `_wcstod_l`|C: \<stdlib.h> ou \<wchar.h> C++: &lt;cstdlib>, \<stdlib.h> ou \<wchar.h> |  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```C  
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
  
```Output  
string = 3.1415926This stopped it  
   strtod = 3.141593  
   Stopped scan at: This stopped it  
  
string = -10110134932This stopped it  
   strtol = -2147483648  
   Stopped scan at: This stopped it  
  
string = 10110134932  
   strtol = 45 (base 2)  
   Stopped scan at: 34932  
   strtol = 4423 (base 4)  
   Stopped scan at: 4932  
   strtol = 2134108 (base 8)  
   Stopped scan at: 932  
```  
    
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Funções de valor de cadeia de caracteres para numérico](../../c-runtime-library/string-to-numeric-value-functions.md)   
 [strtol, wcstol, _strtol_l, _wcstol_l](../../c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l.md)   
 [strtoul, _strtoul_l, wcstoul, _wcstoul_l](../../c-runtime-library/reference/strtoul-strtoul-l-wcstoul-wcstoul-l.md)   
 [atof, _atof_l, _wtof, _wtof_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [_create_locale, _wcreate_locale](../../c-runtime-library/reference/create-locale-wcreate-locale.md)   
 [_free_locale](../../c-runtime-library/reference/free-locale.md)
