---
title: "Compilador C4008 de aviso (n&#237;veis 2 e 3) | Microsoft Docs"
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
  - "C4008"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4008"
ms.assetid: fb45e535-cb68-4743-80e9-a6e34cfffeca
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4008 de aviso (n&#237;veis 2 e 3)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'identifier': atributo ' atributo ' ignorado  
  
 O compilador ignorado a `__fastcall`, **estático**, ou **embutido** atributo para uma função \(aviso de nível 3\) ou dados \(aviso de nível 2\).  
  
### Para corrigir verificando as possíveis causas  
  
1.  `__fastcall` atributo com dados.  
  
2.  **estático** ou **embutido** atributo com **principal** função.