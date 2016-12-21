---
title: "_CRTDBG_MAP_ALLOC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CRTDBG_MAP_ALLOC"
  - "_CRTDBG_MAP_ALLOC"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Macro _CRTDBG_MAP_ALLOC"
  - "alocação de memória, em compilações de depuração"
  - "Macro CRTDBG_MAP_ALLOC"
ms.assetid: 435242b8-caea-4063-b765-4a608200312b
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CRTDBG_MAP_ALLOC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando o sinalizador de **\_CRTDBG\_MAP\_ALLOC** é definido na versão de depuração de um aplicativo, a versão de base das funções de heap será mapeada diretamente para suas versões de depuração.  O sinalizador é usado em Crtdbg.h para fazer o mapeamento.  Esse sinalizador está disponível apenas quando o sinalizador de [\_DEBUG](../Topic/_DEBUG.md) foi definido no aplicativo.  
  
 Para obter mais informações sobre como usar a versão de depuração em relação à versão de base de uma função de heap, consulte [Usando a versão de depuração em relação à versão de base](../Topic/Debug%20Versions%20of%20Heap%20Allocation%20Functions.md).  
  
## Consulte também  
 [Sinalizadores de controle](../c-runtime-library/control-flags.md)