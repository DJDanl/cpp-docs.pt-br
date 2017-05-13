---
title: strtof, _strtof_l, wcstof, _wcstof_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _strtof_l
- wcstof
- strtof
- _wcstof_l
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
- _tcstof
- _tcstof_l
- stdlib/strtof
- strtof
- stdlib/_strtof_l
- _strtof_l
- corecrt_wstdlib/wcstof
- wcstof
- corecrt_wstdlib/_wcstof_l
- _wcstof_l
dev_langs:
- C++
helpviewer_keywords:
- _strtof_l function
- _tcstof function
- _wcstof_l function
- wcstof function
- _tcstof_l function
- strtof function
ms.assetid: 52221b46-876d-4fcc-afb1-97512c17a43b
caps.latest.revision: 9
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 1a08c836ed0048e27957662371d352b3316e6975
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="strtof-strtofl-wcstof-wcstofl"></a>strtof, _strtof_l, wcstof, _wcstof_l
Converte cadeias de caracteres para um valor de ponto flutuante de precisão simples.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
## <a name="parameters"></a>Parâmetros  
 `nptr`  
 Cadeia de caracteres terminada em nulo a ser convertida.  
  
 `endptr`  
 Ponteiro para o caractere que interrompe o exame.  
  
 `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 `strtof`Retorna o valor do número de ponto flutuante, exceto quando a representação causaria um estouro, nesse caso, a função retorna + /-`HUGE_VALF`. O sinal de `HUGE_VALF` coincide com o sinal do valor que não pode ser representado. `strtof` retorna 0 se nenhuma conversão pode ser realizada ou ocorrerá um estouro negativo.  
  
 `wcstof` retorna valores de maneira semelhante a `strtof`. Para ambas as funções, `errno` é definido como `ERANGE` se ocorre estouro ou estouro negativo e o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  
  
 Para obter mais informações sobre os códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 Cada função converte a cadeia de caracteres de entrada `nptr` para um `float`. A função `strtof` converte `nptr` para um valor de precisão simples. `strtof` interrompe a leitura da cadeia de caracteres `nptr` no primeiro caractere que ele não reconhece como parte de um número. Este pode ser o caractere nulo de terminação. `wcstof` é uma versão de caractere largo de `strtof`; seu argumento `nptr` é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcstof`|`strtof`|`strtof`|`wcstof`|  
|`_tcstof_l`|`_strtof_l`|`_strtof_l`|`_wcstof_l`|  
  
 A configuração `LC_NUMERIC` de categoria da localidade atual determina o reconhecimento do caractere fracionário em `nptr`; para mais informações, consulte [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md). As funções que não têm o sufixo `_l` usam a localidade atual, as que usam o sufixo são idênticas, exceto por usarem o parâmetro de localidade informado em vez da localidade atual. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Se `endptr` não for `NULL`, um ponteiro para o caractere que interrompeu o exame será armazenado no local apontado por `endptr`. Se nenhuma conversão puder ser executada (nenhum dígito válido foi encontrado ou uma base inválida foi especificada), o valor `nptr` será armazenado no local apontado por `endptr`.  
  
 `strtof` espera que `nptr` aponte para uma cadeia de caracteres do seguinte formato:  
  
 [`whitespace`] [`sign`] [`digits`] [`.digits`] [ {`e` &#124; `E`}[`sign`]`digits`]  
  
 Um `whitespace` consiste em caracteres de espaço ou tabulação, que são ignorados; `sign` é um sinal de mais (`+`) ou menos (`-`); e `digits` é composto por um ou mais dígitos decimais. Se nenhum dígito aparecer antes do caractere fracionário, pelo menos um deverá aparecer após o caractere fracionário. Os dígitos decimais podem ser seguidos por um expoente, que consiste em uma letra de apresentação (`e` ou `E`) e um inteiro opcionalmente com sinal. Se nem um expoente nem um caractere fracionário aparecer, supõe-se que um caractere fracionário siga o último dígito na cadeia de caracteres. O primeiro caractere que não é adequado a esse formato interrompe o exame.  
 
 As versões UCRT dessas funções não dão suporte para a conversão do estilo Fortran (`d` ou `D`) letras de expoente. Essa extensão não padrão tinha suporte em versões anteriores do CRT e pode ser uma alteração significativa para seu código.
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`strtof`, `_strtof_l`|C: \<stdlib.h> C++: &lt;cstdlib> ou \<stdlib.h>|  
|`wcstof`, `_wcstof_l`|C: \<stdlib.h> ou \<wchar.h> C++: &lt;cstdlib>, \<stdlib.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```C  
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
  
```Output  
string = 3.14159This stopped it  
   strtof = 3.141590  
   Stopped scan at: This stopped it  
```  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Funções de valor de cadeia de caracteres para numérico](../../c-runtime-library/string-to-numeric-value-functions.md)   
 [strtod, _strtod_l, wcstod, _wcstod_l](../../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md)   
 [strtol, wcstol, _strtol_l, _wcstol_l](../../c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l.md)   
 [strtoul, _strtoul_l, wcstoul, _wcstoul_l](../../c-runtime-library/reference/strtoul-strtoul-l-wcstoul-wcstoul-l.md)   
 [atof, _atof_l, _wtof, _wtof_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [_create_locale, _wcreate_locale](../../c-runtime-library/reference/create-locale-wcreate-locale.md)   
 [_free_locale](../../c-runtime-library/reference/free-locale.md)
