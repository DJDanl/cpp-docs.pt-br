---
title: _strtoi64, _wcstoi64, _strtoi64_l, _wcstoi64_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _strtoi64
- _strtoi64_l
- _wcstoi64_l
- _wcstoi64
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
- _strtoi64
- strtoi64
- _stroi64_l
- _wcstoi64_l
- wcstoi64_l
- _wcstoi64
- wcstoi64
- strtoi64_l
dev_langs:
- C++
helpviewer_keywords:
- _strtoi64 function
- _wcstoi64 function
- _strtoi64_l function
- string conversion, to integers
- _wcstoi64_l function
- strtoi64_l function
- wcstoi64 function
- strtoi64 function
- wcstoi64_l function
ms.assetid: ea2abc50-7bfe-420e-a46b-703c3153593a
caps.latest.revision: 16
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5a383d53c762f4bd15d7a45288bb2ef4e7e452ee
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="strtoi64-wcstoi64-strtoi64l-wcstoi64l"></a>_strtoi64, _wcstoi64, _strtoi64_l, _wcstoi64_l
Converta uma cadeia de caracteres em valor `__int64`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__int64 _strtoi64(  
   const char *nptr,  
   char **endptr,  
   int base   
);  
__int64 _wcstoi64(  
   const wchar_t *nptr,  
   wchar_t **endptr,  
   int base   
);  
__int64 _strtoi64_l(  
   const char *nptr,  
   char **endptr,  
   int base,  
   _locale_t locale  
);  
__int64 _wcstoi64_l(  
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
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 `_strtoi64` retorna o valor representado em uma cadeia de caracteres `nptr`, exceto quando a representação causaria um estouro — nesse caso, a função retorna `_I64_MAX` ou `_I64_MIN`. A função retornará 0, se nenhuma conversão puder ser realizada. `_wcstoi64` retorna valores de maneira semelhante a `strtoi64`.  
  
 `_I64_MAX` e `_I64_MIN` são definidos em LIMITS.H.  
  
 Se `nptr` é `NULL` ou `base` é diferente de zero e menos que 2 ou maior que 36, `errno` é definido como `EINVAL`.  
  
 Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.  
  
## <a name="remarks"></a>Comentários  
 A função `_strtoi64` converte `nptr` para um `__int64`. Ambas as funções param de ler a cadeia de caracteres `nptr` no primeiro caractere que não reconhecem como parte de um número. Isso pode ser o caractere nulo de terminação ou pode ser o primeiro caractere numérico maior ou igual a `base`. `_wcstoi64` é uma versão de caractere largo de `_strtoi64`; seu argumento `nptr` é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcstoi64`|`_strtoi64`|`_strtoi64`|`_wcstoi64`|  
|`_tcstoi64_l`|`_strtoi64_l`|`_strtoi64_l`|`_wcstoi64_l`|  
  
 A configuração da categoria `LC_NUMERIC` da localidade determina o reconhecimento do caractere fracionário em `nptr`*;* para mais informações, consulte [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md). As funções sem o sufixo _l usam a localidade atual; `_strtoi64_l` e `_wcstoi64_l` são idênticos para a função correspondente sem o `_l` sufixo exceto que eles usam a localidade passada em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Se `endptr` não é `NULL`, um ponteiro para o caractere que parou a verificação é armazenado no local apontado pela `endptr`. Se nenhuma conversão pode ser executada (Nenhum dígito válido foi encontrado ou uma base inválida foi especificada), o valor de `nptr` é armazenado no local apontado pela `endptr`.  
  
 `_strtoi64` espera que `nptr` aponte para uma cadeia de caracteres do seguinte formato:  
  
 [`whitespace`] [{`+` &#124; `-`}] [`0` [{ `x` &#124; `X` }]] [`digits`]  
  
 Um `whitespace` consiste em caracteres de espaço ou tabulação, que são ignorados; `digits` é composto por um ou mais dígitos decimais. O primeiro caractere que não é adequado a esse formato interrompe o exame. Se `base` estiver entre 2 e 36, ele será usado como a base do número. Se `base` é 0, os caracteres inicias da cadeia de caracteres apontada por `nptr` são usados para determinar a base. Se o primeiro caractere é 0 e o segundo caractere não for 'x' ou 'X', a cadeia de caracteres é interpretada como um inteiro octal. Se o primeiro caractere for '0' e o segundo caractere for 'x' ou 'X', a cadeia de caracteres será interpretada como um inteiro hexadecimal. Se o primeiro caractere for de '1' até '9', a cadeia de caracteres será interpretada como um inteiro hexadecimal. As letras 'a' a 'z' (ou 'A' a 'Z') recebem os valores 10 a 35; somente são permitidas letras cujos valores atribuídos são menores que `base`. O primeiro caractere fora do intervalo da base interrompe o exame. Por exemplo, se `base` é 0 e o primeiro caractere verificado é '0', é considerado um inteiro octal e um caractere '8' ou '9' interromperá a verificação.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_strtoi64`, `_strtoi64_l`|\<stdlib.h>|  
|`_wcstoi64`, `_wcstoi64_l`|\<stdlib.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md)   
 [Funções de valor de cadeia de caracteres para numérico](../../c-runtime-library/string-to-numeric-value-functions.md)   
 [strtod, _strtod_l, wcstod, _wcstod_l](../../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md)   
 [strtoul, _strtoul_l, wcstoul, _wcstoul_l](../../c-runtime-library/reference/strtoul-strtoul-l-wcstoul-wcstoul-l.md)   
 [atof, _atof_l, _wtof, _wtof_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)