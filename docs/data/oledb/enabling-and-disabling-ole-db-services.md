---
title: "Habilitando e desabilitando servi&#231;os de banco de dados OLE | Microsoft Docs"
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
  - "Serviços OLE DB [OLE DB], habilitando e desabilitando"
  - "provedores de serviço [OLE DB]"
ms.assetid: 445f97eb-32a8-41c2-ad26-1169f78a074f
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Habilitando e desabilitando servi&#231;os de banco de dados OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O gerenciador do componente de serviço do OLE DB compara as propriedades especificadas pelo consumidor para aqueles suportadas pelo provedor para determinar se os componentes de serviço individuais podem ser chamadas para satisfazer a funcionalidade estendida solicitada pelo consumidor.  Por exemplo, se um aplicativo solicitar um cursor rolável e o provedor oferecer suporte apenas a um cursor de somente avanço, o gerenciador do componente de serviço invoca o componente de serviço do mecanismo de cursor do cliente para fornecer funcionalidade rolável.  Se o aplicativo estiver habilitar a funcionalidade estendida suporte por padrão no conjunto de linhas do provedor, e o aplicativo não definir explicitamente as propriedades para solicitar essa funcionalidade, a funcionalidade não pode aparecer no conjunto de linhas retornado pelo mecanismo de cursor do cliente.  Para ser interoperáveis, os aplicativos devem sempre definir propriedades para solicitar explicitamente à funcionalidade estendida onde necessários.  
  
 Em alguns casos, pode ser necessário desabilitar serviços individuais OLE DB para funcionar bem com aplicativos existentes que fazem suposições sobre as características de um provedor.  Os serviços de OLE DB forneçam a capacidade de desabilitar serviços individuais, ou todos os serviços, em uma base para cada conexão ou para todos os aplicativos usando um único provedor.  
  
## Consulte também  
 [Pooling de recursos e serviços de banco de dados OLE](../../data/oledb/ole-db-resource-pooling-and-services.md)