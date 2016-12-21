---
title: "Escrevendo um manipulador de exce&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tratamento de exceção, manipuladores de exceção"
  - "tratamento estruturado de exceções, manipuladores de exceção"
ms.assetid: 71473fee-f773-4a34-bf12-82a3af79579c
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Escrevendo um manipulador de exce&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Normalmente, os manipuladores de exceções são usados para responder a erros específicos.  Você pode usar a sintaxe de manipulação de exceções para filtrar todas as exceções que não sejam aquelas que você sabe tratar.  Outras exceções devem ser passadas para outros manipuladores \(possivelmente na biblioteca em tempo de execução ou no sistema operacional\) criados para procurar essas exceções específicas.  
  
 Os manipuladores de exceções usam a instrução try\-except.  
  
## Que mais você deseja saber?  
  
-   [A instrução try\-except](../cpp/try-except-statement.md)  
  
-   [Escrevendo um filtro de exceção](../cpp/writing-an-exception-filter.md)  
  
-   [Acionando exceções de software](../cpp/raising-software-exceptions.md)  
  
-   [Exceções de hardware](../cpp/hardware-exceptions.md)  
  
-   [Restrições em manipuladores de exceções](../cpp/restrictions-on-exception-handlers.md)  
  
## Consulte também  
 [Tratamento de exceções estruturado](../cpp/structured-exception-handling-c-cpp.md)