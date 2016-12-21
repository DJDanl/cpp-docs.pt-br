---
title: "Criando o controle de lista | Microsoft Docs"
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
  - "Classe CListCtrl, criando controle"
  - "controles de lista"
ms.assetid: a4cb1729-31b6-4d2b-a44b-367474848a39
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando o controle de lista
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como o controle da lista[CListCtrl](../Topic/CListCtrl%20Class.md)\(\) é criado depende de se você estiver usando o controle está diretamente ou usando a classe [CListView](../mfc/reference/clistview-class.md) em vez disso.  Se você usar `CListView`, a estrutura constrói a exibição como parte de sua sequência de criação do documento\/exibição.  Criar a exibição de lista cria o controle da lista também \(os dois forem a mesma coisa\).  O controle é criado na função de manipulador de [OnCreate](../Topic/CWnd::OnCreate.md) de exibição.  Nesse caso, o controle está pronto para que você adicione itens, através de uma chamada para [GetListCtrl](../Topic/CListView::GetListCtrl.md).  
  
### Para usar CListCtrl diretamente em uma caixa de diálogo  
  
1.  No publicador da caixa de diálogo, adicione um controle de lista ao recurso de modelo da caixa de diálogo.  Especificar sua ID de controle  
  
2.  Use [Adicionar o assistente da variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro do tipo `CListCtrl` com a propriedade do controle.  Você pode usar esse membro para chamar funções de membro de `CListCtrl` .  
  
3.  Use a janela Propriedades para mapear funções do manipulador na classe da caixa de diálogo para todas as notificações que o controle da lista você precisar controlar [Mensagens de mapeamento a funções](../Topic/Mapping%20Messages%20to%20Functions.md)\(consulte\).  
  
4.  Em [OnInitDialog](../Topic/CDialog::OnInitDialog.md), defina os estilos para `CListCtrl`.  Consulte [Alterando os estilos de controle de lista](../Topic/Changing%20List%20Control%20Styles.md).  Isso determina o tipo de “exibição” que você obtém o no controle, embora você possa alterar a exibição.  
  
### Para usar CListCtrl em uma janela de nondialog  
  
1.  Define o controle na exibição ou na classe da janela.  
  
2.  Chame a função de membro de [Crie](../Topic/CListCtrl::Create.md) de controle, possivelmente em [OnInitialUpdate](../Topic/CView::OnInitialUpdate.md), possivelmente a partir da função pai do manipulador de [OnCreate](../Topic/CWnd::OnCreate.md) da janela \(se você subclassing o controle\).  Definir os estilos do controle.  
  
## Consulte também  
 [Usando CListCtrl](../Topic/Using%20CListCtrl.md)   
 [Controles](../mfc/controls-mfc.md)