---
title: "Classe de CMFCListCtrl | Microsoft Docs"
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
  - "CMFCListCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCListCtrl"
ms.assetid: 50d16aee-138c-4f34-8690-cb75d544ef2e
caps.latest.revision: 29
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCListCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCListCtrl` estendem a funcionalidade da classe de [Classe de CListCtrl](../Topic/CListCtrl%20Class.md) apoiando a funcionalidade avançada do controle de cabeçalho de [Classe de CMFCHeaderCtrl](../Topic/CMFCHeaderCtrl%20Class.md).  
  
## Sintaxe  
  
```  
class CMFCListCtrl : public CListCtrl  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCListCtrl::EnableMarkSortedColumn](../Topic/CMFCListCtrl::EnableMarkSortedColumn.md)|Permite que a capacidade de marcar uma coluna classificado com uma cor de plano de fundo diferente.|  
|[CMFCListCtrl::EnableMultipleSort](../Topic/CMFCListCtrl::EnableMultipleSort.md)|Permite que vários o modo de tipo.|  
|[CMFCListCtrl::GetHeaderCtrl](../Topic/CMFCListCtrl::GetHeaderCtrl.md)|Retorna uma referência ao controle de cabeçalho sublinhado.|  
|[CMFCListCtrl::IsMultipleSort](../Topic/CMFCListCtrl::IsMultipleSort.md)|Verifica se o controle de lista está no modo de várias tipo.|  
|[CMFCListCtrl::OnCompareItems](../Topic/CMFCListCtrl::OnCompareItems.md)|Quando é chamado pela estrutura comparar dois itens de controle de lista.|  
|[CMFCListCtrl::OnGetCellBkColor](../Topic/CMFCListCtrl::OnGetCellBkColor.md)|Quando chamado pela estrutura deve determinar a cor do plano de fundo de uma célula individual.|  
|[CMFCListCtrl::OnGetCellFont](../Topic/CMFCListCtrl::OnGetCellFont.md)|Quando chamado pela estrutura deve obter a fonte para a célula que está sendo desenhada.|  
|[CMFCListCtrl::OnGetCellTextColor](../Topic/CMFCListCtrl::OnGetCellTextColor.md)|Quando chamado pela estrutura deve determinar a cor do texto de uma célula individual.|  
|[CMFCListCtrl::RemoveSortColumn](../Topic/CMFCListCtrl::RemoveSortColumn.md)|Remove uma coluna de tipo da lista de colunas classificadas.|  
|[CMFCListCtrl::SetSortColumn](../Topic/CMFCListCtrl::SetSortColumn.md)|Definir a coluna classificado atual e a ordem de classificação.|  
|[CMFCListCtrl::Sort](../Topic/CMFCListCtrl::Sort.md)|Classes do controle de lista.|  
  
## Comentários  
 `CMFCListCtrl` oferece dois aprimoramentos para a classe de [Classe de CListCtrl](../Topic/CListCtrl%20Class.md) .  Primeiro, indica que a classificação da coluna é uma opção disponível automaticamente desenhando uma seta de tipo no cabeçalho.  Segundo, oferece suporte a classificação de dados em várias colunas ao mesmo tempo.  
  
## Exemplo  
 O exemplo a seguir demonstra como usar vários métodos na classe de `CMFCListCtrl` .  O exemplo a seguir mostra como criar um controle de lista, inserir colunas, itens de inserção, define o texto de um item, e define a fonte de controle list.  Este trecho de código é parte de [Exemplo de demonstração do Visual Studio](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo#25](../../mfc/reference/codesnippet/CPP/cmfclistctrl-class_1.h)]  
[!code-cpp[NVC_MFC_VisualStudioDemo#26](../../mfc/reference/codesnippet/CPP/cmfclistctrl-class_2.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CListCtrl](../Topic/CListCtrl%20Class.md)  
  
 [CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxlistctrl.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CListCtrl](../Topic/CListCtrl%20Class.md)