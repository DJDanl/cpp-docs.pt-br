---
title: "Fun&#231;&#245;es strcoll | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apilocation: 
  - "msvcr120.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr90.dll"
  - "msvcr80.dll"
  - "msvcr100.dll"
  - "msvcr110.dll"
apitype: "DLLExport"
f1_keywords: 
  - "strcoll"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "páginas de código, usando para comparações de cadeias de caracteres"
  - "Funções strcoll"
  - "comparação de cadeias de caracteres [C++], específico da cultura"
  - "cadeias de caracteres [C++], comparando por página de código"
ms.assetid: c09eeff3-8aba-4cfb-a524-752436d85573
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fun&#231;&#245;es strcoll
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada uma das funções de `strcoll` e de `wcscoll` compara duas cadeias de caracteres de acordo com a configuração da categoria de `LC_COLLATE` de página de código da localidade em uso.  Cada uma das funções de `_mbscoll` compara duas cadeias de caracteres de acordo com a página de código de multibyte atualmente em uso.  Use as funções de `coll` para comparações de cadeias de caracteres quando há uma diferença entre a ordem do conjunto de caracteres e ordem lexicographic de caractere na página de código atual e essa diferença é interessante para comparação.  Use as funções correspondentes de `cmp` para testar somente para a igualdade de cadeia de caracteres.  
  
### funções de strcoll  
  
|SBCS|Unicode|MBCS|Descrição|  
|----------|-------------|----------|---------------|  
|[strcoll](../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md)|[wcscoll](../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md)|[\_mbscoll](../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md)|Use duas cadeias de caracteres|  
|[\_stricoll](../Topic/_stricoll,%20_wcsicoll,%20_mbsicoll,%20_stricoll_l,%20_wcsicoll_l,%20_mbsicoll_l.md)|[\_wcsicoll](../Topic/_stricoll,%20_wcsicoll,%20_mbsicoll,%20_stricoll_l,%20_wcsicoll_l,%20_mbsicoll_l.md)|[\_mbsicoll](../Topic/_stricoll,%20_wcsicoll,%20_mbsicoll,%20_stricoll_l,%20_wcsicoll_l,%20_mbsicoll_l.md)|Use duas cadeias de caracteres \(sem diferenciação de maiúsculas e minúsculas\)|  
|[\_strncoll](../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|[\_wcsncoll](../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|[\_mbsncoll](../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|Ordene primeiros caracteres de `count` de duas cadeias de caracteres|  
|[\_strnicoll](../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|[\_wcsnicoll](../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|[\_mbsnicoll](../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|Ordene primeiros caracteres de `count` de duas cadeias de caracteres \(sem diferenciação de maiúsculas e minúsculas\)|  
  
## Comentários  
 As versões \(SBCS\) de caractere de byte único dessas funções \(`strcoll`, `stricoll`, `_strncoll`, e `_strnicoll`\) se comparam `string1` e `string2` de acordo com a configuração da categoria de `LC_COLLATE` de localidade atual.  Essas funções são diferentes das funções correspondentes de `strcmp` que as funções de `strcoll` usam informações de página de código de localidade que fornece sequências de agrupamento.  Para comparações de cadeias de caracteres em localidades em que a ordem do conjunto de caracteres e ordem lexicographic de caracteres forem diferentes, as funções de `strcoll` devem ser usadas em vez das funções correspondentes de `strcmp` .  Para obter mais informações sobre `LC_COLLATE`, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  
  
 Para algumas páginas de código e conjuntos de caracteres correspondentes, a ordem de caracteres no conjunto de caracteres pode diferir da ordem lexicographic de caractere.  Na localidade de C, este é não o casos: a ordem dos caracteres no conjunto de caracteres ASCII é a mesma que a ordem lexicográfica de caracteres.  No entanto, em determinadas páginas de código europeias, por exemplo, o caractere "a" \(valor 0x61\) precede o caractere "ä" \(valor 0xE4\) no conjunto de caracteres, mas o caractere "ä" precede o caractere "a" lexicograficamente.  Para executar uma comparação lexicographic nessa instância, use `strcoll` em vez de `strcmp`.  Como alternativa, você pode usar `strxfrm` em cadeias de caracteres original, o usa `strcmp` em cadeias de caracteres resultante.  
  
 `strcoll`, `stricoll`, `_strncoll`, e de `_strnicoll` cadeias de caracteres de multibyte\- caractere de identificador automaticamente de acordo com a página de código da localidade em uso, como faz suas contrapartes ampla de caractere Unicode \(\).  As versões \(MBCS\) de multibyte\- caractere dessas funções, porém, as regras de cadeias de caracteres em uma base de caracteres de acordo com a página de código de multibyte atualmente em uso.  
  
 Como as funções de `coll` suportam cadeias de caracteres graficamente léxicas para comparação e as funções de `cmp` simplesmente testam a igualdade da cadeia de caracteres, as funções de `coll` são muito mais lentas que as versões correspondentes de `cmp`.  Em virtude disso, as funções de `coll` devem ser usadas somente quando há uma diferença entre a ordem do conjunto de caracteres e ordem lexicographic de caractere na página de código atual e essa diferença é interessante para a comparação de cadeia de caracteres.  
  
## Consulte também  
 [Localidade](../c-runtime-library/locale.md)   
 [Manipulação da cadeia de caracteres](../c-runtime-library/string-manipulation-crt.md)   
 [localeconv](../c-runtime-library/reference/localeconv.md)   
 [\_mbsnbcoll, \_mbsnbcoll\_l, \_mbsnbicoll, \_mbsnbicoll\_l](../c-runtime-library/reference/mbsnbcoll-mbsnbcoll-l-mbsnbicoll-mbsnbicoll-l.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [strcmp, wcscmp, \_mbscmp](../Topic/strcmp,%20wcscmp,%20_mbscmp.md)   
 [strncmp, wcsncmp, \_mbsncmp, \_mbsncmp\_l](../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [\_strnicmp, \_wcsnicmp, \_mbsnicmp, \_strnicmp\_l, \_wcsnicmp\_l, \_mbsnicmp\_l](../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)   
 [strxfrm, wcsxfrm, \_strxfrm\_l, \_wcsxfrm\_l](../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)