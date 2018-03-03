---
title: "Cabeçalhos e rodapés | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7525cba7d05c4d04f0548bd2dc774503b284c220
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="headers-and-footers"></a>Cabeçalhos e rodapés
Este artigo explica como adicionar cabeçalhos e rodapés a um documento impresso.  
  
 Quando você examinar um documento na tela, o nome do documento e seu local atual no documento normalmente são exibidos em uma barra de título e uma barra de status. Ao examinar uma cópia impressa de um documento, é útil para que o número de página e o nome mostrado em um cabeçalho ou rodapé. Isso é uma maneira comum no qual WYSIWYG mesmo programas diferem em como eles executam impressão e a tela.  
  
 O [OnPrint](../mfc/reference/cview-class.md#onprint) função de membro é o local apropriado para imprimir cabeçalhos ou rodapés de páginas porque ele é chamado para cada página, e porque ele é chamado somente para impressão, não para exibição na tela. Você pode definir uma função separada para imprimir um cabeçalho ou rodapé e passe o contexto de dispositivo de impressora de `OnPrint`. Talvez seja necessário ajustar a origem de janela ou extensão antes de chamar [OnDraw](../mfc/reference/cview-class.md#ondraw) para evitar que o corpo da sobreposição de página no cabeçalho ou rodapé. Você também pode precisar modificar `OnDraw` porque a quantidade do documento que se ajuste na página poderia ser reduzida.  
  
 Uma maneira para compensar para a área usada pelo cabeçalho ou rodapé usar o **m_rectDraw** membro [CPrintInfo](../mfc/reference/cprintinfo-structure.md). Cada vez que uma página é impresso, esse membro é inicializado com a área utilizável da página. Se você imprimir um cabeçalho ou rodapé de página antes de imprimir o corpo da página, você pode reduzir o tamanho do retângulo armazenado em **m_rectDraw** a conta para a área usada pelo cabeçalho ou rodapé. Em seguida, `OnPrint` podem se referir a **m_rectDraw** para saber quanto área permanece para imprimir o corpo da página.  
  
 Não é possível imprimir um cabeçalho ou qualquer outra coisa, de [OnPrepareDC](../mfc/reference/cview-class.md#onpreparedc), porque ele é chamado antes do `StartPage` função membro de [CDC](../mfc/reference/cdc-class.md) foi chamado. Nesse ponto, o contexto de dispositivo de impressora é considerado em um limite de página. Você pode executar apenas impressão a partir de `OnPrint` função de membro.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Imprimindo documentos Multipágina](../mfc/multipage-documents.md)  
  
-   [Alocando recursos GDI para impressão](../mfc/allocating-gdi-resources.md)  
  
## <a name="see-also"></a>Consulte também  
 [Imprimindo](../mfc/printing.md)

