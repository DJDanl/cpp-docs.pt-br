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
ms.openlocfilehash: 86395798a91852860b20f40f3ee0a53c745816c0
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46440583"
---
# <a name="list-items-and-image-lists"></a>Itens de lista e listas de imagens

Um "item" em um controle de lista ([CListCtrl](../mfc/reference/clistctrl-class.md)) consiste em um ícone, um rótulo e, possivelmente, outras informações (em "subitens").

Os ícones para itens de controle de lista estão contidos em listas de imagens. Uma lista de imagem contém ícones em tamanho normal usadas no modo de exibição de ícone. Uma lista de imagens em segundo lugar, opcional, contém versões menores dos mesmos ícones para uso em outros modos de exibição do controle. Uma terceira lista opcional contém imagens de "estado", como caixas de seleção, para exibição na frente de ícones pequenos em determinados modos de exibição. Uma quarta lista opcional contém imagens que são exibidas em itens individuais de cabeçalho do controle de lista.

> [!NOTE]
>  Se um controle de exibição de lista é criado com o estilo LVS_SHAREIMAGELISTS, você é responsável por destruir as listas de imagens, quando eles não estão mais em uso. Especifique esse estilo se você atribuir a mesma imagem listas para vários controles de exibição de lista; Caso contrário, mais de um controle pode tentar destruir a mesma lista de imagens.

Para obter mais informações sobre itens de lista, consulte [listas de imagens do modo de exibição de lista](/windows/desktop/Controls/using-list-view-controls) e [itens e subitens](/windows/desktop/Controls/using-list-view-controls) no SDK do Windows. Consulte também a classe [CImageList](../mfc/reference/cimagelist-class.md) na *referência da MFC* e [usando CImageList](../mfc/using-cimagelist.md) nessa família de artigos.

Para criar um controle de lista, você precisará fornecer listas de imagens a serem usados ao inserir novos itens na lista. O exemplo a seguir demonstra esse procedimento, onde *m_pImagelist* é um ponteiro de tipo `CImageList` e *m_listctrl* é um `CListCtrl` membro de dados.

[!code-cpp[NVC_MFCControlLadenDialog#19](../mfc/codesnippet/cpp/list-items-and-image-lists_1.cpp)]

No entanto, se você não planeja exibir ícones em seu modo de exibição de lista ou um controle de lista, você não precisa de listas de imagens.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

