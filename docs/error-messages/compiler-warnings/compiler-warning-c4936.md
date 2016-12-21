---
title: "C4936 de aviso do compilador | Microsoft Docs"
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
  - "C4936"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4936"
ms.assetid: 6676de35-bf1b-4d0b-a70f-b5734130336c
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C4936 de aviso do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este declspec é suportado apenas quando compilado com \/clr ou \/clr: puro  
  
 Um `__declspec` modificador foi usado, mas que `__declspec` modificador só é válido quando compilado com uma do [\/clr](../../build/reference/clr-common-language-runtime-compilation.md) opções.  
  
 Para obter mais informações, consulte [appdomain](../Topic/appdomain.md) e [processo](../../cpp/process.md).  
  
 C4936 sempre é emitida como um erro.  Você pode desabilitar C4936 com o [warning](../../preprocessor/warning.md) pragma.  
  
 O exemplo a seguir gera C4936:  
  
```  
// C4936.cpp // compile with: /c // #pragma warning (disable : 4936) __declspec(process) int i;   // C4936 __declspec(appdomain) int j;   // C4936  
```