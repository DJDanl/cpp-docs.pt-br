---
title: Definindo as imagens para um item individual
ms.date: 11/04/2016
helpviewer_keywords:
- extended combo boxes [MFC], images
- images [MFC], combo box items
ms.assetid: bde83db8-23a7-4e35-837a-c86447d2c0af
ms.openlocfilehash: 61e152534dbea09fbca0af819b0847e82a1c4146
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50512067"
---
# <a name="setting-the-images-for-an-individual-item"></a>Definindo as imagens para um item individual

Os diferentes tipos de imagens usadas pelo item da caixa de combinação estendida são determinados pelos valores de *iImage*, *iSelectedImage*, e *iOverlay* os membros a [ COMBOBOXEXITEM](/windows/desktop/api/commctrl/ns-commctrl-tagcomboboxexitema) estrutura. Cada valor é o índice de uma imagem na lista de imagens associado do controle. Por padrão, esses membros são definidos como 0, fazendo com que o controle para não exibir nenhuma imagem do item. Se você quiser usar imagens para um item específico, você pode modificar a estrutura da mesma forma, ao inserir o item de caixa de combinação ou modificando um item de caixa de combinação existente.

## <a name="setting-the-image-for-a-new-item"></a>Definir a imagem para um novo Item

Se você estiver inserindo um novo item, inicializar o *iImage*, *iSelectedImage*, e *iOverlay* membros com os valores adequados da estrutura e, em seguida, inserir o item com uma chamada para [CComboBoxEx::InsertItem](../mfc/reference/ccomboboxex-class.md#insertitem).

O exemplo a seguir insere um novo item de caixa de combinação estendido (`cbi`) no controle de caixa de combinação estendido (`m_comboEx`), fornecendo os índices para todos os três estados de imagem:

[!code-cpp[NVC_MFCControlLadenDialog#12](../mfc/codesnippet/cpp/setting-the-images-for-an-individual-item_1.cpp)]

## <a name="setting-the-image-for-an-existing-item"></a>Definir a imagem de um Item existente

Se você estiver modificando um item existente, você precisará trabalhar com o *máscara* membro de uma **COMBOBOXEXITEM** estrutura.

#### <a name="to-modify-an-existing-item-to-use-images"></a>Para modificar um item existente para usar imagens

1. Declarar uma **COMBOBOXEXITEM** estruturar e defina as *máscara* membro de dados para os valores que você está interessado em modificar.

1. Usando essa estrutura, fazer uma chamada para [CComboBoxEx::GetItem](../mfc/reference/ccomboboxex-class.md#getitem).

1. Modificar a *máscara*, *iImage*, e *iSelectedImage* membros da estrutura retornada recentemente, usando os valores apropriados.

1. Fazer uma chamada para [CComboBoxEx::SetItem](../mfc/reference/ccomboboxex-class.md#setitem), passando a estrutura alterada.

O exemplo a seguir demonstra esse procedimento, trocando as imagens selecionadas e do terceiro item de caixa de combinação estendida:

[!code-cpp[NVC_MFCControlLadenDialog#13](../mfc/codesnippet/cpp/setting-the-images-for-an-individual-item_2.cpp)]

## <a name="see-also"></a>Consulte também

[Usando CComboBoxEx](../mfc/using-ccomboboxex.md)<br/>
[Controles](../mfc/controls-mfc.md)

