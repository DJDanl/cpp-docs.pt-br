---
title: "Edi&#231;&#227;o do r&#243;tulo de controle de &#225;rvore | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CTreeCtrl, editando rótulos"
  - "editando rótulos de controle de árvore"
  - "editando rótulo na classe CTreeCtrl"
  - "controles em árvore, edição de rótulos"
ms.assetid: 6cde2ac3-43ee-468f-bac2-cf1a228ad32d
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Edi&#231;&#227;o do r&#243;tulo de controle de &#225;rvore
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O usuário pode editar diretamente os rótulos de itens em um controle de árvore \([CTreeCtrl](../mfc/reference/ctreectrl-class.md)\) que tenha o estilo de **TVS\_EDITLABELS** .  O usuário inicia a editar clicando no rótulo do item que tem o foco.  Um aplicativo inicia a editar usando a função de membro de [EditLabel](../Topic/CTreeCtrl::EditLabel.md) .  O controle de árvore envia notificação ao editar inicia e quando será cancelado ou concluído.  Ao editar é concluído, você é responsável para atualizar o rótulo do item, se apropriado.  
  
 Quando a edição do rótulo é iniciada, um controle de árvore envia uma notificação de [TVN\_BEGINLABELEDIT](http://msdn.microsoft.com/library/windows/desktop/bb773506) .  Processando esta notificação, você pode permitir a edição de alguns rótulos e evitar a edição de outro.  Retornar 0 permite editar, e retornar diferente de zero impedir.  
  
 Quando a edição do rótulo é cancelada ou concluída, um controle de árvore envia uma notificação de [TVN\_ENDLABELEDIT](http://msdn.microsoft.com/library/windows/desktop/bb773515) .  O parâmetro de `lParam` é o endereço de uma estrutura de [NMTVDISPINFO](http://msdn.microsoft.com/library/windows/desktop/bb773418) .  O membro de **item** é uma estrutura de [TVITEM](http://msdn.microsoft.com/library/windows/desktop/bb773456) que identifica o item e inclua texto editado.  Você é responsável para atualizar o rótulo do item, se apropriado, talvez depois de ter validado a cadeia de caracteres editada.  O membro de **pszText** de `TV_ITEM` é 0 se a edição é cancelada.  
  
 Durante a edição do rótulo, normalmente em resposta à notificação de [TVN\_BEGINLABELEDIT](http://msdn.microsoft.com/library/windows/desktop/bb773506) , você pode obter um ponteiro para o controle de edição usado para a edição do rótulo usando a função de membro de [GetEditControl](../Topic/CTreeCtrl::GetEditControl.md) .  Você pode chamar a função de membro de [SetLimitText](../Topic/CEdit::SetLimitText.md) de controle de edição para limitar a quantidade de texto que um usuário possa digitar ou subclasse o controle de edição para interceptar e descartar caracteres inválidos.  Observe, entretanto, que o controle de edição será exibido somente *depois* que **TVN\_BEGINLABELEDIT** é enviado.  
  
## Consulte também  
 [Usando CTreeCtrl](../Topic/Using%20CTreeCtrl.md)   
 [Controles](../mfc/controls-mfc.md)