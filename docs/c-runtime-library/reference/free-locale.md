---
title: "_free_locale | Microsoft Docs"
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
  - "_free_locale"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-locale-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "__free_locale"
  - "free_locale"
  - "_free_locale"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função __free_locale"
  - "Função _free_locale"
  - "Função free_locale"
  - "localidades, liberando"
ms.assetid: 1f08d348-ab32-4028-a145-6cbd51b49af9
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _free_locale
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Libera um objeto da localidade.  
  
## Sintaxe  
  
```  
void _free_locale(  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `locale`  
 Objeto de localidade para libertar.  
  
## Comentários  
 A função de `_free_locale` é usada para liberar o objeto de localidade obtido de uma chamada para `_get_current_locale` ou a `_create_locale`.  
  
 O nome anterior desta função, `__free_locale` \(com dois sublinhados principais\) foi substituído.  
  
## Requisitos  
  
|`Routine`|Cabeçalho necessário|  
|---------------|--------------------------|  
|`_free_locale`|\<locale.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 Nenhum equivalente.  
  
## Consulte também  
 [\_get\_current\_locale](../Topic/_get_current_locale.md)   
 [\_create\_locale, \_wcreate\_locale](../../c-runtime-library/reference/create-locale-wcreate-locale.md)