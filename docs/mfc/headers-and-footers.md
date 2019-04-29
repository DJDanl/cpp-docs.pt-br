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
ms.openlocfilehash: 1e2e57331ccbc7f0afd7b82dc035410af495abd8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62297223"
---
# <a name="headers-and-footers"></a>Cabeçalhos e rodapés

Este artigo explica como adicionar cabeçalhos e rodapés a um documento impresso.

Quando você examinar um documento na tela, o nome do documento e seu local atual no documento normalmente são exibidos em uma barra de título e uma barra de status. Ao examinar uma cópia impressa de um documento, é útil ter o número de página e o nome mostrado em um cabeçalho ou rodapé. Isso é uma maneira comum de em qual WYSIWYG até mesmo programas diferem em como eles se comportam impressão e exibição de tela.

O [OnPrint](../mfc/reference/cview-class.md#onprint) função de membro é o local adequado para imprimir os cabeçalhos ou rodapés de páginas porque ele é chamado para cada página, e porque ele é chamado somente para impressão, não para exibição na tela. Você pode definir uma função separada para imprimir um cabeçalho ou rodapé e passá-lo o contexto de dispositivo de impressora do `OnPrint`. Talvez seja necessário ajustar a origem de janela ou a extensão antes de chamar [OnDraw](../mfc/reference/cview-class.md#ondraw) para evitar que o corpo da sobreposição de página no cabeçalho ou rodapé. Você também precisará modificar `OnDraw` porque a quantidade do documento que se encaixa na página poderia ser reduzida.

É uma maneira de compensar para a área ocupada pelo cabeçalho ou rodapé é usar o **m_rectDraw** membro [CPrintInfo](../mfc/reference/cprintinfo-structure.md). Sempre que uma página é impressa, esse membro é inicializado com a área utilizável da página. Se você imprimir um cabeçalho ou rodapé antes de imprimir o corpo da página, você pode reduzir o tamanho do retângulo armazenado no **m_rectDraw** para levar em conta a área ocupada pelo cabeçalho ou rodapé. Em seguida `OnPrint` podem se referir a **m_rectDraw** para descobrir quanto área permanece para imprimir o corpo da página.

Você não pode imprimir um cabeçalho ou qualquer outra coisa, do [OnPrepareDC](../mfc/reference/cview-class.md#onpreparedc), porque ele é chamado antes do `StartPage` a função de membro de [CDC](../mfc/reference/cdc-class.md) foi chamado. Nesse ponto, o contexto de dispositivo de impressora é considerado em um limite de página. Você pode executar a impressão apenas no `OnPrint` função de membro.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Imprimindo documentos Multipágina](../mfc/multipage-documents.md)

- [Alocando recursos GDI para impressão](../mfc/allocating-gdi-resources.md)

## <a name="see-also"></a>Consulte também

[Imprimindo](../mfc/printing.md)
