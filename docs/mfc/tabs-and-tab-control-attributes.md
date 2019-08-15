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
ms.openlocfilehash: 982ec40e330e2a7dda5c125d83e54751cd14416d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69511236"
---
# <a name="tabs-and-tab-control-attributes"></a>Guias e atributos de controle da guia

Você tem um controle considerável sobre a aparência e o comportamento das guias que compõem um controle de guia ([CTabCtrl](../mfc/reference/ctabctrl-class.md)). Cada guia pode ter um rótulo, um ícone, um estado de item e um valor de 32 bits definido pelo aplicativo associado a ele. Para cada guia, você pode exibir o ícone, o rótulo ou ambos.

Além disso, cada item de guia pode ter três estados possíveis: pressionado, inpressionado ou realçado. Esse Estado só pode ser definido modificando um item de guia existente. Para modificar um item de guia existente, recupere-o com uma chamada para [GetItem](../mfc/reference/ctabctrl-class.md#getitem), `TCITEM` modifique a estrutura (especificamente os membros de dados *dwState* e *dwStateMask* ) e, em `TCITEM` seguida, retorne a estrutura modificada com uma chamada para [SetItem](../mfc/reference/ctabctrl-class.md#setitem). Se você precisar limpar os Estados de item de todos os itens de guia em `CTabCtrl` um objeto, faça uma chamada para [DeselectAll](../mfc/reference/ctabctrl-class.md#deselectall). Essa função redefine o estado de todos os itens de guia ou todos os itens, exceto aquele selecionado no momento.

O código a seguir limpa o estado de todos os itens de guia e, em seguida, modifica o estado do terceiro item:

[!code-cpp[NVC_MFCControlLadenDialog#32](../mfc/codesnippet/cpp/tabs-and-tab-control-attributes_1.cpp)]

Para obter mais informações sobre atributos de tabulação, consulte [guias e atributos](/windows/win32/Controls/tab-controls) de tabulação no SDK do Windows. Para obter mais informações sobre como adicionar guias a um controle guia, consulte [adicionando guias a um controle guia](../mfc/adding-tabs-to-a-tab-control.md) posteriormente neste tópico.

## <a name="see-also"></a>Consulte também

[Usando CTabCtrl](../mfc/using-ctabctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
