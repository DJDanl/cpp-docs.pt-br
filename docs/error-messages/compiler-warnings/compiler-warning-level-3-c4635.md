---
title: "Compilador C4635 de aviso (n&#237;vel 3) | Microsoft Docs"
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
  - "C4635"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4635"
ms.assetid: b2ba90de-c093-4a76-8076-b65878467574
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4635 de aviso (n&#237;vel 3)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Destino de comentário de documento XML: incorreta de XML: motivo  
  
 O compilador encontrar algum problema com as marcas XML.  Corrigir o problema e recompile  
  
 O exemplo a seguir gera C4635:  
  
```  
// C4635.cpp // compile with: /doc /clr /W3 /c /// <summary> /// The contents of the folder have changed. /// <summary/>   // C4635 // try the following line instead // /// </summary> public ref class Test {};  
```  
  
 Observe que a saída deste exemplo diz: **marca final 'member' não coincide com a marca de início 'Resumo'.**  
  
 O problema com este exemplo é que a marca de fim para \< resumo \> está incorreta e o compilador não reconhecê\-lo como o resumo de \< \> marca de fim.  A marca \< membro \> é inserida no arquivo .xdc pelo compilador em cada compilação \/doc.  Portanto, o problema aqui é que a marca de fim \< \/ membro \>, não coincide com a marca de início anterior, o compilador processados \(\< summary \>.