---
title: Cabeçalhos e rodapés
ms.date: 11/04/2016
helpviewer_keywords:
- printing [MFC], multipage documents
- page headers [MFC], printing
- headers [MFC], printing
- footers [MFC], printing
- page footers [MFC], printing
- page headers [MFC]
- printing [MFC], headers and footers
- page footers [MFC]
ms.assetid: b0be9c53-5773-4955-a777-3c15da745128
ms.openlocfilehash: 7024c57dbe41a579582d409d0536db0ca0bc46d6
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620102"
---
# <a name="headers-and-footers"></a>Cabeçalhos e rodapés

Este artigo explica como adicionar cabeçalhos e rodapés a um documento impresso.

Quando você examina um documento na tela, o nome do documento e seu local atual no documento são normalmente exibidos em uma barra de título e uma barra de status. Ao examinar uma cópia impressa de um documento, é útil ter o nome e o número da página mostrados em um cabeçalho ou rodapé. Essa é uma maneira comum em que até mesmo programas WYSIWYG diferem em como eles executam impressão e exibição de tela.

A função de membro [OnPrint](reference/cview-class.md#onprint) é o local apropriado para imprimir cabeçalhos ou rodapés, pois ele é chamado para cada página e porque é chamado apenas para impressão, não para exibição de tela. Você pode definir uma função separada para imprimir um cabeçalho ou rodapé e passá-lo do contexto do dispositivo de impressora `OnPrint` . Talvez seja necessário ajustar a origem ou a extensão da janela antes de chamar [OnDraw](reference/cview-class.md#ondraw) para evitar que o corpo da página se sobreponha ao cabeçalho ou rodapé. Talvez você também precise modificar `OnDraw` porque a quantidade do documento que cabe na página pode ser reduzida.

Uma maneira de compensar a área tomada pelo cabeçalho ou pelo rodapé é usar o membro **m_rectDraw** de [CPrintInfo](reference/cprintinfo-structure.md). Cada vez que uma página é impressa, esse membro é inicializado com a área utilizável da página. Se você imprimir um cabeçalho ou rodapé antes de imprimir o corpo da página, poderá reduzir o tamanho do retângulo armazenado em **m_rectDraw** para considerar a área realizada pelo cabeçalho ou rodapé. Em seguida, `OnPrint` pode consultar **m_rectDraw** para descobrir a quantidade de área restante para imprimir o corpo da página.

Não é possível imprimir um cabeçalho ou qualquer outra coisa, de [OnPrepareDC](reference/cview-class.md#onpreparedc), porque ele é chamado antes que a `StartPage` função membro do [CDC](reference/cdc-class.md) tenha sido chamada. Nesse ponto, o contexto do dispositivo de impressora é considerado como sendo um limite de página. Você pode executar a impressão apenas da `OnPrint` função de membro.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Imprimindo documentos com multipáginas](multipage-documents.md)

- [Alocando recursos GDI para impressão](allocating-gdi-resources.md)

## <a name="see-also"></a>Consulte também

[Impressão](printing.md)
