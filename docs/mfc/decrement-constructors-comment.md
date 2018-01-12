---
title: "– Comentário construtores | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
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
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1f6425252df34936d4ba3c9013664205b0038d82
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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

