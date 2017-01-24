---
title: "Classe de CRecentDockSiteInfo | Microsoft Docs"
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
  - "CRecentDockSiteInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CRecentDockSiteInfo"
ms.assetid: 2dd14f95-d5a2-4461-a7a5-2c6c36a3a165
caps.latest.revision: 26
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CRecentDockSiteInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O `CRecentDockSiteInfo` classe é uma classe auxiliar que armazena informações de estado recentes para o [Classe de CPane](../../mfc/reference/cpane-class.md).  
  
## Sintaxe  
  
```  
class CRecentDockSiteInfo : public CObject  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CRecentDockSiteInfo::CRecentDockSiteInfo`|Construtor padrão.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRecentDockSiteInfo::CleanUp](../Topic/CRecentDockSiteInfo::CleanUp.md)||  
|[CRecentDockSiteInfo::GetRecentDefaultPaneDivider](../Topic/CRecentDockSiteInfo::GetRecentDefaultPaneDivider.md)||  
|[CRecentDockSiteInfo::GetRecentDockedPercent](../Topic/CRecentDockSiteInfo::GetRecentDockedPercent.md)||  
|[CRecentDockSiteInfo::GetRecentDockedRect](../Topic/CRecentDockSiteInfo::GetRecentDockedRect.md)||  
|[CRecentDockSiteInfo::GetRecentListOfPanes](../Topic/CRecentDockSiteInfo::GetRecentListOfPanes.md)||  
|[CRecentDockSiteInfo::GetRecentPaneContainer](../Topic/CRecentDockSiteInfo::GetRecentPaneContainer.md)||  
|[CRecentDockSiteInfo::GetRecentTabContainer](../Topic/CRecentDockSiteInfo::GetRecentTabContainer.md)||  
|[CRecentDockSiteInfo::Init](../Topic/CRecentDockSiteInfo::Init.md)||  
|[CRecentDockSiteInfo::IsRecentLeftPane](../Topic/CRecentDockSiteInfo::IsRecentLeftPane.md)||  
|[CRecentDockSiteInfo::operator \=](../Topic/CRecentDockSiteInfo::operator%20=.md)||  
|[CRecentDockSiteInfo::SaveListOfRecentPanes](../Topic/CRecentDockSiteInfo::SaveListOfRecentPanes.md)||  
|[CRecentDockSiteInfo::SetInfo](../Topic/CRecentDockSiteInfo::SetInfo.md)||  
|[CRecentDockSiteInfo::StoreDockInfo](../Topic/CRecentDockSiteInfo::StoreDockInfo.md)||  
  
## Comentários  
 O `CRecentDockSiteInfo` classe é uma classe de gerenciamento de dados.  Controla o último estado de um `CPane` como ela faz a transição entre sendo encaixado e flutuante.  Quando um usuário clicar duas vezes um painel encaixável flutuante, ele ficará encaixado.  O painel encaixado de clicando duas vezes retorna ao seu local anterior, o tamanho e o estado.  Da mesma forma, quando o painel está ancorado novamente ele retorna para seu local de encaixe anterior.  Essa classe de dados é o que torna isso possível.  Já que os membros dessa classe armazenam informações de estado para o painel encaixado, eles não devem ser diretamente modificados por seu aplicativo.  
  
 Um `CRecentDockSiteInfo` objeto é criado sempre que um painel é criado.  Cada `CPane` objeto tem uma variável de membro, [CPane::m\_recentDockInfo](../Topic/CPane::m_recentDockInfo.md), para armazenar essas informações.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CRecentDockSiteInfo](../../mfc/reference/crecentdocksiteinfo-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxrecentDockSiteInfo.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CDockSite](../../mfc/reference/cdocksite-class.md)