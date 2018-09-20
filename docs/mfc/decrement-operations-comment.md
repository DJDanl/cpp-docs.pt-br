---
title: – Comentário sobre operações | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Operations comment in MFC source files
- comments, MFC
- MFC source files, Operations comments
ms.assetid: f3bff48d-26be-4db6-8435-9e4d079838c9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 73c4a7a70c9f2ed987337426793bd462c2a94309
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46372490"
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

