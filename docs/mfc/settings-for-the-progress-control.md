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
ms.openlocfilehash: 26afdcb58a64f2d2042596349acc4496aa530468
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="settings-for-the-progress-control"></a>Configurações para o controle de progresso
As configurações básicas para o controle de progresso ([CProgressCtrl](../mfc/reference/cprogressctrl-class.md)) são o intervalo e a posição atual. O intervalo representa todo o período da operação. A posição atual representa o progresso feitas pelo seu aplicativo para concluir a operação. As alterações para o intervalo ou a posição com que o controle de andamento redesenhado.  
  
 Por padrão, o intervalo é definido como 0 - 100 e a posição inicial é definido como 0. Para recuperar as configurações atuais de intervalo para o controle de andamento, use o [GetRange](../mfc/reference/cprogressctrl-class.md#getrange) função de membro. Para alterar o intervalo, use o [SetRange](../mfc/reference/cprogressctrl-class.md#setrange) função de membro.  
  
 Para definir a posição, use [SetPos](../mfc/reference/cprogressctrl-class.md#setpos). Para recuperar a posição atual sem especificar um novo valor, use [GetPos](../mfc/reference/cprogressctrl-class.md#getpos). Por exemplo, convém simplesmente consultar o status da operação atual.  
  
 Para depurar a posição atual do controle de andamento, use [StepIt](../mfc/reference/cprogressctrl-class.md#stepit). Para definir a quantidade de cada etapa, use [SetStep](../mfc/reference/cprogressctrl-class.md#setstep)  
  
## <a name="see-also"></a>Consulte também  
 [Usando CProgressCtrl](../mfc/using-cprogressctrl.md)   
 [Controles](../mfc/controls-mfc.md)

