---
title: "Itens de lista e listas de imagens | Microsoft Docs"
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
  - "Classe CImageList, e itens de lista"
  - "Classe CListCtrl, listas de imagens"
  - "listas de imagens [C++], itens de lista"
  - "itens de lista, listas de imagens"
ms.assetid: 317d095f-f978-47da-acb6-7bfe7dd3bc69
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Itens de lista e listas de imagens
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um item “” em um controle de listas \([CListCtrl](../Topic/CListCtrl%20Class.md)\) consiste em um ícone, em um rótulo, e possivelmente outras informações em subitens \(“”\).  
  
 Os ícones para itens de controle de lista estão contidos em listas da imagem.  Uma lista de imagem conterá os ícones usados sem redução na exibição do ícone.  Um segundo, opcional, lista de imagem conterá versões secundárias dos mesmos ícones para uso em outras exibições do controle.  Uma terceira lista opcional contém imagens de “estado”, como caixas de seleção, para exibição na frente de ícones pequenos em certas exibições.  Uma quarta listagem opcional contém as imagens exibidas em itens individuais do cabeçalho do controle da lista.  
  
> [!NOTE]
>  Se um controle de exibição de lista é criado com o estilo de `LVS_SHAREIMAGELISTS` , você é responsável para destruição as listas de imagem quando não são mais em uso.  Especificar esse estilo se você atribuir as mesmas listas de imagem em vários controles de exibição de lista; se não, mais de um controle pode tentar destruir a mesma lista da imagem.  
  
 Para obter mais informações sobre os itens de lista, consulte [Listas da imagem da exibição de lista](http://msdn.microsoft.com/library/windows/desktop/bb774736) e [Itens e subitens](http://msdn.microsoft.com/library/windows/desktop/bb774736) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  Consulte também a classe [CImageList](../Topic/CImageList%20Class.md)*na referência de MFC* e o [Usando CImageList](../mfc/using-cimagelist.md) nesta família de artigos.  
  
 Para criar um controle na lista, você precisa fornecer as listas da imagem a ser usada quando você insere novos itens na lista.  O exemplo a seguir demonstra esse procedimento, onde `m_pImagelist` é um ponteiro de tipo `CImageList` e `m_listctrl` é um membro de dados de `CListCtrl` .  
  
 [!code-cpp[NVC_MFCControlLadenDialog#19](../mfc/codesnippet/CPP/list-items-and-image-lists_1.cpp)]  
  
 No entanto, se você não planeja exibir ícones no controle de exibição de lista ou na lista, você não precisa listas da imagem.  
  
## Consulte também  
 [Usando CListCtrl](../Topic/Using%20CListCtrl.md)   
 [Controles](../mfc/controls-mfc.md)