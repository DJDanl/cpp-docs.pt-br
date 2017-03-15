---
title: "Restri&#231;&#245;es em manipuladores de exce&#231;&#227;o | Microsoft Docs"
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
  - "restrições, manipuladores de exceção"
ms.assetid: 31d63524-0e8c-419f-b87c-061f4c0ea470
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Restri&#231;&#245;es em manipuladores de exce&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A principal limitação do uso de manipuladores de exceção no código é que você não pode usar uma instrução `goto` para ir diretamente para um bloco de instruções `__try`.  Em vez disso, você deve digitar o bloco de instruções por meio do fluxo de controle normal.  Você pode sair de um bloco de instruções `__try` e aninhar manipuladores de exceção como quiser.  
  
## Consulte também  
 [Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)   
 [Tratamento de exceções estruturado](../cpp/structured-exception-handling-c-cpp.md)