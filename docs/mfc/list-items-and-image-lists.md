---
title: Itens de lista e listas de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- CImageList class [MFC], and list items
- image lists [MFC], list items
- CListCtrl class [MFC], image lists
- list items [MFC], image lists
ms.assetid: 317d095f-f978-47da-acb6-7bfe7dd3bc69
ms.openlocfilehash: 14abf72551d39b2d1b2069bd17da308b39d7f6cc
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621408"
---
# <a name="list-items-and-image-lists"></a>Itens de lista e listas de imagens

Um "item" em um controle de lista ([CListCtrl](reference/clistctrl-class.md)) consiste em um ícone, um rótulo e, possivelmente, outras informações (em "subitens").

Os ícones para itens de controle de lista estão contidos em listas de imagens. Uma lista de imagens contém ícones de tamanho completo usados na exibição de ícones. Uma segunda lista de imagens opcional contém versões menores dos mesmos ícones para uso em outras exibições do controle. Uma terceira lista opcional contém imagens "estado", como caixas de seleção, para exibição na frente dos ícones pequenos em determinadas exibições. Uma quarta lista opcional contém imagens que são exibidas em itens de cabeçalho individuais do controle de lista.

> [!NOTE]
> Se um controle de exibição de lista for criado com o estilo de LVS_SHAREIMAGELISTS, você será responsável por destruir as listas de imagens quando elas não estiverem mais em uso. Especifique este estilo se você atribuir as mesmas listas de imagens a vários controles de exibição de lista; caso contrário, mais de um controle poderá tentar destruir a mesma lista de imagens.

Para obter mais informações sobre itens de lista, consulte [listas de imagens de exibição de lista](/windows/win32/Controls/using-list-view-controls) e [itens e subitens](/windows/win32/Controls/using-list-view-controls) no SDK do Windows. Consulte também a classe [CImageList](reference/cimagelist-class.md) na *referência do MFC* e [usando o CImageList](using-cimagelist.md) nesta família de artigos.

Para criar um controle de lista, você precisa fornecer listas de imagens a serem usadas quando inserir novos itens na lista. O exemplo a seguir demonstra esse procedimento, em que *m_pImagelist* é um ponteiro do tipo `CImageList` e *m_listctrl* é um `CListCtrl` membro de dados.

[!code-cpp[NVC_MFCControlLadenDialog#19](codesnippet/cpp/list-items-and-image-lists_1.cpp)]

No entanto, se você não planeja exibir ícones na exibição de lista ou no controle de lista, não precisa de listas de imagens.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](using-clistctrl.md)<br/>
[Controles](controls-mfc.md)
