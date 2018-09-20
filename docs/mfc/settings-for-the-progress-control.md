---
title: Configurações para o controle de andamento | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CProgressCtrl class [MFC], settings
- progress controls [MFC], settings
ms.assetid: f4616e91-74fa-4000-ba0d-d3ddc0ee075b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b6b11189e3e0a8381ade372841e6c7b25a5a9fa0
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46434629"
---
# <a name="settings-for-the-progress-control"></a>Configurações para o controle de progresso

As configurações básicas para o controle de progresso ([CProgressCtrl](../mfc/reference/cprogressctrl-class.md)) são o intervalo e a posição atual. O intervalo representa a duração inteira da operação. A posição atual representa o progresso que seu aplicativo fez para concluir a operação. As alterações para o intervalo ou a posição fazem o controle de progresso para redesenhar a mesmo.

Por padrão, o intervalo é definido como 0 - 100 e a posição inicial é definido como 0. Para recuperar as configurações atuais de intervalo para o controle de progresso, use o [GetRange](../mfc/reference/cprogressctrl-class.md#getrange) função de membro. Para alterar o intervalo, use o [SetRange](../mfc/reference/cprogressctrl-class.md#setrange) função de membro.

Para definir a posição, use [SetPos](../mfc/reference/cprogressctrl-class.md#setpos). Para recuperar a posição atual sem especificar um novo valor, use [GetPos](../mfc/reference/cprogressctrl-class.md#getpos). Por exemplo, talvez você queira simplesmente consultar o status da operação atual.

Para depurar a posição atual do controle de progresso, use [StepIt](../mfc/reference/cprogressctrl-class.md#stepit). Para definir a quantidade de cada etapa, use [SetStep](../mfc/reference/cprogressctrl-class.md#setstep)

## <a name="see-also"></a>Consulte também

[Usando CProgressCtrl](../mfc/using-cprogressctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

