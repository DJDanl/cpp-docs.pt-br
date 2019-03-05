---
title: Mapeando mensagens do Windows para a classe
ms.date: 11/04/2016
helpviewer_keywords:
- MFC dialog boxes [MFC], Windows messages
- message maps [MFC], in dialog class
- Windows messages [MFC], mapping in dialog classes
- messages to dialog class [MFC]
- mappings [MFC], messages to dialog class [MFC]
- message maps [MFC], mapping Windows messages to classes
- messages to dialog class [MFC], mapping
ms.assetid: a4c6fd1f-1d33-47c9-baa0-001755746d6d
ms.openlocfilehash: 7e15f52e41d4ac91a839629342258128db86e2d5
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57326667"
---
# <a name="mapping-windows-messages-to-your-class"></a>Mapeando mensagens do Windows para a classe

Se você precisar de sua caixa de diálogo para lidar com mensagens do Windows, substitua as funções de manipulador apropriado. Para fazer isso, use a janela de propriedades para [mapear as mensagens](../mfc/reference/mapping-messages-to-functions.md) para a classe de caixa de diálogo. Isso grava uma entrada de mapa de mensagem para cada mensagem e adiciona as funções de membro de manipulador de mensagens para a classe. Use o editor de código de origem do Visual C++ para escrever o código nos manipuladores de mensagem.

Você também pode substituir as funções de membro [CDialog](../mfc/reference/cdialog-class.md) e suas classes base, especialmente [CWnd](../mfc/reference/cwnd-class.md).

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Mapeamento e manipulação de mensagens](../mfc/message-handling-and-mapping.md)

- [Funções de membro normalmente substituídas](../mfc/commonly-overridden-member-functions.md)

- [Funções de membro normalmente adicionadas](../mfc/commonly-added-member-functions.md)

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](../mfc/dialog-boxes.md)<br/>
[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)
