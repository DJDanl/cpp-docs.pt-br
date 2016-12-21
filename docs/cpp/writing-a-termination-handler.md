---
title: "Escrevendo um manipulador de t&#233;rmino | Microsoft Docs"
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
  - "tratamento de exceção, manipuladores de encerramento"
  - "exceções, encerrando"
  - "manipuladores"
  - "manipuladores, encerramento"
  - "tratamento estruturado de exceções, manipuladores de encerramento"
  - "manipuladores de encerramento"
  - "manipuladores de encerramento, gravando"
  - "palavra-chave try-catch [C++], manipuladores de encerramento"
ms.assetid: 52aa1f8f-f8dd-44b8-be94-5e2fc88d44fb
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Escrevendo um manipulador de t&#233;rmino
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Diferente de um manipulador de exceção, um manipulador de término sempre é executado, independentemente do bloco de código protegido encerrado normalmente.  O único propósito do manipulador de término deve ser garantir que os recursos, como memória, identificadores e arquivos, sejam fechados corretamente, independentemente de como uma seção de código termina a execução.  
  
 Os manipuladores de término usam a instrução try\-finally.  
  
## Que mais você deseja saber?  
  
-   [A instrução try\-finally](../cpp/try-finally-statement.md)  
  
-   [Limpando recursos](../cpp/cleaning-up-resources.md)  
  
-   [Controle de tempo de ações no tratamento de exceções](../cpp/timing-of-exception-handling-a-summary.md)  
  
-   [Restrições de manipuladores de término](../cpp/restrictions-on-termination-handlers.md)  
  
## Consulte também  
 [Tratamento de exceções estruturado](../cpp/structured-exception-handling-c-cpp.md)