---
title: "STACKSIZE | Microsoft Docs"
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
  - "STACKSIZE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "instrução de arquivo .def STACKSIZE"
ms.assetid: 4d8c79bd-1cb4-4e4d-90f2-b5a7a4d20e7a
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# STACKSIZE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define o tamanho da pilha, em bytes.  
  
```  
STACKSIZE reserve[,commit]  
```  
  
## Comentários  
 Uma maneira de definir equivalente a pilha é com o padrão de [Alocações de pilhas](../../build/reference/stack-stack-allocations.md) \(\/STACK\).  Consulte a documentação nessa opção para obter detalhes sobre *a reserva* e os argumentos de `commit` .  
  
 Essa opção não tem efeito na DLL.  
  
## Consulte também  
 [Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)