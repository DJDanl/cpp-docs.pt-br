---
title: "Compilador C4629 de aviso (n&#237;vel 4) | Microsoft Docs"
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
  - "C4629"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4629"
ms.assetid: 158cde12-bae5-4d43-b575-b52b35aaa0b9
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4629 de aviso (n&#237;vel 4)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

digraph usado, a seqüência de caracteres 'digraph' interpretada como token 'char' \(inserir um espaço entre os dois caracteres se for não pretende\)  
  
 Em [\/Za](../../build/reference/za-ze-disable-language-extensions.md), o compilador emitirá um aviso quando detecta um digraph.  
  
 O exemplo a seguir gera C4629:  
  
```  
// C4629.cpp // compile with: /Za /W4 int main() <%   // C4629 <% digraph for { }  
```