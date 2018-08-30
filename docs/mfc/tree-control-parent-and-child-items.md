---
title: Controle itens pai e filho de árvore | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- parent items in CTreeCtrl [MFC]
- child items in tree control [MFC]
- CTreeCtrl class [MFC], parent and child items
- tree controls [MFC], parent and child items
ms.assetid: abcea1e4-fe9b-40d9-86dc-1db235f8f103
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1c56885300b05cfb038dd1a8484ae57648bf9357
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43208426"
---
# <a name="tree-control-parent-and-child-items"></a>Itens pai e filho do controle de árvore
Qualquer item em um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) pode ter uma lista de subitens, que são chamados de itens filhos, associados a ele. Um item que tem um ou mais itens filho é chamado de um item pai. Um item filho é exibido abaixo de seu item pai e é recuado para indicar que ele seja subordinado ao pai. Um item que não tem nenhum pai está no topo da hierarquia e é chamado de um item de raiz.  
  
 Em um determinado momento, o estado da lista de um item pai dos itens filhos pode ser expandido ou recolhido. Quando o estado é expandido, os itens filhos são exibidos abaixo do item pai. Quando ele estiver recolhido, os itens filho não são exibidos. A lista alterna automaticamente entre os estados expandidos e recolhidos quando o usuário clica duas vezes o item pai ou, se o pai tem o **TVS_HASBUTTONS** estilo, quando o usuário clica no botão associado ao item pai. Um aplicativo pode expandir ou recolher os itens filho usando o [expandir](../mfc/reference/ctreectrl-class.md#expand) função de membro.  
  
 Adicionar um item a um controle de árvore chamando o [InsertItem](../mfc/reference/ctreectrl-class.md#insertitem) função de membro. Essa função retorna um identificador do **HTREEITEM** tipo, que identifica exclusivamente o item. Ao adicionar um item, você deve especificar o identificador do item do pai do novo item. Se você especificar **nulo** ou o **TVI_ROOT** valor em vez de um identificador do item pai no [TVINSERTSTRUCT](/windows/desktop/api/commctrl/ns-commctrl-tagtvinsertstructa) estrutura ou *hParent* parâmetro, o item é adicionado como um item de raiz.  
  
 Um controle de árvore envia um [TVN_ITEMEXPANDING](/windows/desktop/Controls/tvn-itemexpanding) mensagem de notificação quando a lista de um item pai dos itens filhos está prestes a ser expandidos ou recolhidos. A notificação fornece a oportunidade para evitar a alteração ou para definir todos os atributos do item pai que dependem do estado da lista de itens filho. Depois de alterar o estado da lista, o controle de árvore envia um [TVN_ITEMEXPANDED](/windows/desktop/Controls/tvn-itemexpanded) mensagem de notificação.  
  
 Quando uma lista de itens filho é expandida, ele é recuado em relação ao item pai. Você pode definir a quantidade de recuo, usando o [SetIndent](../mfc/reference/ctreectrl-class.md#setindent) função de membro ou recuperar o valor atual usando o [GetIndent](../mfc/reference/ctreectrl-class.md#getindent) função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

