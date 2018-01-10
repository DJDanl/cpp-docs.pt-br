---
title: "Classes de pontos de Conexão (ATL) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.atl.connection
dev_langs: C++
helpviewer_keywords:
- classes [C++], connection points
- connection points classes
ms.assetid: 076365fa-299a-4dce-84c3-a5dff0e0da1f
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e85194547b78e3d3fa3bba868be02c705fcf9a43
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="connection-points-classes"></a>Classes de pontos de Conexão
As classes a seguir fornecem suporte para pontos de conexão:  
  
-   [IConnectionPointContainerImpl](../atl/reference/iconnectionpointcontainerimpl-class.md) implementa um contêiner de ponto de conexão.  
  
-   [IConnectionPointImpl](../atl/reference/iconnectionpointimpl-class.md) implementa um ponto de conexão.  
  
-   [IPropertyNotifySinkCP](../atl/reference/ipropertynotifysinkcp-class.md) implementa um ponto de conexão que representa o [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) interface.  
  
-   [CComDynamicUnkArray](../atl/reference/ccomdynamicunkarray-class.md) gerencia conexões ilimitadas entre um ponto de conexão e seus coletores.  
  
-   [CComUnkArray](../atl/reference/ccomunkarray-class.md) gerencia um número fixo de conexões entre um ponto de conexão e seus coletores.  
  
-   [CFirePropNotifyEvent](../atl/reference/cfirepropnotifyevent-class.md) notifica o coletor do cliente que são propriedade de um objeto foi alterado ou está prestes a ser alterada.  
  
-   [IDispEventImpl](../atl/reference/idispeventimpl-class.md) fornece suporte para pontos de conexão para um objeto COM da ATL. Esses pontos de conexão são mapeados com um mapa de coletor de eventos, que é fornecido pelo seu objeto COM.  
  
-   [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) funciona em conjunto com o coletor de eventos do mapa em sua classe para eventos de rota para a função de manipulador adequado.  
  
## <a name="related-articles"></a>Artigos relacionados  
 [Pontos de conexão](../atl/atl-connection-points.md)  
  
 [Manipulação de eventos e a ATL](../atl/event-handling-and-atl.md)  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../atl/atl-class-overview.md)   
 [Macros de ponto de Conexão](../atl/reference/connection-point-macros.md)   
 [Funções globais de ponto de conexão](../atl/reference/connection-point-global-functions.md)

