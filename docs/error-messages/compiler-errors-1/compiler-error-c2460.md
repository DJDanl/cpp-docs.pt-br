---
title: "Erro do Compilador C2460 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C2460"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2460"
ms.assetid: d969fca9-3ac5-4e4e-88fc-df05510e2093
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2460
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identifier1”: usa o “identifier2”, que está sendo definido  
  
 Uma classe ou estrutura \(`identifier2`\) é declarado como um membro do`identifier1`\(\).  As definições recursivos das classes e as estruturas não são permitidas.  
  
 O seguinte exemplo gera C2460:  
  
```  
// C2460.cpp  
class C {  
   C aC;    // C2460  
};  
```  
  
 Em vez disso, use uma referência de ponteiro na classe.  
  
```  
// C2460.cpp  
class C {  
   C * aC;    // OK  
};  
```