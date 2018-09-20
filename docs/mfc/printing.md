---
title: Imprimindo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- view classes [MFC], print operations
- documents [MFC], printing
- printing [MFC], from framework
- printing [MFC]
ms.assetid: be465e8d-b0c9-4fc5-9fa8-d10486064f76
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e03e750941be02385ac4d5b7463d5b6f32997b6a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46373942"
---
# <a name="printing"></a>Imprimindo

Microsoft Windows implementa independentes de dispositivo de exibição. No MFC, isso significa que as mesmas chamadas de desenho, o `OnDraw` a função de membro da sua classe de exibição, são responsáveis por desenho na tela e em outros dispositivos, como impressoras. Para visualização de impressão, o dispositivo de destino é uma saída da impressora simulado para a exibição.

##  <a name="_core_your_role_in_printing_vs.._the_framework.92.s_role"></a> Sua função na impressão vs. a função da estrutura

Sua classe de exibição tem as seguintes responsabilidades:

- Informe a estrutura de quantas páginas estão no documento.

- Quando for solicitado para imprimir uma página especificada, desenhe a parte do documento.

- Aloque e desaloque todas as fontes ou outros recursos de interface (GDI) do dispositivo de gráficos necessários para impressão.

- Se necessário, enviar um necessária para alterar o modo de impressora antes de imprimir uma determinada página, por exemplo, para alterar a orientação de impressão em uma base por página de códigos de escape.

Responsabilidades da estrutura são da seguinte maneira:

- Exibição de **impressão** caixa de diálogo.

- Criar uma [CDC](../mfc/reference/cdc-class.md) objeto para a impressora.

- Chame o [StartDoc](../mfc/reference/cdc-class.md#startdoc) e [EndDoc](../mfc/reference/cdc-class.md#enddoc) funções de membro a `CDC` objeto.

- Chamar repetidamente o [StartPage](../mfc/reference/cdc-class.md#startpage) função de membro da `CDC` do objeto, informar qual página deve ser impresso e chamar a classe de exibição a [EndPage](../mfc/reference/cdc-class.md#endpage) função de membro do `CDC` objeto.

- Chame funções substituíveis no modo de exibição nos momentos apropriados.

Os artigos a seguir discutem como o framework oferece suporte à impressão e visualização de impressão:

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Como a impressão padrão é feita](../mfc/how-default-printing-is-done.md)

- [Documentos Multipágina](../mfc/multipage-documents.md)

- [Cabeçalhos e rodapés](../mfc/headers-and-footers.md)

- [Alocando recursos GDI para impressão](../mfc/allocating-gdi-resources.md)

- [Visualização de impressão](../mfc/print-preview-architecture.md)

## <a name="see-also"></a>Consulte também

[Impressão e visualização de impressão](../mfc/printing-and-print-preview.md)

