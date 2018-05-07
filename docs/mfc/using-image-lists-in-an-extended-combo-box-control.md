---
title: Usando listas de imagens em um controle de caixa de combinação estendido | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- image lists [MFC], combo boxes
- extended combo boxes [MFC], images
- images [MFC], combo box items
ms.assetid: dfff25fe-af70-47a2-8032-3901d1e6842d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7c9a701871631fead48c22b1ffb2cbc3c386b960
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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

