---
title: Usando listas de imagens em um controle de barra de ferramentas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- toolbar controls [MFC], image
- image lists [MFC], toolbar controls
- CToolBarCtrl class [MFC], image lists
ms.assetid: ccbe8df4-4ed9-4b54-bb93-9a1dcb3b97eb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 50e7cb936c55ced1f16a325a031dccd1edde7d06
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36951901"
---
# <a name="using-image-lists-in-a-toolbar-control"></a>Usando listas de imagens em um controle da barra de ferramentas
Por padrão, as imagens usadas pelos botões em um controle de barra de ferramentas são armazenadas como um único bitmap. No entanto, você também pode armazenar imagens de botão em um conjunto de listas de imagens. O objeto de controle de barra de ferramentas pode usar até três listas de imagens separadas:  
  
-   Habilitado imagem listar contém imagens de botões de barra de ferramentas que estão habilitadas no momento.  
  
-   Desabilitado imagem listar contém imagens de botões de barra de ferramentas que estão atualmente desabilitados.  
  
-   Realçado imagem listar contém imagens de botões de barra de ferramentas que são realçadas no momento. Esta lista de imagens é usada somente quando a barra de ferramentas usa o estilo TBSTYLE_FLAT.  
  
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

