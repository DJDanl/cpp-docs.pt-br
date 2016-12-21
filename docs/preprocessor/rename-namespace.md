---
title: "rename_namespace | Microsoft Docs"
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
  - "rename_namespace"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Atributo rename_namespace"
ms.assetid: 45006d2b-36cd-4bec-98b9-3b8ec45299e3
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# rename_namespace
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico do C\+\+**  
  
 Renomeia o namespace que contém o conteúdo da biblioteca de tipos.  
  
## Sintaxe  
  
```  
rename_namespace("NewName")  
```  
  
#### Parâmetros  
 `NewName`  
 O nome do novo namespace.  
  
## Comentários  
 Usa um único argumento, *NewName*, que especifica o novo nome do namespace.  
  
 Para remover o namespace, use o atributo [no\_namespace](../Topic/no_namespace.md).  
  
 **FIM de Específico do C\+\+**  
  
## Consulte também  
 [Atributos \#import](../preprocessor/hash-import-attributes-cpp.md)   
 [Diretiva \#import](../Topic/%23import%20Directive%20\(C++\).md)