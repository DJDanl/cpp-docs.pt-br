---
title: Operações de fluxo em controles de edição avançada
ms.date: 11/04/2016
helpviewer_keywords:
- CRichEditCtrl class [MFC], stream operations
- CRichEditCtrl class [MFC], stream storage
- rich edit controls [MFC], stream operations
- storage, stream in CRichEditCtrl
- stream operations in CRichEditCtrl
- stream storage and CRichEditCtrl
ms.assetid: 110b4684-1e76-4ca6-9ef0-5bc8b2d93c78
ms.openlocfilehash: 73277f59dc0ad4dfe21d481d0b893903ed407ea9
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69512947"
---
# <a name="stream-operations-in-rich-edit-controls"></a>Operações de fluxo em controles de edição avançada

Você pode usar fluxos para transferir dados para dentro ou para fora de um controle de edição rico ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)). Um fluxo é definido por uma estrutura [EDITSTREAM](/windows/win32/api/richedit/ns-richedit-editstream) , que especifica um buffer e uma função de retorno de chamada definida pelo aplicativo.

Para ler dados em um controle de edição rico (ou seja, transmitir os dados), use a função de membro de [fluxo](../mfc/reference/cricheditctrl-class.md#streamin) . O controle chama repetidamente a função de retorno de chamada definida pelo aplicativo, que transfere uma parte dos dados para o buffer a cada vez.

Para salvar o conteúdo de um controle de edição rico (ou seja, transmitir os dados de saída), você pode usar a função de membro [StreamOut](../mfc/reference/cricheditctrl-class.md#streamout). O controle grava repetidamente no buffer e, em seguida, chama a função de retorno de chamada definida pelo aplicativo. Para cada chamada, a função de chamada de retorno salva o conteúdo do buffer.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
