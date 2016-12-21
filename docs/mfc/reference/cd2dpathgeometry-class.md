---
title: "Classe de CD2DPathGeometry | Microsoft Docs"
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
  - "afxrendertarget/CD2DPathGeometry"
  - "CD2DPathGeometry"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CD2DPathGeometry"
ms.assetid: 686216eb-5080-4242-ace5-8fa1ce96307c
caps.latest.revision: 17
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CD2DPathGeometry
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um wrapper para ID2D1PathGeometry.  
  
## Sintaxe  
  
```  
class CD2DPathGeometry : public CD2DGeometry;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DPathGeometry::CD2DPathGeometry](../Topic/CD2DPathGeometry::CD2DPathGeometry.md)|Constrói um objeto de CD2DPathGeometry.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DPathGeometry::Attach](../Topic/CD2DPathGeometry::Attach.md)|O recurso existente de anexa interfaces para o objeto|  
|[CD2DPathGeometry::Create](../Topic/CD2DPathGeometry::Create.md)|Cria um CD2DPathGeometry.  Overrides \( [CD2DResource::Create](../Topic/CD2DResource::Create.md).\)|  
|[CD2DPathGeometry::Destroy](../Topic/CD2DPathGeometry::Destroy.md)|For um objeto de CD2DPathGeometry.  Overrides \( [CD2DGeometry::Destroy](../Topic/CD2DGeometry::Destroy.md).\)|  
|[CD2DPathGeometry::Detach](../Topic/CD2DPathGeometry::Detach.md)|Dispara a interface de recurso de objeto|  
|[CD2DPathGeometry::GetFigureCount](../Topic/CD2DPathGeometry::GetFigureCount.md)|Retorna o número de figuras em geometrias de caminho.|  
|[CD2DPathGeometry::GetSegmentCount](../Topic/CD2DPathGeometry::GetSegmentCount.md)|Retorna o número de segmentos em geometrias de caminho.|  
|[CD2DPathGeometry::Open](../Topic/CD2DPathGeometry::Open.md)|Recupera o coletor de geometria que é usado para preencher a geometria de caminhos com figuras e segmentos.|  
|[CD2DPathGeometry::Stream](../Topic/CD2DPathGeometry::Stream.md)|Copia o conteúdo da geometria do caminho para o ID2D1GeometrySink especificado.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DPathGeometry::m\_pPathGeometry](../Topic/CD2DPathGeometry::m_pPathGeometry.md)|Um ponteiro para um ID2D1PathGeometry.|  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CD2DResource](../Topic/CD2DResource%20Class.md)  
  
 [CD2DGeometry](../Topic/CD2DGeometry%20Class.md)  
  
 [CD2DPathGeometry](../../mfc/reference/cd2dpathgeometry-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)