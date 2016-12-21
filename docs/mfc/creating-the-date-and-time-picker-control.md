---
title: "Criando o controle de seletor de data e hora | Microsoft Docs"
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
  - "Classe CDateTimeCtrl, criando"
  - "Controle DateTimePicker [MFC], criando"
ms.assetid: 764ec2fb-98cd-478b-a5f2-d63f0bb12279
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando o controle de seletor de data e hora
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como o controle de seletor de data e hora é criado depende de se você estiver usando o controle em uma caixa de diálogo ou se estiver criando em uma janela de nondialog.  
  
### Para usar CDateTimeCtrl diretamente em uma caixa de diálogo  
  
1.  No publicador da caixa de diálogo, adicione um controle de seletor de data e hora ao recurso de modelo da caixa de diálogo.  Especificar sua ID de controle  
  
2.  Especificar todos os estilos necessários, usando a caixa de diálogo propriedades do controle de seletor de data e hora.  
  
3.  Use [Adicionar o assistente da variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro do tipo [CDateTimeCtrl](../mfc/reference/cdatetimectrl-class.md) com a propriedade do controle.  Você pode usar esse membro para chamar funções de membro de `CDateTimeCtrl` .  
  
4.  Use a janela Propriedades para mapear funções do manipulador na classe da caixa de diálogo para todas as mensagens de [notificação](../mfc/processing-notification-messages-in-date-and-time-picker-controls.md) de controle do selecionador de data e hora você precisar controlar [Mensagens de mapeamento a funções](../Topic/Mapping%20Messages%20to%20Functions.md)\(consulte\).  
  
5.  Em [OnInitDialog](../Topic/CDialog::OnInitDialog.md), defina todos os estilos adicionais para o objeto de `CDateTimeCtrl` .  
  
### Para usar CDateTimeCtrl em uma janela de nondialog  
  
1.  Declare o controle na exibição ou na classe da janela.  
  
2.  Chame a função de membro de [Crie](../Topic/CTabCtrl::Create.md) de controle, possivelmente em [OnInitialUpdate](../Topic/CView::OnInitialUpdate.md), possivelmente a partir da função pai do manipulador de [OnCreate](../Topic/CWnd::OnCreate.md) da janela \(se você subclassing o controle\).  Definir os estilos do controle.  
  
## Consulte também  
 [Usando CDateTimeCtrl](../mfc/using-cdatetimectrl.md)   
 [Controles](../mfc/controls-mfc.md)