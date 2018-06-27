---
title: Elásticos e controladores | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- trackers [MFC]
- CRectTracker class [MFC], implementing trackers
- OLE objects [MFC], selecting
- rubber banding [MFC]
- WM_LBUTTONDOWN [MFC]
ms.assetid: 0d0fa64c-6418-4baf-ab7f-2d16ca039230
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a4f36a634e4e5e6d4ee6c2618d0d43313c7c8094
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36931730"
---
# <a name="rubber-banding-and-trackers"></a>Elásticos e controladores
Outro recurso fornecido com controladores é a seleção de "elástica", que permite que um usuário selecione vários itens OLE arrastando um retângulo de dimensionamento em redor dos itens a ser selecionado. Quando o usuário libera o botão esquerdo do mouse, itens dentro da região selecionada pelo usuário são selecionados e podem ser manipulados pelo usuário. Por exemplo, o usuário pode arrastar a seleção em outro aplicativo de contêiner.  
  
 Implementar esse recurso requer um código adicional na função de manipulador WM_LBUTTONDOWN do seu aplicativo.  
  
 O exemplo de código a seguir implementa a seleção elástica e recursos adicionais.  
  
 [!code-cpp[NVC_MFCOClient#6](../mfc/codesnippet/cpp/rubber-banding-and-trackers_1.cpp)]  
  
 Se você quiser permitir reversível orientação do controlador durante esticar, você deve chamar [CRectTracker::TrackRubberBand](../mfc/reference/crecttracker-class.md#trackrubberband) com o terceiro parâmetro definido como **TRUE**. Lembre-se de que permitir reversível orientação, às vezes, [CRectTracker::m_rect](../mfc/reference/crecttracker-class.md#m_rect) deve ser invertida. Isso pode ser corrigido por uma chamada para [CRect::NormalizeRect](../atl-mfc-shared/reference/crect-class.md#normalizerect).  
  
 Para obter mais informações, consulte [itens de cliente de contêiner](../mfc/containers-client-items.md) e [personalizando arrastar e soltar](../mfc/drag-and-drop-customizing.md).  
  
## <a name="see-also"></a>Consulte também  
 [Controladores: Implementando controladores no aplicativo OLE](../mfc/trackers-implementing-trackers-in-your-ole-application.md)   
 [Classe CRectTracker](../mfc/reference/crecttracker-class.md)
