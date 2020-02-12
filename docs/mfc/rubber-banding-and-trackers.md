---
title: Elásticos e controladores
ms.date: 11/04/2016
helpviewer_keywords:
- trackers [MFC]
- CRectTracker class [MFC], implementing trackers
- OLE objects [MFC], selecting
- rubber banding [MFC]
- WM_LBUTTONDOWN [MFC]
ms.assetid: 0d0fa64c-6418-4baf-ab7f-2d16ca039230
ms.openlocfilehash: 095f3c15546466c6a495f6aa348990ed69b04a9e
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127360"
---
# <a name="rubber-banding-and-trackers"></a>Elásticos e controladores

Outro recurso fornecido com os rastreadores é a seleção de "faixa de borracha", que permite que um usuário Selecione vários itens OLE arrastando um retângulo de dimensionamento ao lado dos itens a serem selecionados. Quando o usuário libera o botão esquerdo do mouse, os itens dentro da região selecionada pelo usuário são selecionados e podem ser manipulados pelo usuário. Por exemplo, o usuário pode arrastar a seleção para outro aplicativo de contêiner.

A implementação desse recurso requer algum código adicional na função de manipulador de WM_LBUTTONDOWN do seu aplicativo.

O exemplo de código a seguir implementa a seleção de banda de borracha e recursos adicionais.

[!code-cpp[NVC_MFCOClient#6](../mfc/codesnippet/cpp/rubber-banding-and-trackers_1.cpp)]

Se você quiser permitir a orientação reversível do controlador durante a faixa de borracha, deverá chamar [CRectTracker:: TrackRubberBand](../mfc/reference/crecttracker-class.md#trackrubberband) com o terceiro parâmetro definido como **true**. Lembre-se de que permitir a orientação reversível às vezes fará com que [CRectTracker:: m_rect](../mfc/reference/crecttracker-class.md#m_rect) se torne invertido. Isso pode ser corrigido por uma chamada para [CRect:: NormalizeRect](../atl-mfc-shared/reference/crect-class.md#normalizerect).

Para obter mais informações, consulte [itens de cliente de contêiner](../mfc/containers-client-items.md) e [arrastar e soltar OLE: Personalizar arrastar e soltar](../mfc/drag-and-drop-ole.md#customize-drag-and-drop).

## <a name="see-also"></a>Consulte também

[Controladores: implementando controladores no aplicativo OLE](../mfc/trackers-implementing-trackers-in-your-ole-application.md)<br/>
[Classe CRectTracker](../mfc/reference/crecttracker-class.md)
