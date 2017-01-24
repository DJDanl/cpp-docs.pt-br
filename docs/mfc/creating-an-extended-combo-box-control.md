---
title: "Criando um controle de caixa de combina&#231;&#227;o estendido | Microsoft Docs"
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
  - "Classe CComboBoxEx, criando controles de caixa de combinação estendidos"
  - "caixas de combinação estendidas"
  - "caixas de combinação estendidas, criando"
ms.assetid: a964267e-97b6-4e77-9f89-55bb5c68913f
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um controle de caixa de combina&#231;&#227;o estendido
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como o controle estendido da caixa de combinação é criado depende de se você estiver usando o controle em uma caixa de diálogo ou se estiver criando em uma janela de nondialog.  
  
### Para usar CComboBoxEx diretamente em uma caixa de diálogo  
  
1.  No publicador da caixa de diálogo, adicione um controle estendido da caixa de combinação com seu recurso de modelo da caixa de diálogo.  Especificar sua ID de controle  
  
2.  Especificar todos os estilos necessários, usando a caixa de diálogo propriedades do controle estendido da caixa de combinação.  
  
3.  Use [Adicionar o assistente da variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro do tipo [CComboBoxEx](../mfc/reference/ccomboboxex-class.md) com a propriedade do controle.  Você pode usar esse membro para chamar funções de membro de `CComboBoxEx` .  
  
4.  Use a janela Propriedades para mapear funções do manipulador na classe da caixa de diálogo para todas as notificações que estendidos do controle da caixa de combinação você precisar controlar [Mensagens de mapeamento a funções](../Topic/Mapping%20Messages%20to%20Functions.md)\(consulte\).  
  
5.  Em [OnInitDialog](../Topic/CDialog::OnInitDialog.md), defina todos os estilos adicionais para o objeto de `CComboBoxEx` .  
  
### Para usar CComboBoxEx em uma janela de nondialog  
  
1.  Define o controle na exibição ou na classe da janela.  
  
2.  Chame a função de membro de [Crie](../Topic/CTabCtrl::Create.md) de controle, possivelmente em [OnInitialUpdate](../Topic/CView::OnInitialUpdate.md), possivelmente a partir da função pai do manipulador de [OnCreate](../Topic/CWnd::OnCreate.md) da janela.  Definir os estilos do controle.  
  
## Consulte também  
 [Usando CComboBoxEx](../mfc/using-ccomboboxex.md)   
 [Controles](../mfc/controls-mfc.md)