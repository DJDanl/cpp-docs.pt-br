---
title: Processando notificações de controle de cabeçalho | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CHeaderCtrl class [MFC], processing notifications
- controls [MFC], header
- notifications [MFC], processing for CHeaderCtrl
- header controls [MFC], processing notifications
- header control notifications
ms.assetid: e6c6af7c-d458-4d33-85aa-48014ccde5f6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fd7c6fa8a85aee06aca3b1bf804a06df428e82cb
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46387751"
---
# <a name="processing-header-control-notifications"></a>Processando notificações de controle do cabeçalho

Em sua classe de exibição ou a caixa de diálogo, use a janela Propriedades para criar uma [OnChildNotify](../mfc/reference/cwnd-class.md#onchildnotify) função de manipulador com uma instrução switch para qualquer controle de cabeçalho ([CHeaderCtrl](../mfc/reference/cheaderctrl-class.md)) mensagens de notificação que você deseja manipular (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)). As notificações são enviadas para a janela pai quando o usuário clica ou clica duas vezes em um item de cabeçalho, arrastar um divisor entre itens e assim por diante.

As mensagens de notificação associadas com um controle de cabeçalho são listadas na [referência de controle de cabeçalho](https://msdn.microsoft.com/library/windows/desktop/bb775239) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

