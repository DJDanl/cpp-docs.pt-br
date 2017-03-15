---
title: "// Coment&#225;rio sobre opera&#231;&#245;es | Microsoft Docs"
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
  - "Arquivos de origem MFC, Comentários sobre operações"
  - "Comentário sobre operações nos arquivos de origem MFC"
ms.assetid: f3bff48d-26be-4db6-8435-9e4d079838c9
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# // Coment&#225;rio sobre opera&#231;&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A seção de `// Operations` de uma declaração de classe de MFC contém funções de membro que você pode chamar o objeto para o fazer coisas ou executar ações executar operações \(\).  Essas funções são**const** normalmente não porque normalmente têm efeitos colaterais.  Podem ser virtuais ou nonvirtual dependendo das necessidades da classe.  Normalmente, esses membros são públicos.  
  
 Na listagem de exemplo da classe `CStdioFile`, em [Um exemplo de comentários](../mfc/an-example-of-the-comments.md), a lista inclui duas funções de membro nesse comentário: `ReadString` e `WriteString`.  
  
 Como com atributos, as operações podem mais ser subdivididas.  
  
## Consulte também  
 [Usando os arquivos de origem MFC](../Topic/Using%20the%20MFC%20Source%20Files.md)   
 [Um exemplo dos comentários](../mfc/an-example-of-the-comments.md)   
 [\/\/ Comentário da implementação](../mfc/decrement-implementation-comment.md)   
 [\/\/ Comentário sobre construtores](../mfc/decrement-constructors-comment.md)   
 [\/\/ Comentário sobre atributos](../Topic/--%20Attributes%20Comment.md)   
 [\/\/ Comentário sobre substituíveis](../mfc/decrement-overridables-comment.md)