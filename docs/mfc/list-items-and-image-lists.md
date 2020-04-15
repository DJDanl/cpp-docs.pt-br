---
title: Itens de lista e listas de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- CImageList class [MFC], and list items
- image lists [MFC], list items
- CListCtrl class [MFC], image lists
- list items [MFC], image lists
ms.assetid: 317d095f-f978-47da-acb6-7bfe7dd3bc69
ms.openlocfilehash: d378c6e07280349f9995981ad794039ebc015b25
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81353057"
---
# <a name="list-items-and-image-lists"></a>Itens de lista e listas de imagens

Um "item" em um controle de lista[(CListCtrl)](../mfc/reference/clistctrl-class.md)consiste em um ícone, um rótulo e possivelmente outras informações (em "subitems").

Os ícones para itens de controle de lista estão contidos em listas de imagens. Uma lista de imagens contém ícones de tamanho completo usados na exibição de ícones. Uma segunda lista de imagens, opcional, contém versões menores dos mesmos ícones para uso em outras exibições do controle. Uma terceira lista opcional contém imagens de "estado", como caixas de seleção, para exibição na frente dos pequenos ícones em determinadas visualizações. Uma quarta lista opcional contém imagens exibidas em itens individuais de cabeçalho do controle da lista.

> [!NOTE]
> Se um controle de exibição de lista for criado com o estilo LVS_SHAREIMAGELISTS, você será responsável por destruir as listas de imagens quando elas não estiverem mais em uso. Especificar esse estilo se você atribuir as mesmas listas de imagens a vários controles de exibição de lista; caso contrário, mais de um controle pode tentar destruir a mesma lista de imagens.

Para obter mais informações sobre itens de lista, consulte [Listas de imagens](/windows/win32/Controls/using-list-view-controls) e [itens e subitens](/windows/win32/Controls/using-list-view-controls) no Windows SDK. Veja também a classe [CImageList](../mfc/reference/cimagelist-class.md) na referência do *MFC* e [usando CImageList](../mfc/using-cimagelist.md) nesta família de artigos.

Para criar um controle de lista, você precisa fornecer listas de imagens para serem usadas quando você inserir novos itens na lista. O exemplo a seguir demonstra este procedimento, `CImageList` onde *m_pImagelist* é um ponteiro de tipo e *m_listctrl* é um `CListCtrl` membro de dados.

[!code-cpp[NVC_MFCControlLadenDialog#19](../mfc/codesnippet/cpp/list-items-and-image-lists_1.cpp)]

No entanto, se você não planeja exibir ícones na sua exibição de lista ou controle de lista, você não precisa de listas de imagens.

## <a name="see-also"></a>Confira também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
