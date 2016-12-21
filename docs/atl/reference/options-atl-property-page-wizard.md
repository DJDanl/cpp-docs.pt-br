---
title: "Op&#231;&#245;es, o assistente da p&#225;gina de propriedades de ATL | Microsoft Docs"
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
  - "vc.codewiz.class.atl.ppg.options"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente da página de propriedades de ATL, options"
ms.assetid: a7107779-b2ea-4f99-b84b-7f3e0c504bc8
caps.latest.revision: 13
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Op&#231;&#245;es, o assistente da p&#225;gina de propriedades de ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Use esta página do assistente para definir o modelo de segmentação e a agregação em nível de página de propriedades que você está criando.  
  
 **Threading model**  
 Especifica o modelo de segmentação usado pela página de propriedades.  
  
 Consulte [Especificando o modelo de segmentação do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para mais informações.  
  
|Opção|Descrição|  
|-----------|---------------|  
|`Single`|A página de propriedades é executado somente no segmento principal COM.|  
|**Apartment**|A página de propriedades pode ser criada em qualquer single thread apartment.  a opção.|  
  
 **Aggregation**  
 Adiciona suporte de agregação para a página de propriedades que você está criando.  Consulte [Agregado](../../atl/aggregation.md) para mais informações.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Sim**|Crie uma página de propriedades que pode ser aggregate.|  
|**Não**|Crie uma página de propriedades que não pode ser aggregate.|  
|**Somente**|Crie uma página de propriedades que pode apenas ser instanciada com a agregação.|  
  
## Consulte também  
 [Assistente da página de propriedades de ATL](../../atl/reference/atl-property-page-wizard.md)   
 [Cadeias de caracteres, assistente da página de propriedades de ATL](../../atl/reference/strings-atl-property-page-wizard.md)