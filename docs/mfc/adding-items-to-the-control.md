---
title: Adicionando itens ao controle | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CListCtrl class [MFC], adding items
ms.assetid: 715994bd-340d-4ad2-9882-411654137830
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eab0c7cb1aebf1675d078aa99941edfd9afdc5a8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="adding-items-to-the-control"></a>Adicionando itens ao controle
Para adicionar itens ao controle de lista ([CListCtrl](../mfc/reference/clistctrl-class.md)), chame uma das várias versões do [InsertItem](../mfc/reference/clistctrl-class.md#insertitem) função de membro, dependendo de quais informações você tem. Uma versão usa um [LV_ITEM](http://msdn.microsoft.com/library/windows/desktop/bb774760) estrutura que você preparar. Porque o `LV_ITEM` estrutura contém vários membros, você terá maior controle sobre os atributos do item de controle de lista.  
  
 Dois membros importantes (com o modo de exibição de relatório) da `LV_ITEM` estrutura são o `iItem` e `iSubItem` membros. O `iItem` membro é o índice de base zero do item está referenciando a estrutura e o `iSubItem` membro é o índice baseado em um de um subitem ou zero se a estrutura contém informações sobre um item. Com esses dois membros determinar, por item, o tipo e o valor das informações do subitem que são exibidas quando o controle de lista está no modo de exibição de relatório. Para obter mais informações, consulte [CListCtrl::SetItem](../mfc/reference/clistctrl-class.md#setitem).  
  
 Membros adicionais especificar o texto do item, ícone, estado e dados de item. "Item de dados" é um valor definido pelo aplicativo associado a um item de exibição de lista. Para obter mais informações sobre o `LV_ITEM` estrutura, consulte [CListCtrl::GetItem](../mfc/reference/clistctrl-class.md#getitem).  
  
 Outras versões do `InsertItem` levar um ou mais valores separados, correspondentes a membros de `LV_ITEM` estrutura, permitindo que você inicializar somente os membros que você deseja dar suporte. Geralmente, o controle de lista gerencia o armazenamento de itens de lista, mas você pode armazenar algumas das informações em seu aplicativo em vez disso, usando "itens". Para obter mais informações, consulte [itens e máscara de retorno de chamada](../mfc/callback-items-and-the-callback-mask.md) neste tópico e [itens e máscara de retorno de chamada](http://msdn.microsoft.com/library/windows/desktop/bb774736) no SDK do Windows.  
  
 Para obter mais informações, consulte [adicionar modo de exibição de lista de itens e Subitems](http://msdn.microsoft.com/library/windows/desktop/bb774736).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CListCtrl](../mfc/using-clistctrl.md)   
 [Controles](../mfc/controls-mfc.md)

