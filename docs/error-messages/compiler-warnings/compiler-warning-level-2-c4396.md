---
title: "Compilador C4396 de aviso (n&#237;vel 2) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C4396"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4396"
ms.assetid: 7cd6b283-db17-4574-b299-03e0b913ad70
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4396 de aviso (n&#237;vel 2)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

"nome": o especificador embutido não pode ser usado quando uma declaração de amigo se refere a uma especialização de um modelo de função  
  
 Uma especialização de um modelo de função não é possível especificar qualquer um do [embutido](../../misc/inline-inline-forceinline.md) especificadores. O compilador emite um aviso C4396 e ignora o especificador embutido.  
  
### Para corrigir este erro  
  
-   Remover o `inline`, `__inline`, ou `__forceinline` especificador de declaração de função friend.  
  
## Exemplo  
 O código exemplo seguinte mostra um amigo inválido função declaração com um `inline` especificador.  
  
```  
// C4396.cpp // compile with: /W2 /c class X; template<class T> void Func(T t, int i); class X { friend inline void Func<char>(char t, int i);  //C4396 // try the following line instead //    friend void Func<char>(char t, int i); int i; };  
```