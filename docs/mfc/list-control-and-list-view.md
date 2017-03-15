---
title: "Controle e exibi&#231;&#227;o de lista | Microsoft Docs"
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
  - "Classe CListCtrl, e CListView"
  - "Classe CListView, e CListCtrl"
  - "controles de lista, Exibição de lista"
  - "exibições de lista"
  - "modos de exibição, lista e controle de lista"
ms.assetid: 7aee1c48-b158-4399-be0b-be366993665e
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controle e exibi&#231;&#227;o de lista
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Por conveniência, o MFC encapsula o controle da lista de duas formas.  Você pode usar controles da lista:  
  
-   Diretamente, inserindo um objeto de [CListCtrl](../Topic/CListCtrl%20Class.md) em uma classe da caixa de diálogo.  
  
-   Indiretamente, usando a classe [CListView](../mfc/reference/clistview-class.md).  
  
 `CListView` facilita a integração de um controle da lista com a arquitetura do documento\/exibição MFC, encapsulando o controle de modo muito semelhante [CEditView](../Topic/CEditView%20Class.md) encapsula um controle de edição: o controle preenche a área da superfície inteira de uma exibição de MFC. \(A exibição *é* o controle, a conversão `CListView`.\)  
  
 Um objeto de `CListView` herda de [CCtrlView](../mfc/reference/cctrlview-class.md) e suas classes base e adiciona uma função de membro para recuperar o controle subjacente da lista.  Usa membros de exibição para trabalhar com a exibição como uma exibição.  Use a função de membro de [GetListCtrl](../Topic/CListView::GetListCtrl.md) para obter acesso às funções de membro do controle da lista.  Use esses membros:  
  
-   Adicionar, excluir, ou manipular itens “” na lista.  
  
-   O conjunto ou define atributos de controle da lista.  
  
 Para obter uma referência a `CListCtrl` que é a base de `CListView`, chame `GetListCtrl` da sua classe da exibição de lista:  
  
 [!CODE [NVC_MFCListView#4](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCListView#4)]  
  
 Este tópico descreve duas formas de usar o controle da lista.  
  
## Consulte também  
 [Usando CListCtrl](../Topic/Using%20CListCtrl.md)   
 [Controles](../mfc/controls-mfc.md)