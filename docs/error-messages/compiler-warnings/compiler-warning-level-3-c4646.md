---
title: "Compilador C4646 de aviso (n&#237;vel 3) | Microsoft Docs"
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
  - "C4646"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4646"
ms.assetid: 23677e8e-603e-40e0-b99a-2e4894a1278e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4646 de aviso (n&#237;vel 3)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função declarada com \_\_declspec\(noreturn\) tem o tipo de retorno não nulo  
  
 Uma função marcada com o [noreturn](../../cpp/noreturn.md) `__declspec` modificador deve ter uma [void](../../cpp/void-cpp.md) tipo de retorno.  
  
 O exemplo a seguir gera C4646:  
  
```  
// C4646.cpp // compile with: /W3 /WX int __declspec(noreturn) TestFunction() {   // C4646  make return type void }  
```