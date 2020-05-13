---
title: Usando listas de imagens em um controle da barra de ferramentas
ms.date: 11/04/2016
helpviewer_keywords:
- toolbar controls [MFC], image
- image lists [MFC], toolbar controls
- CToolBarCtrl class [MFC], image lists
ms.assetid: ccbe8df4-4ed9-4b54-bb93-9a1dcb3b97eb
ms.openlocfilehash: 81468528c15300a7e9ace6b20fd9fb34818f1928
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366491"
---
# <a name="using-image-lists-in-a-toolbar-control"></a>Usando listas de imagens em um controle da barra de ferramentas

Por padrão, as imagens usadas pelos botões em um controle de barra de ferramentas são armazenadas como um único bitmap. No entanto, você também pode armazenar imagens de botão em um conjunto de listas de imagens. O objeto de controle da barra de ferramentas pode usar até três listas de imagens separadas:

- Lista de imagens habilitadas Contém imagens para botões de barra de ferramentas habilitados no momento.

- Lista de imagens desativadas Contém imagens para botões de barra de ferramentas que estão atualmente desativados.

- Lista de imagens destacadas Contém imagens para botões de barra de ferramentas que estão atualmente destacados. Esta lista de imagens só é usada quando a barra de ferramentas usa o estilo TBSTYLE_FLAT.

Essas listas de imagens são usadas pelo controle `CToolBarCtrl` da barra de ferramentas quando você as associa ao objeto. Essa associação é realizada fazendo chamadas para [CToolBarCtrl::SetImageList,](../mfc/reference/ctoolbarctrl-class.md#setimagelist) [SetDisabledImageList](../mfc/reference/ctoolbarctrl-class.md#setdisabledimagelist)e [SetHotImageList](../mfc/reference/ctoolbarctrl-class.md#sethotimagelist).

Por padrão, o `CToolBar` MFC usa a classe para implementar barras de ferramentas de aplicativos MFC. No entanto, a `GetToolBarCtrl` função de `CToolBarCtrl` membro pode ser usada para recuperar o objeto incorporado. Em seguida, você `CToolBarCtrl` pode fazer chamadas para funções de membro usando o objeto retornado.

O exemplo a seguir demonstra essa técnica`m_ToolBarImages`atribuindo`m_ToolBarDisabledImages`uma lista de `CToolBarCtrl` imagens habilitada () e desativada () a um objeto (`m_ToolBarCtrl`).

[!code-cpp[NVC_MFCControlLadenDialog#35](../mfc/codesnippet/cpp/using-image-lists-in-a-toolbar-control_1.cpp)]

> [!NOTE]
> As listas de imagens usadas pelo objeto da barra de ferramentas devem ser objetos permanentes. Por essa razão, eles são comumente membros de dados de uma classe MFC; neste exemplo, a classe de janela de quadro principal.

Uma vez que as `CToolBarCtrl` listas de imagens estejam associadas ao objeto, a estrutura exibe automaticamente a imagem do botão adequada.

## <a name="see-also"></a>Confira também

[Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
