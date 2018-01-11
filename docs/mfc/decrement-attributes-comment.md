---
title: "– Atributos comentário | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- comments, Attributes
- Attributes comment in MFC source files
- MFC source files, Attributes comment
- public attributes comment
ms.assetid: 96388e11-42df-4994-aedf-decd152961a7
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 18a142cc0434e0e09e69d9bffc30826c461cf185
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="-attributes-comment"></a>// Comentário sobre atributos
O `// Attributes` seção de uma declaração de classe MFC contém os atributos públicos (ou propriedades) do objeto. Normalmente, esses são variáveis de membro, ou funções de Get/Set. As funções de "Get" e "Set" podem ou não ser virtuais. As funções de "Get" normalmente são **const**, pois na maioria dos casos eles não têm efeitos colaterais. Esses membros são normalmente públicos; atributos protegidos e privados são geralmente encontrados na seção de implementação.  
  
 No exemplo a listagem da classe `CStdioFile`, em [um exemplo dos comentários](../mfc/an-example-of-the-comments.md), a lista inclui uma variável de membro, `m_pStream`. Classe `CDC` lista aproximadamente 20 membros sob esse comentário.  
  
> [!NOTE]
>  Classes de grande, como `CDC` e `CWnd`, pode ter muitos membros que simplesmente lista todos os atributos em um grupo não adicionaria muito para maior clareza. Nesses casos, a biblioteca de classes usa outros comentários como títulos para delimitar ainda mais os membros. Por exemplo, `CDC` usa `// Device-Context Functions`, `// Drawing Tool Functions`, `// Drawing Attribute Functions`e muito mais. Grupos que representam atributos seguirá a sintaxe normal descrita acima. Muitas classes OLE tem uma seção de implementação chamada `// Interface Maps`.  
  
## <a name="see-also"></a>Consulte também  
 [Usando os arquivos de origem MFC](../mfc/using-the-mfc-source-files.md)   
 [Um exemplo dos comentários](../mfc/an-example-of-the-comments.md)   
 [Comentário de implementação](../mfc/decrement-implementation-comment.md)   
 [Construtores de comentário](../mfc/decrement-constructors-comment.md)   
 [Comentário sobre operações](../mfc/decrement-operations-comment.md)   
 [Comentário sobre substituíveis](../mfc/decrement-overridables-comment.md)

