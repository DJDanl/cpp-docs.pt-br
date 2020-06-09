---
title: Adicionando itens ao controle
ms.date: 11/04/2016
helpviewer_keywords:
- CListCtrl class [MFC], adding items
ms.assetid: 715994bd-340d-4ad2-9882-411654137830
ms.openlocfilehash: 5cc1c7a921cf6d6ba2c0f968012b48bfcaef0658
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623373"
---
# <a name="adding-items-to-the-control"></a>Adicionando itens ao controle

Para adicionar itens ao controle de lista ([CListCtrl](reference/clistctrl-class.md)), chame uma das várias versões da função de membro [InsertItem](reference/clistctrl-class.md#insertitem) , dependendo de quais informações você tem. Uma versão usa uma estrutura [LVITEM](/windows/win32/api/commctrl/ns-commctrl-lvitemw) que você prepara. Como a `LVITEM` estrutura contém vários membros, você tem maior controle sobre os atributos do item de controle de lista.

Dois membros importantes (em relação ao modo de exibição de relatório) da `LVITEM` estrutura são `iItem` os `iSubItem` Membros e. O `iItem` membro é o índice de base zero do item que a estrutura está referenciando e o `iSubItem` membro é o índice com base em um subitem, ou zero se a estrutura contém informações sobre um item. Com esses dois membros, você determina, por item, o tipo e o valor de informações de subitem que são exibidas quando o controle de lista está no modo de exibição de relatório. Para obter mais informações, consulte [CListCtrl:: SetItem](reference/clistctrl-class.md#setitem).

Membros adicionais especificam os dados de texto, ícone, estado e item do item. "Dados do item" é um valor definido pelo aplicativo associado a um item de exibição de lista. Para obter mais informações sobre a `LVITEM` estrutura, consulte [CListCtrl:: GetItem](reference/clistctrl-class.md#getitem).

Outras versões do `InsertItem` usam um ou mais valores separados, correspondentes aos membros na `LVITEM` estrutura, permitindo que você inicialize somente os membros aos quais deseja dar suporte. Em geral, o controle de lista gerencia o armazenamento para itens de lista, mas você pode armazenar algumas das informações em seu aplicativo, usando "itens de retorno de chamada". Para obter mais informações, consulte [itens de retorno de chamada e a máscara de retorno de chamada](callback-items-and-the-callback-mask.md) neste tópico e [itens de retorno de chamada e a máscara de retorno de chamada](/windows/win32/Controls/using-list-view-controls) no SDK do Windows.

Para obter mais informações, consulte [Adicionar itens de exibição de lista e subitens](/windows/win32/Controls/using-list-view-controls).

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](using-clistctrl.md)<br/>
[Controles](controls-mfc.md)
