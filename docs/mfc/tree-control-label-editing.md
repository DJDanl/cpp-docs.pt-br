---
title: Edição do rótulo de controle de árvore
ms.date: 11/04/2016
helpviewer_keywords:
- editing tree control labels
- CTreeCtrl class [MFC], editing labels
- label editing in CTreeCtrl class [MFC]
- tree controls [MFC], label editing
ms.assetid: 6cde2ac3-43ee-468f-bac2-cf1a228ad32d
ms.openlocfilehash: 4b53d2c8e5a26a4dc37dfd7ae0710748bcd27bf6
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70741227"
---
# <a name="tree-control-label-editing"></a>Edição do rótulo de controle de árvore

O usuário pode editar diretamente os rótulos de itens em um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) que tem o estilo **TVS_EDITLABELS** . O usuário começa a editar clicando no rótulo do item que tem o foco. Um aplicativo começa a ser editado usando a função de membro [EditLabel](../mfc/reference/ctreectrl-class.md#editlabel) . O controle de árvore envia a notificação quando a edição começa e quando é cancelada ou concluída. Quando a edição for concluída, você será responsável por atualizar o rótulo do item, se apropriado.

Quando começa a edição do rótulo, um controle de árvore envia uma mensagem de notificação [TVN_BEGINLABELEDIT](/windows/win32/Controls/tvn-beginlabeledit) . Ao processar essa notificação, você pode permitir a edição de alguns rótulos e impedir a edição de outros. Retornar 0 permite a edição, e o retorno de zero é evitado.

Quando a edição de rótulo é cancelada ou concluída, um controle de árvore envia uma mensagem de notificação [TVN_ENDLABELEDIT](/windows/win32/Controls/tvn-endlabeledit) . O parâmetro *lParam* é o endereço de uma estrutura [NMTVDISPINFO](/windows/win32/api/commctrl/ns-commctrl-nmtvdispinfow) . O membro **Item** é uma estrutura [TVITEM](/windows/win32/api/commctrl/ns-commctrl-tvitemw) que identifica o item e inclui o texto editado. Você é responsável por atualizar o rótulo do item, se apropriado, talvez depois de validar a cadeia de caracteres editada. O membro *pszText* de `TV_ITEM` será 0 se a edição for cancelada.

Durante a edição de rótulo, normalmente em resposta à mensagem de notificação [TVN_BEGINLABELEDIT](/windows/win32/Controls/tvn-beginlabeledit) , você pode obter um ponteiro para o controle de edição usado para edição de rótulo usando a função de membro [GetEditControl](../mfc/reference/ctreectrl-class.md#geteditcontrol) . Você pode chamar a função de membro [SetLimitText](../mfc/reference/cedit-class.md#setlimittext) do controle de edição para limitar a quantidade de texto que um usuário pode inserir ou subclasse do controle de edição para interceptar e descartar caracteres inválidos. Observe, no entanto, que o controle de edição é exibido somente *depois* que **TVN_BEGINLABELEDIT** é enviado.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
