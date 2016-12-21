---
title: "Classe de CRectTracker | Microsoft Docs"
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
  - "CRectTracker"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CRectTracker"
  - "exibindo itens"
  - "redimensionando itens"
ms.assetid: 99caa7f2-3c0d-4a42-bbee-e5d1d342d4ee
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CRectTracker
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite que um item é exibido, e movido, redimensionado para formas diferentes.  
  
## Sintaxe  
  
```  
  
class CRectTracker  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRectTracker::CRectTracker](../Topic/CRectTracker::CRectTracker.md)|Constrói um objeto de `CRectTracker` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRectTracker::AdjustRect](../Topic/CRectTracker::AdjustRect.md)|Chamado quando o retângulo é redimensionado.|  
|[CRectTracker::Draw](../Topic/CRectTracker::Draw.md)|Processa o retângulo.|  
|[CRectTracker::DrawTrackerRect](../Topic/CRectTracker::DrawTrackerRect.md)|Chamado ao desenhar a borda de um objeto de `CRectTracker` .|  
|[CRectTracker::GetHandleMask](../Topic/CRectTracker::GetHandleMask.md)|Chamado para obter a máscara de um item de `CRectTracker`redimensionar alças.|  
|[CRectTracker::GetTrueRect](../Topic/CRectTracker::GetTrueRect.md)|O retorna largura e altura do retângulo, incluindo as alças de redimensionamento.|  
|[CRectTracker::HitTest](../Topic/CRectTracker::HitTest.md)|Retorna a posição atual do cursor relativo ao objeto de `CRectTracker` .|  
|[CRectTracker::NormalizeHit](../Topic/CRectTracker::NormalizeHit.md)|Normalizará um código sucessos\-teste.|  
|[CRectTracker::OnChangedRect](../Topic/CRectTracker::OnChangedRect.md)|Chamado quando o retângulo é redimensionado ou movido.|  
|[CRectTracker::SetCursor](../Topic/CRectTracker::SetCursor.md)|Define o cursor, dependendo de sua posição no retângulo.|  
|[CRectTracker::Track](../Topic/CRectTracker::Track.md)|Permite que o usuário manipular o retângulo.|  
|[CRectTracker::TrackRubberBand](../Topic/CRectTracker::TrackRubberBand.md)|Permite ao usuário para “extensível” a seleção.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRectTracker::m\_nHandleSize](../Topic/CRectTracker::m_nHandleSize.md)|Determina o tamanho das alças de redimensionamento.|  
|[CRectTracker::m\_nStyle](../Topic/CRectTracker::m_nStyle.md)|Estilos atual de perseguidor.|  
|[CRectTracker::m\_rect](../Topic/CRectTracker::m_rect.md)|A posição atual \(em pixels\) do retângulo.|  
|[CRectTracker::m\_sizeMin](../Topic/CRectTracker::m_sizeMin.md)|Determina a largura e altura mínimas do retângulo.|  
  
## Comentários  
 `CRectTracker` não tem uma classe base.  
  
 Embora a classe de `CRectTracker` é criada para permitir que o usuário interaja com os itens VELHOS usando uma interface gráfica, seu uso não é restrito para aplicativos OLE\- ativados.  Pode ser usado em qualquer lugar tal interface do usuário é necessário.  
  
 As bordas de`CRectTracker` podem ser linhas contínuas ou pontilhadas.  O item pode ser fornecida uma borda chocada ou ser sobreposto com um padrão chocado para indicar estados diferentes de item.  Você pode colocar redimensiona oito alças na borda externa ou de dentro do item.  \(Para uma explicação sobre as alças de redimensionamento, consulte [GetHandleMask](../Topic/CRectTracker::GetHandleMask.md).\) Finalmente, `CRectTracker` permite que você altere a orientação de um item durante redimensionar.  
  
 Para usar `CRectTracker`, construir um objeto de `CRectTracker` e especifica que exibem estados são inicializadas.  Você pode usar esta interface para dar ao usuário feedback visual no status atual do OLE item associado ao objeto de `CRectTracker` .  
  
 Para obter mais informações sobre como usar `CRectTracker`, consulte o artigo [perseguidores](../../mfc/trackers.md).  
  
## Hierarquia de herança  
 `CRectTracker`  
  
## Requisitos  
 **Cabeçalho:** afxext.h  
  
## Consulte também  
 [O MFC sem o PERSEGUIDOR](../../top/visual-cpp-samples.md)   
 [Exemplo DRAWCLI MFC](../../top/visual-cpp-samples.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleResizeBar](../../mfc/reference/coleresizebar-class.md)   
 [Classe de CRect](../../atl-mfc-shared/reference/crect-class.md)   
 [CRectTracker::GetHandleMask](../Topic/CRectTracker::GetHandleMask.md)