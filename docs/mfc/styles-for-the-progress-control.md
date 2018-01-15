---
title: Estilos para o controle de andamento | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- PBS_SMOOTH style
- progress controls [MFC], styles
- PBS_VERTICAL style
- CProgressCtrl class [MFC], styles
ms.assetid: 39eb8081-bc20-4552-91b9-e7cdd1b7d8ae
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6186372dc3ac8bc1000a71706971c9ff72078c5a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="styles-for-the-progress-control"></a>Estilos para o controle de progresso
Quando você cria inicialmente o controle de progresso ([CProgressCtrl::Create](../mfc/reference/cprogressctrl-class.md#create)), use o `dwStyle` para especificar os estilos de janela desejado para o controle de andamento. A lista a seguir detalha os estilos de janela aplicável. O controle ignora qualquer estilo de janela diferentes daqueles listados aqui. Você sempre deve criar o controle como uma janela filho, geralmente de um pai de caixa de diálogo.  
  
|Estilo da janela|Efeito|  
|------------------|------------|  
|`WS_BORDER`|Cria uma borda em torno da janela.|  
|**ESTILO**|Cria uma janela filho (sempre deve ser usado para `CProgressCtrl`).|  
|**WS_CLIPCHILDREN**|Exclui a área ocupada pelas janelas filho ao desenhar dentro da janela pai. Usado quando você cria a janela pai.|  
|**WS_CLIPSIBLINGS**|Recorta janelas filho relação umas às outras.|  
|**WS_DISABLED**|Cria uma janela que é inicialmente desabilitada.|  
|**WS_VISIBLE**|Cria uma janela que é visível inicialmente.|  
|**WS_TABSTOP**|Especifica que o controle pode receber o foco quando o usuário pressiona a tecla TAB para mover a ele.|  
  
 Além disso, você pode especificar dois estilos que se aplicam somente para o controle de progresso, `PBS_VERTICAL` e `PBS_SMOOTH`.  
  
 Use `PBS_VERTICAL` para orientar o controle verticalmente, em vez de horizontalmente. Use `PBS_SMOOTH` para preencher o controle completamente, em vez de exibir pequenos quadrados delineados que preencher o controle de forma incremental.  
  
 Sem `PBS_SMOOTH` estilo:  
  
 ![Estilo de barra de progresso padrão](../mfc/media/vc4ruw1.gif "vc4ruw1")  
  
 Com `PBS_SMOOTH` e `PBS_VERTICAL` estilos:  
  
 ![Estilo, smooth e vertical de barra de progresso](../mfc/media/vc4ruw2.gif "vc4ruw2")  
  
 Para obter mais informações, consulte [estilos de janela](../mfc/reference/styles-used-by-mfc.md#frame-window-styles-mfc) no *referência MFC*.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CProgressCtrl](../mfc/using-cprogressctrl.md)

