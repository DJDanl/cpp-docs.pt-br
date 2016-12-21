---
title: "// Coment&#225;rio sobre construtores | Microsoft Docs"
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
  - "comentários, comentário sobre construtores"
  - "comentários, MFC"
  - "construtores [C++], declarando"
  - "comentário sobre construtores"
  - "declarações, construtores"
  - "declarando construtores, comentários de código"
  - "construtores de instância, comentários de código"
  - "Arquivos de origem MFC, Comentário sobre construtores"
ms.assetid: f400774e-ba85-49ed-85b7-70ef2f7dcb2b
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# // Coment&#225;rio sobre construtores
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A seção de `// Constructors` de uma declaração de classe \(MFC declara construtores no sentido C\+\+\) bem como as funções de inicialização necessárias para usar realmente o objeto.  Por exemplo, `CWnd::Create` está na seção dos construtores como antes de usar o objeto de `CWnd` , “deve ser totalmente” construído pela primeira chamada no construtor de C\+\+ e chamar a função de **Criar** .  Normalmente, esses membros são públicos.  
  
 Por exemplo, a classe `CStdioFile` tem três construtores, um dos quais é exibido na lista em [Um exemplo de comentários](../mfc/an-example-of-the-comments.md).  
  
## Consulte também  
 [Usando os arquivos de origem MFC](../Topic/Using%20the%20MFC%20Source%20Files.md)   
 [\/\/ Comentário da implementação](../mfc/decrement-implementation-comment.md)   
 [\/\/ Comentário sobre atributos](../Topic/--%20Attributes%20Comment.md)   
 [\/\/ Comentário sobre operações](../mfc/decrement-operations-comment.md)   
 [\/\/ Comentário sobre substituíveis](../mfc/decrement-overridables-comment.md)