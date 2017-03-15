---
title: "// Coment&#225;rio sobre substitu&#237;veis | Microsoft Docs"
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
  - "comentários, MFC"
  - "Arquivos de origem MFC, Comentário sobre substituíveis"
  - "Comentário sobre substituíveis nos arquivos de origem MFC"
  - "substituição, Comentário sobre substituíveis nos arquivos de origem MFC"
ms.assetid: 8968dea5-0d94-451f-bcb2-991580e65ba2
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# // Coment&#225;rio sobre substitu&#237;veis
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A seção de `// Overridables` de uma declaração de classe de MFC contém as funções virtuais que você pode substituir em uma classe derivada quando você precisar alterar o comportamento da classe base.  São nomeados geralmente começar com " ON ", embora não é estritamente necessário.  As funções aqui são criadas para ser substituída, e geralmente implementam ou fornece alguma mídia “retorno de chamada” ou “gancho”. Normalmente, esses membros são protegidos.  
  
 Em MFC próprio, as funções virtuais puras são colocadas sempre nesta seção.  Uma função virtual pura em C\+\+ é um formulário:  
  
 `virtual void OnDraw( ) = 0;`  
  
 Na listagem de exemplo da classe `CStdioFile`, em [Um exemplo de comentários](../mfc/an-example-of-the-comments.md), a lista não inclui nenhuma seção de overridables.  Classe **CDocument**, por outro lado, listas aproximadamente 10 funções de membro substituível.  
  
 Em algumas classes, você também pode ver comentários `// Advanced Overridables`.  Essas são as funções que apenas os programadores experientes devem tentar substituir.  Você provavelmente nunca precisará substituições.  
  
> [!NOTE]
>  As convenções descritas neste artigo também funcionam, geralmente, para métodos e propriedades de automação \(anteriormente conhecido como a Automação OLE\).  Os métodos de automação são semelhantes às operações de MFC.  As propriedades de automação são semelhantes aos atributos de MFC.  Os eventos de automação \(suporte para controles ActiveX, anteriormente conhecido como controladores OLE\) são semelhantes às funções de membro substituível de MFC.  
  
## Consulte também  
 [Usando os arquivos de origem MFC](../Topic/Using%20the%20MFC%20Source%20Files.md)   
 [Um exemplo dos comentários](../mfc/an-example-of-the-comments.md)   
 [\/\/ Comentário da implementação](../mfc/decrement-implementation-comment.md)   
 [\/\/ Comentário sobre construtores](../mfc/decrement-constructors-comment.md)   
 [\/\/ Comentário sobre atributos](../Topic/--%20Attributes%20Comment.md)   
 [\/\/ Comentário sobre operações](../mfc/decrement-operations-comment.md)