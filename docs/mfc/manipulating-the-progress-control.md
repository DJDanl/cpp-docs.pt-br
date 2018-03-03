---
title: Manipulando o controle de andamento | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- CProgressCtrl class [MFC], working with
- progress controls [MFC], manipulating
- CProgressCtrl class [MFC], manipulating
- controlling progress controls [MFC]
- CProgressCtrl class [MFC], using
ms.assetid: 9af561d1-980b-4003-a6da-ff79be15bf23
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c75866cdcf947745db741a6626f01215e58932e3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="manipulating-the-progress-control"></a>Manipulando o controle de progresso
Há três maneiras de alterar a posição atual de um controle de progresso ([CProgressCtrl](../mfc/reference/cprogressctrl-class.md)).  
  
-   A posição pode ser alterada por um valor de incremento predefinido.  
  
-   A posição pode ser alterada por um valor arbitrário.  
  
-   A posição pode ser alterada para um valor específico.  
  
### <a name="to-change-the-position-by-a-preset-amount"></a>Para alterar a posição em um valor predefinido  
  
1.  Use o [SetStep](../mfc/reference/cprogressctrl-class.md#setstep) a função de membro para definir o valor de incremento. Por padrão, esse valor é 10. Normalmente, esse valor é definido como uma das configurações iniciais para o controle. O valor da etapa pode ser negativo.  
  
2.  Use o [StepIt](../mfc/reference/cprogressctrl-class.md#stepit) a função de membro para incrementar a posição. Isso faz com que o controle ser redesenhado.  
  
    > [!NOTE]
    >  `StepIt`fará com que a posição seja ajustada. Por exemplo, um determinado intervalo de 1 -100, uma etapa de 20 e uma posição de 90, `StepIt` definirá a posição como 10.  
  
### <a name="to-change-the-position-by-an-arbitrary-amount"></a>Para alterar a posição em um valor arbitrário  
  
1.  Use o [OffsetPos](../mfc/reference/cprogressctrl-class.md#offsetpos) a função de membro para alterar a posição. `OffsetPos`aceita valores negativos.  
  
    > [!NOTE]
    >  `OffsetPos`, ao contrário de `StepIt`, não será quebrado para a posição. A nova posição é ajustada para permanecer dentro do intervalo.  
  
### <a name="to-change-the-position-to-a-specific-value"></a>Para alterar a posição de um valor específico  
  
1.  Use o [SetPos](../mfc/reference/cprogressctrl-class.md#setpos) a função de membro para definir a posição de um valor específico. Se necessário, a nova posição é ajustada para ficar dentro do intervalo.  
  
 Normalmente, o controle de progresso é usado somente para saída. Para obter a posição atual sem especificar um novo valor, use [GetPos](../mfc/reference/cprogressctrl-class.md#getpos).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CProgressCtrl](../mfc/using-cprogressctrl.md)   
 [Controles](../mfc/controls-mfc.md)

