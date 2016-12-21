---
title: "Operadores de convers&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "index-page "
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "operadores de conversão"
  - "operadores [C++], conversão"
ms.assetid: 16240348-26bc-4f77-8eab-57253f00ce52
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores de convers&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Há vários operadores de conversão específicos à linguagem C\+\+.  Esses operadores são destinados a remover qualquer ambiguidade e perigo inerente no estilo antigo de conversões da linguagem C.  Esses operadores são:  
  
-   [dynamic\_cast](../cpp/dynamic-cast-operator.md) Usado para a conversão de tipos polimórficos.  
  
-   [static\_cast](../cpp/static-cast-operator.md) Usado para a conversão de tipos não polimórficos.  
  
-   [const\_cast](../Topic/const_cast%20Operator.md) Usado para remover os atributos `const`, `volatile` e `__unaligned`.  
  
-   [reinterpret\_cast](../cpp/reinterpret-cast-operator.md) Usado para a reinterpretação simples de bits.  
  
-   [safe\_cast](../windows/safe-cast-cpp-component-extensions.md) Usado para produzir MSIL verificável.  
  
 Use `const_cast` e `reinterpret_cast` como último recurso, pois esses operadores apresentam os mesmos perigos das conversões antigas.  No entanto, ainda são necessários para substituir completamente as conversões antigas.  
  
## Consulte também  
 [Conversão](../cpp/casting.md)