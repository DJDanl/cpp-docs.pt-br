---
title: "Compilador C4935 de aviso (n&#237;vel 1) | Microsoft Docs"
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
  - "C4935"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4935"
ms.assetid: a36c56d3-571a-44dd-bb0f-bcc6b020e134
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4935 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

especificador de acesso do assembly modificado de 'access'  
  
 A visibilidade de um tipo do assembly foi modificada. O compilador usa o especificador de última que ele encontra. Por exemplo, a visibilidade do assembly de uma declaração de encaminhamento pode ser diferente do que a visibilidade do assembly da definição de classe.  
  
 C4935 é só pode ser acessado usando **\/clr:oldSyntax**.  
  
 O exemplo a seguir gera C4935:  
  
```  
// C4935.cpp // compile with: /clr:oldSyntax /W1 /c public __gc public class X {   // C4935 int i; };  
```