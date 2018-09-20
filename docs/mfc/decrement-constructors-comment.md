---
title: – Comentário sobre construtores | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f03a65c3f870b1e7648f03b70efe7242c35a21f9
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46429342"
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

