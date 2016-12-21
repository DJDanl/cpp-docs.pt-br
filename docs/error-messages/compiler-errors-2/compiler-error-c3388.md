---
title: "C3388 de erro do compilador | Microsoft Docs"
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
  - "C3388"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3388"
ms.assetid: 34336545-ed13-4d81-ab5f-f869799fe4c2
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3388 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'type': não é permitido como uma restrição, supondo que 'classe ref' para continuar a análise  
  
 Uma restrição foi especificada em um tipo genérico, mas a restrição não foi especificada corretamente. Consulte [Constraints on Generic Type Parameters \(C\+\+\/CLI\)](../Topic/Constraints%20on%20Generic%20Type%20Parameters%20\(C++-CLI\).md) para obter mais informações.  
  
## Exemplo  
 O exemplo a seguir gera C3388.  
  
```  
// C3388.cpp // compile with: /clr /c interface class AA {}; generic <class T> where T : interface class   // C3388 ref class C {}; // OK generic <class T> where T : AA ref class D {};  
```