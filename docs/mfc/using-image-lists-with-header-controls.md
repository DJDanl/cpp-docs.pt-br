---
title: Usando listas de imagens com controles de cabeçalho
ms.date: 11/04/2016
helpviewer_keywords:
- header controls [MFC], image lists
- CHeaderCtrl class [MFC], image lists
- image lists [MFC], header controls
ms.assetid: d5e9b310-6278-406c-909c-eefa09549a47
ms.openlocfilehash: 8002c16d1cdf5e0683b642001409b6da9c260660
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366466"
---
# <a name="using-image-lists-with-header-controls"></a>Usando listas de imagens com controles de cabeçalho

Os itens de cabeçalho têm a capacidade de exibir uma imagem dentro de um item de cabeçalho. Esta imagem, armazenada em uma lista de imagens associadas, tem 16 x 16 pixels e tem as mesmas características das imagens de ícone usadas em um controle de exibição de lista. Para implementar esse comportamento com sucesso, você deve primeiro criar e inicializar a lista de imagens, associar a lista ao controle de cabeçalho e, em seguida, modificar os atributos do item cabeçalho que exibirá a imagem.

O procedimento a seguir ilustra os detalhes,`m_pHdrCtrl`usando um ponteiro para um`m_pHdrImages`controle de cabeçalho ( ) e um ponteiro para uma lista de imagens ( ).

### <a name="to-display-an-image-in-a-header-item"></a>Para exibir uma imagem em um item de cabeçalho

1. Construa uma nova lista de imagens (ou use um objeto de lista de imagens existente) usando o construtor [CImageList,](../mfc/reference/cimagelist-class.md) armazenando o ponteiro resultante.

1. Inicialize o novo objeto da lista de imagens chamando [CImageList::Create](../mfc/reference/cimagelist-class.md#create). O código a seguir é um exemplo desta chamada.

   [!code-cpp[NVC_MFCControlLadenDialog#15](../mfc/codesnippet/cpp/using-image-lists-with-header-controls_1.cpp)]

1. Adicione as imagens para cada item de cabeçalho. O código a seguir adiciona duas imagens predefinidas.

   [!code-cpp[NVC_MFCControlLadenDialog#16](../mfc/codesnippet/cpp/using-image-lists-with-header-controls_2.cpp)]

1. Associe a lista de imagens com o controle de cabeçalho com uma chamada para [CHeaderCtrl::SetImageList](../mfc/reference/cheaderctrl-class.md#setimagelist).

1. Modifique o item do cabeçalho para exibir uma imagem da lista de imagens associada. O exemplo a seguir atribui `m_phdrImages`a primeira imagem, de `m_pHdrCtrl`, ao primeiro item de cabeçalho, .

   [!code-cpp[NVC_MFCControlLadenDialog#17](../mfc/codesnippet/cpp/using-image-lists-with-header-controls_3.cpp)]

Para obter informações detalhadas sobre os valores dos parâmetros utilizados, consulte o [CHeaderCtrl](../mfc/reference/cheaderctrl-class.md)pertinente .

> [!NOTE]
> É possível ter vários controles usando a mesma lista de imagens. Por exemplo, em um controle de exibição de lista padrão, pode haver uma lista de imagens de imagem (de 16 x 16 pixels) usada tanto pela pequena exibição de ícone de um controle de exibição de lista quanto pelos itens de cabeçalho do controle de exibição da lista.

## <a name="see-also"></a>Confira também

[Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)
