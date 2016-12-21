---
title: "Gerenciamento de mem&#243;ria: aloca&#231;&#227;o do heap | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador delete, usando com MFC de depuração"
  - "detectando perdas de memória"
  - "alocação de heap"
  - "alocação de heap, descrito"
  - "alocação de memória, memória heap"
  - "perdas de memória, detectando"
  - "memória, detectando perdas"
  - "Operador new, usando com MFC de depuração"
ms.assetid: a5d949c6-1b79-476e-9c66-513a558203d9
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Gerenciamento de mem&#243;ria: aloca&#231;&#227;o do heap
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O heap é reservado para as necessidades de alocação de memória do programa.  É uma área independentemente do código de programa e de pilha.  Os programas de 2.0 c típicos usam as funções `malloc` e **free** o aloque e desaloque a memória heap.  A versão de depuração MFC fornece versões alteradas dos operadores internos **new** e **delete** C\+\+ o aloque e desaloque objetos na memória heap.  
  
 Quando você usa **new** e **delete** em vez de `malloc` e de **free**, você pode aproveitar os aprimoramentos de depuração de gerenciamento de memória da biblioteca de classe, que podem ser úteis para detectar possíveis vazamentos de memória.  Quando você cria seu programa com a versão lançada de MFC, as versões padrão dos operadores de **new** e de **delete** fornecem uma maneira eficiente de aloque e desaloque a memória \(a versão lançada de MFC não fornece modificadas versões destes operadores\).  
  
 Observe que o tamanho total dos objetos alocados no heap é limitado apenas pela memória virtual disponível do sistema.  
  
## Consulte também  
 [Gerenciamento de memória](../mfc/memory-management.md)