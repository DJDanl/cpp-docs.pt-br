---
title: "Criando o controle de calend&#225;rio mensal | Microsoft Docs"
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
  - "Classe CMonthCalCtrl, criando"
  - "controles de calendário mensal"
  - "controles de calendário mensal, criando"
ms.assetid: 185cc642-85e9-4365-8a4c-d90b75b010f7
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando o controle de calend&#225;rio mensal
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como o controle de calendário do mês será criado depende de se você estiver usando o controle em uma caixa de diálogo ou se estiver criando em uma janela de nondialog.  
  
### Para usar CMonthCalCtrl diretamente em uma caixa de diálogo  
  
1.  No publicador da caixa de diálogo, adicione um controle de calendário do mês ao recurso de modelo da caixa de diálogo.  Especificar sua ID de controle  
  
2.  Especificar todos os estilos necessários, usando a caixa de diálogo propriedades do controle de calendário do mês.  
  
3.  Use [Adicionar o assistente da variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro do tipo [CMonthCalCtrl](../mfc/reference/cmonthcalctrl-class.md) com a propriedade do controle.  Você pode usar esse membro para chamar funções de membro de `CMonthCalCtrl` .  
  
4.  Use a janela Propriedades para mapear funções do manipulador na classe da caixa de diálogo para todas as notificações que o controle de calendário do mês você precisar controlar [Mensagens de mapeamento a funções](../Topic/Mapping%20Messages%20to%20Functions.md)\(consulte\).  
  
5.  Em [OnInitDialog](../Topic/CDialog::OnInitDialog.md), defina todos os estilos adicionais para o objeto de `CMonthCalCtrl` .  
  
### Para usar CMonthCalCtrl em uma janela de nondialog  
  
1.  Define o controle na exibição ou na classe da janela.  
  
2.  Chame a função de membro de [Crie](../Topic/CMonthCalCtrl::Create.md) de controle, possivelmente em [OnInitialUpdate](../Topic/CView::OnInitialUpdate.md), possivelmente a partir da função pai do manipulador de [OnCreate](../Topic/CWnd::OnCreate.md) da janela \(se você subclassing o controle\).  Definir os estilos do controle.  
  
## Consulte também  
 [Usando CMonthCalCtrl](../Topic/Using%20CMonthCalCtrl.md)   
 [Controles](../mfc/controls-mfc.md)