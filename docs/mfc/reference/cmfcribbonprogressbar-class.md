---
title: "Classe de CMFCRibbonProgressBar | Microsoft Docs"
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
  - "CMFCRibbonProgressBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCRibbonProgressBar"
ms.assetid: de3d9f2e-ed59-480e-aa7d-08a33ab36c67
caps.latest.revision: 26
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCRibbonProgressBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa um controle que indica visualmente o progresso de uma operação longa.  
  
## Sintaxe  
  
```  
class CMFCRibbonProgressBar : public CMFCRibbonBaseElement  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonProgressBar::CMFCRibbonProgressBar](../Topic/CMFCRibbonProgressBar::CMFCRibbonProgressBar.md)|As compilações e inicializam um objeto de `CMFCRibbonProgressBar` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonProgressBar::GetPos](../Topic/CMFCRibbonProgressBar::GetPos.md)|Retorna o progresso atual.|  
|[CMFCRibbonProgressBar::GetRangeMax](../Topic/CMFCRibbonProgressBar::GetRangeMax.md)|Retorna o valor médio de intervalo atual.|  
|[CMFCRibbonProgressBar::GetRangeMin](../Topic/CMFCRibbonProgressBar::GetRangeMin.md)|Retorna o valor médio de intervalo atual.|  
|[CMFCRibbonProgressBar::GetRegularSize](../Topic/CMFCRibbonProgressBar::GetRegularSize.md)|Retorna o tamanho normal do elemento de fita.  Overrides \( [CMFCRibbonBaseElement::GetRegularSize](../Topic/CMFCRibbonBaseElement::GetRegularSize.md).\)|  
|[CMFCRibbonProgressBar::IsInfiniteMode](../Topic/CMFCRibbonProgressBar::IsInfiniteMode.md)|Especifica se a barra de progresso estiver trabalhando em modo infinito.|  
|[CMFCRibbonProgressBar::OnDraw](../Topic/CMFCRibbonProgressBar::OnDraw.md)|Chamado pela estrutura para desenhar o elemento de fita.  Overrides \( [CMFCRibbonBaseElement::OnDraw](../Topic/CMFCRibbonBaseElement::OnDraw.md).\)|  
|[CMFCRibbonProgressBar::SetInfiniteMode](../Topic/CMFCRibbonProgressBar::SetInfiniteMode.md)|Define a barra de progresso para trabalhar no modo infinito.|  
|[CMFCRibbonProgressBar::SetPos](../Topic/CMFCRibbonProgressBar::SetPos.md)|Define o progresso atual.|  
|[CMFCRibbonProgressBar::SetRange](../Topic/CMFCRibbonProgressBar::SetRange.md)|Defina os valores mínimo e máximo.|  
  
## Comentários  
 `CMFCRibbonProgressBar` pode operar em dois modos: normal e infinito.  Em o modo normal, barra de progresso é preenchida da esquerda para a direita e para quando atinge o valor máximo.  Em o modo interminável, a barra de progresso é preenchida repetidamente do valor mínimo para o valor máximo.  Você pode usar o para infinito para indicar que é uma operação em traço, mas o tempo de conclusão que são desconhecidos.  
  
## Exemplo  
 O exemplo a seguir demonstra como usar vários métodos na classe de `CMFCRibbonProgressBar` .  O exemplo a seguir mostra como definir a barra de progresso para trabalhar no modo infinito \(onde a hora de conclusão da operação são desconhecidas\), defina os valores mínimo e máximo para a barra de progresso, e define a posição atual de barra de progresso.  Este trecho de código é parte de [Exemplo 2007 de demonstração de MS Office](../../top/visual-cpp-samples.md).  
  
 [!CODE [NVC_MFC_MSOffice2007Demo#11](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_MSOffice2007Demo#11)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonProgressBar](../../mfc/reference/cmfcribbonprogressbar-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxRibbonProgressBar.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)   
 [Classe de CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)