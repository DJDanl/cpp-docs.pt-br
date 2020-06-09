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
ms.openlocfilehash: 26ced8172a36d34883d6b65997bb3a81fdc3c319
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625274"
---
# <a name="printing-and-print-preview"></a>Impressão e visualização de impressão

O MFC dá suporte à visualização de impressão e impressão para os documentos do seu programa por meio da classe [cvisualização](reference/cview-class.md). Para impressão básica e visualização de impressão, basta substituir a função de membro [OnDraw](reference/cview-class.md#ondraw) da classe View, que você deve fazer mesmo assim. Essa função pode ser desenhada para o modo de exibição na tela, para um contexto de dispositivo de impressora para uma impressora real ou para um contexto de dispositivo que simula a impressora na tela.

Você também pode adicionar código para gerenciar a impressão e a visualização de documentos de multipágina, para paginar seus documentos impressos e adicionar cabeçalhos e rodapés a eles.

Esta família de artigos explica como a impressão é implementada no biblioteca MFC (MFC) e como aproveitar a arquitetura de impressão já incorporada à estrutura. Os artigos também explicam como o MFC dá suporte à implementação fácil da funcionalidade de visualização de impressão e como você pode usar e modificar essa funcionalidade.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Impressão](printing.md)

- [Arquitetura de visualização de impressão](print-preview-architecture.md)

- [Amostra](../overview/visual-cpp-samples.md)

## <a name="see-also"></a>Consulte também

[Elementos da interface do usuário](user-interface-elements-mfc.md)
