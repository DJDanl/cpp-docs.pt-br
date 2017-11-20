---
title: "Funções do strcoll | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apilocation:
- msvcr120.dll
- msvcr110_clr0400.dll
- msvcr90.dll
- msvcr80.dll
- msvcr100.dll
- msvcr110.dll
apitype: DLLExport
f1_keywords: strcoll
dev_langs: C++
helpviewer_keywords:
- code pages, using for string comparisons
- string comparison [C++], culture-specific
- strcoll functions
- strings [C++], comparing by code page
ms.assetid: c09eeff3-8aba-4cfb-a524-752436d85573
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 224c30dfbc79ab91e60f7f55f4835d3f627c454c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="strcoll-functions"></a>Funções strcoll
Cada uma das funções `strcoll` e `wcscoll` compara duas cadeias de caracteres de acordo com a configuração da categoria `LC_COLLATE` da página de código de localidade em uso no momento. Cada uma das funções `_mbscoll` compara duas cadeias de caracteres de acordo com a página de código multibyte em uso no momento. Use as funções `coll` para comparações de cadeia de caracteres quando há uma diferença entre a ordem de conjunto de caracteres e a ordem lexicográfica de caracteres na página de código atual e essa diferença é de interesse para a comparação. Use as funções `cmp` correspondentes para testar apenas para igualdade de cadeia de caracteres.  
  
### <a name="strcoll-functions"></a>Funções strcoll  
  
|SBCS|Unicode|MBCS|Descrição|  
|----------|-------------|----------|-----------------|  
|[strcoll](../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md)|[wcscoll](../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md)|[_mbscoll](../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md)|Agrupar duas cadeias de caracteres|  
|[_stricoll](../c-runtime-library/reference/stricoll-wcsicoll-mbsicoll-stricoll-l-wcsicoll-l-mbsicoll-l.md)|[_wcsicoll](../c-runtime-library/reference/stricoll-wcsicoll-mbsicoll-stricoll-l-wcsicoll-l-mbsicoll-l.md)|[_mbsicoll](../c-runtime-library/reference/stricoll-wcsicoll-mbsicoll-stricoll-l-wcsicoll-l-mbsicoll-l.md)|Agrupar duas cadeias de caracteres (não diferencia maiúsculas de minúsculas)|  
|[_strncoll](../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|[_wcsncoll](../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|[_mbsncoll](../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|Agrupar primeiro caracteres `count` de duas cadeias de caracteres|  
|[_strnicoll](../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|[_wcsnicoll](../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|[_mbsnicoll](../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|Agrupar primeiro caracteres `count` de duas cadeias de caracteres (não diferencia maiúsculas de minúsculas)|  
  
## <a name="remarks"></a>Comentários  
 As versões de caracteres de um byte (SBCS) dessas funções (`strcoll`, `stricoll`, `_strncoll` e `_strnicoll`) comparam `string1` e `string2` de acordo com a configuração da categoria `LC_COLLATE` da localidade atual. Essas funções diferem das funções `strcmp` correspondentes onde as funções `strcoll` usam informações de página de código de localidade que fornecem sequências de agrupamento. Para comparações de cadeia de caracteres em localidades em que a ordem de conjunto de caracteres e a ordem lexicográfica de caracteres diferem, as funções `strcoll` devem ser usadas em vez das funções `strcmp` correspondentes. Para obter mais informações sobre `LC_COLLATE`, consulte [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md).  
  
 Para algumas páginas de código e conjuntos de caracteres correspondentes, a ordem dos caracteres no conjunto de caracteres pode diferir da ordem lexicográfica de caracteres. Na localidade “C”, esse não é o caso: a ordem dos caracteres no conjunto de caracteres ASCII é a mesma que a ordem lexicográfica dos caracteres. No entanto, em algumas páginas de código europeias, por exemplo, o caractere “a” (valor 0x61) precede o caractere “ä” (valor 0xE4) no conjunto de caracteres, mas o caractere “ä” precede a caractere “a” lexicograficamente. Para realizar uma comparação lexicográfica nessa instância, use `strcoll` em vez de `strcmp`. Como alternativa, você pode usar `strxfrm` nas cadeias de caracteres originais e, então, usar `strcmp` nas cadeias de caracteres resultantes.  
  
 `strcoll`, `stricoll`, `_strncoll` e `_strnicoll` tratam automaticamente das cadeias de caracteres multibyte de acordo com a página de código de localidade atualmente em uso, assim como suas contrapartes de caractere largo (Unicode). As versões de caracteres multibyte (MBCS) dessas funções, no entanto, agrupam de cadeias de caracteres em cada caractere, de acordo com a página de código multibyte em uso no momento.  
  
 Como as funções `coll` agrupam as cadeias de caracteres lexicograficamente para comparação, enquanto as funções `cmp` simplesmente testam a igualdade da cadeia de caracteres, as funções `coll` são muito mais lentas do que as versões `cmp` correspondentes. Portanto, as funções `coll` devem ser usadas somente quando há uma diferença entre a ordem de conjunto de caracteres e a ordem lexicográfica de caracteres na página de código atual e essa diferença é de interesse para a comparação da cadeia de caracteres.  
  
## <a name="see-also"></a>Consulte também  
 [Localidade](../c-runtime-library/locale.md)   
 [Manipulação de cadeias de caracteres](../c-runtime-library/string-manipulation-crt.md)   
 [localeconv](../c-runtime-library/reference/localeconv.md)   
 [_mbsnbcoll, _mbsnbcoll_l, _mbsnbicoll, _mbsnbicoll_l](../c-runtime-library/reference/mbsnbcoll-mbsnbcoll-l-mbsnbicoll-mbsnbicoll-l.md)   
 [setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)   
 [strcmp, wcscmp, _mbscmp](../c-runtime-library/reference/strcmp-wcscmp-mbscmp.md)   
 [strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)   
 [strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)