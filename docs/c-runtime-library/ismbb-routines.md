---
title: "Rotinas _ismbb | Microsoft Docs"
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
  - "msvcr110.dll"
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_ismbb"
  - "ismbb"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Rotinas _ismbb"
  - "rotinas ismbb"
ms.assetid: d63c232e-3fe4-4844-aafd-2133846ece4b
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Rotinas _ismbb
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa o valor inteiro de determinado `c` para uma determinada condição, usando a localidade atual ou uma categoria de estado de conversão LC\_CTYPE especificada.  
  
|||  
|-|-|  
|[\_ismbbalnum, \_ismbbalnum\_l](../c-runtime-library/reference/ismbbalnum-ismbbalnum-l.md)|[\_ismbbkprint, \_ismbbkprint\_l](../c-runtime-library/reference/ismbbkprint-ismbbkprint-l.md)|  
|[\_ismbbalpha, \_ismbbalpha\_l](http://msdn.microsoft.com/pt-br/8e54cb92-fc2b-41f5-8ab4-b22ac8aa9ad0)|[\_ismbbkpunct, \_ismbbkpunct\_l](../Topic/_ismbbkpunct,%20_ismbbkpunct_l.md)|  
|[\_ismbbblank, \_ismbbblank\_l](../c-runtime-library/reference/ismbbblank-ismbbblank-l.md)|[\_ismbblead, \_ismbblead\_l](../c-runtime-library/reference/ismbblead-ismbblead-l.md)|  
|[\_ismbbgraph, \_ismbbgraph\_l](../c-runtime-library/reference/ismbbgraph-ismbbgraph-l.md)|[\_ismbbprint, \_ismbbprint\_l](../c-runtime-library/reference/ismbbprint-ismbbprint-l.md)|  
|[\_ismbbkalnum, \_ismbbkalnum\_l](../c-runtime-library/reference/ismbbkalnum-ismbbkalnum-l.md)|[\_ismbbpunct, \_ismbbpunct\_l](../c-runtime-library/reference/ismbbpunct-ismbbpunct-l.md)|  
|[\_ismbbkana, \_ismbbkana\_l](../c-runtime-library/reference/ismbbkana-ismbbkana-l.md)|[\_ismbbtrail, \_ismbbtrail\_l](../c-runtime-library/reference/ismbbtrail-ismbbtrail-l.md)|  
  
## Comentários  
 Cada rotina no `_ismbb` família testa o valor inteiro de determinado `c` para uma determinada condição. O resultado do teste depende da página de código multibyte que está em vigor. Por padrão, a página de código multibyte é definida para a página de código ANSI obtida do sistema operacional na inicialização do programa. Você pode usar [getmbcp](../c-runtime-library/reference/getmbcp.md) para consultar a página de código multibyte que está em uso, ou [setmbcp](../c-runtime-library/reference/setmbcp.md) para alterá\-lo.  
  
 O valor de saída é afetado pela configuração do `LC_CTYPE` categoria configurações da localidade; para obter mais informações, consulte [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md). As versões dessas funções que não têm o **\_l** usam a localidade atual do sufixo para esse comportamento depende da localidade; as versões que têm o **\_l** sufixo são idênticas, exceto que em vez disso, eles usam o parâmetro de localidade que é passado.  
  
 As rotinas no `_ismbb` família testar os inteiros `c` da seguinte maneira.  
  
|Rotina|Condição de teste de byte|  
|------------|-------------------------------|  
|[ismbbalnum](../c-runtime-library/reference/ismbbalnum-ismbbalnum-l.md)|`isalnum` &#124;&#124; `_ismbbkalnum`.|  
|[ismbbalpha](http://msdn.microsoft.com/pt-br/8e54cb92-fc2b-41f5-8ab4-b22ac8aa9ad0)|`isalpha` &#124;&#124; `_ismbbkalnum`.|  
|[\_ismbbblank](../c-runtime-library/reference/ismbbblank-ismbbblank-l.md)|`isblank`|  
|[ismbbgraph](../c-runtime-library/reference/ismbbgraph-ismbbgraph-l.md)|Mesmo que `_ismbbprint`, mas `_ismbbgraph` não inclui o caractere de espaço \(0x20\).|  
|[ismbbkalnum](../c-runtime-library/reference/ismbbkalnum-ismbbkalnum-l.md)|Símbolo de texto não\-ASCII que não seja de pontuação. Por exemplo, na página de código 932 somente `_ismbbkalnum` testes para katakana alfanumérico.|  
|[ismbbkana](../c-runtime-library/reference/ismbbkana-ismbbkana-l.md)|Katakana \(0xA1 – 0xDF\). Página de código 932 específicos.|  
|[ismbbkprint](../c-runtime-library/reference/ismbbkprint-ismbbkprint-l.md)|Texto não\-ASCII ou símbolo de pontuação não\-ASCII. Por exemplo, na página de código 932 somente `_ismbbkprint` testes para katakana alfanumérico ou pontuação katakana \(intervalo: 0xA1 – 0xDF\).|  
|[ismbbkpunct](../Topic/_ismbbkpunct,%20_ismbbkpunct_l.md)|Pontuação de não\-ASCII. Por exemplo, na página de código 932 somente `_ismbbkpunct` testes para pontuação katakana.|  
|[ismbblead](../c-runtime-library/reference/ismbblead-ismbblead-l.md)|Primeiro byte do caractere multibyte. Por exemplo, no código de página 932 intervalos válidos, somente são 0x81 – 0x9F, 0xE0 – 0xFC.|  
|[ismbbprint](../c-runtime-library/reference/ismbbprint-ismbbprint-l.md)|`isprint` &#124;&#124; `_ismbbkprint`.**ismbbprint** inclui o caractere de espaço \(0x20\).|  
|[ismbbpunct](../c-runtime-library/reference/ismbbpunct-ismbbpunct-l.md)|`ispunct` &#124;&#124; `_ismbbkpunct`.|  
|[ismbbtrail](../c-runtime-library/reference/ismbbtrail-ismbbtrail-l.md)|Segundo byte de caracteres multibyte. Por exemplo, no código de página 932 intervalos válidos, somente são 0x40 – 0x7E, 0x80 – 0xEC.|  
  
 A tabela a seguir mostra os valores ORed que compõem as condições de teste para essas rotinas. As constantes de manifesto `_BLANK`, `_DIGIT`, `_LOWER`, `_PUNCT`, e `_UPPER` são definidos em CType.  
  
|Rotina|BLANK|\_DIGIT|INFERIOR|\_PUNCT|SUPERIOR|Não\-<br /><br /> ASCII<br /><br /> texto|Não\-<br /><br /> ASCII<br /><br /> pontuação|  
|------------|-----------|-------------|--------------|-------------|--------------|-------------------------------|-----------------------------------|  
|`_ismbbalnum`|—|x|x|—|x|x|—|  
|`_ismbbalpha`|—|—|x|—|x|x|—|  
|`_ismbbblank`|x|—|—|—|—|—|—|  
|`_ismbbgraph`|—|x|x|x|x|x|x|  
|`_ismbbkalnum`|—|—|—|—|—|x|—|  
|`_ismbbkprint`|—|—|—|—|—|x|x|  
|`_ismbbkpunct`|—|—|—|—|—|—|x|  
|`_ismbbprint`|x|x|x|x|x|x|x|  
|`_ismbbpunct`|—|—|—|x|—|—|x|  
  
 O `_ismbb` rotinas são implementadas como funções e macros. Para obter mais informações sobre como escolher qualquer implementação, consulte [Recomendações para escolher entre funções e macros](../c-runtime-library/recommendations-for-choosing-between-functions-and-macros.md).  
  
## Equivalente ao .NET framework  
 Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx).  
  
## Consulte também  
 [Classificação de byte](../c-runtime-library/byte-classification.md)   
 [Rotinas is, isw](../c-runtime-library/is-isw-routines.md)   
 [\_mbbtombc, \_mbbtombc\_l](../c-runtime-library/reference/mbbtombc-mbbtombc-l.md)   
 [\_mbctombb, \_mbctombb\_l](../c-runtime-library/reference/mbctombb-mbctombb-l.md)