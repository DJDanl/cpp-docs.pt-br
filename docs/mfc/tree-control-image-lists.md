---
title: Listas de imagens de controle de árvore | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- images [MFC], lists in tree controls
- tree controls [MFC], image lists
- CTreeCtrl class [MFC], image lists
ms.assetid: f560c4f2-20d2-4d28-ac33-4017e65fb0a6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 184a68ec29e806b5bb914d8744ff5c1f334db5ea
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43203760"
---
# <a name="tree-control-image-lists"></a>Listas de imagens de controle de árvore
Cada item em um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) pode ter um par de imagens de bitmap associados a ele. As imagens aparecerão no lado esquerdo do rótulo do item. Uma imagem é exibida quando o item está selecionado e o outro é exibido quando o item não está selecionado. Por exemplo, um item pode exibir uma pasta aberta quando ele é selecionado e uma pasta fechada quando não estiver selecionada.  
  
 Para usar imagens do item, você deve criar uma lista de imagens, criando uma [CImageList](../mfc/reference/cimagelist-class.md) objeto e usando o [CImageList::Create](../mfc/reference/cimagelist-class.md#create) função para criar a lista de imagem associado. Em seguida, adicione os bitmaps desejados à lista e associá-la com o controle de árvore usando o [SetImageList](../mfc/reference/ctreectrl-class.md#setimagelist) função de membro. Por padrão, todos os itens exibem a primeira imagem na lista de imagens para os estados selecionados e não selecionados. Você pode alterar o comportamento padrão para um item específico, especificando os índices das imagens selecionadas e não selecionados ao adicionar o item para o controle de árvore usando o [InsertItem](../mfc/reference/ctreectrl-class.md#insertitem) função de membro. Você pode alterar os índices depois de adicionar um item usando o [SetItemImage](../mfc/reference/ctreectrl-class.md#setitemimage) função de membro.  
  
 Listas de imagens de um controle de árvore também podem conter imagens de sobreposição, que são projetadas para sobrepostas em imagens do item. Um valor diferente de zero em bits 8 a 11 do estado de um item controle de árvore Especifica o índice baseado em um de uma imagem de sobreposição (0 não indica que nenhuma imagem de sobreposição). Como um índice de 4 bits, baseado em um for usado, as imagens de sobreposição devem ser entre as primeiros 15 imagens nas listas de imagens. Para obter mais informações sobre estados de item de controle de árvore, consulte [visão geral dos Estados de Item de controle de árvore](../mfc/tree-control-item-states-overview.md) anteriormente neste tópico.  
  
 Se uma lista de imagens de estado for especificada, um controle de árvore reserva espaço à esquerda do ícone de cada item para uma imagem de estado. Um aplicativo pode usar imagens de estado, como caixas de seleção marcadas e desmarcadas, para indicar estados de item definido pelo aplicativo. Um valor diferente de zero em bits 12 a 15 Especifica o índice baseado em um de uma imagem de estado (0 não indica que nenhuma imagem de estado).  
  
 Especificando o **I_IMAGECALLBACK** valor em vez do índice de uma imagem, você pode atrasar especificando a imagem selecionada ou não selecionada até que o item está prestes a ser redesenhado. **I_IMAGECALLBACK** direciona o controle de árvore para consultar o aplicativo para o índice, enviando o [TVN_GETDISPINFO](/windows/desktop/Controls/tvn-getdispinfo) mensagem de notificação.  
  
 O [GetImageList](../mfc/reference/ctreectrl-class.md#getimagelist) função de membro recupera o identificador de um controle de árvore lista de imagens. Essa função é útil se você precisar adicionar mais imagens à lista. Para obter mais informações sobre listas de imagens, consulte [usando CImageList](../mfc/using-cimagelist.md), [CImageList](../mfc/reference/cimagelist-class.md) no *referência da MFC*, e [listas de imagens](https://msdn.microsoft.com/library/windows/desktop/bb761389) no Windows SDK.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

