---
title: Usando listas de imagens em um controle de barra de ferramentas | Microsoft Docs
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
- toolbar controls [MFC], image
- image lists [MFC], toolbar controls
- CToolBarCtrl class [MFC], image lists
ms.assetid: ccbe8df4-4ed9-4b54-bb93-9a1dcb3b97eb
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 507f684a0c5c7a923cd5c8e16bc9578b8b68e511
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-image-lists-in-a-toolbar-control"></a>Usando listas de imagens em um controle da barra de ferramentas
Por padrão, as imagens usadas pelos botões em um controle de barra de ferramentas são armazenadas como um único bitmap. No entanto, você também pode armazenar imagens de botão em um conjunto de listas de imagens. O objeto de controle de barra de ferramentas pode usar até três listas de imagens separadas:  
  
-   Habilitado imagem listar contém imagens de botões de barra de ferramentas que estão habilitadas no momento.  
  
-   Desabilitado imagem listar contém imagens de botões de barra de ferramentas que estão atualmente desabilitados.  
  
-   Realçado imagem listar contém imagens de botões de barra de ferramentas que são realçadas no momento. Essa lista de imagem é usada somente quando a barra de ferramentas usa a **TBSTYLE_FLAT** estilo.  
  
 Essas listas de imagens são usadas pelo controle de barra de ferramentas quando você associá-los com o `CToolBarCtrl` objeto. Essa associação é realizada por meio de chamadas para [CToolBarCtrl::SetImageList](../mfc/reference/ctoolbarctrl-class.md#setimagelist), [SetDisabledImageList](../mfc/reference/ctoolbarctrl-class.md#setdisabledimagelist), e [SetHotImageList](../mfc/reference/ctoolbarctrl-class.md#sethotimagelist).  
  
 Por padrão, o MFC usa o `CToolBar` classe para implementar as barras de ferramentas de aplicativo MFC. No entanto, o `GetToolBarCtrl` função de membro pode ser usada para recuperar o item inserido `CToolBarCtrl` objeto. Em seguida, você pode fazer chamadas para `CToolBarCtrl` funções de membro usando o objeto retornado.  
  
 O exemplo a seguir demonstra essa técnica, atribuindo um habilitado (`m_ToolBarImages`) e desabilitado (`m_ToolBarDisabledImages`) lista de imagens para um `CToolBarCtrl` objeto (`m_ToolBarCtrl`).  
  
 [!code-cpp[NVC_MFCControlLadenDialog#35](../mfc/codesnippet/cpp/using-image-lists-in-a-toolbar-control_1.cpp)]  
  
> [!NOTE]
>  As listas de imagens usadas pelo objeto de barra de ferramentas devem ser objetos permanentes. Por esse motivo, eles geralmente são membros de dados de uma classe do MFC; Neste exemplo, a classe de janela do quadro principal.  
  
 Depois que as listas de imagens associadas a `CToolBarCtrl` do objeto, o framework exibe automaticamente a imagem do botão adequado.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

