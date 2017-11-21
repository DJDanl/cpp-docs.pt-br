---
title: "– Comentário sobre operações | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Operations comment in MFC source files
- comments, MFC
- MFC source files, Operations comments
ms.assetid: f3bff48d-26be-4db6-8435-9e4d079838c9
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 63b3d7a313f0f725444ba77612d8b53280393640
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="-operations-comment"></a>// Comentário sobre operações
O `// Operations` seção de uma declaração de classe MFC contém funções de membro que você pode chamar o objeto para torná-lo a realizar tarefas ou executar ações (operações). Essas funções são normalmente não -**const** porque eles normalmente têm efeitos colaterais. Eles podem ser virtual ou não, dependendo das necessidades da classe. Normalmente, esses membros são públicos.  
  
 No exemplo a listagem da classe `CStdioFile`, na [um exemplo dos comentários](../mfc/an-example-of-the-comments.md), a lista inclui duas funções de membro sob este comentário: `ReadString` e `WriteString`.  
  
 Assim como acontece com atributos, operações podem ser mais subdivididas.  
  
## <a name="see-also"></a>Consulte também  
 [Usando os arquivos de origem MFC](../mfc/using-the-mfc-source-files.md)   
 [Um exemplo dos comentários](../mfc/an-example-of-the-comments.md)   
 [Comentário de implementação](../mfc/decrement-implementation-comment.md)   
 [Construtores de comentário](../mfc/decrement-constructors-comment.md)   
 [Comentário sobre atributos](../mfc/decrement-attributes-comment.md)   
 [Comentário sobre substituíveis](../mfc/decrement-overridables-comment.md)

