---
title: Usando dicas de ferramenta em um objeto CStatusBarCtrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: CStatusBarCtrl
dev_langs: C++
helpviewer_keywords:
- tool tips [MFC], using in status bars
- status bars [MFC], tool tips
- CStatusBarCtrl class [MFC], tool tips
ms.assetid: a77597a7-43ef-4b8f-87bc-a8ea1dc63dc3
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 3e2d7f2ee90b7389ad3602e808213c3803dd5ad1
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="using-tooltips-in-a-cstatusbarctrl-object"></a>Usando dicas de ferramenta em um objeto CStatusBarCtrl
Para ativar dicas de ferramenta para um controle de barra de status, crie o `CStatusBarCtrl` do objeto com o **SBT_TOOLTIPS** estilo.  
  
> [!NOTE]
>  Se você estiver usando um `CStatusBar` objeto para implementar sua barra de status, use o `CStatusBar::CreateEx` função. Ele permite que você especifique estilos adicionais para o item inserido **CStatusBarCtrl** objeto.  
  
 Uma vez o `CStatusBarCtrl` objeto foi criado com êxito, use [CStatusBarCtrl::SetTipText](../mfc/reference/cstatusbarctrl-class.md#settiptext) e [CStatusBarCtrl::GetTipText](../mfc/reference/cstatusbarctrl-class.md#gettiptext) para definir e recuperar o texto da dica para um painel específico.  
  
 Depois que a dica de ferramenta tiver sido definida, ele será exibido somente se a parte tem um ícone e nenhum texto, ou se todo o texto não pode ser exibido em parte. Não há suporte para dicas de ferramenta no modo simples.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

