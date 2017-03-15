---
title: "Exemplo de ponto de conex&#227;o de ATL | Microsoft Docs"
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
  - "pontos de conexão [C++], exemplos"
  - "exemplos [ATL]"
ms.assetid: a49721b7-f308-43de-8868-f662a94bc81a
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exemplo de ponto de conex&#227;o de ATL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este exemplo mostra um objeto que suporta [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) como uma interface de saída:  
  
 [!code-cpp[NVC_ATL_Windowing#84](../atl/codesnippet/CPP/atl-connection-point-example_1.h)]  
  
 Ao especificar `IPropertyNotifySink` como uma interface de saída, você pode usar a classe [IPropertyNotifySinkCP](../atl/reference/ipropertynotifysinkcp-class.md) em vez de `IConnectionPointImpl`.  Por exemplo:  
  
 [!code-cpp[NVC_ATL_Windowing#85](../atl/codesnippet/CPP/atl-connection-point-example_2.h)]  
  
## Consulte também  
 [Ponto de conexão](../atl/atl-connection-points.md)