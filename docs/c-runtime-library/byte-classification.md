---
title: "Classifica&#231;&#227;o de byte | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.types.bytes"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "rotinas de classificação de byte"
  - "bytes, testando"
  - "página de código 932"
ms.assetid: 1cb52d71-fb0c-46ca-aad7-6472c1103370
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classifica&#231;&#227;o de byte
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada uma dessas rotinas testa um byte especificado de um caracteres multibyte para a satisfação de uma condição.  Exceto onde especificado de outra forma, o valor de saída é afetado pela configuração de configuração da categoria de `LC_CTYPE` de localidade; consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md) para obter mais informações.  As versões dessas funções sem o sufixo `_l` usam a localidade atual para esse comportamento dependente da localidade; as versões com o sufixo `_l` são idênticas, exceto que elas usam o parâmetro de localidade informado.  
  
> [!NOTE]
>  Por definição, os caracteres ASCII entre 0 e 127 são um subconjunto de todos os conjuntos de multibyte\- caractere.  Por exemplo, o conjunto de caracteres katakana japonês inclui caracteres ASCII bem como não ASCII.  
  
 As constantes predefinidas na tabela a seguir são definidas em CTYPE.H.  
  
### Rotinas de Byte\- classificação de Multibyte\- caractere  
  
|Rotina|Condição de teste do byte|Equivalente a .NET Framework|  
|------------|-------------------------------|----------------------------------|  
|[isleadbyte, \_isleadbyte\_l](../c-runtime-library/reference/isleadbyte-isleadbyte-l.md)|Byte inicial; o resultado da análise depende da configuração da categoria de `LC_CTYPE` de localidade atual|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
|[\_ismbbalnum, \_ismbbalnum\_l](../c-runtime-library/reference/ismbbalnum-ismbbalnum-l.md)|`isalnum &#124;&#124; _ismbbkalnum`|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
|[\_ismbbalpha, \_ismbbalpha\_l](../c-runtime-library/reference/ismbbalpha-ismbbalpha-l.md)|`isalpha &#124;&#124; _ismbbkalnum`|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
|[\_ismbbgraph, \_ismbbgraph\_l](../c-runtime-library/reference/ismbbgraph-ismbbgraph-l.md)|Mesmo que `_ismbbprint`, mas `_ismbbgraph` não inclui o caractere de espaço \(0x20\)|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
|[\_ismbbkalnum, \_ismbbkalnum\_l](../c-runtime-library/reference/ismbbkalnum-ismbbkalnum-l.md)|Símbolo de texto não ASCII a não ser pontuação.  Por exemplo, na página de código 932, apenas para os testes de `_ismbbkalnum` katakana alfanuméricos|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
|[\_ismbbkana, \_ismbbkana\_l](../c-runtime-library/reference/ismbbkana-ismbbkana-l.md)|Katakana e 0xA1 \(– 0xDF\), página de código 932 somente|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
|[\_ismbbkprint, \_ismbbkprint\_l](../c-runtime-library/reference/ismbbkprint-ismbbkprint-l.md)|Texto não ASCII ou símbolo de pontuação não ASCII.  Por exemplo, somente na página de código 932, `_ismbbkprint` testa o katakana alfanumérico ou a pontuação de katakana \(intervalo: 0xA1 – 0xDF\).|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
|[\_ismbbkpunct, \_ismbbkpunct\_l](../Topic/_ismbbkpunct,%20_ismbbkpunct_l.md)|Pontuação não ASCII.  Por exemplo, somente na página de código 932, `_ismbbkpunct` testa a pontuação de katakana.|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
|[\_ismbblead, \_ismbblead\_l](../c-runtime-library/reference/ismbblead-ismbblead-l.md)|Primeiro byte do caractere de multibyte.  Por exemplo, somente na página de código 932, os intervalos válidos são: de 0x81 a 0x9F e de 0xE0 a 0xFC.|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
|[\_ismbbprint, \_ismbbprint\_l](../c-runtime-library/reference/ismbbprint-ismbbprint-l.md)|`isprint &#124;&#124; _ismbbkprint. ismbbprint` inclui o caractere de espaço \(0x20\)|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
|[\_ismbbpunct, \_ismbbpunct\_l](../c-runtime-library/reference/ismbbpunct-ismbbpunct-l.md)|`ispunct &#124;&#124; _ismbbkpunct`|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
|[\_ismbbtrail, \_ismbbtrail\_l](../c-runtime-library/reference/ismbbtrail-ismbbtrail-l.md)|Segundo byte do caractere multibyte.  Por exemplo, somente na página de código 932, os intervalos válidos são: de 0x40 a 0x7E e de 0x80 a 0xEC.|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
|[\_ismbslead, \_ismbslead\_l](../c-runtime-library/reference/ismbslead-ismbstrail-ismbslead-l-ismbstrail-l.md)|Byte inicial \(no contexto da cadeia de caracteres\)|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
|[ismbstrail, \_ismbstrail\_l](../c-runtime-library/reference/ismbslead-ismbstrail-ismbslead-l-ismbstrail-l.md)|Byte final \(no contexto da cadeia de caracteres\)|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
|[\_mbbtype, \_mbbtype\_l](../c-runtime-library/reference/mbbtype-mbbtype-l.md)|Tipo de retorno de bytes baseado em bytes anterior|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
|[\_mbsbtype, \_mbsbtype\_l](../c-runtime-library/reference/mbsbtype-mbsbtype-l.md)|Tipo de retorno de bytes dentro da cadeia de caracteres|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
|[mbsinit](../c-runtime-library/reference/mbsinit.md)|Controla o estado de uma conversão de caracteres multibyte.|Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)|  
  
 A macro de `MB_LEN_MAX` , definido em LIMITS.H, expanda para o comprimento máximo em bytes que qualquer caracteres multibyte pode ter.  `MB_CUR_MAX`, definido em STDLIB.H, expanda para o comprimento máximo em bytes de qualquer caracteres multibyte na localidade atual.  
  
## Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)