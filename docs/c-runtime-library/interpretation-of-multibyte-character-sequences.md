---
title: "Interpreta&#231;&#227;o de sequ&#234;ncias de caracteres multibyte | Microsoft Docs"
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
  - "c.character.multibyte"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "MBCS [C++], página de código de localidade"
ms.assetid: da9150de-70ea-4d2f-90e6-ddb9202dd80b
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Interpreta&#231;&#227;o de sequ&#234;ncias de caracteres multibyte
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A maioria das rotinas de multibyte\- caractere na biblioteca de tempo de execução Microsoft reconhece sequências de multibyte\- caractere em relação a uma página de código de multibyte.  O valor de saída é afetado pela configuração da categoria `LC_CTYPE` de localidade. Para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  As versões dessas funções sem o sufixo `_l` usam a localidade atual para esse comportamento dependente da localidade; as versões com o sufixo `_l` são idênticas, exceto que elas usam o parâmetro de localidade informado.  
  
### Rotinas de Multibyte de localidade dependente  
  
|Rotina|Uso|  
|------------|---------|  
|[\_mbclen, mblen, \_mblen\_l](../c-runtime-library/reference/mbclen-mblen-mblen-l.md)|Validar e retornar o número de bytes em caracteres multibyte|  
|[strlen, wcslen, \_mbslen, \_mbslen\_l, \_mbstrlen, \_mbstrlen\_l](../Topic/strlen,%20wcslen,%20_mbslen,%20_mbslen_l,%20_mbstrlen,%20_mbstrlen_l.md)|Para cadeias de caracteres multibyte: validar cada caractere na cadeia de caracteres; retorna o comprimento da cadeia de caracteres.  Para cadeias de caracteres amplas: comprimento da cadeia de caracteres.|  
|[mbstowcs, \_mbstowcs\_l](../c-runtime-library/reference/mbstowcs-mbstowcs-l.md), [mbstowcs\_s, \_mbstowcs\_s\_l](../c-runtime-library/reference/mbstowcs-s-mbstowcs-s-l.md)|Converter a sequência de caracteres multibyte correspondente à sequência de caracteres amplos|  
|[mbtowc, \_mbtowc\_l](../Topic/mbtowc,%20_mbtowc_l.md)|O converter caracteres multibyte ao caractere largo correspondente|  
|[wcstombs, \_wcstombs\_l](../Topic/wcstombs,%20_wcstombs_l.md), [wcstombs\_s, \_wcstombs\_s\_l](../Topic/wcstombs_s,%20_wcstombs_s_l.md)|Converter a sequência de caracteres amplos correspondente à sequência de caracteres multibyte|  
|[wctomb, \_wctomb\_l](../c-runtime-library/reference/wctomb-wctomb-l.md), [wctomb\_s, \_wctomb\_s\_l](../c-runtime-library/reference/wctomb-s-wctomb-s-l.md)|Converter o caractere largo correspondente em caracteres multibyte|  
  
## Consulte também  
 [Internacionalização](../c-runtime-library/internationalization.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)