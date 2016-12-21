---
title: "Compilador C4076 de aviso (n&#237;vel 1) | Microsoft Docs"
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
  - "C4076"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4076"
ms.assetid: 04581066-313a-4a11-bb60-721e6d038d75
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4076 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'typemod': não pode ser usado com o tipo 'typename'  
  
 Um modificador de tipo seja **assinado** ou `unsigned`, não pode ser usado com um tipo não inteiro.***typemod*** será ignorado.  
  
## Exemplo  
 O exemplo a seguir gera C4076:  
  
```  
// C4076.cpp // compile with: /W1 /LD unsigned double x;   // C4076  
```