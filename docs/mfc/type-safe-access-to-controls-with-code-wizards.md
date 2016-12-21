---
title: "Acesso fortemente tipado a controles com assistentes de c&#243;digo | Microsoft Docs"
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
  - "assistentes de código"
  - "DDX (troca de dados da caixa de diálogo), acesso a controles"
  - "controles de caixas de diálogo, acessando"
  - "caixas de diálogo, acesso a controles"
ms.assetid: b8874393-ee48-4124-8d78-e3648a7e29b9
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Acesso fortemente tipado a controles com assistentes de c&#243;digo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se você estiver familiarizado com os recursos de DDX, você pode usar a propriedade do controle em [Adicionar o assistente da variável de membro](../ide/add-member-variable-wizard.md) para criar o acesso do tipo seguro.  Essa abordagem é mais fácil de criar controles sem os assistentes de código.  
  
 Se você quiser simplesmente acesso ao valor de um controle, DDX fornece.  Se você quiser fazer mais do que acessa o valor de um controle, use o assistente variável de membro adicionar para adicionar uma variável de membro da classe apropriado para sua classe da caixa de diálogo.  Anexar essa variável de membro à propriedade do controle.  
  
 As variáveis de membros podem ter uma propriedade do controle em vez de uma propriedade de valor.  A propriedade refere\-se o tipo de dados retornados de controle, como `CString` ou `int`.  A propriedade do controle habilita o acesso direto ao controle por meio de um membro de dados cujo tipo é uma das classes de controle em MFC, como `CButton` ou `CEdit`.  
  
> [!NOTE]
>  Para um determinado controle, você pode, se desejar, tem várias variáveis de membro com a propriedade do valor e o máximo uma variável de membro com a propriedade do controle.  Você pode ter somente um objeto de MFC mapeado para um controle como os vários objetos anexados a um controle, ou qualquer outra janela, resultaria em uma ambiguidade da mensagem.  
  
 Você pode usar este objeto para chamar todas as funções de membro para o objeto do controle.  Essa chamadas afetam o controle na caixa de diálogo.  Por exemplo, para um controle da caixa de seleção representado por `m_Checkbox`variável, do tipo `CButton`, você pode chamar:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#52](../mfc/codesnippet/CPP/type-safe-access-to-controls-with-code-wizards_1.cpp)]  
  
 É o membro `m_Checkbox` variável tem a mesma finalidade da função de membro `GetMyCheckbox` mostrado em [Acesso fortemente tipado nos controles sem assistentes de código](../mfc/type-safe-access-to-controls-without-code-wizards.md).  Se a caixa de seleção não é uma caixa de seleção automática, ainda precisará de um manipulador em sua classe da caixa de diálogo para controle\- a mensagem de notificação de **BN\_CLICKED** quando o usuário clicar no botão.  
  
 Para obter mais informações sobre os controles, consulte [Controles](../mfc/controls-mfc.md).  
  
## Consulte também  
 [Acesso fortemente tipado a controles em uma caixa de diálogo](../Topic/Type-Safe%20Access%20to%20Controls%20in%20a%20Dialog%20Box.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)   
 [Acesso fortemente tipado a controles sem assistentes de código](../mfc/type-safe-access-to-controls-without-code-wizards.md)