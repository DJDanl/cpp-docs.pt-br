---
title: Função de membro OnIdle
ms.date: 11/19/2018
f1_keywords:
- OnIdle
helpviewer_keywords:
- processing messages [MFC]
- OnIdle method [MFC]
- idle loop processing [MFC]
- CWinApp class [MFC], OnIdle method [MFC]
- message handling [MFC], OnIdle method [MFC]
ms.assetid: 51adc874-0075-4f76-be1c-79283f46c10b
ms.openlocfilehash: c7cdd5cd2327be1b90e7fdb3694353acf8adcafe
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57304426"
---
# <a name="onidle-member-function"></a>Função de membro OnIdle

Quando nenhuma mensagem do Windows está sendo processadas, o framework chama o [CWinApp](../mfc/reference/cwinapp-class.md) função de membro [OnIdle](../mfc/reference/cwinapp-class.md#onidle) (descrito na referência de biblioteca do MFC).

Substituir `OnIdle` para executar tarefas em segundo plano. A versão padrão atualiza o estado dos objetos de interface do usuário como botões da barra de ferramentas e executa a limpeza dos objetos temporários criados pela estrutura no decorrer de suas operações. A figura a seguir ilustra como o loop de mensagem chama `OnIdle` quando há mensagens na fila.

![Processo de loop de mensagem](../mfc/media/vc387c1.gif "processo de loop de mensagem") <br/>
O Loop de mensagem

Para obter mais informações sobre o que você pode fazer o loop ocioso, consulte [processamento de Loop ocioso](../mfc/idle-loop-processing.md).

## <a name="see-also"></a>Consulte também

[CWinApp: A classe do aplicativo](../mfc/cwinapp-the-application-class.md)
