---
title: _strncoll, _wcsncoll, _mbsncoll, _strncoll_l, _wcsncoll_l, _mbsncoll_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _strncoll
- _mbsncoll_l
- _wcsncoll
- _wcsncoll_l
- _mbsncoll
- _strncoll_l
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
- mbsncoll_l
- strncoll
- _wcsncoll
- _tcsnccoll
- _ftcsnccoll
- wcsncoll
- _mbsncoll
- wcsncoll_l
- strncoll_l
- _ftcsncoll
- _strncoll
- _tcsncoll
- mbsncoll
dev_langs: C++
helpviewer_keywords:
- _strncoll_l function
- code pages, using for string comparisons
- _strncoll function
- _mbsncoll function
- ftcsncoll function
- strncoll function
- _ftcsncoll function
- strncoll_l function
- wcsncoll function
- mbsncoll function
- _tcsncoll function
- _tcsnccoll function
- wcsncoll_l function
- tcsnccoll function
- mbsncoll_l function
- _mbsncoll_l function
- tcsncoll function
- _wcsncoll function
- strings [C++], comparing by code page
- _ftcsnccoll function
- ftcsnccoll function
- _wcsncoll_l function
ms.assetid: e659a5a4-8afe-4033-8e72-17ffd4bdd8e9
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 51777605e24d9bb3ddf6fa7e6b9ad9c332165881
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="strncoll-wcsncoll-mbsncoll-strncolll-wcsncolll-mbsncolll"></a>_strncoll, _wcsncoll, _mbsncoll, _strncoll_l, _wcsncoll_l, _mbsncoll_l
Compara cadeias de caracteres usando informações específicas de localidade.  
  
> [!IMPORTANT]
>  `_mbsncoll` e `_mbsncoll_l` não podem ser usados em aplicativos executados no Windows Runtime. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _strncoll(  
   const char *string1,  
   const char *string2,  
   size_t count   
);  
int _wcsncoll(  
   const wchar_t *string1,  
   const wchar_t *string2,  
   size_t count   
);  
int _mbsncoll(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count   
);  
int _strncoll_l(  
   const char *string1,  
   const char *string2,  
   size_t count,  
   _locale_t locale  
);  
int _wcsncoll_l(  
   const wchar_t *string1,  
   const wchar_t *string2,  
   size_t count,  
   _locale_t locale  
);  
int _mbsncoll_l(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `string1, string2`  
 Cadeias de caracteres com terminação nula.  
  
 `count`  
 O número de caracteres a ser comparado.  
  
 `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas funções retorna um valor que indica a relação de subcadeias de caracteres de `string1` e `string2`, da seguinte maneira.  
  
|Valor retornado|Relação da string1 com a string2|  
|------------------|----------------------------------------|  
|< 0|`string1` é menor que `string2`.|  
|0|`string1` é idêntico a `string2`.|  
|> 0|`string1` é maior que `string2`.|  
  
 Cada uma dessas funções retorna `_NLSCMPERROR`. Para usar `_NLSCMPERROR`, inclua STRING.h ou MBSTRING.h. `_wcsncoll` pode falhar se `string1` ou `string2` contiverem códigos de caractere largo fora do domínio da sequência de agrupamento. Quando um erro ocorre, `_wcsncoll` pode definir `errno` para `EINVAL`. Para verificar se há um erro em uma chamada para `_wcsncoll`, defina `errno` como 0 e, em seguida, verifique `errno` depois de chamar `_wcsncoll`.  
  
## <a name="remarks"></a>Comentários  
 Cada uma dessas funções executa uma comparação que diferencia maiúsculas e minúsculas dos primeiros `count` caracteres em `string1` e `string2`, de acordo com a página de código atualmente em uso. Use essas funções somente quando há uma diferença entre a ordem do conjunto de caracteres e a ordem lexicográfica dos caracteres na página de código atual e essa diferença é de interesse para a comparação de cadeia de caracteres. A ordem do conjunto de caracteres é dependente de localidade. As versões dessas funções que não têm o `_l` sufixo usam a localidade atual, mas as versões que têm o `_l` sufixo usam a localidade que é passada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Todas essas funções validam seus parâmetros. Se `string1` ou `string2` for um ponteiro nulo ou `count` ser maior que `INT_MAX`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão `_NLSCMPERROR` e definirão `errno` para `EINVAL`.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcsnccoll`|`_strncoll`|`_mbsncoll`|`_wcsncoll`|  
|`_tcsncoll`|`_strncoll`|[_mbsnbcoll](../../c-runtime-library/reference/mbsnbcoll-mbsnbcoll-l-mbsnbicoll-mbsnbicoll-l.md)|`_wcsncoll`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_strncoll`, `_strncoll_l`|\<string.h>|  
|`_wcsncoll`, `_wcsncoll_l`|\<wchar.h> or \<string.h>|  
|`_mbsncoll`, `_mbsncoll_l`|\<mbstring.h>|  
  
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