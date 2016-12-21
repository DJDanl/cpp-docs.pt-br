---
title: "Rotinas _ismbc | Microsoft Docs"
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
  - "msvcr110_clr0400.dll"
  - "msvcr100.dll"
  - "msvcrt.dll"
  - "msvcr90.dll"
  - "msvcr120.dll"
  - "msvcr80.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_ismbc"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Rotinas _ismbc"
  - "rotinas ismbc"
ms.assetid: b8995391-7857-4ac3-9a1e-de946eb4464d
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Rotinas _ismbc
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada rotina de **\_ismbc** testa um determinado caractere `c` multibyte para uma condição específica.  
  
|||  
|-|-|  
|[\_ismbcalnum, \_ismbcalnum\_l, \_ismbcalpha, \_ismbcalpha\_l, \_ismbcdigit, \_ismbcdigit\_l](../Topic/_ismbcalnum,%20_ismbcalnum_l,%20_ismbcalpha,%20_ismbcalpha_l,%20_ismbcdigit,%20_ismbcdigit_l.md)|[\_ismbcl0, \_ismbcl0\_l, \_ismbcl1, \_ismbcl1\_l, \_ismbcl2, \_ismbcl2\_l](../c-runtime-library/reference/ismbcl0-ismbcl0-l-ismbcl1-ismbcl1-l-ismbcl2-ismbcl2-l.md)|  
|[\_ismbcgraph, \_ismbcgraph\_l, \_ismbcprint, \_ismbcprint\_l, \_ismbcpunct, \_ismbcpunct\_l, \_ismbcblank, \_ismbcblank\_l, \_ismbcspace, \_ismbcspace\_l](../c-runtime-library/reference/ismbcgraph-functions.md)|[\_ismbclegal, \_ismbclegal\_l, \_ismbcsymbol, \_ismbcsymbol\_l](../c-runtime-library/reference/ismbclegal-ismbclegal-l-ismbcsymbol-ismbcsymbol-l.md)|  
|[\_ismbchira, \_ismbchira\_l, \_ismbckata, \_ismbckata\_l](../c-runtime-library/reference/ismbchira-ismbchira-l-ismbckata-ismbckata-l.md)|[\_ismbclower, \_ismbclower\_l, \_ismbcupper, \_ismbcupper\_l](../c-runtime-library/reference/ismbclower-ismbclower-l-ismbcupper-ismbcupper-l.md)|  
  
