---
title: _strnicoll, _wcsnicoll, _mbsnicoll, _strnicoll_l, _wcsnicoll_l, _mbsnicoll_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _mbsnicoll_l
- _mbsnicoll
- _wcsnicoll_l
- _strnicoll
- _strnicoll_l
- _wcsnicoll
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
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-string-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- wcshicoll_l
- _ftcsncicoll
- strnicoll_l
- _wcsnicoll
- mbsnicoll_l
- _strnicoll
- mbsnicoll
- _ftcsnicoll
- wcsnicoll
- _tcsnicoll
- _mbsnicoll
- strinicoll
- _tcsncicoll
dev_langs:
- C++
helpviewer_keywords:
- code pages, using for string comparisons
- ftcsncicoll function
- mbsnicoll_l function
- _ftcsnicoll function
- mbsnicoll function
- _tcsnicoll function
- _wcsnicoll_l function
- _mbsnicoll function
- tcsncicoll function
- strnicoll function
- _ftcsncicoll function
- wcsnicoll_l function
- _mbsnicoll_l function
- _tcsncicoll function
- strnicoll_l function
- wcsnicoll function
- _strnicoll_l function
- _wcsnicoll function
- ftcsnicoll function
- strings [C++], comparing by code page
- tcsnicoll function
- _strnicoll function
ms.assetid: abf0c569-725b-428d-9ff2-924f430104b4
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 37ce547f56ce635d7abb2577b1c8278783ba360d
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="strnicoll-wcsnicoll-mbsnicoll-strnicolll-wcsnicolll-mbsnicolll"></a>_strnicoll, _wcsnicoll, _mbsnicoll, _strnicoll_l, _wcsnicoll_l, _mbsnicoll_l
Compara cadeias de caracteres usando informações específicas de localidade.  
  
> [!IMPORTANT]
>  `_mbsnicoll` e `_mbsnicoll_l` não podem ser usados em aplicativos executados no Windows Runtime. Para obter mais informações, consulte [funções de CRT sem suporte em aplicativos de plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _strnicoll(  
   const char *string1,  
   const char *string2,  
   size_t count   
);  
int _wcsnicoll(  
   const wchar_t *string1,  
   const wchar_t *string2 ,  
   size_t count   
);  
int _mbsnicoll(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count   
);  
int _strnicoll_l(  
   const char *string1,  
   const char *string2,  
   size_t count,  
   _locale_t locale  
);  
int _wcsnicoll_l(  
   const wchar_t *string1,  
   const wchar_t *string2 ,  
   size_t count,  
   _locale_t locale  
);  
int _mbsnicoll_l(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `string1, string2`  
 Cadeias de caracteres com encerramento nulo a serem comparadas  
  
 `count`  
 Número de caracteres a ser comparado  
  
 `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas funções retorna um valor que indica a relação de subcadeias de caracteres de `string1` e `string2`, da seguinte maneira.  
  
|Valor retornado|Relação da string1 com a string2|  
|------------------|----------------------------------------|  
|< 0|`string1` é menor que `string2`|  
|0|`string1` é idêntica a `string2`|  
|> 0|`string1` é maior que `string2`|  
  
 Cada uma dessas funções retorna `_NLSCMPERROR`. Para usar `_NLSCMPERROR`, inclua STRING.H ou MBSTRING.H. `_wcsnicoll` pode falhar se `string1` ou `string2` contém códigos de caractere largo fora do domínio da sequência de agrupamento. Quando um erro ocorre, `_wcsnicoll` pode definir `errno` para `EINVAL`. Para verificar se há um erro em uma chamada para `_wcsnicoll`, defina `errno` como 0 e, em seguida, verifique `errno` depois de chamar `_wcsnicoll`**.**  
  
## <a name="remarks"></a>Comentários  
 Cada uma dessas funções executa uma comparação não diferencia maiúsculas e minúsculas dos primeiros `count` caracteres em `string1` e `string2`, de acordo com a página de código. Essas funções devem ser usadas somente quando há uma diferença entre a ordem de conjunto de caracteres e a ordem lexicográfica de caracteres na página de código e essa diferença é de interesse para a comparação de cadeia de caracteres. As versões dessas funções sem o sufixo `_l` usam a localidade atual e a página de código. As versões com o `_l` sufixo são idênticas, exceto que eles usam a localidade passada em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Todas essas funções validam seus parâmetros. Se `string1` ou `string2` for um ponteiro nulo ou se a contagem é maior que `INT_MAX`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções retornarão `_NLSCMPERROR` e `errno` será definido como `EINVAL`**.**  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcsncicoll`|`_strnicoll`|`_mbsnbicoll`|`_wcsnicoll`|  
|`_tcsnicoll`|`_strnicoll`|[_mbsnbicoll](../../c-runtime-library/reference/mbsnbcoll-mbsnbcoll-l-mbsnbicoll-mbsnbicoll-l.md)|`_wcsnicoll`|  
|`_tcsnicoll_l`|`_strnicoll_l`|`_mbsnbicoll_l`|`_wcsnicoll_l`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_strnicoll`, `_strnicoll_l`|\<string.h>|  
|`_wcsnicoll`, `_wcsnicoll_l`|\<wchar.h> or \<string.h>|  
|`_mbsnicoll`, `_mbsnicoll_l`|\<mbstring.h>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Localidade](../../c-runtime-library/locale.md)   
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [_mbsnbcoll, _mbsnbcoll_l, _mbsnbicoll, _mbsnbicoll_l](../../c-runtime-library/reference/mbsnbcoll-mbsnbcoll-l-mbsnbicoll-mbsnbicoll-l.md)   
 [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md)   
 [strcmp, wcscmp, _mbscmp](../../c-runtime-library/reference/strcmp-wcscmp-mbscmp.md)   
 [_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l](../../c-runtime-library/reference/stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)   
 [strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](../../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)   
 [strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](../../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)