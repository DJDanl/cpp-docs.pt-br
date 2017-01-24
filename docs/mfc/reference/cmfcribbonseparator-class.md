---
title: "Classe de CMFCRibbonSeparator | Microsoft Docs"
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
  - "GetThisClass"
  - "CMFCRibbonSeparator::GetThisClass"
  - "CMFCRibbonSeparator.CreateObject"
  - "CMFCRibbonSeparator::CreateObject"
  - "CMFCRibbonSeparator"
  - "CreateObject"
  - "CMFCRibbonSeparator.GetThisClass"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCRibbonSeparator"
  - "Método de CreateObject"
  - "Método de GetThisClass"
ms.assetid: bedb1a53-cb07-4c3c-be12-698c5409e7cf
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCRibbonSeparator
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa o separador de fita.  
  
## Sintaxe  
  
```  
class CMFCRibbonSeparator : public CMFCRibbonBaseElement  
```  
  
## Membros  
  
### Construtores public  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCRibbonSeparator::CMFCRibbonSeparator](../Topic/CMFCRibbonSeparator::CMFCRibbonSeparator.md)|Constrói um objeto de `CMFCRibbonSeparator` .|  
  
### Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCRibbonSeparator::AddToListBox](../Topic/CMFCRibbonSeparator::AddToListBox.md)|Adiciona um separador à lista de **Comandos** na caixa de diálogo de **Personalizar** .  Overrides \( [CMFCRibbonBaseElement::AddToListBox](../Topic/CMFCRibbonBaseElement::AddToListBox.md).\)|  
|`CMFCRibbonSeparator::CreateObject`|Usado pela estrutura dinâmica para criar uma instância de esse tipo da classe.|  
|`CMFCRibbonSeparator::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
  
### Métodos protegidos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCRibbonSeparator::CopyFrom](../Topic/CMFCRibbonSeparator::CopyFrom.md)|Um método de impressão que define variáveis de membro de um separador de outro objeto.|  
|[CMFCRibbonSeparator::GetRegularSize](../Topic/CMFCRibbonSeparator::GetRegularSize.md)|Retorna o tamanho de um separador.|  
|[CMFCRibbonSeparator::IsSeparator](../Topic/CMFCRibbonSeparator::IsSeparator.md)|Indica se este é um separador.|  
|[CMFCRibbonSeparator::IsTabStop](../Topic/CMFCRibbonSeparator::IsTabStop.md)|Indica se esta é uma parada de tabulação.|  
|[CMFCRibbonSeparator::OnDraw](../Topic/CMFCRibbonSeparator::OnDraw.md)|Chamado pelo sistema para desenhar o separador em fita ou na barra de ferramentas de acesso rápido.|  
|[CMFCRibbonSeparator::OnDrawOnList](../Topic/CMFCRibbonSeparator::OnDrawOnList.md)|Chamado pelo sistema para desenhar o separador na lista de **Comandos** .|  
  
## Comentários  
 Um separador de fita é uma linha vertical ou horizontal que separa logicamente os elementos de fita.  Um separador pode ser desenhado no controle de fita, no menu principal do aplicativo, na barra de status de fita, e na barra de ferramentas de acesso rápido.  
  
 Para usar um separador em seu aplicativo, crie o novo objeto e adicioná\-lo ao menu principal do aplicativo como mostrado aqui:  
  
```  
CMFCRibbonMainPanel* pMainPanel = m_wndRibbonBar.AddMainCategory(_T("Main Menu"), IDB_FILESMALL, IDB_FILELARGE);   
...  
pMainPanel->Add(new CMFCRibbonSeparator(TRUE));  
```  
  
 Chame [CMFCRibbonPanel::AddSeparator](../Topic/CMFCRibbonPanel::AddSeparator.md) para adicionar separadores aos painéis de fita.  Separadores são atribuídos e adicionados internamente pelo método de `AddSeparator` .  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonSeparator](../../mfc/reference/cmfcribbonseparator-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxbaseribbonelement.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)