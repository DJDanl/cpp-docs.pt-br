---
title: Adicionando itens ao controle
ms.date: 11/04/2016
helpviewer_keywords:
- CListCtrl class [MFC], adding items
ms.assetid: 715994bd-340d-4ad2-9882-411654137830
ms.openlocfilehash: 88e008f06fb669db1c13872b1a58555eeb357d86
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57304594"
---
# <a name="adding-items-to-the-control"></a>Adicionando itens ao controle

Para adicionar itens ao controle de lista ([CListCtrl](../mfc/reference/clistctrl-class.md)), chame uma das várias versões dos [InsertItem](../mfc/reference/clistctrl-class.md#insertitem) função de membro, dependendo das informações que você tem. Uma versão usa uma [LV_ITEM](/windows/desktop/api/commctrl/ns-commctrl-taglvitema) estrutura que você prepara. Porque o `LV_ITEM` estrutura contém vários membros, você tem maior controle sobre os atributos do item da lista de controle.

Dois membros importantes (em relação ao modo de exibição de relatório) da `LV_ITEM` estrutura são as `iItem` e `iSubItem` membros. O `iItem` membro é o índice baseado em zero do item que está fazendo referência à estrutura e o `iSubItem` membro é o índice baseado em um de um subitem, ou zero se a estrutura contém informações sobre um item. Com esses dois membros determinar, por item, o tipo e o valor de informações do subitem que são exibidas quando o controle de lista está no modo de exibição de relatório. Para obter mais informações, consulte [CListCtrl::SetItem](../mfc/reference/clistctrl-class.md#setitem).

Membros adicionais especificam texto, ícone, estado e dados de item do item. "Dados de item" é um valor definido pelo aplicativo associado a um item de exibição de lista. Para obter mais informações sobre o `LV_ITEM` estrutura, consulte [CListCtrl::GetItem](../mfc/reference/clistctrl-class.md#getitem).

Outras versões do `InsertItem` levar um ou mais valores separados, correspondentes a membros no `LV_ITEM` estrutura, permitindo que você inicialize somente os membros que você deseja dar suporte. Em geral, o controle de lista gerencia o armazenamento de itens de lista, mas você pode armazenar algumas das informações em seu aplicativo em vez disso, usando "itens de retorno de chamada". Para obter mais informações, consulte [itens de retorno de chamada e a máscara de retorno de chamada](../mfc/callback-items-and-the-callback-mask.md) neste tópico e [itens de retorno de chamada e a máscara de retorno de chamada](/windows/desktop/Controls/using-list-view-controls) no SDK do Windows.

Para obter mais informações, consulte [adicionando o modo de exibição de lista de itens e subitens](/windows/desktop/Controls/using-list-view-controls).

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
