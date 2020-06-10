---
title: Manipulando mensagens refletidas
ms.date: 11/04/2016
helpviewer_keywords:
- message handling [MFC], reflected messages
- reflected messages, handling
ms.assetid: 147a4e0c-51cc-4447-a8e1-c28b4cece578
ms.openlocfilehash: 8907b432cf4dabad33c0925b841f65dfc57c6295
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620149"
---
# <a name="handling-reflected-messages"></a>Manipulando mensagens refletidas

A reflexão de mensagem permite que você manipule mensagens para um controle, como **WM_CTLCOLOR**, **WM_COMMAND**e **WM_NOTIFY**, dentro do próprio controle. Isso torna o controle mais autônomo e portátil. O mecanismo funciona com controles comuns do Windows, bem como com controles ActiveX (anteriormente chamados de controles OLE).

A reflexão de mensagem permite reutilizar suas `CWnd` classes derivadas de forma mais pronta. A reflexão de mensagem funciona via [CWnd:: OnChildNotify](reference/cwnd-class.md#onchildnotify), usando entradas especiais de mapa de mensagens **ON_XXX_REFLECT** : por exemplo, **ON_CTLCOLOR_REFLECT** e **ON_CONTROL_REFLECT**. A [Observação técnica 62](tn062-message-reflection-for-windows-controls.md) explica a reflexão da mensagem em mais detalhes.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer

- [Saiba mais sobre a reflexão de mensagens](tn062-message-reflection-for-windows-controls.md)

- [Implementar a reflexão de mensagens para um controle comum](tn062-message-reflection-for-windows-controls.md)

- [Implementar a reflexão de mensagens para um controle ActiveX](mfc-activex-controls-subclassing-a-windows-control.md)

## <a name="see-also"></a>Consulte também

[Declarando funções de manipulador de mensagens](declaring-message-handler-functions.md)
