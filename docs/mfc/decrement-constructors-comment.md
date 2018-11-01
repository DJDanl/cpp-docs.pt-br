---
title: – Comentário sobre construtores
ms.date: 11/04/2016
helpviewer_keywords:
- constructors comment
- declarations, constructors
- MFC source files, Constructors comment
- declaring constructors, code comments
- comments, MFC
- comments, constructors comment
- constructors [MFC], declaring
- instance constructors, code comments
ms.assetid: f400774e-ba85-49ed-85b7-70ef2f7dcb2b
ms.openlocfilehash: ee36ad991f2a19211b494010d6ff0a5338b80557
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50480698"
---
# <a name="-constructors-comment"></a>// Comentário sobre construtores

O `// Constructors` seção de uma declaração de classe MFC declara construtores (no sentido de C++), bem como quaisquer funções de inicialização necessárias para realmente usar o objeto. Por exemplo, `CWnd::Create` está na seção construtores porque antes de usar o `CWnd` do objeto, ele deve ser "totalmente construído" primeiro chamar o construtor de C++ e, em seguida, chamando o `Create` função. Normalmente, esses membros são públicos.

Por exemplo, a classe `CStdioFile` tem três construtores, um dos quais é mostrado na listagem em [um exemplo dos comentários](../mfc/an-example-of-the-comments.md).

## <a name="see-also"></a>Consulte também

[Usando os arquivos de origem MFC](../mfc/using-the-mfc-source-files.md)<br/>
[Comentário da implementação](../mfc/decrement-implementation-comment.md)<br/>
[Comentário sobre atributos](../mfc/decrement-attributes-comment.md)<br/>
[Comentário sobre operações](../mfc/decrement-operations-comment.md)<br/>
[Comentário sobre substituíveis](../mfc/decrement-overridables-comment.md)

