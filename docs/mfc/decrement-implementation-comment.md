---
title: "// Coment&#225;rio da implementa&#231;&#227;o | Microsoft Docs"
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
  - "comentários, Comentários de implementação"
  - "comentários, MFC"
  - "Comentário de implementação nos arquivos de origem MFC"
  - "Arquivos de origem MFC, Comentário da implementação"
ms.assetid: 4d799c07-8e71-4a6b-90ab-8282d6ff48ce
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# // Coment&#225;rio da implementa&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A seção de `// Implementation` é a parte mais importante de qualquer declaração de classe de MFC.  
  
 Casas desta seção todos os detalhes de implementação.  As variáveis e funções do membro podem aparecer nesta seção.  Tudo nessa linha pode ser alterado em uma versão futura de MFC.  A menos que você não pode impedir o, você não deve confiar em detalhes abaixo da linha de `// Implementation` .  Além disso, os membros declarados abaixo da linha de implementação não estão documentados, embora qualquer implementação é discutida em observações técnicas.  As substituições de funções virtuais na classe base residem nesta seção, independentemente de qual a seção a função da classe base é definida no, porque o fato de que uma função substitui a implementação da classe base é considerado um detalhes de implementação.  Normalmente, esses membros são protegidos, mas nem sempre.  
  
 Aviso de que lista `CStdioFile` em [Um exemplo de comentários](../mfc/an-example-of-the-comments.md) que os membros declarados abaixo de `// Implementation` podem ser declaradas como **public**, `protected`, ou `private`.  Você só deve usar esses membros com cuidado, pois podem ser alteradas no futuro.  Declare um grupo de membros como **public** pode ser necessário para que a implementação da biblioteca de classes funcione corretamente.  No entanto, isso não significa que você pode usar com segurança os membros declarados isso.  
  
> [!NOTE]
>  Você pode localizar os comentários dos tipos restantes acima ou abaixo de `// Implementation` .  Em ambos os casos, descrevem os tipos de membros declarados neles.  Se ocorrerem abaixo de `// Implementation` , você deve pressupor que os membros podem mudar em versões futuras de MFC.  
  
## Consulte também  
 [Usando os arquivos de origem MFC](../Topic/Using%20the%20MFC%20Source%20Files.md)   
 [Um exemplo dos comentários](../mfc/an-example-of-the-comments.md)   
 [\/\/ Comentário sobre construtores](../mfc/decrement-constructors-comment.md)   
 [\/\/ Comentário sobre atributos](../Topic/--%20Attributes%20Comment.md)   
 [\/\/ Comentário sobre operações](../mfc/decrement-operations-comment.md)   
 [\/\/ Comentário sobre substituíveis](../mfc/decrement-overridables-comment.md)