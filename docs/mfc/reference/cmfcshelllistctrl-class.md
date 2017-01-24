---
title: "Classe de CMFCShellListCtrl | Microsoft Docs"
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
  - "CMFCShellListCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCShellListCtrl"
ms.assetid: ad472958-5586-4c50-aadf-1844c30bf6e7
caps.latest.revision: 30
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCShellListCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCShellListCtrl` fornece a funcionalidade do controle de lista do windows e para expandi\-la incluindo a capacidade de exibir uma lista de itens de shell.  
  
## Sintaxe  
  
```  
class CMFCShellListCtrl : public CMFCListCtrl  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCShellListCtrl::DisplayFolder](../Topic/CMFCShellListCtrl::DisplayFolder.md)|Exibe uma lista de itens que estão contidos em uma pasta fornecida.|  
|[CMFCShellListCtrl::DisplayParentFolder](../Topic/CMFCShellListCtrl::DisplayParentFolder.md)|Exibe uma lista de itens que estão contidos na pasta que é o pai do diretório atualmente exibida.|  
|[CMFCShellListCtrl::EnableShellContextMenu](../Topic/CMFCShellListCtrl::EnableShellContextMenu.md)|Habilita ou desabilita o menu de atalho.|  
|[CMFCShellListCtrl::GetCurrentFolder](../Topic/CMFCShellListCtrl::GetCurrentFolder.md)|Retorna o caminho da pasta atual.|  
|[CMFCShellListCtrl::GetCurrentFolderName](../Topic/CMFCShellListCtrl::GetCurrentFolderName.md)|Recupera o nome da pasta atual.|  
|[CMFCShellListCtrl::GetCurrentItemIdList](../Topic/CMFCShellListCtrl::GetCurrentItemIdList.md)|Retorna o PIDL de item atual do controle de lista.|  
|[CMFCShellListCtrl::GetCurrentShellFolder](../Topic/CMFCShellListCtrl::GetCurrentShellFolder.md)|Retorna um ponteiro para a pasta atual do Shell.|  
|[CMFCShellListCtrl::GetItemPath](../Topic/CMFCShellListCtrl::GetItemPath.md)|Retorna o caminho textual de um item.|  
|[CMFCShellListCtrl::GetItemTypes](../Topic/CMFCShellListCtrl::GetItemTypes.md)|Retorna os tipos de itens de Shell que são exibidos pelo controle de lista.|  
|[CMFCShellListCtrl::IsDesktop](../Topic/CMFCShellListCtrl::IsDesktop.md)|Verifica se a pasta selecionada é a pasta da área de trabalho.|  
|[CMFCShellListCtrl::OnCompareItems](../Topic/CMFCShellListCtrl::OnCompareItems.md)|A estrutura quando chamar esse método compara dois itens.  Overrides \( [CMFCListCtrl::OnCompareItems](../Topic/CMFCListCtrl::OnCompareItems.md).\)|  
|[CMFCShellListCtrl::OnFormatFileDate](../Topic/CMFCShellListCtrl::OnFormatFileDate.md)|Chamado quando a estrutura recuperar a data do arquivo exibida pelo controle de lista.|  
|[CMFCShellListCtrl::OnFormatFileSize](../Topic/CMFCShellListCtrl::OnFormatFileSize.md)|Chamado quando a estrutura converter o tamanho do arquivo de um controle de lista.|  
|[CMFCShellListCtrl::OnGetItemIcon](../Topic/CMFCShellListCtrl::OnGetItemIcon.md)|Chamado quando a estrutura recuperar o ícone de um controle de item de lista.|  
|[CMFCShellListCtrl::OnGetItemText](../Topic/CMFCShellListCtrl::OnGetItemText.md)|Chamado quando a estrutura converter o texto de um controle de item de lista.|  
|[CMFCShellListCtrl::OnSetColumns](../Topic/CMFCShellListCtrl::OnSetColumns.md)|Chamado pela estrutura quando definir os nomes das colunas.|  
|[CMFCShellListCtrl::Refresh](../Topic/CMFCShellListCtrl::Refresh.md)|As atualizações e repintam o controle de lista.|  
|[CMFCShellListCtrl::SetItemTypes](../Topic/CMFCShellListCtrl::SetItemTypes.md)|Define o tipo de itens exibidos pelo controle de lista.|  
  
## Comentários  
 A classe de `CMFCShellListCtrl` estendem a funcionalidade de [Classe de CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md) ativando o programa para listar itens do shell do windows.  O formato de exibição que é usado é como o de uma exibição de lista para uma janela do Explorer.  
  
 Um objeto de [CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) pode ser associado com um objeto de `CMFCShellListCtrl` para criar uma janela completo de Explorer.  Em seguida, selecione um item em `CMFCShellTreeCtrl` fará com que o objeto de `CMFCShellListCtrl` do conteúdo do item selecionado.  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um objeto da classe de `CMFCShellListCtrl` e como exibir a pasta pai do diretório atualmente exibida.  Este trecho de código é parte de [exemplo de Explorer](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_Explorer#1](../../mfc/reference/codesnippet/CPP/cmfcshelllistctrl-class_1.h)]  
[!code-cpp[NVC_MFC_Explorer#2](../../mfc/reference/codesnippet/CPP/cmfcshelllistctrl-class_2.cpp)]  
[!code-cpp[NVC_MFC_Explorer#3](../../mfc/reference/codesnippet/CPP/cmfcshelllistctrl-class_3.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CListCtrl](../Topic/CListCtrl%20Class.md)  
  
 [CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)  
  
 [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxshelllistCtrl.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)   
 [Classe de CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md)