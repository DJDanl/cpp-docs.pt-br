---
title: "Aviso do compilador (n&#237;vel 1) C4561 | Microsoft Docs"
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
  - "C4561"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4561"
ms.assetid: 3a10c12c-601b-4b6c-9861-331fd022e021
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4561
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“\_\_fastcall” incompatível com a opção de “\/clr”: ao converter “\_\_stdcall”  
  
 A convenção da chamada de função de [\_\_fastcall](../../cpp/fastcall.md) não pode ser usada com a opção do compilador de [\/clr](../../build/reference/clr-common-language-runtime-compilation.md) .  O compilador ignora as chamadas a `__fastcall`.  Para corrigir esse aviso, remover chamadas a **\_\_fastcall** ou criá\-las sem **\/clr**.  
  
 O seguinte exemplo gera C4561:  
  
```  
// C4561.cpp  
// compile with: /clr /W1 /c  
// processor: x86  
void __fastcall Func(void *p);   // C4561, remove __fastcall to resolve  
```