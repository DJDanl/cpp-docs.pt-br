---
title: strtol, wcstol, _strtol_l, _wcstol_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- strtol
- wcstol
- _strtol_l
- _wcstol_l
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
- _wcstol_l
- strtol
- _tcstol
- wcstol
- _strtol_l
- _tcstol_l
dev_langs: C++
helpviewer_keywords:
- wcstol function
- wcstol_l function
- _tcstol function
- string conversion, to integers
- tcstol function
- strtol_l function
- _wcstol_l function
- _strtol_l function
- strtol function
ms.assetid: 1787c96a-f283-4a83-9325-33cfc1c7e240
caps.latest.revision: "18"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 8c1678b523b9225e7ea0986e5ef8d00c5fd31391
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="strtol-wcstol-strtoll-wcstoll"></a>strtol, wcstol, _strtol_l, _wcstol_l
Converte uma cadeia de caracteres para um valor inteiro e longo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
long strtol(  
   const char *nptr,  
   char **endptr,  
   int base   
);  
long wcstol(  
   const wchar_t *nptr,  
   wchar_t **endptr,  
   int base   
);  
long _strtol_l(  
   const char *nptr,  
   char **endptr,  
   int base,  
   _locale_t locale  
);  
long _wcstol_l(  
   const wchar_t *nptr,  
   wchar_t **endptr,  
   int base,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nptr`  
 Cadeia de caracteres terminada em nulo a ser convertida.  
  
 `endptr`  
 Ponteiro para o caractere que interrompe a verificação.  
  
 `base`  
 O número base a ser usado.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 `strtol` retorna o valor representado em uma cadeia de caracteres `nptr`, exceto quando a representação causaria um estouro — nesse caso, a função retorna `LONG_MAX` ou `LONG_MIN`. `strtol` retorna 0 se nenhuma conversão pode ser realizada. `wcstol` retorna valores de maneira semelhante a `strtol`. Para ambas as funções, `errno` será definido como `ERANGE` se ocorrer um estouro ou estouro negativo.  
  
 Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.  
  
## <a name="remarks"></a>Comentários  
 A função `strtol` converte `nptr` para um `long`. `strtol` interrompe a leitura da cadeia de caracteres `nptr` no primeiro caractere que ele não reconhece como parte de um número. Isso pode ser o caractere nulo de terminação ou pode ser o primeiro caractere numérico maior ou igual a `base`.  
  
 `wcstol` é uma versão de caractere largo de `strtol`; seu argumento `nptr` é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcstol`|`strtol`|`strtol`|`wcstol`|  
|`_tcstol_l`|`_strtol_l`|`_strtol_l`|`_wcstol_l`|  
  
 A configuração da categoria `LC_NUMERIC` da localidade atual determina o reconhecimento do caractere fracionário em `nptr`*;* para mais informações, consulte [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md). As funções sem o sufixo `_l` usam a localidade atual; `_strtol_l` e `_wcstol_l` são idênticas as funções correspondentes sem o sufixo `_l`, exceto por usarem o parâmetro de localidade informado. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Se `endptr` não é `NULL`, um ponteiro para o caractere que parou a verificação é armazenado no local apontado pela `endptr`. Se nenhuma conversão pode ser executada (Nenhum dígito válido foi encontrado ou uma base inválida foi especificada), o valor de `nptr` é armazenado no local apontado pela `endptr`.  
  
 `strtol` espera que `nptr` aponte para uma cadeia de caracteres do seguinte formato:  
  
 [`whitespace`] [{`+` &#124; `-`}] [`0` [{ `x` &#124; `X` }]] [`digits`]  
  
 Um `whitespace` consiste em caracteres de espaço ou tabulação, que são ignorados; `digits` é composto por um ou mais dígitos decimais. O primeiro caractere que não é adequado a esse formato interrompe o exame. Se `base` estiver entre 2 e 36, ele será usado como a base do número. Se `base` é 0, os caracteres inicias da cadeia de caracteres apontada por `nptr` são usados para determinar a base. Se o primeiro caractere é 0 e o segundo caractere não for 'x' ou 'X', a cadeia de caracteres é interpretada como um inteiro octal. Se o primeiro caractere for '0' e o segundo caractere for 'x' ou 'X', a cadeia de caracteres será interpretada como um inteiro hexadecimal. Se o primeiro caractere for de '1' até '9', a cadeia de caracteres será interpretada como um inteiro hexadecimal. As letras 'a' a 'z' (ou 'A' a 'Z') recebem os valores 10 a 35; somente são permitidas letras cujos valores atribuídos são menores que `base`. O primeiro caractere fora do intervalo da base interrompe o exame. Por exemplo, se `base` é 0 e o primeiro caractere verificado é '0', é considerado um inteiro octal e um caractere '8' ou '9' interromperá a verificação.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`strtol`|\<stdlib.h>|  
|`wcstol`|\<stdlib.h> ou \<wchar.h>|  
|`_strtol_l`|\<stdlib.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo de [strtod](../../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md)   
 [Funções de valor de cadeia de caracteres para numérico](../../c-runtime-library/string-to-numeric-value-functions.md)   
 [strtod, _strtod_l, wcstod, _wcstod_l](../../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md)   
 [strtoul, _strtoul_l, wcstoul, _wcstoul_l](../../c-runtime-library/reference/strtoul-strtoul-l-wcstoul-wcstoul-l.md)   
 [atof, _atof_l, _wtof, _wtof_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)