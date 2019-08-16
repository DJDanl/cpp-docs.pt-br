---
title: Definindo as imagens para um item individual
ms.date: 11/04/2016
helpviewer_keywords:
- extended combo boxes [MFC], images
- images [MFC], combo box items
ms.assetid: bde83db8-23a7-4e35-837a-c86447d2c0af
ms.openlocfilehash: 177c06acfe665a43921b19407d9d357d4545e748
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69511280"
---
# <a name="setting-the-images-for-an-individual-item"></a>Definindo as imagens para um item individual

Os diferentes tipos de imagens usadas pelo item da caixa de combinação estendida são determinados pelos valores nos membros *iImage*, *iSelectedImage*e *IOverlay* da estrutura [COMBOBOXEXITEM](/windows/win32/api/commctrl/ns-commctrl-comboboxexitemw) . Cada valor é o índice de uma imagem na lista de imagens associadas do controle. Por padrão, esses membros são definidos como 0, fazendo com que o controle não exiba nenhuma imagem para o item. Se você quiser usar imagens para um item específico, poderá modificar a estrutura de acordo, seja ao inserir o item da caixa de combinação ou modificando um item da caixa de combinação existente.

## <a name="setting-the-image-for-a-new-item"></a>Definindo a imagem para um novo item

Se você estiver inserindo um novo item, inicialize os membros da estrutura *iImage*, *iSelectedImage*e *IOverlay* com os valores adequados e, em seguida, insira o item com uma chamada para [CComboBoxEx:: InsertItem](../mfc/reference/ccomboboxex-class.md#insertitem).

O exemplo a seguir insere um novo item de caixa de`cbi`combinação estendida () no controle de`m_comboEx`caixa de combinação estendida (), fornecendo índices para todos os três Estados de imagem:

[!code-cpp[NVC_MFCControlLadenDialog#12](../mfc/codesnippet/cpp/setting-the-images-for-an-individual-item_1.cpp)]

## <a name="setting-the-image-for-an-existing-item"></a>Definindo a imagem para um item existente

Se você estiver modificando um item existente, precisará trabalhar com o membro *Mask* de uma estrutura **COMBOBOXEXITEM** .

#### <a name="to-modify-an-existing-item-to-use-images"></a>Para modificar um item existente para usar imagens

1. Declare uma estrutura **COMBOBOXEXITEM** e defina o membro de dados *Mask* para os valores que você está interessado em Modificar.

1. Usando essa estrutura, faça uma chamada para [CComboBoxEx:: GetItem](../mfc/reference/ccomboboxex-class.md#getitem).

1. Modifique os membros *Mask*, *iImage*e *iSelectedImage* da estrutura retornada recentemente, usando os valores apropriados.

1. Faça uma chamada para [CComboBoxEx:: SetItem](../mfc/reference/ccomboboxex-class.md#setitem), passando a estrutura modificada.

O exemplo a seguir demonstra esse procedimento alternando as imagens selecionadas e não selecionadas do terceiro item da caixa de combinação estendida:

[!code-cpp[NVC_MFCControlLadenDialog#13](../mfc/codesnippet/cpp/setting-the-images-for-an-individual-item_2.cpp)]

## <a name="see-also"></a>Consulte também

[Usando CComboBoxEx](../mfc/using-ccomboboxex.md)<br/>
[Controles](../mfc/controls-mfc.md)
