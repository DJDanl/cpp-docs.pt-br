---
title: Mapeando mensagens do Windows para a classe
ms.date: 09/06/2019
helpviewer_keywords:
- MFC dialog boxes [MFC], Windows messages
- message maps [MFC], in dialog class
- Windows messages [MFC], mapping in dialog classes
- messages to dialog class [MFC]
- mappings [MFC], messages to dialog class [MFC]
- message maps [MFC], mapping Windows messages to classes
- messages to dialog class [MFC], mapping
- Class Wizard [MFC]
ms.assetid: a4c6fd1f-1d33-47c9-baa0-001755746d6d
ms.openlocfilehash: 6b1155945c4248c5ac2755d60d8887f890e6d324
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618297"
---
# <a name="mapping-windows-messages-to-your-class"></a>Mapeando mensagens do Windows para a classe

Se você precisar que sua caixa de diálogo manipule mensagens do Windows, substitua as funções de manipulador apropriadas. Para fazer isso, escolha a guia **modo de exibição de classe** em **Gerenciador de soluções**, clique com o botão direito do mouse na classe que representa a caixa de diálogo e escolha [Assistente de classe](reference/mfc-class-wizard.md). Use o assistente para [mapear as mensagens](reference/mapping-messages-to-functions.md) para a classe da caixa de diálogo. Isso grava uma entrada de mapa de mensagem para cada mensagem e adiciona as funções de membro do manipulador de mensagens à classe. Use o editor de código para escrever código nos manipuladores de mensagens.

Você também pode substituir as funções de membro de [CDialog](reference/cdialog-class.md) e suas classes base, especialmente [CWnd](reference/cwnd-class.md).

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Manipulação e mapeamento de mensagens](message-handling-and-mapping.md)

- [Funções de membro comumente substituídas](commonly-overridden-member-functions.md)

- [Funções de membro comumente adicionadas](commonly-added-member-functions.md)

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](dialog-boxes.md)<br/>
[Trabalhar com caixas de diálogo no MFC](life-cycle-of-a-dialog-box.md)
