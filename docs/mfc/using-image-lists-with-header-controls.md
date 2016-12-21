---
title: "Usando listas de imagens com controles de cabe&#231;alho | Microsoft Docs"
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
  - "Classe CHeaderCtrl, listas de imagens"
  - "controles de cabeçalho, listas de imagens"
  - "listas de imagens [C++], controles de cabeçalho"
ms.assetid: d5e9b310-6278-406c-909c-eefa09549a47
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando listas de imagens com controles de cabe&#231;alho
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Itens de cabeçalho tem a capacidade de exibir uma imagem em um item de cabeçalho.  Esta imagem, armazenada em uma lista associado à imagem, é de 16 x 16 pixels e tem as mesmas características que as imagens de ícones usados em um controle de exibição de lista.  Para implementar com êxito esse comportamento, você deve primeiro criar e iniciar a lista da imagem, associa a lista com o controle de cabeçalho, e modificar os atributos do item de cabeçalho que exibirá a imagem.  
  
 O procedimento a seguir explica os detalhes, usando um ponteiro para um controle de cabeçalho \(`m_pHdrCtrl`\) e um ponteiro para uma lista de imagem \(`m_pHdrImages`\).  
  
### Para exibir uma imagem em um item de cabeçalho  
  
1.  Cria uma nova lista de imagem \(ou use um objeto existente na lista de imagem\) que utiliza o construtor de [CImageList](../Topic/CImageList%20Class.md) , o armazenamento do ponteiro resultante.  
  
2.  Inicializar o novo objeto da lista de imagem chamando [CImageList::Create](../Topic/CImageList::Create.md).  O código a seguir é um exemplo dessa chamada.  
  
     [!code-cpp[NVC_MFCControlLadenDialog#15](../mfc/codesnippet/CPP/using-image-lists-with-header-controls_1.cpp)]  
  
3.  Adicionar imagens para cada item do cabeçalho.  O código a seguir adiciona duas imagens predefinidas.  
  
     [!code-cpp[NVC_MFCControlLadenDialog#16](../mfc/codesnippet/CPP/using-image-lists-with-header-controls_2.cpp)]  
  
4.  Associar a lista de imagem com o controle de cabeçalho com uma chamada a [CHeaderCtrl::SetImageList](../Topic/CHeaderCtrl::SetImageList.md).  
  
5.  Modifique o item do cabeçalho para exibir uma imagem na lista de imagem associado.  O exemplo a seguir atribui a primeira imagem, de `m_phdrImages`, o primeiro item de cabeçalho, `m_pHdrCtrl`.  
  
     [!code-cpp[NVC_MFCControlLadenDialog#17](../mfc/codesnippet/CPP/using-image-lists-with-header-controls_3.cpp)]  
  
 Para obter informações detalhadas sobre os valores de parâmetro usados, consulte [CHeaderCtrl](../Topic/CHeaderCtrl%20Class.md)pertinentes.  
  
> [!NOTE]
>  É possível ter várias controles usando a mesma lista da imagem.  Por exemplo, em um controle padrão da exibição de lista, poderá haver uma lista de imagem \(16 x 16 pixels de imagens\) usada pela exibição pequena de ícone de um controle de exibição de lista e os itens do cabeçalho da exibição de lista controlam.  
  
## Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)