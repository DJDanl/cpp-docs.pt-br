---
title: Impressão e visualização de impressão
ms.date: 11/04/2016
helpviewer_keywords:
- printing [MFC]
- previewing printing
- printing [MFC]
- print preview
- printing [MFC], print preview
ms.assetid: d15059cd-32de-4450-95f7-e73aece238f6
ms.openlocfilehash: 73aae3391f07ba5ba2fe54e2c45179fe4b347a0b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50629288"
---
# <a name="printing-and-print-preview"></a>Impressão e visualização de impressão

MFC dá suporte à impressão e visualização de impressão para documentos do seu programa por meio da classe [CView](../mfc/reference/cview-class.md). Para impressão básica e visualização de impressão, basta substituir sua classe de exibição [OnDraw](../mfc/reference/cview-class.md#ondraw) função de membro, você deve fazer qualquer forma. Essa função pode desenhar para a exibição na tela, para um contexto de dispositivo de impressora para uma impressora real, ou para um contexto de dispositivo que simula a impressora na tela.

Você também pode adicionar código para gerenciar a impressão de documentos de várias páginas e visualização, paginar documentos impressos e adicionar cabeçalhos e rodapés a elas.

Essa família de artigos explica como imprimir é implementada no Microsoft Foundation Class Library (MFC) e como tirar proveito da arquitetura de impressão já incorporado a estrutura. Os artigos também explicam como o MFC oferece suporte a fácil implementação da funcionalidade de visualização de impressão e como você pode usar e modificar essa funcionalidade.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Imprimindo](../mfc/printing.md)

- [Arquitetura de visualização de impressão](../mfc/print-preview-architecture.md)

- [Amostra](../visual-cpp-samples.md)

## <a name="see-also"></a>Consulte também

[Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)
