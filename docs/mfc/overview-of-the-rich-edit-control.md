---
title: "Vis&#227;o geral do controle de edi&#231;&#227;o avan&#231;ada | Microsoft Docs"
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
  - "controles de edição avançada"
ms.assetid: ad589b9f-a3fd-4820-bf1f-6b1965997e68
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vis&#227;o geral do controle de edi&#231;&#227;o avan&#231;ada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!IMPORTANT]
>  Se você estiver usando um controle de edição rico em uma caixa de diálogo \(independentemente de se seu aplicativo for SDI, documentos, ou diálogo\- base\), chame [AfxInitRichEdit](../Topic/AfxInitRichEdit.md) uma vez antes da caixa de diálogo é exibida.  Um local comum para chamar essa função está na função de membro de `InitInstance` do programa.  Você não precisa chame para cada vez que você exibir a caixa de diálogo, apenas a primeira vez.  Você não precisa chamar `AfxInitRichEdit` se você estiver trabalhando com `CRichEditView`.  
  
 Os controles de edição avançada \([CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md)\) fornecem uma interface de programação para formatar o texto.  No entanto, um aplicativo deve implementar todos os componentes de interface do usuário necessária para operações de formatação disponíveis para o usuário.  Isto é, o controle de edição suporte rico alterar os atributos de caractere ou de parágrafo de texto selecionado.  Alguns exemplos de atributos de caracteres são negrito, itálico, família de fontes, e tamanho do ponto.  Os exemplos de atributos de parágrafo incluem o alinhamento, as margens, e as paradas de tabulação.  No entanto, cabe a você para fornecer a interface do usuário, se esse é botões da barra de ferramentas, itens de menu, ou uma caixa de diálogo de caracteres de formato.  Também há funções para consultar o controle de edição avançado para os atributos de seleção atual.  Use essas funções para exibir as configurações atuais dos atributos, por exemplo, definindo uma marca de seleção no comando interface do usuário se a seleção tem o atributo em negrito de formatação de caractere.  
  
 Para obter mais informações sobre de formatação de caractere e de parágrafo, consulte [Formatação de caractere](../mfc/character-formatting-in-rich-edit-controls.md) e [Formatação de parágrafo](../Topic/Paragraph%20Formatting%20in%20Rich%20Edit%20Controls.md) posteriormente neste tópico.  
  
 Os controles de edição avançada dão suporte a quase todas as operações e notificações usadas com controles de edição multilinha.  Assim, os aplicativos que já usam controles de edição podem ser facilmente modificados para usar controles de edição avançada.  As mensagens e as notificações adicionais a seguir permitem que aplicativos acessar a funcionalidade exclusiva nos controles de edição avançada.  Para obter informações sobre os controles de edição, consulte [CEdit](../Topic/CEdit%20Class.md).  
  
 Para obter mais informações sobre as notificações, consulte [Notificações de um controle de edição avançado](../mfc/notifications-from-a-rich-edit-control.md) posteriormente neste tópico.  
  
## Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)