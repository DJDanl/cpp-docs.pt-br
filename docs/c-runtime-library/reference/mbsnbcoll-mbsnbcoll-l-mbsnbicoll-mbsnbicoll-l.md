---
title: _mbsnbcoll, _mbsnbcoll_l, _mbsnbicoll, _mbsnbicoll_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _mbsnbicoll_l
- _mbsnbcoll_l
- _mbsnbcoll
- _mbsnbicoll
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
apitype: DLLExport
f1_keywords:
- mbsnbicoll
- mbsnbcoll
- mbsnbicoll_l
- _mbsnbcoll
- _mbsnbicoll
- _ftcsnicoll
- _ftcsncoll
- mbsnbcoll_l
dev_langs:
- C++
helpviewer_keywords:
- _mbsnbcoll_l function
- mbsnbcoll_l function
- _mbsnbcoll function
- _tcsnicoll function
- mbsnbcoll function
- mbsnbicoll_l function
- mbsnbicoll function
- _tcsncoll function
- _mbsnbicoll function
- _mbsnbicoll_l function
- tcsncoll function
- tcsnicoll function
ms.assetid: d139ed63-ccba-4458-baa2-61cbcef03e94
caps.latest.revision: 21
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
ms.openlocfilehash: e1237602841dad1772b4a0d7330cad308b7d7789
ms.lasthandoff: 02/25/2017

---
# <a name="mbsnbcoll-mbsnbcolll-mbsnbicoll-mbsnbicolll"></a>_mbsnbcoll, _mbsnbcoll_l, _mbsnbicoll, _mbsnbicoll_l
Compara `n` bytes de duas cadeias de caracteres multibyte usando informações de página de código multibyte.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _mbsnbcoll(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count   
);  
int _mbsnbcoll_l(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count,  
   _locale_t locale  
);  
int _mbsnbicoll(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count   
);  
int _mbsnbicoll_l(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `string1, string2`  
 Cadeias de caracteres a serem comparadas.  
  
 `count`  
 Número de bytes a serem comparados.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor retornado indica a relação das subcadeias de caracteres de `string1` e `string2`.  
  
|Valor retornado|Descrição|  
|------------------|-----------------|  
|< 0|Subcadeia de caracteres `string1` menor do que a subcadeia de caracteres `string2`.|  
|0|Subcadeia de caracteres `string1` idêntica à subcadeia de caracteres `string2`.|  
|> 0|Subcadeia de caracteres `string1` maior que a subcadeia de caracteres `string2`.|  
  
 Se `string1` ou `string2` for `NULL` ou `count` for maior que `INT_MAX`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão `_NLSCMPERROR` e definirão `errno` para `EINVAL`. Para usar `_NLSCMPERROR`, inclua String.h ou Mbstring.h.  
  
## <a name="remarks"></a>Comentários  
 Cada uma dessas funções agrupa, no máximo, os primeiros `count` bytes em `string1` e `string2` retorna um valor indicando a relação entre as subcadeias de caracteres resultantes de `string1` e `string2`. Se o byte final na subcadeia de caracteres de `string1` ou `string2` for um byte inicial, ele não será incluído na comparação, essas funções comparam apenas caracteres completos nas subcadeias de caracteres. `_mbsnbicoll` é uma versão que não diferencia maiúsculas e minúsculas de `_mbsnbcoll`. Como `_mbsnbcmp` e `_mbsnbicmp`, `_mbsnbcoll` e `_mbsnbicoll` agrupam as duas cadeias de caracteres multibyte de acordo com a ordem lexicográfica especificada pela [página de código](../../c-runtime-library/code-pages.md) multibyte em uso no momento.  
  
 Para algumas páginas de código e conjuntos de caracteres correspondente, a ordem dos caracteres no conjunto de caracteres pode diferir da ordem de caracteres lexicográfica. Na localidade “C”, esse não é o caso: a ordem dos caracteres no conjunto de caracteres ASCII é a mesma que a ordem lexicográfica dos caracteres. No entanto, em algumas páginas de código europeias, por exemplo, o caractere “a” (valor 0x61) precede o caractere “ä” (valor 0xE4) no conjunto de caracteres, mas o caractere “ä” precede a caractere “a” lexicograficamente. Para realizar uma comparação lexicográfica de cadeias de caracteres por bytes em uma instância, use `_mbsnbcoll` em vez de `_mbsnbcmp`. Para verificar somente a igualdade de cadeia de caracteres, use `_mbsnbcmp`.  
  
 Como as funções `coll` agrupam as cadeias de caracteres lexicograficamente para comparação, enquanto as funções `cmp` simplesmente testam a igualdade da cadeia de caracteres, as funções `coll` são muito mais lentas do que as versões `cmp` correspondentes. Portanto, as funções `coll` devem ser usadas somente quando há uma diferença entre a ordem de conjunto de caracteres e a ordem lexicográfica de caracteres na página de código atual e essa diferença é de interesse para a comparação.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` da localidade; consulte [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo `_l` usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo `_l` são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tcsncoll`|[_strncoll](../../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|`_mbsnbcoll`|[_wcsncoll](../../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|  
|`_tcsncoll_l`|[_strncoll, _wcsncoll, _mbsncoll, _strncoll_l, _wcsncoll_l, _mbsncoll_l](../../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|`_mbsnbcoll_l`|[_wcsncoll_l](../../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|  
|`_tcsnicoll`|[_strnicoll](../../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|`_mbsnbicoll`|[_wcsnicoll](../../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|  
|`_tcsnicoll_l`|[_strnicoll_l](../../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|`_mbsnbicoll_l`|[_wcsnicoll_l](../../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_mbsnbcoll`|\<mbstring.h>|  
|`_mbsnbcoll_l`|\<mbstring.h>|  
|`_mbsnbicoll`|\<mbstring.h>|  
|`_mbsnbicoll_l`|\<mbstring.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [_mbsnbcat, _mbsnbcat_l](../../c-runtime-library/reference/mbsnbcat-mbsnbcat-l.md)   
 [_mbsnbcmp, _mbsnbcmp_l](../../c-runtime-library/reference/mbsnbcmp-mbsnbcmp-l.md)   
 [_mbsnbicmp, _mbsnbicmp_l](../../c-runtime-library/reference/mbsnbicmp-mbsnbicmp-l.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](../../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)
