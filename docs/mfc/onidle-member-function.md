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
ms.openlocfilehash: 17595713f942c7fe7784fa2a12adbcc583cad418
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619840"
---
# <a name="onidle-member-function"></a>Função de membro OnIdle

Quando nenhuma mensagem do Windows está sendo processada, a estrutura chama a função de membro [CWinApp](reference/cwinapp-class.md) [OnIdle](reference/cwinapp-class.md#onidle) (descrita na referência da biblioteca do MFC).

Substitua `OnIdle` para executar tarefas em segundo plano. A versão padrão atualiza o estado dos objetos da interface do usuário, como botões da barra de ferramentas, e executa a limpeza de objetos temporários criados pela estrutura no decorrer de suas operações. A figura a seguir ilustra como o loop de mensagem chama quando não há `OnIdle` mensagens na fila.

![Processo de loop de mensagem](../mfc/media/vc387c1.gif "Processo de loop de mensagem") <br/>
O loop de mensagem

Para obter mais informações sobre o que você pode fazer no loop ocioso, consulte [processamento de loop ocioso](idle-loop-processing.md).

## <a name="see-also"></a>Consulte também

[CWinApp: a classe do aplicativo](cwinapp-the-application-class.md)
