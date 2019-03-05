---
title: Guias e atributos de controle da guia
ms.date: 11/04/2016
helpviewer_keywords:
- attributes [MFC], reference topics
- tab controls [MFC], attributes
- tabs [MFC]
- tabs [MFC], attributes
- CTabCtrl class [MFC], tab control attributes
ms.assetid: ecf190cb-f323-4751-bfdb-766dbe6bb553
ms.openlocfilehash: ca9f89565770e60a59007d609d132fae15eacae6
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57304789"
---
# <a name="tabs-and-tab-control-attributes"></a>Guias e atributos de controle da guia

Você tem controle considerável sobre a aparência e comportamento de guias que compõem um controle de guia ([CTabCtrl](../mfc/reference/ctabctrl-class.md)). Cada guia pode ter um rótulo, um ícone, um estado de item e um valor de 32 bits definido pelo aplicativo associado a ele. Para cada guia, você pode exibir o ícone, o rótulo ou ambos.

Além disso, cada item de guia pode ter três estados possíveis: pressionado, não pressionado ou realçado. Esse estado só pode ser definido por meio da modificação de um item de guia existente. Para modificar um item de guia existente, recuperá-la com uma chamada para [GetItem](../mfc/reference/ctabctrl-class.md#getitem), modifique a `TCITEM` estrutura (especificamente o *dwState* e *dwStateMask* membros de dados ) e, em seguida, retornar modificado `TCITEM` estrutura com uma chamada para [SetItem](../mfc/reference/ctabctrl-class.md#setitem). Se você precisará limpar os estados de item de todos os itens de guia em uma `CTabCtrl` de objeto, fazer uma chamada para [DeselectAll](../mfc/reference/ctabctrl-class.md#deselectall). Essa função redefine o estado de todos os itens de guia ou todos os itens, exceto o selecionado no momento.

O código a seguir limpa o estado de todos os itens de guia e, em seguida, modifica o estado do terceiro item:

[!code-cpp[NVC_MFCControlLadenDialog#32](../mfc/codesnippet/cpp/tabs-and-tab-control-attributes_1.cpp)]

Para obter mais informações sobre atributos de guia, consulte [guias e atributos guia](/windows/desktop/Controls/tab-controls) no SDK do Windows. Para obter mais informações sobre como adicionar guias a um controle guia, consulte [adicionando guias a um controle guia](../mfc/adding-tabs-to-a-tab-control.md) mais adiante neste tópico.

## <a name="see-also"></a>Consulte também

[Usando CTabCtrl](../mfc/using-ctabctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
