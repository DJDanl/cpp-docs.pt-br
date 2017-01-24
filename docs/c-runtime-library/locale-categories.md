---
title: "Categorias de localidade | Microsoft Docs"
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
  - "LC_MAX"
  - "LC_MIN"
  - "LC_MONETARY"
  - "LC_TIME"
  - "LC_NUMERIC"
  - "LC_COLLATE"
  - "LC_CTYPE"
  - "LC_ALL"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante LC_ALL"
  - "Constante LC_COLLATE"
  - "Constante LC_CTYPE"
  - "Constante LC_MAX"
  - "Constante LC_MIN"
  - "Constante LC_MONETARY"
  - "Constante LC_NUMERIC"
  - "Constante LC_TIME"
  - "constantes de localidade"
ms.assetid: 868f1493-fe5d-4722-acab-bfcd374a063a
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Categorias de localidade
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <locale.h>  
  
```  
  
## Comentários  
 As categorias de localidade manifestas constantes são usadas pela rotinas do local para especificar que a parte das informações de localidade de um programa será usada.  A localidade refere\-se à localidade \(ou o país\/região\) para que alguns aspectos do programa podem ser personalizados.  As áreas de localidades incluem dependente, por exemplo, a formatação de datas ou o formato de exibição de valores monetários.  
  
|Categoria de localidade|Partes do programa afetadas|  
|-----------------------------|---------------------------------|  
|`LC_ALL`|Qualquer comportamento específico de localidade \(todas as categorias\)|  
|`LC_COLLATE`|Comportamento de `strcoll` e funções de `strxfrm`|  
|`LC_CTYPE`|O comportamento de caractere funções de manipulação \(exceto **isdigit**, `isxdigit`, `mbstowcs`, e `mbtowc`, que não são afetados\)|  
|`LC_MAX`|Mesmo que `LC_TIME`|  
|`LC_MIN`|Mesmo que `LC_ALL`|  
|`LC_MONETARY`|As informações de formatação de moeda retornado pela função de `localeconv`|  
|`LC_NUMERIC`|O caractere de ponto decimal para rotinas da saída formatada \(por exemplo, `printf`\), rotinas de conversão de dados, e as informações de formatação nonmonetary retornado pela função de `localeconv`|  
|`LC_TIME`|Comportamento da função de `strftime`|  
  
 Consulte [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md) para obter um exemplo.  
  
## Consulte também  
 [localeconv](../c-runtime-library/reference/localeconv.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [Funções strcoll](../c-runtime-library/strcoll-functions.md)   
 [strftime, wcsftime, \_strftime\_l, \_wcsftime\_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)   
 [strxfrm, wcsxfrm, \_strxfrm\_l, \_wcsxfrm\_l](../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)