## Comentários  
 O resultado do teste de cada rotina **\_ismbc** depende da página de código multibyte que está em vigor.  As páginas de código de multibyte têm caracteres alfabéticos de byte único.  Por padrão, a página de código de multibyte é definida como página de código ANSI padrão do sistema, obtida do sistema operacional na inicialização do programa.  Você pode consultar ou alterar a página de código multibyte em uso com [\_getmbcp](../c-runtime-library/reference/getmbcp.md) ou [\_setmbcp](../c-runtime-library/reference/setmbcp.md), respectivamente.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` da localidade. Para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  As versões dessas funções sem o sufixo **\_l** usam a localidade atual para esse comportamento dependente da localidade; as versões com o sufixo **\_l** são idênticas, exceto que elas usam o parâmetro de localidade informado.  
  
|Rotina|Condição de teste|Exemplo 932 de página de código|  
|------------|-----------------------|-------------------------------------|  
|[\_ismbcalnum, \_ismbcalnum\_l](../Topic/_ismbcalnum,%20_ismbcalnum_l,%20_ismbcalpha,%20_ismbcalpha_l,%20_ismbcdigit,%20_ismbcdigit_l.md)|Alfanumérico|Retorna diferente de zero e somente se `c` for uma representação de byte único de uma letra ASCII em inglês: para ver exemplos de `_ismbcdigit` e `_ismbcalpha`.|  
|[\_ismbcalpha, \_ismbcalpha\_](../Topic/_ismbcalnum,%20_ismbcalnum_l,%20_ismbcalpha,%20_ismbcalpha_l,%20_ismbcdigit,%20_ismbcdigit_l.md)|Alfabético|Retorna um valor diferente de zero se, e somente se, `c` for uma representação de byte único de uma letra ASCII em inglês: Veja os exemplos para `_ismbcupper` e `_ismbclower` ou uma letra katakana: 0xA6\<\=`c`\<\=0xDF.|  
|[\_ismbcdigit, \_ismbcdigit\_l](../Topic/_ismbcalnum,%20_ismbcalnum_l,%20_ismbcalpha,%20_ismbcalpha_l,%20_ismbcdigit,%20_ismbcdigit_l.md)|Dígito|Retorna um valor diferente de zero se, e somente se, `c` for uma representação de byte único de um dígito ASCII: 0x30\=\<`c`\<\=0x39.|  
|[\_ismbcgraph, \_ismbcgraph\_l](../c-runtime-library/reference/ismbcgraph-functions.md)|Gráficos|Retorna um valor diferente de zero se, e somente se, `c` for uma representação de byte único de qualquer caractere imprimível ASCII ou katakana, exceto um espaço em branco \( \).  Consulte os exemplos de `_ismbcdigit`, `_ismbcalpha` e `_ismbcpunct`.|  
|[\_ismbclegal, \_ismbclegal\_l](../c-runtime-library/reference/ismbclegal-ismbclegal-l-ismbcsymbol-ismbcsymbol-l.md)|Caractere de multibyte válido|Retorna um valor diferente de zero se, e somente se, o primeiro byte de `c` estiver dentro dos intervalos 0x81 – 0x9F ou 0xE0 – 0xFC e o segundo byte estiver dentro dos intervalos 0x40 \- 0x7E ou 0x80 \- FC.|  
|[\_ismbclower, \_ismbclower\_l](../c-runtime-library/reference/ismbclower-ismbclower-l-ismbcupper-ismbcupper-l.md)|Minúsculas alfabéticas|Retorna um valor diferente de zero se, e somente se, `c` for uma representação de byte único de uma letra ASCII minúscula em inglês: 0x61\<\=`c`\<\=0x7A.|  
|[\_ismbcprint, \_ismbcprint\_l](../c-runtime-library/reference/ismbcgraph-functions.md)|Para impressão|Retorna um valor diferente de zero se, e somente se, `c` for uma representação de byte único de qualquer caractere imprimível ASCII ou katakana, incluindo um espaço em branco \( \): Veja os exemplos para `_ismbcspace`, `_ismbcdigit`, `_ismbcalpha` e `_ismbcpunct`.|  
|[\_ismbcpunct, \_ismbcpunct\_l](../c-runtime-library/reference/ismbcgraph-functions.md)|Pontuação|Retorna um valor diferente de zero se, e somente se, `c` for uma representação de byte único de um caractere de pontuação ASCII ou katakana.|  
|[\_ismbcblank, \_ismbcblank\_l,](../c-runtime-library/reference/ismbcgraph-functions.md)|Espaço ou tabulação horizontal|Retorna um valor diferente de zero se, e somente se, `c` for uma representação de byte único de um caractere de espaço ou um caractere de tabulação horizontal: `c`\=0x20 ou `c`\=0x09.|  
|[\_ismbcspace, \_ismbcspace\_l](../c-runtime-library/reference/ismbcgraph-functions.md)|Whitespace|Retorna um valor diferente de zero se, e somente se, `c` for um caractere de espaço em branco: `c`\=0x20 ou 0x09\<\=`c`\<\=0x0D.|  
|[\_ismbcsymbol, \_ismbcsymbol\_l](../c-runtime-library/reference/ismbclegal-ismbclegal-l-ismbcsymbol-ismbcsymbol-l.md)|Símbolo de multibyte|Retorna um valor diferente de zero se, e somente se, 0x8141\=\<`c`\<\=0x81AC.|  
|[\_ismbcupper, \_ismbcupper\_l](../c-runtime-library/reference/ismbclower-ismbclower-l-ismbcupper-ismbcupper-l.md)|Minúsculas alfabéticas|Retorna um valor diferente de zero se, e somente se, `c` for uma representação de byte único de uma letra ASCII maiúscula em inglês: 0x41\<\=`c`\<\=0x5A.|  
  
 **Página de código 932 específico**  
  
 As seguintes rotinas são específicas para a página de código 932.  
  
|Rotina|Condição de teste \(somente a página de código 932\)|  
|------------|----------------------------------------------------------|  
|[\_ismbchira, \_ismbchira\_l](../c-runtime-library/reference/ismbchira-ismbchira-l-ismbckata-ismbckata-l.md)|Hiragana de dois bytes: 0x829F\=\<`c`\<\=0x82F1.|  
|[\_ismbckata, \_ismbckata\_l](../c-runtime-library/reference/ismbchira-ismbchira-l-ismbckata-ismbckata-l.md)|Katakana de dois bytes: 0x8340\=\<`c`\<\=0x8396.|  
|[\_ismbcl0, \_ismbcl0\_l](../c-runtime-library/reference/ismbcl0-ismbcl0-l-ismbcl1-ismbcl1-l-ismbcl2-ismbcl2-l.md)|JIS não Kanji: 0x8140\<\=`c`\<\=0x889E.|  
|[\_ismbcl1, \_ismbcl1\_l](../c-runtime-library/reference/ismbcl0-ismbcl0-l-ismbcl1-ismbcl1-l-ismbcl2-ismbcl2-l.md)|JIS level\-1: 0x889F\<\=`c`\<\=0x9872.|  
|[\_ismbcl2, \_ismbcl2\_l](../c-runtime-library/reference/ismbcl0-ismbcl0-l-ismbcl1-ismbcl1-l-ismbcl2-ismbcl2-l.md)|JIS level\-2: 0x989F\<\=`c`\<\=0xEA9E.|  
  
 `_ismbcl0`, `_ismbcl1` e `_ismbcl2` verificam se o valor especificado `c` corresponde às condições de teste descritas na tabela anterior, mas não verificam se `c` é um caractere multibyte válido.  Se o byte menor estiver nos intervalos 0x00 – 0x3F, 0x7F, ou 0xFD – 0xFF, essas funções retornarão um valor diferente de zero, indicando que o caractere satisfaz a condição de teste.  Use [\_ismbbtrail, \_ismbbtrail\_l](../c-runtime-library/reference/ismbbtrail-ismbbtrail-l.md) para testar se o caractere multibyte está definido.  
  
 **Encerrar página de código 932 específica**  
  
## Consulte também  
 [Classificação de caractere](../c-runtime-library/character-classification.md)   
 [Rotinas is, isw](../c-runtime-library/is-isw-routines.md)   
 [Rotinas \_ismbb](../c-runtime-library/ismbb-routines.md)