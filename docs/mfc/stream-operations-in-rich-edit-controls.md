---
title: Stream de operações em controles de edição avançada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CRichEditCtrl class [MFC], stream operations
- CRichEditCtrl class [MFC], stream storage
- rich edit controls [MFC], stream operations
- storage, stream in CRichEditCtrl
- stream operations in CRichEditCtrl
- stream storage and CRichEditCtrl
ms.assetid: 110b4684-1e76-4ca6-9ef0-5bc8b2d93c78
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f34417d765151adbd7a6c02b7a76ef9d5732994f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46441976"
---
# <a name="stream-operations-in-rich-edit-controls"></a>Operações de fluxo em controles de edição avançada

Você pode usar fluxos para transferir dados para dentro ou fora de um controle rich edit ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)). Um fluxo é definido por uma [EDITSTREAM](/windows/desktop/api/richedit/ns-richedit-_editstream) estrutura, que especifica um buffer e uma função de retorno de chamada definida pelo aplicativo.

Para ler dados em uma avançada de controle de edição (isto é, transmitir os dados em), use o [StreamIn](../mfc/reference/cricheditctrl-class.md#streamin) função de membro. O controle chama repetidamente a função de retorno de chamada definida pelo aplicativo, que transfere uma parte dos dados no buffer de cada vez.

Para salvar o conteúdo de uma sofisticada do controle de edição (isto é, transmitir os saída de dados), você pode usar o [StreamOut](../mfc/reference/cricheditctrl-class.md#streamout) função de membro. O controle repetidamente grava no buffer e, em seguida, chama a função de retorno de chamada definida pelo aplicativo. Para cada chamada, a função de retorno de chamada salva o conteúdo do buffer.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

