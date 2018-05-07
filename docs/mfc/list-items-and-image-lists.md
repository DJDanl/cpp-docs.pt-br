---
title: Itens de lista e listas de imagens | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CImageList class [MFC], and list items
- image lists [MFC], list items
- CListCtrl class [MFC], image lists
- list items [MFC], image lists
ms.assetid: 317d095f-f978-47da-acb6-7bfe7dd3bc69
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f6bd7a97330a8a646a880bf229562dbec9a70181
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="list-items-and-image-lists"></a>Itens de lista e listas de imagens
Um "item" em um controle de lista ([CListCtrl](../mfc/reference/clistctrl-class.md)) consiste em um ícone, um rótulo e possivelmente outras informações (em "subitens").  
  
 Os ícones de itens de controle de lista estão contidos em listas de imagens. Uma lista de imagem contém ícones em tamanho normal usadas no modo de exibição de ícone. Uma lista de imagens em segundo lugar, opcional, contém versões menores dos ícones a mesma para uso em outros modos de exibição do controle. Uma lista opcional de terceira contém imagens de "estado", como caixas de seleção para exibição na frente de ícones pequenos em certos modos de exibição. Uma lista opcional quarta contém imagens que são exibidas em itens individuais do cabeçalho do controle de lista.  
  
> [!NOTE]
>  Se um controle de exibição de lista é criado com o `LVS_SHAREIMAGELISTS` estilo, você é responsável por destruindo as listas de imagens quando elas não estão mais em uso. Especifique esse estilo se você atribuir a mesma imagem listas para vários controles de exibição de lista; Caso contrário, mais de um controle pode tentar destruir a mesma lista de imagem.  
  
 Para obter mais informações sobre itens de lista, consulte [listas de imagens de exibição de lista](http://msdn.microsoft.com/library/windows/desktop/bb774736) e [itens e Subitems](http://msdn.microsoft.com/library/windows/desktop/bb774736) no SDK do Windows. Consulte também a classe [CImageList](../mfc/reference/cimagelist-class.md) no *referência MFC* e [usando CImageList](../mfc/using-cimagelist.md) nesta família de artigos.  
  
 Para criar um controle de lista, você precisa fornecer as listas de imagens a ser usado quando você insere novos itens na lista. O exemplo a seguir demonstra esse procedimento, onde `m_pImagelist` é um ponteiro de tipo `CImageList` e `m_listctrl` é um `CListCtrl` membro de dados.  
  
 [!code-cpp[NVC_MFCControlLadenDialog#19](../mfc/codesnippet/cpp/list-items-and-image-lists_1.cpp)]  
  
 No entanto, se você não planeja exibir ícones no modo de exibição de lista ou controle de lista, listas de imagens não é necessário.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CListCtrl](../mfc/using-clistctrl.md)   
 [Controles](../mfc/controls-mfc.md)

