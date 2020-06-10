---
title: Imprimindo
ms.date: 11/04/2016
helpviewer_keywords:
- view classes [MFC], print operations
- documents [MFC], printing
- printing [MFC], from framework
- printing [MFC]
ms.assetid: be465e8d-b0c9-4fc5-9fa8-d10486064f76
ms.openlocfilehash: 3d2ef494be66171cbcbf2b8b9e19c29c8bdc5c2f
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619811"
---
# <a name="printing"></a>Imprimindo

O Microsoft Windows implementa a exibição independente de dispositivo. No MFC, isso significa que as mesmas chamadas de desenho, na `OnDraw` função de membro da sua classe de exibição, são responsáveis por desenhar na tela e em outros dispositivos, como impressoras. Para visualização de impressão, o dispositivo de destino é uma saída de impressora simulada para a exibição.

## <a name="your-role-in-printing-vs-the-frameworks-role"></a><a name="_core_your_role_in_printing_vs.._the_framework.92.s_role"></a>Sua função na impressão versus a função da estrutura

Sua classe de exibição tem as seguintes responsabilidades:

- Informe a estrutura quantas páginas estão no documento.

- Quando solicitado a imprimir uma página especificada, desenhe essa parte do documento.

- Aloque e desaloque qualquer fonte ou outro recurso de interface de dispositivo de gráficos (GDI) necessário para impressão.

- Se necessário, envie todos os códigos de escape necessários para alterar o modo da impressora antes de imprimir uma determinada página, por exemplo, para alterar a orientação de impressão por página.

As responsabilidades da estrutura são as seguintes:

- Exibir a caixa de diálogo **Imprimir** .

- Crie um objeto [CDC](reference/cdc-class.md) para a impressora.

- Chame as funções de membro [StartDoc](reference/cdc-class.md#startdoc) e [EndDoc](reference/cdc-class.md#enddoc) do `CDC` objeto.

- Chame repetidamente a função de membro [Startpage](reference/cdc-class.md#startpage) do `CDC` objeto, informe à classe de exibição qual página deve ser impressa e chame a função de membro [EndPage](reference/cdc-class.md#endpage) do `CDC` objeto.

- Chame funções substituíveis na exibição nos horários apropriados.

Os artigos a seguir discutem como a estrutura dá suporte à visualização de impressão e impressão:

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Como a impressão padrão é feita](how-default-printing-is-done.md)

- [Documentos de multipágina](multipage-documents.md)

- [Cabeçalhos e rodapés](headers-and-footers.md)

- [Alocando recursos GDI para impressão](allocating-gdi-resources.md)

- [Visualizar impressão](print-preview-architecture.md)

## <a name="see-also"></a>Consulte também

[Impressão e visualização de impressão](printing-and-print-preview.md)
