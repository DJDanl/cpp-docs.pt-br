---
title: Rótulo de controle de árvore edição | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- editing tree control labels
- CTreeCtrl class [MFC], editing labels
- label editing in CTreeCtrl class [MFC]
- tree controls [MFC], label editing
ms.assetid: 6cde2ac3-43ee-468f-bac2-cf1a228ad32d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fd2157755146606b2bdacf8ae5a1da9cd0966b21
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="tree-control-label-editing"></a>Edição do rótulo de controle de árvore
O usuário pode editar diretamente os rótulos de itens em um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) que tem o **TVS_EDITLABELS** estilo. O usuário começa a editar clicando o rótulo do item que tem o foco. Um aplicativo começa a edição usando o [EditLabel](../mfc/reference/ctreectrl-class.md#editlabel) função de membro. O controle de árvore envia a notificação ao editar começa e quando é cancelada ou concluída. Quando concluir a edição, você é responsável por atualizar o rótulo do item, se apropriado.  
  
 Editando rótulo começa, um controle de árvore envia um [TVN_BEGINLABELEDIT](http://msdn.microsoft.com/library/windows/desktop/bb773506) mensagem de notificação. Processando essa notificação, você pode permitir a edição de alguns rótulos e impedir a edição de outras pessoas. Retornar 0 permite a edição e retornando diferente de zero evita-lo.  
  
 Quando o rótulo edição seja cancelada ou concluída, um controle de árvore envia um [TVN_ENDLABELEDIT](http://msdn.microsoft.com/library/windows/desktop/bb773515) mensagem de notificação. O `lParam` parâmetro é o endereço de um [NMTVDISPINFO](http://msdn.microsoft.com/library/windows/desktop/bb773418) estrutura. O **item** membro é um [TVITEM](http://msdn.microsoft.com/library/windows/desktop/bb773456) estrutura que identifica o item e inclui o texto editado. Você é responsável por Atualizando rótulo do item, se apropriado, talvez depois de validar a cadeia de caracteres editada. O **pszText** membro `TV_ITEM` é 0 se a edição será cancelada.  
  
 Durante a edição de rótulos, normalmente em resposta ao [TVN_BEGINLABELEDIT](http://msdn.microsoft.com/library/windows/desktop/bb773506) mensagem de notificação, você pode obter um ponteiro para o controle de edição usado para edição de rótulos usando o [GetEditControl](../mfc/reference/ctreectrl-class.md#geteditcontrol) membro função. Você pode chamar o controle de edição [SetLimitText](../mfc/reference/cedit-class.md#setlimittext) a função de membro para limitar a quantidade de texto que um usuário pode inserir ou subclasse de controle de edição para interceptar e descartar os caracteres inválidos. No entanto, observe que o controle de edição é exibido apenas *depois* **TVN_BEGINLABELEDIT** é enviada.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

