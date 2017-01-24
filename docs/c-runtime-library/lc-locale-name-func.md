---
title: "___lc_locale_name_func | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "___lc_locale_name_func"
apilocation: 
  - "msvcrt.dll"
  - "msvcr110.dll"
  - "msvcr100.dll"
  - "msvcr90.dll"
  - "msvcr120.dll"
  - "msvcr80.dll"
  - "msvcr110_clr0400.dll"
apitype: "DLLExport"
f1_keywords: 
  - "___lc_locale_name_func"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "___lc_locale_name_func"
ms.assetid: ef858308-872e-43de-95e0-9b1b4084343e
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ___lc_locale_name_func
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Função CRT interna.  Recupera o nome da localidade atual do thread.  
  
## Sintaxe  
  
```cpp  
wchar_t** ___lc_locale_name_func(void);  
```  
  
## Valor de retorno  
 Um ponteiro para uma cadeia de caracteres contendo o nome da localidade atual do thread.  
  
## Comentários  
 `___lc_locale_name_func` é uma função CRT interna usada por outras funções CRT para obter o nome da localidade atual do armazenamento local do thread para dados CRT.  Essas informações também estão disponíveis usando a função [\_get\_current\_locale](../Topic/_get_current_locale.md) ou as funções [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md).  
  
 Funções CRT internas são específicas da implementação e estão sujeitas a alteração em cada versão.  Não recomendamos usá\-las no seu código.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`___lc_locale_name_func`|crt\\src\\setlocal.h|  
  
## Consulte também  
 [\_get\_current\_locale](../Topic/_get_current_locale.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [\_create\_locale, \_wcreate\_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)   
 [\_free\_locale](../c-runtime-library/reference/free-locale.md)