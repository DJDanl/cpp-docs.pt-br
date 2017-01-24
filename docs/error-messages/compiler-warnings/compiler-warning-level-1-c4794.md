---
title: "Compilador C4794 de aviso (n&#237;vel 1) | Microsoft Docs"
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
  - "C4794"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4794"
ms.assetid: badc9c36-fa1a-4fec-929b-7bfda7a7b79f
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4794 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

segmento da variável de armazenamento local de thread 'variável' alterado de 'nome da seção' para '.tls$ '  
  
 Você usou [\#pragma data\_seg](../../preprocessor/data-seg.md) colocar uma variável tls em uma seção que não começa com .tls$.  
  
 O $ .tls*x* seção continuará a existir no arquivo de objeto onde [\_\_declspec\(thread\)](../../cpp/thread.md) variáveis são definidas. Uma seção .tls no arquivo EXE ou DLL resultarão essas seções.  
  
## Exemplo  
 O exemplo a seguir gera C4794:  
  
```  
// C4794.cpp // compile with: /W1 /c #pragma data_seg(".someseg") __declspec(thread) int i;   // C4794 // OK #pragma data_seg(".tls$9") __declspec(thread) int j;  
```