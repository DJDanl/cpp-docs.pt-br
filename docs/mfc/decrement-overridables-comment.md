---
title: – Comentário sobre substituíveis de
ms.date: 11/04/2016
helpviewer_keywords:
- Overridables comment in MFC source files
- MFC source files, Overridables comment
- overriding, Overridables comment in MFC source files
- comments, MFC
ms.assetid: 8968dea5-0d94-451f-bcb2-991580e65ba2
ms.openlocfilehash: 90d6a585f62de589299147edce87332d96c6dbb8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62153223"
---
# <a name="-overridables-comment"></a>// Comentário sobre substituíveis

O `// Overridables` seção de uma declaração de classe do MFC contém funções virtuais que podem ser substituídos em uma classe derivada quando você precisa modificar o comportamento da classe base. Eles geralmente são nomeados começando com "On", embora não seja estritamente necessário. Funções aqui são projetadas para ser substituído e geralmente implementam ou fornecer algum tipo de "retorno de chamada" ou "conectar". Normalmente, esses membros são protegidos.

No próprio MFC, funções virtuais puras sempre são colocadas nesta seção. Uma função virtual pura em C++ é um do formulário:

`virtual void OnDraw( ) = 0;`

No exemplo de listagem da classe `CStdioFile`, na [um exemplo dos comentários](../mfc/an-example-of-the-comments.md), a lista não inclui nenhuma seção sobre substituíveis. Classe `CDocument`, por outro lado, lista aproximadamente 10 funções de membro substituíveis.

Em algumas classes, você também poderá ver o comentário `// Advanced Overridables`. Essas são funções avançadas apenas os programadores devem tentar substituir. Você provavelmente nunca será necessário substituí-las.

> [!NOTE]
>  As convenções descritas neste artigo também funcionam bem, em geral, para propriedades e métodos de automação (anteriormente conhecido como automação OLE). Métodos de automação são semelhantes às operações do MFC. Propriedades de automação são semelhantes aos atributos do MFC. Eventos de automação (suportados para controles ActiveX, anteriormente conhecidos como controles OLE) são semelhantes às funções de membro substituíveis do MFC.

## <a name="see-also"></a>Consulte também

[Usando os arquivos de origem MFC](../mfc/using-the-mfc-source-files.md)<br/>
[Um exemplo dos comentários](../mfc/an-example-of-the-comments.md)<br/>
[Comentário da implementação](../mfc/decrement-implementation-comment.md)<br/>
[Comentário sobre construtores](../mfc/decrement-constructors-comment.md)<br/>
[Comentário sobre atributos](../mfc/decrement-attributes-comment.md)<br/>
[Comentário sobre operações](../mfc/decrement-operations-comment.md)
