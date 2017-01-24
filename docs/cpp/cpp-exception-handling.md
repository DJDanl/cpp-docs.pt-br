---
title: "Tratamento de exce&#231;&#245;es C++ | Microsoft Docs"
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
  - "tratamento de exceção de C++"
  - "Visual C++, tratamento de exceção"
ms.assetid: 65f80b44-9d0f-4d17-b910-07205a5c5c40
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tratamento de exce&#231;&#245;es C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A linguagem C\+\+ fornece suporte interno para lançamento e captura de exceções.  Ao programar em C\+\+, você quase sempre deve usar o suporte interno à exceção C\+\+, conforme descrito nesta seção.  
  
 Para habilitar o tratamento de exceções C\+\+ em seu código, use [\/EHsc](../build/reference/eh-exception-handling-model.md).  
  
## Nesta seção  
 Esta discussão sobre tratamento de exceções C\+\+ inclui:  
  
-   [As instruções try, catch e throw](../cpp/try-throw-and-catch-statements-cpp.md)  
  
-   [Como os blocos catch são avaliados](../Topic/How%20Catch%20Blocks%20are%20Evaluated%20\(C++\).md)  
  
-   [Desenrolando exceções e pilha](../cpp/exceptions-and-stack-unwinding-in-cpp.md)  
  
-   [Especificações de exceção](../cpp/exception-specifications-throw-cpp.md)  
  
-   [noexcept](../Topic/noexcept%20\(C++\).md)  
  
-   [Exceções C\+\+ não tratadas](../cpp/unhandled-cpp-exceptions.md)  
  
-   [Combinação de exceções C \(Estruturada\) e C\+\+](../Topic/Mixing%20C%20\(Structured\)%20and%20C++%20Exceptions.md)  
  
## Suporte às exceções antigas do MFC  
 A partir da versão 4.0, a MFC começou a usar o mecanismo de tratamento de exceções C\+\+.  Embora você seja encorajado a usar o tratamento de exceções C\+\+ no novo código, o MFC versão 4.0 e posterior mantêm as macros das versões anteriores do MFC para que o código antigo não seja quebrado.  As macros e o novo mecanismo também podem ser combinados.  Para obter informações sobre como combinar macros e o tratamento de exceções C\+\+ e sobre como converter código antigo para usar o novo mecanismo, consulte os artigos [Exceções: usando macros do MFC e exceções C\+\+](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md) e [Exceções: fazendo conversões de macros de exceção do MFC](../mfc/exceptions-converting-from-mfc-exception-macros.md).  As macros de exceção mais antigas do MFC, se você ainda as usa, são avaliadas para palavras\-chave de exceção C\+\+.  Consulte [Exceções: alterações nas macros de exceção da versão 3.0](../mfc/exceptions-changes-to-exception-macros-in-version-3-0.md).  
  
## Consulte também  
 [Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md)