---
title: Definindo as imagens para um Item Individual | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- extended combo boxes [MFC], images
- images [MFC], combo box items
ms.assetid: bde83db8-23a7-4e35-837a-c86447d2c0af
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4d9cb74c2290292f44b8c6c9b8797890e759f315
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="setting-the-images-for-an-individual-item"></a>Definindo as imagens para um item individual
Os diferentes tipos de imagens usadas pelo item de caixa de combinação estendidas são determinados pelos valores a `iImage`, **iSelectedImage**, e **iOverlay** membros a [COMBOBOXEXITEM ](http://msdn.microsoft.com/library/windows/desktop/bb775746) estrutura. Cada valor é o índice de uma imagem na lista de imagens associado do controle. Por padrão, esses membros são definidos como 0, fazendo com que o controle para não exibir nenhuma imagem do item. Se você quiser usar imagens para um item específico, você pode modificar a estrutura da mesma forma, ao inserir o item de caixa de combinação ou modificando um item de caixa de combinação existente.  
  
## <a name="setting-the-image-for-a-new-item"></a>Definir a imagem para um novo Item  
 Se você estiver inserindo um novo item, inicializar o `iImage`, **iSelectedImage**, e **iOverlay** estrutura membros com os valores apropriados e, em seguida, inserir o item com uma chamada para [ CComboBoxEx::InsertItem](../mfc/reference/ccomboboxex-class.md#insertitem).  
  
 O exemplo a seguir insere um novo item de caixa de combinação estendido (`cbi`) no controle de caixa de combinação estendido (`m_comboEx`), fornecendo índices para todos os três estados de imagem:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#12](../mfc/codesnippet/cpp/setting-the-images-for-an-individual-item_1.cpp)]  
  
## <a name="setting-the-image-for-an-existing-item"></a>Definindo a imagem para um Item existente  
 Se você estiver modificando um item existente, você precisará trabalhar com o **máscara** membro de um **COMBOBOXEXITEM** estrutura.  
  
#### <a name="to-modify-an-existing-item-to-use-images"></a>Para modificar um item existente para usar imagens  
  
1.  Declarar um **COMBOBOXEXITEM** estrutura e defina o **máscara** membro de dados para os valores que você está interessado em modificar.  
  
2.  Usar essa estrutura, fazer uma chamada para [CComboBoxEx::GetItem](../mfc/reference/ccomboboxex-class.md#getitem).  
  
3.  Modificar o **máscara**, `iImage`, e **iSelectedImage** membros da estrutura retornado recentemente, usando os valores apropriados.  
  
4.  Fazer uma chamada para [CComboBoxEx::SetItem](../mfc/reference/ccomboboxex-class.md#setitem), passando a estrutura modificada.  
  
 O exemplo a seguir demonstra esse procedimento, trocando as imagens selecionadas e não selecionadas do terceiro item de caixa de combinação estendida:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#13](../mfc/codesnippet/cpp/setting-the-images-for-an-individual-item_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Usando CComboBoxEx](../mfc/using-ccomboboxex.md)   
 [Controles](../mfc/controls-mfc.md)

