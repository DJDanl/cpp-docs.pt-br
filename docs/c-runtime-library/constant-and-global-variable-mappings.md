---
title: "Constante e mapeamentos de vari&#225;vel global | Microsoft Docs"
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
  - "_tenviron"
  - "_TEOF"
  - "_tfinddata_t"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _tenviron"
  - "Tipo _TEOF"
  - "Função _tfinddata_t"
  - "mapeamentos de texto genérico"
  - "Função tenviron"
  - "Tipo TEOF"
  - "Função tfinddatat"
ms.assetid: 3af4fd3e-9ed5-4ed9-96fd-7031e5126fd1
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constante e mapeamentos de vari&#225;vel global
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Esses constante de genérico\- texto, a variável global, e ocorrendo mapeamentos são definidos em TCHAR.H e dependem se `_UNICODE` constante ou `_MBCS` foram definidos em seu programa.  
  
### Mapeamentos de constante de Genérico\- texto e da variável global  
  
|Genérico\- texto \- nome do objeto|SBCS \(\_UNICODE, \_MBCS não definidos\)|\_MBCS definido|\_UNICODE definido|  
|----------------------------------------|----------------------------------------------|---------------------|------------------------|  
|`_TEOF`|`EOF`|`EOF`|`WEOF`|  
|`_tenviron`|`_environ`|`_environ`|`_wenviron`|  
|`_tpgmptr`|`_pgmptr`|`_pgmptr`|`_wpgmptr`|  
  
## Consulte também  
 [Mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md)   
 [Mapeamentos de tipo de dados](../c-runtime-library/data-type-mappings.md)   
 [Mapeamentos de rotina](../c-runtime-library/routine-mappings.md)   
 [Um programa de texto genérico de exemplo](../c-runtime-library/a-sample-generic-text-program.md)   
 [Usando mapeamentos de texto genérico](../c-runtime-library/using-generic-text-mappings.md)