---
title: "Exce&#231;&#245;es: exce&#231;&#245;es em construtores | Microsoft Docs"
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
  - "construtores [C++], exceções"
  - "exceções, em construtores"
  - "lançando exceções, em construtores"
ms.assetid: a78eae5a-5821-4b27-9478-1436320ed1e1
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exce&#231;&#245;es: exce&#231;&#245;es em construtores
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ao gerar uma exceção em um construtor, limpe o que objetos e alocações de memória antes de você fazer lançar exceção, como explicado em [Exceções: Lançando exceções de suas próprias funções](../mfc/exceptions-throwing-exceptions-from-your-own-functions.md).  
  
 Ao gerar uma exceção em um construtor, a memória para o objeto própria já tiver sido atribuído antes que o construtor é chamado.  Assim, o compilador desalocará automaticamente a memória ocupada pelo objeto depois que a exceção é gerada.  
  
 Para obter mais informações, consulte [Exceções: Liberando objetos nas exceções](../Topic/Exceptions:%20Freeing%20Objects%20in%20Exceptions.md).  
  
## Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)