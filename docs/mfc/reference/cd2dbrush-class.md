---
title: "Classe de CD2DBrush | Microsoft Docs"
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
  - "CD2DBrush"
  - "afxrendertarget/CD2DBrush"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CD2DBrush"
ms.assetid: 0d2c0857-2261-48a8-8ee0-a88cbf08499a
caps.latest.revision: 17
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CD2DBrush
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um wrapper para ID2D1Brush.  
  
## Sintaxe  
  
```  
class CD2DBrush : public CD2DResource;  
```  
  
## Membros  
  
### Construtores protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DBrush::CD2DBrush](../Topic/CD2DBrush::CD2DBrush.md)|Constrói um objeto de CD2DBrush.|  
|[CD2DBrush::~CD2DBrush](../Topic/CD2DBrush::~CD2DBrush.md)|O destrutor.  Chamado quando um objeto do pincel de D2D é destruído.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DBrush::Attach](../Topic/CD2DBrush::Attach.md)|O recurso existente de anexa interfaces para o objeto|  
|[CD2DBrush::Destroy](../Topic/CD2DBrush::Destroy.md)|For um objeto de CD2DBrush.  Overrides \( [CD2DResource::Destroy](../Topic/CD2DResource::Destroy.md).\)|  
|[CD2DBrush::Detach](../Topic/CD2DBrush::Detach.md)|Dispara a interface de recurso de objeto|  
|[CD2DBrush::Get](../Topic/CD2DBrush::Get.md)|Interface de retorna ID2D1Brush|  
|[CD2DBrush::GetOpacity](../Topic/CD2DBrush::GetOpacity.md)|Obtém o grau de opacidade essa pincel|  
|[CD2DBrush::GetTransform](../Topic/CD2DBrush::GetTransform.md)|Obtém a atual se tornam de destino processar|  
|[CD2DBrush::IsValid](../Topic/CD2DBrush::IsValid.md)|Validade de recursos das verificações \(Substitui [CD2DResource::IsValid](../Topic/CD2DResource::IsValid.md)\).|  
|[CD2DBrush::SetOpacity](../Topic/CD2DBrush::SetOpacity.md)|Define o grau de opacidade essa pincel|  
|[CD2DBrush::SetTransform](../Topic/CD2DBrush::SetTransform.md)|Aplica especificado torna\-se ao processar destino, substituindo a transformação existente.  Todas as operações subsequentes de desenho ocorrem no espaço transformado|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DBrush::operator ID2D1Brush\*](../Topic/CD2DBrush::operator%20ID2D1Brush*.md)|Interface de retorna ID2D1Brush|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DBrush::m\_pBrush](../Topic/CD2DBrush::m_pBrush.md)|Armazena um ponteiro para um objeto de ID2D1Brush.|  
|[CD2DBrush::m\_pBrushProperties](../Topic/CD2DBrush::m_pBrushProperties.md)|Propriedades de pintura.|  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CD2DResource](../Topic/CD2DResource%20Class.md)  
  
 [CD2DBrush](../../mfc/reference/cd2dbrush-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)