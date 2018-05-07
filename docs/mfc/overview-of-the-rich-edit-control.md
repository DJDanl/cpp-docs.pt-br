---
title: Visão geral do controle de edição avançada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- rich edit controls [MFC]
ms.assetid: ad589b9f-a3fd-4820-bf1f-6b1965997e68
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 143fc93fb07d9ac7c4e803bbce426c114c02bfeb
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="overview-of-the-rich-edit-control"></a>Visão geral do controle de edição avançada
> [!IMPORTANT]
>  Se você estiver usando um controle de edição na caixa de diálogo (independentemente do aplicativo é SDI, MDI, com a caixa de diálogo ou), você deve chamar [AfxInitRichEdit](../mfc/reference/application-information-and-management.md#afxinitrichedit) depois antes da caixa de diálogo caixa é exibida. Em geral para chamar esta função é em seu programa `InitInstance` função de membro. Você não precisa chamá-la sempre que você exibir a caixa de diálogo, somente na primeira vez. Você não precisa chamar `AfxInitRichEdit` se você estiver trabalhando com `CRichEditView`.  
  
 Controles de edição avançada ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) fornecem uma interface de programação de formatação de texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface de usuário necessários para tornar as operações de formatação disponíveis para o usuário. Ou seja, a edição avançada controle oferece suporte ao alterar os atributos de parágrafo ou de caractere do texto selecionado. Alguns exemplos de atributos são de caractere negrito, itálico, família de fontes e tamanho de ponto. Exemplos de atributos de parágrafo incluem alinhamento, margens e paradas de tabulação. No entanto, é até que você forneça a interface do usuário seja botões da barra de ferramentas, itens de menu ou uma caixa de diálogo de caracteres de formato. Também há funções para consultar o controle de edição para os atributos da seleção atual. Use essas funções para exibir as configurações atuais para os atributos, por exemplo, definindo uma marca de seleção no comando de interface do usuário, se a seleção tem o atributo de formatação de caracteres em negrito.  
  
 Para obter mais informações sobre formatação de parágrafo e caracteres, consulte [formatação de caractere](../mfc/character-formatting-in-rich-edit-controls.md) e [formatação de parágrafo](../mfc/paragraph-formatting-in-rich-edit-controls.md) mais adiante neste tópico.  
  
 Edição rico controles suporte quase todas as operações e mensagens de notificação usadas com controles de edição de várias linhas. Portanto, os aplicativos que já use controles de edição podem ser facilmente modificados para usar rich controles de edição. Notificações e mensagens adicionais permitem que aplicativos acessem os controles de edição exclusivos avançados funcionalidade. Para obter informações sobre controles de edição, consulte [CEdit](../mfc/reference/cedit-class.md).  
  
 Para obter mais informações sobre notificações, consulte [notificações de um controle de edição avançada](../mfc/notifications-from-a-rich-edit-control.md) mais adiante neste tópico.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)

