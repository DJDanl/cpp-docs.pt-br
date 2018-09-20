---
title: Manipulando mensagens refletidas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- message handling [MFC], reflected messages
- reflected messages, handling
ms.assetid: 147a4e0c-51cc-4447-a8e1-c28b4cece578
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 99fc9c30ea85ba3f94fa811464f023da0eeea37e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46438672"
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
