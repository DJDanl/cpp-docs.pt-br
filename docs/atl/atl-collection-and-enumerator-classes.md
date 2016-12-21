---
title: "Classes de cole&#231;&#227;o e o enumerador de ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes de coleção, ATL"
  - "enumeradores, Classes de ATL"
ms.assetid: 6818db73-7094-48d8-a0ca-18147beec362
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de cole&#231;&#227;o e o enumerador de ATL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

ATL fornece as seguintes classes para ajudar ao implementar coleções e enumeradores.  
  
|Classe|Descrição|  
|------------|---------------|  
|[ICollectionOnSTLImpl](../atl/reference/icollectiononstlimpl-class.md)|Implementação da interface de coleção|  
|[IEnumOnSTLImpl](../atl/reference/ienumonstlimpl-class.md)|Implementação da interface de enumerador \(pressupõe os dados armazenados em um contêiner STL\- compatível\)|  
|[CComEnumImpl](../atl/reference/ccomenumimpl-class.md)|Implementação da interface de enumerador \(pressupõe os dados armazenados em uma matriz\)|  
|[CComEnumOnSTL](../atl/reference/ccomenumonstl-class.md)|Implementação do objeto enumerator \(usa `IEnumOnSTLImpl`\)|  
|[CComEnum](../atl/reference/ccomenum-class.md)|Implementação do objeto enumerator \(usa `CComEnumImpl`\)|  
|[\_Copiar](../Topic/ATL%20Copy%20Policy%20Classes.md)|Classe de diretiva de impressão|  
|[\_CopyInterface](../Topic/ATL%20Copy%20Policy%20Classes.md)|Classe de diretiva de impressão|  
|[CAdapt](../atl/reference/cadapt-class.md)|Classe do adaptador \(oculta **operator &** permitindo `CComPtr`, `CComQIPtr`, e `CComBSTR` a ser armazenado em um recipiente de STL\)|  
  
## Consulte também  
 [Coleções e enumeradores](../atl/atl-collections-and-enumerators.md)