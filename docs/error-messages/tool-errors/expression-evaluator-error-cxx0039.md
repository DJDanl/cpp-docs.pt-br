---
title: "Erro CXX0039 (avaliador de express&#227;o) | Microsoft Docs"
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
  - "CXX0039"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CAN0039"
  - "CXX0039"
ms.assetid: 8bf698d2-e015-4595-944f-72b81aa43d22
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro CXX0039 (avaliador de express&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o símbolo é ambíguo  
  
 O avaliador de expressão C não pode determinar a instância de um símbolo a serem usados em uma expressão.  O símbolo ocorrer mais de uma vez na árvore de herança.  
  
 Você deve usar o operador de resolução de escopo \(`::`\) para especificar explicitamente a instância a ser usado na expressão.  
  
 Esse erro é idêntico a CAN0039.