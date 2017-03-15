---
title: "Classes de pontos de conex&#227;o | Microsoft Docs"
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
  - "vc.atl.connection"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes [C++], pontos de conexão"
  - "classes de pontos de conexão"
ms.assetid: 076365fa-299a-4dce-84c3-a5dff0e0da1f
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de pontos de conex&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As seguintes classes oferecem suporte para pontos de conexão:  
  
-   [IConnectionPointContainerImpl](../Topic/IConnectionPointContainerImpl%20Class.md) implementa um contêiner de ponto de conexão.  
  
-   [IConnectionPointImpl](../Topic/IConnectionPointImpl%20Class.md) implementa um ponto de conexão.  
  
-   [IPropertyNotifySinkCP](../atl/reference/ipropertynotifysinkcp-class.md) implementa um ponto de conexão que representa a interface de [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) .  
  
-   [CComDynamicUnkArray](../Topic/CComDynamicUnkArray%20Class.md) gerencia ilimitados conexões entre um ponto de conexão e seus dissipadores.  
  
-   [CComUnkArray](../atl/reference/ccomunkarray-class.md) gerencia um número fixo de conexões entre um ponto de conexão e seus dissipadores.  
  
-   [CFirePropNotifyEvent](../Topic/CFirePropNotifyEvent%20Class.md) notifica o coletor de um cliente que a propriedade de um objeto foi alterado ou é o ponto de alteração.  
  
-   [IDispEventImpl](../atl/reference/idispeventimpl-class.md) fornece suporte para conexão aponta para um objeto COM de ATL.  Esses pontos de conexão são mapeados com um mapa do coletor de eventos, que é fornecido pelo objeto COM.  
  
-   [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) Works o mapa em conjunto com o coletor de eventos em sua classe para rotear eventos para a função apropriada do manipulador.  
  
## Artigos relacionados  
 [Pontos de conexão](../atl/atl-connection-points.md)  
  
 [Tratamento de evento e ATL](../Topic/Event%20Handling%20and%20ATL.md)  
  
## Consulte também  
 [Visão geral de classe](../atl/atl-class-overview.md)   
 [Macros de ponto de conexão](../atl/reference/connection-point-macros.md)   
 [Funções globais do ponto de conexão](../Topic/Connection%20Point%20Global%20Functions.md)