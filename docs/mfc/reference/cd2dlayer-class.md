---
title: "Classe de CD2DLayer | Microsoft Docs"
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
  - "afxrendertarget/CD2DLayer"
  - "CD2DLayer"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CD2DLayer"
ms.assetid: 2f96378e-66bb-40d1-9661-6afe324de3c1
caps.latest.revision: 18
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CD2DLayer
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um wrapper para ID2D1Layer.  
  
## Sintaxe  
  
```  
class CD2DLayer : public CD2DResource;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DLayer::CD2DLayer](../Topic/CD2DLayer::CD2DLayer.md)|Constrói um objeto de CD2DLayer.|  
|[CD2DLayer::~CD2DLayer](../Topic/CD2DLayer::~CD2DLayer.md)|O destrutor.  Chamado quando um objeto de camada de D2D é destruído.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DLayer::Attach](../Topic/CD2DLayer::Attach.md)|O recurso existente de anexa interfaces para o objeto|  
|[CD2DLayer::Create](../Topic/CD2DLayer::Create.md)|Cria um CD2DLayer.  Overrides \( [CD2DResource::Create](../Topic/CD2DResource::Create.md).\)|  
|[CD2DLayer::Destroy](../Topic/CD2DLayer::Destroy.md)|For um objeto de CD2DLayer.  Overrides \( [CD2DResource::Destroy](../Topic/CD2DResource::Destroy.md).\)|  
|[CD2DLayer::Detach](../Topic/CD2DLayer::Detach.md)|Dispara a interface de recurso de objeto|  
|[CD2DLayer::Get](../Topic/CD2DLayer::Get.md)|Interface de retorna ID2D1Layer|  
|[CD2DLayer::GetSize](../Topic/CD2DLayer::GetSize.md)|Retorna o tamanho de destino processar em pixels independentes|  
|[CD2DLayer::IsValid](../Topic/CD2DLayer::IsValid.md)|Validade de recursos das verificações \(Substitui [CD2DResource::IsValid](../Topic/CD2DResource::IsValid.md)\).|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DLayer::operator ID2D1Layer\*](../Topic/CD2DLayer::operator%20ID2D1Layer*.md)|Interface de retorna ID2D1Layer|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DLayer::m\_pLayer](../Topic/CD2DLayer::m_pLayer.md)|Armazena um ponteiro para um objeto de ID2D1Layer.|  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CD2DResource](../Topic/CD2DResource%20Class.md)  
  
 [CD2DLayer](../../mfc/reference/cd2dlayer-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)