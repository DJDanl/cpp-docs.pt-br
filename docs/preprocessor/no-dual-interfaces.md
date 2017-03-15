---
title: "no_dual_interfaces | Microsoft Docs"
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
  - "no_dual_interfaces"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Atributo no_dual_interfaces"
ms.assetid: 9acd5d9d-4a49-4cdc-9470-73a2c23cf512
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# no_dual_interfaces
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico do C\+\+**  
  
 Altera o modo como o compilador gerenciar funções wrapper para métodos da interface dupla.  
  
## Sintaxe  
  
```  
no_dual_interfaces  
```  
  
## Comentários  
 Normalmente, o wrapper chamará o método por meio da tabela de funções virtuais da interface.  Com `no_dual_interfaces`, o wrapper chama **IDispatch::Invoke** para invocar o método.  
  
 **FIM de Específico do C\+\+**  
  
## Consulte também  
 [Atributos \#import](../preprocessor/hash-import-attributes-cpp.md)   
 [Diretiva \#import](../Topic/%23import%20Directive%20\(C++\).md)