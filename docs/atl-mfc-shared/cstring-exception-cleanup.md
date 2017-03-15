---
title: "Limpeza de exce&#231;&#227;o de CString | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Objetos de CString, exceções"
  - "tratamento de exceção, código de limpeza"
ms.assetid: 28b9ce70-be63-4a0d-92a8-44bbfbc95e83
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Limpeza de exce&#231;&#227;o de CString
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em versões anteriores MFC, é importante que você faz após o uso de objetos de [CString](../atl-mfc-shared/reference/cstringt-class.md) .  Com versão MFC 3,0 e posterior, a limpeza explícita não é mais necessário.  
  
 Sob o mecanismo de manipulação de exceção C\+\+ que o MFC agora usa, você não tem que se preocupar na limpeza após uma exceção.  Para obter uma descrição de como C\+\+ “” desenrola a pilha depois que uma exceção é detectada, consulte [a tentativa, a captura, e as instruções throw](../cpp/try-throw-and-catch-statements-cpp.md).  Mesmo se você usar macros MFC **TRY**\/**CATCH** em vez de **try** palavra\-chave e **catch**C\+\+, o MFC usa o mecanismo de exceção C\+\+ abaixo, portanto você ainda não precisa limpar explicitamente.  
  
## Consulte também  
 [Cadeias de caracteres](../atl-mfc-shared/strings-atl-mfc.md)   
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)