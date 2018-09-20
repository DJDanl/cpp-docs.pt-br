---
title: – Comentário da implementação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Implementation comment in MFC source files
- comments, MFC
- MFC source files, Implementation comment
- comments, Implementation comments
ms.assetid: 4d799c07-8e71-4a6b-90ab-8282d6ff48ce
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 874c7eb29f1908e6098ee4a9095f17a4dae00006
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46402116"
---
# <a name="-implementation-comment"></a>// Comentário da implementação

O `// Implementation` seção é a parte mais importante de qualquer declaração de classe do MFC.

Esta seção contém todos os detalhes de implementação. Funções de membro e variáveis de membro podem aparecer nesta seção. Tudo abaixo desta linha pode ser alteradas em uma versão futura do MFC. A menos que você não pode evitar isso, você não deve confiar em detalhes abaixo o `// Implementation` linha. Além disso, os membros declarados abaixo da linha de implementação não são documentados, embora alguns implementação é discutida em Observações técnicas. Substituições de funções virtuais na classe base residam nesta seção, independentemente de qual seção a função de classe base é definida, pois o fato de que uma função substitui a implementação da classe base é considerado um detalhe de implementação. Normalmente, esses membros são protegidos, mas não sempre.

Observe a partir o `CStdioFile` listando sob [um exemplo dos comentários](../mfc/an-example-of-the-comments.md) que os membros declarados abaixo a `// Implementation` comentário pode ser declarado como **público**, **protegido**, ou **privada**. Você só deve usar esses membros com cuidado, porque eles podem mudar no futuro. Declarando um grupo de membros, como **pública** podem ser necessários para a implementação da biblioteca de classe funcionar corretamente. No entanto, isso não significa que você pode usar com segurança os membros declarados até.

> [!NOTE]
>  Você pode encontrar comentários dos tipos restantes acima ou abaixo de `// Implementation` comentário. Em ambos os casos, elas descrevem os tipos de membros declarados abaixo deles. Se ocorrerem abaixo o `// Implementation` comentário, você deve presumir que os membros podem mudar em versões futuras do MFC.

## <a name="see-also"></a>Consulte também

[Usando os arquivos de origem MFC](../mfc/using-the-mfc-source-files.md)<br/>
[Um exemplo dos comentários](../mfc/an-example-of-the-comments.md)<br/>
[Comentário sobre construtores](../mfc/decrement-constructors-comment.md)<br/>
[Comentário sobre atributos](../mfc/decrement-attributes-comment.md)<br/>
[Comentário sobre operações](../mfc/decrement-operations-comment.md)<br/>
[Comentário sobre substituíveis](../mfc/decrement-overridables-comment.md)

