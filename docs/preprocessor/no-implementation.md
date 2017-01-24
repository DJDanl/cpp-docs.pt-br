---
title: "no_implementation | Microsoft Docs"
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
  - "no_implementation"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Atributo no_implementation"
ms.assetid: bdc67785-e131-409c-87bc-f4d2f4abb07b
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# no_implementation
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico do C\+\+**  
  
 Suprime geração do cabeçalho .tli, que contém as implementações das funções de membro do wrapper.  
  
## Sintaxe  
  
```  
no_implementation  
```  
  
## Comentários  
 Se esse atributo for especificado, o cabeçalho .tlh, com as declarações para expor itens do tipo biblioteca, será gerado sem uma instrução `#include` para incluir o arquivo de cabeçalho .tli.  
  
 Este atributo é usado junto com [implementation\_only](../preprocessor/implementation-only.md).  
  
 **FIM de Específico do C\+\+**  
  
## Consulte também  
 [Atributos \#import](../preprocessor/hash-import-attributes-cpp.md)   
 [Diretiva \#import](../Topic/%23import%20Directive%20\(C++\).md)