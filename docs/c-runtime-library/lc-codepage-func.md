---
title: "___lc_codepage_func | Microsoft Docs"
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
  - "___lc_codepage_func"
apilocation: 
  - "msvcr120.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr80.dll"
  - "msvcr100.dll"
  - "msvcr90.dll"
  - "msvcr110.dll"
  - "msvcrt.dll"
apitype: "DLLExport"
f1_keywords: 
  - "lc_codepage_func"
  - "___lc_codepage_func"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "___lc_codepage_func"
ms.assetid: 6a663bd0-5a63-4a2f-9507-872ec1582aae
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ___lc_codepage_func
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Função CRT interna.  Recupera a página de código atual do thread.  
  
## Sintaxe  
  
```cpp  
UINT ___lc_codepage_func(void);  
```  
  
## Valor de retorno  
 A página de código atual do thread.  
  
## Comentários  
 `___lc_codepage_func` é uma função CRT interna usada por outras funções CRT para obter a página de código atual do armazenamento local do thread para os dados do CRT.  Essa informação também está disponível usando a função [\_get\_current\_locale](../Topic/_get_current_locale.md).  
  
 Uma *página de código* é um mapeamento dos códigos de um ou dois bytes para caracteres individuais.  Diferentes páginas de código contêm caracteres especiais diferentes, que geralmente são personalizados para um idioma ou um grupo de idiomas.  Para obter mais informações páginas de códigos, consulte [Páginas de código](../c-runtime-library/code-pages.md).  
  
 Funções CRT internas são específicas da implementação e estão sujeitas a alteração em cada versão.  Não recomendamos usá\-las no seu código.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`___lc_codepage_func`|crt\\src\\setlocal.h|  
  
## Consulte também  
 [\_get\_current\_locale](../Topic/_get_current_locale.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [\_create\_locale, \_wcreate\_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)   
 [\_free\_locale](../c-runtime-library/reference/free-locale.md)