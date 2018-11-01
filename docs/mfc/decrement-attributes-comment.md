---
title: -- Comentário atributos
ms.date: 11/04/2016
helpviewer_keywords:
- comments, Attributes
- Attributes comment in MFC source files
- MFC source files, Attributes comment
- public attributes comment
ms.assetid: 96388e11-42df-4994-aedf-decd152961a7
ms.openlocfilehash: 33ee18400e03b55a26c4ad17e8d1ba6853ccda88
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50486067"
---
# <a name="-attributes-comment"></a>// Comentário sobre atributos

O `// Attributes` seção de uma declaração de classe do MFC contém os atributos públicos (ou propriedades) do objeto. Normalmente, esses são variáveis de membro, ou funções de Get/Set. As funções de "Get" e "Set" podem ou não podem ser virtuais. As funções de "Get" são geralmente **const**, pois na maioria dos casos eles não têm efeitos colaterais. Esses membros são normalmente públicos; atributos protegidos e privados são normalmente encontrados na seção de implementação.

No exemplo de listagem da classe `CStdioFile`, sob [um exemplo dos comentários](../mfc/an-example-of-the-comments.md), a lista inclui uma variável de membro, *m_pStream*. Classe `CDC` lista quase 20 membros sob esse comentário.

> [!NOTE]
>  Classes de grande, como `CDC` e `CWnd`, pode ter muitos membros que simplesmente listar todos os atributos em um grupo que não agregam muito a clareza. Nesses casos, a biblioteca de classes usa outros comentários como cabeçalhos para delinear ainda mais os membros. Por exemplo, `CDC` usa `// Device-Context Functions`, `// Drawing Tool Functions`, `// Drawing Attribute Functions`e muito mais. Grupos que representam atributos seguirá a sintaxe normal descrita acima. Muitas classes OLE tem uma seção de implementação chamada `// Interface Maps`.

## <a name="see-also"></a>Consulte também

[Usando os arquivos de origem MFC](../mfc/using-the-mfc-source-files.md)<br/>
[Um exemplo dos comentários](../mfc/an-example-of-the-comments.md)<br/>
[Comentário da implementação](../mfc/decrement-implementation-comment.md)<br/>
[Comentário sobre construtores](../mfc/decrement-constructors-comment.md)<br/>
[Comentário sobre operações](../mfc/decrement-operations-comment.md)<br/>
[Comentário sobre substituíveis](../mfc/decrement-overridables-comment.md)

