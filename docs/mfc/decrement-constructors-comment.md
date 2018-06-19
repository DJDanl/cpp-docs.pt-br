---
title: – Comentário construtores | Microsoft Docs
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
ms.openlocfilehash: 71b78e74b4b8d974fceaf5f854c9890cd7cdd1a1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33344159"
---
# <a name="-constructors-comment"></a>// Comentário sobre construtores
O `// Constructors` seção de uma declaração de classe MFC declara construtores (no sentido de C++), bem como quaisquer funções de inicialização necessárias para realmente usar o objeto. Por exemplo, `CWnd::Create` está na seção de construtores porque antes de usar o `CWnd` do objeto, ele deve ser "totalmente construído" primeiro chamando o construtor de C++ e, em seguida, chamar o **criar** função. Normalmente, esses membros são públicos.  
  
 Por exemplo, a classe `CStdioFile` tem três construtores, um dos quais é mostrado na listagem em [um exemplo dos comentários](../mfc/an-example-of-the-comments.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando os arquivos de origem MFC](../mfc/using-the-mfc-source-files.md)   
 [Comentário de implementação](../mfc/decrement-implementation-comment.md)   
 [Comentário sobre atributos](../mfc/decrement-attributes-comment.md)   
 [Comentário sobre operações](../mfc/decrement-operations-comment.md)   
 [Comentário sobre substituíveis](../mfc/decrement-overridables-comment.md)

