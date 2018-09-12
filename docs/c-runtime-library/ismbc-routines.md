---
title: Rotinas _ismbc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
apilocation:
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr100.dll
- msvcrt.dll
- msvcr90.dll
- msvcr120.dll
- msvcr80.dll
apitype: DLLExport
f1_keywords:
- _ismbc
dev_langs:
- C++
helpviewer_keywords:
- ismbc routines
- _ismbc routines
ms.assetid: b8995391-7857-4ac3-9a1e-de946eb4464d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4aaf456e83968cf47573a9ea2e765f9e7d552625
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43760244"
---
# <a name="ismbc-routines"></a>Rotinas _ismbc
Cada teste de rotina **_ismbc** testa um caractere multibyte `c` para uma condição determinada.  
  
|||  
|-|-|  
|[_ismbcalnum, _ismbcalnum_l, _ismbcalpha, _ismbcalpha_l, _ismbcdigit, _ismbcdigit_l](../c-runtime-library/reference/ismbcalnum-functions.md)|[_ismbcl0, _ismbcl0_l, _ismbcl1, _ismbcl1_l, _ismbcl2, _ismbcl2_l](../c-runtime-library/reference/ismbcl0-ismbcl0-l-ismbcl1-ismbcl1-l-ismbcl2-ismbcl2-l.md)|  
|[_ismbcgraph, _ismbcgraph_l, _ismbcprint, _ismbcprint_l, _ismbcpunct, _ismbcpunct_l, _ismbcblank, _ismbcblank_l, _ismbcspace, _ismbcspace_l](../c-runtime-library/reference/ismbcgraph-functions.md)|[_ismbclegal, _ismbclegal_l, _ismbcsymbol, _ismbcsymbol_l](../c-runtime-library/reference/ismbclegal-ismbclegal-l-ismbcsymbol-ismbcsymbol-l.md)|  
|[_ismbchira, _ismbchira_l, _ismbckata, _ismbckata_l](../c-runtime-library/reference/ismbchira-ismbchira-l-ismbckata-ismbckata-l.md)|[_ismbclower, _ismbclower_l, _ismbcupper, _ismbcupper_l](../c-runtime-library/reference/ismbclower-ismbclower-l-ismbcupper-ismbcupper-l.md)|  
  
## <a name="remarks"></a>Comentários  
O resultado do teste de cada rotina **_ismbc** depende da página de código multibyte em vigor. Páginas de código multibyte têm caracteres alfabéticos de um byte. Por padrão, a página de código multibyte é definida para a página de código ANSI padrão do sistema obtida do sistema operacional na inicialização do programa. Você pode consultar ou alterar a página de código multibyte em uso com [_getmbcp](../c-runtime-library/reference/getmbcp.md) ou [_setmbcp](../c-runtime-library/reference/setmbcp.md), respectivamente.  
  
