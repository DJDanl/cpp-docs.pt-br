---
title: "Usando listas de imagens em um controle de caixa de combina&#231;&#227;o estendido | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "caixas de combinação estendidas, imagens"
  - "listas de imagens [C++], caixas de combinação"
  - "imagens [C++], itens de caixa de combinação"
ms.assetid: dfff25fe-af70-47a2-8032-3901d1e6842d
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando listas de imagens em um controle de caixa de combina&#231;&#227;o estendido
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O recurso principal de controles estendidos da caixa de combinação é a capacidade de associação imagens de uma lista de imagem com os itens individuais em um controle da caixa de combinação.  Cada item pode exibir três imagens diferentes: um para seu estado selecionado, um para seu estado nonselected, e um terço de uma imagem de sobreposição.  
  
 O procedimento a seguir associa uma lista de imagem com um controle estendido da caixa de combinação:  
  
### Para associar uma lista de imagem com um controle estendido da caixa de combinação  
  
1.  Cria uma nova lista de imagem \(ou use um objeto existente na lista de imagem\), usando o construtor de [CImageList](../Topic/CImageList%20Class.md) e o armazenamento do ponteiro resultante.  
  
2.  Inicializar o novo objeto da lista de imagem chamando [CImageList::Create](../Topic/CImageList::Create.md).  O código a seguir é um exemplo dessa chamada.  
  
     [!code-cpp[NVC_MFCControlLadenDialog#10](../mfc/codesnippet/CPP/using-image-lists-in-an-extended-combo-box-control_1.cpp)]  
  
3.  Adicionar imagens opcionais para cada estado possível: selecionado ou nonselected, e uma sobreposição.  O código a seguir adiciona três imagens predefinidas.  
  
     [!code-cpp[NVC_MFCControlLadenDialog#11](../mfc/codesnippet/CPP/using-image-lists-in-an-extended-combo-box-control_2.cpp)]  
  
4.  Associar a lista de imagem com o controle com uma chamada a [CComboBoxEx::SetImageList](../Topic/CComboBoxEx::SetImageList.md).  
  
 A lista de imagem associada uma vez ao controle, você pode especificar individualmente as imagens que cada item usará para os três estados possíveis.  Para obter mais informações, consulte [Definindo as imagens de um item individual](../mfc/setting-the-images-for-an-individual-item.md).  
  
## Consulte também  
 [Usando CComboBoxEx](../mfc/using-ccomboboxex.md)   
 [Controles](../mfc/controls-mfc.md)