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
ms.openlocfilehash: f15256f99a744273b3487925bf273ad563c32aff
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50450798"
---
# <a name="rubber-banding-and-trackers"></a>Elásticos e controladores

Outro recurso fornecido com rastreadores é a seleção de "elástica", que permite que um usuário selecione vários itens OLE arrastando um retângulo de dimensionamento ao redor dos itens a ser selecionado. Quando o usuário libera o botão esquerdo do mouse, os itens dentro da região selecionada pelo usuário são selecionadas e podem ser manipulados pelo usuário. Por exemplo, o usuário pode arrastar a seleção em outro aplicativo de contêiner.

Implementar este recurso requer código adicional na função de manipulador WM_LBUTTONDOWN do seu aplicativo.

O exemplo de código a seguir implementa recursos adicionais e seleção de Retângulo Elástico.

[!code-cpp[NVC_MFCOClient#6](../mfc/codesnippet/cpp/rubber-banding-and-trackers_1.cpp)]

Se você quiser permitir reversível orientação do controlador durante Elásticos, você deve chamar [CRectTracker::TrackRubberBand](../mfc/reference/crecttracker-class.md#trackrubberband) com o terceiro parâmetro definido como **verdadeiro**. Lembre-se de que permitir orientação reversível às vezes causará [CRectTracker::m_rect](../mfc/reference/crecttracker-class.md#m_rect) para se tornar invertido. Isso pode ser corrigido por uma chamada para [CRect::NormalizeRect](../atl-mfc-shared/reference/crect-class.md#normalizerect).

Para obter mais informações, consulte [itens de cliente de contêiner](../mfc/containers-client-items.md) e [personalizando arrastar e soltar](../mfc/drag-and-drop-customizing.md).

## <a name="see-also"></a>Consulte também

[Controladores: implementando controladores no aplicativo OLE](../mfc/trackers-implementing-trackers-in-your-ole-application.md)<br/>
[Classe CRectTracker](../mfc/reference/crecttracker-class.md)
