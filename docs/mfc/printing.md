---
title: Imprimindo
ms.date: 11/04/2016
helpviewer_keywords:
- view classes [MFC], print operations
- documents [MFC], printing
- printing [MFC], from framework
- printing [MFC]
ms.assetid: be465e8d-b0c9-4fc5-9fa8-d10486064f76
ms.openlocfilehash: a46096592c9983d04d2122bfabb56ece9346c4bc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371198"
---
# <a name="printing"></a>Imprimindo

O Microsoft Windows implementa a exibição independente do dispositivo. No MFC, isso significa que as `OnDraw` mesmas chamadas de desenho, na função membro da sua classe de visualização, são responsáveis por desenhar no display e em outros dispositivos, como impressoras. Para visualização de impressão, o dispositivo de destino é uma saída de impressora simulada para o display.

## <a name="your-role-in-printing-vs-the-frameworks-role"></a><a name="_core_your_role_in_printing_vs.._the_framework.92.s_role"></a>Seu papel na impressão versus o papel do framework

Sua classe de opinião tem as seguintes responsabilidades:

- Informe a estrutura quantas páginas estão no documento.

- Quando solicitado a imprimir uma página especificada, desenhe essa parte do documento.

- Aloque e deloque quaisquer fontes ou outros recursos de interface de dispositivo gráfico (GDI) necessários para impressão.

- Se necessário, envie quaisquer códigos de fuga necessários para alterar o modo de impressora antes de imprimir uma determinada página, por exemplo, para alterar a orientação de impressão por página.

As responsabilidades do quadro são as seguintes:

- Exibir a caixa de diálogo **Imprimir.**

- Crie um objeto [CDC](../mfc/reference/cdc-class.md) para a impressora.

- Ligue para as funções do membro [StartDoc](../mfc/reference/cdc-class.md#startdoc) e [EndDoc](../mfc/reference/cdc-class.md#enddoc) do `CDC` objeto.

- Ligue repetidamente para a função `CDC` de membro [do StartPage](../mfc/reference/cdc-class.md#startpage) do objeto, informe a classe `CDC` de exibição qual página deve ser impressa e chame a função de membro [EndPage](../mfc/reference/cdc-class.md#endpage) do objeto.

- Chame funções superridíveis na exibição nos momentos apropriados.

Os seguintes artigos discutem como o framework suporta impressão e visualização de impressão:

### <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Como a impressão padrão é feita](../mfc/how-default-printing-is-done.md)

- [Documentos de várias páginas](../mfc/multipage-documents.md)

- [Cabeçalhos e rodapés](../mfc/headers-and-footers.md)

- [Alocação de recursos GDI para impressão](../mfc/allocating-gdi-resources.md)

- [Visualização de impressão](../mfc/print-preview-architecture.md)

## <a name="see-also"></a>Confira também

[Impressão e visualização de impressão](../mfc/printing-and-print-preview.md)
