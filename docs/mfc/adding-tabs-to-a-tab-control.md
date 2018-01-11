---
title: Adicionando guias a um controle guia | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- tab controls [MFC], adding tabs
- putting tabs on CTabCtrls [MFC]
- CTabCtrl class [MFC], adding tabs
- tabs [MFC], adding to CTabCtrl class [MFC]
ms.assetid: 7f3d9340-e3c7-4c71-9912-be57534ecc78
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 46012a265c1ecefa7af63f829be22e6132e036cb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="adding-tabs-to-a-tab-control"></a>Adicionando guias a um controle de guia
Depois de criar o controle de guia ([CTabCtrl](../mfc/reference/ctabctrl-class.md)), adicionar quantas guias conforme necessário.  
  
### <a name="to-add-a-tab-item"></a>Para adicionar um item de guia  
  
1.  Preparar um [TCITEM](http://msdn.microsoft.com/library/windows/desktop/bb760554) estrutura.  
  
2.  Chamar [CTabCtrl::InsertItem](../mfc/reference/ctabctrl-class.md#insertitem), passando a estrutura.  
  
3.  Repita as etapas 1 e 2 para os itens da guia adicional.  
  
 Para obter mais informações, consulte [criando um controle guia](http://msdn.microsoft.com/library/windows/desktop/bb760550) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTabCtrl](../mfc/using-ctabctrl.md)   
 [Controles](../mfc/controls-mfc.md)

