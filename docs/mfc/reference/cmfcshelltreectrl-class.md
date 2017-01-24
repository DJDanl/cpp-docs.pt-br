---
title: "Classe de CMFCShellTreeCtrl | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CMFCShellTreeCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCShellTreeCtrl"
ms.assetid: 3d1da715-9554-4ed7-968c-055c48146267
caps.latest.revision: 30
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCShellTreeCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCShellTreeCtrl` estendem a funcionalidade de [Classe de CTreeCtrl](../../mfc/reference/ctreectrl-class.md) exibindo uma hierarquia de itens de Shell.  
  
## Sintaxe  
  
```  
class CMFCShellTreeCtrl : public CTreeCtrl  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCShellTreeCtrl::EnableShellContextMenu](../Topic/CMFCShellTreeCtrl::EnableShellContextMenu.md)|Habilita ou desabilita o menu de atalho.|  
|[CMFCShellTreeCtrl::GetFlags](../Topic/CMFCShellTreeCtrl::GetFlags.md)|Retorna uma combinação de sinalizadores que são passados para [IShellFolder::EnumObjects](http://msdn.microsoft.com/library/windows/desktop/bb775066).|  
|[CMFCShellTreeCtrl::GetItemPath](../Topic/CMFCShellTreeCtrl::GetItemPath.md)|Retorna o caminho para um item.|  
|[CMFCShellTreeCtrl::GetRelatedList](../Topic/CMFCShellTreeCtrl::GetRelatedList.md)|Retorna um ponteiro para o objeto de [Classe de CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) que é usado junto com esse objeto de `CMFCShellTreeCtrl` para criar explorer \- como a janela.|  
|[CMFCShellTreeCtrl::OnChildNotify](../Topic/CMFCShellTreeCtrl::OnChildNotify.md)|Essa função de membro é chamada pela janela pai de essa janela quando receber uma notificação que se aplica a essa janela.  Overrides \( [CWnd::OnChildNotify](../Topic/CWnd::OnChildNotify.md).\)|  
|[CMFCShellTreeCtrl::OnGetItemIcon](../Topic/CMFCShellTreeCtrl::OnGetItemIcon.md)||  
|[CMFCShellTreeCtrl::OnGetItemText](../Topic/CMFCShellTreeCtrl::OnGetItemText.md)||  
|[CMFCShellTreeCtrl::Refresh](../Topic/CMFCShellTreeCtrl::Refresh.md)|As atualizações e repintam o objeto atual de `CMFCShellTreeCtrl` .|  
|[CMFCShellTreeCtrl::SelectPath](../Topic/CMFCShellTreeCtrl::SelectPath.md)|Seleciona o item apropriado do controle da árvore baseado em um caminho fornecido de PIDL ou de cadeia de caracteres.|  
|[CMFCShellTreeCtrl::SetFlags](../Topic/CMFCShellTreeCtrl::SetFlags.md)|Define os sinalizadores para filtrar o contexto da árvore \(semelhante aos sinalizadores usados por `IShellFolder::EnumObjects`\).|  
|[CMFCShellTreeCtrl::SetRelatedList](../Topic/CMFCShellTreeCtrl::SetRelatedList.md)|Define uma relação entre o objeto atual de `CMFCShellTreeCtrl` e um objeto de `CMFCShellListCtrl` .|  
  
## Comentários  
 Essa classe estende a classe de `CTreeCtrl` ativando o programa para incluir itens do Shell do windows na árvore.  Essa classe pode ser associada a um objeto de `CMFCShellListCtrl` para criar uma janela completo de Explorer.  Em seguida, selecione um item na árvore exibirá uma lista de itens do Shell do windows na lista associado.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CTreeCtrl](../../mfc/reference/ctreectrl-class.md)  
  
 [CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxshelltreeCtrl.h  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um objeto da classe de `CMFCShellTreeCtrl` .  Este trecho de código é parte de [exemplo de Explorer](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_Explorer#4](../../mfc/reference/codesnippet/CPP/cmfcshelltreectrl-class_1.h)]  
[!code-cpp[NVC_MFC_Explorer#5](../../mfc/reference/codesnippet/CPP/cmfcshelltreectrl-class_2.cpp)]  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CTreeCtrl](../../mfc/reference/ctreectrl-class.md)   
 [Classe de CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md)