O valor de saída é afetado pela configuração da categoria `LC_CTYPE` da localidade. Confira [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo **_l** usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo **_l** são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar.  
  
|Rotina|Condição de teste|Exemplo da página de código 932|  
|-------------|--------------------|---------------------------|  
|[_ismbcalnum, _ismbcalnum_l](../c-runtime-library/reference/ismbcalnum-functions.md)|Alfanumérico|Retornará um valor diferente de zero se e somente se `c` for uma representação de byte único de uma letra ASCII em inglês: consulte exemplos para `_ismbcdigit` e `_ismbcalpha`.|  
|[_ismbcalpha, _ismbcalpha\_](../c-runtime-library/reference/ismbcalnum-functions.md)|Alfabético|Retornará um valor diferente de zero se e somente se `c` for uma representação de byte único de uma letra ASCII em inglês: confira exemplos de `_ismbcupper` e `_ismbclower`; ou uma letra katakana: 0xA6<=`c`<=0xDF.|  
|[_ismbcdigit, _ismbcdigit_l](../c-runtime-library/reference/ismbcalnum-functions.md)|Dígito|Retornará um valor diferente de zero se e somente se `c` for uma representação de um byte único de um dígito ASCII: 0x30<=`c`<=0x39.|  
|[_ismbcgraph, _ismbcgraph_l](../c-runtime-library/reference/ismbcgraph-functions.md)|Gráfico|Retorna um valor diferente de zero se e somente se `c` for uma representação de byte único de qualquer caractere imprimível ASCII ou katakana, exceto por um espaço em branco ( ). Confira exemplos de `_ismbcdigit`, `_ismbcalpha` e `_ismbcpunct`.|  
|[_ismbclegal, _ismbclegal_l](../c-runtime-library/reference/ismbclegal-ismbclegal-l-ismbcsymbol-ismbcsymbol-l.md)|Caractere multibyte válido|Retornará um valor diferente de zero se e somente se o primeiro byte de `c` estiver dentro dos intervalos 0x81 – 0x9F ou 0xE0 – 0xFC, enquanto o segundo byte estiver dentro dos intervalos 0x40 – 0x7E ou 0x80 – FC.|  
|[_ismbclower, _ismbclower_l](../c-runtime-library/reference/ismbclower-ismbclower-l-ismbcupper-ismbcupper-l.md)|Alfabético minúsculo|Retorna um valor diferente de zero se e somente se `c` for uma representação de um byte de uma letra minúscula ASCII em inglês: 0x61<=`c`<=0x7A.|  
|[_ismbcprint, _ismbcprint_l](../c-runtime-library/reference/ismbcgraph-functions.md)|Imprimível|Retornará um valor diferente de zero se e somente se `c` for uma representação de byte único de qualquer caractere imprimível ASCII ou katakana, incluindo um espaço em branco ( ). Confira exemplos de `_ismbcspace`, `_ismbcdigit`, `_ismbcalpha` e `_ismbcpunct`.|  
|[_ismbcpunct, _ismbcpunct_l](../c-runtime-library/reference/ismbcgraph-functions.md)|Pontuação|Retorna um valor diferente de zero se e somente se `c` for uma representação de byte único de qualquer caractere de pontuação ASCII ou katakana.|  
|[_ismbcblank, _ismbcblank_l,](../c-runtime-library/reference/ismbcgraph-functions.md)|Espaço ou tabulação horizontal|Retornará um valor diferente de zero se e somente se `c` for uma representação de byte único de um caractere de espaço ou um caractere de tabulação horizontal: `c`=0x20 ou `c`=0x09.|  
|[_ismbcspace, _ismbcspace_l](../c-runtime-library/reference/ismbcgraph-functions.md)|Whitespace|Retornará um valor diferente de zero se e somente se `c` for um caractere de espaço em branco: `c`=0x20 ou 0x09<=`c`<=0x0D.|  
|[_ismbcsymbol, _ismbcsymbol_l](../c-runtime-library/reference/ismbclegal-ismbclegal-l-ismbcsymbol-ismbcsymbol-l.md)|Símbolo multibyte|Retorna um valor diferente de zero se e somente se 0x8141<=`c`<=0x81AC.|  
|[_ismbcupper, _ismbcupper_l](../c-runtime-library/reference/ismbclower-ismbclower-l-ismbcupper-ismbcupper-l.md)|Alfabético maiúsculo|Retorna um valor diferente de zero se e somente se `c` for uma representação de um byte de uma letra maiúscula ASCII em inglês: 0x41<=`c`<=0x5A.|  
  
**Específico da página de código 932**  
  
As seguintes rotinas são específicas para a página de código 932.  
  
|Rotina|Condição de teste (página de código 932 somente)|  
|-------------|-------------------------------------------|  
|[_ismbchira, _ismbchira_l](../c-runtime-library/reference/ismbchira-ismbchira-l-ismbckata-ismbckata-l.md)|Hiragana de byte duplo: 0x829F<=`c`<=0x82F1.|  
|[_ismbckata, _ismbckata_l](../c-runtime-library/reference/ismbchira-ismbchira-l-ismbckata-ismbckata-l.md)|Katakana de byte duplo: 0x8340<=`c`<=0x8396.|  
|[_ismbcl0, _ismbcl0_l](../c-runtime-library/reference/ismbcl0-ismbcl0-l-ismbcl1-ismbcl1-l-ismbcl2-ismbcl2-l.md)|JIS não Kanji: 0x8140<=`c`<=0x889E.|  
|[_ismbcl1, _ismbcl1_l](../c-runtime-library/reference/ismbcl0-ismbcl0-l-ismbcl1-ismbcl1-l-ismbcl2-ismbcl2-l.md)|JIS nível 1: 0x889F<=`c`<=0x9872.|  
|[_ismbcl2, _ismbcl2_l](../c-runtime-library/reference/ismbcl0-ismbcl0-l-ismbcl1-ismbcl1-l-ismbcl2-ismbcl2-l.md)|JIS nível 2: 0x989F<=`c`<=0xEA9E.|  
  
`_ismbcl0`, `_ismbcl1` e `_ismbcl2` verificam se o valor especificado `c` corresponde às condições de teste descritas na tabela acima, mas não verificam se `c` é um caractere multibyte válido. Se o byte inferior estiver nos intervalos 0x00 – 0x3F, 0x7F ou 0xFD – 0xFF, essas funções retornarão um valor diferente de zero, indicando que o caractere satisfaz a condição de teste. Use [_ismbbtrail, _ismbbtrail_l](../c-runtime-library/reference/ismbbtrail-ismbbtrail-l.md) para testar se o caractere multibyte está definido.  
  
**FIM do específico da página de código 932**  
  
## <a name="see-also"></a>Consulte também  
[Classificação de caracteres](../c-runtime-library/character-classification.md)   
[Rotinas is, isw](../c-runtime-library/is-isw-routines.md)   
[Rotinas _ismbb](../c-runtime-library/ismbb-routines.md)