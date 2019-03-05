---
title: Usando listas de imagens em um controle da barra de ferramentas
ms.date: 11/04/2016
helpviewer_keywords:
- toolbar controls [MFC], image
- image lists [MFC], toolbar controls
- CToolBarCtrl class [MFC], image lists
ms.assetid: ccbe8df4-4ed9-4b54-bb93-9a1dcb3b97eb
ms.openlocfilehash: d027f7834c67ad0ed51d1b7fda5b2704972efe38
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57300785"
---
# <a name="using-image-lists-in-a-toolbar-control"></a>Usando listas de imagens em um controle da barra de ferramentas

Por padrão, as imagens usadas pelos botões em um controle de barra de ferramentas são armazenadas como um único bitmap. No entanto, você também pode armazenar imagens de botão em um conjunto de listas de imagens. O objeto de controle de barra de ferramentas pode usar até três listas de imagens separadas:

- Habilitada a imagem listar contém imagens de botões de barra de ferramentas que estão habilitado no momento.

- Desabilitado imagem listar contém imagens de botões de barra de ferramentas que estão atualmente desabilitados.

- Realçado imagem listar contém imagens de botões de barra de ferramentas que são realçadas no momento. Essa lista de imagens é usada somente quando a barra de ferramentas usa o estilo TBSTYLE_FLAT.

Essas listas de imagens são usadas pelo controle de barra de ferramentas quando você associá-los com o `CToolBarCtrl` objeto. Essa associação é realizada por meio de chamadas para [CToolBarCtrl::SetImageList](../mfc/reference/ctoolbarctrl-class.md#setimagelist), [SetDisabledImageList](../mfc/reference/ctoolbarctrl-class.md#setdisabledimagelist), e [SetHotImageList](../mfc/reference/ctoolbarctrl-class.md#sethotimagelist).

Por padrão, o MFC usa o `CToolBar` classe para implementar as barras de ferramentas de aplicativo MFC. No entanto, o `GetToolBarCtrl` função de membro pode ser usada para recuperar o embedded `CToolBarCtrl` objeto. Em seguida, você pode fazer chamadas para `CToolBarCtrl` funções de membro usando o objeto retornado.

O exemplo a seguir demonstra essa técnica, atribuindo um habilitado (`m_ToolBarImages`) e desabilitado (`m_ToolBarDisabledImages`) lista de imagens para um `CToolBarCtrl` objeto (`m_ToolBarCtrl`).

[!code-cpp[NVC_MFCControlLadenDialog#35](../mfc/codesnippet/cpp/using-image-lists-in-a-toolbar-control_1.cpp)]

> [!NOTE]
>  As listas de imagens usadas pelo objeto de barra de ferramentas devem ser objetos permanentes. Por esse motivo, normalmente eles são membros de dados de uma classe do MFC; Neste exemplo, a classe de janela do quadro principal.

Depois que as listas de imagens que estão associadas a `CToolBarCtrl` do objeto, o framework exibe automaticamente a imagem do botão adequado.

## <a name="see-also"></a>Consulte também

[Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
