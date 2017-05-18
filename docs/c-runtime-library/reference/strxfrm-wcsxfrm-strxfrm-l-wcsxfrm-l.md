---
title: strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- strxfrm
- _wcsxfrm_l
- _strxfrm_l
- wcsxfrm
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
- api-ms-win-crt-string-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- strxfrm
- _tcsxfrm
- wcsxfrm
dev_langs:
- C++
helpviewer_keywords:
- strxfrm_l function
- _tcsxfrm function
- _strxfrm_l function
- strxfrm function
- wcsxfrm_l function
- wcsxfrm function
- string comparison [C++], transforming strings
- tcsxfrm function
- strings [C++], comparing locale
- _wcsxfrm_l function
ms.assetid: 6ba8e1f6-4484-49aa-83b8-bc2373187d9e
caps.latest.revision: 18
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
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: b05ec00ae2144670844cd54de0900aa1412128ff
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="strxfrm-wcsxfrm-strxfrml-wcsxfrml"></a>strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l
Transforme uma cadeia de caracteres com base nas informações específicas à localidade.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
size_t strxfrm(  
   char *strDest,  
   const char *strSource,  
   size_t count   
);  
size_t wcsxfrm(  
   wchar_t *strDest,  
   const wchar_t *strSource,  
   size_t count   
);  
size_t _strxfrm_l(  
   char *strDest,  
   const char *strSource,  
   size_t count,  
   _locale_t locale  
);  
size_t wcsxfrm_l(  
   wchar_t *strDest,  
   const wchar_t *strSource,  
   size_t count,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `strDest`  
 Cadeia de caracteres de destino.  
  
 `strSource`  
 Cadeia de caracteres de origem.  
  
 `count`  
 Número máximo de caracteres para colocar em `strDest`.  
  
 `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o tamanho da cadeia de caracteres transformada, sem contar o caractere nulo de terminação. Se o valor retornado for maior ou igual a `count`, o conteúdo de `strDest` será imprevisível. Em um erro, cada função define `errno` e retorna `INT_MAX`. Para um caractere inválido, `errno` é definido como `EILSEQ`.  
  
## <a name="remarks"></a>Comentários  
 A função `strxfrm` transforma a cadeia de caracteres apontada por `strSource` em um novo formato agrupado que é armazenado em `strDest`. Um número que não excede `count` caracteres, incluindo o caractere nulo, é transformado e colocado na cadeia de caracteres resultante. A transformação é feita usando a configuração de categoria `LC_COLLATE` da localidade. Para obter mais informações sobre `LC_COLLATE`, consulte [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md). `strxfrm` usa a localidade atual de seu comportamento dependente da localidade; `_strxfrm_l` é idêntico, exceto pelo fato de que ele usa a localidade passada, em vez da localidade atual. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Após a transformação, uma chamada a `strcmp` com as duas cadeias de caracteres transformadas produz resultados idênticos aos de uma chamada a `strcoll` aplicada às duas cadeias de caracteres originais. Assim como ocorre com `strcoll` e `stricoll`, `strxfrm` manipula automaticamente as cadeias de caracteres multibyte, conforme apropriado.  
  
 `wcsxfrm` é uma versão de caractere largo de `strxfrm`; os argumentos de cadeia de caracteres de `wcsxfrm` são ponteiros de caracteres largos. Para `wcsxfrm`, após a transformação de cadeia de caracteres, uma chamada a `wcscmp` com as duas cadeias de caracteres transformadas produz resultados idênticos aos de uma chamada a `wcscoll` aplicada às duas cadeias de caracteres originais. Caso contrário, `wcsxfrm` e `strxfrm` se comportam de forma idêntica. `wcsxfrm` usa a localidade atual de seu comportamento dependente da localidade; `_wcsxfrm_l` usa a localidade passada, em vez da localidade atual.  
  
 Essas funções validam seus parâmetros. Se `strSource` for um ponteiro nulo, se `strDest` for um ponteiro NULL (a menos que a contagem seja zero) ou se `count` for maior que `INT_MAX`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definirão `errno` como `EINVAL` e retornarão `INT_MAX`.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcsxfrm`|`strxfrm`|`strxfrm`|`wcsxfrm`|  
|`_tcsxfrm_l`|`_strxfrm_l`|`_strxfrm_l`|`_wcsxfrm_l`|  
  
 Na localidade “C”, a ordem dos caracteres no conjunto de caracteres (conjunto de caracteres ASCII) é a mesma que a ordem lexicográfica dos caracteres. No entanto, em outras localidades, a ordem de caracteres no conjunto de caracteres pode ser diferente da ordem lexicográfica de caracteres. Por exemplo, em algumas localidades europeias, o caractere “a” (valor 0x61) precede o caractere “&\#x00E4;” (valor 0xE4) no conjunto de caracteres, mas o caractere “ä” precede a caractere “a” lexicograficamente.  
  
 Em localidades nas quais o conjunto de caracteres e a ordem lexicográfica dos caracteres diferem, use `strxfrm` nas cadeias de caracteres originais e, em seguida, `strcmp` nas cadeias de caracteres resultantes para produzir uma comparação lexicográfica de cadeia de caracteres de acordo com a configuração de categoria `LC_COLLATE` da localidade atual. Portanto, para comparar duas cadeias de caracteres lexicograficamente na localidade acima, use `strxfrm` nas cadeias de caracteres originais e, em seguida, `strcmp` nas cadeias de caracteres resultantes. Como alternativa, é possível usar `strcoll` em vez de `strcmp` nas cadeias de caracteres originais.  
  
 `strxfrm` é basicamente um wrapper em torno de [LCMapString](http://msdn.microsoft.com/library/windows/desktop/dd318700) com `LCMAP_SORTKEY`.  
  
 O valor da seguinte expressão é o tamanho da matriz necessário para conter a transformação `strxfrm` da cadeia de caracteres de origem:  
  
```  
1 + strxfrm( NULL, string, 0 )  
```  
  
 Somente na localidade “C”, `strxfrm` é equivalente ao seguinte:  
  
```  
strncpy( _string1, _string2, _count );  
return( strlen( _string1 ) );  
```  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`strxfrm`|\<string.h>|  
|`wcsxfrm`|\<string.h> ou \<wchar.h>|  
|`_strxfrm_l`|\<string.h>|  
|`_wcsxfrm_l`|\<string.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [strcmp, wcscmp, _mbscmp](../../c-runtime-library/reference/strcmp-wcscmp-mbscmp.md)   
 [strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)
