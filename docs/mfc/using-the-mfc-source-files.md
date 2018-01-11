---
title: Arquivos de origem usando o MFC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
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
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 930c205ffd690c190f68766f7a51c83b68ef8d2f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-the-mfc-source-files"></a>Usando os arquivos de origem MFC
A biblioteca Microsoft Foundation Class (MFC) fornece o código-fonte completo. Arquivos de cabeçalho (. h) estão no diretório \atlmfc\include; arquivos de implementação (. cpp) estão no diretório \atlmfc\src\mfc.  
  
 Essa família de artigos explica as convenções de MFC usa comentários de várias partes de cada classe, o que significam esses comentários e o que você deve esperar encontrar cada seção. Os assistentes do Visual C++ usam convenções semelhantes para as classes que foram criadas para você, e você provavelmente encontrará essas convenções úteis para seu próprio código.  
  
 Você pode estar familiarizado com o **pública**, `protected`, e `private` palavras-chave C++. Ao examinar os arquivos de cabeçalho MFC, você descobrirá que cada classe pode ter vários deles. Por exemplo, funções e variáveis de membro público podem ser em mais de um **pública** palavra-chave. Isso ocorre porque o MFC separa variáveis de membro e funções com base no uso, não por tipo de acesso permitido. MFC usa `private` moderadamente; itens mesmo consideraram detalhes de implementação geralmente são protegidos e muitas vezes são públicos. Embora o acesso a detalhes de implementação não é recomendado, MFC deixa a decisão para você.  
  
 Os arquivos de origem MFC e os arquivos que o Assistente de aplicativo MFC cria, você encontrará comentários como essas dentro de declarações de classe (geralmente nessa ordem):  
  
 `// Constructors`  
  
 `// Attributes`  
  
 `// Operations`  
  
 `// Overridables`  
  
 `// Implementation`  
  
 Os tópicos abordados nesta família de artigos incluem:  
  
-   [Um exemplo dos comentários](../mfc/an-example-of-the-comments.md)  
  
-   [O / / comentário da implementação](../mfc/decrement-implementation-comment.md)  
  
-   [O / / comentário sobre construtores](../mfc/decrement-constructors-comment.md)  
  
-   [O / / comentário de atributos](../mfc/decrement-attributes-comment.md)  
  
-   [O / / comentário sobre operações](../mfc/decrement-operations-comment.md)  
  
-   [O / / comentário sobre substituíveis](../mfc/decrement-overridables-comment.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tópicos gerais do MFC](../mfc/general-mfc-topics.md)

