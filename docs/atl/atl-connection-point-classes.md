---
title: "Classes de Ponto de Conex&#227;o de ATL | Microsoft Docs"
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
  - "Classe CFirePropNotifyEvent, classes de ponto de conexão"
  - "pontos de conexão [C++], classes ATL"
  - "Pontos de conexão de ATL"
  - "Classe CComDynamicUnkArray, classes de ponto de conexão"
  - "Classe CFirePropNotifyEvent"
  - "Classe CComUnkArray, classes de ponto de conexão"
ms.assetid: 9582ba71-7ace-4df4-9c9b-1b0636953efc
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de Ponto de Conex&#227;o de ATL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

ATL usa as seguintes classes para oferecer suporte a pontos de conexão:  
  
-   [IConnectionPointImpl](../Topic/IConnectionPointImpl%20Class.md) implementa um ponto de conexão. O IID da interface de saída representa é passado como um parâmetro de modelo.  
  
-   [IConnectionPointContainerImpl](../Topic/IConnectionPointContainerImpl%20Class.md) implementa o contêiner de ponto de conexão e gerencia a lista de `IConnectionPointImpl` objetos.  
  
-   [IPropertyNotifySinkCP](../atl/reference/ipropertynotifysinkcp-class.md) implementa um ponto de conexão que representa o [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) interface.  
  
-   [CComDynamicUnkArray](../Topic/CComDynamicUnkArray%20Class.md) gerencia um número arbitrário de conexões entre o ponto de conexão e seus coletores.  
  
-   [CComUnkArray](../atl/reference/ccomunkarray-class.md) gerencia um número predefinido de conexões conforme especificado pelo parâmetro de modelo.  
  
-   [CFirePropNotifyEvent](../Topic/CFirePropNotifyEvent%20Class.md) notifica o coletor do cliente que são propriedade de um objeto foi alterado ou está prestes a alterar.  
  
-   [IDispEventImpl](../atl/reference/idispeventimpl-class.md) fornece suporte para pontos de conexão para um objeto COM ATL. Esses pontos de conexão são mapeados com um mapa coletor de evento, que é fornecido pelo seu objeto COM.  
  
-   [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) funciona em conjunto com o mapa de coletor de eventos em sua classe para eventos de rota para a função de manipulador apropriado.  
  
## Consulte também  
 [Ponto de conexão](../atl/atl-connection-points.md)