---
title: – Comentário sobre operações
ms.date: 11/04/2016
helpviewer_keywords:
- Operations comment in MFC source files
- comments, MFC
- MFC source files, Operations comments
ms.assetid: f3bff48d-26be-4db6-8435-9e4d079838c9
ms.openlocfilehash: 7e4d0549d3d77916df532f105dc58ed9e9f78af2
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57326186"
---
# <a name="-operations-comment"></a>// Comentário sobre operações

O `// Operations` seção de uma declaração de classe do MFC contém funções de membro que você pode chamar o objeto para torná-lo a fazer coisas ou executar ações (executar operações). Essas funções são normalmente não -**const** porque eles geralmente têm efeitos colaterais. Eles podem ser virtual ou não virtuais dependendo das necessidades da classe. Normalmente, esses membros são públicos.

No exemplo de listagem da classe `CStdioFile`, na [um exemplo dos comentários](../mfc/an-example-of-the-comments.md), a lista inclui duas funções de membro sob esse comentário: `ReadString` e `WriteString`.

Assim como acontece com atributos, operações podem ser mais subdivididas.

## <a name="see-also"></a>Consulte também

[Usando os arquivos de origem MFC](../mfc/using-the-mfc-source-files.md)<br/>
[Um exemplo dos comentários](../mfc/an-example-of-the-comments.md)<br/>
[Comentário da implementação](../mfc/decrement-implementation-comment.md)<br/>
[Comentário sobre construtores](../mfc/decrement-constructors-comment.md)<br/>
[Comentário sobre atributos](../mfc/decrement-attributes-comment.md)<br/>
[Comentário sobre substituíveis](../mfc/decrement-overridables-comment.md)
