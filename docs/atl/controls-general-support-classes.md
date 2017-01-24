---
title: "Controles: Classes gerais de suporte | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.atl.controls"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "controles [ATL]"
  - "classes gerais de suporte"
ms.assetid: cf73f1d2-7542-48e3-b8c8-9d3abf29f85b
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles: Classes gerais de suporte
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As seguintes classes oferecem suporte geral para controles de ATL:  
  
-   [CComControl](../atl/reference/ccomcontrol-class.md) consiste nos membros das funções e dados de auxílio que são essenciais para controles de ATL.  
  
-   [IOleControlImpl](../atl/reference/iolecontrolimpl-class.md) fornece os métodos necessários para controles.  
  
-   [IOleObjectImpl](../atl/reference/ioleobjectimpl-class.md) fornece os métodos chave com que um contêiner se comunica com um controle.  Gerencia a ativação e a desactivação de controles no lugar.  
  
-   Inicialização das combina de[IQuickActivateImpl](../atl/reference/iquickactivateimpl-class.md) em uma única chamada contêiner para ajudar a evitar atrasos quando controles de carregamento.  
  
-   [IPointerInactiveImpl](../atl/reference/ipointerinactiveimpl-class.md) fornece a interação mínima do mouse para um controle de outra forma inativo.  
  
## Programa de exemplo  
 [ATLFire](../top/visual-cpp-samples.md)  
  
## Artigos relacionados  
 [Tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md)  
  
## Consulte também  
 [Visão geral de classe](../atl/atl-class-overview.md)