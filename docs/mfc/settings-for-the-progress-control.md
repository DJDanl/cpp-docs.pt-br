---
title: "Configurações para o controle de andamento | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- CProgressCtrl class [MFC], settings
- progress controls [MFC], settings
ms.assetid: f4616e91-74fa-4000-ba0d-d3ddc0ee075b
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1ad62f3a60c8fe4fcd7efdde7f69f5c5e9450d14
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="settings-for-the-progress-control"></a>Configurações para o controle de progresso
As configurações básicas para o controle de progresso ([CProgressCtrl](../mfc/reference/cprogressctrl-class.md)) são o intervalo e a posição atual. O intervalo representa todo o período da operação. A posição atual representa o progresso feitas pelo seu aplicativo para concluir a operação. As alterações para o intervalo ou a posição com que o controle de andamento redesenhado.  
  
 Por padrão, o intervalo é definido como 0 - 100 e a posição inicial é definido como 0. Para recuperar as configurações atuais de intervalo para o controle de andamento, use o [GetRange](../mfc/reference/cprogressctrl-class.md#getrange) função de membro. Para alterar o intervalo, use o [SetRange](../mfc/reference/cprogressctrl-class.md#setrange) função de membro.  
  
 Para definir a posição, use [SetPos](../mfc/reference/cprogressctrl-class.md#setpos). Para recuperar a posição atual sem especificar um novo valor, use [GetPos](../mfc/reference/cprogressctrl-class.md#getpos). Por exemplo, convém simplesmente consultar o status da operação atual.  
  
 Para depurar a posição atual do controle de andamento, use [StepIt](../mfc/reference/cprogressctrl-class.md#stepit). Para definir a quantidade de cada etapa, use [SetStep](../mfc/reference/cprogressctrl-class.md#setstep)  
  
## <a name="see-also"></a>Consulte também  
 [Usando CProgressCtrl](../mfc/using-cprogressctrl.md)   
 [Controles](../mfc/controls-mfc.md)

