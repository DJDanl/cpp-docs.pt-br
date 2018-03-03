---
title: "Usando listas de imagens em um controle de caixa de combinação estendido | Microsoft Docs"
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
- image lists [MFC], combo boxes
- extended combo boxes [MFC], images
- images [MFC], combo box items
ms.assetid: dfff25fe-af70-47a2-8032-3901d1e6842d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3ac69e7d0dbe1748a409b107579c747b7f9a4a7c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-image-lists-in-an-extended-combo-box-control"></a>Usando listas de imagens em um controle de caixa de combinação estendido
O principal recurso de controles de caixa de combinação estendido é a capacidade de associar imagens a partir de uma lista de imagens a itens individuais em um controle de caixa de combinação. Cada item é capaz de exibir três diferentes imagens: uma para seu estado selecionado, um para seu estado não selecionado e um terceiro para uma imagem de sobreposição.  
  
 O procedimento a seguir associa uma lista de imagens a um controle de caixa de combinação estendido:  
  
### <a name="to-associate-an-image-list-with-an-extended-combo-box-control"></a>Para associar uma lista de imagens um controle de caixa de combinação estendidas  
  
1.  Criar uma nova lista de imagem (ou usar um objeto de lista de imagem existente), usando o [CImageList](../mfc/reference/cimagelist-class.md) construtor e armazenar o ponteiro resultante.  
  
2.  Inicialize o novo objeto de lista de imagem chamando [CImageList::Create](../mfc/reference/cimagelist-class.md#create). O código a seguir é um exemplo desta chamada.  
  
     [!code-cpp[NVC_MFCControlLadenDialog#10](../mfc/codesnippet/cpp/using-image-lists-in-an-extended-combo-box-control_1.cpp)]  
  
3.  Adicionar imagens opcionais para cada estado possível: selecionado ou não selecionados e uma sobreposição. O código a seguir adiciona três imagens predefinidas.  
  
     [!code-cpp[NVC_MFCControlLadenDialog#11](../mfc/codesnippet/cpp/using-image-lists-in-an-extended-combo-box-control_2.cpp)]  
  
4.  Associar a lista de imagens com o controle com uma chamada para [CComboBoxEx::SetImageList](../mfc/reference/ccomboboxex-class.md#setimagelist).  
  
 Depois que a lista de imagens foi associada com o controle, você pode especificar individualmente as imagens de que cada item será usado para os três possíveis estados. Para obter mais informações, consulte [definindo as imagens para um Item Individual](../mfc/setting-the-images-for-an-individual-item.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CComboBoxEx](../mfc/using-ccomboboxex.md)   
 [Controles](../mfc/controls-mfc.md)

