---
title: – Comentário sobre substituíveis de | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Overridables comment in MFC source files
- MFC source files, Overridables comment
- overriding, Overridables comment in MFC source files
- comments, MFC
ms.assetid: 8968dea5-0d94-451f-bcb2-991580e65ba2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6a1b9b04647717fc5892421f2b45947ebd079a0c
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36928721"
---
# <a name="-overridables-comment"></a>// Comentário sobre substituíveis
O `// Overridables` seção de uma declaração de classe MFC contém funções virtuais que pode ser substituído em uma classe derivada quando você precisa modificar o comportamento da classe base. Elas geralmente são nomeadas começando com "On", embora não seja estritamente necessária. Funções são projetadas para ser substituído e geralmente implementar ou fornecer algum tipo de "retorno de chamada" ou "conectar". Normalmente, esses membros são protegidos.  
  
 Em MFC em si, funções virtuais puras sempre são colocadas nesta seção. Uma função virtual pura em C++ é um do formulário:  
  
 `virtual void OnDraw( ) = 0;`  
  
 No exemplo a listagem da classe `CStdioFile`, na [um exemplo dos comentários](../mfc/an-example-of-the-comments.md), a lista não inclui nenhuma seção sobre substituíveis. Classe `CDocument`, por outro lado, lista aproximadamente 10 funções de membro substituíveis.  
  
 Em algumas classes, você também poderá ver o comentário `// Advanced Overridables`. Essas são funções avançadas apenas programadores devem tentar substituir. Provavelmente nunca será necessário substituí-los.  
  
> [!NOTE]
>  As convenções descritas neste artigo também funcionam bem, em geral, propriedades e métodos de automação (anteriormente conhecido como automação OLE). Métodos de automação são semelhantes às operações do MFC. Propriedades de automação são semelhantes aos atributos do MFC. Eventos de automação (suportados para controles ActiveX, anteriormente conhecidos como controles OLE) são semelhantes às funções de membro substituível do MFC.  
  
## <a name="see-also"></a>Consulte também  
 [Usando os arquivos de origem MFC](../mfc/using-the-mfc-source-files.md)   
 [Um exemplo dos comentários](../mfc/an-example-of-the-comments.md)   
 [Comentário de implementação](../mfc/decrement-implementation-comment.md)   
 [Construtores de comentário](../mfc/decrement-constructors-comment.md)   
 [Comentário sobre atributos](../mfc/decrement-attributes-comment.md)   
 [Comentário sobre operações](../mfc/decrement-operations-comment.md)

