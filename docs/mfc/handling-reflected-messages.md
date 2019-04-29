---
title: Manipulando mensagens refletidas
ms.date: 11/04/2016
helpviewer_keywords:
- message handling [MFC], reflected messages
- reflected messages, handling
ms.assetid: 147a4e0c-51cc-4447-a8e1-c28b4cece578
ms.openlocfilehash: 973e8cff24eca37b1806207d081636f0d1b38365
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62240555"
---
# <a name="handling-reflected-messages"></a>Manipulando mensagens refletidas

Mensagem de reflexão lhe permite lidar com mensagens para um controle, como **WM_CTLCOLOR**, **WM_COMMAND**, e **WM_NOTIFY**, no próprio controle. Isso torna o controle mais portátil e autossuficiente. O mecanismo funciona com controles comuns do Windows, bem como com controles ActiveX (antes chamados de controles OLE).

Mensagem de reflexão permite que você reutilize sua `CWnd`-as classes derivadas mais prontamente. Reflexão funciona por meio da mensagem [CWnd::OnChildNotify](../mfc/reference/cwnd-class.md#onchildnotify), usando especial **ON_XXX_REFLECT** entradas de mapa da mensagem: por exemplo, **ON_CTLCOLOR_REFLECT** e **ON_CONTROL_REFLECT**. [62 de observação técnica](../mfc/tn062-message-reflection-for-windows-controls.md) explica a reflexão de mensagem em mais detalhes.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer

- [Saiba mais sobre a reflexão de mensagem](../mfc/tn062-message-reflection-for-windows-controls.md)

- [Implementar a reflexão de mensagem para um controle comum](../mfc/tn062-message-reflection-for-windows-controls.md)

- [Implementar a reflexão de mensagem para um controle ActiveX](../mfc/mfc-activex-controls-subclassing-a-windows-control.md)

## <a name="see-also"></a>Consulte também

[Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)
