---
title: _strtoui64, _wcstoui64, _strtoui64_l, _wcstoui64_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _strtoui64
- _strtoui64_l
- _wcstoui64
- _wcstoui64_l
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
- _wcstoui64_l
- strtoui64_l
- wcstoui64
- _wcstoui64
- _strtoui64_l
- strtoui64
- _strtoui64
- wcstoui64_l
dev_langs:
- C++
helpviewer_keywords:
- _strtoui64_l function
- _wcstoui64_l function
- string conversion, to integers
- wcstoui64_l function
- _strtoui64 function
- _wcstoui64 function
- wcstoui64 function
- strtoui64_l function
- strtoui64 function
ms.assetid: 7fcb537e-4554-4ceb-a5b6-bc09244e72ef
caps.latest.revision: 19
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
ms.openlocfilehash: 6d7253994d7f9920a4fcca3844766dce38f5c5d8
ms.lasthandoff: 02/25/2017

---
# <a name="strtoui64-wcstoui64-strtoui64l-wcstoui64l"></a>_strtoui64, _wcstoui64, _strtoui64_l, _wcstoui64_l
Converte uma cadeia de caracteres em um valor `__int64` não assinado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned __int64 _strtoui64(  
   const char *nptr,  
   char **endptr,  
   int base   
);  
unsigned __int64 _wcstoui64(  
   const wchar_t *nptr,  
   wchar_t **endptr,  
   int base   
);  
unsigned __int64 _strtoui64_l(  
   const char *nptr,  
   char **endptr,  
   int base,  
   _locale_t locale  
);  
unsigned __int64 _wcstoui64(  
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
 `_strtoui64` retorna o valor representado na cadeia de caracteres `nptr`, exceto quando a representação causaria um estouro, caso em que ele retorna `_UI64_MAX`. _`strtoui64` retornará 0, se nenhuma conversão pode ser realizada.  
  
 `_UI64_MAX` é definido em LIMITS.H.  
  
 Se `nptr` é `NULL` ou `base` é diferente de zero e menos que 2 ou maior que 36, `errno` é definido como `EINVAL`.  
  
 Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.  
  
## <a name="remarks"></a>Comentários  
 A função `_strtoui64` converte `nptr` para um `unsigned` `__int64`. `_wcstoui64` é uma versão de caractere largo de `_strtoui64`; seu argumento `nptr` é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.  
  
 Ambas as funções param de ler a cadeia de caracteres `nptr` no primeiro caractere que não reconhecem como parte de um número. Isso pode ser o caractere nulo de terminação ou pode ser o primeiro caractere numérico maior ou igual a `base`.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcstoui64`|`_strtoui64`|`_strtoui64`|`_wstrtoui64`|  
|`_tcstoui64_l`|`_strtoui64_l`|`_strtoui64_l`|`_wstrtoui64_l`|  
  
 A configuração da categoria `LC_NUMERIC` da localidade atual determina o reconhecimento do caractere fracionário em `nptr`; para mais informações, consulte [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md). As funções sem o sufixo _| usam a localidade atual; `_strtoui64_l` e `_wcstoui64_l` são idênticas as funções correspondentes sem o sufixo `_l`, exceto por usarem o parâmetro de localidade informado. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Se `endptr` não é `NULL`, um ponteiro para o caractere que parou a verificação é armazenado no local apontado pela `endptr`. Se nenhuma conversão pode ser executada (Nenhum dígito válido foi encontrado ou uma base inválida foi especificada), o valor de `nptr` é armazenado no local apontado pela `endptr`.  
  
 `_strtoui64` espera que `nptr` aponte para uma cadeia de caracteres do seguinte formato:  
  
 [`whitespace`] [{`+` &#124; `–`}] [`0` [{ `x` &#124; `X` }]] [`digits`]  
  
 Um `whitespace` consiste em caracteres de espaço ou tabulação, que são ignorados; `digits` é composto por um ou mais dígitos decimais. O primeiro caractere que não é adequado a esse formato interrompe o exame. Se `base` estiver entre 2 e 36, ele será usado como a base do número. Se `base` é 0, os caracteres inicias da cadeia de caracteres apontada por `nptr` são usados para determinar a base. Se o primeiro caractere é 0 e o segundo caractere não for 'x' ou 'X', a cadeia de caracteres é interpretada como um inteiro octal. Se o primeiro caractere for '0' e o segundo caractere for 'x' ou 'X', a cadeia de caracteres será interpretada como um inteiro hexadecimal. Se o primeiro caractere for de '1' até '9', a cadeia de caracteres será interpretada como um inteiro hexadecimal. As letras 'a' a 'z' (ou 'A' a 'Z') recebem os valores 10 a 35; somente são permitidas letras cujos valores atribuídos são menores que `base`. O primeiro caractere fora do intervalo da base interrompe o exame. Por exemplo, se `base` é 0 e o primeiro caractere verificado é '0', é considerado um inteiro octal e um caractere '8' ou '9' interromperá a verificação.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_strtoui64`|\<stdlib.h>|  
|`_wcstoui64`|\<stdlib.h> ou \<wchar.h>|  
|`_strtoui64_l`|\<stdlib.h>|  
|`_wcstoui64_l`|\<stdlib.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_strtoui64.c  
#include <stdio.h>  
  
unsigned __int64 atoui64(const char *szUnsignedInt) {  
   return _strtoui64(szUnsignedInt, NULL, 10);  
}  
  
int main() {  
   unsigned __int64 u = atoui64("18446744073709551615");  
   printf( "u = %I64u\n", u );  
}  
```  
  
```Output  
u = 18446744073709551615  
```  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md)   
 [Funções de valor de cadeia de caracteres para numérico](../../c-runtime-library/string-to-numeric-value-functions.md)   
 [strtod, _strtod_l, wcstod, _wcstod_l](../../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md)   
 [strtoul, _strtoul_l, wcstoul, _wcstoul_l](../../c-runtime-library/reference/strtoul-strtoul-l-wcstoul-wcstoul-l.md)   
 [atof, _atof_l, _wtof, _wtof_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)
