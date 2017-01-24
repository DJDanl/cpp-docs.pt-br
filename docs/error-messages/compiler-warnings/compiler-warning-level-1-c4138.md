---
title: "Compilador C4138 de aviso (n&#237;vel 1) | Microsoft Docs"
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
  - "C4138"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4138"
ms.assetid: 65ebf929-bba0-4237-923b-c1b66adfe17d
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4138 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

' \* \/' encontrado fora de comentário  
  
 O delimitador de comentário de fechamento não é precedido por um delimitador de comentário de abertura. O compilador pressupõe um espaço entre o asterisco \(**\***\) e a barra \(\/\).  
  
## Exemplo  
  
```  
// C4138a.cpp // compile with: /W1 int */*comment*/ptr;   // C4138 Ambiguous first delimiter causes warning int main() { }  
```  
  
 Esse aviso pode ser causado pela tentativa de aninhar comentários.  
  
 Esse aviso pode ser resolvido se você comentar seções de código que contém comentários, coloque o código em um **\#if \/ \#endif** bloquear e definir a expressão de controle como zero:  
  
```  
// C4138b.cpp // compile with: /W1 #if 0 int my_variable;   /* Declaration currently not needed */ #endif int main() { }  
```