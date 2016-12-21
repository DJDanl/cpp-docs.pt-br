---
title: "Listas de imagens de controle de &#225;rvore | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CTreeCtrl, listas de imagens"
  - "imagens [C++], listas em controles de árvore"
  - "controles em árvore, listas de imagens"
ms.assetid: f560c4f2-20d2-4d28-ac33-4017e65fb0a6
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Listas de imagens de controle de &#225;rvore
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada item em um controle de árvore[CTreeCtrl](../mfc/reference/ctreectrl-class.md)\(\) pode ter um par de imagens de bitmap associadas a eles.  As imagens aparecerão no lado esquerdo do rótulo de um item.  Uma imagem é exibida quando o item é selecionado, e a outra é exibida quando o item não é selecionado.  Por exemplo, um item pode exibir uma pasta aberta quando está selecionado e uma pasta fechado quando não está selecionado.  
  
 Para usar imagens de item, você deve criar uma lista de imagem construindo um objeto de [CImageList](../Topic/CImageList%20Class.md) e usando a função de [CImageList::Create](../Topic/CImageList::Create.md) para criar a lista de imagem associado.  Adicione os bitmaps desejados à lista, e associar a lista com o controle de árvore usando a função de membro de [SetImageList](../Topic/CTreeCtrl::SetImageList.md) .  Por padrão, todos os itens exibem a primeira imagem na lista de imagem para os estados selecionados e nonselected.  Você pode alterar o comportamento padrão para um item específico especificando os índices das imagens selecionadas e nonselected ao adicionar o item ao controle de árvore usando a função de membro de [InsertItem](../Topic/CTreeCtrl::InsertItem.md) .  Você pode alterar os índices depois de adicionar um item usando a função de membro de [SetItemImage](../Topic/CTreeCtrl::SetItemImage.md) .  
  
 As listas de imagem de um controle de árvore também podem conter as imagens de sobreposição, que é criada para ser sobrepostos em imagens do item.  Um valor diferente de zero nos bits 8 a 11 do estado de um item do controle de árvore especifica o índice de uma imagem de sobreposição \(0 não indica nenhuma imagem da sobreposição\).  Como um de 4 bits, índice for usado, as imagens de sobreposição devem estar entre as primeiras 15 imagens em listas da imagem.  Para obter mais informações sobre os estados do item do controle de árvore, consulte [O item do controle de árvore indica a visão geral](../mfc/tree-control-item-states-overview.md) anteriormente neste tópico.  
  
 Se uma lista de imagem do estado for especificada, um espaço reservas de controle de árvore à esquerda do ícone de cada item para uma imagem do estado.  Um aplicativo pode usar imagens de estado, como caixas de seleção marcadas e desmarcadas, para indicar estados definidos pelo aplicativo do item.  Um valor diferente de zero nos bits 12 a 15 especifica o índice de uma imagem do estado \(0 não indica nenhuma imagem do estado\).  
  
 Especificando o valor de **I\_IMAGECALLBACK** em vez do índice de uma imagem, você pode retardar especificar a imagem selecionada ou nonselected até que o item está prestes a ser redesenhado.  **I\_IMAGECALLBACK** direciona o controle de árvore para consultar o aplicativo para o índice enviando uma notificação de [TVN\_GETDISPINFO](http://msdn.microsoft.com/library/windows/desktop/bb773518) .  
  
 A função de membro de [GetImageList](../Topic/CTreeCtrl::GetImageList.md) recupera o identificador da lista de imagem de um controle de árvore.  Essa função é útil se você precisar adicionar mais imagens na lista.  Para obter mais informações sobre listas da imagem, consulte [Usando CImageList](../mfc/using-cimagelist.md), [CImageList](../Topic/CImageList%20Class.md)*na referência de MFC*, e [Listas de imagem](http://msdn.microsoft.com/library/windows/desktop/bb761389) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Consulte também  
 [Usando CTreeCtrl](../Topic/Using%20CTreeCtrl.md)   
 [Controles](../mfc/controls-mfc.md)