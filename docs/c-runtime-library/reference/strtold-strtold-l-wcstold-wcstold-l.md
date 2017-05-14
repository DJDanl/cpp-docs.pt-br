---
title: strtold, _strtold_l, wcstold, _wcstold_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- wcstold
- strtold
- _strtold_l
- _wcstold_l
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
- _tcstold_l
- _wcstold_l
- _tcstold
- strtold
- _strtold_l
- wcstold
dev_langs:
- C++
ms.assetid: 928c0c9a-bc49-445b-8822-100eb5954115
caps.latest.revision: 8
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
ms.openlocfilehash: f23b0e3105532357ba9d31634a999c98df366552
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="strtold-strtoldl-wcstold-wcstoldl"></a>strtold, _strtold_l, wcstold, _wcstold_l
Converte cadeias de caracteres em um valor de ponto flutuante de precisão dupla longo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
long double strtold(  
   const char *nptr,  
   char **endptr   
);  
long double _strtold_l(  
   const char *nptr,  
   char **endptr,  
   _locale_t locale  
);  
long double wcstold(  
   const wchar_t *nptr,  
   wchar_t **endptr   
);  
long double wcstold_l(  
   const wchar_t *nptr,  
   wchar_t **endptr,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nptr`  
 Cadeia de caracteres terminada em nulo a ser convertida.  
  
 `endptr`  
 Ponteiro para o caractere que interrompe o exame.  
  
 `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 `strtold`Retorna o valor do número de ponto flutuante como um `long double`, exceto quando a representação causaria um estouro — nesse caso, a função retorna + /-`HUGE_VALL`. O sinal de `HUGE_VALL` coincide com o sinal do valor que não pode ser representado. `strtold` retorna 0 se nenhuma conversão pode ser realizada ou ocorrerá um estouro negativo.  
  
 `wcstold` retorna valores de maneira semelhante a `strtold`. Para ambas as funções, `errno` é definido como `ERANGE` se ocorre estouro ou estouro negativo e o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  
  
 Para obter mais informações sobre os códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 Cada função converte a cadeia de caracteres de entrada `nptr` para um `long double`. A função `strtold` converte `nptr` para um valor de precisão duplo e longo. `strtold` interrompe a leitura da cadeia de caracteres `nptr` no primeiro caractere que ele não reconhece como parte de um número. Este pode ser o caractere nulo de terminação. A versão de caractere largo de `strtold` é `wcstold`; seu argumento `nptr` é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcstold`|`strtold`|`strtold`|`wcstold`|  
|`_tcstold_l`|`_strtold_l`|`_strtold_l`|`_wcstold_l`|  
  
 A configuração `LC_NUMERIC` de categoria da localidade atual determina o reconhecimento do caractere fracionário `nptr`. Para obter mais informações, consulte [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md). As funções sem o `_l` sufixo usam a localidade atual; `_strtold_l` e `_wcstold_l` são idênticos aos `_strtold` e `_wcstold`, exceto que usam a localidade que é informada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Se `endptr` não for `NULL`, um ponteiro para o caractere que interrompeu o exame será armazenado no local apontado por `endptr`. Se nenhuma conversão puder ser executada (nenhum dígito válido foi encontrado ou uma base inválida foi especificada), o valor `nptr` será armazenado no local apontado por `endptr`.  
  
 `strtold` espera que `nptr` aponte para uma cadeia de caracteres do seguinte formato:  
  
 [`whitespace`] [`sign`] [`digits`] [`.digits`] [ {`d` &#124; `D` &#124; `e` &#124; `E`}[`sign`]`digits`]  
  
 Um `whitespace` consiste em caracteres de espaço ou tabulação, que são ignorados; `sign` é um sinal de mais (`+`) ou menos (`-`); e `digits` é composto por um ou mais dígitos decimais. Se nenhum dígito aparecer antes do caractere fracionário, pelo menos um deverá aparecer após o caractere fracionário. Os dígitos decimais podem ser seguidos por um expoente, que consiste em uma letra de apresentação (`d`, `D`, `e` ou `E`) e um inteiro opcionalmente com sinal. Se nem um expoente nem um caractere fracionário aparecer, supõe-se que um caractere fracionário siga o último dígito na cadeia de caracteres. O primeiro caractere que não é adequado a esse formato interrompe o exame.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`strtold`, `_strtold_l`|\<stdlib.h>|  
|`wcstold`, `_wcstold_l`|\<stdlib.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_strtold.c  
// Build with: cl /W4 /Tc crt_strtold.c  
// This program uses strtold to convert a  
// string to a long double-precision value.  
  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char *string;  
   char *stopstring;  
   long double x;  
  
   string = "3.1415926535898This stopped it";  
   x = strtold(string, &stopstring);  
   printf("string = %s\n", string);  
   printf("   strtold = %.13Lf\n", x);  
   printf("   Stopped scan at: %s\n\n", stopstring);  
}  
```  
  
```Output  
string = 3.1415926535898This stopped it  
   strtold = 3.1415926535898  
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
