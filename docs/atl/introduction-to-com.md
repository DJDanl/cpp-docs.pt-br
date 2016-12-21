---
title: "Introdu&#231;&#227;o ao COM | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "index-page "
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "COM"
ms.assetid: 120735d9-db71-4ad3-a730-ce576ea2354e
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Introdu&#231;&#227;o ao COM
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

COM “é o modelo de objeto” fundamental em que controles ActiveX e o OLE são compilados.  COM permite que um objeto expor sua funcionalidade a outros componentes e para aplicativos host.  Define como se o objeto expõe e assim expor funciona em processos e através de internet.  COM também define o ciclo de vida do objeto.  
  
 O fundamento a é COM esses conceitos:  
  
-   [interfaces](../atl/interfaces-atl.md) — o mecanismo através de que um objeto expor sua funcionalidade.  
  
-   [IUnknown](../atl/iunknown.md) — a interface básica em que todos os outros são baseados.  Implementa a interface e a contagem de referência que consulte os mecanismos executados com COM.  
  
-   [Contagem de referência](../atl/reference-counting.md) — a técnica por que um objeto \(ou, restrita, uma interface\) decidem quando ele não está sendo usado e portanto é livre se remover.  
  
-   [QueryInterface](../atl/queryinterface.md) — o método usado para consultar um objeto para uma determinada interface.  
  
-   [Empacotamento](../atl/marshaling.md) — o mecanismo que permite os objetos a serem usados pelo segmento, o processo, e os limites de rede, permitir independência do local.  
  
-   [Agregado](../atl/aggregation.md) — uma maneira na qual objeto pode utilizar outro.  
  
## Consulte também  
 [Introdução à e a ATL](../atl/introduction-to-com-and-atl.md)   
 [The Component Object Model](http://msdn.microsoft.com/library/windows/desktop/ms694363)