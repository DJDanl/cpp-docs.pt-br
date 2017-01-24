---
title: "Mapas de propriedade | Microsoft Docs"
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
  - "mapas, propriedade"
  - "Provedores OLE DB, propriedades"
  - "mapas de propriedade"
ms.assetid: 44abde56-90ad-4612-854e-d2fa5426fa80
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Mapas de propriedade
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Além da sessão, o conjunto de linhas, e o objeto de comando opcional, cada provedor da suporte a uma ou mais propriedades.  Essas propriedades são definidas nos mapas da propriedade contidos nos arquivos de cabeçalho criados pelo assistente do provedor OLE DB.  Cada arquivo de cabeçalho contém um mapa das propriedades no grupo de propriedades OLE DB definido para o objeto ou os objetos definidos no arquivo.  O arquivo de cabeçalho que contém o objeto de fonte de dados também contém o mapa de propriedade para [Propriedades da fonte de dados](https://msdn.microsoft.com/en-us/library/ms724188\(v=vs.140\).aspx).  Session.h contém o mapa de propriedade para [Propriedades de sessão](https://msdn.microsoft.com/en-us/library/ms714221.aspx).  Os objetos do conjunto de linhas e do comando residem em um único arquivo de cabeçalho, *projectnameRS.h*chamado.  Essas propriedades são membros do grupo de [Propriedades de conjunto de linhas](https://msdn.microsoft.com/en-us/library/ms711252.aspx) .  
  
## Consulte também  
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)