---
title: Usando os arquivos de origem MFC
ms.date: 11/04/2016
helpviewer_keywords:
- public members
- source files
- MFC, source files
- MFC source files
- comments, MFC
- private member access
- protected member access
- source files, MFC
ms.assetid: 3230e8fb-3b69-4ddf-9538-365ac7ea5e72
ms.openlocfilehash: 6f23f792f750e4352494bf3e4bde08f0fe360439
ms.sourcegitcommit: db1ed91fa7451ade91c3fb76bc7a2b857f8a5eef
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/13/2019
ms.locfileid: "68980485"
---
# <a name="using-the-mfc-source-files"></a>Usando os arquivos de origem MFC

A biblioteca do MFC (Microsoft Foundation Class) fornece código-fonte completo. Os arquivos de cabeçalho (. h) estão no diretório \atlmfc\include; os arquivos de implementação (. cpp) estão no diretório \atlmfc\src\mfc

Esta família de artigos explica as convenções que o MFC usa para comentar as várias partes de cada classe, o que significam esses comentários e o que você deve esperar encontrar em cada seção. Os assistentes visuais C++ usam convenções semelhantes para as classes que criam para você, e você provavelmente encontrará essas convenções úteis para seu próprio código.

Você pode estar familiarizado com as palavras-chave **pública**, **protegida**e **privada** C++ . Nos arquivos de cabeçalho do MFC, você encontrará que cada classe pode ter vários deles. Por exemplo, variáveis de membro público e funções podem estar em mais de uma palavra-chave **pública** . É porque o MFC separa variáveis de membro e funções com base em seu uso, não pelo tipo de acesso permitido. O MFC usa de forma moderada. Até mesmo os itens considerados detalhes de implementação geralmente são **protegidos**e muitas vezes são **públicos**. Embora o acesso aos detalhes da implementação seja desencorajado, o MFC deixa a decisão para você.

Nos arquivos de origem do MFC e nos arquivos de cabeçalho criados pelo assistente de aplicativo do MFC, você encontrará comentários como esses dentro de declarações de classe (geralmente nesta ordem):

`// Constructors`

`// Attributes`

`// Operations`

`// Overridables`

`// Implementation`

Os tópicos abordados nesta família de artigos incluem:

- [Um exemplo dos comentários](../mfc/an-example-of-the-comments.md)

- [O comentário de implementação//](../mfc/decrement-implementation-comment.md)

- [O comentário de construtores//](../mfc/decrement-constructors-comment.md)

- [O comentário de atributos//](../mfc/decrement-attributes-comment.md)

- [O comentário de operações//](../mfc/decrement-operations-comment.md)

- [O comentário//Overridables](../mfc/decrement-overridables-comment.md)

## <a name="see-also"></a>Consulte também

[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)
