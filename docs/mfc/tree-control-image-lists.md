---
title: Listas de imagens de controle de árvore
ms.date: 11/04/2016
helpviewer_keywords:
- images [MFC], lists in tree controls
- tree controls [MFC], image lists
- CTreeCtrl class [MFC], image lists
ms.assetid: f560c4f2-20d2-4d28-ac33-4017e65fb0a6
ms.openlocfilehash: 8f9e323244657ea6a7cc132deab6deedfcd1a167
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69513364"
---
# <a name="tree-control-image-lists"></a>Listas de imagens de controle de árvore

Cada item em um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) pode ter um par de imagens de bitmap associadas a ele. As imagens aparecem no lado esquerdo do rótulo de um item. Uma imagem é exibida quando o item é selecionado e a outra é exibida quando o item não está selecionado. Por exemplo, um item pode exibir uma pasta aberta quando ela é selecionada e uma pasta fechada quando não está selecionada.

Para usar imagens de item, você deve criar uma lista de imagens construindo um objeto [CImageList](../mfc/reference/cimagelist-class.md) e usando a função [CImageList:: Create](../mfc/reference/cimagelist-class.md#create) para criar a lista de imagens associada. Em seguida, adicione os bitmaps desejados à lista e associe a lista ao controle de árvore usando a função de membro [SetImageList](../mfc/reference/ctreectrl-class.md#setimagelist) . Por padrão, todos os itens exibem a primeira imagem na lista de imagens para os Estados selecionados e não selecionados. Você pode alterar o comportamento padrão de um determinado item especificando os índices das imagens selecionadas e não selecionadas ao adicionar o item ao controle de árvore usando a função de membro [InsertItem](../mfc/reference/ctreectrl-class.md#insertitem) . Você pode alterar os índices depois de adicionar um item usando a função de membro [SetItemImage](../mfc/reference/ctreectrl-class.md#setitemimage) .

As listas de imagens de um controle de árvore também podem conter imagens de sobreposição, que são projetadas para serem sobrepostas em imagens de item. Um valor diferente de zero em bits 8 a 11 de um estado de item de controle de árvore especifica o índice baseado em um de uma imagem de sobreposição (0 indica nenhuma imagem de sobreposição). Como um índice de 4 bits com base em um é usado, as imagens de sobreposição devem estar entre as 15 primeiras imagens nas listas de imagens. Para obter mais informações sobre Estados de item de controle de árvore, consulte [visão geral dos Estados de item de controle de árvore](../mfc/tree-control-item-states-overview.md) , anteriormente neste tópico.

Se uma lista de imagens de estado for especificada, um controle de árvore reserva espaço à esquerda do ícone de cada item para uma imagem de estado. Um aplicativo pode usar imagens de estado, como as caixas de seleção marcada e desmarcada, para indicar os Estados de item definido pelo aplicativo. Um valor diferente de zero em bits 12 a 15 especifica o índice baseado em um de uma imagem de estado (0 indica nenhuma imagem de estado).

Ao especificar o valor de **I_IMAGECALLBACK** em vez do índice de uma imagem, você pode atrasar a especificação da imagem selecionada ou não selecionada até que o item esteja prestes a ser redesenhado. O **I_IMAGECALLBACK** direciona o controle de árvore para consultar o aplicativo para o índice enviando a mensagem de notificação [TVN_GETDISPINFO](/windows/win32/Controls/tvn-getdispinfo) .

A função de membro [GetImageList](../mfc/reference/ctreectrl-class.md#getimagelist) recupera o identificador da lista de imagens de um controle de árvore. Essa função será útil se você precisar adicionar mais imagens à lista. Para obter mais informações sobre listas de imagens, consulte [usando CImageList](../mfc/using-cimagelist.md), [CImageList](../mfc/reference/cimagelist-class.md) na *referência do MFC*e [listas de imagens](/windows/win32/controls/image-lists) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
