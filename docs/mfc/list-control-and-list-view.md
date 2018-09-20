---
title: Controle de lista e exibição de lista | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CListView class [MFC], and CListCtrl
- views [MFC], list and list control
- CListCtrl class [MFC], and CListView
- list views [MFC]
- list controls [MFC], List view
ms.assetid: 7aee1c48-b158-4399-be0b-be366993665e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9925bd7188faa97ab5aa32dc2830dc6498726381
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46436748"
---
# <a name="list-control-and-list-view"></a>Controle e exibição de lista

Para sua conveniência, o MFC encapsula o controle de lista de duas maneiras. Você pode usar controles de lista:

- Diretamente, incorporando uma [CListCtrl](../mfc/reference/clistctrl-class.md) objeto em uma classe de caixa de diálogo.

- Indiretamente, usando a classe [CListView](../mfc/reference/clistview-class.md).

`CListView` torna mais fácil integrar a um controle de lista com a arquitetura de exibição/documento MFC, encapsulando o controle de maneira muito parecida [CEditView](../mfc/reference/ceditview-class.md) encapsula um controle de edição: o controle preenche a área da superfície inteira de uma exibição do MFC. (O modo de exibição *está* o controle, convertido em `CListView`.)

Um `CListView` objeto herda [CCtrlView](../mfc/reference/cctrlview-class.md) e sua base de classes e adiciona uma função de membro para recuperar o controle de lista subjacente. Use membros de modo de exibição para trabalhar com o modo de exibição como uma exibição. Use o [GetListCtrl](../mfc/reference/clistview-class.md#getlistctrl) a função de membro para obter acesso a funções de membro do controle de lista. Use esses membros para:

- Adicionar, excluir ou manipular "itens" na lista.

- Definir ou obter atributos de controle de lista.

Para obter uma referência para o `CListCtrl` subjacente uma `CListView`, chame `GetListCtrl` de sua classe de exibição de lista:

[!code-cpp[NVC_MFCListView#4](../atl/reference/codesnippet/cpp/list-control-and-list-view_1.cpp)]

Este tópico descreve as duas maneiras de usar o controle de lista.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

