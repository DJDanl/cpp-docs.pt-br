---
title: Usando listas de imagens com controles de cabeçalho | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- header controls [MFC], image lists
- CHeaderCtrl class [MFC], image lists
- image lists [MFC], header controls
ms.assetid: d5e9b310-6278-406c-909c-eefa09549a47
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2da3737b54c53903f8fc8ff30cccba6165cbde45
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="using-image-lists-with-header-controls"></a>Usando listas de imagens com controles de cabeçalho
Itens de cabeçalho tem a capacidade de exibir uma imagem em um item de cabeçalho. Essa imagem, armazenada em uma lista de imagem associado é 16x16 pixels e tem as mesmas características que as imagens de ícone usadas em um controle de exibição de lista. Para implementar com êxito a esse comportamento, primeiro crie e inicializar a lista de imagens, associar a lista de controle de cabeçalho e, em seguida, modifique os atributos do item de cabeçalho que exibirá a imagem.  
  
 O procedimento a seguir ilustra os detalhes, usando um ponteiro para um controle de cabeçalho (`m_pHdrCtrl`) e um ponteiro para uma lista de imagens (`m_pHdrImages`).  
  
### <a name="to-display-an-image-in-a-header-item"></a>Para exibir uma imagem em um item de cabeçalho  
  
1.  Criar uma nova lista de imagem (ou usar um objeto de lista de imagem existente) usando o [CImageList](../mfc/reference/cimagelist-class.md) construtor, armazenando o ponteiro resultante.  
  
2.  Inicialize o novo objeto de lista de imagem chamando [CImageList::Create](../mfc/reference/cimagelist-class.md#create). O código a seguir é um exemplo desta chamada.  
  
     [!code-cpp[NVC_MFCControlLadenDialog#15](../mfc/codesnippet/cpp/using-image-lists-with-header-controls_1.cpp)]  
  
3.  Adicione imagens para cada item de cabeçalho. O código a seguir adiciona duas imagens predefinidas.  
  
     [!code-cpp[NVC_MFCControlLadenDialog#16](../mfc/codesnippet/cpp/using-image-lists-with-header-controls_2.cpp)]  
  
4.  Associar a lista de imagens com o controle de cabeçalho com uma chamada para [CHeaderCtrl::SetImageList](../mfc/reference/cheaderctrl-class.md#setimagelist).  
  
5.  Modifica o item de cabeçalho para exibir uma imagem da lista de imagens associado. O exemplo a seguir atribui a primeira imagem, de `m_phdrImages`, para o primeiro item de cabeçalho, `m_pHdrCtrl`.  
  
     [!code-cpp[NVC_MFCControlLadenDialog#17](../mfc/codesnippet/cpp/using-image-lists-with-header-controls_3.cpp)]  
  
 Para obter informações detalhadas sobre os valores de parâmetro usados, consulte o pertinentes [CHeaderCtrl](../mfc/reference/cheaderctrl-class.md).  
  
> [!NOTE]
>  É possível ter vários controles usando a mesma lista de imagens. Por exemplo, um controle de exibição de lista padrão, pode haver uma lista de imagens (de imagens de 16 x 16 pixels) usada, a exibição de ícone pequeno de um controle de exibição de lista e os itens de cabeçalho do controle de exibição de lista.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)

