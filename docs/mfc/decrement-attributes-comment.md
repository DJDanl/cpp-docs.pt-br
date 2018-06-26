---
title: – Atributos comentário | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- comments, Attributes
- Attributes comment in MFC source files
- MFC source files, Attributes comment
- public attributes comment
ms.assetid: 96388e11-42df-4994-aedf-decd152961a7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 44b34c2e2d22d0a0a2feb15f6bf2793b68dc7042
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36929563"
---
# <a name="-attributes-comment"></a>// Comentário sobre atributos
O `// Attributes` seção de uma declaração de classe MFC contém os atributos públicos (ou propriedades) do objeto. Normalmente, esses são variáveis de membro, ou funções de Get/Set. As funções de "Get" e "Set" podem ou não ser virtuais. As funções de "Get" normalmente são **const**, pois na maioria dos casos eles não têm efeitos colaterais. Esses membros são normalmente públicos; atributos protegidos e privados são geralmente encontrados na seção de implementação.  
  
 No exemplo a listagem da classe `CStdioFile`, em [um exemplo dos comentários](../mfc/an-example-of-the-comments.md), a lista inclui uma variável de membro, *m_pStream*. Classe `CDC` lista aproximadamente 20 membros sob esse comentário.  
  
> [!NOTE]
>  Classes de grande, como `CDC` e `CWnd`, pode ter muitos membros que simplesmente lista todos os atributos em um grupo não adicionaria muito para maior clareza. Nesses casos, a biblioteca de classes usa outros comentários como títulos para delimitar ainda mais os membros. Por exemplo, `CDC` usa `// Device-Context Functions`, `// Drawing Tool Functions`, `// Drawing Attribute Functions`e muito mais. Grupos que representam atributos seguirá a sintaxe normal descrita acima. Muitas classes OLE tem uma seção de implementação chamada `// Interface Maps`.  
  
## <a name="see-also"></a>Consulte também  
 [Usando os arquivos de origem MFC](../mfc/using-the-mfc-source-files.md)   
 [Um exemplo dos comentários](../mfc/an-example-of-the-comments.md)   
 [Comentário de implementação](../mfc/decrement-implementation-comment.md)   
 [Construtores de comentário](../mfc/decrement-constructors-comment.md)   
 [Comentário sobre operações](../mfc/decrement-operations-comment.md)   
 [Comentário sobre substituíveis](../mfc/decrement-overridables-comment.md)

